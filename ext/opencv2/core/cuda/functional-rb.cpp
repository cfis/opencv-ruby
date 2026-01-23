#include <opencv2/core/cuda/functional.hpp>
#include "functional-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Argument, typename Result>
inline void unary_function_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename Argument1, typename Argument2, typename Result>
inline void binary_function_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void plus_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::plus<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void minus_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::minus<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void multiplies_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::multiplies<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void divides_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::divides<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void modulus_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::modulus<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void negate_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::negate<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void equal_to_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::equal_to<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void not_equal_to_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::not_equal_to<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void greater_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::greater<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void less_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::less<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void greater_equal_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::greater_equal<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void less_equal_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::less_equal<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void logical_and_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::logical_and<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void logical_or_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::logical_or<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void logical_not_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::logical_not<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void bit_and_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::bit_and<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void bit_or_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::bit_or<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void bit_xor_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::bit_xor<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void bit_not_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::bit_not<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void identity_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::identity<T>::__forceinline__);
};

template<typename Data_Type_T, typename T1, typename T2>
inline void project1st_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::project1st<T1, T2>::__forceinline__);
};

template<typename Data_Type_T, typename T1, typename T2>
inline void project2nd_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::project2nd<T1, T2>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void maximum_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::maximum<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void minimum_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::minimum<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void abs_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::abs_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void sqrt_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::sqrt_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void exp_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::exp_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void exp2_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::exp2_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void exp10_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::exp10_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void log_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::log_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void log2_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::log2_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void log10_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::log10_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void sin_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::sin_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void cos_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::cos_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void tan_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::tan_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void asin_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::asin_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void acos_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::acos_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void atan_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::atan_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void sinh_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::sinh_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void cosh_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::cosh_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void tanh_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::tanh_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void asinh_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::asinh_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void acosh_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::acosh_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void atanh_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::atanh_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void hypot_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::hypot_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void atan2_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::atan2_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void pow_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::pow_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void hypot_sqr_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::hypot_sqr_func<T>::__forceinline__);
};

template<typename Data_Type_T, typename T, typename D>
inline void saturate_cast_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::saturate_cast_func<T, D>::__forceinline__);
};

template<typename Data_Type_T, typename T>
inline void thresh_binary_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::thresh_binary_func<T>::__device__).
    define_attr("max_val", &cv::cuda::device::thresh_binary_func<T>::maxVal);
};

template<typename Data_Type_T, typename T>
inline void thresh_binary_inv_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::thresh_binary_inv_func<T>::__device__).
    define_attr("max_val", &cv::cuda::device::thresh_binary_inv_func<T>::maxVal);
};

template<typename Data_Type_T, typename T>
inline void thresh_trunc_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::thresh_trunc_func<T>::__device__);
};

template<typename Data_Type_T, typename T>
inline void thresh_to_zero_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::thresh_to_zero_func<T>::__device__);
};

template<typename Data_Type_T, typename T>
inline void thresh_to_zero_inv_func_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::thresh_to_zero_inv_func<T>::__device__);
};

template<typename Data_Type_T, typename Predicate>
inline void unary_negate_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::unary_negate<Predicate>::__device__);
};

template<typename Data_Type_T, typename Predicate>
inline void binary_negate_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::binary_negate<Predicate>::__device__);
};

template<typename Data_Type_T, typename Op>
inline void binder1st_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::binder1st<Op>::__device__).
    define_attr("arg1", &cv::cuda::device::binder1st<Op>::arg1);
};

template<typename Data_Type_T, typename Op>
inline void binder2nd_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::binder2nd<Op>::__device__).
    define_attr("arg2", &cv::cuda::device::binder2nd<Op>::arg2);
};

template<typename Data_Type_T, typename F>
inline void IsUnaryFunction_builder(Data_Type_T& klass)
{
  klass.Rice::Data_Type<cv::cuda::device::IsUnaryFunction::No> rb_cCvCudaDeviceIsUnaryFunctionNo = define_class<cv::cuda::device::IsUnaryFunction::No>("No").
      define_constructor(Constructor<cv::cuda::device::IsUnaryFunction::No>());.
    define_constant("Value", (int)cv::cuda::device::IsUnaryFunction<F>::value).
    template define_singleton_function<cv::cuda::device::IsUnaryFunction<F>::No(*)()>("check", &cv::cuda::device::IsUnaryFunction<F>::check).
    define_singleton_function("make_f", &cv::cuda::device::IsUnaryFunction<F>::makeF);
};

