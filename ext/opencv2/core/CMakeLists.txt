# Subdirectories
add_subdirectory ("detail")
add_subdirectory ("hal")
add_subdirectory ("parallel")
add_subdirectory ("utils")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "affine-rb.cpp"
    "async-rb.cpp"
    "base-rb.cpp"
    "bindings_utils-rb.cpp"
    "bufferpool-rb.cpp"
    "check-rb.cpp"
    "core-rb.cpp"
    "cuda-rb.cpp"
    "cuda_stream_accessor-rb.cpp"
    "cuda_types-rb.cpp"
    "cv_cpu_dispatch-rb.cpp"
    "cv_cpu_helper-rb.cpp"
    "cvdef-rb.cpp"
    "cvstd-rb.cpp"
    "cvstd.inl-rb.cpp"
    "cvstd_wrapper-rb.cpp"
    "dualquaternion-rb.cpp"
    "fast_math-rb.cpp"
    "mat-rb.cpp"
    "mat.inl-rb.cpp"
    "matx-rb.cpp"
    "matx.inl-rb.cpp"
    "neon_utils-rb.cpp"
    "ocl-rb.cpp"
    "ocl_genbase-rb.cpp"
    "opengl-rb.cpp"
    "operations-rb.cpp"
    "optim-rb.cpp"
    "ovx-rb.cpp"
    "persistence-rb.cpp"
    "quaternion-rb.cpp"
    "saturate-rb.cpp"
    "simd_intrinsics-rb.cpp"
    "softfloat-rb.cpp"
    "traits-rb.cpp"
    "types-rb.cpp"
    "utility-rb.cpp"
    "va_intel-rb.cpp"
    "version-rb.cpp"
    "vsx_utils-rb.cpp"
  )
