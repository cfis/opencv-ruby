#include <opencv2/cudabgsegm.hpp>
#include "cudabgsegm-rb.hpp"

using namespace Rice;

void Init_Cudabgsegm()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::BackgroundSubtractorMOG> rb_cCvCudaBackgroundSubtractorMOG = define_class_under<cv::cuda::BackgroundSubtractorMOG, cv::BackgroundSubtractor>(rb_mCvCuda, "BackgroundSubtractorMOG").
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(cv::InputArray, cv::OutputArray, double, cv::cuda::Stream&)>("apply", &cv::cuda::BackgroundSubtractorMOG::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate"), Arg("stream")).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(cv::OutputArray, cv::cuda::Stream&) const>("get_background_image", &cv::cuda::BackgroundSubtractorMOG::getBackgroundImage,
      Arg("background_image"), Arg("stream")).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(cv::cuda::GpuMat&, cv::cuda::Stream&)>("get_background_image", &cv::cuda::BackgroundSubtractorMOG::getBackgroundImage,
      Arg("background_image"), Arg("stream")).
    define_method<int(cv::cuda::BackgroundSubtractorMOG::*)() const>("get_history", &cv::cuda::BackgroundSubtractorMOG::getHistory).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(int)>("set_history", &cv::cuda::BackgroundSubtractorMOG::setHistory,
      Arg("nframes")).
    define_method<int(cv::cuda::BackgroundSubtractorMOG::*)() const>("get_n_mixtures", &cv::cuda::BackgroundSubtractorMOG::getNMixtures).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(int)>("set_n_mixtures", &cv::cuda::BackgroundSubtractorMOG::setNMixtures,
      Arg("nmix")).
    define_method<double(cv::cuda::BackgroundSubtractorMOG::*)() const>("get_background_ratio", &cv::cuda::BackgroundSubtractorMOG::getBackgroundRatio).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(double)>("set_background_ratio", &cv::cuda::BackgroundSubtractorMOG::setBackgroundRatio,
      Arg("background_ratio")).
    define_method<double(cv::cuda::BackgroundSubtractorMOG::*)() const>("get_noise_sigma", &cv::cuda::BackgroundSubtractorMOG::getNoiseSigma).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(double)>("set_noise_sigma", &cv::cuda::BackgroundSubtractorMOG::setNoiseSigma,
      Arg("noise_sigma"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::BackgroundSubtractorMOG>(*)(int, int, double, double)>("create_background_subtractor_mog", &cv::cuda::createBackgroundSubtractorMOG,
    Arg("history") = static_cast<int>(200), Arg("nmixtures") = static_cast<int>(5), Arg("background_ratio") = static_cast<double>(0.7), Arg("noise_sigma") = static_cast<double>(0));

  Rice::Data_Type<cv::cuda::BackgroundSubtractorMOG2> rb_cCvCudaBackgroundSubtractorMOG2 = define_class_under<cv::cuda::BackgroundSubtractorMOG2, cv::BackgroundSubtractorMOG2>(rb_mCvCuda, "BackgroundSubtractorMOG2").
    define_method<void(cv::cuda::BackgroundSubtractorMOG2::*)(cv::InputArray, cv::OutputArray, double, cv::cuda::Stream&)>("apply", &cv::cuda::BackgroundSubtractorMOG2::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate"), Arg("stream")).
    define_method<void(cv::cuda::BackgroundSubtractorMOG2::*)(cv::OutputArray, cv::cuda::Stream&) const>("get_background_image", &cv::cuda::BackgroundSubtractorMOG2::getBackgroundImage,
      Arg("background_image"), Arg("stream")).
    define_method<void(cv::cuda::BackgroundSubtractorMOG2::*)(cv::cuda::GpuMat&, cv::cuda::Stream&)>("get_background_image", &cv::cuda::BackgroundSubtractorMOG2::getBackgroundImage,
      Arg("background_image"), Arg("stream"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::BackgroundSubtractorMOG2>(*)(int, double, bool)>("create_background_subtractor_mog2", &cv::cuda::createBackgroundSubtractorMOG2,
    Arg("history") = static_cast<int>(500), Arg("var_threshold") = static_cast<double>(16), Arg("detect_shadows") = static_cast<bool>(true));
}
