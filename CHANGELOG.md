  # History

## 1.1.0 (TBD)

### New Features
* Added CUDA support for GPU-accelerated operations

### Ruby API Improvements
* Element and ROI access now uses `[]` instead of `call` (e.g., `mat[row, col]`, `mat[rect]`)
* Added predicate method aliases: `inside?` for Point, `contains?` for Rect, `empty?` for Mat
* Added `each` iterator support for FileNode and Dict classes
* Renamed `grab?` to `grab` for VideoCapture (it's an action, not a predicate)

### Bug Fixes
* Fixed linker errors on Windows for various template methods
* Fixed Point2l and Size2l to use int64 instead of long for cross-platform compatibility

## 1.0.0 (2026-01-04)
This is the initial release of opencv-ruby, which wraps the OpenCV library (version 4.11). It provides access to almost all of OpenCV's APIs except CUDA support (which may be added in the future). Please see the [documentation](https://cfis.github.io/opencv-ruby/) to get started.