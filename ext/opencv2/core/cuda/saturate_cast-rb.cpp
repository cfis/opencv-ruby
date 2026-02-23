#include <opencv2/core/cuda/saturate_cast.hpp>
#include "saturate_cast-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_SaturateCast()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  rb_mCvCudaDevice.define_module_function<uchar(*)(schar)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uchar(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uchar(*)(ushort)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uchar(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uchar(*)(uint)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uchar(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uchar(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<schar(*)(uchar)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<schar(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<schar(*)(ushort)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<schar(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<schar(*)(uint)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<schar(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<schar(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<ushort(*)(schar)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<ushort(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<ushort(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<ushort(*)(uint)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<ushort(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<ushort(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<short(*)(ushort)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<short(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<short(*)(uint)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<short(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<short(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<int(*)(uint)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<int(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<int(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uint(*)(schar)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uint(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uint(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uint(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

  rb_mCvCudaDevice.define_module_function<uint(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
}
