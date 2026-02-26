# Subdirectories
add_subdirectory ("detail")
add_subdirectory ("hal")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "bindings-rb.cpp"
    "imgproc-rb.cpp"
    "segmentation-rb.cpp"
  )
