#include <opencv2/tracking/twist.hpp>
#include "twist-rb.hpp"

using namespace Rice;

void Init_Tracking_Twist()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");

  rb_mCvDetailTracking.define_module_function<cv::Vec6d(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&)>("compute_twist", &cv::detail::tracking::computeTwist,
    Arg("uv"), Arg("duv"), Arg("depths"), Arg("k"));

  rb_mCvDetailTracking.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, cv::Mat&)>("compute_interaction_matrix", &cv::detail::tracking::computeInteractionMatrix,
    Arg("uv"), Arg("depths"), Arg("k"), Arg("j"));
}
