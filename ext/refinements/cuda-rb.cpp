#include <opencv2/core/cuda_stream_accessor.hpp>
#include "cuda-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_Refinements()
{
  Module rb_mCv = define_module("Cv");

  // External opaque types from CUDA headers (forward-declared
  // structs with no definition). These are used by StreamAccessor/EventAccessor.
  define_class<CUstream_st>("CUstreamSt");
  define_class<CUevent_st>("CUeventSt");
}
