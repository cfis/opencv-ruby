#include <opencv2/ximgproc/find_ellipses.hpp>
#include "find_ellipses-rb.hpp"

using namespace Rice;

void Init_Ximgproc_FindEllipses()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, float, float)>("find_ellipses", &cv::ximgproc::findEllipses,
    Arg("image"), Arg("ellipses"), Arg("score_threshold") = static_cast<float>(0.7f), Arg("reliability_threshold") = static_cast<float>(0.5f), Arg("center_distance_threshold") = static_cast<float>(0.05f));
}
