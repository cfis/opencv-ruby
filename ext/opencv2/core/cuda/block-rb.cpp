#include <opencv2/core/cuda/block.hpp>
#include "block-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceBlock;

void Init_Block()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceBlock = define_class_under<cv::cuda::device::Block>(rb_mCvCudaDevice, "Block").
    define_constructor(Constructor<cv::cuda::device::Block>());

}