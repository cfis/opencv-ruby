#include <opencv2/structured_light/graycodepattern.hpp>
#include "graycodepattern-rb.hpp"

using namespace Rice;

void Init_StructuredLight_Graycodepattern()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvStructuredLight = define_module_under(rb_mCv, "StructuredLight");

  Rice::Data_Type<cv::structured_light::GrayCodePattern> rb_cCvStructuredLightGrayCodePattern = define_class_under<cv::structured_light::GrayCodePattern, cv::structured_light::StructuredLightPattern>(rb_mCvStructuredLight, "GrayCodePattern").
    define_singleton_function<cv::Ptr<cv::structured_light::GrayCodePattern>(*)(const cv::structured_light::GrayCodePattern::Params&)>("create", &cv::structured_light::GrayCodePattern::create,
      Arg("parameters") = static_cast<const cv::structured_light::GrayCodePattern::Params&>(cv::structured_light::GrayCodePattern::Params())).
    define_singleton_function<cv::Ptr<cv::structured_light::GrayCodePattern>(*)(int, int)>("create", &cv::structured_light::GrayCodePattern::create,
      Arg("width"), Arg("height")).
    define_method<size_t(cv::structured_light::GrayCodePattern::*)() const>("get_number_of_pattern_images", &cv::structured_light::GrayCodePattern::getNumberOfPatternImages).
    define_method<void(cv::structured_light::GrayCodePattern::*)(size_t)>("set_white_threshold", &cv::structured_light::GrayCodePattern::setWhiteThreshold,
      Arg("value")).
    define_method<void(cv::structured_light::GrayCodePattern::*)(size_t)>("set_black_threshold", &cv::structured_light::GrayCodePattern::setBlackThreshold,
      Arg("value")).
    define_method<void(cv::structured_light::GrayCodePattern::*)(cv::InputOutputArray, cv::InputOutputArray) const>("get_images_for_shadow_masks", &cv::structured_light::GrayCodePattern::getImagesForShadowMasks,
      Arg("black_image"), Arg("white_image")).
    define_method<bool(cv::structured_light::GrayCodePattern::*)(cv::InputArrayOfArrays, int, int, cv::Point&) const>("get_proj_pixel", &cv::structured_light::GrayCodePattern::getProjPixel,
      Arg("pattern_images"), Arg("x"), Arg("y"), Arg("proj_pix"));

  Rice::Data_Type<cv::structured_light::GrayCodePattern::Params> rb_cCvStructuredLightGrayCodePatternParams = define_class_under<cv::structured_light::GrayCodePattern::Params>(rb_cCvStructuredLightGrayCodePattern, "Params").
    define_constructor(Constructor<cv::structured_light::GrayCodePattern::Params>()).
    define_attr("width", &cv::structured_light::GrayCodePattern::Params::width).
    define_attr("height", &cv::structured_light::GrayCodePattern::Params::height);
}