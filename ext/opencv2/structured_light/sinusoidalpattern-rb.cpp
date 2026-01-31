#include <opencv2/structured_light/sinusoidalpattern.hpp>
#include "sinusoidalpattern-rb.hpp"

using namespace Rice;

void Init_StructuredLight_Sinusoidalpattern()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvStructuredLight = define_module_under(rb_mCv, "StructuredLight");

  rb_mCvStructuredLight.define_constant("FTP", (int)cv::structured_light::FTP);
  rb_mCvStructuredLight.define_constant("PSP", (int)cv::structured_light::PSP);
  rb_mCvStructuredLight.define_constant("FAPS", (int)cv::structured_light::FAPS);

  Rice::Data_Type<cv::structured_light::SinusoidalPattern> rb_cCvStructuredLightSinusoidalPattern = define_class_under<cv::structured_light::SinusoidalPattern, cv::structured_light::StructuredLightPattern>(rb_mCvStructuredLight, "SinusoidalPattern").
    define_method<void(cv::structured_light::SinusoidalPattern::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::OutputArray, cv::InputArray)>("compute_phase_map", &cv::structured_light::SinusoidalPattern::computePhaseMap,
      Arg("pattern_images"), Arg("wrapped_phase_map"), Arg("shadow_mask") = static_cast<cv::OutputArray>(cv::noArray()), Arg("fundamental") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<void(cv::structured_light::SinusoidalPattern::*)(cv::InputArray, cv::OutputArray, cv::Size, cv::InputArray)>("unwrap_phase_map", &cv::structured_light::SinusoidalPattern::unwrapPhaseMap,
      Arg("wrapped_phase_map"), Arg("unwrapped_phase_map"), Arg("cam_size"), Arg("shadow_mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<void(cv::structured_light::SinusoidalPattern::*)(cv::InputArray, cv::InputArray, cv::OutputArrayOfArrays)>("find_pro_cam_matches", &cv::structured_light::SinusoidalPattern::findProCamMatches,
      Arg("proj_unwrapped_phase_map"), Arg("cam_unwrapped_phase_map"), Arg("matches")).
    define_method<void(cv::structured_light::SinusoidalPattern::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray)>("compute_data_modulation_term", &cv::structured_light::SinusoidalPattern::computeDataModulationTerm,
      Arg("pattern_images"), Arg("data_modulation_term"), Arg("shadow_mask")).
    define_singleton_function<cv::Ptr<cv::structured_light::SinusoidalPattern>(*)(cv::Ptr<cv::structured_light::SinusoidalPattern::Params>)>("create", &cv::structured_light::SinusoidalPattern::create,
      Arg("parameters") = static_cast<cv::Ptr<cv::structured_light::SinusoidalPattern::Params>>(cv::makePtr<cv::structured_light::SinusoidalPattern::Params>()));

  Rice::Data_Type<cv::structured_light::SinusoidalPattern::Params> rb_cCvStructuredLightSinusoidalPatternParams = define_class_under<cv::structured_light::SinusoidalPattern::Params>(rb_cCvStructuredLightSinusoidalPattern, "Params").
    define_constructor(Constructor<cv::structured_light::SinusoidalPattern::Params>()).
    define_attr("width", &cv::structured_light::SinusoidalPattern::Params::width).
    define_attr("height", &cv::structured_light::SinusoidalPattern::Params::height).
    define_attr("nbr_of_periods", &cv::structured_light::SinusoidalPattern::Params::nbrOfPeriods).
    define_attr("shift_value", &cv::structured_light::SinusoidalPattern::Params::shiftValue).
    define_attr("method_id", &cv::structured_light::SinusoidalPattern::Params::methodId).
    define_attr("nbr_of_pixels_between_markers", &cv::structured_light::SinusoidalPattern::Params::nbrOfPixelsBetweenMarkers).
    define_attr("horizontal", &cv::structured_light::SinusoidalPattern::Params::horizontal).
    define_attr("set_markers", &cv::structured_light::SinusoidalPattern::Params::setMarkers).
    define_attr("markers_location", &cv::structured_light::SinusoidalPattern::Params::markersLocation);
}