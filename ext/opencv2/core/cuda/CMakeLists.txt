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
    "functional-rb.cpp"
    "limits-rb.cpp"
    "reduce-rb.cpp"
    "saturate_cast-rb.cpp"
    "scan-rb.cpp"
    "simd_functions-rb.cpp"
    "transform-rb.cpp"
    "type_traits-rb.cpp"
    "utility-rb.cpp"
    "vec_distance-rb.cpp"
    "vec_math-rb.cpp"
    "vec_traits-rb.cpp"
    "warp-rb.cpp"
    "warp_reduce-rb.cpp"
    "warp_shuffle-rb.cpp"
  )
