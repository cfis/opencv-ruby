#include "glob-rb.ipp"

void Init_Cudev_Ptr2d_Glob()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}