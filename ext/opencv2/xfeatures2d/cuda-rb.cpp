#include <opencv2/xfeatures2d/cuda.hpp>
#include "cuda-rb.hpp"

using namespace Rice;

void Init_Xfeatures2d_Cuda()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::SURF_CUDA> rb_cCvCudaSURFCUDA = define_class_under<cv::cuda::SURF_CUDA>(rb_mCvCuda, "SURF_CUDA").
    define_constructor(Constructor<cv::cuda::SURF_CUDA>()).
    define_constructor(Constructor<cv::cuda::SURF_CUDA, double, int, int, bool, float, bool>(),
      Arg("_hessian_threshold"), Arg("_n_octaves") = static_cast<int>(4), Arg("_n_octave_layers") = static_cast<int>(2), Arg("_extended") = static_cast<bool>(false), Arg("_keypoints_ratio") = static_cast<float>(0.01f), Arg("_upright") = static_cast<bool>(false)).
    define_singleton_function<cv::Ptr<cv::cuda::SURF_CUDA>(*)(double, int, int, bool, float, bool)>("create", &cv::cuda::SURF_CUDA::create,
      Arg("_hessian_threshold"), Arg("_n_octaves") = static_cast<int>(4), Arg("_n_octave_layers") = static_cast<int>(2), Arg("_extended") = static_cast<bool>(false), Arg("_keypoints_ratio") = static_cast<float>(0.01f), Arg("_upright") = static_cast<bool>(false)).
    define_method<int(cv::cuda::SURF_CUDA::*)() const>("descriptor_size", &cv::cuda::SURF_CUDA::descriptorSize).
    define_method<int(cv::cuda::SURF_CUDA::*)() const>("default_norm", &cv::cuda::SURF_CUDA::defaultNorm).
    define_method<void(cv::cuda::SURF_CUDA::*)(const std::vector<cv::KeyPoint>&, cv::cuda::GpuMat&)>("upload_keypoints", &cv::cuda::SURF_CUDA::uploadKeypoints,
      Arg("keypoints"), Arg("keypoints_gpu")).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, std::vector<cv::KeyPoint>&)>("download_keypoints", &cv::cuda::SURF_CUDA::downloadKeypoints,
      Arg("keypoints_gpu"), Arg("keypoints")).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, std::vector<float>&)>("download_descriptors", &cv::cuda::SURF_CUDA::downloadDescriptors,
      Arg("descriptors_gpu"), Arg("descriptors")).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("call", &cv::cuda::SURF_CUDA::operator(),
      Arg("img"), Arg("mask"), Arg("keypoints")).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, bool)>("call", &cv::cuda::SURF_CUDA::operator(),
      Arg("img"), Arg("mask"), Arg("keypoints"), Arg("descriptors"), Arg("use_provided_keypoints") = static_cast<bool>(false)).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("detect", &cv::cuda::SURF_CUDA::detect,
      Arg("img"), Arg("mask"), Arg("keypoints")).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, std::vector<cv::KeyPoint>&)>("call", &cv::cuda::SURF_CUDA::operator(),
      Arg("img"), Arg("mask"), Arg("keypoints")).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, std::vector<cv::KeyPoint>&, cv::cuda::GpuMat&, bool)>("call", &cv::cuda::SURF_CUDA::operator(),
      Arg("img"), Arg("mask"), Arg("keypoints"), Arg("descriptors"), Arg("use_provided_keypoints") = static_cast<bool>(false)).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, bool)>("detect_with_descriptors", &cv::cuda::SURF_CUDA::detectWithDescriptors,
      Arg("img"), Arg("mask"), Arg("keypoints"), Arg("descriptors"), Arg("use_provided_keypoints") = static_cast<bool>(false)).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, std::vector<cv::KeyPoint>&, std::vector<float>&, bool)>("call", &cv::cuda::SURF_CUDA::operator(),
      Arg("img"), Arg("mask"), Arg("keypoints"), Arg("descriptors"), Arg("use_provided_keypoints") = static_cast<bool>(false)).
    define_method<void(cv::cuda::SURF_CUDA::*)()>("release_memory", &cv::cuda::SURF_CUDA::releaseMemory).
    define_attr("hessian_threshold", &cv::cuda::SURF_CUDA::hessianThreshold).
    define_attr("n_octaves", &cv::cuda::SURF_CUDA::nOctaves).
    define_attr("n_octave_layers", &cv::cuda::SURF_CUDA::nOctaveLayers).
    define_attr("extended", &cv::cuda::SURF_CUDA::extended).
    define_attr("upright", &cv::cuda::SURF_CUDA::upright).
    define_attr("keypoints_ratio", &cv::cuda::SURF_CUDA::keypointsRatio).
    define_attr("sum", &cv::cuda::SURF_CUDA::sum).
    define_attr("mask1", &cv::cuda::SURF_CUDA::mask1).
    define_attr("mask_sum", &cv::cuda::SURF_CUDA::maskSum).
    define_attr("det", &cv::cuda::SURF_CUDA::det).
    define_attr("trace", &cv::cuda::SURF_CUDA::trace).
    define_attr("max_pos_buffer", &cv::cuda::SURF_CUDA::maxPosBuffer);

  Enum<cv::cuda::SURF_CUDA::KeypointLayout> rb_cCvCudaSURFCUDAKeypointLayout = define_enum_under<cv::cuda::SURF_CUDA::KeypointLayout>("KeypointLayout", rb_cCvCudaSURFCUDA).
    define_value("X_ROW", cv::cuda::SURF_CUDA::KeypointLayout::X_ROW).
    define_value("Y_ROW", cv::cuda::SURF_CUDA::KeypointLayout::Y_ROW).
    define_value("LAPLACIAN_ROW", cv::cuda::SURF_CUDA::KeypointLayout::LAPLACIAN_ROW).
    define_value("OCTAVE_ROW", cv::cuda::SURF_CUDA::KeypointLayout::OCTAVE_ROW).
    define_value("SIZE_ROW", cv::cuda::SURF_CUDA::KeypointLayout::SIZE_ROW).
    define_value("ANGLE_ROW", cv::cuda::SURF_CUDA::KeypointLayout::ANGLE_ROW).
    define_value("HESSIAN_ROW", cv::cuda::SURF_CUDA::KeypointLayout::HESSIAN_ROW).
    define_value("ROWS_COUNT", cv::cuda::SURF_CUDA::KeypointLayout::ROWS_COUNT);
}
