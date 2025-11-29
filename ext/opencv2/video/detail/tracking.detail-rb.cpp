#include <opencv2/video/detail/tracking.detail.hpp>
#include "../../core/cvstd_wrapper-rb.hpp"
#include "tracking.detail-rb.hpp"

using namespace Rice;

Rice::Class rb_cConfidenceMap;
Rice::Class rb_cCvDetailTrackerFeature;
Rice::Class rb_cCvDetailTrackerFeatureSet;
Rice::Class rb_cCvDetailTrackerModel;
Rice::Class rb_cCvDetailTrackerSampler;
Rice::Class rb_cCvDetailTrackerSamplerAlgorithm;
Rice::Class rb_cCvDetailTrackerSamplerCSC;
Rice::Class rb_cCvDetailTrackerSamplerCSCParams;
Rice::Class rb_cCvDetailTrackerStateEstimator;
Rice::Class rb_cCvDetailTrackerTargetState;
Rice::Class rb_cTrajectory;

void Init_TrackingDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");
  
  rb_cCvDetailTrackerFeature = define_class_under<cv::detail::TrackerFeature>(rb_mCvDetailTracking, "TrackerFeature").
    define_method("compute", &cv::detail::tracking::TrackerFeature::compute,
      Arg("images"), Arg("response"));
  
  rb_cCvDetailTrackerFeatureSet = define_class_under<cv::detail::TrackerFeatureSet>(rb_mCvDetailTracking, "TrackerFeatureSet").
    define_constructor(Constructor<cv::detail::tracking::TrackerFeatureSet>()).
    define_method("extraction", &cv::detail::tracking::TrackerFeatureSet::extraction,
      Arg("images")).
    define_method("add_tracker_feature?", &cv::detail::tracking::TrackerFeatureSet::addTrackerFeature,
      Arg("feature")).
    define_method("get_tracker_features", &cv::detail::tracking::TrackerFeatureSet::getTrackerFeatures).
    define_method("get_responses", &cv::detail::tracking::TrackerFeatureSet::getResponses);
  
  rb_cCvDetailTrackerSamplerAlgorithm = define_class_under<cv::detail::TrackerSamplerAlgorithm>(rb_mCvDetailTracking, "TrackerSamplerAlgorithm").
    define_method("sampling?", &cv::detail::tracking::TrackerSamplerAlgorithm::sampling,
      Arg("image"), Arg("bounding_box"), Arg("sample"));
  
  rb_cCvDetailTrackerSampler = define_class_under<cv::detail::TrackerSampler>(rb_mCvDetailTracking, "TrackerSampler").
    define_constructor(Constructor<cv::detail::tracking::TrackerSampler>()).
    define_method("sampling", &cv::detail::tracking::TrackerSampler::sampling,
      Arg("image"), Arg("bounding_box")).
    define_method("get_samplers", &cv::detail::tracking::TrackerSampler::getSamplers).
    define_method("get_samples", &cv::detail::tracking::TrackerSampler::getSamples).
    define_method("add_tracker_sampler_algorithm?", &cv::detail::tracking::TrackerSampler::addTrackerSamplerAlgorithm,
      Arg("sampler"));
  
  rb_cCvDetailTrackerTargetState = define_class_under<cv::detail::TrackerTargetState>(rb_mCvDetailTracking, "TrackerTargetState").
    define_constructor(Constructor<cv::detail::TrackerTargetState>()).
    define_method("get_target_position", &cv::detail::tracking::TrackerTargetState::getTargetPosition).
    define_method("set_target_position", &cv::detail::tracking::TrackerTargetState::setTargetPosition,
      Arg("position")).
    define_method("get_target_width", &cv::detail::tracking::TrackerTargetState::getTargetWidth).
    define_method("set_target_width", &cv::detail::tracking::TrackerTargetState::setTargetWidth,
      Arg("width")).
    define_method("get_target_height", &cv::detail::tracking::TrackerTargetState::getTargetHeight).
    define_method("set_target_height", &cv::detail::tracking::TrackerTargetState::setTargetHeight,
      Arg("height"));

  //define_vector_under(rb_mCvDetailTracking, "ConfidenceMap", std::vector<std::pair<cv::Ptr<cv::detail::tracking::TrackerTargetState>, float>>);
  //define_vector_under(rb_mCvDetailTracking, "Trajectory", std::vector<cv::Ptr<cv::detail::tracking::TrackerTargetState>>);

  rb_cCvDetailTrackerStateEstimator = define_class_under<cv::detail::TrackerStateEstimator>(rb_mCvDetailTracking, "TrackerStateEstimator").
    define_method("estimate", &cv::detail::tracking::TrackerStateEstimator::estimate,
      Arg("confidence_maps")).
    define_method("update", &cv::detail::tracking::TrackerStateEstimator::update,
      Arg("confidence_maps")).
    //define_singleton_function("create", &cv::detail::tracking::TrackerStateEstimator::create,
    //  Arg("tracke_state_estimator_type")).
    define_method("get_class_name", &cv::detail::tracking::TrackerStateEstimator::getClassName);
  
  rb_cCvDetailTrackerModel = define_class_under<cv::detail::TrackerModel>(rb_mCvDetailTracking, "TrackerModel").
    define_method("set_tracker_state_estimator?", &cv::detail::tracking::TrackerModel::setTrackerStateEstimator,
      Arg("tracker_state_estimator")).
    define_method("model_estimation", &cv::detail::tracking::TrackerModel::modelEstimation,
      Arg("responses")).
    define_method("model_update", &cv::detail::tracking::TrackerModel::modelUpdate).
    define_method("run_state_estimator?", &cv::detail::tracking::TrackerModel::runStateEstimator).
    define_method("set_last_target_state", &cv::detail::tracking::TrackerModel::setLastTargetState,
      Arg("last_target_state")).
    define_method("get_last_target_state", &cv::detail::tracking::TrackerModel::getLastTargetState).
    define_method("get_confidence_maps", &cv::detail::tracking::TrackerModel::getConfidenceMaps).
    define_method("get_last_confidence_map", &cv::detail::tracking::TrackerModel::getLastConfidenceMap).
    define_method("get_tracker_state_estimator", &cv::detail::tracking::TrackerModel::getTrackerStateEstimator);
  
  rb_cCvDetailTrackerSamplerCSC = define_class_under<cv::detail::TrackerSamplerCSC, cv::detail::TrackerSamplerAlgorithm>(rb_mCvDetailTracking, "TrackerSamplerCSC").
    define_constructor(Constructor<cv::detail::TrackerSamplerCSC, const cv::detail::tracking::TrackerSamplerCSC::Params&>(),
      Arg("parameters") = static_cast<const cv::detail::tracking::TrackerSamplerCSC::Params &>(cv::detail::tracking::TrackerSamplerCSC::Params())).
    define_method("set_mode", &cv::detail::tracking::TrackerSamplerCSC::setMode,
      Arg("sampling_mode")).
    define_method("sampling?", &cv::detail::tracking::TrackerSamplerCSC::sampling,
      Arg("image"), Arg("bounding_box"), Arg("sample"));
  
  rb_cCvDetailTrackerSamplerCSCParams = define_class_under<cv::detail::TrackerSamplerCSC::Params>(rb_cCvDetailTrackerSamplerCSC, "Params").
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