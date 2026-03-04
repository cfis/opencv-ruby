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

All builds use CMake presets. From the `ext/` directory:

```bash
cd ext

# Configure with a preset
cmake --preset linux-debug

# Build with matching build preset
cmake --build --preset linux-debug
```

The built extension is placed in `lib/` (Linux/macOS) or `lib/<ruby-version>/` (Windows).

### CMake Presets

The project includes `CMakePresets.json` with pre-configured build settings for all platforms:

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

```bash
# List available presets for your platform
cmake --list-presets
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

   cmake --preset msvc-release
   cmake --build --preset msvc-release
   ```

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
   cmake --preset linux-debug -DOpenCV_DIR=/path/to/opencv/build
   ```

2. On Windows with vcpkg, dependencies are managed automatically via the manifest.

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
# Handled automatically by vcpkg manifest
```

### Apple Silicon (M1/M2) Issues

On Apple Silicon Macs, ensure you're using native ARM64 builds:

```bash
# Check architecture
file $(which ruby)
# Should show: arm64
```

### Compiler Compatibility

If you encounter C++ standard errors:

```bash
# Force a specific compiler (Linux)
cmake --preset linux-debug -DCMAKE_CXX_COMPILER=/usr/bin/g++-14

# Or on macOS with Homebrew LLVM
cmake --preset macos-debug -DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm/bin/clang++
```

## Verbose Build Output

For debugging build issues:

```bash
# Verbose CMake configuration
cmake --preset linux-debug --debug-output

# Verbose build
cmake --build --preset linux-debug --verbose
```

## Project Structure

```
ext/
├── CMakeLists.txt          # Main build configuration
├── CMakePresets.json       # Build presets for all platforms
├── vcpkg.json              # vcpkg manifest (auto-installs dependencies)
├── opencv_ruby-rb.cpp      # Extension entry point
├── opencv_ruby-rb.hpp      # Main header
├── rice-bindings.yaml      # ruby-bindgen configuration
├── manual_updates.md       # Manual fixes applied after regeneration
└── opencv2/                # Module bindings
    ├── CMakeLists.txt
    ├── core-rb.cpp
    ├── imgproc-rb.cpp
    ├── features2d-rb.cpp
    └── ...
```

## See Also

- [CMake Documentation](https://cmake.org/documentation/)
- [Building OpenCV from Source](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html)
- [Rice Build Guide](https://ruby-rice.github.io/)
