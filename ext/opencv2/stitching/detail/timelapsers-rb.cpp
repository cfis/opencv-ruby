#include <opencv2/stitching/detail/timelapsers.hpp>
#include "../../core/cvstd_wrapper-rb.hpp"
#include "timelapsers-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailTimelapser;
Rice::Class rb_cCvDetailTimelapserCrop;

void Init_Timelapsers()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_cCvDetailTimelapser = define_class_under<cv::detail::Timelapser>(rb_mCvDetail, "Timelapser").
    define_constructor(Constructor<cv::detail::Timelapser>()).
    define_singleton_function("create_default", &cv::detail::Timelapser::createDefault,
      Arg("type")).
    define_method("initialize", &cv::detail::Timelapser::initialize,
      Arg("corners"), Arg("sizes")).
    define_method("process", &cv::detail::Timelapser::process,
      Arg("img"), Arg("mask"), Arg("tl")).
    define_method("get_dst", &cv::detail::Timelapser::getDst);
  
  rb_cCvDetailTimelapser.define_constant("AS_IS", (int)cv::detail::Timelapser::AS_IS);
  rb_cCvDetailTimelapser.define_constant("CROP", (int)cv::detail::Timelapser::CROP);
  
  rb_cCvDetailTimelapserCrop = define_class_under<cv::detail::TimelapserCrop, cv::detail::Timelapser>(rb_mCvDetail, "TimelapserCrop").
    define_constructor(Constructor<cv::detail::TimelapserCrop>()).
    define_method("initialize", &cv::detail::TimelapserCrop::initialize,
      Arg("corners"), Arg("sizes"));

}