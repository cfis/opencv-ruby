#include <opencv2/ximgproc/run_length_morphology.hpp>
#include "run_length_morphology-rb.hpp"

using namespace Rice;

void Init_Ximgproc_RunLengthMorphology()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Module rb_mCvXimgprocRl = define_module_under(rb_mCvXimgproc, "Rl");

  rb_mCvXimgprocRl.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, int)>("threshold", &cv::ximgproc::rl::threshold,
    Arg("src"), Arg("rl_dest"), Arg("thresh"), Arg("type"));

  rb_mCvXimgprocRl.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::Point)>("dilate", &cv::ximgproc::rl::dilate,
    Arg("rl_src"), Arg("rl_dest"), Arg("rl_kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(0, 0)));

  rb_mCvXimgprocRl.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, bool, cv::Point)>("erode", &cv::ximgproc::rl::erode,
    Arg("rl_src"), Arg("rl_dest"), Arg("rl_kernel"), Arg("b_boundary_on") = static_cast<bool>(true), Arg("anchor") = static_cast<cv::Point>(cv::Point(0, 0)));

  rb_mCvXimgprocRl.define_module_function<cv::Mat(*)(int, cv::Size)>("get_structuring_element", &cv::ximgproc::rl::getStructuringElement,
    Arg("shape"), Arg("ksize"));

  rb_mCvXimgprocRl.define_module_function<void(*)(cv::InputOutputArray, cv::InputArray, const cv::Scalar&)>("paint", &cv::ximgproc::rl::paint,
    Arg("image"), Arg("rl_src"), Arg("value"));

  rb_mCvXimgprocRl.define_module_function<bool(*)(cv::InputArray)>("rl_morphology_possible?", &cv::ximgproc::rl::isRLMorphologyPossible,
    Arg("rl_structuring_element"));

  rb_mCvXimgprocRl.define_module_function<void(*)(const std::vector<cv::Point3i>&, cv::OutputArray, cv::Size)>("create_rle_image", &cv::ximgproc::rl::createRLEImage,
    Arg("runs"), Arg("res"), Arg("size") = static_cast<cv::Size>(cv::Size(0, 0)));

  rb_mCvXimgprocRl.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, cv::InputArray, bool, cv::Point)>("morphology_ex", &cv::ximgproc::rl::morphologyEx,
    Arg("rl_src"), Arg("rl_dest"), Arg("op"), Arg("rl_kernel"), Arg("b_boundary_on_for_erosion") = static_cast<bool>(true), Arg("anchor") = static_cast<cv::Point>(cv::Point(0,0)));
}
