# Subdirectories
add_subdirectory ("backend")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "parallel_backend-rb.cpp"
  )
