#include <opencv2/core/cuda/warp.hpp>
#include "warp-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceWarp;

void Init_Warp()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceWarp = define_class_under<cv::cuda::device::Warp>(rb_mCvCudaDevice, "Warp").
    define_constructor(Constructor<cv::cuda::device::Warp>());
  
  rb_cCvCudaDeviceWarp.define_constant("LOG_WARP_SIZE", (int)cv::cuda::device::Warp::LOG_WARP_SIZE);
  rb_cCvCudaDeviceWarp.define_constant("WARP_SIZE", (int)cv::cuda::device::Warp::WARP_SIZE);
  rb_cCvCudaDeviceWarp.define_constant("STRIDE", (int)cv::cuda::device::Warp::STRIDE);

}