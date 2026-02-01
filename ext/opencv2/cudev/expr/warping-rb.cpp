#include <opencv2/cudev/expr/warping.hpp>
#include "warping-rb.hpp"

using namespace Rice;

#include "warping-rb.ipp"

void Init_Cudev_Expr_Warping()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}