#include <opencv2/cudaobjdetect.hpp>
#include "cudaobjdetect-rb.hpp"

using namespace Rice;

void Init_Cudaobjdetect()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::HOG> rb_cCvCudaHOG = define_class_under<cv::cuda::HOG, cv::Algorithm>(rb_mCvCuda, "HOG").
    define_method("set_win_sigma", &cv::cuda::HOG::setWinSigma,
      Arg("win_sigma")).
    define_method("get_win_sigma", &cv::cuda::HOG::getWinSigma).
    define_method("set_l2_hys_threshold", &cv::cuda::HOG::setL2HysThreshold,
      Arg("threshold_l2hys")).
    define_method("get_l2_hys_threshold", &cv::cuda::HOG::getL2HysThreshold).
    define_method("set_gamma_correction", &cv::cuda::HOG::setGammaCorrection,
      Arg("gamma_correction")).
    define_method("get_gamma_correction?", &cv::cuda::HOG::getGammaCorrection).
    define_method("set_num_levels", &cv::cuda::HOG::setNumLevels,
      Arg("nlevels")).
    define_method("get_num_levels", &cv::cuda::HOG::getNumLevels).
    define_method("set_hit_threshold", &cv::cuda::HOG::setHitThreshold,
      Arg("hit_threshold")).
    define_method("get_hit_threshold", &cv::cuda::HOG::getHitThreshold).
    define_method("set_win_stride", &cv::cuda::HOG::setWinStride,
      Arg("win_stride")).
    define_method("get_win_stride", &cv::cuda::HOG::getWinStride).
    define_method("set_scale_factor", &cv::cuda::HOG::setScaleFactor,
      Arg("scale0")).
    define_method("get_scale_factor", &cv::cuda::HOG::getScaleFactor).
    define_method("set_group_threshold", &cv::cuda::HOG::setGroupThreshold,
      Arg("group_threshold")).
    define_method("get_group_threshold", &cv::cuda::HOG::getGroupThreshold).
    define_method("set_descriptor_format", &cv::cuda::HOG::setDescriptorFormat,
      Arg("descr_format")).
    define_method("get_descriptor_format", &cv::cuda::HOG::getDescriptorFormat).
    define_method("get_descriptor_size", &cv::cuda::HOG::getDescriptorSize).
    define_method("get_block_histogram_size", &cv::cuda::HOG::getBlockHistogramSize).
    define_method("set_svm_detector", &cv::cuda::HOG::setSVMDetector,
      Arg("detector")).
    define_method("get_default_people_detector", &cv::cuda::HOG::getDefaultPeopleDetector).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Point_<int>>&, std::vector<double>*)>("detect", &cv::cuda::HOG::detect,
      Arg("img"), Arg("found_locations"), Arg("confidences") = static_cast<std::vector<double>*>(NULL)).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Point_<int>>&, std::vector<double>&)>("detect", &cv::cuda::HOG::detect,
      Arg("img"), Arg("found_locations"), Arg("confidences")).
    define_method("detect_without_conf", &cv::cuda::HOG::detectWithoutConf,
      Arg("img"), Arg("found_locations")).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<double>*)>("detect_multi_scale", &cv::cuda::HOG::detectMultiScale,
      Arg("img"), Arg("found_locations"), Arg("confidences") = static_cast<std::vector<double>*>(NULL)).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<double>&)>("detect_multi_scale", &cv::cuda::HOG::detectMultiScale,
      Arg("img"), Arg("found_locations"), Arg("confidences")).
    define_method("detect_multi_scale_without_conf", &cv::cuda::HOG::detectMultiScaleWithoutConf,
      Arg("img"), Arg("found_locations")).
    define_method("compute", &cv::cuda::HOG::compute,
      Arg("img"), Arg("descriptors"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_singleton_function("create", &cv::cuda::HOG::create,
      Arg("win_size") = static_cast<cv::Size>(cv::Size(64, 128)), Arg("block_size") = static_cast<cv::Size>(cv::Size(16, 16)), Arg("block_stride") = static_cast<cv::Size>(cv::Size(8, 8)), Arg("cell_size") = static_cast<cv::Size>(cv::Size(8, 8)), Arg("nbins") = static_cast<int>(9));

  Rice::Data_Type<cv::cuda::CascadeClassifier> rb_cCvCudaCascadeClassifier = define_class_under<cv::cuda::CascadeClassifier, cv::Algorithm>(rb_mCvCuda, "CascadeClassifier").
    define_method("set_max_object_size", &cv::cuda::CascadeClassifier::setMaxObjectSize,
      Arg("max_object_size")).
    define_method("get_max_object_size", &cv::cuda::CascadeClassifier::getMaxObjectSize).
    define_method("set_min_object_size", &cv::cuda::CascadeClassifier::setMinObjectSize,
      Arg("min_size")).
    define_method("get_min_object_size", &cv::cuda::CascadeClassifier::getMinObjectSize).
    define_method("set_scale_factor", &cv::cuda::CascadeClassifier::setScaleFactor,
      Arg("scale_factor")).
    define_method("get_scale_factor", &cv::cuda::CascadeClassifier::getScaleFactor).
    define_method("set_min_neighbors", &cv::cuda::CascadeClassifier::setMinNeighbors,
      Arg("min_neighbors")).
    define_method("get_min_neighbors", &cv::cuda::CascadeClassifier::getMinNeighbors).
    define_method("set_find_largest_object", &cv::cuda::CascadeClassifier::setFindLargestObject,
      Arg("find_largest_object")).
    define_method("get_find_largest_object?", &cv::cuda::CascadeClassifier::getFindLargestObject).
    define_method("set_max_num_objects", &cv::cuda::CascadeClassifier::setMaxNumObjects,
      Arg("max_num_objects")).
    define_method("get_max_num_objects", &cv::cuda::CascadeClassifier::getMaxNumObjects).
    define_method("get_classifier_size", &cv::cuda::CascadeClassifier::getClassifierSize).
    define_method("detect_multi_scale", &cv::cuda::CascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method("convert", &cv::cuda::CascadeClassifier::convert,
      Arg("gpu_objects"), Arg("objects")).
    define_singleton_function<cv::Ptr<cv::cuda::CascadeClassifier>(*)(const cv::String&)>("create", &cv::cuda::CascadeClassifier::create,
      Arg("filename")).
    define_singleton_function<cv::Ptr<cv::cuda::CascadeClassifier>(*)(const cv::FileStorage&)>("create", &cv::cuda::CascadeClassifier::create,
      Arg("file"));
}