#include <opencv2/core/cuda/functional.hpp>
#include "functional-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void plus_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::plus<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::plus<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::plus<T>>()).
    define_constructor(Constructor<cv::cuda::device::plus<T>, const cv::cuda::device::plus<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void minus_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::minus<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::minus<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::minus<T>>()).
    define_constructor(Constructor<cv::cuda::device::minus<T>, const cv::cuda::device::minus<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void multiplies_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::multiplies<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::multiplies<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::multiplies<T>>()).
    define_constructor(Constructor<cv::cuda::device::multiplies<T>, const cv::cuda::device::multiplies<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void divides_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::divides<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::divides<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::divides<T>>()).
    define_constructor(Constructor<cv::cuda::device::divides<T>, const cv::cuda::device::divides<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void modulus_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::modulus<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::modulus<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::modulus<T>>()).
    define_constructor(Constructor<cv::cuda::device::modulus<T>, const cv::cuda::device::modulus<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void negate_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::negate<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::negate<T>::operator(),
      Arg("a")).
    define_constructor(Constructor<cv::cuda::device::negate<T>>()).
    define_constructor(Constructor<cv::cuda::device::negate<T>, const cv::cuda::device::negate<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void equal_to_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::equal_to<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::equal_to<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::equal_to<T>>()).
    define_constructor(Constructor<cv::cuda::device::equal_to<T>, const cv::cuda::device::equal_to<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void not_equal_to_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::not_equal_to<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::not_equal_to<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::not_equal_to<T>>()).
    define_constructor(Constructor<cv::cuda::device::not_equal_to<T>, const cv::cuda::device::not_equal_to<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void greater_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::greater<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::greater<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::greater<T>>()).
    define_constructor(Constructor<cv::cuda::device::greater<T>, const cv::cuda::device::greater<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void less_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::less<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::less<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::less<T>>()).
    define_constructor(Constructor<cv::cuda::device::less<T>, const cv::cuda::device::less<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void greater_equal_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::greater_equal<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::greater_equal<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::greater_equal<T>>()).
    define_constructor(Constructor<cv::cuda::device::greater_equal<T>, const cv::cuda::device::greater_equal<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void less_equal_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::less_equal<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::less_equal<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::less_equal<T>>()).
    define_constructor(Constructor<cv::cuda::device::less_equal<T>, const cv::cuda::device::less_equal<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void logical_and_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::logical_and<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::logical_and<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::logical_and<T>>()).
    define_constructor(Constructor<cv::cuda::device::logical_and<T>, const cv::cuda::device::logical_and<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void logical_or_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::logical_or<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::logical_or<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::logical_or<T>>()).
    define_constructor(Constructor<cv::cuda::device::logical_or<T>, const cv::cuda::device::logical_or<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void logical_not_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cuda::device::logical_not<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::logical_not<T>::operator(),
      Arg("a")).
    define_constructor(Constructor<cv::cuda::device::logical_not<T>>()).
    define_constructor(Constructor<cv::cuda::device::logical_not<T>, const cv::cuda::device::logical_not<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void bit_and_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::bit_and<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::bit_and<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::bit_and<T>>()).
    define_constructor(Constructor<cv::cuda::device::bit_and<T>, const cv::cuda::device::bit_and<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void bit_or_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::bit_or<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::bit_or<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::bit_or<T>>()).
    define_constructor(Constructor<cv::cuda::device::bit_or<T>, const cv::cuda::device::bit_or<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void bit_xor_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::bit_xor<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::bit_xor<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::bit_xor<T>>()).
    define_constructor(Constructor<cv::cuda::device::bit_xor<T>, const cv::cuda::device::bit_xor<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void bit_not_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::bit_not<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::bit_not<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::bit_not<T>>()).
    define_constructor(Constructor<cv::cuda::device::bit_not<T>, const cv::cuda::device::bit_not<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void identity_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeTraits<T>::ParameterType(cv::cuda::device::identity<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::identity<T>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::identity<T>>()).
    define_constructor(Constructor<cv::cuda::device::identity<T>, const cv::cuda::device::identity<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T1, typename T2>
inline void project1st_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeTraits<T1>::ParameterType(cv::cuda::device::project1st<T1, T2>::*)(typename TypeTraits<T1>::ParameterType, typename TypeTraits<T2>::ParameterType) const>("call", &cv::cuda::device::project1st<T1, T2>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::project1st<T1, T2>>()).
    define_constructor(Constructor<cv::cuda::device::project1st<T1, T2>, const cv::cuda::device::project1st<T1, T2>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T1, typename T2>
inline void project2nd_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeTraits<T2>::ParameterType(cv::cuda::device::project2nd<T1, T2>::*)(typename TypeTraits<T1>::ParameterType, typename TypeTraits<T2>::ParameterType) const>("call", &cv::cuda::device::project2nd<T1, T2>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::project2nd<T1, T2>>()).
    define_constructor(Constructor<cv::cuda::device::project2nd<T1, T2>, const cv::cuda::device::project2nd<T1, T2>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void maximum_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::maximum<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::maximum<T>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<T>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<T>, const cv::cuda::device::maximum<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void minimum_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::minimum<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::minimum<T>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<T>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<T>, const cv::cuda::device::minimum<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void abs_func_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::abs_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::abs_func<T>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<T>, const cv::cuda::device::abs_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void sqrt_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::sqrt_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::sqrt_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sqrt_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::sqrt_func<T>, const cv::cuda::device::sqrt_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void exp_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::exp_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::exp_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::exp_func<T>, const cv::cuda::device::exp_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void exp2_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::exp2_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::exp2_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp2_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::exp2_func<T>, const cv::cuda::device::exp2_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void exp10_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::exp10_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::exp10_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp10_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::exp10_func<T>, const cv::cuda::device::exp10_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void log_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::log_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::log_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::log_func<T>, const cv::cuda::device::log_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void log2_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::log2_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::log2_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log2_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::log2_func<T>, const cv::cuda::device::log2_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void log10_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::log10_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::log10_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log10_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::log10_func<T>, const cv::cuda::device::log10_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void sin_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::sin_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::sin_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sin_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::sin_func<T>, const cv::cuda::device::sin_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void cos_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::cos_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::cos_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::cos_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::cos_func<T>, const cv::cuda::device::cos_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void tan_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::tan_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::tan_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::tan_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::tan_func<T>, const cv::cuda::device::tan_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void asin_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::asin_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::asin_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::asin_func<T>>());
};

template<typename Data_Type_T, typename T>
inline void acos_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::acos_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::acos_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::acos_func<T>>());
};

