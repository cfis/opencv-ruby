#include <opencv2/img_hash/average_hash.hpp>
#include "average_hash-rb.hpp"

using namespace Rice;

void Init_ImgHash_AverageHash()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");

  Rice::Data_Type<cv::img_hash::AverageHash> rb_cCvImgHashAverageHash = define_class_under<cv::img_hash::AverageHash, cv::img_hash::ImgHashBase>(rb_mCvImgHash, "AverageHash").
    define_singleton_function<cv::Ptr<cv::img_hash::AverageHash>(*)()>("create", &cv::img_hash::AverageHash::create);

  rb_mCvImgHash.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("average_hash", &cv::img_hash::averageHash,
    Arg("input_arr"), Arg("output_arr"));
}
