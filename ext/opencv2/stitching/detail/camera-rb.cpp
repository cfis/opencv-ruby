#include <opencv2/stitching/detail/camera.hpp>
#include "camera-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailCameraParams;

void Init_Camera()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_cCvDetailCameraParams = define_class_under<cv::detail::CameraParams>(rb_mCvDetail, "CameraParams").
    define_constructor(Constructor<cv::detail::CameraParams>()).
    define_constructor(Constructor<cv::detail::CameraParams, const cv::detail::CameraParams&>(),
      Arg("other")).
    define_method("assign", &cv::detail::CameraParams::operator=,
      Arg("other")).
    define_method("k", &cv::detail::CameraParams::K).
    define_attr("focal", &cv::detail::CameraParams::focal).
    define_attr("aspect", &cv::detail::CameraParams::aspect).
    define_attr("ppx", &cv::detail::CameraParams::ppx).
    define_attr("ppy", &cv::detail::CameraParams::ppy).
    define_attr("r", &cv::detail::CameraParams::R).
    define_attr("t", &cv::detail::CameraParams::t);

}