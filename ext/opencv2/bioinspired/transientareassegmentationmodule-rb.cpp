#include <opencv2/bioinspired/transientareassegmentationmodule.hpp>
#include "transientareassegmentationmodule-rb.hpp"

using namespace Rice;

void Init_Bioinspired_Transientareassegmentationmodule()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvBioinspired = define_module_under(rb_mCv, "Bioinspired");

  Rice::Data_Type<cv::bioinspired::SegmentationParameters> rb_cCvBioinspiredSegmentationParameters = define_class_under<cv::bioinspired::SegmentationParameters>(rb_mCvBioinspired, "SegmentationParameters").
    define_constructor(Constructor<cv::bioinspired::SegmentationParameters>()).
    define_attr("threshold_on", &cv::bioinspired::SegmentationParameters::thresholdON).
    define_attr("threshold_off", &cv::bioinspired::SegmentationParameters::thresholdOFF).
    define_attr("local_energy_temporal_constant", &cv::bioinspired::SegmentationParameters::localEnergy_temporalConstant).
    define_attr("local_energy_spatial_constant", &cv::bioinspired::SegmentationParameters::localEnergy_spatialConstant).
    define_attr("neighborhood_energy_temporal_constant", &cv::bioinspired::SegmentationParameters::neighborhoodEnergy_temporalConstant).
    define_attr("neighborhood_energy_spatial_constant", &cv::bioinspired::SegmentationParameters::neighborhoodEnergy_spatialConstant).
    define_attr("context_energy_temporal_constant", &cv::bioinspired::SegmentationParameters::contextEnergy_temporalConstant).
    define_attr("context_energy_spatial_constant", &cv::bioinspired::SegmentationParameters::contextEnergy_spatialConstant);

  Rice::Data_Type<cv::bioinspired::TransientAreasSegmentationModule> rb_cCvBioinspiredTransientAreasSegmentationModule = define_class_under<cv::bioinspired::TransientAreasSegmentationModule, cv::Algorithm>(rb_mCvBioinspired, "TransientAreasSegmentationModule").
    define_method<cv::Size(cv::bioinspired::TransientAreasSegmentationModule::*)()>("get_size", &cv::bioinspired::TransientAreasSegmentationModule::getSize).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::String, const bool)>("setup", &cv::bioinspired::TransientAreasSegmentationModule::setup,
      Arg("segmentation_parameter_file") = static_cast<cv::String>(""), Arg("apply_default_setup_on_failure") = static_cast<const bool>(true)).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::FileStorage&, const bool)>("setup", &cv::bioinspired::TransientAreasSegmentationModule::setup,
      Arg("fs"), Arg("apply_default_setup_on_failure") = static_cast<const bool>(true)).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::bioinspired::SegmentationParameters)>("setup", &cv::bioinspired::TransientAreasSegmentationModule::setup,
      Arg("new_parameters")).
    define_method<cv::bioinspired::SegmentationParameters(cv::bioinspired::TransientAreasSegmentationModule::*)()>("get_parameters", &cv::bioinspired::TransientAreasSegmentationModule::getParameters).
    define_method<cv::String(cv::bioinspired::TransientAreasSegmentationModule::*)()>("print_setup", &cv::bioinspired::TransientAreasSegmentationModule::printSetup).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::String) const>("write", &cv::bioinspired::TransientAreasSegmentationModule::write,
      Arg("fs")).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::FileStorage&) const>("write", &cv::bioinspired::TransientAreasSegmentationModule::write,
      Arg("fs")).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::InputArray, const int)>("run", &cv::bioinspired::TransientAreasSegmentationModule::run,
      Arg("input_to_segment"), Arg("channel_index") = static_cast<const int>(0)).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::OutputArray)>("get_segmentation_picture", &cv::bioinspired::TransientAreasSegmentationModule::getSegmentationPicture,
      Arg("transient_areas")).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)()>("clear_all_buffers", &cv::bioinspired::TransientAreasSegmentationModule::clearAllBuffers).
    define_singleton_function<cv::Ptr<cv::bioinspired::TransientAreasSegmentationModule>(*)(cv::Size)>("create", &cv::bioinspired::TransientAreasSegmentationModule::create,
      Arg("input_size"));
}