template<typename Data_Type_T, typename T>
inline void atan_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::atan_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::atan_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::atan_func<T>>());
};

template<typename Data_Type_T, typename T>
inline void sinh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::sinh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::sinh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sinh_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::sinh_func<T>, const cv::cuda::device::sinh_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void cosh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::cosh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::cosh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::cosh_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::cosh_func<T>, const cv::cuda::device::cosh_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void tanh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::tanh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::tanh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::tanh_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::tanh_func<T>, const cv::cuda::device::tanh_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void asinh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::asinh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::asinh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::asinh_func<T>>());
};

template<typename Data_Type_T, typename T>
inline void acosh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::acosh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::acosh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::acosh_func<T>>());
};

template<typename Data_Type_T, typename T>
inline void atanh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::atanh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::atanh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::atanh_func<T>>());
};

template<typename Data_Type_T, typename T>
inline void hypot_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::hypot_func<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::hypot_func<T>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::hypot_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::hypot_func<T>, const cv::cuda::device::hypot_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void atan2_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::atan2_func<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::atan2_func<T>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::atan2_func<T>>());
};

template<typename Data_Type_T, typename T>
inline void pow_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cuda::device::pow_func<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::pow_func<T>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::pow_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::pow_func<T>, const cv::cuda::device::pow_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void hypot_sqr_func_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::hypot_sqr_func<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::hypot_sqr_func<T>::operator(),
      Arg("src1"), Arg("src2")).
    define_constructor(Constructor<cv::cuda::device::hypot_sqr_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::hypot_sqr_func<T>, const cv::cuda::device::hypot_sqr_func<T>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, typename D>
inline void saturate_cast_func_builder(Data_Type_T& klass)
{
  klass.template define_method<D(cv::cuda::device::saturate_cast_func<T, D>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::saturate_cast_func<T, D>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::saturate_cast_func<T, D>>()).
    define_constructor(Constructor<cv::cuda::device::saturate_cast_func<T, D>, const cv::cuda::device::saturate_cast_func<T, D>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void thresh_binary_func_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::thresh_binary_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_")).
    template define_method<T(cv::cuda::device::thresh_binary_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_binary_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_func<T>, const cv::cuda::device::thresh_binary_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_binary_func<T>::thresh).
    define_attr("max_val", &cv::cuda::device::thresh_binary_func<T>::maxVal);
};

template<typename Data_Type_T, typename T>
inline void thresh_binary_inv_func_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::thresh_binary_inv_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_")).
    template define_method<T(cv::cuda::device::thresh_binary_inv_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_binary_inv_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_inv_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_inv_func<T>, const cv::cuda::device::thresh_binary_inv_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_binary_inv_func<T>::thresh).
    define_attr("max_val", &cv::cuda::device::thresh_binary_inv_func<T>::maxVal);
};

template<typename Data_Type_T, typename T>
inline void thresh_trunc_func_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::thresh_trunc_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_") = static_cast<T>(0)).
    template define_method<T(cv::cuda::device::thresh_trunc_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_trunc_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_trunc_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_trunc_func<T>, const cv::cuda::device::thresh_trunc_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_trunc_func<T>::thresh);
};

