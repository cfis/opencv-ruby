# OpenCV Ruby

Modern Ruby bindings for [OpenCV](https://opencv.org/) 4.x based on its C++ API.

## Overview

**opencv-ruby** provides comprehensive Ruby bindings for OpenCV, the world's most popular open-source computer vision library. Unlike previous Ruby OpenCV bindings, this library:

- Exposes almost all of OpenCV's C++ API (excluding CUDA)
- Uses [Rice](https://github.com/ruby-rice/rice) for clean, modern C++ to Ruby bindings
- Requires Ruby 3.2+ and OpenCV 4.x
- Provides 1,600+ classes, enums, and modules

## Key Features

- **Core Operations**: Matrix operations, arithmetic, linear algebra
- **Image Processing**: Filtering, morphology, color conversion, geometric transforms
- **Feature Detection**: SIFT, ORB, AKAZE, BRISK, and more
- **Object Detection**: Cascade classifiers, HOG descriptors, ArUco markers
- **Machine Learning**: SVM, decision trees, neural networks, k-means
- **Deep Neural Networks**: Load and run models from TensorFlow, PyTorch, ONNX, Caffe
- **Video Processing**: Optical flow, background subtraction, video I/O
- **Camera Calibration**: Intrinsic/extrinsic calibration, stereo vision, pose estimation
- **Image Stitching**: Panorama creation with exposure compensation and seam finding

## Quick Example

```ruby
require 'opencv-ruby'

# Load an image
image = Cv.imread('photo.jpg', Cv::ImreadModes::IMREAD_COLOR)

# Convert to grayscale
gray = Cv::Mat.new
Cv.cvt_color(image.input_array, gray.output_array, Cv::ColorConversionCodes::COLOR_BGR2GRAY)

# Apply Gaussian blur
blurred = gray.gaussian_blur(Cv::Size.new(5, 5), 1.5)

# Detect edges with Canny
edges = Cv::Mat.new
Cv.canny(blurred.input_array, edges.output_array, 50, 150)

# Save the result
Cv.imwrite('edges.jpg', edges.input_array)
```

## Documentation Approach

This documentation focuses on Ruby-specific usage patterns and getting started guides. For detailed information about OpenCV algorithms and parameters, we link directly to the official [OpenCV documentation](https://docs.opencv.org/4.x/).

The Ruby API closely mirrors the C++ API, so OpenCV's C++ documentation and tutorials are directly applicable. See the [Getting Started](getting-started.md) guide for tips on translating C++ examples to Ruby.

## Project Links

- **Source Code**: [github.com/cfis/opencv-ruby](https://github.com/cfis/opencv-ruby)
- **OpenCV Documentation**: [docs.opencv.org](https://docs.opencv.org/4.x/)
- **Rice (C++ Bindings)**: [github.com/ruby-rice/rice](https://github.com/ruby-rice/rice)
