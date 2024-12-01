#!/usr/bin/env ruby

# To make testing/debugging easier test within this source tree versus an installed gem
require 'bundler/setup'

require 'fileutils'
require 'open-uri'
require 'pathname'
require 'rice'
require 'libxml-ruby'

class OpenCVTag
	OPENCV_ROOT = "https://docs.opencv.org/4.x"

	def initialize()
		#remote_file = URI.open("#{OPENCV_ROOT}/opencv.tag")
		remote_file = File.open("c:/Users/cfis/Downloads/opencv.tag")
		parser = LibXML::XML::Parser.string(remote_file.read)
		@doc = parser.parse
	end

	def camelize(content, first_letter_in_uppercase = true)
		if first_letter_in_uppercase
			content.to_s.gsub(/\/(.?)/) { "::#{$1.upcase}" }.gsub(/(?:^|_)(.)/) { $1.upcase }
		else
			content.to_s[0].chr.downcase + camelize(content)[1..-1]
		end
	end

	def url(member_node)
		# Build url
		anchor_file = member_node.find_first('anchorfile').content
		anchor = member_node.find_first('anchor').content
		"#{OPENCV_ROOT}/#{anchor_file}##{anchor}"
	end

	def cpp_name(klass)
		case klass.cpp_class
			when /^enum/i
				klass.cpp_class.gsub(/enum\s+/i, '')
			when /^union/i
				klass.cpp_class.gsub(/union\s+/i, '')
			when /<.*>/
				pos = klass.cpp_class.index('<')
				klass.cpp_class[0..pos-1]
			else
				klass.cpp_class
		end
	end

	def class_node(klass)
		xpath = "//tagfile/compound[@kind='class' or @kind='struct' or @kind='union'][name='#{cpp_name(klass)}']"
		@doc.find_first(xpath)
	end

	def enum_node(klass)
		cpp_name = klass.cpp_class.gsub(/^enum /, '')
		cpp_parts = cpp_name.split("::")

		kind = enum_kind(klass)
		xpath = if kind == "group"
							"//tagfile/compound[@kind='#{enum_kind(klass)}']/member[@kind='enumeration'][name='#{cpp_parts.last}']"
						else
							parent_name = cpp_name.split("::")[0..-2].join("::")
							"//tagfile/compound[@kind='#{enum_kind(klass)}'][name='#{parent_name}']/member[@kind='enumeration'][name='#{cpp_parts.last}']"
						end
		@doc.find_first(xpath)
	end

	def class_url(node)
		if node
			file = node.find_first('filename').content
  		"#{OPENCV_ROOT}/#{file}"
		end
	end

	def figure_parent(klass)
		# Split namespace
		names = klass.name.split('::')
		# Remove the class
		names.pop

		current_module = Object

		names.each do |name|
			current_module = current_module.const_get(name)
		end

		current_module
	end

	def enum_kind(klass)
		parent = figure_parent(klass)
		if parent == Object
			"group"
		elsif parent.is_a?(Class)
			"class"
		elsif parent.is_a?(Module)
			"namespace"
		else
			raise("Unknown parent type: #{parent}")
		end
	end

	def enum_url(klass)
		cpp_name = klass.cpp_class.gsub(/^enum /, '')
		cpp_parts = cpp_name.split("::")

		kind = enum_kind(klass)
		xpath = if kind == "group"
							"//tagfile/compound[@kind='#{enum_kind(klass)}']/member[@kind='enumeration'][name='#{cpp_parts.last}']"
						else
							parent_name = cpp_name.split("::")[0..-2].join("::")
							"//tagfile/compound[@kind='#{enum_kind(klass)}'][name='#{parent_name}']/member[@kind='enumeration'][name='#{cpp_parts.last}']"
						end

		member_node = @doc.find_first(xpath)
		if member_node
			url(member_node)
		else
			nil
		end
	end

	def enum_value_url(node, klass, value)
		xpath = "../member[@kind='enumvalue'][name='#{value}']"
		member_node = node.find_first(xpath)
		if member_node
			url(member_node)
		else
			nil
		end
	end

	def union_url(node)
		url_node = node.find_first('filename')
  	"#{OPENCV_ROOT}/#{url_node.content}"
	end

	def attribute_url(node, native)
		# Find the member node
		attribute_name = camelize(native.name, false)

		xpath = "member[@kind='variable'][name='#{attribute_name}']"
		member_node = node&.find_first(xpath)
		if member_node
			url(member_node)
		else
			nil
		end
	end

	def figure_member_node(native, xpath)
		# First get all matching functions - remember C++ supports method overloads
		member_nodes = @doc.find(xpath)
		case member_nodes.size
			when 0
				return nil
			when 1
				return member_nodes.first
		end

		# Next filter members that have the same number of parameters
		filtered = member_nodes.find_all do |member_node|
			arglist_content = member_node.find_first('arglist').content
 			match = arglist_content.match(/\((.*)\)/)
			tag_args = match[1].split(',')
			tag_args.size == native.parameters.size
		end

		if filtered.size == 1
			return filtered.first
		end

		# Next filter on type
		filtered.first
	end

	def method_url(node, klass, native, singleton)
		member_name = if singleton
										member_name = native.name.gsub(/\?$/, "")
										camelize(member_name, false)
										member_name.capitalize
									elsif native.name == "initialize"
										cpp_name(klass).split('::').last
									else
										member_name = native.name.gsub(/\?$/, "")
										camelize(member_name, false)
									end
		xpath = if singleton
							"member[@kind='function' and @static='yes'][name='#{member_name}']"
						else
							"member[@kind='function'][name='#{member_name}']"
						end
		member_node = node&.find_first(xpath)
		if member_node
			url(member_node)
		elsif native.name == "initialize"
			class_url(node)
		end
	end
