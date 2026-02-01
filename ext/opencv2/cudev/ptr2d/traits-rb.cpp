#include <opencv2/cudev/ptr2d/traits.hpp>
#include "traits-rb.hpp"

using namespace Rice;

#include "traits-rb.ipp"

void Init_Cudev_Ptr2d_Traits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}