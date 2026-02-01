#include <opencv2/cudev/ptr2d/transform.hpp>
#include "transform-rb.hpp"

using namespace Rice;

#include "transform-rb.ipp"

void Init_Cudev_Ptr2d_Transform()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}