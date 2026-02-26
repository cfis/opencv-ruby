# Subdirectories
add_subdirectory ("cuda")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "affine-rb.cpp"
    "async-rb.cpp"
    "base-rb.cpp"
    "bindings_utils-rb.cpp"
    "bufferpool-rb.cpp"
    "check-rb.cpp"
    "core-rb.cpp"
  )
