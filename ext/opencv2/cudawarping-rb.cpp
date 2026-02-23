#include <opencv2/cudawarping.hpp>
#include "cudawarping-rb.hpp"

using namespace Rice;

void Init_Cudawarping()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, int, int, cv::Scalar, cv::cuda::Stream&)>("remap", &cv::cuda::remap,
    Arg("src"), Arg("dst"), Arg("xmap"), Arg("ymap"), Arg("interpolation"), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<cv::Scalar>(cv::Scalar()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Size, double, double, int, cv::cuda::Stream&)>("resize", &cv::cuda::resize,
    Arg("src"), Arg("dst"), Arg("dsize"), Arg("fx") = static_cast<double>(0), Arg("fy") = static_cast<double>(0), Arg("interpolation") = static_cast<int>(cv::INTER_LINEAR), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::Size, int, int, cv::Scalar, cv::cuda::Stream&)>("warp_affine", &cv::cuda::warpAffine,
    Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<cv::Scalar>(cv::Scalar()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::UMat, cv::Size, int, int, cv::Scalar, cv::cuda::Stream&)>("warp_affine", &cv::cuda::warpAffine,
    Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<cv::Scalar>(cv::Scalar()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Mat, cv::Size, int, int, cv::Scalar, cv::cuda::Stream&)>("warp_affine", &cv::cuda::warpAffine,
    Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<cv::Scalar>(cv::Scalar()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, bool, cv::Size, cv::OutputArray, cv::OutputArray, cv::cuda::Stream&)>("build_warp_affine_maps", &cv::cuda::buildWarpAffineMaps,
    Arg("m"), Arg("inverse"), Arg("dsize"), Arg("xmap"), Arg("ymap"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::UMat, bool, cv::Size, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("build_warp_affine_maps", &cv::cuda::buildWarpAffineMaps,
    Arg("m"), Arg("inverse"), Arg("dsize"), Arg("xmap"), Arg("ymap"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::Mat, bool, cv::Size, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("build_warp_affine_maps", &cv::cuda::buildWarpAffineMaps,
    Arg("m"), Arg("inverse"), Arg("dsize"), Arg("xmap"), Arg("ymap"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::Size, int, int, cv::Scalar, cv::cuda::Stream&)>("warp_perspective", &cv::cuda::warpPerspective,
    Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<cv::Scalar>(cv::Scalar()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::UMat, cv::Size, int, int, cv::Scalar, cv::cuda::Stream&)>("warp_perspective", &cv::cuda::warpPerspective,
    Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<cv::Scalar>(cv::Scalar()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Mat, cv::Size, int, int, cv::Scalar, cv::cuda::Stream&)>("warp_perspective", &cv::cuda::warpPerspective,
    Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<cv::Scalar>(cv::Scalar()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, bool, cv::Size, cv::OutputArray, cv::OutputArray, cv::cuda::Stream&)>("build_warp_perspective_maps", &cv::cuda::buildWarpPerspectiveMaps,
    Arg("m"), Arg("inverse"), Arg("dsize"), Arg("xmap"), Arg("ymap"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::UMat, bool, cv::Size, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("build_warp_perspective_maps", &cv::cuda::buildWarpPerspectiveMaps,
    Arg("m"), Arg("inverse"), Arg("dsize"), Arg("xmap"), Arg("ymap"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::Mat, bool, cv::Size, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("build_warp_perspective_maps", &cv::cuda::buildWarpPerspectiveMaps,
    Arg("m"), Arg("inverse"), Arg("dsize"), Arg("xmap"), Arg("ymap"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Size, double, double, double, int, cv::cuda::Stream&)>("rotate", &cv::cuda::rotate,
    Arg("src"), Arg("dst"), Arg("dsize"), Arg("angle"), Arg("x_shift") = static_cast<double>(0), Arg("y_shift") = static_cast<double>(0), Arg("interpolation") = static_cast<int>(cv::INTER_LINEAR), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("pyr_down", &cv::cuda::pyrDown,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("pyr_up", &cv::cuda::pyrUp,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));
}
