#include <opencv2/core/cuda/funcattrib.hpp>
#include "funcattrib-rb.hpp"

using namespace Rice;


void Init_Funcattrib()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  

}