end

class MkdocsGenerator
	SPECIAL_CHARS = ["*", "_", "(", ")", "{", "}", "[", "]", "<", ">", ">>",
									 "#", "+", "-", ".", "!", "|"]

	attr_reader :klasses, :open_cv_docs, :output

	def initialize(klasses, open_cv_docs, output)
		@klasses = klasses
		@open_cv_docs = open_cv_docs
		@output = output
	end

	def generate
		FileUtils.mkdir_p(@output)

		klasses.sort_by(&:name).each.with_index do |klass, i|
			#next unless ["Affine3D"].include?(klass.name)
			#next unless klass.name.match(/Point2l/)

			STDOUT << klass.name << " (" << i << "/" << klasses.count << ")" << "\n"
			if klass.cpp_class.match(/^enum/i)
				write_enum(klass)
			elsif klass.cpp_class.match(/^union/i)
				write_union(klass)
			else
				write_class(klass)
			end
		end
	end

	def output_path(klass)
		parts = klass.name.split("::")
		path = File.join(@output, *parts[0..-2], "#{parts[-1]}.md")
		unless Dir.exist?(File.dirname(path))
			FileUtils.mkdir_p((File.dirname(path)))
		end
		path
	end

	def cross_reference_url(klass)
		parts = Array.new
		parts << "cfis/opencv-ruby/reference"
		parts += klass.name.split("::")
		"/" + parts.join("/")
	end

	def class_sig(klass, node)
		klass_name = klass.name.split("::").last

		url = open_cv_docs.class_url(node)
		if url
			"#[#{klass_name}](#{url})"
		else
			"##{klass_name}"
		end
	end

	def enum_sig(klass)
		klass_name = klass.name.split("::").last
		url = open_cv_docs.enum_url(klass)
		if url
			"#[#{klass_name} Enum](#{url})"
		else
			"##{klass_name} Enum"
		end
	end

	def enum_value_sig(node, klass, value)
		url = if node
						open_cv_docs.enum_value_url(node, klass, value)
					end

		if url
			"[#{value}](#{url})"
		else
			"#{value}"
		end
	end

	def union_sig(klass, node)
		klass_name = klass.name.split("::").last
		url = open_cv_docs.union_url(node)
		if url
			"#[#{klass_name} Union](#{url})"
		else
			"##{klass_name} Union"
		end
	end

	def method_sigs(node, klass, native_methods, method_sig)
		native_methods.map do |native_method|
			method_sig(node, klass, native_method, method_sig)
		end.join("\n\n")
	end

	def constructor_sig(node, klass, native)
		parameters = native.parameters.map do |parameter|
			"#{parameter.arg.name}: [#{parameter.klass}](#{cross_reference_url(parameter.klass)})"
		end.join(", ")

		url = open_cv_docs.method_url(node, klass, native, false)

		if url
			"[initialize](#{url})(#{parameters})"
		else
			"initialize(#{parameters})"
		end
	end

	def method_sig(node, klass, native, singleton)
		parameters = native.parameters.map do |parameter|
			"#{parameter.arg.name}: [#{parameter.klass}](#{cross_reference_url(parameter.klass)})"
		end.join(", ")

		url = open_cv_docs.method_url(node, klass, native, singleton)

		name = if SPECIAL_CHARS.include?(native.name[0])
						 "\\#{native.name}"
					 else
						 native.name
					 end

		if url
			"[#{name}](#{url})(#{parameters})"
		else
			"#{name}(#{parameters})"
		end
	end

	def attribute_sig(node, native_attributes)
		attr_type = if native_attributes.size == 2
									"read/write"
								elsif native_attributes.first.kind == Rice::NativeKind::AttributeReader
									"read"
								else
									"write"
								end

		native_attribute = native_attributes.first
		url = open_cv_docs.attribute_url(node, native_attribute)

		if url
			"[#{native_attribute.name}](#{url}): [#{native_attribute.klass}](#{cross_reference_url(native_attribute.klass)}) (#{attr_type})"
		else
			"#{native_attribute.name}: [#{native_attribute.klass}](#{cross_reference_url(native_attribute.klass)}) (#{attr_type})"
		end
	end

  def write_class(klass)
		node = open_cv_docs.class_node(klass)

		native_attributes = Rice::Registries.instance.natives.native_attributes(klass).sort.group_by(&:name)
		native_singleton_functions = Rice::Registries.instance.natives.native_singleton_functions(klass).sort.group_by(&:name)
		native_methods = Rice::Registries.instance.natives.native_methods(klass).sort.group_by(&:name)

		path = output_path(klass)
		File.open(path, 'w') do |file|
			file << class_sig(klass, node) << "\n"

			# Singleton methods
			unless native_singleton_functions.empty?
				file << "## Singleton Methods" << "\n"
				native_singleton_functions.each do |name, natives|
					file << method_sigs(node, klass, natives, true) << "\n\n"
				end
				file << "\n"
			end

			# Attributes
			unless native_attributes.empty?
				file << "## Attributes" << "\n"
				native_attributes.each do |name, natives|
					file << attribute_sig(node, natives) << "\n\n"
				end
				file << "\n"
			end

	 		# Constructor
			constructors = native_methods["initialize"]
			if constructors
				file << "## Constructors" << "\n"
				constructors.each do |constructor|
					file << constructor_sig(node, klass, constructor) << "\n\n"
				end
				file << "\n"
			end

			unless native_methods.empty?
				file << "## Methods" << "\n"
				native_methods.each do |name, natives|
					next if name == "initialize"
					file << method_sigs(node, klass, natives, false) << "\n\n"
				end
				file << "\n"
			end
		end
	end

	def write_enum(klass)
		node = open_cv_docs.enum_node(klass)

		klass_name = klass.name.split('::').last

		path = output_path(klass)
		File.open(path, 'w') do |file|
			file << enum_sig(klass) << "\n"
			file << "## Values" << "\n"
			klass.values.each do |value|
				file << "* " << enum_value_sig(node, klass, value) << "\n"
			end
		end
	end

	def write_union(klass)
		node = open_cv_docs.class_node(klass)

		klass_name = klass.name.split('::').last
		native_attributes = Rice::Registries.instance.natives.native_attributes(klass).sort.group_by(&:name)

		path = output_path(klass)
		File.open(path, 'w') do |file|
			file << union_sig(klass, node) << "\n"

			# Attributes
			unless native_attributes.empty?
				file << "## Attributes" << "\n"
				native_attributes.each do |name, natives|
					file << attribute_sig(node, natives) << "\n\n"
				end
				file << "\n"
			end
		end
	end

end

# Load the extension
source = File.expand_path(File.join(__dir__, "..", "ext", "opencv2"))
extension = File.expand_path(File.join(__dir__, "..", "ext", "build", "msvc-debug", "opencv_ruby.so"))
require extension
klasses = Rice::Registries.instance.types.klasses

# Load OpenCV documentation info
open_cv_docs = OpenCVTag.new

# Generate docs
output_path = File.expand_path(File.join('.', 'docs', 'reference'))
generator = MkdocsGenerator.new(klasses, open_cv_docs, output_path)
generator.generate
