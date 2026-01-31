#include <opencv2/cudev/expr/expr.hpp>
#include "expr-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Body>
inline void Expr_builder(Data_Type_T& klass)
{
  klass.define_attr("body", &cv::cudev::Expr<Body>::body);
};

