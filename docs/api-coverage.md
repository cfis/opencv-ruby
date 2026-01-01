# API Coverage

This page summarizes what percentage of OpenCV's API is exposed through opencv-ruby.

## Coverage Summary

| Category | Coverage |
|----------|----------|
| **Core Modules** | ~95% |
| **Extra Modules** | ~60% |
| **Overall** | ~85% |

The bindings expose **1,600+ classes, enums, and types** from OpenCV.

## Modules Included

### Core Modules (opencv)

These are the main modules that ship with OpenCV:

| Module | Status | Description |
|--------|--------|-------------|
| **core** | Full | Matrix operations, basic structures, linear algebra |
| **imgproc** | Full | Image processing (filtering, transforms, drawing) |
| **imgcodecs** | Full | Image file reading and writing |
| **videoio** | Full | Video capture and writing |
| **highgui** | Full | GUI windows and trackbars |
| **video** | Full | Video analysis (optical flow, tracking) |
| **calib3d** | Full | Camera calibration and 3D reconstruction |
| **features2d** | Full | Feature detection and description |
| **objdetect** | Full | Object detection (cascades, HOG, ArUco) |
| **dnn** | Full | Deep neural network inference |
| **ml** | Full | Machine learning algorithms |
| **flann** | Full | Fast approximate nearest neighbors |
| **photo** | Full | Computational photography |
| **stitching** | Full | Image stitching / panoramas |

### Contrib/Extra Modules

| Module | Status | Notes |
|--------|--------|-------|
| **aruco** | Full | ArUco marker detection (part of objdetect in 4.x) |
| **barcode** | Full | Barcode detection (OpenCV 4.8+) |
| **cuda** | Partial | Core CUDA support only, not GPU algorithms |
| **cudaarithm** | Not included | — |
| **cudafilters** | Not included | — |
| **cudev** | Not included | — |

## What's Not Included

### CUDA GPU Modules

The CUDA-accelerated modules are not exposed:

- `cuda` (partial - device info only)
- `cudaarithm`
- `cudabgsegm`
- `cudacodec`
- `cudafeatures2d`
- `cudafilters`
- `cudaimgproc`
- `cudaobjdetect`
- `cudaoptflow`
- `cudastereo`
- `cudawarping`

**Reason**: CUDA support requires specific hardware and significantly complicates the build process. The CPU implementations of all algorithms are available.

### Platform-Specific Features

- DirectX interop (Windows-only)
- VA-API (Linux Intel GPU)
- Some OpenCL features

### Deprecated APIs

Legacy APIs marked deprecated in OpenCV 4.x are not included.

## Enums Coverage

All public enums from included modules are exposed. Examples:

- `Cv::ImreadModes` - Image loading options
- `Cv::ImwriteFlags` - Image saving options
- `Cv::ColorConversionCodes` - Color space conversions
- `Cv::ThresholdTypes` - Thresholding methods
- `Cv::BorderTypes` - Border handling
- `Cv::MorphTypes` - Morphological operations
- `Cv::InterpolationFlags` - Resize/remap interpolation
- And 200+ more...

## Verifying Coverage

To see what's available, explore the [API Reference](api/Cv/index.md) or use Ruby introspection:

```ruby
require 'opencv-ruby'

# List all classes in Cv module
Cv.constants.select { |c| Cv.const_get(c).is_a?(Class) }

# List methods on a class
Cv::Mat.instance_methods(false)

# List enum values
Cv::ImreadModes.constants
```

## See Also

- [Type Mappings](type-mappings.md) - Complete C++ to Ruby type mapping reference
- [API Reference](api/Cv/index.md) - Full class documentation

## Requesting Additional Coverage

If you need an OpenCV feature that isn't currently exposed, please:

1. Check the [API Reference](api/Cv/index.md) to confirm it's not already available
2. Open an issue at [github.com/cfis/opencv-ruby](https://github.com/cfis/opencv-ruby/issues)
3. Include the C++ function/class name from the OpenCV documentation
