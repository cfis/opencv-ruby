#include "cvstd_wrapper-rb.ipp"

void Init_Core_CvstdWrapper()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvSfinae = define_module_under(rb_mCv, "Sfinae");
}