template<typename Data_Type_T, typename T>
inline void thresh_to_zero_func_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::thresh_to_zero_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_") = static_cast<T>(0)).
    template define_method<T(cv::cuda::device::thresh_to_zero_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_to_zero_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_func<T>, const cv::cuda::device::thresh_to_zero_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_to_zero_func<T>::thresh);
};

template<typename Data_Type_T, typename T>
inline void thresh_to_zero_inv_func_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::thresh_to_zero_inv_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_") = static_cast<T>(0)).
    template define_method<T(cv::cuda::device::thresh_to_zero_inv_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_to_zero_inv_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_inv_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_inv_func<T>, const cv::cuda::device::thresh_to_zero_inv_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_to_zero_inv_func<T>::thresh);
};

template<typename Data_Type_T, typename Predicate>
inline void unary_negate_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::unary_negate<Predicate>, const Predicate&>(),
      Arg("p")).
    template define_method<bool(cv::cuda::device::unary_negate<Predicate>::*)(typename TypeTraits<typename Predicate::argument_type>::ParameterType) const>("call", &cv::cuda::device::unary_negate<Predicate>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::unary_negate<Predicate>>()).
    define_constructor(Constructor<cv::cuda::device::unary_negate<Predicate>, const cv::cuda::device::unary_negate<Predicate>&>(),
      Arg("other")).
    define_attr("pred", &cv::cuda::device::unary_negate<Predicate>::pred);
};

template<typename Data_Type_T, typename Predicate>
inline void binary_negate_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::binary_negate<Predicate>, const Predicate&>(),
      Arg("p")).
    template define_method<bool(cv::cuda::device::binary_negate<Predicate>::*)(typename TypeTraits<typename Predicate::first_argument_type>::ParameterType, typename TypeTraits<typename Predicate::second_argument_type>::ParameterType) const>("call", &cv::cuda::device::binary_negate<Predicate>::operator(),
      Arg("x"), Arg("y")).
    define_constructor(Constructor<cv::cuda::device::binary_negate<Predicate>>()).
    define_constructor(Constructor<cv::cuda::device::binary_negate<Predicate>, const cv::cuda::device::binary_negate<Predicate>&>(),
      Arg("other")).
    define_attr("pred", &cv::cuda::device::binary_negate<Predicate>::pred);
};

template<typename Data_Type_T, typename Op>
inline void binder1st_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::binder1st<Op>, const Op&, const typename Op::first_argument_type&>(),
      Arg("op_"), Arg("arg1_")).
    template define_method<typename Op::result_type(cv::cuda::device::binder1st<Op>::*)(typename TypeTraits<typename Op::second_argument_type>::ParameterType) const>("call", &cv::cuda::device::binder1st<Op>::operator(),
      Arg("a")).
    define_constructor(Constructor<cv::cuda::device::binder1st<Op>>()).
    define_constructor(Constructor<cv::cuda::device::binder1st<Op>, const cv::cuda::device::binder1st<Op>&>(),
      Arg("other")).
    define_attr("op", &cv::cuda::device::binder1st<Op>::op).
    define_attr("arg1", &cv::cuda::device::binder1st<Op>::arg1);
};

