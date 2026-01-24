#include <opencv2/hfs.hpp>
#include "hfs-rb.hpp"

using namespace Rice;

void Init_Hfs()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvHfs = define_module_under(rb_mCv, "Hfs");

  Rice::Data_Type<cv::hfs::HfsSegment> rb_cCvHfsHfsSegment = define_class_under<cv::hfs::HfsSegment, cv::Algorithm>(rb_mCvHfs, "HfsSegment").
    define_method("set_seg_egb_threshold_i", &cv::hfs::HfsSegment::setSegEgbThresholdI,
      Arg("c")).
    define_method("get_seg_egb_threshold_i", &cv::hfs::HfsSegment::getSegEgbThresholdI).
    define_method("set_min_region_size_i", &cv::hfs::HfsSegment::setMinRegionSizeI,
      Arg("n")).
    define_method("get_min_region_size_i", &cv::hfs::HfsSegment::getMinRegionSizeI).
    define_method("set_seg_egb_threshold_ii", &cv::hfs::HfsSegment::setSegEgbThresholdII,
      Arg("c")).
    define_method("get_seg_egb_threshold_ii", &cv::hfs::HfsSegment::getSegEgbThresholdII).
    define_method("set_min_region_size_ii", &cv::hfs::HfsSegment::setMinRegionSizeII,
      Arg("n")).
    define_method("get_min_region_size_ii", &cv::hfs::HfsSegment::getMinRegionSizeII).
    define_method("set_spatial_weight", &cv::hfs::HfsSegment::setSpatialWeight,
      Arg("w")).
    define_method("get_spatial_weight", &cv::hfs::HfsSegment::getSpatialWeight).
    define_method("set_slic_spixel_size", &cv::hfs::HfsSegment::setSlicSpixelSize,
      Arg("n")).
    define_method("get_slic_spixel_size", &cv::hfs::HfsSegment::getSlicSpixelSize).
    define_method("set_num_slic_iter", &cv::hfs::HfsSegment::setNumSlicIter,
      Arg("n")).
    define_method("get_num_slic_iter", &cv::hfs::HfsSegment::getNumSlicIter).
    define_method("perform_segment_gpu", &cv::hfs::HfsSegment::performSegmentGpu,
      Arg("src"), Arg("if_draw") = static_cast<bool>(true)).
    define_method("perform_segment_cpu", &cv::hfs::HfsSegment::performSegmentCpu,
      Arg("src"), Arg("if_draw") = static_cast<bool>(true)).
    define_singleton_function("create", &cv::hfs::HfsSegment::create,
      Arg("height"), Arg("width"), Arg("seg_egb_threshold_i") = static_cast<float>(0.08f), Arg("min_region_size_i") = static_cast<int>(100), Arg("seg_egb_threshold_ii") = static_cast<float>(0.28f), Arg("min_region_size_ii") = static_cast<int>(200), Arg("spatial_weight") = static_cast<float>(0.6f), Arg("slic_spixel_size") = static_cast<int>(8), Arg("num_slic_iter") = static_cast<int>(5));
}