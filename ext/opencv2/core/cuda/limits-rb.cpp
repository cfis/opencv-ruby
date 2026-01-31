#include <opencv2/core/cuda/limits.hpp>
#include "limits-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_Limits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::numeric_limits<bool>> rb_cCvCudaDeviceNumericLimitsBool = define_class_under<cv::cuda::device::numeric_limits<bool>>(rb_mCvCudaDevice, "NumericLimitsBool").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<bool>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<bool>::is_signed).
    define_singleton_function<bool(*)()>("min?", &cv::cuda::device::numeric_limits<bool>::min).
    define_singleton_function<bool(*)()>("max?", &cv::cuda::device::numeric_limits<bool>::max);

  Rice::Data_Type<cv::cuda::device::numeric_limits<signed char>> rb_cCvCudaDeviceNumericLimitsSignedChar = define_class_under<cv::cuda::device::numeric_limits<signed char>>(rb_mCvCudaDevice, "NumericLimitsSignedChar").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<signed char>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<signed char>::is_signed).
    define_singleton_function<signed char(*)()>("min", &cv::cuda::device::numeric_limits<signed char>::min).
    define_singleton_function<signed char(*)()>("max", &cv::cuda::device::numeric_limits<signed char>::max);

  Rice::Data_Type<cv::cuda::device::numeric_limits<unsigned char>> rb_cCvCudaDeviceNumericLimitsUnsignedChar = define_class_under<cv::cuda::device::numeric_limits<unsigned char>>(rb_mCvCudaDevice, "NumericLimitsUnsignedChar").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned char>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<unsigned char>::is_signed).
    define_singleton_function<unsigned char(*)()>("min", &cv::cuda::device::numeric_limits<unsigned char>::min).
    define_singleton_function<unsigned char(*)()>("max", &cv::cuda::device::numeric_limits<unsigned char>::max);

  Rice::Data_Type<cv::cuda::device::numeric_limits<short>> rb_cCvCudaDeviceNumericLimitsShort = define_class_under<cv::cuda::device::numeric_limits<short>>(rb_mCvCudaDevice, "NumericLimitsShort").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<short>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<short>::is_signed).
    define_singleton_function<short(*)()>("min", &cv::cuda::device::numeric_limits<short>::min).
    define_singleton_function<short(*)()>("max", &cv::cuda::device::numeric_limits<short>::max);

  Rice::Data_Type<cv::cuda::device::numeric_limits<unsigned short>> rb_cCvCudaDeviceNumericLimitsUnsignedShort = define_class_under<cv::cuda::device::numeric_limits<unsigned short>>(rb_mCvCudaDevice, "NumericLimitsUnsignedShort").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned short>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<unsigned short>::is_signed).
    define_singleton_function<unsigned short(*)()>("min", &cv::cuda::device::numeric_limits<unsigned short>::min).
    define_singleton_function<unsigned short(*)()>("max", &cv::cuda::device::numeric_limits<unsigned short>::max);

  Rice::Data_Type<cv::cuda::device::numeric_limits<int>> rb_cCvCudaDeviceNumericLimitsInt = define_class_under<cv::cuda::device::numeric_limits<int>>(rb_mCvCudaDevice, "NumericLimitsInt").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<int>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<int>::is_signed).
    define_singleton_function<int(*)()>("min", &cv::cuda::device::numeric_limits<int>::min).
    define_singleton_function<int(*)()>("max", &cv::cuda::device::numeric_limits<int>::max);

  Rice::Data_Type<cv::cuda::device::numeric_limits<unsigned int>> rb_cCvCudaDeviceNumericLimitsUnsignedInt = define_class_under<cv::cuda::device::numeric_limits<unsigned int>>(rb_mCvCudaDevice, "NumericLimitsUnsignedInt").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned int>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<unsigned int>::is_signed).
    define_singleton_function<unsigned int(*)()>("min", &cv::cuda::device::numeric_limits<unsigned int>::min).
    define_singleton_function<unsigned int(*)()>("max", &cv::cuda::device::numeric_limits<unsigned int>::max);

  Rice::Data_Type<cv::cuda::device::numeric_limits<float>> rb_cCvCudaDeviceNumericLimitsFloat = define_class_under<cv::cuda::device::numeric_limits<float>>(rb_mCvCudaDevice, "NumericLimitsFloat").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<float>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<float>::is_signed).
    define_singleton_function<float(*)()>("min", &cv::cuda::device::numeric_limits<float>::min).
    define_singleton_function<float(*)()>("max", &cv::cuda::device::numeric_limits<float>::max).
    define_singleton_function<float(*)()>("epsilon", &cv::cuda::device::numeric_limits<float>::epsilon);

  Rice::Data_Type<cv::cuda::device::numeric_limits<double>> rb_cCvCudaDeviceNumericLimitsDouble = define_class_under<cv::cuda::device::numeric_limits<double>>(rb_mCvCudaDevice, "NumericLimitsDouble").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<double>>()).
    define_constant("Is_signed", cv::cuda::device::numeric_limits<double>::is_signed).
    define_singleton_function<double(*)()>("min", &cv::cuda::device::numeric_limits<double>::min).
    define_singleton_function<double(*)()>("max", &cv::cuda::device::numeric_limits<double>::max).
    define_singleton_function<double(*)()>("epsilon", &cv::cuda::device::numeric_limits<double>::epsilon);
}