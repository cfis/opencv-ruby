if RUBY_PLATFORM =~ /mingw|mswin/
	lib_path = File.join(__dir__)
	#$LOAD_PATH.unshift(ext_path)
	ENV["PATH"] = "#{lib_path}#{File::PATH_SEPARATOR}#{ENV["PATH"]}"

  major, minor, _ = RUBY_VERSION.split(".")
  begin
    require "#{major}.#{minor}/opencv_ruby.so"
  rescue LoadError
    require "opencv_ruby.so"
  end
else
  require "opencv_ruby.so"
end

require "opencv-ruby/version"
require "opencv-ruby/core/scalar"
require "opencv-ruby/core/mat_size"
require "opencv-ruby/core/mat"
require "opencv-ruby/core/sparse_mat"
