#include <opencv2/core/cuda/common.hpp>
#include "common-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_Common()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  rb_mCvCuda.define_module_function<void(*)(cudaError_t, const char*, const int, const char*)>("check_cuda_error", &cv::cuda::checkCudaError,
    Arg("err"), Arg("file"), Arg("line"), Arg("func"));

  rb_mCvCuda.define_module_function<bool(*)(size_t, size_t)>("aligned?", &cv::cuda::isAligned,
    Arg("step"), Arg("size"));

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  rb_mCvCudaDevice.define_module_function<int(*)(int, int)>("div_up", &cv::cuda::device::divUp,
    Arg("total"), Arg("grain"));
}