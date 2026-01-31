#include <opencv2/ximgproc/paillou_filter.hpp>
#include "paillou_filter-rb.hpp"

using namespace Rice;

void Init_Ximgproc_PaillouFilter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double)>("gradient_paillou_y", &cv::ximgproc::GradientPaillouY,
    Arg("op"), Arg("_dst"), Arg("alpha"), Arg("omega"));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double)>("gradient_paillou_x", &cv::ximgproc::GradientPaillouX,
    Arg("op"), Arg("_dst"), Arg("alpha"), Arg("omega"));
}