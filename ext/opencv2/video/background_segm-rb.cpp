#include <opencv2/video/background_segm.hpp>
#include "background_segm-rb.hpp"

using namespace Rice;

void Init_Video_BackgroundSegm()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::BackgroundSubtractor> rb_cCvBackgroundSubtractor = define_class_under<cv::BackgroundSubtractor, cv::Algorithm>(rb_mCv, "BackgroundSubtractor").
    define_method<void(cv::BackgroundSubtractor::*)(cv::InputArray, cv::OutputArray, double)>("apply", &cv::BackgroundSubtractor::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate") = static_cast<double>(-1)).
    define_method<void(cv::BackgroundSubtractor::*)(cv::OutputArray) const>("get_background_image", &cv::BackgroundSubtractor::getBackgroundImage,
      Arg("background_image"));

  Rice::Data_Type<cv::BackgroundSubtractorMOG2> rb_cCvBackgroundSubtractorMOG2 = define_class_under<cv::BackgroundSubtractorMOG2, cv::BackgroundSubtractor>(rb_mCv, "BackgroundSubtractorMOG2").
    define_method<int(cv::BackgroundSubtractorMOG2::*)() const>("get_history", &cv::BackgroundSubtractorMOG2::getHistory).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(int)>("set_history", &cv::BackgroundSubtractorMOG2::setHistory,
      Arg("history")).
    define_method<int(cv::BackgroundSubtractorMOG2::*)() const>("get_n_mixtures", &cv::BackgroundSubtractorMOG2::getNMixtures).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(int)>("set_n_mixtures", &cv::BackgroundSubtractorMOG2::setNMixtures,
      Arg("nmixtures")).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_background_ratio", &cv::BackgroundSubtractorMOG2::getBackgroundRatio).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_background_ratio", &cv::BackgroundSubtractorMOG2::setBackgroundRatio,
      Arg("ratio")).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_threshold", &cv::BackgroundSubtractorMOG2::getVarThreshold).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_threshold", &cv::BackgroundSubtractorMOG2::setVarThreshold,
      Arg("var_threshold")).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_threshold_gen", &cv::BackgroundSubtractorMOG2::getVarThresholdGen).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_threshold_gen", &cv::BackgroundSubtractorMOG2::setVarThresholdGen,
      Arg("var_threshold_gen")).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_init", &cv::BackgroundSubtractorMOG2::getVarInit).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_init", &cv::BackgroundSubtractorMOG2::setVarInit,
      Arg("var_init")).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_min", &cv::BackgroundSubtractorMOG2::getVarMin).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_min", &cv::BackgroundSubtractorMOG2::setVarMin,
      Arg("var_min")).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_max", &cv::BackgroundSubtractorMOG2::getVarMax).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_max", &cv::BackgroundSubtractorMOG2::setVarMax,
      Arg("var_max")).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_complexity_reduction_threshold", &cv::BackgroundSubtractorMOG2::getComplexityReductionThreshold).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_complexity_reduction_threshold", &cv::BackgroundSubtractorMOG2::setComplexityReductionThreshold,
      Arg("ct")).
    define_method<bool(cv::BackgroundSubtractorMOG2::*)() const>("get_detect_shadows?", &cv::BackgroundSubtractorMOG2::getDetectShadows).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(bool)>("set_detect_shadows", &cv::BackgroundSubtractorMOG2::setDetectShadows,
      Arg("detect_shadows")).
    define_method<int(cv::BackgroundSubtractorMOG2::*)() const>("get_shadow_value", &cv::BackgroundSubtractorMOG2::getShadowValue).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(int)>("set_shadow_value", &cv::BackgroundSubtractorMOG2::setShadowValue,
      Arg("value")).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_shadow_threshold", &cv::BackgroundSubtractorMOG2::getShadowThreshold).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_shadow_threshold", &cv::BackgroundSubtractorMOG2::setShadowThreshold,
      Arg("threshold")).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(cv::InputArray, cv::OutputArray, double)>("apply", &cv::BackgroundSubtractorMOG2::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate") = static_cast<double>(-1));

  rb_mCv.define_module_function<cv::Ptr<cv::BackgroundSubtractorMOG2>(*)(int, double, bool)>("create_background_subtractor_mog2", &cv::createBackgroundSubtractorMOG2,
    Arg("history") = static_cast<int>(500), Arg("var_threshold") = static_cast<double>(16), Arg("detect_shadows") = static_cast<bool>(true));

  Rice::Data_Type<cv::BackgroundSubtractorKNN> rb_cCvBackgroundSubtractorKNN = define_class_under<cv::BackgroundSubtractorKNN, cv::BackgroundSubtractor>(rb_mCv, "BackgroundSubtractorKNN").
    define_method<int(cv::BackgroundSubtractorKNN::*)() const>("get_history", &cv::BackgroundSubtractorKNN::getHistory).
    define_method<void(cv::BackgroundSubtractorKNN::*)(int)>("set_history", &cv::BackgroundSubtractorKNN::setHistory,
      Arg("history")).
    define_method<int(cv::BackgroundSubtractorKNN::*)() const>("get_n_samples", &cv::BackgroundSubtractorKNN::getNSamples).
    define_method<void(cv::BackgroundSubtractorKNN::*)(int)>("set_n_samples", &cv::BackgroundSubtractorKNN::setNSamples,
      Arg("_n_n")).
    define_method<double(cv::BackgroundSubtractorKNN::*)() const>("get_dist2_threshold", &cv::BackgroundSubtractorKNN::getDist2Threshold).
    define_method<void(cv::BackgroundSubtractorKNN::*)(double)>("set_dist2_threshold", &cv::BackgroundSubtractorKNN::setDist2Threshold,
      Arg("_dist2_threshold")).
    define_method<int(cv::BackgroundSubtractorKNN::*)() const>("getk_nn_samples", &cv::BackgroundSubtractorKNN::getkNNSamples).
    define_method<void(cv::BackgroundSubtractorKNN::*)(int)>("setk_nn_samples", &cv::BackgroundSubtractorKNN::setkNNSamples,
      Arg("_nk_nn")).
    define_method<bool(cv::BackgroundSubtractorKNN::*)() const>("get_detect_shadows?", &cv::BackgroundSubtractorKNN::getDetectShadows).
    define_method<void(cv::BackgroundSubtractorKNN::*)(bool)>("set_detect_shadows", &cv::BackgroundSubtractorKNN::setDetectShadows,
      Arg("detect_shadows")).
    define_method<int(cv::BackgroundSubtractorKNN::*)() const>("get_shadow_value", &cv::BackgroundSubtractorKNN::getShadowValue).
    define_method<void(cv::BackgroundSubtractorKNN::*)(int)>("set_shadow_value", &cv::BackgroundSubtractorKNN::setShadowValue,
      Arg("value")).
    define_method<double(cv::BackgroundSubtractorKNN::*)() const>("get_shadow_threshold", &cv::BackgroundSubtractorKNN::getShadowThreshold).
    define_method<void(cv::BackgroundSubtractorKNN::*)(double)>("set_shadow_threshold", &cv::BackgroundSubtractorKNN::setShadowThreshold,
      Arg("threshold"));

  rb_mCv.define_module_function<cv::Ptr<cv::BackgroundSubtractorKNN>(*)(int, double, bool)>("create_background_subtractor_knn", &cv::createBackgroundSubtractorKNN,
    Arg("history") = static_cast<int>(500), Arg("dist2_threshold") = static_cast<double>(400.0), Arg("detect_shadows") = static_cast<bool>(true));
}
