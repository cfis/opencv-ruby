#include <opencv2/core/cuda/saturate_cast.hpp>
#include "saturate_cast-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_SaturateCast()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  rb_mCvCudaDevice.define_module_function<_Tp(*)(uchar)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<_Tp(*)(schar)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<_Tp(*)(ushort)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<_Tp(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<_Tp(*)(uint)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<_Tp(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<_Tp(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<_Tp(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);

  rb_mCvCudaDevice.define_constant("Saturate_cast", cv::cuda::device::saturate_cast);
}