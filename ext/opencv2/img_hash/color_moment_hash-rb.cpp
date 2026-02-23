#include <opencv2/img_hash/color_moment_hash.hpp>
#include "color_moment_hash-rb.hpp"

using namespace Rice;

void Init_ImgHash_ColorMomentHash()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");

  Rice::Data_Type<cv::img_hash::ColorMomentHash> rb_cCvImgHashColorMomentHash = define_class_under<cv::img_hash::ColorMomentHash, cv::img_hash::ImgHashBase>(rb_mCvImgHash, "ColorMomentHash").
    define_singleton_function<cv::Ptr<cv::img_hash::ColorMomentHash>(*)()>("create", &cv::img_hash::ColorMomentHash::create);

  rb_mCvImgHash.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("color_moment_hash", &cv::img_hash::colorMomentHash,
    Arg("input_arr"), Arg("output_arr"));
}
