# Subdirectories
add_subdirectory ("utils")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "all_layers-rb.cpp"
    "dict-rb.cpp"
    #"dnn-rb.cpp"
    "layer-rb.cpp"
    "layer.details-rb.cpp"
    "shape_utils-rb.cpp"
    "version-rb.cpp"
  )
