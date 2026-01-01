# Python to Ruby Translation

Many developers learn OpenCV through Python. While opencv-ruby can accomplish the same tasks, there are significant differences because **opencv-ruby wraps the C++ API directly**, whereas **Python's cv2 module has its own conventions**.

## Key Differences

| Aspect | Python (cv2) | Ruby (opencv-ruby) |
|--------|--------------|-------------------|
| **Array type** | NumPy `ndarray` | `Cv::Mat` |
| **Function style** | `cv2.function()` | `Cv.function()` or `mat.method()` |
| **Output handling** | Returns result | Often uses `output_array` parameter |
| **Enums** | Integer constants | Enum classes |
| **Memory** | NumPy manages | Ruby GC manages |

**Important**: The differences between Python and Ruby are larger than between C++ and Ruby. When possible, refer to C++ documentation and the [C++ to Ruby](cpp-to-ruby.md) guide.

## NumPy Arrays vs Cv::Mat

The biggest difference is data representation.

### Python: NumPy Arrays

```python
# Python - uses NumPy ndarrays
import cv2
import numpy as np

# Images are NumPy arrays
image = cv2.imread("photo.jpg")
print(type(image))  # <class 'numpy.ndarray'>
print(image.shape)  # (480, 640, 3)

# Create arrays with NumPy
zeros = np.zeros((480, 640), dtype=np.uint8)
ones = np.ones((480, 640, 3), dtype=np.uint8) * 255

# Direct pixel access via NumPy indexing
pixel = image[100, 200]  # BGR tuple
image[100, 200] = [255, 0, 0]  # Set pixel
```

### Ruby: Cv::Mat

```ruby
# Ruby - uses Cv::Mat objects
require 'opencv-ruby'

# Images are Mat objects
image = Cv.imread("photo.jpg")
puts image.class  # Cv::Mat
puts "#{image.rows}x#{image.cols}"  # 480x640

# Create matrices with Mat methods
zeros = Cv::Mat.zeros(480, 640, CV_8UC1).to_mat
ones = Cv::Mat.new(480, 640, CV_8UC3, Cv::Scalar.new(255, 255, 255))

# Pixel access via Mat indexing
pixel = image[100, 200]  # Returns Vec3b
image[100, 200] = Cv::Vec3b.new(255, 0, 0)  # Set pixel
```

## Function Calling Conventions

### Python: Returns Results Directly

```python
# Python - functions return results
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(gray, (5, 5), 1.5)
edges = cv2.Canny(blurred, 50, 150)
```

### Ruby: Uses Input/Output Arrays

```ruby
# Ruby - often uses explicit output arrays
gray = Cv::Mat.new
Cv.cvt_color(image.input_array, gray.output_array, Cv::ColorConversionCodes::COLOR_BGR2GRAY)

blurred = Cv::Mat.new
Cv.gaussian_blur(gray.input_array, blurred.output_array, Cv::Size.new(5, 5), 1.5)

edges = Cv::Mat.new
Cv.canny(blurred.input_array, edges.output_array, 50, 150)

# Many methods also have convenience versions
blurred = gray.gaussian_blur(Cv::Size.new(5, 5), 1.5)
```

## Enums and Constants

### Python: Integer Constants

```python
# Python - bare integer constants
gray = cv2.imread("photo.jpg", cv2.IMREAD_GRAYSCALE)
_, binary = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
resized = cv2.resize(image, (320, 240), interpolation=cv2.INTER_LINEAR)
```

### Ruby: Enum Classes

```ruby
# Ruby - enum classes with namespacing
gray = Cv.imread("photo.jpg", Cv::ImreadModes::IMREAD_GRAYSCALE)

binary = Cv::Mat.new
Cv.threshold(gray.input_array, binary.output_array, 127, 255, Cv::ThresholdTypes::THRESH_BINARY)

resized = Cv::Mat.new
Cv.resize(image.input_array, resized.output_array, Cv::Size.new(320, 240), 0, 0,
          Cv::InterpolationFlags::INTER_LINEAR)
```

## Common Operations Comparison

### Reading and Writing Images

```python
# Python
image = cv2.imread("input.jpg")
cv2.imwrite("output.png", image)

# With flags
gray = cv2.imread("input.jpg", cv2.IMREAD_GRAYSCALE)
cv2.imwrite("output.jpg", image, [cv2.IMWRITE_JPEG_QUALITY, 95])
```

```ruby
# Ruby
image = Cv.imread("input.jpg")
Cv.imwrite("output.png", image.input_array)

# With flags
gray = Cv.imread("input.jpg", Cv::ImreadModes::IMREAD_GRAYSCALE)
Cv.imwrite("output.jpg", image.input_array, [Cv::ImwriteFlags::IMWRITE_JPEG_QUALITY, 95])
```

### Color Conversion

```python
# Python
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
```

```ruby
# Ruby
gray = Cv::Mat.new
Cv.cvt_color(image.input_array, gray.output_array, Cv::ColorConversionCodes::COLOR_BGR2GRAY)

hsv = Cv::Mat.new
Cv.cvt_color(image.input_array, hsv.output_array, Cv::ColorConversionCodes::COLOR_BGR2HSV)
```

### Drawing

