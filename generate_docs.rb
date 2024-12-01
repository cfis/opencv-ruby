#!/usr/bin/env ruby

require 'fileutils'
require 'open-uri'
require 'rexml/document'
require 'pathname'

SRC_ROOT = 'ext/opencv2'
DOCS_ROOT = 'doc'
TAG_URL = 'https://docs.opencv.org/4.x/opencv.tag'
TAG_FILE = 'tmp/opencv.tag'

DEFINE_CLASS_UNDER_RE = /define_class_under<\s*([^>]+)\s*>\(\s*(rb_m\w+),\s*"(\w+)"\)/
DEFINE_METHOD_RE = /define_method(?:<([^>]+)>)?\(\s*"(\w+)",\s*([^,\)]+)(?:,\s*(.*?))?\)/m
DEFINE_ATTR_RE = /define_attr\(\s*"(\w+)",\s*&([\w:]+)::(\w+)\)/
DEFINE_ENUM_UNDER_RE = /define_enum_under<([^>]+)>\(\s*"(\w+)",\s*(rb_c\w+)\)/
DEFINE_VALUE_RE = /define_value\("(\w+)",\s*([^\)]+)\)/

class BoundMethod
	attr_reader :ruby_name, :cpp_signature, :args, :doc_url

	def initialize(ruby_name, cpp_signature, args)
		@ruby_name = ruby_name
		@cpp_signature = cpp_signature
		@args = args
		@doc_url = nil
	end

	def set_doc_url(url)
		@doc_url = url
	end
end

class BoundAttribute
	attr_reader :ruby_name, :cpp_class, :doc_url

	def initialize(ruby_name, cpp_class)
		@ruby_name = ruby_name
		@cpp_class = cpp_class
		@doc_url = nil
	end

	def set_doc_url(url)
		@doc_url = url
	end
end

class BoundEnum
	attr_reader :ruby_name, :cpp_enum, :values, :doc_url

	def initialize(ruby_name, cpp_enum)
		@ruby_name = ruby_name
		@cpp_enum = cpp_enum
		@values = []
		@doc_url = nil
	end

	def add_value(ruby_name, cpp_value)
		@values << [ruby_name, cpp_value]
	end

	def set_doc_url(url)
		@doc_url = url
	end
end

class BoundClass
	attr_reader :ruby_name, :cpp_namespace, :cpp_class, :methods, :attributes, :enums
	attr_accessor :doc_url

	def initialize(ruby_name, cpp_namespace, cpp_class)
		@ruby_name = ruby_name
		@cpp_namespace = cpp_namespace
		@cpp_class = cpp_class
		@methods = []
		@attributes = []
		@enums = []
		@doc_url = nil
	end

	def add_method(method)
		@methods << method
	end

	def add_attribute(attr)
		@attributes << attr
	end

	def add_enum(enum)
		@enums << enum
	end
end

