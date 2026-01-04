# Installation

## Prerequisites

OpenCV is a large, complex C++ code base that makes heavy use of templates. Therefore, to build the Ruby bindings you will need a machine that has at least 32GB of memory, a decent amount of disk space and an up-to-date-date C++ compiler (C++17 or higher). Expect compile times to range from 5 minutes on the latest Macs to 30 minutes for relatively new x86 laptops. Older hardware will of course be slower and compile times vary greatly by compiler (MSVC and Clang are much faster than gcc).

## Installing OpenCV

### macOS

On a MacBook Pro M4, it will take about 5 minutes to build the extension. It will be approximately 140MB.

You will first need to install [HomeBrew](https://brew.sh/)

Then:

```bash
brew install libffi opencv
gem install opencv-ruby --preset macos-release
```

### Fedora

On a Meteor Lake (Intel Core Ultra 7 165U) laptop with 64GB memory, it will take about 30 minutes to build the extension with g++. The extension will be roughly 200MB. Note that g++ uses *a lot* of memory, with some processes taking up to 17GB of memory. At most 6 concurrent g++ instances can at once with 64GB. If you have a machine with 32GB of memory you will need to reduce the number of concurrent jobs. Do this by overriding the setting in the CMakePresets.json file.

```bash
sudo apt-get install libffi-devel opencv
gem install opencv-ruby --preset linux-release
```

### Ubuntu/Debian

```bash
sudo apt-get install libffi-dev libopencv-dev
gem install opencv-ruby --preset linux-release
```

### Windows (RubyInstaller + DevKit)

Most Ruby developers on Windows use the [RubyInstaller](https://rubyinstaller.org/) which installs a MSYS2/Mingw64 environment. On a Meteor Lake (Intel Core Ultra 7 165U) laptop with 64GB memory, it will take about 30 minutes to build the extension with g++. The size will be about 200MB.

```bash
  pacman -S mingw-w64-ucrt-x86_64-opencv mingw-w64-ucrt-x86_64-qt6-base mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-libffi
  gem install opencv-ruby --preset mingw-release
```

You MUST install qt6-base because the OpenCV highgui module is built with it. However, it is not listed as dependency so you have to install it manually.

### Windows Visual Studio (MSVC)

You can also use Visual Studio on Windows in combination with vcpkg. On a Meteor Lake (Intel Core Ultra 7 165U) laptop with 64GB memory, it will take about 30 minutes to build the extension. It will be 70MB.

After installing Visual Studio and vcpkg, install the gem like this:

```bash
gem install opencv-ruby --preset msvc-release
```

Notice you don't have to install any dependencies first. This is because the build system uses vcpkg in manifest mode, which will download and build all dependencies like libffi and OpenCV. The first time you do this, it can take quite a while, up to an hour (it is a one time cost).

This has been tested with Visual Studio 2022 and 2026, with Visual Studio 2026 being strongly preferred (it is quite a bit faster). 

## Verifying Installation

To test that the installation was successful:

```ruby
require 'opencv-ruby'

# Check OpenCV version
puts Cv.get_version_string
# => "4.10.0" (or your installed version)

# Create a simple matrix
mat = Cv::Mat.new(3, 3, CV_8UC1, Cv::Scalar.new(255))
puts "Created #{mat.rows}x#{mat.cols} matrix"
```
