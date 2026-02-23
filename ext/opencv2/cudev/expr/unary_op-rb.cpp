#include <opencv2/cudev/expr/unary_op.hpp>
#include "unary_op-rb.hpp"

using namespace Rice;

void Init_Cudev_Expr_UnaryOp()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