template<typename Data_Type_T, typename Op>
inline void binder2nd_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::binder2nd<Op>, const Op&, const typename Op::second_argument_type&>(),
      Arg("op_"), Arg("arg2_")).
    template define_method<typename Op::result_type(cv::cuda::device::binder2nd<Op>::*)(typename TypeTraits<typename Op::first_argument_type>::ParameterType) const>("call", &cv::cuda::device::binder2nd<Op>::operator(),
      Arg("a")).
    define_constructor(Constructor<cv::cuda::device::binder2nd<Op>>()).
    define_constructor(Constructor<cv::cuda::device::binder2nd<Op>, const cv::cuda::device::binder2nd<Op>&>(),
      Arg("other")).
    define_attr("op", &cv::cuda::device::binder2nd<Op>::op).
    define_attr("arg2", &cv::cuda::device::binder2nd<Op>::arg2);
};

template<typename Data_Type_T, typename F>
inline void IsUnaryFunction_builder(Data_Type_T& klass)
{
  klass.Rice::Data_Type<cv::cuda::device::IsUnaryFunction::No> rb_cCvCudaDeviceIsUnaryFunctionNo = define_class<cv::cuda::device::IsUnaryFunction::No>("No").
      define_constructor(Constructor<cv::cuda::device::IsUnaryFunction<F>::No>()).
      define_attr("a", &cv::cuda::device::IsUnaryFunction<F>::No::a, Rice::AttrAccess::Read);.
    define_constant("Value", (int)cv::cuda::device::IsUnaryFunction<F>::value).
    template define_singleton_function<F(*)()>("make_f", &cv::cuda::device::IsUnaryFunction<F>::makeF);
};

