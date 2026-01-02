# Installation

## Prerequisites

Before installing opencv-ruby, you need:

- **Ruby 3.2** or later
- **OpenCV 4.x** installed on your system
- A C++17 compatible compiler:
  - GCC 13 or 14
  - Clang 17 or 18
  - MSVC 2022 (Visual Studio 17)
  - Apple Clang (Xcode 15 or 16)

## Installing OpenCV

### Windows (RubyInstaller + DevKit)

Most Ruby developers on Windows use [RubyInstaller](https://rubyinstaller.org/) with the MSYS2 DevKit. This is the recommended approach.

1. **Install Ruby with DevKit** from [rubyinstaller.org](https://rubyinstaller.org/downloads/). Choose the version with DevKit (e.g., "Ruby+Devkit 3.3.x (x64)").

2. **Open the MSYS2 UCRT64 terminal** (run "MSYS2 UCRT64" from the Start menu or run `ridk enable` then use your terminal).

3. **Install OpenCV and dependencies**:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-opencv mingw-w64-ucrt-x86_64-qt6-base mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-libffi
   ```
Notice you MUST install qt6-base because the highgui module is built with Qt6 support by default for mingw64 but its not a depdency of opencv.

4. **Verify installation**:
   ```bash
   pkg-config --modversion opencv4
   ```

### macOS

Using Homebrew:

```bash
brew install opencv
```

### Ubuntu/Debian

```bash
sudo apt-get install libopencv-dev
```

### Windows (Alternative: vcpkg)

If you prefer vcpkg over MSYS2/MinGW64:

```bash
vcpkg install opencv4 libffi
```

You'll need Visual Studio 2022 for this approach.

## Installing the Gem

Once OpenCV is installed, install the gem:

```bash
gem install opencv-ruby
```

The gem includes a native extension that will be compiled during installation using CMake.

## Verifying Installation

Test that the installation was successful:

```ruby
require 'opencv-ruby'

# Check OpenCV version
puts Cv.get_version_string
# => "4.10.0" (or your installed version)

# Create a simple matrix
mat = Cv::Mat.new(3, 3, CV_8UC1, Cv::Scalar.new(255))
puts "Created #{mat.rows}x#{mat.cols} matrix"
```

## Troubleshooting

### OpenCV Not Found

If CMake cannot find OpenCV, ensure:

1. OpenCV is properly installed
2. The `OpenCV_DIR` environment variable points to your OpenCV installation
3. On Linux/macOS, pkg-config can find OpenCV: `pkg-config --modversion opencv4`

### Compiler Issues

The extension requires C++17 support. Ensure your compiler is recent enough:

- GCC 7+
- Clang 5+
- MSVC 2017+

### Missing libffi

The extension uses libffi for some functionality. Install it if missing:

```bash
# macOS
brew install libffi

# Ubuntu/Debian
sudo apt-get install libffi-dev

# Windows (via vcpkg)
vcpkg install libffi
```
