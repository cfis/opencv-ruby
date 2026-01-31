#include <opencv2/videostab/inpainting.hpp>
#include "inpainting-rb.hpp"

using namespace Rice;

void Init_Videostab_Inpainting()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  Rice::Data_Type<cv::videostab::InpainterBase> rb_cCvVideostabInpainterBase = define_class_under<cv::videostab::InpainterBase>(rb_mCvVideostab, "InpainterBase").
    define_method<void(cv::videostab::InpainterBase::*)(int)>("set_radius", &cv::videostab::InpainterBase::setRadius,
      Arg("val")).
    define_method<int(cv::videostab::InpainterBase::*)() const>("radius", &cv::videostab::InpainterBase::radius).
    define_method<void(cv::videostab::InpainterBase::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::InpainterBase::setMotionModel,
      Arg("val")).
    define_method<cv::videostab::MotionModel(cv::videostab::InpainterBase::*)() const>("motion_model", &cv::videostab::InpainterBase::motionModel).
    define_method<void(cv::videostab::InpainterBase::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::InpainterBase::inpaint,
      Arg("idx"), Arg("frame"), Arg("mask")).
    define_method<void(cv::videostab::InpainterBase::*)(const std::vector<cv::Mat>&)>("set_frames", &cv::videostab::InpainterBase::setFrames,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::InpainterBase::*)() const>("frames", &cv::videostab::InpainterBase::frames).
    define_method<void(cv::videostab::InpainterBase::*)(const std::vector<cv::Mat>&)>("set_motions", &cv::videostab::InpainterBase::setMotions,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::InpainterBase::*)() const>("motions", &cv::videostab::InpainterBase::motions).
    define_method<void(cv::videostab::InpainterBase::*)(const std::vector<cv::Mat>&)>("set_stabilized_frames", &cv::videostab::InpainterBase::setStabilizedFrames,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::InpainterBase::*)() const>("stabilized_frames", &cv::videostab::InpainterBase::stabilizedFrames).
    define_method<void(cv::videostab::InpainterBase::*)(const std::vector<cv::Mat>&)>("set_stabilization_motions", &cv::videostab::InpainterBase::setStabilizationMotions,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::InpainterBase::*)() const>("stabilization_motions", &cv::videostab::InpainterBase::stabilizationMotions);

  Rice::Data_Type<cv::videostab::NullInpainter> rb_cCvVideostabNullInpainter = define_class_under<cv::videostab::NullInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "NullInpainter").
    define_constructor(Constructor<cv::videostab::NullInpainter>()).
    define_method<void(cv::videostab::NullInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::NullInpainter::inpaint,
      Arg("arg_0"), Arg("arg_1"), Arg("arg_2"));

  Rice::Data_Type<cv::videostab::InpaintingPipeline> rb_cCvVideostabInpaintingPipeline = define_class_under<cv::videostab::InpaintingPipeline, cv::videostab::InpainterBase>(rb_mCvVideostab, "InpaintingPipeline").
    define_constructor(Constructor<cv::videostab::InpaintingPipeline>()).
    define_method<void(cv::videostab::InpaintingPipeline::*)(cv::Ptr<cv::videostab::InpainterBase>)>("push_back", &cv::videostab::InpaintingPipeline::pushBack,
      Arg("inpainter")).
    define_method<bool(cv::videostab::InpaintingPipeline::*)() const>("empty?", &cv::videostab::InpaintingPipeline::empty).
    define_method<void(cv::videostab::InpaintingPipeline::*)(int)>("set_radius", &cv::videostab::InpaintingPipeline::setRadius,
      Arg("val")).
    define_method<void(cv::videostab::InpaintingPipeline::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::InpaintingPipeline::setMotionModel,
      Arg("val")).
    define_method<void(cv::videostab::InpaintingPipeline::*)(const std::vector<cv::Mat>&)>("set_frames", &cv::videostab::InpaintingPipeline::setFrames,
      Arg("val")).
    define_method<void(cv::videostab::InpaintingPipeline::*)(const std::vector<cv::Mat>&)>("set_motions", &cv::videostab::InpaintingPipeline::setMotions,
      Arg("val")).
    define_method<void(cv::videostab::InpaintingPipeline::*)(const std::vector<cv::Mat>&)>("set_stabilized_frames", &cv::videostab::InpaintingPipeline::setStabilizedFrames,
      Arg("val")).
    define_method<void(cv::videostab::InpaintingPipeline::*)(const std::vector<cv::Mat>&)>("set_stabilization_motions", &cv::videostab::InpaintingPipeline::setStabilizationMotions,
      Arg("val")).
    define_method<void(cv::videostab::InpaintingPipeline::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::InpaintingPipeline::inpaint,
      Arg("idx"), Arg("frame"), Arg("mask"));

  Rice::Data_Type<cv::videostab::ConsistentMosaicInpainter> rb_cCvVideostabConsistentMosaicInpainter = define_class_under<cv::videostab::ConsistentMosaicInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "ConsistentMosaicInpainter").
    define_constructor(Constructor<cv::videostab::ConsistentMosaicInpainter>()).
    define_method<void(cv::videostab::ConsistentMosaicInpainter::*)(float)>("set_stdev_thresh", &cv::videostab::ConsistentMosaicInpainter::setStdevThresh,
      Arg("val")).
    define_method<float(cv::videostab::ConsistentMosaicInpainter::*)() const>("stdev_thresh", &cv::videostab::ConsistentMosaicInpainter::stdevThresh).
    define_method<void(cv::videostab::ConsistentMosaicInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::ConsistentMosaicInpainter::inpaint,
      Arg("idx"), Arg("frame"), Arg("mask"));

  Rice::Data_Type<cv::videostab::MotionInpainter> rb_cCvVideostabMotionInpainter = define_class_under<cv::videostab::MotionInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "MotionInpainter").
    define_constructor(Constructor<cv::videostab::MotionInpainter>()).
    define_method<void(cv::videostab::MotionInpainter::*)(cv::Ptr<cv::videostab::IDenseOptFlowEstimator>)>("set_opt_flow_estimator", &cv::videostab::MotionInpainter::setOptFlowEstimator,
      Arg("val")).
    define_method<cv::Ptr<cv::videostab::IDenseOptFlowEstimator>(cv::videostab::MotionInpainter::*)() const>("opt_flow_estimator", &cv::videostab::MotionInpainter::optFlowEstimator).
    define_method<void(cv::videostab::MotionInpainter::*)(float)>("set_flow_error_threshold", &cv::videostab::MotionInpainter::setFlowErrorThreshold,
      Arg("val")).
    define_method<float(cv::videostab::MotionInpainter::*)() const>("flow_error_threshold", &cv::videostab::MotionInpainter::flowErrorThreshold).
    define_method<void(cv::videostab::MotionInpainter::*)(float)>("set_dist_threshold", &cv::videostab::MotionInpainter::setDistThreshold,
      Arg("val")).
    define_method<float(cv::videostab::MotionInpainter::*)() const>("dist_thresh", &cv::videostab::MotionInpainter::distThresh).
    define_method<void(cv::videostab::MotionInpainter::*)(int)>("set_border_mode", &cv::videostab::MotionInpainter::setBorderMode,
      Arg("val")).
    define_method<int(cv::videostab::MotionInpainter::*)() const>("border_mode", &cv::videostab::MotionInpainter::borderMode).
    define_method<void(cv::videostab::MotionInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::MotionInpainter::inpaint,
      Arg("idx"), Arg("frame"), Arg("mask"));

  Rice::Data_Type<cv::videostab::ColorAverageInpainter> rb_cCvVideostabColorAverageInpainter = define_class_under<cv::videostab::ColorAverageInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "ColorAverageInpainter").
    define_constructor(Constructor<cv::videostab::ColorAverageInpainter>()).
    define_method<void(cv::videostab::ColorAverageInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::ColorAverageInpainter::inpaint,
      Arg("idx"), Arg("frame"), Arg("mask"));

  Rice::Data_Type<cv::videostab::ColorInpainter> rb_cCvVideostabColorInpainter = define_class_under<cv::videostab::ColorInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "ColorInpainter").
    define_constructor(Constructor<cv::videostab::ColorInpainter, int, double>(),
      Arg("method") = static_cast<int>(cv::INPAINT_TELEA), Arg("radius") = static_cast<double>(2.)).
    define_method<void(cv::videostab::ColorInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::ColorInpainter::inpaint,
      Arg("idx"), Arg("frame"), Arg("mask"));

  rb_mCvVideostab.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, float, const cv::Mat&, const cv::Mat&, cv::Mat&)>("calc_flow_mask", &cv::videostab::calcFlowMask,
    Arg("flow_x"), Arg("flow_y"), Arg("errors"), Arg("max_error"), Arg("mask0"), Arg("mask1"), Arg("flow_mask"));

  rb_mCvVideostab.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, float, cv::Mat&, cv::Mat&)>("complete_frame_according_to_flow", &cv::videostab::completeFrameAccordingToFlow,
    Arg("flow_mask"), Arg("flow_x"), Arg("flow_y"), Arg("frame1"), Arg("mask1"), Arg("dist_thresh"), Arg("frame0"), Arg("mask0"));
}