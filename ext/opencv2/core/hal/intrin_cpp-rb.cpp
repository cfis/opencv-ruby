#include <opencv2/core/hal/intrin_cpp.hpp>
#include "intrin_cpp-rb.hpp"

using namespace Rice;


void Init_IntrinCpp()
{
  Class(rb_cObject).define_constant("CV_SIMD128_CPP", CV_SIMD128_CPP);
  
  Class(rb_cObject).define_constant("CV_SIMD256", CV_SIMD256);
  
  Class(rb_cObject).define_constant("CV_SIMD512", CV_SIMD512);
  
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_constant("Simd128_width", (int)cv::simd128_width);
  rb_mCv.define_constant("Simdmax_width", (int)cv::simdmax_width);
  
  rb_mCv.define_singleton_attr("PopCountTable", &cv::popCountTable);
  
  rb_mCv.define_module_function("v_load_expand", &cv::v_load_expand,
    Arg("ptr"));
  
  rb_mCv.define_module_function("v_cleanup", &cv::v_cleanup);

}