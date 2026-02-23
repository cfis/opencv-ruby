#include <opencv2/saliency/saliencySpecializedClasses.hpp>
#include "saliencySpecializedClasses-rb.hpp"

using namespace Rice;

void Init_Saliency_SaliencySpecializedClasses()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvSaliency = define_module_under(rb_mCv, "Saliency");

  Rice::Data_Type<cv::saliency::StaticSaliencySpectralResidual> rb_cCvSaliencyStaticSaliencySpectralResidual = define_class_under<cv::saliency::StaticSaliencySpectralResidual, cv::saliency::StaticSaliency>(rb_mCvSaliency, "StaticSaliencySpectralResidual").
    define_constructor(Constructor<cv::saliency::StaticSaliencySpectralResidual>()).
    define_singleton_function<cv::Ptr<cv::saliency::StaticSaliencySpectralResidual>(*)()>("create", &cv::saliency::StaticSaliencySpectralResidual::create).
    define_method<bool(cv::saliency::StaticSaliencySpectralResidual::*)(cv::InputArray, cv::OutputArray)>("compute_saliency", &cv::saliency::StaticSaliencySpectralResidual::computeSaliency,
      Arg("image"), Arg("saliency_map")).
    define_method<void(cv::saliency::StaticSaliencySpectralResidual::*)(const cv::FileNode&)>("read", &cv::saliency::StaticSaliencySpectralResidual::read,
      Arg("fn")).
    define_method<void(cv::saliency::StaticSaliencySpectralResidual::*)(cv::FileStorage&) const>("write", &cv::saliency::StaticSaliencySpectralResidual::write,
      Arg("fs")).
    define_method<int(cv::saliency::StaticSaliencySpectralResidual::*)() const>("get_image_width", &cv::saliency::StaticSaliencySpectralResidual::getImageWidth).
    define_method<void(cv::saliency::StaticSaliencySpectralResidual::*)(int)>("set_image_width", &cv::saliency::StaticSaliencySpectralResidual::setImageWidth,
      Arg("val")).
    define_method<int(cv::saliency::StaticSaliencySpectralResidual::*)() const>("get_image_height", &cv::saliency::StaticSaliencySpectralResidual::getImageHeight).
    define_method<void(cv::saliency::StaticSaliencySpectralResidual::*)(int)>("set_image_height", &cv::saliency::StaticSaliencySpectralResidual::setImageHeight,
      Arg("val"));

  Rice::Data_Type<cv::saliency::StaticSaliencyFineGrained> rb_cCvSaliencyStaticSaliencyFineGrained = define_class_under<cv::saliency::StaticSaliencyFineGrained, cv::saliency::StaticSaliency>(rb_mCvSaliency, "StaticSaliencyFineGrained").
    define_constructor(Constructor<cv::saliency::StaticSaliencyFineGrained>()).
    define_singleton_function<cv::Ptr<cv::saliency::StaticSaliencyFineGrained>(*)()>("create", &cv::saliency::StaticSaliencyFineGrained::create).
    define_method<bool(cv::saliency::StaticSaliencyFineGrained::*)(cv::InputArray, cv::OutputArray)>("compute_saliency", &cv::saliency::StaticSaliencyFineGrained::computeSaliency,
      Arg("image"), Arg("saliency_map"));

  Rice::Data_Type<cv::saliency::MotionSaliencyBinWangApr2014> rb_cCvSaliencyMotionSaliencyBinWangApr2014 = define_class_under<cv::saliency::MotionSaliencyBinWangApr2014, cv::saliency::MotionSaliency>(rb_mCvSaliency, "MotionSaliencyBinWangApr2014").
    define_constructor(Constructor<cv::saliency::MotionSaliencyBinWangApr2014>()).
    define_singleton_function<cv::Ptr<cv::saliency::MotionSaliencyBinWangApr2014>(*)()>("create", &cv::saliency::MotionSaliencyBinWangApr2014::create).
    define_method<bool(cv::saliency::MotionSaliencyBinWangApr2014::*)(cv::InputArray, cv::OutputArray)>("compute_saliency", &cv::saliency::MotionSaliencyBinWangApr2014::computeSaliency,
      Arg("image"), Arg("saliency_map")).
    define_method<void(cv::saliency::MotionSaliencyBinWangApr2014::*)(int, int)>("set_imagesize", &cv::saliency::MotionSaliencyBinWangApr2014::setImagesize,
      Arg("w"), Arg("h")).
    define_method<bool(cv::saliency::MotionSaliencyBinWangApr2014::*)()>("init?", &cv::saliency::MotionSaliencyBinWangApr2014::init).
    define_method<int(cv::saliency::MotionSaliencyBinWangApr2014::*)() const>("get_image_width", &cv::saliency::MotionSaliencyBinWangApr2014::getImageWidth).
    define_method<void(cv::saliency::MotionSaliencyBinWangApr2014::*)(int)>("set_image_width", &cv::saliency::MotionSaliencyBinWangApr2014::setImageWidth,
      Arg("val")).
    define_method<int(cv::saliency::MotionSaliencyBinWangApr2014::*)() const>("get_image_height", &cv::saliency::MotionSaliencyBinWangApr2014::getImageHeight).
    define_method<void(cv::saliency::MotionSaliencyBinWangApr2014::*)(int)>("set_image_height", &cv::saliency::MotionSaliencyBinWangApr2014::setImageHeight,
      Arg("val"));

  Rice::Data_Type<cv::saliency::ObjectnessBING> rb_cCvSaliencyObjectnessBING = define_class_under<cv::saliency::ObjectnessBING, cv::saliency::Objectness>(rb_mCvSaliency, "ObjectnessBING").
    define_constructor(Constructor<cv::saliency::ObjectnessBING>()).
    define_singleton_function<cv::Ptr<cv::saliency::ObjectnessBING>(*)()>("create", &cv::saliency::ObjectnessBING::create).
    define_method<bool(cv::saliency::ObjectnessBING::*)(cv::InputArray, cv::OutputArray)>("compute_saliency", &cv::saliency::ObjectnessBING::computeSaliency,
      Arg("image"), Arg("saliency_map")).
    define_method<void(cv::saliency::ObjectnessBING::*)()>("read", &cv::saliency::ObjectnessBING::read).
    define_method<void(cv::saliency::ObjectnessBING::*)() const>("write", &cv::saliency::ObjectnessBING::write).
    define_method<std::vector<float>(cv::saliency::ObjectnessBING::*)()>("getobjectness_values", &cv::saliency::ObjectnessBING::getobjectnessValues).
    define_method<void(cv::saliency::ObjectnessBING::*)(const cv::String&)>("set_training_path", &cv::saliency::ObjectnessBING::setTrainingPath,
      Arg("training_path")).
    define_method<void(cv::saliency::ObjectnessBING::*)(const cv::String&)>("set_bb_res_dir", &cv::saliency::ObjectnessBING::setBBResDir,
      Arg("results_dir")).
    define_method<double(cv::saliency::ObjectnessBING::*)() const>("get_base", &cv::saliency::ObjectnessBING::getBase).
    define_method<void(cv::saliency::ObjectnessBING::*)(double)>("set_base", &cv::saliency::ObjectnessBING::setBase,
      Arg("val")).
    define_method<int(cv::saliency::ObjectnessBING::*)() const>("get_nss", &cv::saliency::ObjectnessBING::getNSS).
    define_method<void(cv::saliency::ObjectnessBING::*)(int)>("set_nss", &cv::saliency::ObjectnessBING::setNSS,
      Arg("val")).
    define_method<int(cv::saliency::ObjectnessBING::*)() const>("get_w", &cv::saliency::ObjectnessBING::getW).
    define_method<void(cv::saliency::ObjectnessBING::*)(int)>("set_w", &cv::saliency::ObjectnessBING::setW,
      Arg("val"));
}
