#include <opencv2/structured_light/structured_light.hpp>
#include "structured_light-rb.hpp"

using namespace Rice;

void Init_StructuredLight_StructuredLight()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvStructuredLight = define_module_under(rb_mCv, "StructuredLight");

  rb_mCvStructuredLight.define_constant("DECODE_3D_UNDERWORLD", (int)cv::structured_light::DECODE_3D_UNDERWORLD);

  Rice::Data_Type<cv::structured_light::StructuredLightPattern> rb_cCvStructuredLightStructuredLightPattern = define_class_under<cv::structured_light::StructuredLightPattern, cv::Algorithm>(rb_mCvStructuredLight, "StructuredLightPattern").
    define_method<bool(cv::structured_light::StructuredLightPattern::*)(cv::OutputArrayOfArrays)>("generate", &cv::structured_light::StructuredLightPattern::generate,
      Arg("pattern_images")).
    define_method<bool(cv::structured_light::StructuredLightPattern::*)(const std::vector<std::vector<cv::Mat>>&, cv::OutputArray, cv::InputArrayOfArrays, cv::InputArrayOfArrays, int) const>("decode", &cv::structured_light::StructuredLightPattern::decode,
      Arg("pattern_images"), Arg("disparity_map"), Arg("black_images") = static_cast<cv::InputArrayOfArrays>(cv::noArray()), Arg("white_images") = static_cast<cv::InputArrayOfArrays>(cv::noArray()), Arg("flags") = static_cast<int>(cv::structured_light::DECODE_3D_UNDERWORLD));
}