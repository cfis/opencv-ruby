# Subdirectories
add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "block-rb.cpp"
    "border_interpolate-rb.cpp"
    "color-rb.cpp"
    "common-rb.cpp"
    "datamov_utils-rb.cpp"
    "dynamic_smem-rb.cpp"
    "emulation-rb.cpp"
    "filters-rb.cpp"
    "funcattrib-rb.cpp"
  )
