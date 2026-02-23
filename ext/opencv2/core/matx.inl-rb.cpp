#include <opencv2/core/matx.inl.hpp>
#include "matx.inl-rb.hpp"

using namespace Rice;

#include "matx.inl-rb.ipp"

void Init_Core_MatxInl()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");

  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");
}
