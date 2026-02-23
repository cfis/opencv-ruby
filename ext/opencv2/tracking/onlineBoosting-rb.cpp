#include <opencv2/tracking/onlineBoosting.hpp>
#include "onlineBoosting-rb.hpp"

using namespace Rice;

void Init_Tracking_OnlineBoosting()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");

  Module rb_mCvDetailTrackingOnlineBoosting = define_module_under(rb_mCvDetailTracking, "OnlineBoosting");

  Rice::Data_Type<cv::detail::StrongClassifierDirectSelection> rb_cCvDetailStrongClassifierDirectSelection = define_class_under<cv::detail::StrongClassifierDirectSelection>(rb_mCvDetailTrackingOnlineBoosting, "StrongClassifierDirectSelection").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::StrongClassifierDirectSelection, int, int, cv::Size, const cv::Rect&, bool, int>(),
      Arg("num_base_clf"), Arg("num_weak_clf"), Arg("patch_sz"), Arg("sample_roi"), Arg("use_feature_ex") = static_cast<bool>(false), Arg("iteration_init") = static_cast<int>(0)).
    define_method<void(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)()>("init_base_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::initBaseClassifier).
    define_method<bool(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)(const cv::Mat&, int, float)>("update", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::update,
      Arg("image"), Arg("target"), Arg("importance") = static_cast<float>(1.0)).
    define_method<float(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)(const cv::Mat&)>("eval", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::eval,
      Arg("response")).
    define_method<std::vector<int>(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)()>("get_selected_weak_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getSelectedWeakClassifier).
    define_method<float(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)(const std::vector<cv::Mat>&, const cv::Rect&, int&)>("classify_smooth", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::classifySmooth,
      Arg("images"), Arg("sample_roi"), Arg("idx")).
    define_method<int(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)()>("get_num_base_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getNumBaseClassifier).
    define_method<cv::Size(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_patch_size", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getPatchSize).
    define_method<cv::Rect(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_roi", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getROI).
    define_method<bool(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_use_feature_exchange?", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getUseFeatureExchange).
    define_method<int(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_replaced_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getReplacedClassifier).
    define_method<void(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)(int)>("replace_weak_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::replaceWeakClassifier,
      Arg("idx")).
    define_method<int(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_swapped_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getSwappedClassifier);

  Rice::Data_Type<cv::detail::BaseClassifier> rb_cCvDetailBaseClassifier = define_class_under<cv::detail::BaseClassifier>(rb_mCvDetailTrackingOnlineBoosting, "BaseClassifier").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::BaseClassifier, int, int>(),
      Arg("num_weak_classifier"), Arg("iteration_init")).
    define_constructor(Constructor<cv::detail::tracking::online_boosting::BaseClassifier, int, int, cv::detail::tracking::online_boosting::WeakClassifierHaarFeature**>(),
      Arg("num_weak_classifier"), Arg("iteration_init"), ArgBuffer("weak_cls")).
    define_method<cv::detail::tracking::online_boosting::WeakClassifierHaarFeature**(cv::detail::tracking::online_boosting::BaseClassifier::*)()>("get_reference_weak_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::getReferenceWeakClassifier,
      ReturnBuffer()).
    define_method<void(cv::detail::tracking::online_boosting::BaseClassifier::*)(const cv::Mat&, int, float, std::vector<bool>&)>("train_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::trainClassifier,
      Arg("image"), Arg("target"), Arg("importance"), Arg("error_mask")).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)(std::vector<bool>&, float, std::vector<float>&)>("select_best_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::selectBestClassifier,
      Arg("error_mask"), Arg("importance"), Arg("errors")).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)(const std::vector<float>&)>("compute_replace_weakest_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::computeReplaceWeakestClassifier,
      Arg("errors")).
    define_method<void(cv::detail::tracking::online_boosting::BaseClassifier::*)(int, int)>("replace_classifier_statistic", &cv::detail::tracking::online_boosting::BaseClassifier::replaceClassifierStatistic,
      Arg("source_index"), Arg("target_index")).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)()>("get_idx_of_new_weak_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::getIdxOfNewWeakClassifier).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)(const cv::Mat&)>("eval", &cv::detail::tracking::online_boosting::BaseClassifier::eval,
      Arg("image")).
    define_method<float(cv::detail::tracking::online_boosting::BaseClassifier::*)(int)>("get_error", &cv::detail::tracking::online_boosting::BaseClassifier::getError,
      Arg("cur_weak_classifier")).
    define_method<void(cv::detail::tracking::online_boosting::BaseClassifier::*)(float*)>("get_errors", &cv::detail::tracking::online_boosting::BaseClassifier::getErrors,
      ArgBuffer("errors")).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)() const>("get_selected_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::getSelectedClassifier).
    define_method<void(cv::detail::tracking::online_boosting::BaseClassifier::*)(int)>("replace_weak_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::replaceWeakClassifier,
      Arg("index"));

  Rice::Data_Type<cv::detail::EstimatedGaussDistribution> rb_cCvDetailEstimatedGaussDistribution = define_class_under<cv::detail::EstimatedGaussDistribution>(rb_mCvDetailTrackingOnlineBoosting, "EstimatedGaussDistribution").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::EstimatedGaussDistribution>()).
    define_constructor(Constructor<cv::detail::tracking::online_boosting::EstimatedGaussDistribution, float, float, float, float>(),
      Arg("p_mean"), Arg("r_mean"), Arg("p_sigma"), Arg("r_sigma")).
    define_method<void(cv::detail::tracking::online_boosting::EstimatedGaussDistribution::*)(float)>("update", &cv::detail::tracking::online_boosting::EstimatedGaussDistribution::update,
      Arg("value")).
    define_method<float(cv::detail::tracking::online_boosting::EstimatedGaussDistribution::*)()>("get_mean", &cv::detail::tracking::online_boosting::EstimatedGaussDistribution::getMean).
    define_method<float(cv::detail::tracking::online_boosting::EstimatedGaussDistribution::*)()>("get_sigma", &cv::detail::tracking::online_boosting::EstimatedGaussDistribution::getSigma).
    define_method<void(cv::detail::tracking::online_boosting::EstimatedGaussDistribution::*)(float, float)>("set_values", &cv::detail::tracking::online_boosting::EstimatedGaussDistribution::setValues,
      Arg("mean"), Arg("sigma"));

  Rice::Data_Type<cv::detail::WeakClassifierHaarFeature> rb_cCvDetailWeakClassifierHaarFeature = define_class_under<cv::detail::WeakClassifierHaarFeature>(rb_mCvDetailTrackingOnlineBoosting, "WeakClassifierHaarFeature").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::WeakClassifierHaarFeature>()).
    define_method<bool(cv::detail::tracking::online_boosting::WeakClassifierHaarFeature::*)(float, int)>("update", &cv::detail::tracking::online_boosting::WeakClassifierHaarFeature::update,
      Arg("value"), Arg("target")).
    define_method<int(cv::detail::tracking::online_boosting::WeakClassifierHaarFeature::*)(float)>("eval", &cv::detail::tracking::online_boosting::WeakClassifierHaarFeature::eval,
      Arg("value"));

  Rice::Data_Type<cv::detail::Detector> rb_cCvDetailDetector = define_class_under<cv::detail::Detector>(rb_mCvDetailTrackingOnlineBoosting, "Detector").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::Detector, cv::detail::tracking::online_boosting::StrongClassifierDirectSelection*>(),
      Arg("classifier")).
    define_method<void(cv::detail::tracking::online_boosting::Detector::*)(const std::vector<cv::Mat>&, float)>("classify_smooth", &cv::detail::tracking::online_boosting::Detector::classifySmooth,
      Arg("image"), Arg("min_margin") = static_cast<float>(0)).
    define_method<int(cv::detail::tracking::online_boosting::Detector::*)()>("get_num_detections", &cv::detail::tracking::online_boosting::Detector::getNumDetections).
    define_method<float(cv::detail::tracking::online_boosting::Detector::*)(int)>("get_confidence", &cv::detail::tracking::online_boosting::Detector::getConfidence,
      Arg("patch_idx")).
    define_method<float(cv::detail::tracking::online_boosting::Detector::*)(int)>("get_confidence_of_detection", &cv::detail::tracking::online_boosting::Detector::getConfidenceOfDetection,
      Arg("detection_idx")).
    define_method<float(cv::detail::tracking::online_boosting::Detector::*)()>("get_confidence_of_best_detection", &cv::detail::tracking::online_boosting::Detector::getConfidenceOfBestDetection).
    define_method<int(cv::detail::tracking::online_boosting::Detector::*)()>("get_patch_idx_of_best_detection", &cv::detail::tracking::online_boosting::Detector::getPatchIdxOfBestDetection).
    define_method<int(cv::detail::tracking::online_boosting::Detector::*)(int)>("get_patch_idx_of_detection", &cv::detail::tracking::online_boosting::Detector::getPatchIdxOfDetection,
      Arg("detection_idx")).
    define_method<const std::vector<int>&(cv::detail::tracking::online_boosting::Detector::*)() const>("get_idx_detections", &cv::detail::tracking::online_boosting::Detector::getIdxDetections).
    define_method<const std::vector<float>&(cv::detail::tracking::online_boosting::Detector::*)() const>("get_confidences", &cv::detail::tracking::online_boosting::Detector::getConfidences).
    define_method<const cv::Mat&(cv::detail::tracking::online_boosting::Detector::*)() const>("get_conf_image_display", &cv::detail::tracking::online_boosting::Detector::getConfImageDisplay);

  Rice::Data_Type<cv::detail::ClassifierThreshold> rb_cCvDetailClassifierThreshold = define_class_under<cv::detail::ClassifierThreshold>(rb_mCvDetailTrackingOnlineBoosting, "ClassifierThreshold").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::ClassifierThreshold, cv::detail::tracking::online_boosting::EstimatedGaussDistribution*, cv::detail::tracking::online_boosting::EstimatedGaussDistribution*>(),
      Arg("pos_samples"), Arg("neg_samples")).
    define_method<void(cv::detail::tracking::online_boosting::ClassifierThreshold::*)(float, int)>("update", &cv::detail::tracking::online_boosting::ClassifierThreshold::update,
      Arg("value"), Arg("target")).
    define_method<int(cv::detail::tracking::online_boosting::ClassifierThreshold::*)(float)>("eval", &cv::detail::tracking::online_boosting::ClassifierThreshold::eval,
      Arg("value")).
    define_method<void*(cv::detail::tracking::online_boosting::ClassifierThreshold::*)(int)>("get_distribution", &cv::detail::tracking::online_boosting::ClassifierThreshold::getDistribution,
      Arg("target"), ReturnBuffer());
}
