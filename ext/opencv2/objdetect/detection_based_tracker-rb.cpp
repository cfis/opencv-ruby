#include <opencv2/objdetect/detection_based_tracker.hpp>
#include "../core/cvstd_wrapper-rb.hpp"
#include "detection_based_tracker-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetectionBasedTracker;
Rice::Class rb_cCvDetectionBasedTrackerExtObject;
Rice::Class rb_cCvDetectionBasedTrackerIDetector;
Rice::Class rb_cCvDetectionBasedTrackerParameters;

void Init_DetectionBasedTracker()
{
  Module rb_mCv = define_module("Cv");
  
  rb_cCvDetectionBasedTracker = define_class_under<cv::DetectionBasedTracker>(rb_mCv, "DetectionBasedTracker").
    define_constructor(Constructor<cv::DetectionBasedTracker, cv::Ptr<cv::DetectionBasedTracker::IDetector>, cv::Ptr<cv::DetectionBasedTracker::IDetector>, const cv::DetectionBasedTracker::Parameters&>(),
      Arg("main_detector"), Arg("tracking_detector"), Arg("params")).
    define_method("run?", &cv::DetectionBasedTracker::run).
    define_method("stop", &cv::DetectionBasedTracker::stop).
    define_method("reset_tracking", &cv::DetectionBasedTracker::resetTracking).
    define_method("process", &cv::DetectionBasedTracker::process,
      Arg("image_gray")).
    define_method("set_parameters?", &cv::DetectionBasedTracker::setParameters,
      Arg("params")).
    define_method("get_parameters", &cv::DetectionBasedTracker::getParameters).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<cv::Rect_<int>>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<std::pair<cv::Rect_<int>, int>>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<cv::DetectionBasedTracker::ExtObject>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method("add_object", &cv::DetectionBasedTracker::addObject,
      Arg("location"));
  
  rb_cCvDetectionBasedTrackerIDetector = define_class_under<cv::DetectionBasedTracker::IDetector>(rb_cCvDetectionBasedTracker, "IDetector").
    define_method("detect", &cv::DetectionBasedTracker::IDetector::detect,
      Arg("image"), Arg("objects")).
    define_method("set_min_object_size", &cv::DetectionBasedTracker::IDetector::setMinObjectSize,
      Arg("min")).
    define_method("set_max_object_size", &cv::DetectionBasedTracker::IDetector::setMaxObjectSize,
      Arg("max")).
    define_method("get_min_object_size", &cv::DetectionBasedTracker::IDetector::getMinObjectSize).
    define_method("get_max_object_size", &cv::DetectionBasedTracker::IDetector::getMaxObjectSize).
    define_method("get_scale_factor", &cv::DetectionBasedTracker::IDetector::getScaleFactor).
    define_method("set_scale_factor", &cv::DetectionBasedTracker::IDetector::setScaleFactor,
      Arg("value")).
    define_method("get_min_neighbours", &cv::DetectionBasedTracker::IDetector::getMinNeighbours).
    define_method("set_min_neighbours", &cv::DetectionBasedTracker::IDetector::setMinNeighbours,
      Arg("value"));
  
  rb_cCvDetectionBasedTrackerParameters = define_class_under<cv::DetectionBasedTracker::Parameters>(rb_cCvDetectionBasedTracker, "Parameters").
    define_attr("max_track_lifetime", &cv::DetectionBasedTracker::Parameters::maxTrackLifetime).
    define_attr("min_detection_period", &cv::DetectionBasedTracker::Parameters::minDetectionPeriod).
    define_constructor(Constructor<cv::DetectionBasedTracker::Parameters>());
  
  rb_cCvDetectionBasedTrackerExtObject = define_class_under<cv::DetectionBasedTracker::ExtObject>(rb_cCvDetectionBasedTracker, "ExtObject").
    define_attr("id", &cv::DetectionBasedTracker::ExtObject::id).
    define_attr("location", &cv::DetectionBasedTracker::ExtObject::location).
    define_attr("status", &cv::DetectionBasedTracker::ExtObject::status).
    define_constructor(Constructor<cv::DetectionBasedTracker::ExtObject, int, cv::Rect, cv::DetectionBasedTracker::ObjectStatus>(),
      Arg("_id"), Arg("_location"), Arg("_status"));
  
  Enum<cv::DetectionBasedTracker::ObjectStatus> rb_cCvDetectionBasedTrackerObjectStatus = define_enum_under<cv::DetectionBasedTracker::ObjectStatus>("ObjectStatus", rb_cCvDetectionBasedTracker).
    define_value("DETECTED_NOT_SHOWN_YET", cv::DetectionBasedTracker::ObjectStatus::DETECTED_NOT_SHOWN_YET).
    define_value("DETECTED", cv::DetectionBasedTracker::ObjectStatus::DETECTED).
    define_value("DETECTED_TEMPORARY_LOST", cv::DetectionBasedTracker::ObjectStatus::DETECTED_TEMPORARY_LOST).
    define_value("WRONG_OBJECT", cv::DetectionBasedTracker::ObjectStatus::WRONG_OBJECT);

}