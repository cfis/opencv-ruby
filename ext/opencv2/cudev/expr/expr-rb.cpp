#include <opencv2/cudev/expr/expr.hpp>
#include "expr-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Body>
inline void Expr_builder(Data_Type_T& klass)
{
  klass.define_attr("body", &cv::cudev::Expr<Body>::body);
};

void Init_Cudev_Expr_Expr()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}