#include <opencv2/core/types.hpp>
#include <opencv2/core/check.hpp>
#include "../../opencv_ruby_version.hpp"
#include "check-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailCheckContext;

void Init_Check()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function("depth_to_string", &cv::depthToString,
    Arg("depth"));
  
  rb_mCv.define_module_function("type_to_string", &cv::typeToString,
    Arg("type"));
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_mCvDetail.define_module_function("depth_to_string_", &cv::detail::depthToString_,
    Arg("depth"));
  
  rb_mCvDetail.define_module_function("type_to_string_", &cv::detail::typeToString_,
    Arg("type"));
  
  Enum<cv::detail::TestOp> rb_cCvDetailTestOp = define_enum_under<cv::detail::TestOp>("TestOp", rb_mCvDetail).
    define_value("TEST_CUSTOM", cv::detail::TestOp::TEST_CUSTOM).
    define_value("TEST_EQ", cv::detail::TestOp::TEST_EQ).
    define_value("TEST_NE", cv::detail::TestOp::TEST_NE).
    define_value("TEST_LE", cv::detail::TestOp::TEST_LE).
    define_value("TEST_LT", cv::detail::TestOp::TEST_LT).
    define_value("TEST_GE", cv::detail::TestOp::TEST_GE).
    define_value("TEST_GT", cv::detail::TestOp::TEST_GT).
    define_value("CV__LAST_TEST_OP", cv::detail::TestOp::CV__LAST_TEST_OP);
  
  rb_cCvDetailCheckContext = define_class_under<cv::detail::CheckContext>(rb_mCvDetail, "CheckContext").
    define_constructor(Constructor<cv::detail::CheckContext>()).
    define_attr("func", &cv::detail::CheckContext::func).
    define_attr("file", &cv::detail::CheckContext::file).
    define_attr("line", &cv::detail::CheckContext::line).
    define_attr("test_op", &cv::detail::CheckContext::testOp).
    define_attr("message", &cv::detail::CheckContext::message).
    define_attr("p1_str", &cv::detail::CheckContext::p1_str).
    define_attr("p2_str", &cv::detail::CheckContext::p2_str);
  
#if RUBY_CV_VERSION >= 407
  rb_mCvDetail.define_module_function<void(*)(const bool, const bool, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
   Arg("v1"), Arg("v2"), Arg("ctx"));
#endif

  rb_mCvDetail.define_module_function<void(*)(const int, const int, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v1"), Arg("v2"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const ::size_t, const ::size_t, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v1"), Arg("v2"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const float, const float, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v1"), Arg("v2"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const double, const double, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v1"), Arg("v2"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const cv::Size_<int>, const cv::Size_<int>, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v1"), Arg("v2"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const int, const int, const cv::detail::CheckContext&)>("check_failed_mat_depth", &cv::detail::check_failed_MatDepth,
    Arg("v1"), Arg("v2"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const int, const int, const cv::detail::CheckContext&)>("check_failed_mat_type", &cv::detail::check_failed_MatType,
    Arg("v1"), Arg("v2"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const int, const int, const cv::detail::CheckContext&)>("check_failed_mat_channels", &cv::detail::check_failed_MatChannels,
    Arg("v1"), Arg("v2"), Arg("ctx"));
  
#if RUBY_CV_VERSION >= 407
  rb_mCvDetail.define_module_function("check_failed_true", &cv::detail::check_failed_true,
    Arg("v"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function("check_failed_false", &cv::detail::check_failed_false,
    Arg("v"), Arg("ctx"));
#endif

  rb_mCvDetail.define_module_function<void(*)(const int, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const ::size_t, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const float, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const double, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const cv::Size_<int>, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const std::string&, const cv::detail::CheckContext&)>("check_failed_auto", &cv::detail::check_failed_auto,
    Arg("v1"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const int, const cv::detail::CheckContext&)>("check_failed_mat_depth", &cv::detail::check_failed_MatDepth,
    Arg("v"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const int, const cv::detail::CheckContext&)>("check_failed_mat_type", &cv::detail::check_failed_MatType,
    Arg("v"), Arg("ctx"));
  
  rb_mCvDetail.define_module_function<void(*)(const int, const cv::detail::CheckContext&)>("check_failed_mat_channels", &cv::detail::check_failed_MatChannels,
    Arg("v"), Arg("ctx"));
}