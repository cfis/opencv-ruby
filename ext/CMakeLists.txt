cmake_minimum_required (VERSION 3.26)
#set(CMAKE_MESSAGE_LOG_LEVEL DEBUG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The Ruby extension is a shared library
project("opencv_ruby" LANGUAGES CXX)
add_library (${CMAKE_PROJECT_NAME} SHARED)

# Find OpenCv
find_package(OpenCV CONFIG REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

# FFI
if (MSVC) # This will include Clang on Windows
    find_package(unofficial-libffi CONFIG REQUIRED)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE unofficial::libffi::libffi)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE HAVE_LIBFFI)
else()
    find_library(FFI_LIBRARY NAMES ffi REQUIRED)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${FFI_LIBRARY})
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE HAVE_LIBFFI)
endif()

# Rice headers
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ".")

# Find Ruby
find_package(Ruby REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${Ruby_INCLUDE_DIR} ${Ruby_CONFIG_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${Ruby_LIBRARY})

# Ask Ruby what an extension's extension should be (dll, so, bundle, etc.)
execute_process(
  COMMAND "${Ruby_EXECUTABLE}" -rrbconfig -e "print RbConfig::CONFIG['DLEXT']"
  OUTPUT_VARIABLE RUBY_DLEXT
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Define project properties
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
  PREFIX ""
  SUFFIX ".${RUBY_DLEXT}"
  OUTPUT_NAME "opencv_ruby"
#        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib/${Ruby_VERSION_MAJOR}.${Ruby_VERSION_MINOR}" # Windows
 #       LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib") # Not Windows
 )

# Add source files
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "opencv_ruby.def"
    "opencv_ruby-rb.cpp")

# Add subdirectories
add_subdirectory ("opencv2")

# ---- Compiler Settings ---------
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
                           CVAPI_EXPORTS)

# Clang built into Visual Studio
if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC" AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Fixes error  error G5FE2FDFE:  __attribute__((noreturn))' cannot be used prior to '::' because it has no members
    target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CV_NORETURN="__declspec(noreturn)")
endif ()
