# Type Mappings

This page documents how C++ OpenCV types map to Ruby classes.

## Basic Types

| C++ | Ruby | Description |
|-----|------|-------------|
| `cv::Mat` | `Cv::Mat` | N-dimensional dense array (images, matrices) |
| `cv::Scalar` | `Cv::Scalar` | 4-element vector (colors, values) |
| `cv::Point` | `Cv::Point` | 2D integer point |
| `cv::Point2f` | `Cv::Point2f` | 2D float point |
| `cv::Point2d` | `Cv::Point2d` | 2D double point |
| `cv::Point3i` | `Cv::Point3i` | 3D integer point |
| `cv::Point3f` | `Cv::Point3f` | 3D float point |
| `cv::Point3d` | `Cv::Point3d` | 3D double point |
| `cv::Size` | `Cv::Size` | 2D integer size (width, height) |
| `cv::Size2f` | `Cv::Size2f` | 2D float size |
| `cv::Size2d` | `Cv::Size2d` | 2D double size |
| `cv::Rect` | `Cv::Rect` | Integer rectangle (x, y, width, height) |
| `cv::Rect2f` | `Cv::Rect2f` | Float rectangle |
| `cv::Rect2d` | `Cv::Rect2d` | Double rectangle |
| `cv::Range` | `Cv::Range` | Integer range (start, end) |
| `cv::RotatedRect` | `Cv::RotatedRect` | Rotated rectangle |
| `cv::TermCriteria` | `Cv::TermCriteria` | Termination criteria for iterative algorithms |
| `cv::Moments` | `Cv::Moments` | Image moments |

## Vector Types

Small fixed-size vectors:

| C++ | Ruby | Description |
|-----|------|-------------|
| `cv::Vec2b` | `Cv::Vec2b` | 2 unsigned chars |
| `cv::Vec3b` | `Cv::Vec3b` | 3 unsigned chars (BGR pixel) |
| `cv::Vec4b` | `Cv::Vec4b` | 4 unsigned chars (BGRA pixel) |
| `cv::Vec2s` | `Cv::Vec2s` | 2 shorts |
| `cv::Vec3s` | `Cv::Vec3s` | 3 shorts |
| `cv::Vec4s` | `Cv::Vec4s` | 4 shorts |
| `cv::Vec2i` | `Cv::Vec2i` | 2 integers |
| `cv::Vec3i` | `Cv::Vec3i` | 3 integers |
| `cv::Vec4i` | `Cv::Vec4i` | 4 integers |
| `cv::Vec6i` | `Cv::Vec6i` | 6 integers |
| `cv::Vec8i` | `Cv::Vec8i` | 8 integers |
| `cv::Vec2f` | `Cv::Vec2f` | 2 floats |
| `cv::Vec3f` | `Cv::Vec3f` | 3 floats |
| `cv::Vec4f` | `Cv::Vec4f` | 4 floats |
| `cv::Vec6f` | `Cv::Vec6f` | 6 floats |
| `cv::Vec2d` | `Cv::Vec2d` | 2 doubles |
| `cv::Vec3d` | `Cv::Vec3d` | 3 doubles |
| `cv::Vec4d` | `Cv::Vec4d` | 4 doubles |

## Typed Matrix Classes

Type-safe matrix templates:

| C++ | Ruby | Element Type |
|-----|------|--------------|
| `cv::Mat1b` | `Cv::Mat1b` | 1-channel unsigned char |
| `cv::Mat1s` | `Cv::Mat1s` | 1-channel short |
| `cv::Mat1w` | `Cv::Mat1w` | 1-channel unsigned short |
| `cv::Mat1i` | `Cv::Mat1i` | 1-channel int |
| `cv::Mat1f` | `Cv::Mat1f` | 1-channel float |
| `cv::Mat1d` | `Cv::Mat1d` | 1-channel double |
| `cv::Mat2b` | `Cv::Mat2b` | 2-channel unsigned char |
| `cv::Mat3b` | `Cv::Mat3b` | 3-channel unsigned char (BGR image) |
| `cv::Mat4b` | `Cv::Mat4b` | 4-channel unsigned char (BGRA image) |
| `cv::Mat3f` | `Cv::Mat3f` | 3-channel float |
| ... | ... | (all combinations available) |

