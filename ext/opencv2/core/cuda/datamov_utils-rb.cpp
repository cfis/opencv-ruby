#include <opencv2/core/cuda/datamov_utils.hpp>
#include "datamov_utils-rb.hpp"

using namespace Rice;


void Init_DatamovUtils()
{
  Class(rb_cObject).define_constant("OPENCV_CUDA_ASM_PTR", OPENCV_CUDA_ASM_PTR);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  

}