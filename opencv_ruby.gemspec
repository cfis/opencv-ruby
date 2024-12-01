# -*- encoding: utf-8 -*-
# stub: opencv-ruby 0.0.18.20170306223602 ruby lib
# stub: ext/opencv/extconf.rb

Gem::Specification.new do |spec|
  spec.name = "opencv-ruby"
  spec.summary = "Modern Ruby bindings for OpenCV"
  spec.version = "1.0"
  spec.require_paths = ["lib"]
  spec.authors = ["Charlie Savage", "lsxi", "ser1zw", "pcting"]
  spec.date = "2025-07-31"
  spec.description = "Ruby bindings for OpenCV that use its C++ API (version 4 and up)"
  spec.extensions = ["ext/CMakeLists.txt"]
  spec.extra_rdoc_files = ["DEVELOPERS_NOTE.md", "History.txt", "License.txt", "README.md", "examples/facerec/readme.md"]

  spec.homepage = "https://github.com/cfis/opencv-ruby/"
  spec.licenses = ["BSD-3-Clause"]
  spec.rdoc_options = ["--main", "README.md"]
  spec.required_ruby_version = Gem::Requirement.new(">= 3.2")

  spec.files = Dir.glob([".gitignore",
                         ".yardopts",
                         "DEVELOPERS_NOTE.md",
                         "Gemfile",
                         "History.txt",
                         "License.txt",
                         "Manifest.txt",
												 "Rakefile",
                         "README.md",
                         "config.yml",
                         "examples/**/*.rb",
                         "ext/CMakeLists.txt",
                         "ext/CMakePresets.json",
                         "ext/opencv_ruby.def",
                         "ext/opencv_ruby-rb.cpp",
                         "ext/opencv_ruby-rb.hpp",
                         "ext/opencv2/**/*.*",
                         "ext/rice/*.hpp",
                         "test/*.rb"])

	spec.add_runtime_dependency('rice', '>= 4.6.2')
	spec.add_development_dependency('minitest')
	spec.add_development_dependency('rake')
	spec.add_development_dependency('yard')
end
