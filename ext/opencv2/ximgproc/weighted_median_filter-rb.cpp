#include <opencv2/ximgproc/weighted_median_filter.hpp>
#include "weighted_median_filter-rb.hpp"

using namespace Rice;

void Init_Ximgproc_WeightedMedianFilter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Enum<cv::ximgproc::WMFWeightType> rb_cCvXimgprocWMFWeightType = define_enum_under<cv::ximgproc::WMFWeightType>("WMFWeightType", rb_mCvXimgproc).
    define_value("WMF_EXP", cv::ximgproc::WMFWeightType::WMF_EXP).
    define_value("WMF_IV1", cv::ximgproc::WMFWeightType::WMF_IV1).
    define_value("WMF_IV2", cv::ximgproc::WMFWeightType::WMF_IV2).
    define_value("WMF_COS", cv::ximgproc::WMFWeightType::WMF_COS).
    define_value("WMF_JAC", cv::ximgproc::WMFWeightType::WMF_JAC).
    define_value("WMF_OFF", cv::ximgproc::WMFWeightType::WMF_OFF);

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, double, int, cv::InputArray)>("weighted_median_filter", &cv::ximgproc::weightedMedianFilter,
    Arg("joint"), Arg("src"), Arg("dst"), Arg("r"), Arg("sigma") = static_cast<double>(25.5), Arg("weight_type") = static_cast<int>(cv::ximgproc::WMF_EXP), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
}