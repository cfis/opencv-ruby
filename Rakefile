require "rubygems/package_task"
require "rake/testtask"

# Read the spec file
spec = Gem::Specification.load("opencv-ruby.gemspec")

# Setup generic gem
Gem::PackageTask.new(spec) do |pkg|
  pkg.package_dir = "pkg"
  pkg.need_tar    = false
end

# Setup Windows Gem
if RUBY_PLATFORM.match(/mswin|mingw/)
  binaries = (FileList["lib/**/*.so",
                       "lib/**/*dll"])

  # Windows specification
  win_spec = spec.clone
  win_spec.platform = Gem::Platform::CURRENT
  win_spec.files += binaries.to_a
  win_spec.instance_variable_set(:@cache_file, nil)

  # Unset extensions
  win_spec.extensions = nil

  # Rake task to build the windows package
  Gem::PackageTask.new(win_spec) do |pkg|
    pkg.package_dir = "pkg"
    pkg.need_tar = false
  end
end

desc "Run test suite"
Rake::TestTask.new(:test) do |task|
	task.libs << "test"
	task.pattern = "test/**/*_test.rb"
	task.verbose = false
end

desc "Build the documentation"
task :doc do
  build_dir = File.expand_path(File.join("doc", "_build"))
  FileUtils.rm_r(build_dir, secure: true) if File.exist?(build_dir)
  cmd = ["sphinx-build", "--builder", "html", "doc", build_dir]
  sh *cmd
end

desc "Generate API documentation using rice-doc"
task :api do
  config_file = File.expand_path("docs/rice-doc.yaml")

  cmd = ["rice-doc", config_file]
	puts cmd.join(" ")
	system *cmd
end

desc "Generate RBS signature files using rice-rbs"
task :rbs do
	require 'rbconfig'

	output = File.expand_path(File.join("sig"))
	extension = RbConfig::CONFIG["DLEXT"]
	library = File.expand_path(File.join("lib", "opencv_ruby", "3.4"))
	path = "#{library}.#{extension}"
	cmd = ["rice-rbs", "--output", output, path]
	puts cmd.join(" ")
	system *cmd
end