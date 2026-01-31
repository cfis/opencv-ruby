#include <opencv2/bioinspired/retina.hpp>
#include "retina-rb.hpp"

using namespace Rice;

void Init_Bioinspired_Retina()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvBioinspired = define_module_under(rb_mCv, "Bioinspired");

  rb_mCvBioinspired.define_constant("RETINA_COLOR_RANDOM", (int)cv::bioinspired::RETINA_COLOR_RANDOM);
  rb_mCvBioinspired.define_constant("RETINA_COLOR_DIAGONAL", (int)cv::bioinspired::RETINA_COLOR_DIAGONAL);
  rb_mCvBioinspired.define_constant("RETINA_COLOR_BAYER", (int)cv::bioinspired::RETINA_COLOR_BAYER);

  Rice::Data_Type<cv::bioinspired::RetinaParameters> rb_cCvBioinspiredRetinaParameters = define_class_under<cv::bioinspired::RetinaParameters>(rb_mCvBioinspired, "RetinaParameters").
    define_constructor(Constructor<cv::bioinspired::RetinaParameters>()).
    define_attr("op_land_ipl_parvo", &cv::bioinspired::RetinaParameters::OPLandIplParvo).
    define_attr("ipl_magno", &cv::bioinspired::RetinaParameters::IplMagno);

  Rice::Data_Type<cv::bioinspired::RetinaParameters::OPLandIplParvoParameters> rb_cCvBioinspiredRetinaParametersOPLandIplParvoParameters = define_class_under<cv::bioinspired::RetinaParameters::OPLandIplParvoParameters>(rb_cCvBioinspiredRetinaParameters, "OPLandIplParvoParameters").
    define_constructor(Constructor<cv::bioinspired::RetinaParameters::OPLandIplParvoParameters>()).
    define_attr("color_mode", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::colorMode).
    define_attr("normalise_output", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::normaliseOutput).
    define_attr("photoreceptors_local_adaptation_sensitivity", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::photoreceptorsLocalAdaptationSensitivity).
    define_attr("photoreceptors_temporal_constant", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::photoreceptorsTemporalConstant).
    define_attr("photoreceptors_spatial_constant", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::photoreceptorsSpatialConstant).
    define_attr("horizontal_cells_gain", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::horizontalCellsGain).
    define_attr("hcells_temporal_constant", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::hcellsTemporalConstant).
    define_attr("hcells_spatial_constant", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::hcellsSpatialConstant).
    define_attr("ganglion_cells_sensitivity", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::ganglionCellsSensitivity);

  Rice::Data_Type<cv::bioinspired::RetinaParameters::IplMagnoParameters> rb_cCvBioinspiredRetinaParametersIplMagnoParameters = define_class_under<cv::bioinspired::RetinaParameters::IplMagnoParameters>(rb_cCvBioinspiredRetinaParameters, "IplMagnoParameters").
    define_constructor(Constructor<cv::bioinspired::RetinaParameters::IplMagnoParameters>()).
    define_attr("normalise_output", &cv::bioinspired::RetinaParameters::IplMagnoParameters::normaliseOutput).
    define_attr("parasol_cells_beta", &cv::bioinspired::RetinaParameters::IplMagnoParameters::parasolCells_beta).
    define_attr("parasol_cells_tau", &cv::bioinspired::RetinaParameters::IplMagnoParameters::parasolCells_tau).
    define_attr("parasol_cells_k", &cv::bioinspired::RetinaParameters::IplMagnoParameters::parasolCells_k).
    define_attr("amacrin_cells_temporal_cut_frequency", &cv::bioinspired::RetinaParameters::IplMagnoParameters::amacrinCellsTemporalCutFrequency).
    define_attr("v0_compression_parameter", &cv::bioinspired::RetinaParameters::IplMagnoParameters::V0CompressionParameter).
    define_attr("local_adaptintegration_tau", &cv::bioinspired::RetinaParameters::IplMagnoParameters::localAdaptintegration_tau).
    define_attr("local_adaptintegration_k", &cv::bioinspired::RetinaParameters::IplMagnoParameters::localAdaptintegration_k);

  Rice::Data_Type<cv::bioinspired::Retina> rb_cCvBioinspiredRetina = define_class_under<cv::bioinspired::Retina, cv::Algorithm>(rb_mCvBioinspired, "Retina").
    define_method<cv::Size(cv::bioinspired::Retina::*)()>("get_input_size", &cv::bioinspired::Retina::getInputSize).
    define_method<cv::Size(cv::bioinspired::Retina::*)()>("get_output_size", &cv::bioinspired::Retina::getOutputSize).
    define_method<void(cv::bioinspired::Retina::*)(cv::String, const bool)>("setup", &cv::bioinspired::Retina::setup,
      Arg("retina_parameter_file") = static_cast<cv::String>(""), Arg("apply_default_setup_on_failure") = static_cast<const bool>(true)).
    define_method<void(cv::bioinspired::Retina::*)(cv::FileStorage&, const bool)>("setup", &cv::bioinspired::Retina::setup,
      Arg("fs"), Arg("apply_default_setup_on_failure") = static_cast<const bool>(true)).
    define_method<void(cv::bioinspired::Retina::*)(cv::bioinspired::RetinaParameters)>("setup", &cv::bioinspired::Retina::setup,
      Arg("new_parameters")).
    define_method<cv::bioinspired::RetinaParameters(cv::bioinspired::Retina::*)()>("get_parameters", &cv::bioinspired::Retina::getParameters).
    define_method<cv::String(cv::bioinspired::Retina::*)()>("print_setup", &cv::bioinspired::Retina::printSetup).
    define_method<void(cv::bioinspired::Retina::*)(cv::String) const>("write", &cv::bioinspired::Retina::write,
      Arg("fs")).
    define_method<void(cv::bioinspired::Retina::*)(cv::FileStorage&) const>("write", &cv::bioinspired::Retina::write,
      Arg("fs")).
    define_method<void(cv::bioinspired::Retina::*)(const bool, const bool, const float, const float, const float, const float, const float, const float, const float)>("setup_op_land_ipl_parvo_channel", &cv::bioinspired::Retina::setupOPLandIPLParvoChannel,
      Arg("color_mode") = static_cast<const bool>(true), Arg("normalise_output") = static_cast<const bool>(true), Arg("photoreceptors_local_adaptation_sensitivity") = static_cast<const float>(0.7f), Arg("photoreceptors_temporal_constant") = static_cast<const float>(0.5f), Arg("photoreceptors_spatial_constant") = static_cast<const float>(0.53f), Arg("horizontal_cells_gain") = static_cast<const float>(0.f), Arg("hcells_temporal_constant") = static_cast<const float>(1.f), Arg("hcells_spatial_constant") = static_cast<const float>(7.f), Arg("ganglion_cells_sensitivity") = static_cast<const float>(0.7f)).
    define_method<void(cv::bioinspired::Retina::*)(const bool, const float, const float, const float, const float, const float, const float, const float)>("setup_ipl_magno_channel", &cv::bioinspired::Retina::setupIPLMagnoChannel,
      Arg("normalise_output") = static_cast<const bool>(true), Arg("parasol_cells_beta") = static_cast<const float>(0.f), Arg("parasol_cells_tau") = static_cast<const float>(0.f), Arg("parasol_cells_k") = static_cast<const float>(7.f), Arg("amacrin_cells_temporal_cut_frequency") = static_cast<const float>(1.2f), Arg("v0_compression_parameter") = static_cast<const float>(0.95f), Arg("local_adaptintegration_tau") = static_cast<const float>(0.f), Arg("local_adaptintegration_k") = static_cast<const float>(7.f)).
    define_method<void(cv::bioinspired::Retina::*)(cv::InputArray)>("run", &cv::bioinspired::Retina::run,
      Arg("input_image")).
    define_method<void(cv::bioinspired::Retina::*)(cv::InputArray, cv::OutputArray)>("apply_fast_tone_mapping", &cv::bioinspired::Retina::applyFastToneMapping,
      Arg("input_image"), Arg("output_tone_mapped_image")).
    define_method<void(cv::bioinspired::Retina::*)(cv::OutputArray)>("get_parvo", &cv::bioinspired::Retina::getParvo,
      Arg("retina_output_parvo")).
    define_method<void(cv::bioinspired::Retina::*)(cv::OutputArray)>("get_parvo_raw", &cv::bioinspired::Retina::getParvoRAW,
      Arg("retina_output_parvo")).
    define_method<void(cv::bioinspired::Retina::*)(cv::OutputArray)>("get_magno", &cv::bioinspired::Retina::getMagno,
      Arg("retina_output_magno")).
    define_method<void(cv::bioinspired::Retina::*)(cv::OutputArray)>("get_magno_raw", &cv::bioinspired::Retina::getMagnoRAW,
      Arg("retina_output_magno")).
    define_method<cv::Mat(cv::bioinspired::Retina::*)() const>("get_magno_raw", &cv::bioinspired::Retina::getMagnoRAW).
    define_method<cv::Mat(cv::bioinspired::Retina::*)() const>("get_parvo_raw", &cv::bioinspired::Retina::getParvoRAW).
    define_method<void(cv::bioinspired::Retina::*)(const bool, const float)>("set_color_saturation", &cv::bioinspired::Retina::setColorSaturation,
      Arg("saturate_colors") = static_cast<const bool>(true), Arg("color_saturation_value") = static_cast<const float>(4.0f)).
    define_method<void(cv::bioinspired::Retina::*)()>("clear_buffers", &cv::bioinspired::Retina::clearBuffers).
    define_method<void(cv::bioinspired::Retina::*)(const bool)>("activate_moving_contours_processing", &cv::bioinspired::Retina::activateMovingContoursProcessing,
      Arg("activate")).
    define_method<void(cv::bioinspired::Retina::*)(const bool)>("activate_contours_processing", &cv::bioinspired::Retina::activateContoursProcessing,
      Arg("activate")).
    define_singleton_function<cv::Ptr<cv::bioinspired::Retina>(*)(cv::Size)>("create", &cv::bioinspired::Retina::create,
      Arg("input_size")).
    define_singleton_function<cv::Ptr<cv::bioinspired::Retina>(*)(cv::Size, const bool, int, const bool, const float, const float)>("create", &cv::bioinspired::Retina::create,
      Arg("input_size"), Arg("color_mode"), Arg("color_sampling_method") = static_cast<int>(cv::bioinspired::RETINA_COLOR_BAYER), Arg("use_retina_log_sampling") = static_cast<const bool>(false), Arg("reduction_factor") = static_cast<const float>(1.0f), Arg("sampling_strength") = static_cast<const float>(10.0f));
}