template<typename Data_Type_T, typename F>
inline void IsBinaryFunction_builder(Data_Type_T& klass)
{
  klass.Rice::Data_Type<cv::cuda::device::IsBinaryFunction::No> rb_cCvCudaDeviceIsBinaryFunctionNo = define_class<cv::cuda::device::IsBinaryFunction::No>("No").
      define_constructor(Constructor<cv::cuda::device::IsBinaryFunction<F>::No>()).
      define_attr("a", &cv::cuda::device::IsBinaryFunction<F>::No::a, Rice::AttrAccess::Read);.
    define_constant("Value", (int)cv::cuda::device::IsBinaryFunction<F>::value).
    template define_singleton_function<F(*)()>("make_f", &cv::cuda::device::IsBinaryFunction<F>::makeF);
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

void Init_Core_Cuda_Functional()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::binary_function<unsigned char, unsigned char, unsigned char>> rb_cBinaryFunctionUnsignedCharUnsignedCharUnsignedChar = define_class_under<cv::cuda::device::binary_function<unsigned char, unsigned char, unsigned char>>(rb_mCvCudaDevice, "BinaryFunctionUnsignedCharUnsignedCharUnsignedChar").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<unsigned char, unsigned char, unsigned char>>, unsigned char, unsigned char, unsigned char>);
  Rice::Data_Type<cv::cuda::device::maximum<uchar>> rb_cCvCudaDeviceMaximumUchar = define_class_under<cv::cuda::device::maximum<uchar>, cv::cuda::device::binary_function<unsigned char, unsigned char, unsigned char>>(rb_mCvCudaDevice, "MaximumUchar").
    define_method<uchar(cv::cuda::device::maximum<uchar>::*)(uchar, uchar) const>("call", &cv::cuda::device::maximum<uchar>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<uchar>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<uchar>, const cv::cuda::device::maximum<uchar>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<signed char, signed char, signed char>> rb_cBinaryFunctionSignedCharSignedCharSignedChar = define_class_under<cv::cuda::device::binary_function<signed char, signed char, signed char>>(rb_mCvCudaDevice, "BinaryFunctionSignedCharSignedCharSignedChar").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<signed char, signed char, signed char>>, signed char, signed char, signed char>);
  Rice::Data_Type<cv::cuda::device::maximum<schar>> rb_cCvCudaDeviceMaximumSchar = define_class_under<cv::cuda::device::maximum<schar>, cv::cuda::device::binary_function<signed char, signed char, signed char>>(rb_mCvCudaDevice, "MaximumSchar").
    define_method<schar(cv::cuda::device::maximum<schar>::*)(schar, schar) const>("call", &cv::cuda::device::maximum<schar>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<schar>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<schar>, const cv::cuda::device::maximum<schar>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<char, char, char>> rb_cBinaryFunctionCharCharChar = define_class_under<cv::cuda::device::binary_function<char, char, char>>(rb_mCvCudaDevice, "BinaryFunctionCharCharChar").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<char, char, char>>, char, char, char>);
  Rice::Data_Type<cv::cuda::device::maximum<char>> rb_cCvCudaDeviceMaximumChar = define_class_under<cv::cuda::device::maximum<char>, cv::cuda::device::binary_function<char, char, char>>(rb_mCvCudaDevice, "MaximumChar").
    define_method<char(cv::cuda::device::maximum<char>::*)(char, char) const>("call", &cv::cuda::device::maximum<char>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<char>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<char>, const cv::cuda::device::maximum<char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<unsigned short, unsigned short, unsigned short>> rb_cBinaryFunctionUnsignedShortUnsignedShortUnsignedShort = define_class_under<cv::cuda::device::binary_function<unsigned short, unsigned short, unsigned short>>(rb_mCvCudaDevice, "BinaryFunctionUnsignedShortUnsignedShortUnsignedShort").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<unsigned short, unsigned short, unsigned short>>, unsigned short, unsigned short, unsigned short>);
  Rice::Data_Type<cv::cuda::device::maximum<ushort>> rb_cCvCudaDeviceMaximumUshort = define_class_under<cv::cuda::device::maximum<ushort>, cv::cuda::device::binary_function<unsigned short, unsigned short, unsigned short>>(rb_mCvCudaDevice, "MaximumUshort").
    define_method<ushort(cv::cuda::device::maximum<ushort>::*)(ushort, ushort) const>("call", &cv::cuda::device::maximum<ushort>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<ushort>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<ushort>, const cv::cuda::device::maximum<ushort>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<short, short, short>> rb_cBinaryFunctionShortShortShort = define_class_under<cv::cuda::device::binary_function<short, short, short>>(rb_mCvCudaDevice, "BinaryFunctionShortShortShort").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<short, short, short>>, short, short, short>);
  Rice::Data_Type<cv::cuda::device::maximum<short>> rb_cCvCudaDeviceMaximumShort = define_class_under<cv::cuda::device::maximum<short>, cv::cuda::device::binary_function<short, short, short>>(rb_mCvCudaDevice, "MaximumShort").
    define_method<short(cv::cuda::device::maximum<short>::*)(short, short) const>("call", &cv::cuda::device::maximum<short>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<short>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<short>, const cv::cuda::device::maximum<short>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<int, int, int>> rb_cBinaryFunctionIntIntInt = define_class_under<cv::cuda::device::binary_function<int, int, int>>(rb_mCvCudaDevice, "BinaryFunctionIntIntInt").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<int, int, int>>, int, int, int>);
  Rice::Data_Type<cv::cuda::device::maximum<int>> rb_cCvCudaDeviceMaximumInt = define_class_under<cv::cuda::device::maximum<int>, cv::cuda::device::binary_function<int, int, int>>(rb_mCvCudaDevice, "MaximumInt").
    define_method<int(cv::cuda::device::maximum<int>::*)(int, int) const>("call", &cv::cuda::device::maximum<int>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<int>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<int>, const cv::cuda::device::maximum<int>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<unsigned int, unsigned int, unsigned int>> rb_cBinaryFunctionUnsignedIntUnsignedIntUnsignedInt = define_class_under<cv::cuda::device::binary_function<unsigned int, unsigned int, unsigned int>>(rb_mCvCudaDevice, "BinaryFunctionUnsignedIntUnsignedIntUnsignedInt").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<unsigned int, unsigned int, unsigned int>>, unsigned int, unsigned int, unsigned int>);
  Rice::Data_Type<cv::cuda::device::maximum<uint>> rb_cCvCudaDeviceMaximumUint = define_class_under<cv::cuda::device::maximum<uint>, cv::cuda::device::binary_function<unsigned int, unsigned int, unsigned int>>(rb_mCvCudaDevice, "MaximumUint").
    define_method<uint(cv::cuda::device::maximum<uint>::*)(uint, uint) const>("call", &cv::cuda::device::maximum<uint>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<uint>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<uint>, const cv::cuda::device::maximum<uint>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<float, float, float>> rb_cBinaryFunctionFloatFloatFloat = define_class_under<cv::cuda::device::binary_function<float, float, float>>(rb_mCvCudaDevice, "BinaryFunctionFloatFloatFloat").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<float, float, float>>, float, float, float>);
  Rice::Data_Type<cv::cuda::device::maximum<float>> rb_cCvCudaDeviceMaximumFloat = define_class_under<cv::cuda::device::maximum<float>, cv::cuda::device::binary_function<float, float, float>>(rb_mCvCudaDevice, "MaximumFloat").
    define_method<float(cv::cuda::device::maximum<float>::*)(float, float) const>("call", &cv::cuda::device::maximum<float>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<float>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<float>, const cv::cuda::device::maximum<float>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::binary_function<double, double, double>> rb_cBinaryFunctionDoubleDoubleDouble = define_class_under<cv::cuda::device::binary_function<double, double, double>>(rb_mCvCudaDevice, "BinaryFunctionDoubleDoubleDouble").
    define(&binary_function_builder<Data_Type<cv::cuda::device::binary_function<double, double, double>>, double, double, double>);
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

  Rice::Data_Type<cv::cuda::device::unary_function<unsigned char, unsigned char>> rb_cUnaryFunctionUnsignedCharUnsignedChar = define_class_under<cv::cuda::device::unary_function<unsigned char, unsigned char>>(rb_mCvCudaDevice, "UnaryFunctionUnsignedCharUnsignedChar").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<unsigned char, unsigned char>>, unsigned char, unsigned char>);
  Rice::Data_Type<cv::cuda::device::abs_func<unsigned char>> rb_cCvCudaDeviceAbsFuncUnsignedChar = define_class_under<cv::cuda::device::abs_func<unsigned char>, cv::cuda::device::unary_function<unsigned char, unsigned char>>(rb_mCvCudaDevice, "AbsFuncUnsignedChar").
    define_method<unsigned char(cv::cuda::device::abs_func<unsigned char>::*)(unsigned char) const>("call", &cv::cuda::device::abs_func<unsigned char>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned char>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned char>, const cv::cuda::device::abs_func<unsigned char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<signed char, signed char>> rb_cUnaryFunctionSignedCharSignedChar = define_class_under<cv::cuda::device::unary_function<signed char, signed char>>(rb_mCvCudaDevice, "UnaryFunctionSignedCharSignedChar").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<signed char, signed char>>, signed char, signed char>);
  Rice::Data_Type<cv::cuda::device::abs_func<signed char>> rb_cCvCudaDeviceAbsFuncSignedChar = define_class_under<cv::cuda::device::abs_func<signed char>, cv::cuda::device::unary_function<signed char, signed char>>(rb_mCvCudaDevice, "AbsFuncSignedChar").
    define_method<signed char(cv::cuda::device::abs_func<signed char>::*)(signed char) const>("call", &cv::cuda::device::abs_func<signed char>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<signed char>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<signed char>, const cv::cuda::device::abs_func<signed char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<char, char>> rb_cUnaryFunctionCharChar = define_class_under<cv::cuda::device::unary_function<char, char>>(rb_mCvCudaDevice, "UnaryFunctionCharChar").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<char, char>>, char, char>);
  Rice::Data_Type<cv::cuda::device::abs_func<char>> rb_cCvCudaDeviceAbsFuncChar = define_class_under<cv::cuda::device::abs_func<char>, cv::cuda::device::unary_function<char, char>>(rb_mCvCudaDevice, "AbsFuncChar").
    define_method<char(cv::cuda::device::abs_func<char>::*)(char) const>("call", &cv::cuda::device::abs_func<char>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<char>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<char>, const cv::cuda::device::abs_func<char>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<unsigned short, unsigned short>> rb_cUnaryFunctionUnsignedShortUnsignedShort = define_class_under<cv::cuda::device::unary_function<unsigned short, unsigned short>>(rb_mCvCudaDevice, "UnaryFunctionUnsignedShortUnsignedShort").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<unsigned short, unsigned short>>, unsigned short, unsigned short>);
  Rice::Data_Type<cv::cuda::device::abs_func<unsigned short>> rb_cCvCudaDeviceAbsFuncUnsignedShort = define_class_under<cv::cuda::device::abs_func<unsigned short>, cv::cuda::device::unary_function<unsigned short, unsigned short>>(rb_mCvCudaDevice, "AbsFuncUnsignedShort").
    define_method<unsigned short(cv::cuda::device::abs_func<unsigned short>::*)(unsigned short) const>("call", &cv::cuda::device::abs_func<unsigned short>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned short>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned short>, const cv::cuda::device::abs_func<unsigned short>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<short, short>> rb_cUnaryFunctionShortShort = define_class_under<cv::cuda::device::unary_function<short, short>>(rb_mCvCudaDevice, "UnaryFunctionShortShort").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<short, short>>, short, short>);
  Rice::Data_Type<cv::cuda::device::abs_func<short>> rb_cCvCudaDeviceAbsFuncShort = define_class_under<cv::cuda::device::abs_func<short>, cv::cuda::device::unary_function<short, short>>(rb_mCvCudaDevice, "AbsFuncShort").
    define_method<short(cv::cuda::device::abs_func<short>::*)(short) const>("call", &cv::cuda::device::abs_func<short>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<short>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<short>, const cv::cuda::device::abs_func<short>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<unsigned int, unsigned int>> rb_cUnaryFunctionUnsignedIntUnsignedInt = define_class_under<cv::cuda::device::unary_function<unsigned int, unsigned int>>(rb_mCvCudaDevice, "UnaryFunctionUnsignedIntUnsignedInt").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<unsigned int, unsigned int>>, unsigned int, unsigned int>);
  Rice::Data_Type<cv::cuda::device::abs_func<unsigned int>> rb_cCvCudaDeviceAbsFuncUnsignedInt = define_class_under<cv::cuda::device::abs_func<unsigned int>, cv::cuda::device::unary_function<unsigned int, unsigned int>>(rb_mCvCudaDevice, "AbsFuncUnsignedInt").
    define_method<unsigned int(cv::cuda::device::abs_func<unsigned int>::*)(unsigned int) const>("call", &cv::cuda::device::abs_func<unsigned int>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned int>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<unsigned int>, const cv::cuda::device::abs_func<unsigned int>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<int, int>> rb_cUnaryFunctionIntInt = define_class_under<cv::cuda::device::unary_function<int, int>>(rb_mCvCudaDevice, "UnaryFunctionIntInt").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<int, int>>, int, int>);
  Rice::Data_Type<cv::cuda::device::abs_func<int>> rb_cCvCudaDeviceAbsFuncInt = define_class_under<cv::cuda::device::abs_func<int>, cv::cuda::device::unary_function<int, int>>(rb_mCvCudaDevice, "AbsFuncInt").
    define_method<int(cv::cuda::device::abs_func<int>::*)(int) const>("call", &cv::cuda::device::abs_func<int>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<int>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<int>, const cv::cuda::device::abs_func<int>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<float, float>> rb_cUnaryFunctionFloatFloat = define_class_under<cv::cuda::device::unary_function<float, float>>(rb_mCvCudaDevice, "UnaryFunctionFloatFloat").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<float, float>>, float, float>);
  Rice::Data_Type<cv::cuda::device::abs_func<float>> rb_cCvCudaDeviceAbsFuncFloat = define_class_under<cv::cuda::device::abs_func<float>, cv::cuda::device::unary_function<float, float>>(rb_mCvCudaDevice, "AbsFuncFloat").
    define_method<float(cv::cuda::device::abs_func<float>::*)(float) const>("call", &cv::cuda::device::abs_func<float>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<float>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<float>, const cv::cuda::device::abs_func<float>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<double, double>> rb_cUnaryFunctionDoubleDouble = define_class_under<cv::cuda::device::unary_function<double, double>>(rb_mCvCudaDevice, "UnaryFunctionDoubleDouble").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<double, double>>, double, double>);
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