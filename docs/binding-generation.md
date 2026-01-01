# Binding Generation

The opencv-ruby bindings were generated using a toolchain designed to automatically create Ruby bindings from C++ headers. This page explains how the bindings were created and the technologies involved.

## Overview

Creating Ruby bindings for a library as large as OpenCV (with thousands of classes, functions, and enums) by hand would be impractical. Instead, the bindings are generated automatically using:

1. **ffi-clang** - Parses C++ headers to extract API information
2. **ruby-bindgen** - Generates Rice binding code from parsed headers
3. **Rice** - Runtime library that connects C++ and Ruby

## The Generation Pipeline

```
┌─────────────────┐     ┌──────────────┐     ┌─────────────────┐
│  OpenCV C++     │────▶│  ffi-clang   │────▶│  ruby-bindgen   │
│  Headers        │     │  (Parser)    │     │  (Generator)    │
└─────────────────┘     └──────────────┘     └─────────────────┘
                                                      │
                                                      ▼
                                             ┌─────────────────┐
                                             │  Rice C++       │
                                             │  Binding Code   │
                                             └─────────────────┘
                                                      │
                                                      ▼
                                             ┌─────────────────┐
                                             │  CMake Build    │────▶  opencv_ruby.so
                                             └─────────────────┘
```

## ffi-clang

[ffi-clang](https://github.com/ffi/ffi-clang) provides Ruby bindings to libclang, LLVM's C interface for parsing C/C++ code. It allows ruby-bindgen to:

- Parse OpenCV's header files
- Extract class definitions, methods, and their signatures
- Understand inheritance hierarchies
- Process enums and constants
- Handle templates and type aliases

Using libclang ensures accurate parsing of complex C++ constructs that would be difficult to handle with regex-based approaches.

## ruby-bindgen

[ruby-bindgen](https://github.com/cfis/ruby-bindgen) is a code generator that takes the parsed C++ API information and produces Rice binding code. It handles:

- **Class bindings** - Creating Ruby classes that wrap C++ classes
- **Method mappings** - Converting C++ methods to Ruby methods with proper argument handling
- **Type conversions** - Managing conversions between Ruby and C++ types
- **Enum generation** - Creating Ruby constants from C++ enums
- **Naming conventions** - Converting `camelCase` to `snake_case`

### Configuration

ruby-bindgen uses a YAML configuration file to customize the generation:

```yaml
namespaces:
  - name: cv
    ruby_name: Cv

types:
  - cpp_name: cv::Mat
    ruby_name: Mat

methods:
  - cpp_name: cvtColor
    ruby_name: cvt_color
```

This allows fine-grained control over how C++ APIs are exposed to Ruby.

## Rice

[Rice](https://github.com/ruby-rice/rice) is a C++ library that simplifies writing Ruby extensions. It provides:

- **Type-safe bindings** - Template-based approach catches errors at compile time
- **Automatic type conversion** - Handles common Ruby ↔ C++ type conversions
- **Exception handling** - Converts C++ exceptions to Ruby exceptions
- **Memory management** - Integrates with Ruby's garbage collector

### Example Rice Binding

Here's what generated Rice code looks like:

```cpp
#include <rice/rice.hpp>
#include <opencv2/core.hpp>

void Init_opencv_core() {
  Rice::Module rb_mCv = Rice::define_module("Cv");

  Rice::define_class_under<cv::Mat>(rb_mCv, "Mat")
    .define_constructor(Rice::Constructor<cv::Mat>())
    .define_constructor(Rice::Constructor<cv::Mat, int, int, int>(),
      Rice::Arg("rows"), Rice::Arg("cols"), Rice::Arg("type"))
    .define_method("rows", &cv::Mat::rows)
    .define_method("cols", &cv::Mat::cols)
    .define_method("empty?", &cv::Mat::empty)
    .define_method("clone", &cv::Mat::clone);
}
```

Rice handles:

- Wrapping the `cv::Mat` C++ class
- Exposing constructors with named arguments
- Converting method names to Ruby conventions
- Managing object lifetime

## Regenerating Bindings

To regenerate the bindings (if you're developing opencv-ruby):

1. Install dependencies:
   ```bash
   gem install ffi-clang ruby-bindgen
   ```

2. Ensure LLVM/Clang is installed (for libclang)

3. Run the generator:
   ```bash
   ruby-bindgen --config opencv.yaml --output ext/opencv2
   ```

4. Rebuild the extension (see [Building with CMake](cmake-build.md))

## Why Not FFI?

While Ruby's FFI gem is popular for creating bindings, it's designed for C libraries, not C++. OpenCV's API relies heavily on:

- Classes and inheritance
- Method overloading
- Templates
- Exceptions
- RAII (Resource Acquisition Is Initialization)

Rice handles all of these C++ features, making it the right choice for OpenCV bindings.

## Further Reading

- [Rice Documentation](https://ruby-rice.github.io/)
- [ffi-clang on GitHub](https://github.com/ffi/ffi-clang)
- [ruby-bindgen on GitHub](https://github.com/cfis/ruby-bindgen)
- [libclang Documentation](https://clang.llvm.org/docs/Tooling.html)
