#include <opencv2/core/cuda/functional.hpp>
#include "functional-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceAbsFuncChar;
Rice::Class rb_cCvCudaDeviceAbsFuncDouble;
Rice::Class rb_cCvCudaDeviceAbsFuncFloat;
Rice::Class rb_cCvCudaDeviceAbsFuncInt;
Rice::Class rb_cCvCudaDeviceAbsFuncShort;
Rice::Class rb_cCvCudaDeviceAbsFuncSignedChar;
Rice::Class rb_cCvCudaDeviceAbsFuncUnsignedChar;
Rice::Class rb_cCvCudaDeviceAbsFuncUnsignedInt;
Rice::Class rb_cCvCudaDeviceAbsFuncUnsignedShort;
Rice::Class rb_cCvCudaDeviceIsBinaryFunctionNo;
Rice::Class rb_cCvCudaDeviceIsUnaryFunctionNo;

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
  klass.rb_cCvCudaDeviceIsUnaryFunctionNo = define_class<cv::cuda::device::IsUnaryFunction::No>("No").
      define_constructor(Constructor<cv::cuda::device::IsUnaryFunction::No>());.
    template define_singleton_function("check", &cv::cuda::device::IsUnaryFunction<F>::check).
    template define_singleton_function("make_f", &cv::cuda::device::IsUnaryFunction<F>::makeF).
    define_constant("Value", (int)cv::cuda::device::IsUnaryFunction<F>::value);
};

template<typename Data_Type_T, typename F>
inline void IsBinaryFunction_builder(Data_Type_T& klass)
{
  klass.rb_cCvCudaDeviceIsBinaryFunctionNo = define_class<cv::cuda::device::IsBinaryFunction::No>("No").
      define_constructor(Constructor<cv::cuda::device::IsBinaryFunction::No>());.
    template define_singleton_function("check", &cv::cuda::device::IsBinaryFunction<F>::check).
    template define_singleton_function("make_f", &cv::cuda::device::IsBinaryFunction<F>::makeF).
    define_constant("Value", (int)cv::cuda::device::IsBinaryFunction<F>::value);
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
void Init_Functional()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceAbsFuncUnsignedChar = define_class_under<cv::cuda::device::abs_func<unsigned char>>(rb_mCvCudaDevice, "AbsFuncUnsignedChar").
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned char>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<unsigned char>::__forceinline__);
  
  rb_cCvCudaDeviceAbsFuncSignedChar = define_class_under<cv::cuda::device::abs_func<signed char>>(rb_mCvCudaDevice, "AbsFuncSignedChar").
    define_constructor(Constructor<cv::cuda::device::abs_func<signed char>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<signed char>::__forceinline__);
  
  rb_cCvCudaDeviceAbsFuncChar = define_class_under<cv::cuda::device::abs_func<char>>(rb_mCvCudaDevice, "AbsFuncChar").
    define_constructor(Constructor<cv::cuda::device::abs_func<char>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<char>::__forceinline__);
  
  rb_cCvCudaDeviceAbsFuncUnsignedShort = define_class_under<cv::cuda::device::abs_func<unsigned short>>(rb_mCvCudaDevice, "AbsFuncUnsignedShort").
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned short>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<unsigned short>::__forceinline__);
  
  rb_cCvCudaDeviceAbsFuncShort = define_class_under<cv::cuda::device::abs_func<short>>(rb_mCvCudaDevice, "AbsFuncShort").
    define_constructor(Constructor<cv::cuda::device::abs_func<short>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<short>::__forceinline__);
  
  rb_cCvCudaDeviceAbsFuncUnsignedInt = define_class_under<cv::cuda::device::abs_func<unsigned int>>(rb_mCvCudaDevice, "AbsFuncUnsignedInt").
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned int>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<unsigned int>::__forceinline__);
  
  rb_cCvCudaDeviceAbsFuncInt = define_class_under<cv::cuda::device::abs_func<int>>(rb_mCvCudaDevice, "AbsFuncInt").
    define_constructor(Constructor<cv::cuda::device::abs_func<int>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<int>::__forceinline__);
  
  rb_cCvCudaDeviceAbsFuncFloat = define_class_under<cv::cuda::device::abs_func<float>>(rb_mCvCudaDevice, "AbsFuncFloat").
    define_constructor(Constructor<cv::cuda::device::abs_func<float>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<float>::__forceinline__);
  
  rb_cCvCudaDeviceAbsFuncDouble = define_class_under<cv::cuda::device::abs_func<double>>(rb_mCvCudaDevice, "AbsFuncDouble").
    define_constructor(Constructor<cv::cuda::device::abs_func<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::abs_func<double>::__forceinline__);
  
  Module rb_mCvCudaDeviceFunctionalDetail = define_module_under(rb_mCvCudaDevice, "FunctionalDetail");
  

}