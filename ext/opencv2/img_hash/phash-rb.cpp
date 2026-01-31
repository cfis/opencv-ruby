#include <opencv2/img_hash/phash.hpp>
#include "phash-rb.hpp"

using namespace Rice;

void Init_ImgHash_Phash()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");

  Rice::Data_Type<cv::img_hash::PHash> rb_cCvImgHashPHash = define_class_under<cv::img_hash::PHash, cv::img_hash::ImgHashBase>(rb_mCvImgHash, "PHash").
    define_singleton_function<cv::Ptr<cv::img_hash::PHash>(*)()>("create", &cv::img_hash::PHash::create);

  rb_mCvImgHash.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("p_hash", &cv::img_hash::pHash,
    Arg("input_arr"), Arg("output_arr"));
}