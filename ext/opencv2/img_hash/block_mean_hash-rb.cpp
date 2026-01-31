#include <opencv2/img_hash/block_mean_hash.hpp>
#include "block_mean_hash-rb.hpp"

using namespace Rice;

void Init_ImgHash_BlockMeanHash()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");

  Enum<cv::img_hash::BlockMeanHashMode> rb_cCvImgHashBlockMeanHashMode = define_enum_under<cv::img_hash::BlockMeanHashMode>("BlockMeanHashMode", rb_mCvImgHash).
    define_value("BLOCK_MEAN_HASH_MODE_0", cv::img_hash::BlockMeanHashMode::BLOCK_MEAN_HASH_MODE_0).
    define_value("BLOCK_MEAN_HASH_MODE_1", cv::img_hash::BlockMeanHashMode::BLOCK_MEAN_HASH_MODE_1);

  Rice::Data_Type<cv::img_hash::BlockMeanHash> rb_cCvImgHashBlockMeanHash = define_class_under<cv::img_hash::BlockMeanHash, cv::img_hash::ImgHashBase>(rb_mCvImgHash, "BlockMeanHash").
    define_method<void(cv::img_hash::BlockMeanHash::*)(int)>("set_mode", &cv::img_hash::BlockMeanHash::setMode,
      Arg("mode")).
    define_method<std::vector<double>(cv::img_hash::BlockMeanHash::*)() const>("get_mean", &cv::img_hash::BlockMeanHash::getMean).
    define_singleton_function<cv::Ptr<cv::img_hash::BlockMeanHash>(*)(int)>("create", &cv::img_hash::BlockMeanHash::create,
      Arg("mode") = static_cast<int>(cv::img_hash::BLOCK_MEAN_HASH_MODE_0));

  rb_mCvImgHash.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int)>("block_mean_hash", &cv::img_hash::blockMeanHash,
    Arg("input_arr"), Arg("output_arr"), Arg("mode") = static_cast<int>(cv::img_hash::BLOCK_MEAN_HASH_MODE_0));
}