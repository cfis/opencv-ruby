#include <opencv2/phase_unwrapping/phase_unwrapping.hpp>
#include "phase_unwrapping-rb.hpp"

using namespace Rice;

void Init_PhaseUnwrapping_PhaseUnwrapping()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvPhaseUnwrapping = define_module_under(rb_mCv, "PhaseUnwrapping");

  Rice::Data_Type<cv::phase_unwrapping::PhaseUnwrapping> rb_cCvPhaseUnwrappingPhaseUnwrapping = define_class_under<cv::phase_unwrapping::PhaseUnwrapping, cv::Algorithm>(rb_mCvPhaseUnwrapping, "PhaseUnwrapping").
    define_method<void(cv::phase_unwrapping::PhaseUnwrapping::*)(cv::InputArray, cv::OutputArray, cv::InputArray)>("unwrap_phase_map", &cv::phase_unwrapping::PhaseUnwrapping::unwrapPhaseMap,
      Arg("wrapped_phase_map"), Arg("unwrapped_phase_map"), Arg("shadow_mask") = static_cast<cv::InputArray>(cv::noArray()));
}