#include <opencv2/cudafeatures2d.hpp>
#include "cudafeatures2d-rb.hpp"

using namespace Rice;

void Init_Cudafeatures2d()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::DescriptorMatcher> rb_cCvCudaDescriptorMatcher = define_class_under<cv::cuda::DescriptorMatcher, cv::Algorithm>(rb_mCvCuda, "DescriptorMatcher").
    define_singleton_function<cv::Ptr<cv::cuda::DescriptorMatcher>(*)(int)>("create_bf_matcher", &cv::cuda::DescriptorMatcher::createBFMatcher,
      Arg("norm_type") = static_cast<int>(cv::NORM_L2)).
    define_method<bool(cv::cuda::DescriptorMatcher::*)() const>("mask_supported?", &cv::cuda::DescriptorMatcher::isMaskSupported).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const std::vector<cv::cuda::GpuMat>&)>("add", &cv::cuda::DescriptorMatcher::add,
      Arg("descriptors")).
    define_method<const std::vector<cv::cuda::GpuMat>&(cv::cuda::DescriptorMatcher::*)() const>("get_train_descriptors", &cv::cuda::DescriptorMatcher::getTrainDescriptors).
    define_method<void(cv::cuda::DescriptorMatcher::*)()>("clear", &cv::cuda::DescriptorMatcher::clear).
    define_method<bool(cv::cuda::DescriptorMatcher::*)() const>("empty?", &cv::cuda::DescriptorMatcher::empty).
    define_method<void(cv::cuda::DescriptorMatcher::*)()>("train", &cv::cuda::DescriptorMatcher::train).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<cv::DMatch>&, cv::InputArray)>("match", &cv::cuda::DescriptorMatcher::match,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, std::vector<cv::DMatch>&, const std::vector<cv::cuda::GpuMat>&)>("match", &cv::cuda::DescriptorMatcher::match,
      Arg("query_descriptors"), Arg("matches"), Arg("masks") = static_cast<const std::vector<cv::cuda::GpuMat>&>(std::vector<cv::cuda::GpuMat>())).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray, cv::cuda::Stream&)>("match_async", &cv::cuda::DescriptorMatcher::matchAsync,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::OutputArray, const std::vector<cv::cuda::GpuMat>&, cv::cuda::Stream&)>("match_async", &cv::cuda::DescriptorMatcher::matchAsync,
      Arg("query_descriptors"), Arg("matches"), Arg("masks") = static_cast<const std::vector<cv::cuda::GpuMat>&>(std::vector<cv::cuda::GpuMat>()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, std::vector<cv::DMatch>&)>("match_convert", &cv::cuda::DescriptorMatcher::matchConvert,
      Arg("gpu_matches"), Arg("matches")).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<std::vector<cv::DMatch>>&, int, cv::InputArray, bool)>("knn_match", &cv::cuda::DescriptorMatcher::knnMatch,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("k"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, std::vector<std::vector<cv::DMatch>>&, int, const std::vector<cv::cuda::GpuMat>&, bool)>("knn_match", &cv::cuda::DescriptorMatcher::knnMatch,
      Arg("query_descriptors"), Arg("matches"), Arg("k"), Arg("masks") = static_cast<const std::vector<cv::cuda::GpuMat>&>(std::vector<cv::cuda::GpuMat>()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, cv::InputArray, cv::cuda::Stream&)>("knn_match_async", &cv::cuda::DescriptorMatcher::knnMatchAsync,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("k"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::OutputArray, int, const std::vector<cv::cuda::GpuMat>&, cv::cuda::Stream&)>("knn_match_async", &cv::cuda::DescriptorMatcher::knnMatchAsync,
      Arg("query_descriptors"), Arg("matches"), Arg("k"), Arg("masks") = static_cast<const std::vector<cv::cuda::GpuMat>&>(std::vector<cv::cuda::GpuMat>()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, std::vector<std::vector<cv::DMatch>>&, bool)>("knn_match_convert", &cv::cuda::DescriptorMatcher::knnMatchConvert,
      Arg("gpu_matches"), Arg("matches"), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<std::vector<cv::DMatch>>&, float, cv::InputArray, bool)>("radius_match", &cv::cuda::DescriptorMatcher::radiusMatch,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("max_distance"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, std::vector<std::vector<cv::DMatch>>&, float, const std::vector<cv::cuda::GpuMat>&, bool)>("radius_match", &cv::cuda::DescriptorMatcher::radiusMatch,
      Arg("query_descriptors"), Arg("matches"), Arg("max_distance"), Arg("masks") = static_cast<const std::vector<cv::cuda::GpuMat>&>(std::vector<cv::cuda::GpuMat>()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, cv::OutputArray, float, cv::InputArray, cv::cuda::Stream&)>("radius_match_async", &cv::cuda::DescriptorMatcher::radiusMatchAsync,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("max_distance"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, cv::OutputArray, float, const std::vector<cv::cuda::GpuMat>&, cv::cuda::Stream&)>("radius_match_async", &cv::cuda::DescriptorMatcher::radiusMatchAsync,
      Arg("query_descriptors"), Arg("matches"), Arg("max_distance"), Arg("masks") = static_cast<const std::vector<cv::cuda::GpuMat>&>(std::vector<cv::cuda::GpuMat>()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::DescriptorMatcher::*)(cv::InputArray, std::vector<std::vector<cv::DMatch>>&, bool)>("radius_match_convert", &cv::cuda::DescriptorMatcher::radiusMatchConvert,
      Arg("gpu_matches"), Arg("matches"), Arg("compact_result") = static_cast<bool>(false));

  Rice::Data_Type<cv::cuda::Feature2DAsync> rb_cCvCudaFeature2DAsync = define_class_under<cv::cuda::Feature2DAsync, cv::Feature2D>(rb_mCvCuda, "Feature2DAsync").
    define_method<void(cv::cuda::Feature2DAsync::*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::cuda::Stream&)>("detect_async", &cv::cuda::Feature2DAsync::detectAsync,
      Arg("image"), Arg("keypoints"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::Feature2DAsync::*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::cuda::Stream&)>("compute_async", &cv::cuda::Feature2DAsync::computeAsync,
      Arg("image"), Arg("keypoints"), Arg("descriptors"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::Feature2DAsync::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("detect_and_compute_async", &cv::cuda::Feature2DAsync::detectAndComputeAsync,
      Arg("image"), Arg("mask"), Arg("keypoints"), Arg("descriptors"), Arg("use_provided_keypoints") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::Feature2DAsync::*)(cv::InputArray, std::vector<cv::KeyPoint>&)>("convert", &cv::cuda::Feature2DAsync::convert,
      Arg("gpu_keypoints"), Arg("keypoints"));

  Rice::Data_Type<cv::cuda::FastFeatureDetector> rb_cCvCudaFastFeatureDetector = define_class_under<cv::cuda::FastFeatureDetector, cv::cuda::Feature2DAsync>(rb_mCvCuda, "FastFeatureDetector").
    define_constant("LOCATION_ROW", cv::cuda::FastFeatureDetector::LOCATION_ROW).
    define_constant("RESPONSE_ROW", cv::cuda::FastFeatureDetector::RESPONSE_ROW).
    define_constant("ROWS_COUNT", cv::cuda::FastFeatureDetector::ROWS_COUNT).
    define_constant("FEATURE_SIZE", cv::cuda::FastFeatureDetector::FEATURE_SIZE).
    define_singleton_function<cv::Ptr<cv::cuda::FastFeatureDetector>(*)(int, bool, int, int)>("create", &cv::cuda::FastFeatureDetector::create,
      Arg("threshold") = static_cast<int>(10), Arg("nonmax_suppression") = static_cast<bool>(true), Arg("type") = static_cast<int>(cv::FastFeatureDetector::DetectorType::TYPE_9_16), Arg("max_npoints") = static_cast<int>(5000)).
    define_method<void(cv::cuda::FastFeatureDetector::*)(int)>("set_threshold", &cv::cuda::FastFeatureDetector::setThreshold,
      Arg("threshold")).
    define_method<void(cv::cuda::FastFeatureDetector::*)(int)>("set_max_num_points", &cv::cuda::FastFeatureDetector::setMaxNumPoints,
      Arg("max_npoints")).
    define_method<int(cv::cuda::FastFeatureDetector::*)() const>("get_max_num_points", &cv::cuda::FastFeatureDetector::getMaxNumPoints);

  Rice::Data_Type<cv::cuda::ORB> rb_cCvCudaORB = define_class_under<cv::cuda::ORB, cv::cuda::Feature2DAsync>(rb_mCvCuda, "ORB").
    define_constant("X_ROW", cv::cuda::ORB::X_ROW).
    define_constant("Y_ROW", cv::cuda::ORB::Y_ROW).
    define_constant("RESPONSE_ROW", cv::cuda::ORB::RESPONSE_ROW).
    define_constant("ANGLE_ROW", cv::cuda::ORB::ANGLE_ROW).
    define_constant("OCTAVE_ROW", cv::cuda::ORB::OCTAVE_ROW).
    define_constant("SIZE_ROW", cv::cuda::ORB::SIZE_ROW).
    define_constant("ROWS_COUNT", cv::cuda::ORB::ROWS_COUNT).
    define_singleton_function<cv::Ptr<cv::cuda::ORB>(*)(int, float, int, int, int, int, int, int, int, bool)>("create", &cv::cuda::ORB::create,
      Arg("nfeatures") = static_cast<int>(500), Arg("scale_factor") = static_cast<float>(1.2f), Arg("nlevels") = static_cast<int>(8), Arg("edge_threshold") = static_cast<int>(31), Arg("first_level") = static_cast<int>(0), Arg("wta_k") = static_cast<int>(2), Arg("score_type") = static_cast<int>(cv::ORB::ScoreType::HARRIS_SCORE), Arg("patch_size") = static_cast<int>(31), Arg("fast_threshold") = static_cast<int>(20), Arg("blur_for_descriptor") = static_cast<bool>(false)).
    define_method<void(cv::cuda::ORB::*)(int)>("set_max_features", &cv::cuda::ORB::setMaxFeatures,
      Arg("max_features")).
    define_method<int(cv::cuda::ORB::*)() const>("get_max_features", &cv::cuda::ORB::getMaxFeatures).
    define_method<void(cv::cuda::ORB::*)(double)>("set_scale_factor", &cv::cuda::ORB::setScaleFactor,
      Arg("scale_factor")).
    define_method<double(cv::cuda::ORB::*)() const>("get_scale_factor", &cv::cuda::ORB::getScaleFactor).
    define_method<void(cv::cuda::ORB::*)(int)>("set_n_levels", &cv::cuda::ORB::setNLevels,
      Arg("nlevels")).
    define_method<int(cv::cuda::ORB::*)() const>("get_n_levels", &cv::cuda::ORB::getNLevels).
    define_method<void(cv::cuda::ORB::*)(int)>("set_edge_threshold", &cv::cuda::ORB::setEdgeThreshold,
      Arg("edge_threshold")).
    define_method<int(cv::cuda::ORB::*)() const>("get_edge_threshold", &cv::cuda::ORB::getEdgeThreshold).
    define_method<void(cv::cuda::ORB::*)(int)>("set_first_level", &cv::cuda::ORB::setFirstLevel,
      Arg("first_level")).
    define_method<int(cv::cuda::ORB::*)() const>("get_first_level", &cv::cuda::ORB::getFirstLevel).
    define_method<void(cv::cuda::ORB::*)(int)>("set_wta_k", &cv::cuda::ORB::setWTA_K,
      Arg("wta_k")).
    define_method<int(cv::cuda::ORB::*)() const>("get_wta_k", &cv::cuda::ORB::getWTA_K).
    define_method<void(cv::cuda::ORB::*)(int)>("set_score_type", &cv::cuda::ORB::setScoreType,
      Arg("score_type")).
    define_method<int(cv::cuda::ORB::*)() const>("get_score_type", &cv::cuda::ORB::getScoreType).
    define_method<void(cv::cuda::ORB::*)(int)>("set_patch_size", &cv::cuda::ORB::setPatchSize,
      Arg("patch_size")).
    define_method<int(cv::cuda::ORB::*)() const>("get_patch_size", &cv::cuda::ORB::getPatchSize).
    define_method<void(cv::cuda::ORB::*)(int)>("set_fast_threshold", &cv::cuda::ORB::setFastThreshold,
      Arg("fast_threshold")).
    define_method<int(cv::cuda::ORB::*)() const>("get_fast_threshold", &cv::cuda::ORB::getFastThreshold).
    define_method<void(cv::cuda::ORB::*)(bool)>("set_blur_for_descriptor", &cv::cuda::ORB::setBlurForDescriptor,
      Arg("blur_for_descriptor")).
    define_method<bool(cv::cuda::ORB::*)() const>("get_blur_for_descriptor?", &cv::cuda::ORB::getBlurForDescriptor);
}