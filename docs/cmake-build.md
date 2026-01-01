# Building with CMake

The opencv-ruby extension is built using CMake, a cross-platform build system. This page explains the build process and how to build the extension from source.

## Why CMake?

CMake was chosen over traditional Ruby extension build tools (mkmf/extconf.rb) because:

- **Cross-platform support** - Works consistently on Windows, macOS, and Linux
- **OpenCV integration** - OpenCV provides CMake config files for easy discovery
- **C++17 support** - Better handling of modern C++ standards
- **IDE support** - Generates project files for Visual Studio, Xcode, etc.

## Build Requirements

- **CMake 3.26** or later
- **C++17 compatible compiler**:
  - GCC 13 or 14
  - Clang 17 or 18
  - MSVC 2022 (Visual Studio 17)
  - Apple Clang (Xcode 15 or 16)
- **OpenCV 4.x** with CMake config files
- **libffi** development files
- **Ruby 3.2+** with development headers

## Building from Source

### Standard Build

When you install the gem, CMake is invoked automatically:

```bash
gem install opencv-ruby
```

### Manual Build (Development)

For development or troubleshooting:

```bash
# Clone the repository
git clone https://github.com/cfis/opencv-ruby.git
cd opencv-ruby

# Create build directory
mkdir build && cd build

# Configure
cmake ../ext -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . --config Release

# Copy the built library to lib/
cp opencv_ruby.* ../lib/
```

### Windows with MSYS2/UCRT64

Most Ruby developers on Windows use RubyInstaller with the MSYS2 DevKit:

```bash
# Open MSYS2 UCRT64 terminal (Ruby uses UCRT64)
# Or run: ridk enable

# Ensure dependencies are installed
pacman -S mingw-w64-ucrt-x86_64-opencv mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-libffi

# Clone and build
git clone https://github.com/cfis/opencv-ruby.git
cd opencv-ruby
mkdir build && cd build

# Configure with MinGW Makefiles
cmake ../ext -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build .

# Copy to lib/
cp opencv_ruby.dll ../lib/
```

### Windows with MSVC (Recommended for Development)

For the best development experience on Windows, use MSVC with vcpkg. This approach offers significant advantages:

- **Much faster compilation** than MinGW/g++
- **Superior debugging experience** with Visual Studio
- **Edit and Continue** support for rapid iteration
- **Automatic dependency management** via vcpkg manifest mode

