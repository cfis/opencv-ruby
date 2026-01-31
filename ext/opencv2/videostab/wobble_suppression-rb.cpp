#include <opencv2/videostab/wobble_suppression.hpp>
#include "wobble_suppression-rb.hpp"

using namespace Rice;

void Init_Videostab_WobbleSuppression()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  Rice::Data_Type<cv::videostab::WobbleSuppressorBase> rb_cCvVideostabWobbleSuppressorBase = define_class_under<cv::videostab::WobbleSuppressorBase>(rb_mCvVideostab, "WobbleSuppressorBase").
    define_method<void(cv::videostab::WobbleSuppressorBase::*)(cv::Ptr<cv::videostab::ImageMotionEstimatorBase>)>("set_motion_estimator", &cv::videostab::WobbleSuppressorBase::setMotionEstimator,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::ImageMotionEstimatorBase>(cv::videostab::WobbleSuppressorBase::*)() const>("motion_estimator", &cv::videostab::WobbleSuppressorBase::motionEstimator).
    define_method<void(cv::videostab::WobbleSuppressorBase::*)(int, const cv::Mat&, cv::Mat&)>("suppress", &cv::videostab::WobbleSuppressorBase::suppress,
      Arg("idx"), Arg("frame"), Arg("result")).
    define_method<void(cv::videostab::WobbleSuppressorBase::*)(int)>("set_frame_count", &cv::videostab::WobbleSuppressorBase::setFrameCount,
      Arg("val")).
    define_method<int(cv::videostab::WobbleSuppressorBase::*)() const>("frame_count", &cv::videostab::WobbleSuppressorBase::frameCount).
    define_method<void(cv::videostab::WobbleSuppressorBase::*)(const std::vector<cv::Mat>&)>("set_motions", &cv::videostab::WobbleSuppressorBase::setMotions,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::WobbleSuppressorBase::*)() const>("motions", &cv::videostab::WobbleSuppressorBase::motions).
    define_method<void(cv::videostab::WobbleSuppressorBase::*)(const std::vector<cv::Mat>&)>("set_motions2", &cv::videostab::WobbleSuppressorBase::setMotions2,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::WobbleSuppressorBase::*)() const>("motions2", &cv::videostab::WobbleSuppressorBase::motions2).
    define_method<void(cv::videostab::WobbleSuppressorBase::*)(const std::vector<cv::Mat>&)>("set_stabilization_motions", &cv::videostab::WobbleSuppressorBase::setStabilizationMotions,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::WobbleSuppressorBase::*)() const>("stabilization_motions", &cv::videostab::WobbleSuppressorBase::stabilizationMotions);

  Rice::Data_Type<cv::videostab::NullWobbleSuppressor> rb_cCvVideostabNullWobbleSuppressor = define_class_under<cv::videostab::NullWobbleSuppressor, cv::videostab::WobbleSuppressorBase>(rb_mCvVideostab, "NullWobbleSuppressor").
    define_constructor(Constructor<cv::videostab::NullWobbleSuppressor>()).
    define_method<void(cv::videostab::NullWobbleSuppressor::*)(int, const cv::Mat&, cv::Mat&)>("suppress", &cv::videostab::NullWobbleSuppressor::suppress,
      Arg("idx"), Arg("frame"), Arg("result"));

  Rice::Data_Type<cv::videostab::MoreAccurateMotionWobbleSuppressorBase> rb_cCvVideostabMoreAccurateMotionWobbleSuppressorBase = define_class_under<cv::videostab::MoreAccurateMotionWobbleSuppressorBase, cv::videostab::WobbleSuppressorBase>(rb_mCvVideostab, "MoreAccurateMotionWobbleSuppressorBase").
    define_method<void(cv::videostab::MoreAccurateMotionWobbleSuppressorBase::*)(int)>("set_period", &cv::videostab::MoreAccurateMotionWobbleSuppressorBase::setPeriod,
      Arg("val")).
    define_method<int(cv::videostab::MoreAccurateMotionWobbleSuppressorBase::*)() const>("period", &cv::videostab::MoreAccurateMotionWobbleSuppressorBase::period);

  Rice::Data_Type<cv::videostab::MoreAccurateMotionWobbleSuppressor> rb_cCvVideostabMoreAccurateMotionWobbleSuppressor = define_class_under<cv::videostab::MoreAccurateMotionWobbleSuppressor, cv::videostab::MoreAccurateMotionWobbleSuppressorBase>(rb_mCvVideostab, "MoreAccurateMotionWobbleSuppressor").
    define_constructor(Constructor<cv::videostab::MoreAccurateMotionWobbleSuppressor>()).
    define_method<void(cv::videostab::MoreAccurateMotionWobbleSuppressor::*)(int, const cv::Mat&, cv::Mat&)>("suppress", &cv::videostab::MoreAccurateMotionWobbleSuppressor::suppress,
      Arg("idx"), Arg("frame"), Arg("result"));

  Rice::Data_Type<cv::videostab::MoreAccurateMotionWobbleSuppressorGpu> rb_cCvVideostabMoreAccurateMotionWobbleSuppressorGpu = define_class_under<cv::videostab::MoreAccurateMotionWobbleSuppressorGpu, cv::videostab::MoreAccurateMotionWobbleSuppressorBase>(rb_mCvVideostab, "MoreAccurateMotionWobbleSuppressorGpu").
    define_constructor(Constructor<cv::videostab::MoreAccurateMotionWobbleSuppressorGpu>()).
    define_method<void(cv::videostab::MoreAccurateMotionWobbleSuppressorGpu::*)(int, const cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("suppress", &cv::videostab::MoreAccurateMotionWobbleSuppressorGpu::suppress,
      Arg("idx"), Arg("frame"), Arg("result")).
    define_method<void(cv::videostab::MoreAccurateMotionWobbleSuppressorGpu::*)(int, const cv::Mat&, cv::Mat&)>("suppress", &cv::videostab::MoreAccurateMotionWobbleSuppressorGpu::suppress,
      Arg("idx"), Arg("frame"), Arg("result"));
}