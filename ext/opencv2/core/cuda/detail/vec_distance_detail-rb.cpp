#include <opencv2/core/cuda/detail/vec_distance_detail.hpp>
#include "vec_distance_detail-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_Detail_VecDistanceDetail()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Module rb_mCvCudaDeviceVecDistanceDetail = define_module_under(rb_mCvCudaDevice, "VecDistanceDetail");
}