template<typename Data_Type_T, typename F>
inline void IsBinaryFunction_builder(Data_Type_T& klass)
{
  klass.Rice::Data_Type<cv::cuda::device::IsBinaryFunction::No> rb_cCvCudaDeviceIsBinaryFunctionNo = define_class<cv::cuda::device::IsBinaryFunction::No>("No").
      define_constructor(Constructor<cv::cuda::device::IsBinaryFunction::No>());.
    define_constant("Value", (int)cv::cuda::device::IsBinaryFunction<F>::value).
    template define_singleton_function<cv::cuda::device::IsBinaryFunction<F>::No(*)()>("check", &cv::cuda::device::IsBinaryFunction<F>::check).
    define_singleton_function("make_f", &cv::cuda::device::IsBinaryFunction<F>::makeF);
};

template<typename Data_Type_T, size_t src_elem_size, size_t dst_elem_size>
inline void UnOpShift_builder(Data_Type_T& klass)
{
  klass.define_constant("Shift", (int)cv::cuda::device::functional_detail::UnOpShift<src_elem_size, dst_elem_size>::shift);
};

template<typename Data_Type_T, typename T, typename D>
inline void DefaultUnaryShift_builder(Data_Type_T& klass)
{
  klass.define_constant("Shift", (int)cv::cuda::device::functional_detail::DefaultUnaryShift<T, D>::shift);
};

template<typename Data_Type_T, size_t src_elem_size1, size_t src_elem_size2, size_t dst_elem_size>
inline void BinOpShift_builder(Data_Type_T& klass)
{
  klass.define_constant("Shift", (int)cv::cuda::device::functional_detail::BinOpShift<src_elem_size1, src_elem_size2, dst_elem_size>::shift);
};

template<typename Data_Type_T, typename T1, typename T2, typename D>
inline void DefaultBinaryShift_builder(Data_Type_T& klass)
{
  klass.define_constant("Shift", (int)cv::cuda::device::functional_detail::DefaultBinaryShift<T1, T2, D>::shift);
};

template<typename Data_Type_T, typename Func>
inline void DefaultTransformShift_builder(Data_Type_T& klass)
{
  klass.define_constant("Shift", (int)cv::cuda::device::DefaultTransformShift<Func>::shift);
};

template<typename Data_Type_T, typename Func>
inline void DefaultTransformFunctorTraits_builder(Data_Type_T& klass)
{
  klass.define_constant("Simple_block_dim_x", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::simple_block_dim_x).
    define_constant("Simple_block_dim_y", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::simple_block_dim_y).
    define_constant("Smart_block_dim_x", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::smart_block_dim_x).
    define_constant("Smart_block_dim_y", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::smart_block_dim_y).
    define_constant("Smart_shift", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::smart_shift);
};

template<typename Data_Type_T, typename Func>
inline void TransformFunctorTraits_builder(Data_Type_T& klass)
{
};

