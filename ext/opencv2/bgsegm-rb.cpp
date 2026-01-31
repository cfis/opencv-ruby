#include <opencv2/bgsegm.hpp>
#include "bgsegm-rb.hpp"

using namespace Rice;

void Init_Bgsegm()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvBgsegm = define_module_under(rb_mCv, "Bgsegm");

  Rice::Data_Type<cv::bgsegm::BackgroundSubtractorMOG> rb_cCvBgsegmBackgroundSubtractorMOG = define_class_under<cv::bgsegm::BackgroundSubtractorMOG, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorMOG").
    define_method<int(cv::bgsegm::BackgroundSubtractorMOG::*)() const>("get_history", &cv::bgsegm::BackgroundSubtractorMOG::getHistory).
    define_method<void(cv::bgsegm::BackgroundSubtractorMOG::*)(int)>("set_history", &cv::bgsegm::BackgroundSubtractorMOG::setHistory,
      Arg("nframes")).
    define_method<int(cv::bgsegm::BackgroundSubtractorMOG::*)() const>("get_n_mixtures", &cv::bgsegm::BackgroundSubtractorMOG::getNMixtures).
    define_method<void(cv::bgsegm::BackgroundSubtractorMOG::*)(int)>("set_n_mixtures", &cv::bgsegm::BackgroundSubtractorMOG::setNMixtures,
      Arg("nmix")).
    define_method<double(cv::bgsegm::BackgroundSubtractorMOG::*)() const>("get_background_ratio", &cv::bgsegm::BackgroundSubtractorMOG::getBackgroundRatio).
    define_method<void(cv::bgsegm::BackgroundSubtractorMOG::*)(double)>("set_background_ratio", &cv::bgsegm::BackgroundSubtractorMOG::setBackgroundRatio,
      Arg("background_ratio")).
    define_method<double(cv::bgsegm::BackgroundSubtractorMOG::*)() const>("get_noise_sigma", &cv::bgsegm::BackgroundSubtractorMOG::getNoiseSigma).
    define_method<void(cv::bgsegm::BackgroundSubtractorMOG::*)(double)>("set_noise_sigma", &cv::bgsegm::BackgroundSubtractorMOG::setNoiseSigma,
      Arg("noise_sigma"));

  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorMOG>(*)(int, int, double, double)>("create_background_subtractor_mog", &cv::bgsegm::createBackgroundSubtractorMOG,
    Arg("history") = static_cast<int>(200), Arg("nmixtures") = static_cast<int>(5), Arg("background_ratio") = static_cast<double>(0.7), Arg("noise_sigma") = static_cast<double>(0));

  Rice::Data_Type<cv::bgsegm::BackgroundSubtractorGMG> rb_cCvBgsegmBackgroundSubtractorGMG = define_class_under<cv::bgsegm::BackgroundSubtractorGMG, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorGMG").
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(cv::InputArray, cv::OutputArray, double)>("apply", &cv::bgsegm::BackgroundSubtractorGMG::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate") = static_cast<double>(-1)).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(cv::OutputArray) const>("get_background_image", &cv::bgsegm::BackgroundSubtractorGMG::getBackgroundImage,
      Arg("background_image")).
    define_method<int(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_max_features", &cv::bgsegm::BackgroundSubtractorGMG::getMaxFeatures).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(int)>("set_max_features", &cv::bgsegm::BackgroundSubtractorGMG::setMaxFeatures,
      Arg("max_features")).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_default_learning_rate", &cv::bgsegm::BackgroundSubtractorGMG::getDefaultLearningRate).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_default_learning_rate", &cv::bgsegm::BackgroundSubtractorGMG::setDefaultLearningRate,
      Arg("lr")).
    define_method<int(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_num_frames", &cv::bgsegm::BackgroundSubtractorGMG::getNumFrames).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(int)>("set_num_frames", &cv::bgsegm::BackgroundSubtractorGMG::setNumFrames,
      Arg("nframes")).
    define_method<int(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_quantization_levels", &cv::bgsegm::BackgroundSubtractorGMG::getQuantizationLevels).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(int)>("set_quantization_levels", &cv::bgsegm::BackgroundSubtractorGMG::setQuantizationLevels,
      Arg("nlevels")).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_background_prior", &cv::bgsegm::BackgroundSubtractorGMG::getBackgroundPrior).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_background_prior", &cv::bgsegm::BackgroundSubtractorGMG::setBackgroundPrior,
      Arg("bgprior")).
    define_method<int(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_smoothing_radius", &cv::bgsegm::BackgroundSubtractorGMG::getSmoothingRadius).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(int)>("set_smoothing_radius", &cv::bgsegm::BackgroundSubtractorGMG::setSmoothingRadius,
      Arg("radius")).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_decision_threshold", &cv::bgsegm::BackgroundSubtractorGMG::getDecisionThreshold).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_decision_threshold", &cv::bgsegm::BackgroundSubtractorGMG::setDecisionThreshold,
      Arg("thresh")).
    define_method<bool(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_update_background_model?", &cv::bgsegm::BackgroundSubtractorGMG::getUpdateBackgroundModel).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(bool)>("set_update_background_model", &cv::bgsegm::BackgroundSubtractorGMG::setUpdateBackgroundModel,
      Arg("update")).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_min_val", &cv::bgsegm::BackgroundSubtractorGMG::getMinVal).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_min_val", &cv::bgsegm::BackgroundSubtractorGMG::setMinVal,
      Arg("val")).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_max_val", &cv::bgsegm::BackgroundSubtractorGMG::getMaxVal).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_max_val", &cv::bgsegm::BackgroundSubtractorGMG::setMaxVal,
      Arg("val"));

  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorGMG>(*)(int, double)>("create_background_subtractor_gmg", &cv::bgsegm::createBackgroundSubtractorGMG,
    Arg("initialization_frames") = static_cast<int>(120), Arg("decision_threshold") = static_cast<double>(0.8));

  Rice::Data_Type<cv::bgsegm::BackgroundSubtractorCNT> rb_cCvBgsegmBackgroundSubtractorCNT = define_class_under<cv::bgsegm::BackgroundSubtractorCNT, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorCNT").
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(cv::InputArray, cv::OutputArray, double)>("apply", &cv::bgsegm::BackgroundSubtractorCNT::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate") = static_cast<double>(-1)).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(cv::OutputArray) const>("get_background_image", &cv::bgsegm::BackgroundSubtractorCNT::getBackgroundImage,
      Arg("background_image")).
    define_method<int(cv::bgsegm::BackgroundSubtractorCNT::*)() const>("get_min_pixel_stability", &cv::bgsegm::BackgroundSubtractorCNT::getMinPixelStability).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(int)>("set_min_pixel_stability", &cv::bgsegm::BackgroundSubtractorCNT::setMinPixelStability,
      Arg("value")).
    define_method<int(cv::bgsegm::BackgroundSubtractorCNT::*)() const>("get_max_pixel_stability", &cv::bgsegm::BackgroundSubtractorCNT::getMaxPixelStability).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(int)>("set_max_pixel_stability", &cv::bgsegm::BackgroundSubtractorCNT::setMaxPixelStability,
      Arg("value")).
    define_method<bool(cv::bgsegm::BackgroundSubtractorCNT::*)() const>("get_use_history?", &cv::bgsegm::BackgroundSubtractorCNT::getUseHistory).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(bool)>("set_use_history", &cv::bgsegm::BackgroundSubtractorCNT::setUseHistory,
      Arg("value")).
    define_method<bool(cv::bgsegm::BackgroundSubtractorCNT::*)() const>("get_is_parallel?", &cv::bgsegm::BackgroundSubtractorCNT::getIsParallel).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(bool)>("set_is_parallel", &cv::bgsegm::BackgroundSubtractorCNT::setIsParallel,
      Arg("value"));

  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorCNT>(*)(int, bool, int, bool)>("create_background_subtractor_cnt", &cv::bgsegm::createBackgroundSubtractorCNT,
    Arg("min_pixel_stability") = static_cast<int>(15), Arg("use_history") = static_cast<bool>(true), Arg("max_pixel_stability"), Arg("is_parallel") = static_cast<bool>(true));

  Enum<cv::bgsegm::LSBPCameraMotionCompensation> rb_cCvBgsegmLSBPCameraMotionCompensation = define_enum_under<cv::bgsegm::LSBPCameraMotionCompensation>("LSBPCameraMotionCompensation", rb_mCvBgsegm).
    define_value("LSBP_CAMERA_MOTION_COMPENSATION_NONE", cv::bgsegm::LSBPCameraMotionCompensation::LSBP_CAMERA_MOTION_COMPENSATION_NONE).
    define_value("LSBP_CAMERA_MOTION_COMPENSATION_LK", cv::bgsegm::LSBPCameraMotionCompensation::LSBP_CAMERA_MOTION_COMPENSATION_LK);

  Rice::Data_Type<cv::bgsegm::BackgroundSubtractorGSOC> rb_cCvBgsegmBackgroundSubtractorGSOC = define_class_under<cv::bgsegm::BackgroundSubtractorGSOC, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorGSOC").
    define_method<void(cv::bgsegm::BackgroundSubtractorGSOC::*)(cv::InputArray, cv::OutputArray, double)>("apply", &cv::bgsegm::BackgroundSubtractorGSOC::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate") = static_cast<double>(-1)).
    define_method<void(cv::bgsegm::BackgroundSubtractorGSOC::*)(cv::OutputArray) const>("get_background_image", &cv::bgsegm::BackgroundSubtractorGSOC::getBackgroundImage,
      Arg("background_image"));

  Rice::Data_Type<cv::bgsegm::BackgroundSubtractorLSBP> rb_cCvBgsegmBackgroundSubtractorLSBP = define_class_under<cv::bgsegm::BackgroundSubtractorLSBP, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorLSBP").
    define_method<void(cv::bgsegm::BackgroundSubtractorLSBP::*)(cv::InputArray, cv::OutputArray, double)>("apply", &cv::bgsegm::BackgroundSubtractorLSBP::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate") = static_cast<double>(-1)).
    define_method<void(cv::bgsegm::BackgroundSubtractorLSBP::*)(cv::OutputArray) const>("get_background_image", &cv::bgsegm::BackgroundSubtractorLSBP::getBackgroundImage,
      Arg("background_image"));

  Rice::Data_Type<cv::bgsegm::BackgroundSubtractorLSBPDesc> rb_cCvBgsegmBackgroundSubtractorLSBPDesc = define_class_under<cv::bgsegm::BackgroundSubtractorLSBPDesc>(rb_mCvBgsegm, "BackgroundSubtractorLSBPDesc").
    define_constructor(Constructor<cv::bgsegm::BackgroundSubtractorLSBPDesc>()).
    define_singleton_function<void(*)(cv::OutputArray, const cv::Mat&)>("calc_local_svd_values", &cv::bgsegm::BackgroundSubtractorLSBPDesc::calcLocalSVDValues,
      Arg("local_svd_values"), Arg("frame")).
    define_singleton_function<void(*)(cv::OutputArray, const cv::Mat&, const cv::Point2i*)>("compute_from_local_svd_values", &cv::bgsegm::BackgroundSubtractorLSBPDesc::computeFromLocalSVDValues,
      Arg("desc"), Arg("local_svd_values"), Arg("lsbp_sample_points")).
    define_singleton_function<void(*)(cv::OutputArray, const cv::Mat&, const cv::Point2i*)>("compute", &cv::bgsegm::BackgroundSubtractorLSBPDesc::compute,
      Arg("desc"), Arg("frame"), Arg("lsbp_sample_points"));

  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorGSOC>(*)(int, int, float, float, int, float, float, float, float, float, float)>("create_background_subtractor_gsoc", &cv::bgsegm::createBackgroundSubtractorGSOC,
    Arg("mc") = static_cast<int>(cv::bgsegm::LSBP_CAMERA_MOTION_COMPENSATION_NONE), Arg("n_samples") = static_cast<int>(20), Arg("replace_rate") = static_cast<float>(0.003f), Arg("propagation_rate") = static_cast<float>(0.01f), Arg("hits_threshold") = static_cast<int>(32), Arg("alpha") = static_cast<float>(0.01f), Arg("beta") = static_cast<float>(0.0022f), Arg("blinking_supression_decay") = static_cast<float>(0.1f), Arg("blinking_supression_multiplier") = static_cast<float>(0.1f), Arg("noise_removal_threshold_fac_bg") = static_cast<float>(0.0004f), Arg("noise_removal_threshold_fac_fg") = static_cast<float>(0.0008f));

  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorLSBP>(*)(int, int, int, float, float, float, float, float, float, float, float, int, int)>("create_background_subtractor_lsbp", &cv::bgsegm::createBackgroundSubtractorLSBP,
    Arg("mc") = static_cast<int>(cv::bgsegm::LSBP_CAMERA_MOTION_COMPENSATION_NONE), Arg("n_samples") = static_cast<int>(20), Arg("lsbp_radius") = static_cast<int>(16), Arg("tlower") = static_cast<float>(2.0f), Arg("tupper") = static_cast<float>(32.0f), Arg("tinc") = static_cast<float>(1.0f), Arg("tdec") = static_cast<float>(0.05f), Arg("rscale") = static_cast<float>(10.0f), Arg("rincdec") = static_cast<float>(0.005f), Arg("noise_removal_threshold_fac_bg") = static_cast<float>(0.0004f), Arg("noise_removal_threshold_fac_fg") = static_cast<float>(0.0008f), Arg("lsb_pthreshold") = static_cast<int>(8), Arg("min_count") = static_cast<int>(2));

  Rice::Data_Type<cv::bgsegm::SyntheticSequenceGenerator> rb_cCvBgsegmSyntheticSequenceGenerator = define_class_under<cv::bgsegm::SyntheticSequenceGenerator, cv::Algorithm>(rb_mCvBgsegm, "SyntheticSequenceGenerator").
    define_constructor(Constructor<cv::bgsegm::SyntheticSequenceGenerator, cv::InputArray, cv::InputArray, double, double, double, double>(),
      Arg("background"), Arg("object"), Arg("amplitude"), Arg("wavelength"), Arg("wavespeed"), Arg("objspeed")).
    define_method<void(cv::bgsegm::SyntheticSequenceGenerator::*)(cv::OutputArray, cv::OutputArray)>("get_next_frame", &cv::bgsegm::SyntheticSequenceGenerator::getNextFrame,
      Arg("frame"), Arg("gt_mask"));

  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::SyntheticSequenceGenerator>(*)(cv::InputArray, cv::InputArray, double, double, double, double)>("create_synthetic_sequence_generator", &cv::bgsegm::createSyntheticSequenceGenerator,
    Arg("background"), Arg("object"), Arg("amplitude") = static_cast<double>(2.0), Arg("wavelength") = static_cast<double>(20.0), Arg("wavespeed") = static_cast<double>(0.2), Arg("objspeed") = static_cast<double>(6.0));
}