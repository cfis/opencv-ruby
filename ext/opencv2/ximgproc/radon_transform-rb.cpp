#include <opencv2/ximgproc/radon_transform.hpp>
#include "radon_transform-rb.hpp"

using namespace Rice;

void Init_Ximgproc_RadonTransform()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double, double, bool, bool)>("radon_transform", &cv::ximgproc::RadonTransform,
    Arg("src"), Arg("dst"), Arg("theta") = static_cast<double>(1), Arg("start_angle") = static_cast<double>(0), Arg("end_angle") = static_cast<double>(180), Arg("crop") = static_cast<bool>(false), Arg("norm") = static_cast<bool>(false));
}
