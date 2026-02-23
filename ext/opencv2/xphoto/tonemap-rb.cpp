#include <opencv2/xphoto/tonemap.hpp>
#include "tonemap-rb.hpp"

using namespace Rice;

void Init_Xphoto_Tonemap()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");

  Rice::Data_Type<cv::xphoto::TonemapDurand> rb_cCvXphotoTonemapDurand = define_class_under<cv::xphoto::TonemapDurand, cv::Tonemap>(rb_mCvXphoto, "TonemapDurand").
    define_method<float(cv::xphoto::TonemapDurand::*)() const>("get_saturation", &cv::xphoto::TonemapDurand::getSaturation).
    define_method<void(cv::xphoto::TonemapDurand::*)(float)>("set_saturation", &cv::xphoto::TonemapDurand::setSaturation,
      Arg("saturation")).
    define_method<float(cv::xphoto::TonemapDurand::*)() const>("get_contrast", &cv::xphoto::TonemapDurand::getContrast).
    define_method<void(cv::xphoto::TonemapDurand::*)(float)>("set_contrast", &cv::xphoto::TonemapDurand::setContrast,
      Arg("contrast")).
    define_method<float(cv::xphoto::TonemapDurand::*)() const>("get_sigma_space", &cv::xphoto::TonemapDurand::getSigmaSpace).
    define_method<void(cv::xphoto::TonemapDurand::*)(float)>("set_sigma_space", &cv::xphoto::TonemapDurand::setSigmaSpace,
      Arg("sigma_space")).
    define_method<float(cv::xphoto::TonemapDurand::*)() const>("get_sigma_color", &cv::xphoto::TonemapDurand::getSigmaColor).
    define_method<void(cv::xphoto::TonemapDurand::*)(float)>("set_sigma_color", &cv::xphoto::TonemapDurand::setSigmaColor,
      Arg("sigma_color"));

  rb_mCvXphoto.define_module_function<cv::Ptr<cv::xphoto::TonemapDurand>(*)(float, float, float, float, float)>("create_tonemap_durand", &cv::xphoto::createTonemapDurand,
    Arg("gamma") = static_cast<float>(1.0f), Arg("contrast") = static_cast<float>(4.0f), Arg("saturation") = static_cast<float>(1.0f), Arg("sigma_color") = static_cast<float>(2.0f), Arg("sigma_space") = static_cast<float>(2.0f));
}
