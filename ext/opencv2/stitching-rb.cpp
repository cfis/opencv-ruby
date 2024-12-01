#include <opencv2/stitching.hpp>
#include "core/cvstd_wrapper-rb.hpp"
#include "stitching-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvStitcher;

void Init_Stitching()
{
  Module rb_mCv = define_module("Cv");
  
  rb_cCvStitcher = define_class_under<cv::Stitcher>(rb_mCv, "Stitcher").
    define_constructor(Constructor<cv::Stitcher>()).
    define_constant("ORIG_RESOL", cv::Stitcher::ORIG_RESOL).
    define_singleton_function("create", &cv::Stitcher::create,
      Arg("mode") = static_cast<cv::Stitcher::Mode>(cv::Stitcher::PANORAMA)).
    define_method("registration_resol", &cv::Stitcher::registrationResol).
    define_method("set_registration_resol", &cv::Stitcher::setRegistrationResol,
      Arg("resol_mpx")).
    define_method("seam_estimation_resol", &cv::Stitcher::seamEstimationResol).
    define_method("set_seam_estimation_resol", &cv::Stitcher::setSeamEstimationResol,
      Arg("resol_mpx")).
    define_method("compositing_resol", &cv::Stitcher::compositingResol).
    define_method("set_compositing_resol", &cv::Stitcher::setCompositingResol,
      Arg("resol_mpx")).
    define_method("pano_confidence_thresh", &cv::Stitcher::panoConfidenceThresh).
    define_method("set_pano_confidence_thresh", &cv::Stitcher::setPanoConfidenceThresh,
      Arg("conf_thresh")).
    define_method("wave_correction?", &cv::Stitcher::waveCorrection).
    define_method("set_wave_correction", &cv::Stitcher::setWaveCorrection,
      Arg("flag")).
    define_method("interpolation_flags", &cv::Stitcher::interpolationFlags).
    define_method("set_interpolation_flags", &cv::Stitcher::setInterpolationFlags,
      Arg("interp_flags")).
    define_method("wave_correct_kind", &cv::Stitcher::waveCorrectKind).
    define_method("set_wave_correct_kind", &cv::Stitcher::setWaveCorrectKind,
      Arg("kind")).
    define_method<cv::Ptr<cv::Feature2D>(cv::Stitcher::*)()>("features_finder", &cv::Stitcher::featuresFinder).
    define_method<cv::Ptr<cv::Feature2D>(cv::Stitcher::*)() const>("features_finder", &cv::Stitcher::featuresFinder).
    define_method("set_features_finder", &cv::Stitcher::setFeaturesFinder,
      Arg("features_finder")).
    define_method<cv::Ptr<cv::detail::FeaturesMatcher>(cv::Stitcher::*)()>("features_matcher", &cv::Stitcher::featuresMatcher).
    define_method<cv::Ptr<cv::detail::FeaturesMatcher>(cv::Stitcher::*)() const>("features_matcher", &cv::Stitcher::featuresMatcher).
    define_method("set_features_matcher", &cv::Stitcher::setFeaturesMatcher,
      Arg("features_matcher")).
    define_method("matching_mask", &cv::Stitcher::matchingMask).
    define_method("set_matching_mask", &cv::Stitcher::setMatchingMask,
      Arg("mask")).
    define_method<cv::Ptr<cv::detail::BundleAdjusterBase>(cv::Stitcher::*)()>("bundle_adjuster", &cv::Stitcher::bundleAdjuster).
    define_method<const cv::Ptr<cv::detail::BundleAdjusterBase>(cv::Stitcher::*)() const>("bundle_adjuster", &cv::Stitcher::bundleAdjuster).
    define_method("set_bundle_adjuster", &cv::Stitcher::setBundleAdjuster,
      Arg("bundle_adjuster")).
    define_method<cv::Ptr<cv::detail::Estimator>(cv::Stitcher::*)()>("estimator", &cv::Stitcher::estimator).
    define_method<const cv::Ptr<cv::detail::Estimator>(cv::Stitcher::*)() const>("estimator", &cv::Stitcher::estimator).
    define_method("set_estimator", &cv::Stitcher::setEstimator,
      Arg("estimator")).
    define_method<cv::Ptr<cv::WarperCreator>(cv::Stitcher::*)()>("warper", &cv::Stitcher::warper).
    define_method<const cv::Ptr<cv::WarperCreator>(cv::Stitcher::*)() const>("warper", &cv::Stitcher::warper).
    define_method("set_warper", &cv::Stitcher::setWarper,
      Arg("creator")).
    define_method<cv::Ptr<cv::detail::ExposureCompensator>(cv::Stitcher::*)()>("exposure_compensator", &cv::Stitcher::exposureCompensator).
    define_method<const cv::Ptr<cv::detail::ExposureCompensator>(cv::Stitcher::*)() const>("exposure_compensator", &cv::Stitcher::exposureCompensator).
    define_method("set_exposure_compensator", &cv::Stitcher::setExposureCompensator,
      Arg("exposure_comp")).
    define_method<cv::Ptr<cv::detail::SeamFinder>(cv::Stitcher::*)()>("seam_finder", &cv::Stitcher::seamFinder).
    define_method<const cv::Ptr<cv::detail::SeamFinder>(cv::Stitcher::*)() const>("seam_finder", &cv::Stitcher::seamFinder).
    define_method("set_seam_finder", &cv::Stitcher::setSeamFinder,
      Arg("seam_finder")).
    define_method<cv::Ptr<cv::detail::Blender>(cv::Stitcher::*)()>("blender", &cv::Stitcher::blender).
    define_method<const cv::Ptr<cv::detail::Blender>(cv::Stitcher::*)() const>("blender", &cv::Stitcher::blender).
    define_method("set_blender", &cv::Stitcher::setBlender,
      Arg("b")).
    define_method("estimate_transform", &cv::Stitcher::estimateTransform,
      Arg("images"), Arg("masks") = static_cast<cv::InputArrayOfArrays>(cv::noArray())).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(cv::InputArrayOfArrays, const std::vector<cv::detail::CameraParams>&, const std::vector<int>&)>("set_transform", &cv::Stitcher::setTransform,
      Arg("images"), Arg("cameras"), Arg("component")).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(cv::InputArrayOfArrays, const std::vector<cv::detail::CameraParams>&)>("set_transform", &cv::Stitcher::setTransform,
      Arg("images"), Arg("cameras")).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(cv::OutputArray)>("compose_panorama", &cv::Stitcher::composePanorama,
      Arg("pano")).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(cv::InputArrayOfArrays, cv::OutputArray)>("compose_panorama", &cv::Stitcher::composePanorama,
      Arg("images"), Arg("pano")).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(cv::InputArrayOfArrays, cv::OutputArray)>("stitch", &cv::Stitcher::stitch,
      Arg("images"), Arg("pano")).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::OutputArray)>("stitch", &cv::Stitcher::stitch,
      Arg("images"), Arg("masks"), Arg("pano")).
    define_method("component", &cv::Stitcher::component).
    define_method("cameras", &cv::Stitcher::cameras).
    define_method("work_scale", &cv::Stitcher::workScale).
    define_method("result_mask", &cv::Stitcher::resultMask);
  
  Enum<cv::Stitcher::Status> rb_cCvStitcherStatus = define_enum_under<cv::Stitcher::Status>("Status", rb_cCvStitcher).
    define_value("OK", cv::Stitcher::Status::OK).
    define_value("ERR_NEED_MORE_IMGS", cv::Stitcher::Status::ERR_NEED_MORE_IMGS).
    define_value("ERR_HOMOGRAPHY_EST_FAIL", cv::Stitcher::Status::ERR_HOMOGRAPHY_EST_FAIL).
    define_value("ERR_CAMERA_PARAMS_ADJUST_FAIL", cv::Stitcher::Status::ERR_CAMERA_PARAMS_ADJUST_FAIL);
  
  Enum<cv::Stitcher::Mode> rb_cCvStitcherMode = define_enum_under<cv::Stitcher::Mode>("Mode", rb_cCvStitcher).
    define_value("PANORAMA", cv::Stitcher::Mode::PANORAMA).
    define_value("SCANS", cv::Stitcher::Mode::SCANS);
}