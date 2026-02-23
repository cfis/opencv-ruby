#include <opencv2/cudev/expr/reduction.hpp>
#include "reduction-rb.hpp"

using namespace Rice;

#include "reduction-rb.ipp"

void Init_Cudev_Expr_Reduction()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
