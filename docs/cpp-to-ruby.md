# C++ to Ruby Translation

The opencv-ruby API closely mirrors OpenCV's C++ API. This guide shows how to translate C++ code to Ruby.

## Why Follow C++ Examples?

OpenCV's documentation and tutorials are primarily written for C++. Since opencv-ruby directly wraps the C++ API:

- **C++ tutorials translate almost 1:1** to Ruby
- **Function signatures match** (with Ruby naming conventions)
- **Class hierarchies are preserved**

The `test/` folder contains Ruby examples for almost every API - these are excellent references for real-world usage patterns.

## Naming Conventions

### Methods: camelCase → snake_case

C++ uses `camelCase`, Ruby uses `snake_case`:

| C++ | Ruby |
|-----|------|
| `cv::imread()` | `Cv.imread()` |
| `cv::cvtColor()` | `Cv.cvt_color()` |
| `cv::GaussianBlur()` | `Cv.gaussian_blur()` |
| `mat.convertTo()` | `mat.convert_to()` |
| `mat.copyTo()` | `mat.copy_to()` |
| `detector.detectAndCompute()` | `detector.detect_and_compute()` |

### Namespaces → Modules

C++ namespaces map directly to Ruby modules:

| C++ | Ruby |
|-----|------|
| `cv::` | `Cv::` |
| `cv::ml::` | `Cv::Ml::` |
| `cv::dnn::` | `Cv::Dnn::` |
| `cv::aruco::` | `Cv::Aruco::` |
| `cv::cuda::` | `Cv::Cuda::` |
| `cv::flann::` | `Cv::Flann::` |

### Enums

C++ enums become Ruby constants nested under a class:

```cpp
// C++
cv::imread("image.jpg", cv::IMREAD_GRAYSCALE);
cv::threshold(src, dst, 127, 255, cv::THRESH_BINARY);
cv::resize(src, dst, size, 0, 0, cv::INTER_LINEAR);
```

```ruby
# Ruby
Cv.imread("image.jpg", Cv::ImreadModes::IMREAD_GRAYSCALE)
Cv.threshold(src.input_array, dst.output_array, 127, 255, Cv::ThresholdTypes::THRESH_BINARY)
Cv.resize(src.input_array, dst.output_array, size, 0, 0, Cv::InterpolationFlags::INTER_LINEAR)
```

Common enum classes:
- `Cv::ImreadModes` - Image loading flags
- `Cv::ImwriteFlags` - Image saving options
- `Cv::ColorConversionCodes` - Color space conversions
- `Cv::ThresholdTypes` - Thresholding methods
- `Cv::BorderTypes` - Border handling modes
- `Cv::InterpolationFlags` - Resize interpolation

## InputArray and OutputArray

OpenCV uses `InputArray` and `OutputArray` for flexible parameter handling. In Ruby, you explicitly create these from Mat objects:

```cpp
// C++
cv::Mat src, dst;
cv::GaussianBlur(src, dst, cv::Size(5, 5), 1.5);
```

```ruby
# Ruby
src = Cv::Mat.new
dst = Cv::Mat.new
Cv.gaussian_blur(src.input_array, dst.output_array, Cv::Size.new(5, 5), 1.5)
```

**The three array types:**

| Method | Purpose | When to Use |
|--------|---------|-------------|
| `mat.input_array` | Read-only input | Source images, masks |
| `mat.output_array` | Write-only output | Destination images |
| `mat.input_output_array` | Read and write | In-place modifications |

Many methods also have convenience wrappers that handle this automatically:

```ruby
# Using convenience method (returns new Mat)
blurred = src.gaussian_blur(Cv::Size.new(5, 5), 1.5)

# Equivalent explicit version
dst = Cv::Mat.new
Cv.gaussian_blur(src.input_array, dst.output_array, Cv::Size.new(5, 5), 1.5)
```

## Creating Objects

### Matrices

```cpp
// C++
cv::Mat empty;
cv::Mat sized(480, 640, CV_8UC3);
cv::Mat filled(480, 640, CV_8UC3, cv::Scalar(255, 0, 0));
cv::Mat zeros = cv::Mat::zeros(480, 640, CV_8UC1);
cv::Mat ones = cv::Mat::ones(480, 640, CV_8UC1);
cv::Mat eye = cv::Mat::eye(3, 3, CV_64FC1);
```

```ruby
# Ruby
empty = Cv::Mat.new
sized = Cv::Mat.new(480, 640, CV_8UC3)
filled = Cv::Mat.new(480, 640, CV_8UC3, Cv::Scalar.new(255, 0, 0))
zeros = Cv::Mat.zeros(480, 640, CV_8UC1).to_mat
ones = Cv::Mat.ones(480, 640, CV_8UC1).to_mat
eye = Cv::Mat.eye(3, 3, CV_64FC1).to_mat
```

