# Subdirectories
add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "warpers-rb.cpp"
  )
