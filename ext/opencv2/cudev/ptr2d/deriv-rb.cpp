#include <opencv2/cudev/ptr2d/deriv.hpp>
#include "deriv-rb.hpp"

using namespace Rice;

#include "deriv-rb.ipp"

void Init_Cudev_Ptr2d_Deriv()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}