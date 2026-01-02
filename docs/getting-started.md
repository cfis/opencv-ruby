# Getting Started

## Following OpenCV Documentation

The opencv-ruby API closely mirrors OpenCV's C++ API. This means:

- **C++ tutorials work directly** - OpenCV's extensive [C++ tutorials](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html) translate almost 1:1 to Ruby
- **Python examples need adaptation** - OpenCV's Python API uses different conventions (NumPy arrays, different naming)

When learning OpenCV with Ruby, we recommend following **C++ examples** rather than Python ones. See [C++ to Ruby](cpp-to-ruby.md) for the translation guide, or [Python to Ruby](python-to-ruby.md) if coming from Python.

## Quick Reference

For detailed type and naming mappings, see:

- [C++ to Ruby](cpp-to-ruby.md) - Method naming, namespaces, enums, InputArray/OutputArray
- [Python to Ruby](python-to-ruby.md) - Key differences from Python's cv2 module
- [Type Mappings](type-mappings.md) - Complete C++ to Ruby type reference

## Common Operations

### Loading and Saving Images

```ruby
# Load a color image
image = Cv.imread('photo.jpg', Cv::ImreadModes::IMREAD_COLOR)

# Load as grayscale
gray = Cv.imread('photo.jpg', Cv::ImreadModes::IMREAD_GRAYSCALE)

# Save an image
Cv.imwrite('output.png', image.input_array)

# Save with options (JPEG quality)
Cv.imwrite('output.jpg', image.input_array, [Cv::ImwriteFlags::IMWRITE_JPEG_QUALITY, 95])
```

### Color Conversion

```ruby
# BGR to Grayscale
gray = Cv::Mat.new
Cv.cvt_color(image.input_array, gray.output_array, Cv::ColorConversionCodes::COLOR_BGR2GRAY)

# BGR to HSV
hsv = Cv::Mat.new
Cv.cvt_color(image.input_array, hsv.output_array, Cv::ColorConversionCodes::COLOR_BGR2HSV)
```

### Image Filtering

```ruby
# Gaussian blur
blurred = image.gaussian_blur(Cv::Size.new(5, 5), 1.5)

# Or using the module function
blurred = Cv::Mat.new
Cv.gaussian_blur(image.input_array, blurred.output_array, Cv::Size.new(5, 5), 1.5)

# Bilateral filter (edge-preserving)
filtered = image.bilateral_filter(9, 75, 75)

# Median blur
median = image.median_blur(5)
```

### Edge Detection

```ruby
# Canny edge detection
edges = Cv::Mat.new
Cv.canny(gray.input_array, edges.output_array, 50, 150)

# Sobel derivatives
sobel_x = Cv::Mat.new
Cv.sobel(gray.input_array, sobel_x.output_array, CV_64F, 1, 0)
```

### Thresholding

```ruby
# Simple threshold
binary = Cv::Mat.new
Cv.threshold(gray.input_array, binary.output_array, 127, 255, Cv::ThresholdTypes::THRESH_BINARY)

# Otsu's automatic thresholding
_, binary = gray.threshold(0, 255, Cv::ThresholdTypes::THRESH_BINARY | Cv::ThresholdTypes::THRESH_OTSU)

# Adaptive threshold
adaptive = gray.adaptive_threshold(255,
  Cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_GAUSSIAN_C,
  Cv::ThresholdTypes::THRESH_BINARY, 11, 2)
```

### Drawing

```ruby
# Create a canvas
canvas = Cv::Mat.new(400, 400, CV_8UC3, Cv::Scalar.new(255, 255, 255))

# Draw a rectangle
Cv.rectangle(canvas.input_output_array,
  Cv::Point.new(50, 50), Cv::Point.new(150, 150),
  Cv::Scalar.new(0, 0, 255), 2)

# Draw a circle
Cv.circle(canvas.input_output_array,
  Cv::Point.new(200, 200), 50,
  Cv::Scalar.new(0, 255, 0), -1)  # -1 = filled

# Draw a line
Cv.line(canvas.input_output_array,
  Cv::Point.new(0, 0), Cv::Point.new(400, 400),
  Cv::Scalar.new(255, 0, 0), 3)

# Put text
Cv.put_text(canvas.input_output_array, "Hello OpenCV!",
  Cv::Point.new(50, 350),
  Cv::HersheyFonts::FONT_HERSHEY_SIMPLEX, 1.0,
  Cv::Scalar.new(0, 0, 0), 2)
```

### Finding Contours

```ruby
# Find contours
contours, hierarchy = binary.find_contours(
  Cv::RetrievalModes::RETR_EXTERNAL,
  Cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE)

# Draw contours
Cv.draw_contours(image.input_output_array, contours, -1, Cv::Scalar.new(0, 255, 0), 2)

# Get contour area
area = Cv.contour_area(Cv::InputArray.new(contours[0]))
```

### Feature Detection

```ruby
# Create ORB detector
orb = Cv::ORB.create

# Detect keypoints
keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
orb.detect(gray.input_array, keypoints)

# Compute descriptors
descriptors = Cv::Mat.new
orb.compute(gray.input_array, keypoints, descriptors.output_array)

# Or detect and compute together
keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
descriptors = Cv::Mat.new
orb.detect_and_compute(gray.input_array, Cv::Mat.new.input_array, keypoints, descriptors.output_array)
```

### Video Capture

```ruby
# Open camera
cap = Cv::VideoCapture.new(0)

# Or open video file
cap = Cv::VideoCapture.new('video.mp4')

# Check if opened
unless cap.opened?
  puts "Failed to open video"
  exit
end

# Read frames
frame = Cv::Mat.new
while cap.read(frame.output_array)
  # Process frame...
  break if frame.empty?
end

cap.release
```

## Displaying Images

For GUI display, you can use OpenCV's HighGUI module:

```ruby
# Create a window
Cv.named_window("Display", Cv::WindowFlags::WINDOW_AUTOSIZE)

# Show image
Cv.imshow("Display", image.input_array)

# Wait for key press (0 = indefinitely)
Cv.wait_key(0)

# Destroy window
Cv.destroy_all_windows
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

## Where to Learn More

- **Test Suite** - The `test/` folder contains Ruby examples for almost every API. These are excellent references for real-world usage patterns.
- [C++ to Ruby](cpp-to-ruby.md) - Translation guide for C++ code
- [Python to Ruby](python-to-ruby.md) - Guide for Python OpenCV users
- [Type Mappings](type-mappings.md) - Complete type reference
- [OpenCV C++ Tutorials](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html) - Primary learning resource
- [OpenCV API Reference](https://docs.opencv.org/4.x/) - Detailed function documentation
- [API Reference](api/Cv/index.md) - Ruby-specific API documentation
