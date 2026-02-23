#include <opencv2/videostab/stabilizer.hpp>
#include "stabilizer-rb.hpp"

using namespace Rice;

void Init_Videostab_Stabilizer()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  Rice::Data_Type<cv::videostab::StabilizerBase> rb_cCvVideostabStabilizerBase = define_class_under<cv::videostab::StabilizerBase>(rb_mCvVideostab, "StabilizerBase").
    define_method<void(cv::videostab::StabilizerBase::*)(cv::Ptr<cv::videostab::ILog>)>("set_log", &cv::videostab::StabilizerBase::setLog,
      Arg("ilog")).
    define_method<cv::Ptr<cv::videostab::ILog>(cv::videostab::StabilizerBase::*)() const>("log", &cv::videostab::StabilizerBase::log).
    define_method<void(cv::videostab::StabilizerBase::*)(int)>("set_radius", &cv::videostab::StabilizerBase::setRadius,
      Arg("val")).
    define_method<int(cv::videostab::StabilizerBase::*)() const>("radius", &cv::videostab::StabilizerBase::radius).
    define_method<void(cv::videostab::StabilizerBase::*)(cv::Ptr<cv::videostab::IFrameSource>)>("set_frame_source", &cv::videostab::StabilizerBase::setFrameSource,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::IFrameSource>(cv::videostab::StabilizerBase::*)() const>("frame_source", &cv::videostab::StabilizerBase::frameSource).
    define_method<void(cv::videostab::StabilizerBase::*)(const cv::Ptr<cv::videostab::IFrameSource>&)>("set_mask_source", &cv::videostab::StabilizerBase::setMaskSource,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::IFrameSource>(cv::videostab::StabilizerBase::*)() const>("mask_source", &cv::videostab::StabilizerBase::maskSource).
    define_method<void(cv::videostab::StabilizerBase::*)(cv::Ptr<cv::videostab::ImageMotionEstimatorBase>)>("set_motion_estimator", &cv::videostab::StabilizerBase::setMotionEstimator,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::ImageMotionEstimatorBase>(cv::videostab::StabilizerBase::*)() const>("motion_estimator", &cv::videostab::StabilizerBase::motionEstimator).
    define_method<void(cv::videostab::StabilizerBase::*)(cv::Ptr<cv::videostab::DeblurerBase>)>("set_deblurer", &cv::videostab::StabilizerBase::setDeblurer,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::DeblurerBase>(cv::videostab::StabilizerBase::*)() const>("deblurrer", &cv::videostab::StabilizerBase::deblurrer).
    define_method<void(cv::videostab::StabilizerBase::*)(float)>("set_trim_ratio", &cv::videostab::StabilizerBase::setTrimRatio,
      Arg("val")).
    define_method<float(cv::videostab::StabilizerBase::*)() const>("trim_ratio", &cv::videostab::StabilizerBase::trimRatio).
    define_method<void(cv::videostab::StabilizerBase::*)(bool)>("set_correction_for_inclusion", &cv::videostab::StabilizerBase::setCorrectionForInclusion,
      Arg("val")).
    define_method<bool(cv::videostab::StabilizerBase::*)() const>("do_correction_for_inclusion?", &cv::videostab::StabilizerBase::doCorrectionForInclusion).
    define_method<void(cv::videostab::StabilizerBase::*)(int)>("set_border_mode", &cv::videostab::StabilizerBase::setBorderMode,
      Arg("val")).
    define_method<int(cv::videostab::StabilizerBase::*)() const>("border_mode", &cv::videostab::StabilizerBase::borderMode).
    define_method<void(cv::videostab::StabilizerBase::*)(cv::Ptr<cv::videostab::InpainterBase>)>("set_inpainter", &cv::videostab::StabilizerBase::setInpainter,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::InpainterBase>(cv::videostab::StabilizerBase::*)() const>("inpainter", &cv::videostab::StabilizerBase::inpainter);

  Rice::Data_Type<cv::videostab::OnePassStabilizer> rb_cCvVideostabOnePassStabilizer = define_class_under<cv::videostab::OnePassStabilizer, cv::videostab::StabilizerBase>(rb_mCvVideostab, "OnePassStabilizer").
    define_constructor(Constructor<cv::videostab::OnePassStabilizer>()).
    define_method<void(cv::videostab::OnePassStabilizer::*)(cv::Ptr<cv::videostab::MotionFilterBase>)>("set_motion_filter", &cv::videostab::OnePassStabilizer::setMotionFilter,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::MotionFilterBase>(cv::videostab::OnePassStabilizer::*)() const>("motion_filter", &cv::videostab::OnePassStabilizer::motionFilter).
    define_method<void(cv::videostab::OnePassStabilizer::*)()>("reset", &cv::videostab::OnePassStabilizer::reset).
    define_method<cv::Mat(cv::videostab::OnePassStabilizer::*)()>("next_frame", &cv::videostab::OnePassStabilizer::nextFrame);

  Rice::Data_Type<cv::videostab::TwoPassStabilizer> rb_cCvVideostabTwoPassStabilizer = define_class_under<cv::videostab::TwoPassStabilizer, cv::videostab::StabilizerBase>(rb_mCvVideostab, "TwoPassStabilizer").
    define_constructor(Constructor<cv::videostab::TwoPassStabilizer>()).
    define_method<void(cv::videostab::TwoPassStabilizer::*)(cv::Ptr<cv::videostab::IMotionStabilizer>)>("set_motion_stabilizer", &cv::videostab::TwoPassStabilizer::setMotionStabilizer,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::IMotionStabilizer>(cv::videostab::TwoPassStabilizer::*)() const>("motion_stabilizer", &cv::videostab::TwoPassStabilizer::motionStabilizer).
    define_method<void(cv::videostab::TwoPassStabilizer::*)(cv::Ptr<cv::videostab::WobbleSuppressorBase>)>("set_wobble_suppressor", &cv::videostab::TwoPassStabilizer::setWobbleSuppressor,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::WobbleSuppressorBase>(cv::videostab::TwoPassStabilizer::*)() const>("wobble_suppressor", &cv::videostab::TwoPassStabilizer::wobbleSuppressor).
    define_method<void(cv::videostab::TwoPassStabilizer::*)(bool)>("set_estimate_trim_ratio", &cv::videostab::TwoPassStabilizer::setEstimateTrimRatio,
      Arg("val")).
    define_method<bool(cv::videostab::TwoPassStabilizer::*)() const>("must_estimate_trima_ratio?", &cv::videostab::TwoPassStabilizer::mustEstimateTrimaRatio).
    define_method<void(cv::videostab::TwoPassStabilizer::*)()>("reset", &cv::videostab::TwoPassStabilizer::reset).
    define_method<cv::Mat(cv::videostab::TwoPassStabilizer::*)()>("next_frame", &cv::videostab::TwoPassStabilizer::nextFrame);
}
