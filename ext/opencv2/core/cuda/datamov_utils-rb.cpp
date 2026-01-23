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
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<uchar>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::ForceGlob<schar>> rb_cCvCudaDeviceForceGlobSchar = define_class_under<cv::cuda::device::ForceGlob<schar>>(rb_mCvCudaDevice, "ForceGlobSchar").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<schar>>()).
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<schar>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::ForceGlob<char>> rb_cCvCudaDeviceForceGlobChar = define_class_under<cv::cuda::device::ForceGlob<char>>(rb_mCvCudaDevice, "ForceGlobChar").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<char>>()).
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<char>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::ForceGlob<ushort>> rb_cCvCudaDeviceForceGlobUshort = define_class_under<cv::cuda::device::ForceGlob<ushort>>(rb_mCvCudaDevice, "ForceGlobUshort").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<ushort>>()).
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<ushort>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::ForceGlob<short>> rb_cCvCudaDeviceForceGlobShort = define_class_under<cv::cuda::device::ForceGlob<short>>(rb_mCvCudaDevice, "ForceGlobShort").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<short>>()).
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<short>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::ForceGlob<uint>> rb_cCvCudaDeviceForceGlobUint = define_class_under<cv::cuda::device::ForceGlob<uint>>(rb_mCvCudaDevice, "ForceGlobUint").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<uint>>()).
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<uint>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::ForceGlob<int>> rb_cCvCudaDeviceForceGlobInt = define_class_under<cv::cuda::device::ForceGlob<int>>(rb_mCvCudaDevice, "ForceGlobInt").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<int>>()).
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<int>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::ForceGlob<float>> rb_cCvCudaDeviceForceGlobFloat = define_class_under<cv::cuda::device::ForceGlob<float>>(rb_mCvCudaDevice, "ForceGlobFloat").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<float>>()).
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<float>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::ForceGlob<double>> rb_cCvCudaDeviceForceGlobDouble = define_class_under<cv::cuda::device::ForceGlob<double>>(rb_mCvCudaDevice, "ForceGlobDouble").
    define_constructor(Constructor<cv::cuda::device::ForceGlob<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::ForceGlob<double>::__forceinline__);
}