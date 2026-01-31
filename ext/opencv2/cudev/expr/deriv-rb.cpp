#include <opencv2/cudev/expr/deriv.hpp>
#include "deriv-rb.hpp"

using namespace Rice;

void Init_Cudev_Expr_Deriv()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}