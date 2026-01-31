#include <opencv2/face/mace.hpp>
#include "mace-rb.hpp"

using namespace Rice;

void Init_Face_Mace()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::MACE> rb_cCvFaceMACE = define_class_under<cv::face::MACE, cv::Algorithm>(rb_mCvFace, "MACE").
    define_method<void(cv::face::MACE::*)(const cv::String&)>("salt", &cv::face::MACE::salt,
      Arg("passphrase")).
    define_method<void(cv::face::MACE::*)(cv::InputArrayOfArrays)>("train", &cv::face::MACE::train,
      Arg("images")).
    define_method<bool(cv::face::MACE::*)(cv::InputArray) const>("same", &cv::face::MACE::same,
      Arg("query")).
    define_singleton_function<cv::Ptr<cv::face::MACE>(*)(const cv::String&, const cv::String&)>("load", &cv::face::MACE::load,
      Arg("filename"), Arg("objname") = static_cast<const cv::String&>(cv::String())).
    define_singleton_function<cv::Ptr<cv::face::MACE>(*)(int)>("create", &cv::face::MACE::create,
      Arg("imgsize") = static_cast<int>(64));
}