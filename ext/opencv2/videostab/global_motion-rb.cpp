#include <opencv2/videostab/global_motion.hpp>
#include "global_motion-rb.hpp"

using namespace Rice;

void Init_Videostab_GlobalMotion()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  rb_mCvVideostab.define_module_function<cv::Mat(*)(cv::InputOutputArray, cv::InputOutputArray, int, float*)>("estimate_global_motion_least_squares", &cv::videostab::estimateGlobalMotionLeastSquares,
    Arg("points0"), Arg("points1"), Arg("model") = static_cast<int>(cv::videostab::MM_AFFINE), ArgBuffer("rmse") = static_cast<float*>(0));

  rb_mCvVideostab.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, int, const cv::videostab::RansacParams&, float*, int*)>("estimate_global_motion_ransac", &cv::videostab::estimateGlobalMotionRansac,
    Arg("points0"), Arg("points1"), Arg("model") = static_cast<int>(cv::videostab::MM_AFFINE), Arg("params") = static_cast<const cv::videostab::RansacParams&>(cv::videostab::RansacParams::default2dMotion(cv::videostab::MM_AFFINE)), ArgBuffer("rmse") = static_cast<float*>(0), ArgBuffer("ninliers") = static_cast<int*>(0));

  Rice::Data_Type<cv::videostab::MotionEstimatorBase> rb_cCvVideostabMotionEstimatorBase = define_class_under<cv::videostab::MotionEstimatorBase>(rb_mCvVideostab, "MotionEstimatorBase").
    define_method<void(cv::videostab::MotionEstimatorBase::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::MotionEstimatorBase::setMotionModel,
      Arg("val")).
    define_method<cv::videostab::MotionModel(cv::videostab::MotionEstimatorBase::*)() const>("motion_model", &cv::videostab::MotionEstimatorBase::motionModel).
    define_method<cv::Mat(cv::videostab::MotionEstimatorBase::*)(cv::InputArray, cv::InputArray, bool*)>("estimate", &cv::videostab::MotionEstimatorBase::estimate,
      Arg("points0"), Arg("points1"), ArgBuffer("ok") = static_cast<bool*>(0));

  Rice::Data_Type<cv::videostab::MotionEstimatorRansacL2> rb_cCvVideostabMotionEstimatorRansacL2 = define_class_under<cv::videostab::MotionEstimatorRansacL2, cv::videostab::MotionEstimatorBase>(rb_mCvVideostab, "MotionEstimatorRansacL2").
    define_constructor(Constructor<cv::videostab::MotionEstimatorRansacL2, cv::videostab::MotionModel>(),
      Arg("model") = static_cast<cv::videostab::MotionModel>(cv::videostab::MM_AFFINE)).
    define_method<void(cv::videostab::MotionEstimatorRansacL2::*)(const cv::videostab::RansacParams&)>("set_ransac_params", &cv::videostab::MotionEstimatorRansacL2::setRansacParams,
      Arg("val")).
    define_method<cv::videostab::RansacParams(cv::videostab::MotionEstimatorRansacL2::*)() const>("ransac_params", &cv::videostab::MotionEstimatorRansacL2::ransacParams).
    define_method<void(cv::videostab::MotionEstimatorRansacL2::*)(float)>("set_min_inlier_ratio", &cv::videostab::MotionEstimatorRansacL2::setMinInlierRatio,
      Arg("val")).
    define_method<float(cv::videostab::MotionEstimatorRansacL2::*)() const>("min_inlier_ratio", &cv::videostab::MotionEstimatorRansacL2::minInlierRatio).
    define_method<cv::Mat(cv::videostab::MotionEstimatorRansacL2::*)(cv::InputArray, cv::InputArray, bool*)>("estimate", &cv::videostab::MotionEstimatorRansacL2::estimate,
      Arg("points0"), Arg("points1"), ArgBuffer("ok") = static_cast<bool*>(0));

  Rice::Data_Type<cv::videostab::MotionEstimatorL1> rb_cCvVideostabMotionEstimatorL1 = define_class_under<cv::videostab::MotionEstimatorL1, cv::videostab::MotionEstimatorBase>(rb_mCvVideostab, "MotionEstimatorL1").
    define_constructor(Constructor<cv::videostab::MotionEstimatorL1, cv::videostab::MotionModel>(),
      Arg("model") = static_cast<cv::videostab::MotionModel>(cv::videostab::MM_AFFINE)).
    define_method<cv::Mat(cv::videostab::MotionEstimatorL1::*)(cv::InputArray, cv::InputArray, bool*)>("estimate", &cv::videostab::MotionEstimatorL1::estimate,
      Arg("points0"), Arg("points1"), ArgBuffer("ok") = static_cast<bool*>(0));

  Rice::Data_Type<cv::videostab::ImageMotionEstimatorBase> rb_cCvVideostabImageMotionEstimatorBase = define_class_under<cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "ImageMotionEstimatorBase").
    define_method<void(cv::videostab::ImageMotionEstimatorBase::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::ImageMotionEstimatorBase::setMotionModel,
      Arg("val")).
    define_method<cv::videostab::MotionModel(cv::videostab::ImageMotionEstimatorBase::*)() const>("motion_model", &cv::videostab::ImageMotionEstimatorBase::motionModel).
    define_method<void(cv::videostab::ImageMotionEstimatorBase::*)(cv::InputArray)>("set_frame_mask", &cv::videostab::ImageMotionEstimatorBase::setFrameMask,
      Arg("mask")).
    define_method<cv::Mat(cv::videostab::ImageMotionEstimatorBase::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::ImageMotionEstimatorBase::estimate,
      Arg("frame0"), Arg("frame1"), ArgBuffer("ok") = static_cast<bool*>(0));

  Rice::Data_Type<cv::videostab::FromFileMotionReader> rb_cCvVideostabFromFileMotionReader = define_class_under<cv::videostab::FromFileMotionReader, cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "FromFileMotionReader").
    define_constructor(Constructor<cv::videostab::FromFileMotionReader, const cv::String&>(),
      Arg("path")).
    define_method<cv::Mat(cv::videostab::FromFileMotionReader::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::FromFileMotionReader::estimate,
      Arg("frame0"), Arg("frame1"), ArgBuffer("ok") = static_cast<bool*>(0));

  Rice::Data_Type<cv::videostab::ToFileMotionWriter> rb_cCvVideostabToFileMotionWriter = define_class_under<cv::videostab::ToFileMotionWriter, cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "ToFileMotionWriter").
    define_constructor(Constructor<cv::videostab::ToFileMotionWriter, const cv::String&, cv::Ptr<cv::videostab::ImageMotionEstimatorBase>>(),
      Arg("path"), Arg("estimator")).
    define_method<void(cv::videostab::ToFileMotionWriter::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::ToFileMotionWriter::setMotionModel,
      Arg("val")).
    define_method<cv::videostab::MotionModel(cv::videostab::ToFileMotionWriter::*)() const>("motion_model", &cv::videostab::ToFileMotionWriter::motionModel).
    define_method<void(cv::videostab::ToFileMotionWriter::*)(cv::InputArray)>("set_frame_mask", &cv::videostab::ToFileMotionWriter::setFrameMask,
      Arg("mask")).
    define_method<cv::Mat(cv::videostab::ToFileMotionWriter::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::ToFileMotionWriter::estimate,
      Arg("frame0"), Arg("frame1"), ArgBuffer("ok") = static_cast<bool*>(0));

  Rice::Data_Type<cv::videostab::KeypointBasedMotionEstimator> rb_cCvVideostabKeypointBasedMotionEstimator = define_class_under<cv::videostab::KeypointBasedMotionEstimator, cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "KeypointBasedMotionEstimator").
    define_constructor(Constructor<cv::videostab::KeypointBasedMotionEstimator, cv::Ptr<cv::videostab::MotionEstimatorBase>>(),
      Arg("estimator")).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::KeypointBasedMotionEstimator::setMotionModel,
      Arg("val")).
    define_method<cv::videostab::MotionModel(cv::videostab::KeypointBasedMotionEstimator::*)() const>("motion_model", &cv::videostab::KeypointBasedMotionEstimator::motionModel).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::Ptr<cv::Feature2D>)>("set_detector", &cv::videostab::KeypointBasedMotionEstimator::setDetector,
      Arg("val")).
    define_method<cv::Ptr<cv::Feature2D>(cv::videostab::KeypointBasedMotionEstimator::*)() const>("detector", &cv::videostab::KeypointBasedMotionEstimator::detector).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::Ptr<cv::videostab::ISparseOptFlowEstimator>)>("set_optical_flow_estimator", &cv::videostab::KeypointBasedMotionEstimator::setOpticalFlowEstimator,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::ISparseOptFlowEstimator>(cv::videostab::KeypointBasedMotionEstimator::*)() const>("optical_flow_estimator", &cv::videostab::KeypointBasedMotionEstimator::opticalFlowEstimator).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::Ptr<cv::videostab::IOutlierRejector>)>("set_outlier_rejector", &cv::videostab::KeypointBasedMotionEstimator::setOutlierRejector,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::IOutlierRejector>(cv::videostab::KeypointBasedMotionEstimator::*)() const>("outlier_rejector", &cv::videostab::KeypointBasedMotionEstimator::outlierRejector).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::InputArray)>("set_frame_mask", &cv::videostab::KeypointBasedMotionEstimator::setFrameMask,
      Arg("mask")).
    define_method<cv::Mat(cv::videostab::KeypointBasedMotionEstimator::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::KeypointBasedMotionEstimator::estimate,
      Arg("frame0"), Arg("frame1"), ArgBuffer("ok") = static_cast<bool*>(0)).
    define_method<cv::Mat(cv::videostab::KeypointBasedMotionEstimator::*)(cv::InputArray, cv::InputArray, bool*)>("estimate", &cv::videostab::KeypointBasedMotionEstimator::estimate,
      Arg("frame0"), Arg("frame1"), ArgBuffer("ok") = static_cast<bool*>(0));

  Rice::Data_Type<cv::videostab::KeypointBasedMotionEstimatorGpu> rb_cCvVideostabKeypointBasedMotionEstimatorGpu = define_class_under<cv::videostab::KeypointBasedMotionEstimatorGpu, cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "KeypointBasedMotionEstimatorGpu").
    define_constructor(Constructor<cv::videostab::KeypointBasedMotionEstimatorGpu, cv::Ptr<cv::videostab::MotionEstimatorBase>>(),
      Arg("estimator")).
    define_method<void(cv::videostab::KeypointBasedMotionEstimatorGpu::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::KeypointBasedMotionEstimatorGpu::setMotionModel,
      Arg("val")).
    define_method<cv::videostab::MotionModel(cv::videostab::KeypointBasedMotionEstimatorGpu::*)() const>("motion_model", &cv::videostab::KeypointBasedMotionEstimatorGpu::motionModel).
    define_method<void(cv::videostab::KeypointBasedMotionEstimatorGpu::*)(cv::Ptr<cv::videostab::IOutlierRejector>)>("set_outlier_rejector", &cv::videostab::KeypointBasedMotionEstimatorGpu::setOutlierRejector,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::IOutlierRejector>(cv::videostab::KeypointBasedMotionEstimatorGpu::*)() const>("outlier_rejector", &cv::videostab::KeypointBasedMotionEstimatorGpu::outlierRejector).
    define_method<cv::Mat(cv::videostab::KeypointBasedMotionEstimatorGpu::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::KeypointBasedMotionEstimatorGpu::estimate,
      Arg("frame0"), Arg("frame1"), ArgBuffer("ok") = static_cast<bool*>(0)).
    define_method<cv::Mat(cv::videostab::KeypointBasedMotionEstimatorGpu::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, bool*)>("estimate", &cv::videostab::KeypointBasedMotionEstimatorGpu::estimate,
      Arg("frame0"), Arg("frame1"), ArgBuffer("ok") = static_cast<bool*>(0));

  rb_mCvVideostab.define_module_function<cv::Mat(*)(int, int, const std::vector<cv::Mat>&)>("get_motion", &cv::videostab::getMotion,
    Arg("from"), Arg("to"), Arg("motions"));
}