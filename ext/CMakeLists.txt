cmake_minimum_required (VERSION 3.26)
#set(CMAKE_MESSAGE_LOG_LEVEL DEBUG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The Ruby extension is a shared library
project("opencv_ruby" LANGUAGES C CXX)
add_library (${CMAKE_PROJECT_NAME} SHARED)

# Find OpenCv
find_package(OpenCV CONFIG REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS})

# FFI
find_library(FFI_LIBRARY NAMES ffi REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} ${FFI_LIBRARY})
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE HAVE_LIBFFI)

# Find Ruby
find_package(Ruby REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${Ruby_INCLUDE_DIR} ${Ruby_CONFIG_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} ${Ruby_LIBRARY})

# Rice headers
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ".")

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

# ---- Compiler Settings ---------
if (MSVC)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
            _CRT_SECURE_NO_DEPRECATE
            _CRT_NONSTDC_NO_DEPRECATE)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CVAPI_EXPORTS)

    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE 
            /W4        # Warning level 4
            /bigobj    # Increase number of sections in .obj file
            /utf-8)    # Set source and execution character sets to UTF-8
    
    # Edit and Continue for Debug builds
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT 
        "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
    
    # Fix exception handling for Ruby's longjmp
    # The default of /EHsc crashes Ruby when calling longjmp with optimizations on (/O2)
    # So replace /EHsc with /EHs just for this target
    get_target_property(_cxx_opts ${CMAKE_PROJECT_NAME} COMPILE_OPTIONS)
    if(_cxx_opts)
        list(TRANSFORM _cxx_opts REPLACE "/EHsc" "/EHs")
        set_target_properties(${CMAKE_PROJECT_NAME}  PROPERTIES COMPILE_OPTIONS "${_cxx_opts}")
    endif()
else ()   
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
            -Wall
            -Wno-unused-private-field
            -ftemplate-backtrace-limit=0
            -Wa,-mbig-obj
            $<$<CONFIG:Debug>:-Og>)
endif ()


#elseif (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#  #  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
 # target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC _CRT_SECURE_NO_DEPRECATE _CRT_NONSTDC_NO_DEPRECATE)
  # Fixes error  error G5FE2FDFE:  __attribute__((noreturn))' cannot be used prior to '::' because it has no members
 # target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CV_NORETURN="__attribute__((__noreturn__))")
 # target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC CVAPI_EXPORTS)
 # target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -Wa,-mbig-obj)

#elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -ftemplate-backtrace-limit=0)
#endif ()
