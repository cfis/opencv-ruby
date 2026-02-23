#include <opencv2/cudev/ptr2d/remap.hpp>
#include "remap-rb.hpp"

using namespace Rice;

#include "remap-rb.ipp"

void Init_Cudev_Ptr2d_Remap()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
