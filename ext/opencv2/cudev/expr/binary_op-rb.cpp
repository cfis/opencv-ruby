#include <opencv2/cudev/expr/binary_op.hpp>
#include "binary_op-rb.hpp"

using namespace Rice;

void Init_Cudev_Expr_BinaryOp()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
