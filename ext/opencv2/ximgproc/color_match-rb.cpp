#include <opencv2/ximgproc/color_match.hpp>
#include "color_match-rb.hpp"

using namespace Rice;

void Init_Ximgproc_ColorMatch()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("create_quaternion_image", &cv::ximgproc::createQuaternionImage,
    Arg("img"), Arg("qimg"));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("qconj", &cv::ximgproc::qconj,
    Arg("qimg"), Arg("qcimg"));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("qunitary", &cv::ximgproc::qunitary,
    Arg("qimg"), Arg("qnimg"));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("qmultiply", &cv::ximgproc::qmultiply,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, bool)>("qdft", &cv::ximgproc::qdft,
    Arg("img"), Arg("qimg"), Arg("flags"), Arg("side_left"));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("color_match_template", &cv::ximgproc::colorMatchTemplate,
    Arg("img"), Arg("templ"), Arg("result"));
}