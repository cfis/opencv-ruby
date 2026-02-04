#include <opencv2/xfeatures2d/nonfree.hpp>
#include "nonfree-rb.hpp"

using namespace Rice;

void Init_Xfeatures2d_Nonfree()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXfeatures2d = define_module_under(rb_mCv, "Xfeatures2d");

  Rice::Data_Type<cv::xfeatures2d::SURF> rb_cCvXfeatures2dSURF = define_class_under<cv::xfeatures2d::SURF, cv::Feature2D>(rb_mCvXfeatures2d, "SURF").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::SURF>(*)(double, int, int, bool, bool)>("create", &cv::xfeatures2d::SURF::create,
      Arg("hessian_threshold") = static_cast<double>(100), Arg("n_octaves") = static_cast<int>(4), Arg("n_octave_layers") = static_cast<int>(3), Arg("extended") = static_cast<bool>(false), Arg("upright") = static_cast<bool>(false)).
    define_method<void(cv::xfeatures2d::SURF::*)(double)>("set_hessian_threshold", &cv::xfeatures2d::SURF::setHessianThreshold,
      Arg("hessian_threshold")).
    define_method<double(cv::xfeatures2d::SURF::*)() const>("get_hessian_threshold", &cv::xfeatures2d::SURF::getHessianThreshold).
    define_method<void(cv::xfeatures2d::SURF::*)(int)>("set_n_octaves", &cv::xfeatures2d::SURF::setNOctaves,
      Arg("n_octaves")).
    define_method<int(cv::xfeatures2d::SURF::*)() const>("get_n_octaves", &cv::xfeatures2d::SURF::getNOctaves).
    define_method<void(cv::xfeatures2d::SURF::*)(int)>("set_n_octave_layers", &cv::xfeatures2d::SURF::setNOctaveLayers,
      Arg("n_octave_layers")).
    define_method<int(cv::xfeatures2d::SURF::*)() const>("get_n_octave_layers", &cv::xfeatures2d::SURF::getNOctaveLayers).
    define_method<void(cv::xfeatures2d::SURF::*)(bool)>("set_extended", &cv::xfeatures2d::SURF::setExtended,
      Arg("extended")).
    define_method<bool(cv::xfeatures2d::SURF::*)() const>("get_extended?", &cv::xfeatures2d::SURF::getExtended).
    define_method<void(cv::xfeatures2d::SURF::*)(bool)>("set_upright", &cv::xfeatures2d::SURF::setUpright,
      Arg("upright")).
    define_method<bool(cv::xfeatures2d::SURF::*)() const>("get_upright?", &cv::xfeatures2d::SURF::getUpright).
    define_method<cv::String(cv::xfeatures2d::SURF::*)() const>("get_default_name", &cv::xfeatures2d::SURF::getDefaultName);
}