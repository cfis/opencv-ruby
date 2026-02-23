#include <opencv2/cudev/ptr2d/detail/gpumat.hpp>
#include "gpumat-rb.hpp"

using namespace Rice;

void Init_Cudev_Ptr2d_Detail_Gpumat()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
