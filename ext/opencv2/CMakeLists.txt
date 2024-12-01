# Subdirectories
add_subdirectory ("core")
add_subdirectory ("dnn")
add_subdirectory ("flann")
add_subdirectory ("stitching")
add_subdirectory ("video")

if ((${OpenCV_VERSION_MAJOR} EQUAL 4 AND ${OpenCV_VERSION_MINOR} GREATER_EQUAL 8) OR ${OpenCV_VERSION_MAJOR} GREATER_EQUAL 5)
add_subdirectory ("objdetect")
endif()

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "calib3d-rb.cpp"
    "core-rb.cpp"
    "dnn-rb.cpp"
    "features2d-rb.cpp"
    "flann-rb.cpp"
    "highgui-rb.cpp"
    "imgcodecs-rb.cpp"
    "imgproc-rb.cpp"
    "ml-rb.cpp"
    "objdetect-rb.cpp"
    "opencv_modules-rb.cpp"
    "photo-rb.cpp"
    "stitching-rb.cpp"
    "videoio-rb.cpp"
  )
