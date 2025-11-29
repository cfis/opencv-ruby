#include <opencv2/stitching/detail/util_inl.hpp>
#include "util_inl-rb.hpp"

using namespace Rice;


void Init_UtilInl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_mCvDetail.define_module_function<float(*)(const cv::Point3f&)>("norm_l2", &cv::detail::normL2,
    Arg("a"));
  
  rb_mCvDetail.define_module_function<float(*)(const cv::Point3f&, const cv::Point3f&)>("norm_l2", &cv::detail::normL2,
    Arg("a"), Arg("b"));
  
  rb_mCvDetail.define_module_function("norm_l2sq", &cv::detail::normL2sq,
    Arg("r"));
  
  rb_mCvDetail.define_module_function<int(*)(int)>("sqr", &cv::detail::sqr,
    Arg("x"));
  
  rb_mCvDetail.define_module_function<float(*)(float)>("sqr", &cv::detail::sqr,
    Arg("x"));
  
  rb_mCvDetail.define_module_function<double(*)(double)>("sqr", &cv::detail::sqr,
    Arg("x"));

}