```python
# Python
cv2.rectangle(image, (50, 50), (150, 150), (0, 0, 255), 2)
cv2.circle(image, (200, 200), 50, (0, 255, 0), -1)
cv2.line(image, (0, 0), (400, 400), (255, 0, 0), 3)
cv2.putText(image, "Hello", (50, 350), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 0, 0), 2)
```

```ruby
# Ruby
Cv.rectangle(image.input_output_array,
  Cv::Point.new(50, 50), Cv::Point.new(150, 150),
  Cv::Scalar.new(0, 0, 255), 2)

Cv.circle(image.input_output_array,
  Cv::Point.new(200, 200), 50,
  Cv::Scalar.new(0, 255, 0), -1)

Cv.line(image.input_output_array,
  Cv::Point.new(0, 0), Cv::Point.new(400, 400),
  Cv::Scalar.new(255, 0, 0), 3)

Cv.put_text(image.input_output_array, "Hello",
  Cv::Point.new(50, 350),
  Cv::HersheyFonts::FONT_HERSHEY_SIMPLEX, 1.0,
  Cv::Scalar.new(0, 0, 0), 2)
```

### Thresholding

```python
# Python - returns tuple (threshold_value, result)
_, binary = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
_, otsu = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

adaptive = cv2.adaptiveThreshold(gray, 255,
    cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2)
```

```ruby
# Ruby
binary = Cv::Mat.new
Cv.threshold(gray.input_array, binary.output_array, 127, 255, Cv::ThresholdTypes::THRESH_BINARY)

otsu = Cv::Mat.new
Cv.threshold(gray.input_array, otsu.output_array, 0, 255,
  Cv::ThresholdTypes::THRESH_BINARY | Cv::ThresholdTypes::THRESH_OTSU)

adaptive = gray.adaptive_threshold(255,
  Cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_GAUSSIAN_C,
  Cv::ThresholdTypes::THRESH_BINARY, 11, 2)
```

### Contours

```python
# Python
contours, hierarchy = cv2.findContours(binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
cv2.drawContours(image, contours, -1, (0, 255, 0), 2)

for contour in contours:
    area = cv2.contourArea(contour)
    x, y, w, h = cv2.boundingRect(contour)
```

```ruby
# Ruby
contours, hierarchy = binary.find_contours(
  Cv::RetrievalModes::RETR_EXTERNAL,
  Cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE)

Cv.draw_contours(image.input_output_array, contours, -1, Cv::Scalar.new(0, 255, 0), 2)

contours.each do |contour|
  area = Cv.contour_area(Cv::InputArray.new(contour))
  rect = Cv.bounding_rect(Cv::InputArray.new(contour))
  x, y, w, h = rect.x, rect.y, rect.width, rect.height
end
```

### Feature Detection

```python
# Python
orb = cv2.ORB_create()
keypoints = orb.detect(gray, None)
keypoints, descriptors = orb.detectAndCompute(gray, None)

# Draw keypoints
output = cv2.drawKeypoints(gray, keypoints, None)
```

```ruby
# Ruby
orb = Cv::ORB.create
keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
orb.detect(gray.input_array, keypoints)

keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
descriptors = Cv::Mat.new
orb.detect_and_compute(gray.input_array, Cv::Mat.new.input_array, keypoints, descriptors.output_array)

# Draw keypoints
output = Cv::Mat.new
Cv.draw_keypoints(gray.input_array, keypoints, output.output_array)
```

### Video Capture

```python
# Python
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Process frame...

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
```

```ruby
# Ruby
cap = Cv::VideoCapture.new(0)

frame = Cv::Mat.new
while cap.read(frame.output_array)
  break if frame.empty?

  # Process frame...

  break if Cv.wait_key(1) == 'q'.ord
end

cap.release
```

## Python Convenience vs Ruby Explicitness

Python's OpenCV bindings include many conveniences that Ruby doesn't have:

| Python Convenience | Ruby Equivalent |
|-------------------|-----------------|
| `image.shape` | `[image.rows, image.cols, image.channels]` |
| `image.dtype` | `image.type` or `image.depth` |
| `image.copy()` | `image.clone` |
| `image[y, x]` | `image[y, x]` (similar) |
| `image[y1:y2, x1:x2]` (slicing) | `image.row_range(...).col_range(...)` |
| NumPy broadcasting | Manual loops or OpenCV functions |
| `np.array([...])` | `Cv::Mat.new(...)` with data |

## Tips for Python Users

1. **Always create output Mats**: Unlike Python where functions return results, Ruby often requires pre-creating output matrices.

2. **Use `.input_array` and `.output_array`**: These are required for most OpenCV functions in Ruby.

3. **Enum names are longer**: `cv2.THRESH_BINARY` becomes `Cv::ThresholdTypes::THRESH_BINARY`.

4. **Check the tests**: The `test/` folder has Ruby examples for almost every API.

5. **Refer to C++ docs**: Since Ruby wraps C++ directly, C++ documentation is more accurate than Python docs.

6. **Type conversions differ**: No automatic NumPy ↔ list conversion; use explicit `Std::Vector≺T≻` types.

## See Also

- [C++ to Ruby](cpp-to-ruby.md) - More direct translation guide (recommended)
- [Type Mappings](type-mappings.md) - Complete type reference
- [Getting Started](getting-started.md) - Common operations with examples
