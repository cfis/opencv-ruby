if RUBY_PLATFORM =~ /mingw|mswin/
  major, minor, _ = RUBY_VERSION.split(".")
  lib_path = File.join(__dir__)

  #$LOAD_PATH.unshift(ext_path)
  path = File.join(lib_path, "#{major}.#{minor}")
  ENV["PATH"] = "#{path}#{File::PATH_SEPARATOR}#{ENV["PATH"]}"

  #begin
    require "#{major}.#{minor}/opencv_ruby.so"
    #  rescue LoadError => e
    #require "opencv_ruby"
    #end
else
  require "opencv_ruby"
end

require "opencv-ruby/version"
require "opencv-ruby/core/scalar"
require "opencv-ruby/core/mat_size"
require "opencv-ruby/core/mat"
require "opencv-ruby/core/sparse_mat"
