# Subdirectories

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "deblurring-rb.cpp"
    "fast_marching-rb.cpp"
    "fast_marching_inl-rb.cpp"
    "frame_source-rb.cpp"
    "global_motion-rb.cpp"
    "inpainting-rb.cpp"
    "log-rb.cpp"
    "motion_core-rb.cpp"
    "motion_stabilizing-rb.cpp"
    "optical_flow-rb.cpp"
    "outlier_rejection-rb.cpp"
    "ring_buffer-rb.cpp"
    "stabilizer-rb.cpp"
    "wobble_suppression-rb.cpp"
  )
