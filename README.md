# opencv-ruby

Ruby bindings for OpenCV4 based on its C++ API. Almost all of OpenCV's API is exposed, except for CUDA support.

* Web site: <https://github.com/cfis/opencv-ruby>
* [Documentation](http://www.rubydoc.info/gems/opencv-ruby/frames)

## Requirement[config](.bundle/config)

* OpenCV <http://opencv.org/>
  * [Download](http://sourceforge.net/projects/opencvlibrary/)
  * [Install guide](http://docs.opencv.org/doc/tutorials/introduction/table_of_content_introduction/table_of_content_introduction.html#table-of-content-introduction)

## Install
### Linux/Mac
1. Install [OpenCV](http://sourceforge.net/projects/opencvlibrary/files/opencv-unix/)
2. Install opencv-ruby

```
$ gem install opencv-ruby -- --with-opencv-dir=/path/to/opencvdir
```

Note: **/path/to/opencvdir** is the directory where you installed OpenCV.


### Windows (RubyInstaller)

See [install-opencv-ruby-with-rubyinstaller-on-windows.md](install-opencv-ruby-with-rubyinstaller-on-windows.md).

## Sample code
### Load and Display an Image

A sample to load and display an image. An equivalent code of [this tutorial](http://docs.opencv.org/doc/tutorials/introduction/display_image/display_image.html#display-image).

```ruby
require 'opencv'
include OpenCV

if ARGV.size == 0
  puts "Usage: ruby #{__FILE__} ImageToLoadAndDisplay"
  exit
end

image = nil
begin
  image = CvMat.load(ARGV[0], CV_LOAD_IMAGE_COLOR) # Read the file.
rescue
  puts 'Could not open or find the image.'
  exit
end

window = GUI::Window.new('Display window') # Create a window for display.
window.show(image) # Show our image inside it.
GUI::wait_key # Wait for a keystroke in the window.
```

### Face Detection

A sample to detect faces from an image.

```ruby
require 'opencv'
include OpenCV

if ARGV.length < 2
  puts "Usage: ruby #{__FILE__} source dest"
  exit
end

data = './data/haarcascades/haarcascade_frontalface_alt.xml'
detector = CvHaarClassifierCascade::load(data)
image = CvMat.load(ARGV[0])
detector.detect_objects(image).each do |region|
  color = CvColor::Blue
  image.rectangle! region.top_left, region.bottom_right, :color => color
end

image.save_image(ARGV[1])
window = GUI::Window.new('Face detection')
window.show(image)
GUI::wait_key
```