void Init_Core_Cuda_Functional()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::maximum<uchar>> rb_cCvCudaDeviceMaximumUchar = define_class_under<cv::cuda::device::maximum<uchar>>(rb_mCvCudaDevice, "MaximumUchar").
    define_constructor(Constructor<cv::cuda::device::maximum<uchar>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<uchar>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::maximum<schar>> rb_cCvCudaDeviceMaximumSchar = define_class_under<cv::cuda::device::maximum<schar>>(rb_mCvCudaDevice, "MaximumSchar").
    define_constructor(Constructor<cv::cuda::device::maximum<schar>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<schar>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::maximum<char>> rb_cCvCudaDeviceMaximumChar = define_class_under<cv::cuda::device::maximum<char>>(rb_mCvCudaDevice, "MaximumChar").
    define_constructor(Constructor<cv::cuda::device::maximum<char>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<char>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::maximum<ushort>> rb_cCvCudaDeviceMaximumUshort = define_class_under<cv::cuda::device::maximum<ushort>>(rb_mCvCudaDevice, "MaximumUshort").
    define_constructor(Constructor<cv::cuda::device::maximum<ushort>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<ushort>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::maximum<short>> rb_cCvCudaDeviceMaximumShort = define_class_under<cv::cuda::device::maximum<short>>(rb_mCvCudaDevice, "MaximumShort").
    define_constructor(Constructor<cv::cuda::device::maximum<short>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<short>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::maximum<int>> rb_cCvCudaDeviceMaximumInt = define_class_under<cv::cuda::device::maximum<int>>(rb_mCvCudaDevice, "MaximumInt").
    define_constructor(Constructor<cv::cuda::device::maximum<int>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<int>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::maximum<uint>> rb_cCvCudaDeviceMaximumUint = define_class_under<cv::cuda::device::maximum<uint>>(rb_mCvCudaDevice, "MaximumUint").
    define_constructor(Constructor<cv::cuda::device::maximum<uint>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<uint>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::maximum<float>> rb_cCvCudaDeviceMaximumFloat = define_class_under<cv::cuda::device::maximum<float>>(rb_mCvCudaDevice, "MaximumFloat").
    define_constructor(Constructor<cv::cuda::device::maximum<float>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<float>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::maximum<double>> rb_cCvCudaDeviceMaximumDouble = define_class_under<cv::cuda::device::maximum<double>>(rb_mCvCudaDevice, "MaximumDouble").
    define_constructor(Constructor<cv::cuda::device::maximum<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::maximum<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<uchar>> rb_cCvCudaDeviceMinimumUchar = define_class_under<cv::cuda::device::minimum<uchar>>(rb_mCvCudaDevice, "MinimumUchar").
    define_constructor(Constructor<cv::cuda::device::minimum<uchar>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<uchar>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<schar>> rb_cCvCudaDeviceMinimumSchar = define_class_under<cv::cuda::device::minimum<schar>>(rb_mCvCudaDevice, "MinimumSchar").
    define_constructor(Constructor<cv::cuda::device::minimum<schar>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<schar>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<char>> rb_cCvCudaDeviceMinimumChar = define_class_under<cv::cuda::device::minimum<char>>(rb_mCvCudaDevice, "MinimumChar").
    define_constructor(Constructor<cv::cuda::device::minimum<char>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<char>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<ushort>> rb_cCvCudaDeviceMinimumUshort = define_class_under<cv::cuda::device::minimum<ushort>>(rb_mCvCudaDevice, "MinimumUshort").
    define_constructor(Constructor<cv::cuda::device::minimum<ushort>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<ushort>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<short>> rb_cCvCudaDeviceMinimumShort = define_class_under<cv::cuda::device::minimum<short>>(rb_mCvCudaDevice, "MinimumShort").
    define_constructor(Constructor<cv::cuda::device::minimum<short>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<short>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<int>> rb_cCvCudaDeviceMinimumInt = define_class_under<cv::cuda::device::minimum<int>>(rb_mCvCudaDevice, "MinimumInt").
    define_constructor(Constructor<cv::cuda::device::minimum<int>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<int>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<uint>> rb_cCvCudaDeviceMinimumUint = define_class_under<cv::cuda::device::minimum<uint>>(rb_mCvCudaDevice, "MinimumUint").
    define_constructor(Constructor<cv::cuda::device::minimum<uint>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<uint>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<float>> rb_cCvCudaDeviceMinimumFloat = define_class_under<cv::cuda::device::minimum<float>>(rb_mCvCudaDevice, "MinimumFloat").
    define_constructor(Constructor<cv::cuda::device::minimum<float>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<float>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::minimum<double>> rb_cCvCudaDeviceMinimumDouble = define_class_under<cv::cuda::device::minimum<double>>(rb_mCvCudaDevice, "MinimumDouble").
    define_constructor(Constructor<cv::cuda::device::minimum<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::minimum<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<unsigned char>> rb_cCvCudaDeviceAbsFuncUnsignedChar = define_class_under<cv::cuda::device::abs_func<unsigned char>>(rb_mCvCudaDevice, "AbsFuncUnsignedChar").
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned char>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<unsigned char>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<signed char>> rb_cCvCudaDeviceAbsFuncSignedChar = define_class_under<cv::cuda::device::abs_func<signed char>>(rb_mCvCudaDevice, "AbsFuncSignedChar").
    define_constructor(Constructor<cv::cuda::device::abs_func<signed char>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<signed char>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<char>> rb_cCvCudaDeviceAbsFuncChar = define_class_under<cv::cuda::device::abs_func<char>>(rb_mCvCudaDevice, "AbsFuncChar").
    define_constructor(Constructor<cv::cuda::device::abs_func<char>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<char>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<unsigned short>> rb_cCvCudaDeviceAbsFuncUnsignedShort = define_class_under<cv::cuda::device::abs_func<unsigned short>>(rb_mCvCudaDevice, "AbsFuncUnsignedShort").
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned short>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<unsigned short>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<short>> rb_cCvCudaDeviceAbsFuncShort = define_class_under<cv::cuda::device::abs_func<short>>(rb_mCvCudaDevice, "AbsFuncShort").
    define_constructor(Constructor<cv::cuda::device::abs_func<short>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<short>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<unsigned int>> rb_cCvCudaDeviceAbsFuncUnsignedInt = define_class_under<cv::cuda::device::abs_func<unsigned int>>(rb_mCvCudaDevice, "AbsFuncUnsignedInt").
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned int>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<unsigned int>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<int>> rb_cCvCudaDeviceAbsFuncInt = define_class_under<cv::cuda::device::abs_func<int>>(rb_mCvCudaDevice, "AbsFuncInt").
    define_constructor(Constructor<cv::cuda::device::abs_func<int>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<int>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<float>> rb_cCvCudaDeviceAbsFuncFloat = define_class_under<cv::cuda::device::abs_func<float>>(rb_mCvCudaDevice, "AbsFuncFloat").
    define_constructor(Constructor<cv::cuda::device::abs_func<float>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<float>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::abs_func<double>> rb_cCvCudaDeviceAbsFuncDouble = define_class_under<cv::cuda::device::abs_func<double>>(rb_mCvCudaDevice, "AbsFuncDouble").
    define_constructor(Constructor<cv::cuda::device::abs_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::sqrt_func<double>> rb_cCvCudaDeviceSqrtFuncDouble = define_class_under<cv::cuda::device::sqrt_func<double>>(rb_mCvCudaDevice, "SqrtFuncDouble").
    define_constructor(Constructor<cv::cuda::device::sqrt_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::sqrt_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::exp_func<double>> rb_cCvCudaDeviceExpFuncDouble = define_class_under<cv::cuda::device::exp_func<double>>(rb_mCvCudaDevice, "ExpFuncDouble").
    define_constructor(Constructor<cv::cuda::device::exp_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::exp_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::exp2_func<double>> rb_cCvCudaDeviceExp2FuncDouble = define_class_under<cv::cuda::device::exp2_func<double>>(rb_mCvCudaDevice, "Exp2FuncDouble").
    define_constructor(Constructor<cv::cuda::device::exp2_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::exp2_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::exp10_func<double>> rb_cCvCudaDeviceExp10FuncDouble = define_class_under<cv::cuda::device::exp10_func<double>>(rb_mCvCudaDevice, "Exp10FuncDouble").
    define_constructor(Constructor<cv::cuda::device::exp10_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::exp10_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::log_func<double>> rb_cCvCudaDeviceLogFuncDouble = define_class_under<cv::cuda::device::log_func<double>>(rb_mCvCudaDevice, "LogFuncDouble").
    define_constructor(Constructor<cv::cuda::device::log_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::log_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::log2_func<double>> rb_cCvCudaDeviceLog2FuncDouble = define_class_under<cv::cuda::device::log2_func<double>>(rb_mCvCudaDevice, "Log2FuncDouble").
    define_constructor(Constructor<cv::cuda::device::log2_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::log2_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::log10_func<double>> rb_cCvCudaDeviceLog10FuncDouble = define_class_under<cv::cuda::device::log10_func<double>>(rb_mCvCudaDevice, "Log10FuncDouble").
    define_constructor(Constructor<cv::cuda::device::log10_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::log10_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::sin_func<double>> rb_cCvCudaDeviceSinFuncDouble = define_class_under<cv::cuda::device::sin_func<double>>(rb_mCvCudaDevice, "SinFuncDouble").
    define_constructor(Constructor<cv::cuda::device::sin_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::sin_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::cos_func<double>> rb_cCvCudaDeviceCosFuncDouble = define_class_under<cv::cuda::device::cos_func<double>>(rb_mCvCudaDevice, "CosFuncDouble").
    define_constructor(Constructor<cv::cuda::device::cos_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::cos_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::tan_func<double>> rb_cCvCudaDeviceTanFuncDouble = define_class_under<cv::cuda::device::tan_func<double>>(rb_mCvCudaDevice, "TanFuncDouble").
    define_constructor(Constructor<cv::cuda::device::tan_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::tan_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::asin_func<double>> rb_cCvCudaDeviceAsinFuncDouble = define_class_under<cv::cuda::device::asin_func<double>>(rb_mCvCudaDevice, "AsinFuncDouble").
    define_constructor(Constructor<cv::cuda::device::asin_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::asin_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::acos_func<double>> rb_cCvCudaDeviceAcosFuncDouble = define_class_under<cv::cuda::device::acos_func<double>>(rb_mCvCudaDevice, "AcosFuncDouble").
    define_constructor(Constructor<cv::cuda::device::acos_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::acos_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::atan_func<double>> rb_cCvCudaDeviceAtanFuncDouble = define_class_under<cv::cuda::device::atan_func<double>>(rb_mCvCudaDevice, "AtanFuncDouble").
    define_constructor(Constructor<cv::cuda::device::atan_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::atan_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::sinh_func<double>> rb_cCvCudaDeviceSinhFuncDouble = define_class_under<cv::cuda::device::sinh_func<double>>(rb_mCvCudaDevice, "SinhFuncDouble").
    define_constructor(Constructor<cv::cuda::device::sinh_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::sinh_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::cosh_func<double>> rb_cCvCudaDeviceCoshFuncDouble = define_class_under<cv::cuda::device::cosh_func<double>>(rb_mCvCudaDevice, "CoshFuncDouble").
    define_constructor(Constructor<cv::cuda::device::cosh_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::cosh_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::tanh_func<double>> rb_cCvCudaDeviceTanhFuncDouble = define_class_under<cv::cuda::device::tanh_func<double>>(rb_mCvCudaDevice, "TanhFuncDouble").
    define_constructor(Constructor<cv::cuda::device::tanh_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::tanh_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::asinh_func<double>> rb_cCvCudaDeviceAsinhFuncDouble = define_class_under<cv::cuda::device::asinh_func<double>>(rb_mCvCudaDevice, "AsinhFuncDouble").
    define_constructor(Constructor<cv::cuda::device::asinh_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::asinh_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::acosh_func<double>> rb_cCvCudaDeviceAcoshFuncDouble = define_class_under<cv::cuda::device::acosh_func<double>>(rb_mCvCudaDevice, "AcoshFuncDouble").
    define_constructor(Constructor<cv::cuda::device::acosh_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::acosh_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::atanh_func<double>> rb_cCvCudaDeviceAtanhFuncDouble = define_class_under<cv::cuda::device::atanh_func<double>>(rb_mCvCudaDevice, "AtanhFuncDouble").
    define_constructor(Constructor<cv::cuda::device::atanh_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::atanh_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::hypot_func<double>> rb_cCvCudaDeviceHypotFuncDouble = define_class_under<cv::cuda::device::hypot_func<double>>(rb_mCvCudaDevice, "HypotFuncDouble").
    define_constructor(Constructor<cv::cuda::device::hypot_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::hypot_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::atan2_func<double>> rb_cCvCudaDeviceAtan2FuncDouble = define_class_under<cv::cuda::device::atan2_func<double>>(rb_mCvCudaDevice, "Atan2FuncDouble").
    define_constructor(Constructor<cv::cuda::device::atan2_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::atan2_func<double>::__forceinline__);

  Rice::Data_Type<cv::cuda::device::pow_func<double>> rb_cCvCudaDevicePowFuncDouble = define_class_under<cv::cuda::device::pow_func<double>>(rb_mCvCudaDevice, "PowFuncDouble").
    define_constructor(Constructor<cv::cuda::device::pow_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::pow_func<double>::__forceinline__);

  Module rb_mCvCudaDeviceFunctionalDetail = define_module_under(rb_mCvCudaDevice, "FunctionalDetail");
}