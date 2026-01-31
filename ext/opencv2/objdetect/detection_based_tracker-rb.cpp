#include <opencv2/objdetect/detection_based_tracker.hpp>
#include "detection_based_tracker-rb.hpp"

using namespace Rice;

void Init_Objdetect_DetectionBasedTracker()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::DetectionBasedTracker> rb_cCvDetectionBasedTracker = define_class_under<cv::DetectionBasedTracker>(rb_mCv, "DetectionBasedTracker").
    define_constructor(Constructor<cv::DetectionBasedTracker, cv::Ptr<cv::DetectionBasedTracker::IDetector>, cv::Ptr<cv::DetectionBasedTracker::IDetector>, const cv::DetectionBasedTracker::Parameters&>(),
      Arg("main_detector"), Arg("tracking_detector"), Arg("params")).
    define_method<bool(cv::DetectionBasedTracker::*)()>("run?", &cv::DetectionBasedTracker::run).
    define_method<void(cv::DetectionBasedTracker::*)()>("stop", &cv::DetectionBasedTracker::stop).
    define_method<void(cv::DetectionBasedTracker::*)()>("reset_tracking", &cv::DetectionBasedTracker::resetTracking).
    define_method<void(cv::DetectionBasedTracker::*)(const cv::Mat&)>("process", &cv::DetectionBasedTracker::process,
      Arg("image_gray")).
    define_method<bool(cv::DetectionBasedTracker::*)(const cv::DetectionBasedTracker::Parameters&)>("set_parameters", &cv::DetectionBasedTracker::setParameters,
      Arg("params")).
    define_method<const cv::DetectionBasedTracker::Parameters&(cv::DetectionBasedTracker::*)() const>("get_parameters", &cv::DetectionBasedTracker::getParameters).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<cv::Rect>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<std::pair<cv::Rect_<int>, int>>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<cv::DetectionBasedTracker::ExtObject>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method<int(cv::DetectionBasedTracker::*)(const cv::Rect&)>("add_object", &cv::DetectionBasedTracker::addObject,
      Arg("location"));

  Rice::Data_Type<cv::DetectionBasedTracker::Parameters> rb_cCvDetectionBasedTrackerParameters = define_class_under<cv::DetectionBasedTracker::Parameters>(rb_cCvDetectionBasedTracker, "Parameters").
    define_attr("max_track_lifetime", &cv::DetectionBasedTracker::Parameters::maxTrackLifetime).
    define_attr("min_detection_period", &cv::DetectionBasedTracker::Parameters::minDetectionPeriod).
    define_constructor(Constructor<cv::DetectionBasedTracker::Parameters>());

  Rice::Data_Type<cv::DetectionBasedTracker::IDetector> rb_cCvDetectionBasedTrackerIDetector = define_class_under<cv::DetectionBasedTracker::IDetector>(rb_cCvDetectionBasedTracker, "IDetector").
    define_method<void(cv::DetectionBasedTracker::IDetector::*)(const cv::Mat&, std::vector<cv::Rect>&)>("detect", &cv::DetectionBasedTracker::IDetector::detect,
      Arg("image"), Arg("objects")).
    define_method<void(cv::DetectionBasedTracker::IDetector::*)(const cv::Size&)>("set_min_object_size", &cv::DetectionBasedTracker::IDetector::setMinObjectSize,
      Arg("min")).
    define_method<void(cv::DetectionBasedTracker::IDetector::*)(const cv::Size&)>("set_max_object_size", &cv::DetectionBasedTracker::IDetector::setMaxObjectSize,
      Arg("max")).
    define_method<cv::Size(cv::DetectionBasedTracker::IDetector::*)() const>("get_min_object_size", &cv::DetectionBasedTracker::IDetector::getMinObjectSize).
    define_method<cv::Size(cv::DetectionBasedTracker::IDetector::*)() const>("get_max_object_size", &cv::DetectionBasedTracker::IDetector::getMaxObjectSize).
    define_method<float(cv::DetectionBasedTracker::IDetector::*)()>("get_scale_factor", &cv::DetectionBasedTracker::IDetector::getScaleFactor).
    define_method<void(cv::DetectionBasedTracker::IDetector::*)(float)>("set_scale_factor", &cv::DetectionBasedTracker::IDetector::setScaleFactor,
      Arg("value")).
    define_method<int(cv::DetectionBasedTracker::IDetector::*)()>("get_min_neighbours", &cv::DetectionBasedTracker::IDetector::getMinNeighbours).
    define_method<void(cv::DetectionBasedTracker::IDetector::*)(int)>("set_min_neighbours", &cv::DetectionBasedTracker::IDetector::setMinNeighbours,
      Arg("value"));

  Rice::Data_Type<cv::DetectionBasedTracker::ExtObject> rb_cCvDetectionBasedTrackerExtObject = define_class_under<cv::DetectionBasedTracker::ExtObject>(rb_cCvDetectionBasedTracker, "ExtObject").
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