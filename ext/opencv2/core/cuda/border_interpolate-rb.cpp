#include <opencv2/core/cuda/border_interpolate.hpp>
#include "border_interpolate-rb.hpp"

using namespace Rice;

#include "border_interpolate-rb.ipp"

void Init_Core_Cuda_BorderInterpolate()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
}