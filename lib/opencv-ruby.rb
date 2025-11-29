if RUBY_PLATFORM =~ /mingw|mswin/
  major, minor, subminor = RUBY_VERSION.split(".")
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
