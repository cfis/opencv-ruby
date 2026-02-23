#include <opencv2/stitching/detail/timelapsers.hpp>
#include "timelapsers-rb.hpp"

using namespace Rice;

void Init_Stitching_Detail_Timelapsers()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Rice::Data_Type<cv::detail::Timelapser> rb_cCvDetailTimelapser = define_class_under<cv::detail::Timelapser>(rb_mCvDetail, "Timelapser").
    define_constructor(Constructor<cv::detail::Timelapser>()).
    define_singleton_function<cv::Ptr<cv::detail::Timelapser>(*)(int)>("create_default", &cv::detail::Timelapser::createDefault,
      Arg("type")).
    define_method<void(cv::detail::Timelapser::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("initialize", &cv::detail::Timelapser::initialize,
      Arg("corners"), Arg("sizes")).
    define_method<void(cv::detail::Timelapser::*)(cv::InputArray, cv::InputArray, cv::Point)>("process", &cv::detail::Timelapser::process,
      Arg("img"), Arg("mask"), Arg("tl")).
    define_method<const cv::UMat&(cv::detail::Timelapser::*)()>("get_dst", &cv::detail::Timelapser::getDst);

  rb_cCvDetailTimelapser.define_constant("AS_IS", (int)cv::detail::Timelapser::AS_IS);
  rb_cCvDetailTimelapser.define_constant("CROP", (int)cv::detail::Timelapser::CROP);

  Rice::Data_Type<cv::detail::TimelapserCrop> rb_cCvDetailTimelapserCrop = define_class_under<cv::detail::TimelapserCrop, cv::detail::Timelapser>(rb_mCvDetail, "TimelapserCrop").
    define_constructor(Constructor<cv::detail::TimelapserCrop>()).
    define_method<void(cv::detail::TimelapserCrop::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("initialize", &cv::detail::TimelapserCrop::initialize,
      Arg("corners"), Arg("sizes"));
}