class BoundModule
	attr_reader :name, :classes, :submodules

	def initialize(name)
		@name = name
		@classes = {}
		@submodules = {}
	end

	def add_class(cls)
		@classes[cls.ruby_name] = cls
	end

	def find_or_create_submodule(name)
		@submodules[name] ||= BoundModule.new(name)
	end

	def write_rst(output_dir)
		module_dir = File.join(output_dir, name.downcase)
		FileUtils.mkdir_p(module_dir)
		index_path = File.join(module_dir, 'index.rst')
		File.open(index_path, 'w') do |f|
			f.puts "#{name} Module"
			f.puts "#{'=' * (name.length + 7)}"
			f.puts ""
			f.puts ".. toctree::"
			f.puts "   :maxdepth: 1"
			f.puts ""
			@classes.each_key do |cls|
				f.puts "   #{cls.downcase}"
			end
		end

		@classes.each_value do |cls|
			cls_path = File.join(module_dir, "#{cls.ruby_name.downcase}.rst")
			File.open(cls_path, 'w') do |f|
				f.puts "#{cls.ruby_name}"
				f.puts "#{'=' * cls.ruby_name.length}"
				f.puts ""
				f.puts "**C++ class**: ``#{cls.cpp_namespace}::#{cls.cpp_class}``"
				f.puts ""

				# Constructor section
				constructors = cls.methods.select { |m| m.ruby_name == 'initialize' }
				f.puts ".. rubric:: Constructor"
				f.puts ""
				if constructors.empty?
					f.puts "No documented constructors."
				else
					constructors.each do |ctor|
						link = ctor.doc_url ? " (`OpenCV Docs <#{ctor.doc_url}>`_)" : ""
						f.puts "- ``#{ctor.ruby_name}(#{ctor.args.join(', ')})``#{link}"
					end
				end

				# Attributes section - alphabetized
				f.puts "\n.. rubric:: Attributes"
				f.puts ""
				if cls.attributes.empty?
					f.puts "No documented attributes."
				else
					cls.attributes.sort_by(&:ruby_name).each do |a|
						link = a.doc_url ? " (`OpenCV Docs <#{a.doc_url}>`_)" : ""
						f.puts "- ``#{a.ruby_name}``#{link}"
					end
				end

				# Methods section - alphabetized excluding constructors
				f.puts "\n.. rubric:: Methods"
				f.puts ""
				methods = cls.methods.reject { |m| m.ruby_name == 'initialize' }
				if methods.empty?
					f.puts "No documented methods."
				else
					methods.sort_by(&:ruby_name).each do |m|
						link = m.doc_url ? " (`OpenCV Docs <#{m.doc_url}>`_)" : ""
						f.puts "- ``#{m.ruby_name}(#{m.args.join(', ')})``#{link}"
					end
				end

				# Enums section
				f.puts "\n.. rubric:: Enums"
				f.puts ""
				if cls.enums.empty?
					f.puts "No documented enums."
				else
					cls.enums.each do |e|
						link = e.doc_url ? " (`OpenCV Docs <#{e.doc_url}>`_)" : ""
						f.puts "- ``#{e.ruby_name}``#{link}"
						e.values.each do |val|
							f.puts "  - #{val[0]} = #{val[1]}"
						end
					end
				end
			end
		end

		@submodules.each_value { |m| m.write_rst(output_dir) }
	end
end

class OpenCVTagParser
	attr_reader :tag_file, :tags

	def initialize(tag_file)
		@tag_file = tag_file
		@tags = {}
	end

	def download_tag_file
		FileUtils.mkdir_p(File.dirname(@tag_file))
		open(TAG_URL) do |remote|
			File.open(@tag_file, "wb") do |local|
				local.write(remote.read)
			end
		end
	end

	def parse_tag_file
		# The tag file is a ctags format, tab-separated: name, file, pattern, kind, ...
		File.foreach(@tag_file) do |line|
			next if line.start_with?('!_TAG_') # skip header lines
			parts = line.chomp.split("\t")
			name = parts[0]
			file = parts[1]
			pattern = parts[2]
			kind = parts[3]

			# Store info keyed by name; may have multiple entries per name, keep array
			@tags[name] ||= []
			@tags[name] << {
				file: file,
				pattern: pattern,
				kind: kind
			}
		end
	end

	# Returns OpenCV documentation URL for a given class or method, or nil if not found
	def find_doc_url(name, kind_hint = nil)
		entries = @tags[name]
		return nil if entries.nil?

		# Prefer class or struct entries for classes
		if kind_hint == :class
			entry = entries.find { |e| e[:kind] == 'class' || e[:kind] == 'struct' }
			entry ||= entries.first
		elsif kind_hint == :method
			# For methods, prefer kind 'function' or 'member'
			entry = entries.find { |e| ['function', 'member'].include?(e[:kind]) }
			entry ||= entries.first
		else
			entry = entries.first
		end

		return nil if entry.nil?

		# Build full doc URL
		# OpenCV doc URL base
		base_url = "https://docs.opencv.org/4.x/"

		# The file field looks like: d3/d63/classcv_1_1Mat.html
		# Compose full URL with base_url + file
		url = base_url + entry[:file]
		url
	end
end

