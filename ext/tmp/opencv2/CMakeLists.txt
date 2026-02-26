# Subdirectories
add_subdirectory ("aruco")
add_subdirectory ("bioinspired")
add_subdirectory ("calib3d")
add_subdirectory ("ccalib")
add_subdirectory ("core")
add_subdirectory ("dnn")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "aruco-rb.cpp"
    "bgsegm-rb.cpp"
    "bioinspired-rb.cpp"
    "calib3d-rb.cpp"
    "ccalib-rb.cpp"
    "core-rb.cpp"
  )
