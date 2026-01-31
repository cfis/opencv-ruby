#include <opencv2/cudev/expr/warping.hpp>
#include "warping-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr>
inline void PyrDownBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::PyrDownBody<SrcPtr>::src);
};

template<typename Data_Type_T, typename SrcPtr>
inline void PyrUpBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::PyrUpBody<SrcPtr>::src);
};

template<typename Data_Type_T, typename SrcPtr>
inline void TransposeBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::TransposeBody<SrcPtr>::src);
};

void Init_Cudev_Expr_Warping()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}