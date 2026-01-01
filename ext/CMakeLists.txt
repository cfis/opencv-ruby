# =============================================================================
# CMakeLists.txt - Builds opencv-ruby extension with Rice
# =============================================================================

# -----------------------------------------------------------------------------
# CMake Version and C++ Standard
# -----------------------------------------------------------------------------
# CMake 3.26+ is required for modern FetchContent features and improved
# Ruby detection. Rice requires C++17 for features like std::string_view,
# structured bindings, and if-constexpr.

cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------------------------------------------------------
# Project Definition
# -----------------------------------------------------------------------------
# Define the project name and specify that we only need a C++ compiler.
# The project name is used throughout via ${CMAKE_PROJECT_NAME}.

project("opencv_ruby" LANGUAGES CXX)

# -----------------------------------------------------------------------------
# Create the Extension Library
# -----------------------------------------------------------------------------
# IMPORTANT: Use MODULE instead of SHARED for Ruby extensions!
#
# - MODULE: Creates a loadable plugin that cannot be linked against.
#           This is correct for Ruby extensions loaded via require/dlopen.
# - SHARED: Creates a shared library that can be linked against.
#           On macOS, this creates a .dylib which Ruby cannot load.

if (MSVC)
    # MSVC fails to recognize targets for debugging when using MODULE
    add_library(${CMAKE_PROJECT_NAME} SHARED)
else ()
    add_library(${CMAKE_PROJECT_NAME} MODULE)
endif ()

# -----------------------------------------------------------------------------
# Fetch Rice from GitHub
# -----------------------------------------------------------------------------
# Rice is a header-only library, so we use FetchContent to download it
# automatically. This eliminates the need for users to manually install Rice.
#
# FetchContent downloads the repository at configure time and makes it
# available as if it were part of your project.
#
# Note: For production gems, you may want to pin to a specific release tag
# instead of 'dev' for reproducible builds.

include(FetchContent)

FetchContent_Declare(
  rice
  GIT_REPOSITORY https://github.com/ruby-rice/rice.git
  GIT_TAG 4.8.0
)
FetchContent_MakeAvailable(rice)

# -----------------------------------------------------------------------------
# Configure Ruby Detection
# -----------------------------------------------------------------------------
# Rice provides an enhanced FindRuby.cmake that creates proper CMake targets
# (Ruby::Ruby, Ruby::Module) instead of just setting variables. We prepend
# Rice's module path so CMake finds this improved version.
#
# The upstream CMake FindRuby.cmake is being updated to support these targets,
# but until that lands, we use Rice's version.

list(PREPEND CMAKE_MODULE_PATH "${rice_SOURCE_DIR}")

# -----------------------------------------------------------------------------
# Find Ruby Installation
# -----------------------------------------------------------------------------
# find_package(Ruby) locates the Ruby installation and sets up:
#   - Ruby::Ruby    - Target for embedding Ruby (links to libruby)
#   - Ruby::Module  - Target for extensions (links to Ruby headers only)
#
# For extensions, always link to Ruby::Module, not Ruby::Ruby!
# Extensions are loaded into an already-running Ruby process, so they
# should not link against libruby (which could cause symbol conflicts).

find_package(Ruby REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
  Ruby::Module
)

# -----------------------------------------------------------------------------
# Link to Rice
# -----------------------------------------------------------------------------
# The Rice::Rice target provides:
#   - Include paths to Rice headers
#   - Required compiler flags for Rice
#
# Rice is header-only, so this doesn't add any link-time dependencies.

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
  Rice::Rice
)

# -----------------------------------------------------------------------------
# OpenCv
# -----------------------------------------------------------------------------

find_package(OpenCV CONFIG REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

# -----------------------------------------------------------------------------
# OpenCv
# -----------------------------------------------------------------------------
# FFI
if (MSVC) # This will include Clang on Windows
    find_package(unofficial-libffi CONFIG REQUIRED)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE unofficial::libffi::libffi)
elseif (APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(FFI REQUIRED IMPORTED_TARGET libffi)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE PkgConfig::FFI)
else()
    find_library(FFI_LIBRARY NAMES ffi REQUIRED)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${FFI_LIBRARY})
endif()
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE HAVE_LIBFFI)

# -----------------------------------------------------------------------------
# Include Directories for Project Headers
# -----------------------------------------------------------------------------
# Add the current directory (ext/) to the include path so we can find
# our project's header files (BitmapPlusPlus.hpp, etc.)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE .)

# -----------------------------------------------------------------------------
# Configure Extension Output
# -----------------------------------------------------------------------------
# Ruby extensions have specific naming requirements that vary by platform:
#
# Extension Suffix (from Ruby configuration):
#   - Linux:   .so           (e.g., bitmap_plus_plus_ruby.so)
#   - macOS:   .bundle       (e.g., bitmap_plus_plus_ruby.bundle)
#   - Windows: .so           (e.g., bitmap_plus_plus_ruby.so)
#
# Note: Windows uses .so (not .dll) for Ruby extensions by convention.
#
# PREFIX "": Ruby extensions have no 'lib' prefix (unlike regular shared libs)
#
# Visibility Settings:
#   - CXX_VISIBILITY_PRESET hidden: Hide all symbols by default
#   - VISIBILITY_INLINES_HIDDEN ON: Hide inline function symbols
#   - WINDOWS_EXPORT_ALL_SYMBOLS OFF: Don't auto-export on Windows
#
# These settings ensure only the Init_* function is exported, reducing
# binary size and avoiding symbol conflicts with other extensions.
#
# Output Directories:
#   - RUNTIME_OUTPUT_DIRECTORY: Where Windows puts .dll/.so files
#   - LIBRARY_OUTPUT_DIRECTORY: Where Unix puts .so/.bundle files
#
# On Windows, we place the extension in a Ruby version-specific subdirectory
# (e.g., lib/3.3/) to support multiple Ruby versions simultaneously.

get_target_property(RUBY_EXT_SUFFIX Ruby::Ruby INTERFACE_RUBY_EXTENSION_SUFFIX)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
  PREFIX ""
  SUFFIX ".dll" #"${RUBY_EXT_SUFFIX}"
  OUTPUT_NAME "opencv_ruby"
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN ON
  WINDOWS_EXPORT_ALL_SYMBOLS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib/${Ruby_VERSION_MAJOR}.${Ruby_VERSION_MINOR}" # Windows
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib" # Linxux/macOS
)

# -----------------------------------------------------------------------------
# Compiler Settings
# -----------------------------------------------------------------------------
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
                           CVAPI_EXPORTS)

# Fixes error G5FE2FDFE:  __attribute__((noreturn))' cannot be used prior to '::' because it has no members
if (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CV_NORETURN=)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CV_NORETURN="__declspec(noreturn)")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CV_NORETURN=)
endif()

# -----------------------------------------------------------------------------
# Source Files
# -----------------------------------------------------------------------------
# Add source files
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
               "opencv_ruby-rb.cpp")

# Add subdirectories
add_subdirectory ("opencv2")