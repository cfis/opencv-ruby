#include <opencv2/cudev/ptr2d/constant.hpp>
#include "constant-rb.hpp"

using namespace Rice;

#include "constant-rb.ipp"

void Init_Cudev_Ptr2d_Constant()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
