#include <opencv2/cvconfig.h>
#include "cvconfig-rb.hpp"

using namespace Rice;

void Init_Cvconfig()
{
  Class(rb_cObject).define_constant("CUDA_ARCH_BIN", CUDA_ARCH_BIN);

  Class(rb_cObject).define_constant("CUDA_ARCH_FEATURES", CUDA_ARCH_FEATURES);

  Class(rb_cObject).define_constant("CUDA_ARCH_PTX", CUDA_ARCH_PTX);
}