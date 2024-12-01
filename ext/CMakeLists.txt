cmake_minimum_required (VERSION 3.26)
#set(CMAKE_MESSAGE_LOG_LEVEL DEBUG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The Ruby extension is a shared library
project("opencv_ruby" LANGUAGES C CXX)
add_library (${CMAKE_PROJECT_NAME} SHARED)

# Find Ruby
find_package(Ruby REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${Ruby_INCLUDE_DIR} ${Ruby_CONFIG_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} ${Ruby_LIBRARY})

# Find OpenCv
find_package(OpenCV CONFIG REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS})

# Hard code location of Rice headers
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "c:\\source\\rice")

# Define project properties
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        PREFIX ""
        SUFFIX ".dll"
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

# Set compiler options
if (MINGW)
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -ftemplate-backtrace-limit=0)
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -Wa,-mbig-obj)
  # https://github.com/doxygen/doxygen/issues/9269#issuecomment-1094975328
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  #set(VCPKG_VERBOSE, true)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
  target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC _CRT_SECURE_NO_DEPRECATE _CRT_NONSTDC_NO_DEPRECATE)
  target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CVAPI_EXPORTS)
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC /bigobj /utf-8)

  # The default of /EHsc crashes Ruby when calling longjmp with optimizations on (/O2)
  string(REGEX REPLACE "/EHsc" "/EHs" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY VS_DEBUGGER_COMMAND $<$<CONFIG:DEBUG>:\$(ProjectDir))

elseif (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  #  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
  target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC _CRT_SECURE_NO_DEPRECATE _CRT_NONSTDC_NO_DEPRECATE)
  # Fixes error  error G5FE2FDFE:  __attribute__((noreturn))' cannot be used prior to '::' because it has no members
  target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CV_NORETURN="__attribute__((__noreturn__))")
  target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CVAPI_EXPORTS)
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -Wa,-mbig-obj)

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -ftemplate-backtrace-limit=0)
endif ()
