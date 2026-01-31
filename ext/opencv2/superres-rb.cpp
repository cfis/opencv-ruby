#include <opencv2/superres.hpp>
#include "superres-rb.hpp"

using namespace Rice;

void Init_Superres()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvSuperres = define_module_under(rb_mCv, "Superres");

  Rice::Data_Type<cv::superres::FrameSource> rb_cCvSuperresFrameSource = define_class_under<cv::superres::FrameSource>(rb_mCvSuperres, "FrameSource").
    define_method<void(cv::superres::FrameSource::*)(cv::OutputArray)>("next_frame", &cv::superres::FrameSource::nextFrame,
      Arg("frame")).
    define_method<void(cv::superres::FrameSource::*)()>("reset", &cv::superres::FrameSource::reset);

  rb_mCvSuperres.define_module_function<cv::Ptr<cv::superres::FrameSource>(*)()>("create_frame_source_empty", &cv::superres::createFrameSource_Empty);

  rb_mCvSuperres.define_module_function<cv::Ptr<cv::superres::FrameSource>(*)(const cv::String&)>("create_frame_source_video", &cv::superres::createFrameSource_Video,
    Arg("file_name"));

  rb_mCvSuperres.define_module_function<cv::Ptr<cv::superres::FrameSource>(*)(const cv::String&)>("create_frame_source_video_cuda", &cv::superres::createFrameSource_Video_CUDA,
    Arg("file_name"));

  rb_mCvSuperres.define_module_function<cv::Ptr<cv::superres::FrameSource>(*)(int)>("create_frame_source_camera", &cv::superres::createFrameSource_Camera,
    Arg("device_id") = static_cast<int>(0));

  Rice::Data_Type<cv::superres::SuperResolution> rb_cCvSuperresSuperResolution = define_class_under<cv::superres::SuperResolution, cv::Algorithm>(rb_mCvSuperres, "SuperResolution").
    define_method<void(cv::superres::SuperResolution::*)(const cv::Ptr<cv::superres::FrameSource>&)>("set_input", &cv::superres::SuperResolution::setInput,
      Arg("frame_source")).
    define_method<void(cv::superres::SuperResolution::*)(cv::OutputArray)>("next_frame", &cv::superres::SuperResolution::nextFrame,
      Arg("frame")).
    define_method<void(cv::superres::SuperResolution::*)()>("reset", &cv::superres::SuperResolution::reset).
    define_method<void(cv::superres::SuperResolution::*)()>("collect_garbage", &cv::superres::SuperResolution::collectGarbage).
    define_method<int(cv::superres::SuperResolution::*)() const>("get_scale", &cv::superres::SuperResolution::getScale).
    define_method<void(cv::superres::SuperResolution::*)(int)>("set_scale", &cv::superres::SuperResolution::setScale,
      Arg("val")).
    define_method<int(cv::superres::SuperResolution::*)() const>("get_iterations", &cv::superres::SuperResolution::getIterations).
    define_method<void(cv::superres::SuperResolution::*)(int)>("set_iterations", &cv::superres::SuperResolution::setIterations,
      Arg("val")).
    define_method<double(cv::superres::SuperResolution::*)() const>("get_tau", &cv::superres::SuperResolution::getTau).
    define_method<void(cv::superres::SuperResolution::*)(double)>("set_tau", &cv::superres::SuperResolution::setTau,
      Arg("val")).
    define_method<double(cv::superres::SuperResolution::*)() const>("get_lambda", &cv::superres::SuperResolution::getLambda).
    define_method<void(cv::superres::SuperResolution::*)(double)>("set_lambda", &cv::superres::SuperResolution::setLambda,
      Arg("val")).
    define_method<double(cv::superres::SuperResolution::*)() const>("get_alpha", &cv::superres::SuperResolution::getAlpha).
    define_method<void(cv::superres::SuperResolution::*)(double)>("set_alpha", &cv::superres::SuperResolution::setAlpha,
      Arg("val")).
    define_method<int(cv::superres::SuperResolution::*)() const>("get_kernel_size", &cv::superres::SuperResolution::getKernelSize).
    define_method<void(cv::superres::SuperResolution::*)(int)>("set_kernel_size", &cv::superres::SuperResolution::setKernelSize,
      Arg("val")).
    define_method<int(cv::superres::SuperResolution::*)() const>("get_blur_kernel_size", &cv::superres::SuperResolution::getBlurKernelSize).
    define_method<void(cv::superres::SuperResolution::*)(int)>("set_blur_kernel_size", &cv::superres::SuperResolution::setBlurKernelSize,
      Arg("val")).
    define_method<double(cv::superres::SuperResolution::*)() const>("get_blur_sigma", &cv::superres::SuperResolution::getBlurSigma).
    define_method<void(cv::superres::SuperResolution::*)(double)>("set_blur_sigma", &cv::superres::SuperResolution::setBlurSigma,
      Arg("val")).
    define_method<int(cv::superres::SuperResolution::*)() const>("get_temporal_area_radius", &cv::superres::SuperResolution::getTemporalAreaRadius).
    define_method<void(cv::superres::SuperResolution::*)(int)>("set_temporal_area_radius", &cv::superres::SuperResolution::setTemporalAreaRadius,
      Arg("val")).
    define_method<cv::Ptr<cv::superres::DenseOpticalFlowExt>(cv::superres::SuperResolution::*)() const>("get_optical_flow", &cv::superres::SuperResolution::getOpticalFlow).
    define_method<void(cv::superres::SuperResolution::*)(const cv::Ptr<cv::superres::DenseOpticalFlowExt>&)>("set_optical_flow", &cv::superres::SuperResolution::setOpticalFlow,
      Arg("val"));

  rb_mCvSuperres.define_module_function<cv::Ptr<cv::superres::SuperResolution>(*)()>("create_super_resolution_btvl1", &cv::superres::createSuperResolution_BTVL1);

  rb_mCvSuperres.define_module_function<cv::Ptr<cv::superres::SuperResolution>(*)()>("create_super_resolution_btvl1_cuda", &cv::superres::createSuperResolution_BTVL1_CUDA);
}