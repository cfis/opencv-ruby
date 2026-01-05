Gem::Specification.new do |spec|
  spec.name = "opencv-ruby"
  spec.summary = "Modern Ruby bindings for OpenCV4"
  spec.version = "1.0"
  spec.require_paths = ["lib"]
  spec.authors = ["Charlie Savage"]
  spec.date = "2026-01-04"
  spec.description = "Ruby bindings for OpenCV that uses its C++ API (version 4 and up)"
  spec.extensions = ["ext/CMakeLists.txt"]
  spec.homepage = "https://github.com/cfis/opencv-ruby/"
  spec.licenses = ["BSD-3-Clause"]
  spec.required_ruby_version = Gem::Requirement.new(">= 3.2")

  spec.files = Dir.glob([".gitignore",
                         "Gemfile",
                         "History.txt",
                         "License.txt",
												 "mkdocs.yml",
												 "Rakefile",
                         "README.md",
												 "docs/*.pages",
												 "docs/*.md",
												 "docs/*.yaml",
                         "ext/CMakeLists.txt",
                         "ext/CMakePresets.json",
                         "ext/opencv_ruby-rb.cpp",
                         "ext/opencv_ruby-rb.hpp",
												 "ext/opencv_ruby_version.hpp",
												 "ext/vcpkg.json",
                         "ext/opencv2/**/*.*",
												 "lib/**/*.rb",
                         "test/*.rb"])

	# rbs files
	rbs_files = Dir.glob("sig/**/*.rbs").reject do |path|
		path.length >= 80
	end
	spec.files += rbs_files

  # api files
  api_files = Dir.glob("docs/api/**/*.md").reject do |path|
    path.length >= 80
  end
  spec.files += api_files

  # minitest 6.0 breaks RubyMine test runner
	spec.add_development_dependency('minitest', '~>5.0')
	spec.add_development_dependency('rake')
  # No reason to depend on Rice unless you want to rebuild the docs/api or sig files
	#	spec.add_development_dependency('rice')
end