**Requirements:**
- Visual Studio 2022 with C++ workload
- [vcpkg](https://vcpkg.io/) installed
- MSVC-built Ruby (compile Ruby from source with MSVC, or use an MSVC-compatible build)

**Setup:**

1. **Set the VCPKG_ROOT environment variable**:
   ```cmd
   set VCPKG_ROOT=C:\path\to\vcpkg
   ```

2. **Clone and build**:
   ```cmd
   git clone https://github.com/cfis/opencv-ruby.git
   cd opencv-ruby\ext

   # Configure with MSVC preset (dependencies install automatically)
   cmake --preset=msvc-release

   # Build
   cmake --build --preset=msvc-release

   # Copy to lib/
   copy build\msvc-release\opencv_ruby.dll ..\lib\
   ```

The `vcpkg.json` manifest file automatically installs all dependencies (OpenCV with many features enabled, libffi) on first configure. This can take a while initially but subsequent builds are fast.

### CMake Presets

The project includes `CMakePresets.json` with pre-configured build settings for all platforms:

**Available Presets:**

| Preset | Platform | Description |
|--------|----------|-------------|
| `msvc-debug` | Windows | MSVC with Edit-and-Continue debugging |
| `msvc-release` | Windows | MSVC optimized release build |
| `clang-windows-debug` | Windows | Clang-cl debug build |
| `clang-windows-release` | Windows | Clang-cl release build |
| `mingw-debug` | Windows | MinGW/g++ debug build |
| `mingw-release` | Windows | MinGW/g++ release build |
| `linux-debug` | Linux | GCC/Clang debug build |
| `linux-release` | Linux | GCC/Clang release build |
| `macos-debug` | macOS | Apple Clang debug build |
| `macos-release` | macOS | Apple Clang release build |

**Using Presets:**

```bash
cd ext

# List available presets for your platform
cmake --list-presets

# Configure with a preset
cmake --preset=msvc-release   # or linux-release, macos-release, etc.

# Build with matching build preset
cmake --build --preset=msvc-release
```

**Key Preset Features:**

- **Windows presets** automatically use vcpkg toolchain for dependency management
- **Debug presets** include symbols and disable optimizations for debugging
- **Release presets** enable full optimizations (`-O3` or `/O2`)
- All presets use **Ninja** as the build generator for fast parallel builds

### vcpkg Manifest Mode

The `ext/vcpkg.json` file defines all dependencies that vcpkg will automatically install:

```json
{
  "dependencies": [
    {
      "name": "opencv4",
      "features": ["dnn", "highgui", "ffmpeg", "png", "jpeg", ...]
    },
    { "name": "libffi" }
  ]
}
```

When you configure with a Windows preset (MSVC or Clang-cl), vcpkg:

1. Reads the manifest file
2. Downloads and builds all dependencies
3. Makes them available to CMake automatically

The first build takes longer (20-40 minutes) as dependencies compile, but subsequent builds only rebuild opencv-ruby itself.

## CMakeLists.txt Explained

The main build configuration is in `ext/CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("opencv_ruby" LANGUAGES CXX)
add_library(${CMAKE_PROJECT_NAME} SHARED)

# Find OpenCV
find_package(OpenCV CONFIG REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

# Find libffi (platform-specific)
# ... (see actual file for details)

# Find Ruby
include("../../rice/FindRuby.cmake")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
  ${Ruby_INCLUDE_DIR} ${Ruby_CONFIG_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${Ruby_LIBRARY})
```

### Key Components

1. **OpenCV Discovery**: Uses `find_package(OpenCV CONFIG)` to locate OpenCV's CMake configuration files.

2. **libffi Handling**: Platform-specific logic finds libffi:
   - Windows: Uses vcpkg's `unofficial-libffi`
   - macOS: Uses pkg-config
   - Linux: Searches standard paths

3. **Ruby Discovery**: Custom `FindRuby.cmake` locates Ruby headers and libraries.

4. **Source Files**: Module subdirectories are included via `add_subdirectory()`.

## Build Output

The build produces a shared library:

| Platform | Output File |
|----------|-------------|
| Linux | `opencv_ruby.so` |
| macOS | `opencv_ruby.bundle` |
| Windows | `opencv_ruby.dll` |

## Troubleshooting

### OpenCV Not Found

```
CMake Error: Could not find OpenCV
```

Solutions:

1. Set `OpenCV_DIR` to the directory containing `OpenCVConfig.cmake`:
   ```bash
   cmake -DOpenCV_DIR=/path/to/opencv/build ..
   ```

2. On Windows with vcpkg:
   ```bash
   cmake -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake ..
   ```

### Ruby Not Found

```
CMake Error: Could not find Ruby
```

Ensure Ruby development files are installed:

```bash
# Ubuntu/Debian
sudo apt-get install ruby-dev

# macOS (usually included with system Ruby or rbenv)
# Windows - use RubyInstaller DevKit
```

### libffi Not Found

```bash
# Ubuntu/Debian
sudo apt-get install libffi-dev

# macOS
brew install libffi
export PKG_CONFIG_PATH="/opt/homebrew/opt/libffi/lib/pkgconfig"

# Windows (vcpkg)
vcpkg install libffi
```

### Apple Silicon (M1/M2) Issues

On Apple Silicon Macs, ensure you're using native ARM64 builds:

```bash
# Check architecture
file $(which ruby)
# Should show: arm64

# Configure for ARM64
cmake -DCMAKE_OSX_ARCHITECTURES=arm64 ..
```

### Compiler Compatibility

If you encounter C++ standard errors:

```bash
# Force a specific compiler (Linux)
cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-14 ..

# Or on macOS with Homebrew LLVM
cmake -DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm/bin/clang++ ..

# On Windows with MSYS2, ensure you're using the UCRT64 environment
# (Ruby uses UCRT64, not MINGW64 or MSYS)
```

## Verbose Build Output

For debugging build issues:

```bash
# Verbose CMake configuration
cmake --debug-output ..

# Verbose build
cmake --build . --verbose
```

## Project Structure

```
ext/
├── CMakeLists.txt          # Main build configuration
├── CMakePresets.json       # Build presets for all platforms
├── vcpkg.json              # vcpkg manifest (auto-installs dependencies)
├── opencv_ruby-rb.cpp      # Extension entry point
├── opencv_ruby-rb.hpp      # Main header
├── opencv2/                # Module bindings
│   ├── CMakeLists.txt
│   ├── core-rb.cpp
│   ├── imgproc-rb.cpp
│   ├── features2d-rb.cpp
│   └── ...
└── rice/                   # Rice headers (bundled)
```

## See Also

- [CMake Documentation](https://cmake.org/documentation/)
- [Building OpenCV from Source](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html)
- [Rice Build Guide](https://ruby-rice.github.io/)
