#include <opencv2/video/detail/tracking.detail.hpp>
#include "tracking.detail-rb.hpp"

using namespace Rice;

void Init_Video_Detail_TrackingDetail()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");

  Rice::Data_Type<cv::detail::TrackerFeature> rb_cCvDetailTrackerFeature = define_class_under<cv::detail::TrackerFeature>(rb_mCvDetailTracking, "TrackerFeature").
    define_method<void(cv::detail::tracking::TrackerFeature::*)(const std::vector<cv::Mat>&, cv::Mat&)>("compute", &cv::detail::tracking::TrackerFeature::compute,
      Arg("images"), Arg("response"));

  Rice::Data_Type<cv::detail::TrackerFeatureSet> rb_cCvDetailTrackerFeatureSet = define_class_under<cv::detail::TrackerFeatureSet>(rb_mCvDetailTracking, "TrackerFeatureSet").
    define_constructor(Constructor<cv::detail::tracking::TrackerFeatureSet>()).
    define_method<void(cv::detail::tracking::TrackerFeatureSet::*)(const std::vector<cv::Mat>&)>("extraction", &cv::detail::tracking::TrackerFeatureSet::extraction,
      Arg("images")).
    define_method<bool(cv::detail::tracking::TrackerFeatureSet::*)(const cv::Ptr<cv::detail::TrackerFeature>&)>("add_tracker_feature", &cv::detail::tracking::TrackerFeatureSet::addTrackerFeature,
      Arg("feature")).
    define_method<const std::vector<cv::Ptr<cv::detail::TrackerFeature>>&(cv::detail::tracking::TrackerFeatureSet::*)() const>("get_tracker_features", &cv::detail::tracking::TrackerFeatureSet::getTrackerFeatures).
    define_method<const std::vector<cv::Mat>&(cv::detail::tracking::TrackerFeatureSet::*)() const>("get_responses", &cv::detail::tracking::TrackerFeatureSet::getResponses);

  Rice::Data_Type<cv::detail::TrackerSamplerAlgorithm> rb_cCvDetailTrackerSamplerAlgorithm = define_class_under<cv::detail::TrackerSamplerAlgorithm>(rb_mCvDetailTracking, "TrackerSamplerAlgorithm").
    define_method<bool(cv::detail::tracking::TrackerSamplerAlgorithm::*)(const cv::Mat&, const cv::Rect&, std::vector<cv::Mat>&)>("sampling", &cv::detail::tracking::TrackerSamplerAlgorithm::sampling,
      Arg("image"), Arg("bounding_box"), Arg("sample"));

  Rice::Data_Type<cv::detail::TrackerSampler> rb_cCvDetailTrackerSampler = define_class_under<cv::detail::TrackerSampler>(rb_mCvDetailTracking, "TrackerSampler").
    define_constructor(Constructor<cv::detail::tracking::TrackerSampler>()).
    define_method<void(cv::detail::tracking::TrackerSampler::*)(const cv::Mat&, cv::Rect)>("sampling", &cv::detail::tracking::TrackerSampler::sampling,
      Arg("image"), Arg("bounding_box")).
    define_method<const std::vector<cv::Ptr<cv::detail::TrackerSamplerAlgorithm>>&(cv::detail::tracking::TrackerSampler::*)() const>("get_samplers", &cv::detail::tracking::TrackerSampler::getSamplers).
    define_method<const std::vector<cv::Mat>&(cv::detail::tracking::TrackerSampler::*)() const>("get_samples", &cv::detail::tracking::TrackerSampler::getSamples).
    define_method<bool(cv::detail::tracking::TrackerSampler::*)(const cv::Ptr<cv::detail::TrackerSamplerAlgorithm>&)>("add_tracker_sampler_algorithm", &cv::detail::tracking::TrackerSampler::addTrackerSamplerAlgorithm,
      Arg("sampler"));

  Rice::Data_Type<cv::detail::TrackerTargetState> rb_cCvDetailTrackerTargetState = define_class_under<cv::detail::TrackerTargetState>(rb_mCvDetailTracking, "TrackerTargetState").
    define_constructor(Constructor<cv::detail::tracking::TrackerTargetState>()).
    define_method<cv::Point2f(cv::detail::tracking::TrackerTargetState::*)() const>("get_target_position", &cv::detail::tracking::TrackerTargetState::getTargetPosition).
    define_method<void(cv::detail::tracking::TrackerTargetState::*)(const cv::Point2f&)>("set_target_position", &cv::detail::tracking::TrackerTargetState::setTargetPosition,
      Arg("position")).
    define_method<int(cv::detail::tracking::TrackerTargetState::*)() const>("get_target_width", &cv::detail::tracking::TrackerTargetState::getTargetWidth).
    define_method<void(cv::detail::tracking::TrackerTargetState::*)(int)>("set_target_width", &cv::detail::tracking::TrackerTargetState::setTargetWidth,
      Arg("width")).
    define_method<int(cv::detail::tracking::TrackerTargetState::*)() const>("get_target_height", &cv::detail::tracking::TrackerTargetState::getTargetHeight).
    define_method<void(cv::detail::tracking::TrackerTargetState::*)(int)>("set_target_height", &cv::detail::tracking::TrackerTargetState::setTargetHeight,
      Arg("height"));

  Rice::Data_Type<cv::detail::TrackerStateEstimator> rb_cCvDetailTrackerStateEstimator = define_class_under<cv::detail::TrackerStateEstimator>(rb_mCvDetailTracking, "TrackerStateEstimator").
    define_method<cv::Ptr<cv::detail::TrackerTargetState>(cv::detail::tracking::TrackerStateEstimator::*)(const std::vector<std::vector<std::pair<cv::Ptr<cv::detail::TrackerTargetState>, float>>>&)>("estimate", &cv::detail::tracking::TrackerStateEstimator::estimate,
      Arg("confidence_maps")).
    define_method<void(cv::detail::tracking::TrackerStateEstimator::*)(std::vector<std::vector<std::pair<cv::Ptr<cv::detail::TrackerTargetState>, float>>>&)>("update", &cv::detail::tracking::TrackerStateEstimator::update,
      Arg("confidence_maps")).
    define_singleton_function<cv::Ptr<cv::detail::TrackerStateEstimator>(*)(const cv::String&)>("create", &cv::detail::tracking::TrackerStateEstimator::create,
      Arg("tracke_state_estimator_type")).
    define_method<cv::String(cv::detail::tracking::TrackerStateEstimator::*)() const>("get_class_name", &cv::detail::tracking::TrackerStateEstimator::getClassName);

  Rice::Data_Type<cv::detail::TrackerModel> rb_cCvDetailTrackerModel = define_class_under<cv::detail::TrackerModel>(rb_mCvDetailTracking, "TrackerModel").
    define_method<bool(cv::detail::tracking::TrackerModel::*)(cv::Ptr<cv::detail::TrackerStateEstimator>)>("set_tracker_state_estimator", &cv::detail::tracking::TrackerModel::setTrackerStateEstimator,
      Arg("tracker_state_estimator")).
    define_method<void(cv::detail::tracking::TrackerModel::*)(const std::vector<cv::Mat>&)>("model_estimation", &cv::detail::tracking::TrackerModel::modelEstimation,
      Arg("responses")).
    define_method<void(cv::detail::tracking::TrackerModel::*)()>("model_update", &cv::detail::tracking::TrackerModel::modelUpdate).
    define_method<bool(cv::detail::tracking::TrackerModel::*)()>("run_state_estimator?", &cv::detail::tracking::TrackerModel::runStateEstimator).
    define_method<void(cv::detail::tracking::TrackerModel::*)(const cv::Ptr<cv::detail::TrackerTargetState>&)>("set_last_target_state", &cv::detail::tracking::TrackerModel::setLastTargetState,
      Arg("last_target_state")).
    define_method<cv::Ptr<cv::detail::TrackerTargetState>(cv::detail::tracking::TrackerModel::*)() const>("get_last_target_state", &cv::detail::tracking::TrackerModel::getLastTargetState).
    define_method<const std::vector<std::vector<std::pair<cv::Ptr<cv::detail::TrackerTargetState>, float>>>&(cv::detail::tracking::TrackerModel::*)() const>("get_confidence_maps", &cv::detail::tracking::TrackerModel::getConfidenceMaps).
    define_method<const cv::detail::tracking::ConfidenceMap&(cv::detail::tracking::TrackerModel::*)() const>("get_last_confidence_map", &cv::detail::tracking::TrackerModel::getLastConfidenceMap).
    define_method<cv::Ptr<cv::detail::TrackerStateEstimator>(cv::detail::tracking::TrackerModel::*)() const>("get_tracker_state_estimator", &cv::detail::tracking::TrackerModel::getTrackerStateEstimator);

  Rice::Data_Type<cv::detail::TrackerSamplerCSC> rb_cCvDetailTrackerSamplerCSC = define_class_under<cv::detail::TrackerSamplerCSC, cv::detail::TrackerSamplerAlgorithm>(rb_mCvDetailTracking, "TrackerSamplerCSC").
    define_constructor(Constructor<cv::detail::tracking::TrackerSamplerCSC, const cv::detail::tracking::TrackerSamplerCSC::Params&>(),
      Arg("parameters") = static_cast<const cv::detail::tracking::TrackerSamplerCSC::Params&>(cv::detail::tracking::TrackerSamplerCSC::Params())).
    define_method<void(cv::detail::tracking::TrackerSamplerCSC::*)(int)>("set_mode", &cv::detail::tracking::TrackerSamplerCSC::setMode,
      Arg("sampling_mode")).
    define_method<bool(cv::detail::tracking::TrackerSamplerCSC::*)(const cv::Mat&, const cv::Rect&, std::vector<cv::Mat>&)>("sampling", &cv::detail::tracking::TrackerSamplerCSC::sampling,
      Arg("image"), Arg("bounding_box"), Arg("sample"));

  Rice::Data_Type<cv::detail::TrackerSamplerCSC::Params> rb_cCvDetailTrackerSamplerCSCParams = define_class_under<cv::detail::TrackerSamplerCSC::Params>(rb_cCvDetailTrackerSamplerCSC, "Params").
    define_constructor(Constructor<cv::detail::tracking::TrackerSamplerCSC::Params>()).
    define_attr("init_in_rad", &cv::detail::tracking::TrackerSamplerCSC::Params::initInRad).
    define_attr("track_in_pos_rad", &cv::detail::tracking::TrackerSamplerCSC::Params::trackInPosRad).
    define_attr("search_win_size", &cv::detail::tracking::TrackerSamplerCSC::Params::searchWinSize).
    define_attr("init_max_neg_num", &cv::detail::tracking::TrackerSamplerCSC::Params::initMaxNegNum).
    define_attr("track_max_pos_num", &cv::detail::tracking::TrackerSamplerCSC::Params::trackMaxPosNum).
    define_attr("track_max_neg_num", &cv::detail::tracking::TrackerSamplerCSC::Params::trackMaxNegNum);

  Enum<cv::detail::tracking::TrackerSamplerCSC::MODE> rb_cCvDetailTrackerSamplerCSCMODE = define_enum_under<cv::detail::tracking::TrackerSamplerCSC::MODE>("MODE", rb_cCvDetailTrackerSamplerCSC).
    define_value("MODE_INIT_POS", cv::detail::tracking::TrackerSamplerCSC::MODE::MODE_INIT_POS).
    define_value("MODE_INIT_NEG", cv::detail::tracking::TrackerSamplerCSC::MODE::MODE_INIT_NEG).
    define_value("MODE_TRACK_POS", cv::detail::tracking::TrackerSamplerCSC::MODE::MODE_TRACK_POS).
    define_value("MODE_TRACK_NEG", cv::detail::tracking::TrackerSamplerCSC::MODE::MODE_TRACK_NEG).
    define_value("MODE_DETECT", cv::detail::tracking::TrackerSamplerCSC::MODE::MODE_DETECT);
}