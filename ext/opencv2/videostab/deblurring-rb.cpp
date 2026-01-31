#include <opencv2/videostab/deblurring.hpp>
#include "deblurring-rb.hpp"

using namespace Rice;

void Init_Videostab_Deblurring()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  rb_mCvVideostab.define_module_function<float(*)(const cv::Mat&)>("calc_blurriness", &cv::videostab::calcBlurriness,
    Arg("frame"));

  Rice::Data_Type<cv::videostab::DeblurerBase> rb_cCvVideostabDeblurerBase = define_class_under<cv::videostab::DeblurerBase>(rb_mCvVideostab, "DeblurerBase").
    define_method<void(cv::videostab::DeblurerBase::*)(int)>("set_radius", &cv::videostab::DeblurerBase::setRadius,
      Arg("val")).
    define_method<int(cv::videostab::DeblurerBase::*)() const>("radius", &cv::videostab::DeblurerBase::radius).
    define_method<void(cv::videostab::DeblurerBase::*)(int, cv::Mat&, const cv::Range&)>("deblur", &cv::videostab::DeblurerBase::deblur,
      Arg("idx"), Arg("frame"), Arg("range")).
    define_method<void(cv::videostab::DeblurerBase::*)(const std::vector<cv::Mat>&)>("set_frames", &cv::videostab::DeblurerBase::setFrames,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::DeblurerBase::*)() const>("frames", &cv::videostab::DeblurerBase::frames).
    define_method<void(cv::videostab::DeblurerBase::*)(const std::vector<cv::Mat>&)>("set_motions", &cv::videostab::DeblurerBase::setMotions,
      Arg("val")).
    define_method<const std::vector<cv::Mat>&(cv::videostab::DeblurerBase::*)() const>("motions", &cv::videostab::DeblurerBase::motions).
    define_method<void(cv::videostab::DeblurerBase::*)(const std::vector<float>&)>("set_blurriness_rates", &cv::videostab::DeblurerBase::setBlurrinessRates,
      Arg("val")).
    define_method<const std::vector<float>&(cv::videostab::DeblurerBase::*)() const>("blurriness_rates", &cv::videostab::DeblurerBase::blurrinessRates);

  Rice::Data_Type<cv::videostab::NullDeblurer> rb_cCvVideostabNullDeblurer = define_class_under<cv::videostab::NullDeblurer, cv::videostab::DeblurerBase>(rb_mCvVideostab, "NullDeblurer").
    define_constructor(Constructor<cv::videostab::NullDeblurer>()).
    define_method<void(cv::videostab::NullDeblurer::*)(int, cv::Mat&, const cv::Range&)>("deblur", &cv::videostab::NullDeblurer::deblur,
      Arg("arg_0"), Arg("arg_1"), Arg("arg_2"));

  Rice::Data_Type<cv::videostab::WeightingDeblurer> rb_cCvVideostabWeightingDeblurer = define_class_under<cv::videostab::WeightingDeblurer, cv::videostab::DeblurerBase>(rb_mCvVideostab, "WeightingDeblurer").
    define_constructor(Constructor<cv::videostab::WeightingDeblurer>()).
    define_method<void(cv::videostab::WeightingDeblurer::*)(float)>("set_sensitivity", &cv::videostab::WeightingDeblurer::setSensitivity,
      Arg("val")).
    define_method<float(cv::videostab::WeightingDeblurer::*)() const>("sensitivity", &cv::videostab::WeightingDeblurer::sensitivity).
    define_method<void(cv::videostab::WeightingDeblurer::*)(int, cv::Mat&, const cv::Range&)>("deblur", &cv::videostab::WeightingDeblurer::deblur,
      Arg("idx"), Arg("frame"), Arg("range"));
}