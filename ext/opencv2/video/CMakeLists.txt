# Subdirectories
add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "background_segm-rb.cpp"
    "tracking-rb.cpp"
    "video-rb.cpp"
  )
