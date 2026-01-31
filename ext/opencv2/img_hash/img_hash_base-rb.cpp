#include <opencv2/img_hash/img_hash_base.hpp>
#include "img_hash_base-rb.hpp"

using namespace Rice;

void Init_ImgHash_ImgHashBase()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");

  Rice::Data_Type<cv::img_hash::ImgHashBase> rb_cCvImgHashImgHashBase = define_class_under<cv::img_hash::ImgHashBase, cv::Algorithm>(rb_mCvImgHash, "ImgHashBase");

  Rice::Data_Type<cv::img_hash::ImgHashBase::ImgHashImpl> rb_cCvImgHashImgHashBaseImgHashImpl = define_class_under<cv::img_hash::ImgHashBase::ImgHashImpl>(rb_cCvImgHashImgHashBase, "ImgHashImpl");

  rb_cCvImgHashImgHashBase.
    define_method<void(cv::img_hash::ImgHashBase::*)(cv::InputArray, cv::OutputArray)>("compute", &cv::img_hash::ImgHashBase::compute,
      Arg("input_arr"), Arg("output_arr")).
    define_method<double(cv::img_hash::ImgHashBase::*)(cv::InputArray, cv::InputArray) const>("compare", &cv::img_hash::ImgHashBase::compare,
      Arg("hash_one"), Arg("hash_two"));
}