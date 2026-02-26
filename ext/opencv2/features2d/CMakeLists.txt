# Subdirectories
add_subdirectory ("hal")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "features2d-rb.cpp"
  )
