#include <opencv2/core/cuda/datamov_utils.hpp>
#include "datamov_utils-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_DatamovUtils()
{
  Class(rb_cObject).define_constant("OPENCV_CUDA_ASM_PTR", OPENCV_CUDA_ASM_PTR);

  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::ForceGlob<uchar>> rb_cCvCudaDeviceForceGlobUchar = define_class_under<cv::cuda::device::ForceGlob<uchar>>(rb_mCvCudaDevice, "ForceGlobUchar").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<uchar>>()).
    define_singleton_function<void(*)(const uchar*, int, uchar&)>("load", &cv::cuda::device::ForceGlob<uchar>::Load,
      ArgBuffer("ptr"), Arg("offset"), Arg("val"));

  Rice::Data_Type<cv::cuda::device::ForceGlob<schar>> rb_cCvCudaDeviceForceGlobSchar = define_class_under<cv::cuda::device::ForceGlob<schar>>(rb_mCvCudaDevice, "ForceGlobSchar").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<schar>>()).
    define_singleton_function<void(*)(const schar*, int, schar&)>("load", &cv::cuda::device::ForceGlob<schar>::Load,
      ArgBuffer("ptr"), Arg("offset"), Arg("val"));

  Rice::Data_Type<cv::cuda::device::ForceGlob<char>> rb_cCvCudaDeviceForceGlobChar = define_class_under<cv::cuda::device::ForceGlob<char>>(rb_mCvCudaDevice, "ForceGlobChar").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<char>>()).
    define_singleton_function<void(*)(const char*, int, char&)>("load", &cv::cuda::device::ForceGlob<char>::Load,
      Arg("ptr"), Arg("offset"), Arg("val"));

  Rice::Data_Type<cv::cuda::device::ForceGlob<ushort>> rb_cCvCudaDeviceForceGlobUshort = define_class_under<cv::cuda::device::ForceGlob<ushort>>(rb_mCvCudaDevice, "ForceGlobUshort").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<ushort>>()).
    define_singleton_function<void(*)(const ushort*, int, ushort&)>("load", &cv::cuda::device::ForceGlob<ushort>::Load,
      ArgBuffer("ptr"), Arg("offset"), Arg("val"));

  Rice::Data_Type<cv::cuda::device::ForceGlob<short>> rb_cCvCudaDeviceForceGlobShort = define_class_under<cv::cuda::device::ForceGlob<short>>(rb_mCvCudaDevice, "ForceGlobShort").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<short>>()).
    define_singleton_function<void(*)(const short*, int, short&)>("load", &cv::cuda::device::ForceGlob<short>::Load,
      ArgBuffer("ptr"), Arg("offset"), Arg("val"));

  Rice::Data_Type<cv::cuda::device::ForceGlob<uint>> rb_cCvCudaDeviceForceGlobUint = define_class_under<cv::cuda::device::ForceGlob<uint>>(rb_mCvCudaDevice, "ForceGlobUint").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<uint>>()).
    define_singleton_function<void(*)(const uint*, int, uint&)>("load", &cv::cuda::device::ForceGlob<uint>::Load,
      ArgBuffer("ptr"), Arg("offset"), Arg("val"));

  Rice::Data_Type<cv::cuda::device::ForceGlob<int>> rb_cCvCudaDeviceForceGlobInt = define_class_under<cv::cuda::device::ForceGlob<int>>(rb_mCvCudaDevice, "ForceGlobInt").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<int>>()).
    define_singleton_function<void(*)(const int*, int, int&)>("load", &cv::cuda::device::ForceGlob<int>::Load,
      ArgBuffer("ptr"), Arg("offset"), Arg("val"));

  Rice::Data_Type<cv::cuda::device::ForceGlob<float>> rb_cCvCudaDeviceForceGlobFloat = define_class_under<cv::cuda::device::ForceGlob<float>>(rb_mCvCudaDevice, "ForceGlobFloat").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<float>>()).
    define_singleton_function<void(*)(const float*, int, float&)>("load", &cv::cuda::device::ForceGlob<float>::Load,
      ArgBuffer("ptr"), Arg("offset"), Arg("val"));

  Rice::Data_Type<cv::cuda::device::ForceGlob<double>> rb_cCvCudaDeviceForceGlobDouble = define_class_under<cv::cuda::device::ForceGlob<double>>(rb_mCvCudaDevice, "ForceGlobDouble").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<double>>()).
    define_singleton_function<void(*)(const double*, int, double&)>("load", &cv::cuda::device::ForceGlob<double>::Load,
      ArgBuffer("ptr"), Arg("offset"), Arg("val"));
}
