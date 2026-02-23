#include <opencv2/ximgproc/deriche_filter.hpp>
#include "deriche_filter-rb.hpp"

using namespace Rice;

void Init_Ximgproc_DericheFilter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double)>("gradient_deriche_y", &cv::ximgproc::GradientDericheY,
    Arg("op"), Arg("dst"), Arg("alpha"), Arg("omega"));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double)>("gradient_deriche_x", &cv::ximgproc::GradientDericheX,
    Arg("op"), Arg("dst"), Arg("alpha"), Arg("omega"));
}
