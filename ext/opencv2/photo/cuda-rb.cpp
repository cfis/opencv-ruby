#include <opencv2/photo/cuda.hpp>
#include "cuda-rb.hpp"

using namespace Rice;

void Init_Photo_Cuda()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, int, int, int, cv::cuda::Stream&)>("non_local_means", &cv::cuda::nonLocalMeans,
    Arg("src"), Arg("dst"), Arg("h"), Arg("search_window") = static_cast<int>(21), Arg("block_size") = static_cast<int>(7), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, float, int, int, int, cv::cuda::Stream&)>("non_local_means", &cv::cuda::nonLocalMeans,
    Arg("src"), Arg("dst"), Arg("h"), Arg("search_window") = static_cast<int>(21), Arg("block_size") = static_cast<int>(7), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, int, int, cv::cuda::Stream&)>("fast_nl_means_denoising", &cv::cuda::fastNlMeansDenoising,
    Arg("src"), Arg("dst"), Arg("h"), Arg("search_window") = static_cast<int>(21), Arg("block_size") = static_cast<int>(7), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, float, int, int, cv::cuda::Stream&)>("fast_nl_means_denoising", &cv::cuda::fastNlMeansDenoising,
    Arg("src"), Arg("dst"), Arg("h"), Arg("search_window") = static_cast<int>(21), Arg("block_size") = static_cast<int>(7), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, float, int, int, cv::cuda::Stream&)>("fast_nl_means_denoising_colored", &cv::cuda::fastNlMeansDenoisingColored,
    Arg("src"), Arg("dst"), Arg("h_luminance"), Arg("photo_render"), Arg("search_window") = static_cast<int>(21), Arg("block_size") = static_cast<int>(7), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, float, float, int, int, cv::cuda::Stream&)>("fast_nl_means_denoising_colored", &cv::cuda::fastNlMeansDenoisingColored,
    Arg("src"), Arg("dst"), Arg("h_luminance"), Arg("photo_render"), Arg("search_window") = static_cast<int>(21), Arg("block_size") = static_cast<int>(7), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));
}
