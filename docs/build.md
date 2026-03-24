# Build Issues — Conditional Module Compilation

## Problem

The generated `CMakeLists.txt` files unconditionally include all OpenCV modules (via `add_subdirectory` and `target_sources`). When a module isn't installed on the build system, compilation fails with missing headers.

Modules that are present vary by platform and OpenCV build configuration. For example, Fedora 43's OpenCV packages don't include `xfeatures2d`, and systems without CUDA won't have `cudaimgproc`, `cudawarping`, etc.

## Current State

After `find_package(OpenCV CONFIG REQUIRED)`, the variable `OpenCV_LIB_COMPONENTS` contains the list of available modules:

```cmake
find_package(OpenCV CONFIG REQUIRED)

message(STATUS "OpenCV modules available:")
foreach(m ${OpenCV_LIB_COMPONENTS})
  message(STATUS "  ${m}")
endforeach()
```

Example output on Fedora 43 (no CUDA, no xfeatures2d nonfree):
```
opencv_calib3d, opencv_core, opencv_dnn, opencv_features2d, opencv_flann,
opencv_highgui, opencv_imgcodecs, opencv_imgproc, opencv_ml, opencv_objdetect,
opencv_photo, opencv_stitching, opencv_video, opencv_videoio, opencv_aruco,
opencv_datasets, opencv_face, opencv_optflow, opencv_stereo, opencv_tracking,
opencv_videostab, opencv_ximgproc, opencv_xphoto, ...
```

Notably absent: `opencv_xfeatures2d`, `opencv_cudaimgproc`, `opencv_cudawarping`, etc.

## What ruby-bindgen Needs To Do

The generated `ext/opencv2/CMakeLists.txt` should wrap each module's `add_subdirectory` and `target_sources` calls in a conditional check:

```cmake
# Instead of:
add_subdirectory("xfeatures2d")

# Generate:
if(opencv_xfeatures2d IN_LIST OpenCV_LIB_COMPONENTS)
  add_subdirectory("xfeatures2d")
endif()
```

And similarly for the top-level `target_sources`:

```cmake
# Instead of:
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "xfeatures2d-rb.cpp"
)

# Generate:
if(opencv_xfeatures2d IN_LIST OpenCV_LIB_COMPONENTS)
  target_sources(${CMAKE_PROJECT_NAME} PUBLIC
      "xfeatures2d-rb.cpp"
  )
endif()
```

The mapping from header path to module name should be derivable from the directory structure (e.g., `opencv2/xfeatures2d/` → `opencv_xfeatures2d`).

## Modules That Need Guards

These modules are not universally available and need conditional compilation:

| Module | Reason |
|--------|--------|
| `xfeatures2d` | Contrib module, not always installed. Contains patented SURF algorithm in `nonfree.hpp` |
| `cudaimgproc` | Requires CUDA |
| `cudawarping` | Requires CUDA |
| `cudafeatures2d` | Requires CUDA |
| All `cuda*` modules | Requires CUDA |

Core modules (`core`, `imgproc`, `dnn`, `flann`, etc.) are always present and don't need guards.

## GPU-Specific Classes Within Non-GPU Modules

Some non-GPU modules contain GPU-specific classes that only exist when CUDA is available. These are currently handled with `#ifdef` guards in the C++ source (see `ext/manual_updates.md`):

- `stitching/warpers-rb.cpp` — `PlaneWarperGpu`, `CylindricalWarperGpu`, `SphericalWarperGpu`
- `stitching/detail/seam_finders-rb.cpp` — `GraphCutSeamFinderGpu`
- `videostab/optical_flow-rb.cpp` — `SparsePyrLkOptFlowEstimatorGpu`, `DensePyrLkOptFlowEstimatorGpu`
- `videostab/global_motion-rb.cpp` — `KeypointBasedMotionEstimatorGpu`
- `videostab/wobble_suppression-rb.cpp` — `MoreAccurateMotionWobbleSuppressorGpu`

Ideally ruby-bindgen would detect GPU-only classes (those using `cuda::GpuMat` params or inheriting from GPU base classes) and wrap them in `#ifdef HAVE_OPENCV_CUDAWARPING` or similar guards automatically.

## Upstream OpenCV Header Bugs (GCC 15)

Several OpenCV flann headers have bugs exposed by GCC 15's `-Wtemplate-body` flag. These require manual `#include` additions because the headers use symbols without proper includes:

| File | Missing Include | Symbols |
|------|----------------|---------|
| `flann/dist.h` | `<opencv2/core.hpp>` | `uchar`, `CV_DbgAssert` |
| `flann/heap.h` | `<opencv2/core.hpp>` | `CV_Assert` |
| `flann/ground_truth.h` | `<vector>` | `std::vector` |
| `flann/dynamic_bitset.h` | `<opencv2/core.hpp>` | `bitset_` member access |
| `flann/simplex_downhill.h` | Unfixable | bare `swap`, `Logger`, `NULL` in templates |

The `simplex_downhill.h` issue cannot be worked around with includes — it uses unqualified `swap` and `Logger` in template definitions. The generated `simplex_downhill-rb.cpp` skips the header include entirely (the file has no actual bindings, just a module definition).
