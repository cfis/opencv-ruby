#include <opencv2/tracking/tracking_by_matching.hpp>
#include "tracking_by_matching-rb.hpp"

using namespace Rice;

void Init_Tracking_TrackingByMatching()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");

  Module rb_mCvDetailTrackingTbm = define_module_under(rb_mCvDetailTracking, "Tbm");

  Rice::Data_Type<cv::detail::tbm::TrackedObject> rb_cCvDetailTbmTrackedObject = define_class_under<cv::detail::tbm::TrackedObject>(rb_mCvDetailTrackingTbm, "TrackedObject").
    define_attr("rect", &cv::detail::tracking::tbm::TrackedObject::rect).
    define_attr("confidence", &cv::detail::tracking::tbm::TrackedObject::confidence).
    define_attr("frame_idx", &cv::detail::tracking::tbm::TrackedObject::frame_idx).
    define_attr("object_id", &cv::detail::tracking::tbm::TrackedObject::object_id).
    define_attr("timestamp", &cv::detail::tracking::tbm::TrackedObject::timestamp).
    define_constructor(Constructor<cv::detail::tracking::tbm::TrackedObject>()).
    define_constructor(Constructor<cv::detail::tracking::tbm::TrackedObject, const cv::Rect&, float, int, int>(),
      Arg("rect"), Arg("confidence"), Arg("frame_idx"), Arg("object_id"));

  Rice::Data_Type<cv::detail::tbm::IImageDescriptor> rb_cCvDetailTbmIImageDescriptor = define_class_under<cv::detail::tbm::IImageDescriptor>(rb_mCvDetailTrackingTbm, "IImageDescriptor").
    define_method<cv::Size(cv::detail::tracking::tbm::IImageDescriptor::*)() const>("size", &cv::detail::tracking::tbm::IImageDescriptor::size).
    define_method<void(cv::detail::tracking::tbm::IImageDescriptor::*)(const cv::Mat&, cv::Mat&)>("compute", &cv::detail::tracking::tbm::IImageDescriptor::compute,
      Arg("mat"), Arg("descr")).
    define_method<void(cv::detail::tracking::tbm::IImageDescriptor::*)(const std::vector<cv::Mat>&, std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::IImageDescriptor::compute,
      Arg("mats"), Arg("descrs"));

  Rice::Data_Type<cv::detail::tbm::ResizedImageDescriptor> rb_cCvDetailTbmResizedImageDescriptor = define_class_under<cv::detail::tbm::ResizedImageDescriptor, cv::detail::tbm::IImageDescriptor>(rb_mCvDetailTrackingTbm, "ResizedImageDescriptor").
    define_constructor(Constructor<cv::detail::tracking::tbm::ResizedImageDescriptor, const cv::Size&, const cv::InterpolationFlags>(),
      Arg("descr_size"), Arg("interpolation")).
    define_method<cv::Size(cv::detail::tracking::tbm::ResizedImageDescriptor::*)() const>("size", &cv::detail::tracking::tbm::ResizedImageDescriptor::size).
    define_method<void(cv::detail::tracking::tbm::ResizedImageDescriptor::*)(const cv::Mat&, cv::Mat&)>("compute", &cv::detail::tracking::tbm::ResizedImageDescriptor::compute,
      Arg("mat"), Arg("descr")).
    define_method<void(cv::detail::tracking::tbm::ResizedImageDescriptor::*)(const std::vector<cv::Mat>&, std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::ResizedImageDescriptor::compute,
      Arg("mats"), Arg("descrs"));

  Rice::Data_Type<cv::detail::tbm::IDescriptorDistance> rb_cCvDetailTbmIDescriptorDistance = define_class_under<cv::detail::tbm::IDescriptorDistance>(rb_mCvDetailTrackingTbm, "IDescriptorDistance").
    define_method<float(cv::detail::tracking::tbm::IDescriptorDistance::*)(const cv::Mat&, const cv::Mat&)>("compute", &cv::detail::tracking::tbm::IDescriptorDistance::compute,
      Arg("descr1"), Arg("descr2")).
    define_method<std::vector<float>(cv::detail::tracking::tbm::IDescriptorDistance::*)(const std::vector<cv::Mat>&, const std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::IDescriptorDistance::compute,
      Arg("descrs1"), Arg("descrs2"));

  Rice::Data_Type<cv::detail::tbm::CosDistance> rb_cCvDetailTbmCosDistance = define_class_under<cv::detail::tbm::CosDistance, cv::detail::tbm::IDescriptorDistance>(rb_mCvDetailTrackingTbm, "CosDistance").
    define_constructor(Constructor<cv::detail::tracking::tbm::CosDistance, const cv::Size&>(),
      Arg("descriptor_size")).
    define_method<float(cv::detail::tracking::tbm::CosDistance::*)(const cv::Mat&, const cv::Mat&)>("compute", &cv::detail::tracking::tbm::CosDistance::compute,
      Arg("descr1"), Arg("descr2")).
    define_method<std::vector<float>(cv::detail::tracking::tbm::CosDistance::*)(const std::vector<cv::Mat>&, const std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::CosDistance::compute,
      Arg("descrs1"), Arg("descrs2"));

  Rice::Data_Type<cv::detail::tbm::MatchTemplateDistance> rb_cCvDetailTbmMatchTemplateDistance = define_class_under<cv::detail::tbm::MatchTemplateDistance, cv::detail::tbm::IDescriptorDistance>(rb_mCvDetailTrackingTbm, "MatchTemplateDistance").
    define_constructor(Constructor<cv::detail::tracking::tbm::MatchTemplateDistance, int, float, float>(),
      Arg("type") = static_cast<int>(cv::TM_CCORR_NORMED), Arg("scale") = static_cast<float>(-1), Arg("offset") = static_cast<float>(1)).
    define_method<float(cv::detail::tracking::tbm::MatchTemplateDistance::*)(const cv::Mat&, const cv::Mat&)>("compute", &cv::detail::tracking::tbm::MatchTemplateDistance::compute,
      Arg("descr1"), Arg("descr2")).
    define_method<std::vector<float>(cv::detail::tracking::tbm::MatchTemplateDistance::*)(const std::vector<cv::Mat>&, const std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::MatchTemplateDistance::compute,
      Arg("descrs1"), Arg("descrs2"));

  Rice::Data_Type<cv::detail::tbm::TrackerParams> rb_cCvDetailTbmTrackerParams = define_class_under<cv::detail::tbm::TrackerParams>(rb_mCvDetailTrackingTbm, "TrackerParams").
    define_attr("min_track_duration", &cv::detail::tracking::tbm::TrackerParams::min_track_duration).
    define_attr("forget_delay", &cv::detail::tracking::tbm::TrackerParams::forget_delay).
    define_attr("aff_thr_fast", &cv::detail::tracking::tbm::TrackerParams::aff_thr_fast).
    define_attr("aff_thr_strong", &cv::detail::tracking::tbm::TrackerParams::aff_thr_strong).
    define_attr("shape_affinity_w", &cv::detail::tracking::tbm::TrackerParams::shape_affinity_w).
    define_attr("motion_affinity_w", &cv::detail::tracking::tbm::TrackerParams::motion_affinity_w).
    define_attr("time_affinity_w", &cv::detail::tracking::tbm::TrackerParams::time_affinity_w).
    define_attr("min_det_conf", &cv::detail::tracking::tbm::TrackerParams::min_det_conf).
    define_attr("bbox_aspect_ratios_range", &cv::detail::tracking::tbm::TrackerParams::bbox_aspect_ratios_range).
    define_attr("bbox_heights_range", &cv::detail::tracking::tbm::TrackerParams::bbox_heights_range).
    define_attr("predict", &cv::detail::tracking::tbm::TrackerParams::predict).
    define_attr("strong_affinity_thr", &cv::detail::tracking::tbm::TrackerParams::strong_affinity_thr).
    define_attr("reid_thr", &cv::detail::tracking::tbm::TrackerParams::reid_thr).
    define_attr("drop_forgotten_tracks", &cv::detail::tracking::tbm::TrackerParams::drop_forgotten_tracks).
    define_attr("max_num_objects_in_track", &cv::detail::tracking::tbm::TrackerParams::max_num_objects_in_track).
    define_constructor(Constructor<cv::detail::tracking::tbm::TrackerParams>());

  Rice::Data_Type<cv::detail::tbm::Track> rb_cCvDetailTbmTrack = define_class_under<cv::detail::tbm::Track>(rb_mCvDetailTrackingTbm, "Track").
    define_constructor(Constructor<cv::detail::tracking::tbm::Track, const cv::detail::tracking::tbm::TrackedObjects&, const cv::Mat&, const cv::Mat&, const cv::Mat&>(),
      Arg("objs"), Arg("last_image"), Arg("descriptor_fast"), Arg("descriptor_strong")).
    define_method<bool(cv::detail::tracking::tbm::Track::*)() const>("empty?", &cv::detail::tracking::tbm::Track::empty).
    define_method<size_t(cv::detail::tracking::tbm::Track::*)() const>("size", &cv::detail::tracking::tbm::Track::size).
    define_method<const cv::detail::tracking::tbm::TrackedObject&(cv::detail::tracking::tbm::Track::*)(size_t) const>("[]", &cv::detail::tracking::tbm::Track::operator[],
      Arg("i")).
    define_method<cv::detail::tracking::tbm::TrackedObject&(cv::detail::tracking::tbm::Track::*)(size_t)>("[]", &cv::detail::tracking::tbm::Track::operator[],
      Arg("i")).
    define_method("[]=", [](cv::detail::tracking::tbm::Track&self, int index, TrackedObject & value)
    {
        self[index] = value;
    }).
    define_method<const cv::detail::tracking::tbm::TrackedObject&(cv::detail::tracking::tbm::Track::*)() const>("back", &cv::detail::tracking::tbm::Track::back).
    define_method<cv::detail::tracking::tbm::TrackedObject&(cv::detail::tracking::tbm::Track::*)()>("back", &cv::detail::tracking::tbm::Track::back).
    define_attr("objects", &cv::detail::tracking::tbm::Track::objects).
    define_attr("predicted_rect", &cv::detail::tracking::tbm::Track::predicted_rect).
    define_attr("last_image", &cv::detail::tracking::tbm::Track::last_image).
    define_attr("descriptor_fast", &cv::detail::tracking::tbm::Track::descriptor_fast).
    define_attr("descriptor_strong", &cv::detail::tracking::tbm::Track::descriptor_strong).
    define_attr("lost", &cv::detail::tracking::tbm::Track::lost).
    define_attr("first_object", &cv::detail::tracking::tbm::Track::first_object).
    define_attr("length", &cv::detail::tracking::tbm::Track::length);

  Rice::Data_Type<cv::detail::tbm::ITrackerByMatching> rb_cCvDetailTbmITrackerByMatching = define_class_under<cv::detail::tbm::ITrackerByMatching>(rb_mCvDetailTrackingTbm, "ITrackerByMatching").
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::Mat&, const cv::detail::tracking::tbm::TrackedObjects&, uint64_t)>("process", &cv::detail::tracking::tbm::ITrackerByMatching::process,
      Arg("frame"), Arg("detections"), Arg("timestamp")).
    define_method<const cv::detail::tracking::tbm::TrackerParams&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("params", &cv::detail::tracking::tbm::ITrackerByMatching::params).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::detail::tracking::tbm::TrackerParams&)>("set_params", &cv::detail::tracking::tbm::ITrackerByMatching::setParams,
      Arg("params")).
    define_method<const cv::detail::tracking::tbm::ITrackerByMatching::Descriptor&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("descriptor_fast", &cv::detail::tracking::tbm::ITrackerByMatching::descriptorFast).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::detail::tracking::tbm::ITrackerByMatching::Descriptor&)>("set_descriptor_fast", &cv::detail::tracking::tbm::ITrackerByMatching::setDescriptorFast,
      Arg("val")).
    define_method<const cv::detail::tracking::tbm::ITrackerByMatching::Descriptor&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("descriptor_strong", &cv::detail::tracking::tbm::ITrackerByMatching::descriptorStrong).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::detail::tracking::tbm::ITrackerByMatching::Descriptor&)>("set_descriptor_strong", &cv::detail::tracking::tbm::ITrackerByMatching::setDescriptorStrong,
      Arg("val")).
    define_method<const cv::detail::tracking::tbm::ITrackerByMatching::Distance&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("distance_fast", &cv::detail::tracking::tbm::ITrackerByMatching::distanceFast).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::detail::tracking::tbm::ITrackerByMatching::Distance&)>("set_distance_fast", &cv::detail::tracking::tbm::ITrackerByMatching::setDistanceFast,
      Arg("val")).
    define_method<const cv::detail::tracking::tbm::ITrackerByMatching::Distance&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("distance_strong", &cv::detail::tracking::tbm::ITrackerByMatching::distanceStrong).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::detail::tracking::tbm::ITrackerByMatching::Distance&)>("set_distance_strong", &cv::detail::tracking::tbm::ITrackerByMatching::setDistanceStrong,
      Arg("val")).
    define_method<size_t(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("count", &cv::detail::tracking::tbm::ITrackerByMatching::count).
    define_method<std::unordered_map<std::size_t, std::vector<cv::Point>>(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("get_active_tracks", &cv::detail::tracking::tbm::ITrackerByMatching::getActiveTracks).
    define_method<cv::detail::tracking::tbm::TrackedObjects(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("tracked_detections", &cv::detail::tracking::tbm::ITrackerByMatching::trackedDetections).
    define_method<cv::Mat(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::Mat&)>("draw_active_tracks", &cv::detail::tracking::tbm::ITrackerByMatching::drawActiveTracks,
      Arg("frame")).
    define_method<bool(cv::detail::tracking::tbm::ITrackerByMatching::*)(size_t) const>("track_forgotten?", &cv::detail::tracking::tbm::ITrackerByMatching::isTrackForgotten,
      Arg("id")).
    define_method<const std::unordered_map<unsigned long, cv::detail::tbm::Track>&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("tracks", &cv::detail::tracking::tbm::ITrackerByMatching::tracks).
    define_method<bool(cv::detail::tracking::tbm::ITrackerByMatching::*)(size_t) const>("track_valid?", &cv::detail::tracking::tbm::ITrackerByMatching::isTrackValid,
      Arg("track_id")).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)()>("drop_forgotten_tracks", &cv::detail::tracking::tbm::ITrackerByMatching::dropForgottenTracks).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(size_t)>("drop_forgotten_track", &cv::detail::tracking::tbm::ITrackerByMatching::dropForgottenTrack,
      Arg("track_id"));

  rb_mCvDetailTrackingTbm.define_module_function<cv::Ptr<cv::detail::tbm::ITrackerByMatching>(*)(const cv::detail::tracking::tbm::TrackerParams&)>("create_tracker_by_matching", &cv::detail::tracking::tbm::createTrackerByMatching,
    Arg("params") = static_cast<const cv::detail::tracking::tbm::TrackerParams&>(cv::detail::tracking::tbm::TrackerParams()));

  rb_cCvDetailTbmTrackedObject.
    define_method("==", [](const cv::detail::tracking::tbm::TrackedObject& self, const cv::detail::tracking::tbm::TrackedObject& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::detail::tracking::tbm::TrackedObject& self, const cv::detail::tracking::tbm::TrackedObject& other) -> bool
    {
      return self != other;
    });
}
