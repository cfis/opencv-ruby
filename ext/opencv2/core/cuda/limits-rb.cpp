#include <opencv2/core/cuda/limits.hpp>
#include "limits-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceNumericLimitsBool;
Rice::Class rb_cCvCudaDeviceNumericLimitsDouble;
Rice::Class rb_cCvCudaDeviceNumericLimitsFloat;
Rice::Class rb_cCvCudaDeviceNumericLimitsInt;
Rice::Class rb_cCvCudaDeviceNumericLimitsShort;
Rice::Class rb_cCvCudaDeviceNumericLimitsSignedChar;
Rice::Class rb_cCvCudaDeviceNumericLimitsUnsignedChar;
Rice::Class rb_cCvCudaDeviceNumericLimitsUnsignedInt;
Rice::Class rb_cCvCudaDeviceNumericLimitsUnsignedShort;

void Init_Limits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceNumericLimitsBool = define_class_under<cv::cuda::device::numeric_limits<bool>>(rb_mCvCudaDevice, "NumericLimitsBool").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<bool>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<bool>::__forceinline__);
  
  rb_cCvCudaDeviceNumericLimitsSignedChar = define_class_under<cv::cuda::device::numeric_limits<signed char>>(rb_mCvCudaDevice, "NumericLimitsSignedChar").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<signed char>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<signed char>::__forceinline__);
  
  rb_cCvCudaDeviceNumericLimitsUnsignedChar = define_class_under<cv::cuda::device::numeric_limits<unsigned char>>(rb_mCvCudaDevice, "NumericLimitsUnsignedChar").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned char>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<unsigned char>::__forceinline__);
  
  rb_cCvCudaDeviceNumericLimitsShort = define_class_under<cv::cuda::device::numeric_limits<short>>(rb_mCvCudaDevice, "NumericLimitsShort").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<short>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<short>::__forceinline__);
  
  rb_cCvCudaDeviceNumericLimitsUnsignedShort = define_class_under<cv::cuda::device::numeric_limits<unsigned short>>(rb_mCvCudaDevice, "NumericLimitsUnsignedShort").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned short>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<unsigned short>::__forceinline__);
  
  rb_cCvCudaDeviceNumericLimitsInt = define_class_under<cv::cuda::device::numeric_limits<int>>(rb_mCvCudaDevice, "NumericLimitsInt").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<int>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<int>::__forceinline__);
  
  rb_cCvCudaDeviceNumericLimitsUnsignedInt = define_class_under<cv::cuda::device::numeric_limits<unsigned int>>(rb_mCvCudaDevice, "NumericLimitsUnsignedInt").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned int>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<unsigned int>::__forceinline__);
  
  rb_cCvCudaDeviceNumericLimitsFloat = define_class_under<cv::cuda::device::numeric_limits<float>>(rb_mCvCudaDevice, "NumericLimitsFloat").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<float>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<float>::__forceinline__);
  
  rb_cCvCudaDeviceNumericLimitsDouble = define_class_under<cv::cuda::device::numeric_limits<double>>(rb_mCvCudaDevice, "NumericLimitsDouble").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<double>::__forceinline__);

}