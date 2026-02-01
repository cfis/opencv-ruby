#include <opencv2/cudev/ptr2d/zip.hpp>
#include "zip-rb.hpp"

using namespace Rice;

#include "zip-rb.ipp"

void Init_Cudev_Ptr2d_Zip()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}