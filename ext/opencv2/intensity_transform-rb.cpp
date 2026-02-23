#include <opencv2/intensity_transform.hpp>
#include "intensity_transform-rb.hpp"

using namespace Rice;

void Init_IntensityTransform()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvIntensityTransform = define_module_under(rb_mCv, "IntensityTransform");

  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::Mat, cv::Mat&)>("log_transform", &cv::intensity_transform::logTransform,
    Arg("input"), Arg("output"));

  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::Mat, cv::Mat&, const float)>("gamma_correction", &cv::intensity_transform::gammaCorrection,
    Arg("input"), Arg("output"), Arg("gamma"));

  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::Mat, cv::Mat&)>("autoscaling", &cv::intensity_transform::autoscaling,
    Arg("input"), Arg("output"));

  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::Mat, cv::Mat&, const int, const int, const int, const int)>("contrast_stretching", &cv::intensity_transform::contrastStretching,
    Arg("input"), Arg("output"), Arg("r1"), Arg("s1"), Arg("r2"), Arg("s2"));

  rb_mCvIntensityTransform.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, float, float)>("bimef", &cv::intensity_transform::BIMEF,
    Arg("input"), Arg("output"), Arg("mu") = static_cast<float>(0.5f), Arg("a") = static_cast<float>(-0.3293f), Arg("b") = static_cast<float>(1.1258f));

  rb_mCvIntensityTransform.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, float, float, float)>("bimef", &cv::intensity_transform::BIMEF,
    Arg("input"), Arg("output"), Arg("k"), Arg("mu"), Arg("a"), Arg("b"));
}
