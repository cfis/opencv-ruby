#include <opencv2/core/cuda/color.hpp>
#include "color-rb.hpp"

using namespace Rice;


void Init_Color()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  

}