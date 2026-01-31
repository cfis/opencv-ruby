#include <opencv2/tracking/tracking_legacy.hpp>
#include "tracking_legacy-rb.hpp"

using namespace Rice;

void Init_Tracking_TrackingLegacy()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvLegacy = define_module_under(rb_mCv, "Legacy");

  Module rb_mCvLegacyTracking = define_module_under(rb_mCvLegacy, "Tracking");

  Rice::Data_Type<cv::legacy::Tracker> rb_cCvLegacyTracker = define_class_under<cv::legacy::Tracker, cv::Algorithm>(rb_mCvLegacyTracking, "Tracker").
    define_method<bool(cv::legacy::tracking::Tracker::*)(cv::InputArray, const cv::Rect2d&)>("init", &cv::legacy::tracking::Tracker::init,
      Arg("image"), Arg("bounding_box")).
    define_method<bool(cv::legacy::tracking::Tracker::*)(cv::InputArray, cv::Rect2d&)>("update", &cv::legacy::tracking::Tracker::update,
      Arg("image"), Arg("bounding_box")).
    define_method<void(cv::legacy::tracking::Tracker::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::Tracker::read,
      Arg("fn")).
    define_method<void(cv::legacy::tracking::Tracker::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::Tracker::write,
      Arg("fs"));

  Rice::Data_Type<cv::legacy::TrackerMIL> rb_cCvLegacyTrackerMIL = define_class_under<cv::legacy::TrackerMIL, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerMIL").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMIL>(*)(const cv::legacy::tracking::TrackerMIL::Params&)>("create", &cv::legacy::tracking::TrackerMIL::create,
      Arg("parameters")).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMIL>(*)()>("create", &cv::legacy::tracking::TrackerMIL::create);

  Rice::Data_Type<cv::legacy::TrackerMIL::Params> rb_cCvLegacyTrackerMILParams = define_class_under<cv::legacy::TrackerMIL::Params, cv::TrackerMIL::Params>(rb_cCvLegacyTrackerMIL, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerMIL::Params>()).
    define_method<void(cv::legacy::tracking::TrackerMIL::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerMIL::Params::read,
      Arg("fn")).
    define_method<void(cv::legacy::tracking::TrackerMIL::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerMIL::Params::write,
      Arg("fs"));

  Rice::Data_Type<cv::legacy::TrackerBoosting> rb_cCvLegacyTrackerBoosting = define_class_under<cv::legacy::TrackerBoosting, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerBoosting").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerBoosting>(*)(const cv::legacy::tracking::TrackerBoosting::Params&)>("create", &cv::legacy::tracking::TrackerBoosting::create,
      Arg("parameters")).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerBoosting>(*)()>("create", &cv::legacy::tracking::TrackerBoosting::create);

  Rice::Data_Type<cv::legacy::TrackerBoosting::Params> rb_cCvLegacyTrackerBoostingParams = define_class_under<cv::legacy::TrackerBoosting::Params>(rb_cCvLegacyTrackerBoosting, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerBoosting::Params>()).
    define_attr("num_classifiers", &cv::legacy::tracking::TrackerBoosting::Params::numClassifiers).
    define_attr("sampler_overlap", &cv::legacy::tracking::TrackerBoosting::Params::samplerOverlap).
    define_attr("sampler_search_factor", &cv::legacy::tracking::TrackerBoosting::Params::samplerSearchFactor).
    define_attr("iteration_init", &cv::legacy::tracking::TrackerBoosting::Params::iterationInit).
    define_attr("feature_set_num_features", &cv::legacy::tracking::TrackerBoosting::Params::featureSetNumFeatures).
    define_method<void(cv::legacy::tracking::TrackerBoosting::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerBoosting::Params::read,
      Arg("fn")).
    define_method<void(cv::legacy::tracking::TrackerBoosting::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerBoosting::Params::write,
      Arg("fs"));

  Rice::Data_Type<cv::legacy::TrackerMedianFlow> rb_cCvLegacyTrackerMedianFlow = define_class_under<cv::legacy::TrackerMedianFlow, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerMedianFlow").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMedianFlow>(*)(const cv::legacy::tracking::TrackerMedianFlow::Params&)>("create", &cv::legacy::tracking::TrackerMedianFlow::create,
      Arg("parameters")).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMedianFlow>(*)()>("create", &cv::legacy::tracking::TrackerMedianFlow::create);

  Rice::Data_Type<cv::legacy::TrackerMedianFlow::Params> rb_cCvLegacyTrackerMedianFlowParams = define_class_under<cv::legacy::TrackerMedianFlow::Params>(rb_cCvLegacyTrackerMedianFlow, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerMedianFlow::Params>()).
    define_attr("points_in_grid", &cv::legacy::tracking::TrackerMedianFlow::Params::pointsInGrid).
    define_attr("win_size", &cv::legacy::tracking::TrackerMedianFlow::Params::winSize).
    define_attr("max_level", &cv::legacy::tracking::TrackerMedianFlow::Params::maxLevel).
    define_attr("term_criteria", &cv::legacy::tracking::TrackerMedianFlow::Params::termCriteria).
    define_attr("win_size_ncc", &cv::legacy::tracking::TrackerMedianFlow::Params::winSizeNCC).
    define_attr("max_median_length_of_displacement_difference", &cv::legacy::tracking::TrackerMedianFlow::Params::maxMedianLengthOfDisplacementDifference).
    define_method<void(cv::legacy::tracking::TrackerMedianFlow::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerMedianFlow::Params::read,
      Arg("arg_0")).
    define_method<void(cv::legacy::tracking::TrackerMedianFlow::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerMedianFlow::Params::write,
      Arg("arg_0"));

  Rice::Data_Type<cv::legacy::TrackerTLD> rb_cCvLegacyTrackerTLD = define_class_under<cv::legacy::TrackerTLD, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerTLD").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerTLD>(*)(const cv::legacy::tracking::TrackerTLD::Params&)>("create", &cv::legacy::tracking::TrackerTLD::create,
      Arg("parameters")).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerTLD>(*)()>("create", &cv::legacy::tracking::TrackerTLD::create);

  Rice::Data_Type<cv::legacy::TrackerTLD::Params> rb_cCvLegacyTrackerTLDParams = define_class_under<cv::legacy::TrackerTLD::Params>(rb_cCvLegacyTrackerTLD, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerTLD::Params>()).
    define_method<void(cv::legacy::tracking::TrackerTLD::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerTLD::Params::read,
      Arg("arg_0")).
    define_method<void(cv::legacy::tracking::TrackerTLD::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerTLD::Params::write,
      Arg("arg_0"));

  Rice::Data_Type<cv::legacy::TrackerKCF> rb_cCvLegacyTrackerKCF = define_class_under<cv::legacy::TrackerKCF, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerKCF").
    define_method<void(cv::legacy::tracking::TrackerKCF::*)(void (*)(const cv::Mat, const cv::Rect, cv::Mat&), bool)>("set_feature_extractor", &cv::legacy::tracking::TrackerKCF::setFeatureExtractor,
      Arg("arg_0"), Arg("pca_func") = static_cast<bool>(false)).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerKCF>(*)(const cv::legacy::tracking::TrackerKCF::Params&)>("create", &cv::legacy::tracking::TrackerKCF::create,
      Arg("parameters")).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerKCF>(*)()>("create", &cv::legacy::tracking::TrackerKCF::create);

  Rice::Data_Type<cv::legacy::TrackerKCF::Params> rb_cCvLegacyTrackerKCFParams = define_class_under<cv::legacy::TrackerKCF::Params>(rb_cCvLegacyTrackerKCF, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerKCF::Params>()).
    define_method<void(cv::legacy::tracking::TrackerKCF::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerKCF::Params::read,
      Arg("arg_0")).
    define_method<void(cv::legacy::tracking::TrackerKCF::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerKCF::Params::write,
      Arg("arg_0"));

  Rice::Data_Type<cv::legacy::TrackerMOSSE> rb_cCvLegacyTrackerMOSSE = define_class_under<cv::legacy::TrackerMOSSE, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerMOSSE").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMOSSE>(*)()>("create", &cv::legacy::tracking::TrackerMOSSE::create);

  Rice::Data_Type<cv::legacy::MultiTracker> rb_cCvLegacyMultiTracker = define_class_under<cv::legacy::MultiTracker, cv::Algorithm>(rb_mCvLegacyTracking, "MultiTracker").
    define_constructor(Constructor<cv::legacy::tracking::MultiTracker>()).
    define_method<bool(cv::legacy::tracking::MultiTracker::*)(cv::Ptr<cv::legacy::Tracker>, cv::InputArray, const cv::Rect2d&)>("add", &cv::legacy::tracking::MultiTracker::add,
      Arg("new_tracker"), Arg("image"), Arg("bounding_box")).
    define_method<bool(cv::legacy::tracking::MultiTracker::*)(std::vector<cv::Ptr<cv::legacy::Tracker>>, cv::InputArray, std::vector<cv::Rect_<double>>)>("add", &cv::legacy::tracking::MultiTracker::add,
      Arg("new_trackers"), Arg("image"), Arg("bounding_box")).
    define_method<bool(cv::legacy::tracking::MultiTracker::*)(cv::InputArray)>("update", &cv::legacy::tracking::MultiTracker::update,
      Arg("image")).
    define_method<bool(cv::legacy::tracking::MultiTracker::*)(cv::InputArray, std::vector<cv::Rect_<double>>&)>("update", &cv::legacy::tracking::MultiTracker::update,
      Arg("image"), Arg("bounding_box")).
    define_method<const std::vector<cv::Rect_<double>>&(cv::legacy::tracking::MultiTracker::*)() const>("get_objects", &cv::legacy::tracking::MultiTracker::getObjects).
    define_singleton_function<cv::Ptr<cv::legacy::MultiTracker>(*)()>("create", &cv::legacy::tracking::MultiTracker::create);

  Rice::Data_Type<cv::legacy::MultiTracker_Alt> rb_cCvLegacyMultiTrackerAlt = define_class_under<cv::legacy::MultiTracker_Alt>(rb_mCvLegacyTracking, "MultiTrackerAlt").
    define_constructor(Constructor<cv::legacy::tracking::MultiTracker_Alt>()).
    define_method<bool(cv::legacy::tracking::MultiTracker_Alt::*)(cv::InputArray, const cv::Rect2d&, cv::Ptr<cv::legacy::Tracker>)>("add_target", &cv::legacy::tracking::MultiTracker_Alt::addTarget,
      Arg("image"), Arg("bounding_box"), Arg("tracker_algorithm")).
    define_method<bool(cv::legacy::tracking::MultiTracker_Alt::*)(cv::InputArray)>("update", &cv::legacy::tracking::MultiTracker_Alt::update,
      Arg("image")).
    define_attr("target_num", &cv::legacy::tracking::MultiTracker_Alt::targetNum).
    define_attr("trackers", &cv::legacy::tracking::MultiTracker_Alt::trackers).
    define_attr("bounding_boxes", &cv::legacy::tracking::MultiTracker_Alt::boundingBoxes).
    define_attr("colors", &cv::legacy::tracking::MultiTracker_Alt::colors);

  Rice::Data_Type<cv::legacy::MultiTrackerTLD> rb_cCvLegacyMultiTrackerTLD = define_class_under<cv::legacy::MultiTrackerTLD, cv::legacy::MultiTracker_Alt>(rb_mCvLegacyTracking, "MultiTrackerTLD").
    define_constructor(Constructor<cv::legacy::tracking::MultiTrackerTLD>()).
    define_method<bool(cv::legacy::tracking::MultiTrackerTLD::*)(cv::InputArray)>("update_opt", &cv::legacy::tracking::MultiTrackerTLD::update_opt,
      Arg("image"));

  Rice::Data_Type<cv::legacy::TrackerCSRT> rb_cCvLegacyTrackerCSRT = define_class_under<cv::legacy::TrackerCSRT, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerCSRT").
    define_method<void(cv::legacy::tracking::TrackerCSRT::*)(cv::InputArray)>("set_initial_mask", &cv::legacy::tracking::TrackerCSRT::setInitialMask,
      Arg("mask")).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerCSRT>(*)(const cv::legacy::tracking::TrackerCSRT::Params&)>("create", &cv::legacy::tracking::TrackerCSRT::create,
      Arg("parameters")).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerCSRT>(*)()>("create", &cv::legacy::tracking::TrackerCSRT::create);

  Rice::Data_Type<cv::legacy::TrackerCSRT::Params> rb_cCvLegacyTrackerCSRTParams = define_class_under<cv::legacy::TrackerCSRT::Params>(rb_cCvLegacyTrackerCSRT, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerCSRT::Params>()).
    define_method<void(cv::legacy::tracking::TrackerCSRT::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerCSRT::Params::read,
      Arg("arg_0")).
    define_method<void(cv::legacy::tracking::TrackerCSRT::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerCSRT::Params::write,
      Arg("fs"));

  rb_mCvLegacyTracking.define_module_function<cv::Ptr<cv::Tracker>(*)(const cv::Ptr<cv::legacy::Tracker>&)>("upgrade_tracking_api", &cv::legacy::tracking::upgradeTrackingAPI,
    Arg("legacy_tracker"));
}