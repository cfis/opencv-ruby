#include <opencv2/core/cuda/functional.hpp>
#include "functional-rb.hpp"

using namespace Rice;

#include "functional-rb.ipp"

void Init_Core_Cuda_Functional()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::binary_function<unsigned char, unsigned char, unsigned char>> rb_cBinaryFunctionUnsignedCharUnsignedCharUnsignedChar = binary_function_instantiate<unsigned char, unsigned char, unsigned char>(rb_mCvCudaDevice, "BinaryFunctionUnsignedCharUnsignedCharUnsignedChar");
  Rice::Data_Type<cv::cuda::device::maximum<uchar>> rb_cCvCudaDeviceMaximumUchar = define_class_under<cv::cuda::device::maximum<uchar>, cv::cuda::device::binary_function<unsigned char, unsigned char, unsigned char>>(rb_mCvCudaDevice, "MaximumUchar").
    define_method<uchar(cv::cuda::device::maximum<uchar>::*)(uchar, uchar) const>("call", &cv::cuda::device::maximum<uchar>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<uchar>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<uchar>, const cv::cuda::device::maximum<uchar>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<signed char, signed char, signed char>> rb_cBinaryFunctionSignedCharSignedCharSignedChar = binary_function_instantiate<signed char, signed char, signed char>(rb_mCvCudaDevice, "BinaryFunctionSignedCharSignedCharSignedChar");
  Rice::Data_Type<cv::cuda::device::maximum<schar>> rb_cCvCudaDeviceMaximumSchar = define_class_under<cv::cuda::device::maximum<schar>, cv::cuda::device::binary_function<signed char, signed char, signed char>>(rb_mCvCudaDevice, "MaximumSchar").
    define_method<schar(cv::cuda::device::maximum<schar>::*)(schar, schar) const>("call", &cv::cuda::device::maximum<schar>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<schar>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<schar>, const cv::cuda::device::maximum<schar>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<char, char, char>> rb_cBinaryFunctionCharCharChar = binary_function_instantiate<char, char, char>(rb_mCvCudaDevice, "BinaryFunctionCharCharChar");
  Rice::Data_Type<cv::cuda::device::maximum<char>> rb_cCvCudaDeviceMaximumChar = define_class_under<cv::cuda::device::maximum<char>, cv::cuda::device::binary_function<char, char, char>>(rb_mCvCudaDevice, "MaximumChar").
    define_method<char(cv::cuda::device::maximum<char>::*)(char, char) const>("call", &cv::cuda::device::maximum<char>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<char>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<char>, const cv::cuda::device::maximum<char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<unsigned short, unsigned short, unsigned short>> rb_cBinaryFunctionUnsignedShortUnsignedShortUnsignedShort = binary_function_instantiate<unsigned short, unsigned short, unsigned short>(rb_mCvCudaDevice, "BinaryFunctionUnsignedShortUnsignedShortUnsignedShort");
  Rice::Data_Type<cv::cuda::device::maximum<ushort>> rb_cCvCudaDeviceMaximumUshort = define_class_under<cv::cuda::device::maximum<ushort>, cv::cuda::device::binary_function<unsigned short, unsigned short, unsigned short>>(rb_mCvCudaDevice, "MaximumUshort").
    define_method<ushort(cv::cuda::device::maximum<ushort>::*)(ushort, ushort) const>("call", &cv::cuda::device::maximum<ushort>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<ushort>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<ushort>, const cv::cuda::device::maximum<ushort>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<short, short, short>> rb_cBinaryFunctionShortShortShort = binary_function_instantiate<short, short, short>(rb_mCvCudaDevice, "BinaryFunctionShortShortShort");
  Rice::Data_Type<cv::cuda::device::maximum<short>> rb_cCvCudaDeviceMaximumShort = define_class_under<cv::cuda::device::maximum<short>, cv::cuda::device::binary_function<short, short, short>>(rb_mCvCudaDevice, "MaximumShort").
    define_method<short(cv::cuda::device::maximum<short>::*)(short, short) const>("call", &cv::cuda::device::maximum<short>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<short>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<short>, const cv::cuda::device::maximum<short>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<int, int, int>> rb_cBinaryFunctionIntIntInt = binary_function_instantiate<int, int, int>(rb_mCvCudaDevice, "BinaryFunctionIntIntInt");
  Rice::Data_Type<cv::cuda::device::maximum<int>> rb_cCvCudaDeviceMaximumInt = define_class_under<cv::cuda::device::maximum<int>, cv::cuda::device::binary_function<int, int, int>>(rb_mCvCudaDevice, "MaximumInt").
    define_method<int(cv::cuda::device::maximum<int>::*)(int, int) const>("call", &cv::cuda::device::maximum<int>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<int>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<int>, const cv::cuda::device::maximum<int>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<unsigned int, unsigned int, unsigned int>> rb_cBinaryFunctionUnsignedIntUnsignedIntUnsignedInt = binary_function_instantiate<unsigned int, unsigned int, unsigned int>(rb_mCvCudaDevice, "BinaryFunctionUnsignedIntUnsignedIntUnsignedInt");
  Rice::Data_Type<cv::cuda::device::maximum<uint>> rb_cCvCudaDeviceMaximumUint = define_class_under<cv::cuda::device::maximum<uint>, cv::cuda::device::binary_function<unsigned int, unsigned int, unsigned int>>(rb_mCvCudaDevice, "MaximumUint").
    define_method<uint(cv::cuda::device::maximum<uint>::*)(uint, uint) const>("call", &cv::cuda::device::maximum<uint>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<uint>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<uint>, const cv::cuda::device::maximum<uint>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<float, float, float>> rb_cBinaryFunctionFloatFloatFloat = binary_function_instantiate<float, float, float>(rb_mCvCudaDevice, "BinaryFunctionFloatFloatFloat");
  Rice::Data_Type<cv::cuda::device::maximum<float>> rb_cCvCudaDeviceMaximumFloat = define_class_under<cv::cuda::device::maximum<float>, cv::cuda::device::binary_function<float, float, float>>(rb_mCvCudaDevice, "MaximumFloat").
    define_method<float(cv::cuda::device::maximum<float>::*)(float, float) const>("call", &cv::cuda::device::maximum<float>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<float>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<float>, const cv::cuda::device::maximum<float>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<double, double, double>> rb_cBinaryFunctionDoubleDoubleDouble = binary_function_instantiate<double, double, double>(rb_mCvCudaDevice, "BinaryFunctionDoubleDoubleDouble");
  Rice::Data_Type<cv::cuda::device::maximum<double>> rb_cCvCudaDeviceMaximumDouble = define_class_under<cv::cuda::device::maximum<double>, cv::cuda::device::binary_function<double, double, double>>(rb_mCvCudaDevice, "MaximumDouble").
    define_method<double(cv::cuda::device::maximum<double>::*)(double, double) const>("call", &cv::cuda::device::maximum<double>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<double>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<double>, const cv::cuda::device::maximum<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<uchar>> rb_cCvCudaDeviceMinimumUchar = define_class_under<cv::cuda::device::minimum<uchar>, cv::cuda::device::binary_function<unsigned char, unsigned char, unsigned char>>(rb_mCvCudaDevice, "MinimumUchar").
    define_method<uchar(cv::cuda::device::minimum<uchar>::*)(uchar, uchar) const>("call", &cv::cuda::device::minimum<uchar>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<uchar>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<uchar>, const cv::cuda::device::minimum<uchar>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<schar>> rb_cCvCudaDeviceMinimumSchar = define_class_under<cv::cuda::device::minimum<schar>, cv::cuda::device::binary_function<signed char, signed char, signed char>>(rb_mCvCudaDevice, "MinimumSchar").
    define_method<schar(cv::cuda::device::minimum<schar>::*)(schar, schar) const>("call", &cv::cuda::device::minimum<schar>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<schar>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<schar>, const cv::cuda::device::minimum<schar>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<char>> rb_cCvCudaDeviceMinimumChar = define_class_under<cv::cuda::device::minimum<char>, cv::cuda::device::binary_function<char, char, char>>(rb_mCvCudaDevice, "MinimumChar").
    define_method<char(cv::cuda::device::minimum<char>::*)(char, char) const>("call", &cv::cuda::device::minimum<char>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<char>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<char>, const cv::cuda::device::minimum<char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<ushort>> rb_cCvCudaDeviceMinimumUshort = define_class_under<cv::cuda::device::minimum<ushort>, cv::cuda::device::binary_function<unsigned short, unsigned short, unsigned short>>(rb_mCvCudaDevice, "MinimumUshort").
    define_method<ushort(cv::cuda::device::minimum<ushort>::*)(ushort, ushort) const>("call", &cv::cuda::device::minimum<ushort>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<ushort>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<ushort>, const cv::cuda::device::minimum<ushort>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<short>> rb_cCvCudaDeviceMinimumShort = define_class_under<cv::cuda::device::minimum<short>, cv::cuda::device::binary_function<short, short, short>>(rb_mCvCudaDevice, "MinimumShort").
    define_method<short(cv::cuda::device::minimum<short>::*)(short, short) const>("call", &cv::cuda::device::minimum<short>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<short>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<short>, const cv::cuda::device::minimum<short>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<int>> rb_cCvCudaDeviceMinimumInt = define_class_under<cv::cuda::device::minimum<int>, cv::cuda::device::binary_function<int, int, int>>(rb_mCvCudaDevice, "MinimumInt").
    define_method<int(cv::cuda::device::minimum<int>::*)(int, int) const>("call", &cv::cuda::device::minimum<int>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<int>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<int>, const cv::cuda::device::minimum<int>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<uint>> rb_cCvCudaDeviceMinimumUint = define_class_under<cv::cuda::device::minimum<uint>, cv::cuda::device::binary_function<unsigned int, unsigned int, unsigned int>>(rb_mCvCudaDevice, "MinimumUint").
    define_method<uint(cv::cuda::device::minimum<uint>::*)(uint, uint) const>("call", &cv::cuda::device::minimum<uint>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<uint>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<uint>, const cv::cuda::device::minimum<uint>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<float>> rb_cCvCudaDeviceMinimumFloat = define_class_under<cv::cuda::device::minimum<float>, cv::cuda::device::binary_function<float, float, float>>(rb_mCvCudaDevice, "MinimumFloat").
    define_method<float(cv::cuda::device::minimum<float>::*)(float, float) const>("call", &cv::cuda::device::minimum<float>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<float>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<float>, const cv::cuda::device::minimum<float>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::minimum<double>> rb_cCvCudaDeviceMinimumDouble = define_class_under<cv::cuda::device::minimum<double>, cv::cuda::device::binary_function<double, double, double>>(rb_mCvCudaDevice, "MinimumDouble").
    define_method<double(cv::cuda::device::minimum<double>::*)(double, double) const>("call", &cv::cuda::device::minimum<double>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<double>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<double>, const cv::cuda::device::minimum<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<unsigned char, unsigned char>> rb_cUnaryFunctionUnsignedCharUnsignedChar = unary_function_instantiate<unsigned char, unsigned char>(rb_mCvCudaDevice, "UnaryFunctionUnsignedCharUnsignedChar");
  Rice::Data_Type<cv::cuda::device::abs_func<unsigned char>> rb_cCvCudaDeviceAbsFuncUnsignedChar = define_class_under<cv::cuda::device::abs_func<unsigned char>, cv::cuda::device::unary_function<unsigned char, unsigned char>>(rb_mCvCudaDevice, "AbsFuncUnsignedChar").
    define_method<unsigned char(cv::cuda::device::abs_func<unsigned char>::*)(unsigned char) const>("call", &cv::cuda::device::abs_func<unsigned char>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned char>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned char>, const cv::cuda::device::abs_func<unsigned char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<signed char, signed char>> rb_cUnaryFunctionSignedCharSignedChar = unary_function_instantiate<signed char, signed char>(rb_mCvCudaDevice, "UnaryFunctionSignedCharSignedChar");
  Rice::Data_Type<cv::cuda::device::abs_func<signed char>> rb_cCvCudaDeviceAbsFuncSignedChar = define_class_under<cv::cuda::device::abs_func<signed char>, cv::cuda::device::unary_function<signed char, signed char>>(rb_mCvCudaDevice, "AbsFuncSignedChar").
    define_method<signed char(cv::cuda::device::abs_func<signed char>::*)(signed char) const>("call", &cv::cuda::device::abs_func<signed char>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<signed char>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<signed char>, const cv::cuda::device::abs_func<signed char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<char, char>> rb_cUnaryFunctionCharChar = unary_function_instantiate<char, char>(rb_mCvCudaDevice, "UnaryFunctionCharChar");
  Rice::Data_Type<cv::cuda::device::abs_func<char>> rb_cCvCudaDeviceAbsFuncChar = define_class_under<cv::cuda::device::abs_func<char>, cv::cuda::device::unary_function<char, char>>(rb_mCvCudaDevice, "AbsFuncChar").
    define_method<char(cv::cuda::device::abs_func<char>::*)(char) const>("call", &cv::cuda::device::abs_func<char>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<char>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<char>, const cv::cuda::device::abs_func<char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<unsigned short, unsigned short>> rb_cUnaryFunctionUnsignedShortUnsignedShort = unary_function_instantiate<unsigned short, unsigned short>(rb_mCvCudaDevice, "UnaryFunctionUnsignedShortUnsignedShort");
  Rice::Data_Type<cv::cuda::device::abs_func<unsigned short>> rb_cCvCudaDeviceAbsFuncUnsignedShort = define_class_under<cv::cuda::device::abs_func<unsigned short>, cv::cuda::device::unary_function<unsigned short, unsigned short>>(rb_mCvCudaDevice, "AbsFuncUnsignedShort").
    define_method<unsigned short(cv::cuda::device::abs_func<unsigned short>::*)(unsigned short) const>("call", &cv::cuda::device::abs_func<unsigned short>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned short>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned short>, const cv::cuda::device::abs_func<unsigned short>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<short, short>> rb_cUnaryFunctionShortShort = unary_function_instantiate<short, short>(rb_mCvCudaDevice, "UnaryFunctionShortShort");
  Rice::Data_Type<cv::cuda::device::abs_func<short>> rb_cCvCudaDeviceAbsFuncShort = define_class_under<cv::cuda::device::abs_func<short>, cv::cuda::device::unary_function<short, short>>(rb_mCvCudaDevice, "AbsFuncShort").
    define_method<short(cv::cuda::device::abs_func<short>::*)(short) const>("call", &cv::cuda::device::abs_func<short>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<short>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<short>, const cv::cuda::device::abs_func<short>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<unsigned int, unsigned int>> rb_cUnaryFunctionUnsignedIntUnsignedInt = unary_function_instantiate<unsigned int, unsigned int>(rb_mCvCudaDevice, "UnaryFunctionUnsignedIntUnsignedInt");
  Rice::Data_Type<cv::cuda::device::abs_func<unsigned int>> rb_cCvCudaDeviceAbsFuncUnsignedInt = define_class_under<cv::cuda::device::abs_func<unsigned int>, cv::cuda::device::unary_function<unsigned int, unsigned int>>(rb_mCvCudaDevice, "AbsFuncUnsignedInt").
    define_method<unsigned int(cv::cuda::device::abs_func<unsigned int>::*)(unsigned int) const>("call", &cv::cuda::device::abs_func<unsigned int>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned int>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned int>, const cv::cuda::device::abs_func<unsigned int>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<int, int>> rb_cUnaryFunctionIntInt = unary_function_instantiate<int, int>(rb_mCvCudaDevice, "UnaryFunctionIntInt");
  Rice::Data_Type<cv::cuda::device::abs_func<int>> rb_cCvCudaDeviceAbsFuncInt = define_class_under<cv::cuda::device::abs_func<int>, cv::cuda::device::unary_function<int, int>>(rb_mCvCudaDevice, "AbsFuncInt").
    define_method<int(cv::cuda::device::abs_func<int>::*)(int) const>("call", &cv::cuda::device::abs_func<int>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<int>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<int>, const cv::cuda::device::abs_func<int>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<float, float>> rb_cUnaryFunctionFloatFloat = unary_function_instantiate<float, float>(rb_mCvCudaDevice, "UnaryFunctionFloatFloat");
  Rice::Data_Type<cv::cuda::device::abs_func<float>> rb_cCvCudaDeviceAbsFuncFloat = define_class_under<cv::cuda::device::abs_func<float>, cv::cuda::device::unary_function<float, float>>(rb_mCvCudaDevice, "AbsFuncFloat").
    define_method<float(cv::cuda::device::abs_func<float>::*)(float) const>("call", &cv::cuda::device::abs_func<float>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<float>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<float>, const cv::cuda::device::abs_func<float>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<double, double>> rb_cUnaryFunctionDoubleDouble = unary_function_instantiate<double, double>(rb_mCvCudaDevice, "UnaryFunctionDoubleDouble");
  Rice::Data_Type<cv::cuda::device::abs_func<double>> rb_cCvCudaDeviceAbsFuncDouble = define_class_under<cv::cuda::device::abs_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "AbsFuncDouble").
    define_method<double(cv::cuda::device::abs_func<double>::*)(double) const>("call", &cv::cuda::device::abs_func<double>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<double>, const cv::cuda::device::abs_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::sqrt_func<double>> rb_cCvCudaDeviceSqrtFuncDouble = define_class_under<cv::cuda::device::sqrt_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "SqrtFuncDouble").
    define_method<double(cv::cuda::device::sqrt_func<double>::*)(double) const>("call", &cv::cuda::device::sqrt_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sqrt_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::sqrt_func<double>, const cv::cuda::device::sqrt_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::exp_func<double>> rb_cCvCudaDeviceExpFuncDouble = define_class_under<cv::cuda::device::exp_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "ExpFuncDouble").
    define_method<double(cv::cuda::device::exp_func<double>::*)(double) const>("call", &cv::cuda::device::exp_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::exp_func<double>, const cv::cuda::device::exp_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::exp2_func<double>> rb_cCvCudaDeviceExp2FuncDouble = define_class_under<cv::cuda::device::exp2_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "Exp2FuncDouble").
    define_method<double(cv::cuda::device::exp2_func<double>::*)(double) const>("call", &cv::cuda::device::exp2_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp2_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::exp2_func<double>, const cv::cuda::device::exp2_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::exp10_func<double>> rb_cCvCudaDeviceExp10FuncDouble = define_class_under<cv::cuda::device::exp10_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "Exp10FuncDouble").
    define_method<double(cv::cuda::device::exp10_func<double>::*)(double) const>("call", &cv::cuda::device::exp10_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp10_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::exp10_func<double>, const cv::cuda::device::exp10_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::log_func<double>> rb_cCvCudaDeviceLogFuncDouble = define_class_under<cv::cuda::device::log_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "LogFuncDouble").
    define_method<double(cv::cuda::device::log_func<double>::*)(double) const>("call", &cv::cuda::device::log_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::log_func<double>, const cv::cuda::device::log_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::log2_func<double>> rb_cCvCudaDeviceLog2FuncDouble = define_class_under<cv::cuda::device::log2_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "Log2FuncDouble").
    define_method<double(cv::cuda::device::log2_func<double>::*)(double) const>("call", &cv::cuda::device::log2_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log2_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::log2_func<double>, const cv::cuda::device::log2_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::log10_func<double>> rb_cCvCudaDeviceLog10FuncDouble = define_class_under<cv::cuda::device::log10_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "Log10FuncDouble").
    define_method<double(cv::cuda::device::log10_func<double>::*)(double) const>("call", &cv::cuda::device::log10_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log10_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::log10_func<double>, const cv::cuda::device::log10_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::sin_func<double>> rb_cCvCudaDeviceSinFuncDouble = define_class_under<cv::cuda::device::sin_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "SinFuncDouble").
    define_method<double(cv::cuda::device::sin_func<double>::*)(double) const>("call", &cv::cuda::device::sin_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sin_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::sin_func<double>, const cv::cuda::device::sin_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::cos_func<double>> rb_cCvCudaDeviceCosFuncDouble = define_class_under<cv::cuda::device::cos_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "CosFuncDouble").
    define_method<double(cv::cuda::device::cos_func<double>::*)(double) const>("call", &cv::cuda::device::cos_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::cos_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::cos_func<double>, const cv::cuda::device::cos_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::tan_func<double>> rb_cCvCudaDeviceTanFuncDouble = define_class_under<cv::cuda::device::tan_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "TanFuncDouble").
    define_method<double(cv::cuda::device::tan_func<double>::*)(double) const>("call", &cv::cuda::device::tan_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::tan_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::tan_func<double>, const cv::cuda::device::tan_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::asin_func<double>> rb_cCvCudaDeviceAsinFuncDouble = define_class_under<cv::cuda::device::asin_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "AsinFuncDouble").
    define_method<double(cv::cuda::device::asin_func<double>::*)(double) const>("call", &cv::cuda::device::asin_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::asin_func<double>>());

  Rice::Data_Type<cv::cuda::device::acos_func<double>> rb_cCvCudaDeviceAcosFuncDouble = define_class_under<cv::cuda::device::acos_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "AcosFuncDouble").
    define_method<double(cv::cuda::device::acos_func<double>::*)(double) const>("call", &cv::cuda::device::acos_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::acos_func<double>>());

  Rice::Data_Type<cv::cuda::device::atan_func<double>> rb_cCvCudaDeviceAtanFuncDouble = define_class_under<cv::cuda::device::atan_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "AtanFuncDouble").
    define_method<double(cv::cuda::device::atan_func<double>::*)(double) const>("call", &cv::cuda::device::atan_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::atan_func<double>>());

  Rice::Data_Type<cv::cuda::device::sinh_func<double>> rb_cCvCudaDeviceSinhFuncDouble = define_class_under<cv::cuda::device::sinh_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "SinhFuncDouble").
    define_method<double(cv::cuda::device::sinh_func<double>::*)(double) const>("call", &cv::cuda::device::sinh_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sinh_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::sinh_func<double>, const cv::cuda::device::sinh_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::cosh_func<double>> rb_cCvCudaDeviceCoshFuncDouble = define_class_under<cv::cuda::device::cosh_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "CoshFuncDouble").
    define_method<double(cv::cuda::device::cosh_func<double>::*)(double) const>("call", &cv::cuda::device::cosh_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::cosh_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::cosh_func<double>, const cv::cuda::device::cosh_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::tanh_func<double>> rb_cCvCudaDeviceTanhFuncDouble = define_class_under<cv::cuda::device::tanh_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "TanhFuncDouble").
    define_method<double(cv::cuda::device::tanh_func<double>::*)(double) const>("call", &cv::cuda::device::tanh_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::tanh_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::tanh_func<double>, const cv::cuda::device::tanh_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::asinh_func<double>> rb_cCvCudaDeviceAsinhFuncDouble = define_class_under<cv::cuda::device::asinh_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "AsinhFuncDouble").
    define_method<double(cv::cuda::device::asinh_func<double>::*)(double) const>("call", &cv::cuda::device::asinh_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::asinh_func<double>>());

  Rice::Data_Type<cv::cuda::device::acosh_func<double>> rb_cCvCudaDeviceAcoshFuncDouble = define_class_under<cv::cuda::device::acosh_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "AcoshFuncDouble").
    define_method<double(cv::cuda::device::acosh_func<double>::*)(double) const>("call", &cv::cuda::device::acosh_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::acosh_func<double>>());

  Rice::Data_Type<cv::cuda::device::atanh_func<double>> rb_cCvCudaDeviceAtanhFuncDouble = define_class_under<cv::cuda::device::atanh_func<double>, cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "AtanhFuncDouble").
    define_method<double(cv::cuda::device::atanh_func<double>::*)(double) const>("call", &cv::cuda::device::atanh_func<double>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::atanh_func<double>>());

  Rice::Data_Type<cv::cuda::device::hypot_func<double>> rb_cCvCudaDeviceHypotFuncDouble = define_class_under<cv::cuda::device::hypot_func<double>, cv::cuda::device::binary_function<double, double, double>>(rb_mCvCudaDevice, "HypotFuncDouble").
    define_method<double(cv::cuda::device::hypot_func<double>::*)(double, double) const>("call", &cv::cuda::device::hypot_func<double>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::hypot_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::hypot_func<double>, const cv::cuda::device::hypot_func<double>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::atan2_func<double>> rb_cCvCudaDeviceAtan2FuncDouble = define_class_under<cv::cuda::device::atan2_func<double>, cv::cuda::device::binary_function<double, double, double>>(rb_mCvCudaDevice, "Atan2FuncDouble").
    define_method<double(cv::cuda::device::atan2_func<double>::*)(double, double) const>("call", &cv::cuda::device::atan2_func<double>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::atan2_func<double>>());

  Rice::Data_Type<cv::cuda::device::pow_func<double>> rb_cCvCudaDevicePowFuncDouble = define_class_under<cv::cuda::device::pow_func<double>, cv::cuda::device::binary_function<double, double, double>>(rb_mCvCudaDevice, "PowFuncDouble").
    define_method<double(cv::cuda::device::pow_func<double>::*)(double, double) const>("call", &cv::cuda::device::pow_func<double>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::pow_func<double>>()).
    define_constructor(Constructor<cv::cuda::device::pow_func<double>, const cv::cuda::device::pow_func<double>&>(),
      Arg("arg_0"));

  Module rb_mCvCudaDeviceFunctionalDetail = define_module_under(rb_mCvCudaDevice, "FunctionalDetail");
}