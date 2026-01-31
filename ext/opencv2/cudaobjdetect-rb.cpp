#include <opencv2/cudaobjdetect.hpp>
#include "cudaobjdetect-rb.hpp"

using namespace Rice;

void Init_Cudaobjdetect()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::HOG> rb_cCvCudaHOG = define_class_under<cv::cuda::HOG, cv::Algorithm>(rb_mCvCuda, "HOG").
    define_method<void(cv::cuda::HOG::*)(double)>("set_win_sigma", &cv::cuda::HOG::setWinSigma,
      Arg("win_sigma")).
    define_method<double(cv::cuda::HOG::*)() const>("get_win_sigma", &cv::cuda::HOG::getWinSigma).
    define_method<void(cv::cuda::HOG::*)(double)>("set_l2_hys_threshold", &cv::cuda::HOG::setL2HysThreshold,
      Arg("threshold_l2hys")).
    define_method<double(cv::cuda::HOG::*)() const>("get_l2_hys_threshold", &cv::cuda::HOG::getL2HysThreshold).
    define_method<void(cv::cuda::HOG::*)(bool)>("set_gamma_correction", &cv::cuda::HOG::setGammaCorrection,
      Arg("gamma_correction")).
    define_method<bool(cv::cuda::HOG::*)() const>("get_gamma_correction?", &cv::cuda::HOG::getGammaCorrection).
    define_method<void(cv::cuda::HOG::*)(int)>("set_num_levels", &cv::cuda::HOG::setNumLevels,
      Arg("nlevels")).
    define_method<int(cv::cuda::HOG::*)() const>("get_num_levels", &cv::cuda::HOG::getNumLevels).
    define_method<void(cv::cuda::HOG::*)(double)>("set_hit_threshold", &cv::cuda::HOG::setHitThreshold,
      Arg("hit_threshold")).
    define_method<double(cv::cuda::HOG::*)() const>("get_hit_threshold", &cv::cuda::HOG::getHitThreshold).
    define_method<void(cv::cuda::HOG::*)(cv::Size)>("set_win_stride", &cv::cuda::HOG::setWinStride,
      Arg("win_stride")).
    define_method<cv::Size(cv::cuda::HOG::*)() const>("get_win_stride", &cv::cuda::HOG::getWinStride).
    define_method<void(cv::cuda::HOG::*)(double)>("set_scale_factor", &cv::cuda::HOG::setScaleFactor,
      Arg("scale0")).
    define_method<double(cv::cuda::HOG::*)() const>("get_scale_factor", &cv::cuda::HOG::getScaleFactor).
    define_method<void(cv::cuda::HOG::*)(int)>("set_group_threshold", &cv::cuda::HOG::setGroupThreshold,
      Arg("group_threshold")).
    define_method<int(cv::cuda::HOG::*)() const>("get_group_threshold", &cv::cuda::HOG::getGroupThreshold).
    define_method<void(cv::cuda::HOG::*)(cv::HOGDescriptor::DescriptorStorageFormat)>("set_descriptor_format", &cv::cuda::HOG::setDescriptorFormat,
      Arg("descr_format")).
    define_method<cv::HOGDescriptor::DescriptorStorageFormat(cv::cuda::HOG::*)() const>("get_descriptor_format", &cv::cuda::HOG::getDescriptorFormat).
    define_method<size_t(cv::cuda::HOG::*)() const>("get_descriptor_size", &cv::cuda::HOG::getDescriptorSize).
    define_method<size_t(cv::cuda::HOG::*)() const>("get_block_histogram_size", &cv::cuda::HOG::getBlockHistogramSize).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray)>("set_svm_detector", &cv::cuda::HOG::setSVMDetector,
      Arg("detector")).
    define_method<cv::Mat(cv::cuda::HOG::*)() const>("get_default_people_detector", &cv::cuda::HOG::getDefaultPeopleDetector).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Point_<int>>&, std::vector<double>*)>("detect", &cv::cuda::HOG::detect,
      Arg("img"), Arg("found_locations"), Arg("confidences") = static_cast<std::vector<double>*>(NULL)).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Point_<int>>&, std::vector<double>&)>("detect", &cv::cuda::HOG::detect,
      Arg("img"), Arg("found_locations"), Arg("confidences")).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Point_<int>>&)>("detect_without_conf", &cv::cuda::HOG::detectWithoutConf,
      Arg("img"), Arg("found_locations")).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<double>*)>("detect_multi_scale", &cv::cuda::HOG::detectMultiScale,
      Arg("img"), Arg("found_locations"), Arg("confidences") = static_cast<std::vector<double>*>(NULL)).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<double>&)>("detect_multi_scale", &cv::cuda::HOG::detectMultiScale,
      Arg("img"), Arg("found_locations"), Arg("confidences")).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, std::vector<cv::Rect_<int>>&)>("detect_multi_scale_without_conf", &cv::cuda::HOG::detectMultiScaleWithoutConf,
      Arg("img"), Arg("found_locations")).
    define_method<void(cv::cuda::HOG::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("compute", &cv::cuda::HOG::compute,
      Arg("img"), Arg("descriptors"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_singleton_function<cv::Ptr<cv::cuda::HOG>(*)(cv::Size, cv::Size, cv::Size, cv::Size, int)>("create", &cv::cuda::HOG::create,
      Arg("win_size") = static_cast<cv::Size>(cv::Size(64, 128)), Arg("block_size") = static_cast<cv::Size>(cv::Size(16, 16)), Arg("block_stride") = static_cast<cv::Size>(cv::Size(8, 8)), Arg("cell_size") = static_cast<cv::Size>(cv::Size(8, 8)), Arg("nbins") = static_cast<int>(9));

  Rice::Data_Type<cv::cuda::CascadeClassifier> rb_cCvCudaCascadeClassifier = define_class_under<cv::cuda::CascadeClassifier, cv::Algorithm>(rb_mCvCuda, "CascadeClassifier").
    define_method<void(cv::cuda::CascadeClassifier::*)(cv::Size)>("set_max_object_size", &cv::cuda::CascadeClassifier::setMaxObjectSize,
      Arg("max_object_size")).
    define_method<cv::Size(cv::cuda::CascadeClassifier::*)() const>("get_max_object_size", &cv::cuda::CascadeClassifier::getMaxObjectSize).
    define_method<void(cv::cuda::CascadeClassifier::*)(cv::Size)>("set_min_object_size", &cv::cuda::CascadeClassifier::setMinObjectSize,
      Arg("min_size")).
    define_method<cv::Size(cv::cuda::CascadeClassifier::*)() const>("get_min_object_size", &cv::cuda::CascadeClassifier::getMinObjectSize).
    define_method<void(cv::cuda::CascadeClassifier::*)(double)>("set_scale_factor", &cv::cuda::CascadeClassifier::setScaleFactor,
      Arg("scale_factor")).
    define_method<double(cv::cuda::CascadeClassifier::*)() const>("get_scale_factor", &cv::cuda::CascadeClassifier::getScaleFactor).
    define_method<void(cv::cuda::CascadeClassifier::*)(int)>("set_min_neighbors", &cv::cuda::CascadeClassifier::setMinNeighbors,
      Arg("min_neighbors")).
    define_method<int(cv::cuda::CascadeClassifier::*)() const>("get_min_neighbors", &cv::cuda::CascadeClassifier::getMinNeighbors).
    define_method<void(cv::cuda::CascadeClassifier::*)(bool)>("set_find_largest_object", &cv::cuda::CascadeClassifier::setFindLargestObject,
      Arg("find_largest_object")).
    define_method<bool(cv::cuda::CascadeClassifier::*)()>("get_find_largest_object?", &cv::cuda::CascadeClassifier::getFindLargestObject).
    define_method<void(cv::cuda::CascadeClassifier::*)(int)>("set_max_num_objects", &cv::cuda::CascadeClassifier::setMaxNumObjects,
      Arg("max_num_objects")).
    define_method<int(cv::cuda::CascadeClassifier::*)() const>("get_max_num_objects", &cv::cuda::CascadeClassifier::getMaxNumObjects).
    define_method<cv::Size(cv::cuda::CascadeClassifier::*)() const>("get_classifier_size", &cv::cuda::CascadeClassifier::getClassifierSize).
    define_method<void(cv::cuda::CascadeClassifier::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("detect_multi_scale", &cv::cuda::CascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::CascadeClassifier::*)(cv::OutputArray, std::vector<cv::Rect_<int>>&)>("convert", &cv::cuda::CascadeClassifier::convert,
      Arg("gpu_objects"), Arg("objects")).
    define_singleton_function<cv::Ptr<cv::cuda::CascadeClassifier>(*)(const cv::String&)>("create", &cv::cuda::CascadeClassifier::create,
      Arg("filename")).
    define_singleton_function<cv::Ptr<cv::cuda::CascadeClassifier>(*)(const cv::FileStorage&)>("create", &cv::cuda::CascadeClassifier::create,
      Arg("file"));
}