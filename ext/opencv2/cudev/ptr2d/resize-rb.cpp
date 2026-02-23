#include <opencv2/cudev/ptr2d/resize.hpp>
#include "resize-rb.hpp"

using namespace Rice;

#include "resize-rb.ipp"

void Init_Cudev_Ptr2d_Resize()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
