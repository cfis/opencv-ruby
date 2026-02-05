# Refinements - manual additions to generated classes
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
               "base-rb.cpp"
               "core-rb.cpp"
               "dnn-rb.cpp"
               "hal-rb.cpp"
               "mat-rb.cpp"
               "matx-rb.cpp"
               "persistence-rb.cpp"
               "types-rb.cpp")

# CUDA refinements (optional)
if(OpenCV_HAS_CUDA)
  target_sources(${CMAKE_PROJECT_NAME} PRIVATE "cuda-rb.cpp")
endif()
