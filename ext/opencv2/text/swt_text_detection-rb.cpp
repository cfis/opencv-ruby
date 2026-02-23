#include <opencv2/text/swt_text_detection.hpp>
#include "swt_text_detection-rb.hpp"

using namespace Rice;

void Init_Text_SwtTextDetection()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvText = define_module_under(rb_mCv, "Text");

  rb_mCvText.define_module_function<void(*)(cv::InputArray, std::vector<cv::Rect>&, bool, const cv::_OutputArray&, const cv::_OutputArray&)>("detect_text_swt", &cv::text::detectTextSWT,
    Arg("input"), Arg("result"), Arg("dark_on_light"), Arg("draw") = static_cast<const cv::_OutputArray&>(cv::noArray()), Arg("chain_b_bs") = static_cast<const cv::_OutputArray&>(cv::noArray()));
}
