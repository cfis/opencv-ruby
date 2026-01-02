Gem::Specification.new do |spec|
  spec.name = "opencv-ruby"
  spec.summary = "Modern Ruby bindings for OpenCV4"
  spec.version = "1.0"
  spec.require_paths = ["lib"]
  spec.authors = ["Charlie Savage"]
  spec.date = "2025-12-01"
  spec.description = "Ruby bindings for OpenCV that uses its C++ API (version 4 and up)"
  spec.extensions = ["ext/CMakeLists.txt"]
  spec.extra_rdoc_files = ["History.txt", "License.txt", "README.md"]

  spec.homepage = "https://github.com/cfis/opencv-ruby/"
  spec.licenses = ["BSD-3-Clause"]
  spec.rdoc_options = ["--main", "README.md"]
  spec.required_ruby_version = Gem::Requirement.new(">= 3.2")

  spec.files = Dir.glob([".gitignore",
                         "Gemfile",
                         "History.txt",
                         "License.txt",
												 "Rakefile",
                         "README.md",
                         "examples/**/*.rb",
                         "ext/CMakeLists.txt",
                         "ext/CMakePresets.json",
                         "ext/opencv_ruby.def",
                         "ext/opencv_ruby-rb.cpp",
                         "ext/opencv_ruby-rb.hpp",
												 "ext/opencv_ruby_version.hpp",
												 "ext/vcpkg.json",
                         "ext/opencv2/**/*.*",
												 "ext/lib/**/*",
												 "ext/rbs/**/*",
                         "ext/rice/*.hpp",
                         "test/*.rb"])

  # 6.0 breaks RubyMine
	spec.add_development_dependency('minitest', '~>5.0')
	spec.add_development_dependency('rake')
	spec.add_development_dependency('rice')
end
