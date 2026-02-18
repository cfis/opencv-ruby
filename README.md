# opencv-ruby

Ruby bindings for OpenCV4 based on its C++ API. Almost all of OpenCV's API is exposed, except for CUDA support.

* Web site: https://cfis.github.io/opencv-ruby/

## Requirements

* OpenCV <http://opencv.org/>
  * [Download](http://sourceforge.net/projects/opencvlibrary/)
  * [Install guide](http://docs.opencv.org/doc/tutorials/introduction/table_of_content_introduction/table_of_content_introduction.html#table-of-content-introduction)

## Installation

See [installation](https://cfis.github.io/opencv-ruby/installation/)

## Build from Source on macOS

The following setup was used to successfully build `opencv-ruby` on Apple Silicon macOS with Homebrew OpenCV 4.13 and Ruby 4.0.x (RVM):

* Xcode Command Line Tools (`xcode-select --install`)
* CMake 3.26+ (`brew install cmake`)
* Ninja (`brew install ninja`)
* OpenCV (`brew install opencv`)
* pkg-config (`brew install pkg-config`)

Recommended install command:

```sh
RUBY_EXE="$(rvm which ruby)"
RUBY_LIB="$(ruby -rrbconfig -e 'puts File.join(RbConfig::CONFIG[\"libdir\"], RbConfig::CONFIG[\"LIBRUBY_SO\"])')"
RUBY_HDR="$(ruby -rrbconfig -e 'puts RbConfig::CONFIG[\"rubyhdrdir\"]')"
RUBY_ARCH_HDR="$(ruby -rrbconfig -e 'puts RbConfig::CONFIG[\"rubyarchhdrdir\"]')"

gem install opencv-ruby -- --preset macos-release \
  -DCMAKE_NO_SYSTEM_FROM_IMPORTED=ON \
  -DRuby_EXECUTABLE="$RUBY_EXE" \
  -DRuby_LIBRARY="$RUBY_LIB" \
  -DRuby_INCLUDE_DIR="$RUBY_HDR" \
  -DRuby_CONFIG_INCLUDE_DIR="$RUBY_ARCH_HDR"
```

Notes:

* `-DCMAKE_NO_SYSTEM_FROM_IMPORTED=ON` avoids header-order conflicts when legacy headers are present in `/usr/local/include/opencv2`.
* Passing explicit `Ruby_*` paths helps when RVM has multiple Rubies installed and CMake picks the wrong one.
* The final link step can take several minutes and may show high CPU in `ld`; this is expected.

## Getting Started 

See [getting started](https://cfis.github.io/opencv-ruby/getting-started/)