## Matrix Type Constants

Global constants for `Mat` type specification:

| Constant | Meaning |
|----------|---------|
| `CV_8UC1` | 8-bit unsigned, 1 channel |
| `CV_8UC3` | 8-bit unsigned, 3 channels |
| `CV_8UC4` | 8-bit unsigned, 4 channels |
| `CV_8SC1` | 8-bit signed, 1 channel |
| `CV_16UC1` | 16-bit unsigned, 1 channel |
| `CV_16SC1` | 16-bit signed, 1 channel |
| `CV_32SC1` | 32-bit signed integer, 1 channel |
| `CV_32FC1` | 32-bit float, 1 channel |
| `CV_32FC2` | 32-bit float, 2 channels |
| `CV_64FC1` | 64-bit float (double), 1 channel |

Pattern: `CV_{depth}{signed}{channels}` where:
- Depth: 8, 16, 32, 64
- Signed: U (unsigned), S (signed), F (float)
- Channels: C1, C2, C3, C4

## STL Container Mappings

C++ STL containers map to Ruby `Std::` classes:

| C++ | Ruby |
|-----|------|
| `std::vector<cv::Mat>` | `Std::Vector≺cv꞉꞉Mat≻` |
| `std::vector<cv::Point>` | `Std::Vector≺cv꞉꞉Point_≺int≻≻` |
| `std::vector<cv::Point2f>` | `Std::Vector≺cv꞉꞉Point_≺float≻≻` |
| `std::vector<cv::KeyPoint>` | `Std::Vector≺cv꞉꞉KeyPoint≻` |
| `std::vector<cv::DMatch>` | `Std::Vector≺cv꞉꞉DMatch≻` |
| `std::vector<cv::Rect>` | `Std::Vector≺cv꞉꞉Rect_≺int≻≻` |
| `std::vector<int>` | `Std::Vector≺int≻` |
| `std::vector<float>` | `Std::Vector≺float≻` |
| `std::vector<double>` | `Std::Vector≺double≻` |
| `std::vector<uchar>` | `Std::Vector≺unsigned char≻` |
| `std::vector<std::vector<cv::Point>>` | `Std::Vector≺vector≺cv꞉꞉Point_≺int≻≻≻` |
| `std::string` | Ruby `String` (automatic conversion) |

Note: Ruby uses special Unicode characters (`≺`, `≻`, `꞉꞉`) in type names.

## Input/Output Array Types

| C++ | Ruby Method | Purpose |
|-----|-------------|---------|
| `cv::InputArray` | `mat.input_array` | Read-only input |
| `cv::OutputArray` | `mat.output_array` | Write-only output |
| `cv::InputOutputArray` | `mat.input_output_array` | Read-write |

## Smart Pointers

| C++ | Ruby |
|-----|------|
| `cv::Ptr<T>` | `Cv::Ptr≺T≻` or just the class |
| `std::shared_ptr<T>` | `Std::SharedPtr≺T≻` |

Most factory methods return smart pointers that Ruby handles automatically:

```ruby
# These work equivalently
orb = Cv::ORB.create        # Returns Ptr<ORB>, usable directly
sift = Cv::SIFT.create(500) # Returns Ptr<SIFT>
```

## Feature Detection Types

| C++ | Ruby |
|-----|------|
| `cv::KeyPoint` | `Cv::KeyPoint` |
| `cv::DMatch` | `Cv::DMatch` |
| `cv::Feature2D` | `Cv::Feature2D` |
| `cv::DescriptorMatcher` | `Cv::DescriptorMatcher` |

## Algorithm Classes