Note: `zeros()`, `ones()`, and `eye()` return `MatExpr`, so call `.to_mat` to get a `Mat`.

### Points, Sizes, Rects

```cpp
// C++
cv::Point pt(10, 20);
cv::Point2f ptf(10.5, 20.5);
cv::Size sz(640, 480);
cv::Rect rect(0, 0, 100, 100);
cv::Scalar color(255, 0, 0);
```

```ruby
# Ruby
pt = Cv::Point.new(10, 20)
ptf = Cv::Point2f.new(10.5, 20.5)
sz = Cv::Size.new(640, 480)
rect = Cv::Rect.new(0, 0, 100, 100)
color = Cv::Scalar.new(255, 0, 0)
```

## Type Constants

Matrix type constants are global constants in Ruby:

```ruby
CV_8UC1   # 8-bit unsigned, 1 channel (grayscale)
CV_8UC3   # 8-bit unsigned, 3 channels (BGR color)
CV_8UC4   # 8-bit unsigned, 4 channels (BGRA)
CV_16SC1  # 16-bit signed, 1 channel
CV_32FC1  # 32-bit float, 1 channel
CV_64FC1  # 64-bit float, 1 channel
```

## Static Methods / Factory Functions

C++ static methods become Ruby class methods:

```cpp
// C++
cv::Ptr<cv::ORB> orb = cv::ORB::create();
cv::Ptr<cv::SIFT> sift = cv::SIFT::create(500);
cv::Ptr<cv::CascadeClassifier> cascade = cv::CascadeClassifier::create();
```

```ruby
# Ruby
orb = Cv::ORB.create
sift = Cv::SIFT.create(500)
cascade = Cv::CascadeClassifier.new
```

## STL Containers

C++ `std::vector<T>` maps to `Std::Vector≺T≻` in Ruby:

```cpp
// C++
std::vector<cv::KeyPoint> keypoints;
std::vector<cv::DMatch> matches;
std::vector<std::vector<cv::Point>> contours;
```

```ruby
# Ruby
keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
matches = Std::Vector≺cv꞉꞉DMatch≻.new
contours = Std::Vector≺vector≺cv꞉꞉Point_≺int≻≻≻.new
```

Note the special Unicode characters in Ruby type names (`≺`, `≻`, `꞉꞉`).

## Output Parameters

C++ often uses output parameters. In Ruby, these become part of the return value or require explicit output arrays:

```cpp
// C++ - output parameters
cv::Mat gray, edges;
cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
cv::Canny(gray, edges, 50, 150);

double minVal, maxVal;
cv::Point minLoc, maxLoc;
cv::minMaxLoc(gray, &minVal, &maxVal, &minLoc, &maxLoc);
```

```ruby
# Ruby - using output_array
gray = Cv::Mat.new
edges = Cv::Mat.new
Cv.cvt_color(image.input_array, gray.output_array, Cv::ColorConversionCodes::COLOR_BGR2GRAY)
Cv.canny(gray.input_array, edges.output_array, 50, 150)

# Multiple return values
min_val, max_val, min_loc, max_loc = Cv.min_max_loc(gray.input_array)
```

## Complete Example

```cpp
// C++
#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    Mat image = imread("photo.jpg", IMREAD_COLOR);
    Mat gray, blurred, edges;

    cvtColor(image, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurred, Size(5, 5), 1.5);
    Canny(blurred, edges, 50, 150);

    imwrite("edges.jpg", edges);
    return 0;
}
```

```ruby
# Ruby
require 'opencv-ruby'

image = Cv.imread("photo.jpg", Cv::ImreadModes::IMREAD_COLOR)
gray = Cv::Mat.new
blurred = Cv::Mat.new
edges = Cv::Mat.new

Cv.cvt_color(image.input_array, gray.output_array, Cv::ColorConversionCodes::COLOR_BGR2GRAY)
Cv.gaussian_blur(gray.input_array, blurred.output_array, Cv::Size.new(5, 5), 1.5)
Cv.canny(blurred.input_array, edges.output_array, 50, 150)

Cv.imwrite("edges.jpg", edges.input_array)
```

## See Also

- [Type Mappings](type-mappings.md) - Complete C++ to Ruby type mapping reference
- [Python to Ruby](python-to-ruby.md) - Guide for Python OpenCV users
- [OpenCV C++ Tutorials](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html) - Official tutorials