class RiceBindingParser
	attr_reader :src_root, :docs_root, :modules, :opencv_tag_parser

	def initialize(src_root, docs_root)
		@src_root = src_root
		@docs_root = docs_root
		@modules = {}
		@opencv_tag_parser = OpenCVTagParser.new(TAG_FILE)
	end

	def parse_all
		# Download and parse OpenCV tags once
		unless File.exist?(TAG_FILE)
			puts "Downloading OpenCV tag file..."
			@opencv_tag_parser.download_tag_file
		end
		@opencv_tag_parser.parse_tag_file

		# Parse all source files recursively
		Dir.glob(File.join(@src_root, '**', '*.cpp')) do |file|
			parse_file(file)
		end
	end

	def parse_file(file)
		content = File.read(file)
		# Find classes
		content.scan(DEFINE_CLASS_UNDER_RE) do |cpp_class, module_var, ruby_name|
			cpp_namespace = cpp_class.split('::')[0...-1].join('::')
			cpp_class_name = cpp_class.split('::').last

			# Determine module name from module_var, fallback to top-level 'CV'
			module_name = module_var.sub(/^rb_m/, '').capitalize
			mod = @modules[module_name] ||= BoundModule.new(module_name)

			cls = BoundClass.new(ruby_name, cpp_namespace, cpp_class_name)
			mod.add_class(cls)

			# Attach OpenCV doc url to class if available
			cls_url = @opencv_tag_parser.find_doc_url(cpp_class_name, :class)
			cls.doc_url = cls_url if cls_url
		end

		# Find methods
		content.scan(DEFINE_METHOD_RE) do |template, ruby_name, cpp_func, flags|
			# Example: define_method<void>("foo", &SomeClass::foo)
			# Extract class from cpp_func if possible
			if cpp_func =~ /&([\w:]+)::(\w+)/
				cpp_class = $1
				method_name = ruby_name
				args = [] # no argument parsing here, could be enhanced

				# Find the BoundClass that matches this cpp_class
				@modules.values.each do |mod|
					mod.classes.values.each do |cls|
						if cls.cpp_class == cpp_class.split('::').last
							method = BoundMethod.new(ruby_name, cpp_func, args)
							# Try to find doc_url for method
							method_url = @opencv_tag_parser.find_doc_url(method_name, :method)
							method.set_doc_url(method_url) if method_url
							cls.add_method(method)
						end
					end
				end
			end
		end

		# Find attributes
		content.scan(DEFINE_ATTR_RE) do |ruby_name, cpp_class, cpp_attr|
			# cpp_class may be fully qualified
			cpp_class_name = cpp_class.split('::').last

			@modules.values.each do |mod|
				mod.classes.values.each do |cls|
					if cls.cpp_class == cpp_class_name
						attr = BoundAttribute.new(ruby_name, cpp_class)
						attr_url = @opencv_tag_parser.find_doc_url(ruby_name)
						attr.set_doc_url(attr_url) if attr_url
						cls.add_attribute(attr)
					end
				end
			end
		end

		# Find enums
		content.scan(DEFINE_ENUM_UNDER_RE) do |cpp_enum, ruby_name, rb_cvar|
			# cpp_enum is full enum name with namespace
			cpp_enum_name = cpp_enum.split('::').last

			@modules.values.each do |mod|
				mod.classes.values.each do |cls|
					if cls.ruby_name == ruby_name || cls.cpp_class == cpp_enum_name
						enum = BoundEnum.new(ruby_name, cpp_enum)
						cls.add_enum(enum)

						# Add enum values
						# We need to find define_value inside this enum block - naive approach
						# This example is basic and may be incomplete
						content.scan(DEFINE_VALUE_RE) do |val_name, val_val|
							enum.add_value(val_name, val_val)
						end

						# Try to find enum doc url
						enum_url = @opencv_tag_parser.find_doc_url(ruby_name)
						enum.set_doc_url(enum_url) if enum_url
					end
				end
			end
		end
	end

	def write_docs
		FileUtils.mkdir_p(@docs_root)
		@modules.each_value do |mod|
			mod.write_rst(@docs_root)
		end

		# Write top-level index.rst
		index_path = File.join(@docs_root, 'index.rst')
		File.open(index_path, 'w') do |f|
			f.puts "Rice Documentation"
			f.puts "=================="
			f.puts ""
			f.puts ".. toctree::"
			f.puts "   :maxdepth: 2"
			f.puts ""
			@modules.each_key do |mod_name|
				f.puts "   #{mod_name.downcase}/index"
			end
		end
	end

	def print_summary
		total_modules = @modules.size
		total_classes = @modules.values.sum { |m| m.classes.size }
		total_enums = @modules.values.sum { |m| m.classes.values.sum { |c| c.enums.size } }

		puts "Summary:"
		puts "  Modules documented: #{total_modules}"
		puts "  Classes documented: #{total_classes}"
		puts "  Enums documented:   #{total_enums}"
	end
end

# Main execution
parser = RiceBindingParser.new(SRC_ROOT, DOCS_ROOT)
parser.parse_all
parser.write_docs
parser.print_summary
puts "Documentation generation complete."