| C++ | Ruby |
|-----|------|
| `cv::Algorithm` | `Cv::Algorithm` |
| `cv::ORB` | `Cv::ORB` |
| `cv::SIFT` | `Cv::SIFT` |
| `cv::AKAZE` | `Cv::AKAZE` |
| `cv::BRISK` | `Cv::BRISK` |
| `cv::KAZE` | `Cv::KAZE` |
| `cv::CascadeClassifier` | `Cv::CascadeClassifier` |
| `cv::HOGDescriptor` | `Cv::HOGDescriptor` |
| `cv::BackgroundSubtractorMOG2` | `Cv::BackgroundSubtractorMOG2` |
| `cv::BackgroundSubtractorKNN` | `Cv::BackgroundSubtractorKNN` |

## DNN Types

| C++ | Ruby |
|-----|------|
| `cv::dnn::Net` | `Cv::Dnn::Net` |
| `cv::dnn::Layer` | `Cv::Dnn::Layer` |
| `cv::dnn::Model` | `Cv::Dnn::Model` |
| `cv::dnn::ClassificationModel` | `Cv::Dnn::ClassificationModel` |
| `cv::dnn::DetectionModel` | `Cv::Dnn::DetectionModel` |

## Machine Learning Types

| C++ | Ruby |
|-----|------|
| `cv::ml::StatModel` | `Cv::Ml::StatModel` |
| `cv::ml::SVM` | `Cv::Ml::SVM` |
| `cv::ml::DTrees` | `Cv::Ml::DTrees` |
| `cv::ml::RTrees` | `Cv::Ml::RTrees` |
| `cv::ml::Boost` | `Cv::Ml::Boost` |
| `cv::ml::KNearest` | `Cv::Ml::KNearest` |
| `cv::ml::ANN_MLP` | `Cv::Ml::ANN_MLP` |
| `cv::ml::TrainData` | `Cv::Ml::TrainData` |

## Video Types

| C++ | Ruby |
|-----|------|
| `cv::VideoCapture` | `Cv::VideoCapture` |
| `cv::VideoWriter` | `Cv::VideoWriter` |
| `cv::Tracker` | `Cv::Tracker` |
| `cv::TrackerMIL` | `Cv::TrackerMIL` |

## Enum Naming Pattern

C++ enums map to Ruby enum classes:

| C++ | Ruby |
|-----|------|
| `cv::IMREAD_*` | `Cv::ImreadModes::IMREAD_*` |
| `cv::IMWRITE_*` | `Cv::ImwriteFlags::IMWRITE_*` |
| `cv::COLOR_*` | `Cv::ColorConversionCodes::COLOR_*` |
| `cv::THRESH_*` | `Cv::ThresholdTypes::THRESH_*` |
| `cv::MORPH_*` | `Cv::MorphTypes::MORPH_*` |
| `cv::BORDER_*` | `Cv::BorderTypes::BORDER_*` |
| `cv::INTER_*` | `Cv::InterpolationFlags::INTER_*` |
| `cv::RETR_*` | `Cv::RetrievalModes::RETR_*` |
| `cv::CHAIN_APPROX_*` | `Cv::ContourApproximationModes::CHAIN_APPROX_*` |
| `cv::LINE_*` | `Cv::LineTypes::LINE_*` |
| `cv::FONT_*` | `Cv::HersheyFonts::FONT_*` |

## Introspecting Types

Use Ruby introspection to discover available types:

```ruby
require 'opencv-ruby'

# List all classes in Cv module
Cv.constants.select { |c| Cv.const_get(c).is_a?(Class) }

# List methods on a class
Cv::Mat.instance_methods(false)

# List enum values
Cv::ImreadModes.constants

# Check class hierarchy
Cv::ORB.ancestors
```

## See Also

- [C++ to Ruby](cpp-to-ruby.md) - Translation guide
- [API Coverage](api-coverage.md) - Module coverage summary
- [API Reference](api/Cv/index.md) - Full class documentation
