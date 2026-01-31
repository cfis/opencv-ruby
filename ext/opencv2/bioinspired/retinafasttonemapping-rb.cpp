#include <opencv2/bioinspired/retinafasttonemapping.hpp>
#include "retinafasttonemapping-rb.hpp"

using namespace Rice;

void Init_Bioinspired_Retinafasttonemapping()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvBioinspired = define_module_under(rb_mCv, "Bioinspired");

  Rice::Data_Type<cv::bioinspired::RetinaFastToneMapping> rb_cCvBioinspiredRetinaFastToneMapping = define_class_under<cv::bioinspired::RetinaFastToneMapping, cv::Algorithm>(rb_mCvBioinspired, "RetinaFastToneMapping").
    define_method<void(cv::bioinspired::RetinaFastToneMapping::*)(cv::InputArray, cv::OutputArray)>("apply_fast_tone_mapping", &cv::bioinspired::RetinaFastToneMapping::applyFastToneMapping,
      Arg("input_image"), Arg("output_tone_mapped_image")).
    define_method<void(cv::bioinspired::RetinaFastToneMapping::*)(const float, const float, const float)>("setup", &cv::bioinspired::RetinaFastToneMapping::setup,
      Arg("photoreceptors_neighborhood_radius") = static_cast<const float>(3.f), Arg("ganglioncells_neighborhood_radius") = static_cast<const float>(1.f), Arg("mean_luminance_modulator_k") = static_cast<const float>(1.f)).
    define_singleton_function<cv::Ptr<cv::bioinspired::RetinaFastToneMapping>(*)(cv::Size)>("create", &cv::bioinspired::RetinaFastToneMapping::create,
      Arg("input_size"));
}