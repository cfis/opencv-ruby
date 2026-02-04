

template<typename T>
inline Rice::Data_Type<cv::cuda::device::plus<T>> plus_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::plus<T>>(parent, name).
    template define_method<T(cv::cuda::device::plus<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::plus<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::plus<T>>()).
    define_constructor(Constructor<cv::cuda::device::plus<T>, const cv::cuda::device::plus<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::minus<T>> minus_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::minus<T>>(parent, name).
    template define_method<T(cv::cuda::device::minus<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::minus<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::minus<T>>()).
    define_constructor(Constructor<cv::cuda::device::minus<T>, const cv::cuda::device::minus<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::multiplies<T>> multiplies_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::multiplies<T>>(parent, name).
    template define_method<T(cv::cuda::device::multiplies<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::multiplies<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::multiplies<T>>()).
    define_constructor(Constructor<cv::cuda::device::multiplies<T>, const cv::cuda::device::multiplies<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::divides<T>> divides_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::divides<T>>(parent, name).
    template define_method<T(cv::cuda::device::divides<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::divides<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::divides<T>>()).
    define_constructor(Constructor<cv::cuda::device::divides<T>, const cv::cuda::device::divides<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::modulus<T>> modulus_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::modulus<T>>(parent, name).
    template define_method<T(cv::cuda::device::modulus<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::modulus<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::modulus<T>>()).
    define_constructor(Constructor<cv::cuda::device::modulus<T>, const cv::cuda::device::modulus<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::negate<T>> negate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::negate<T>>(parent, name).
    template define_method<T(cv::cuda::device::negate<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::negate<T>::operator(),
      Arg("a")).
    define_constructor(Constructor<cv::cuda::device::negate<T>>()).
    define_constructor(Constructor<cv::cuda::device::negate<T>, const cv::cuda::device::negate<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::equal_to<T>> equal_to_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::equal_to<T>>(parent, name).
    template define_method<bool(cv::cuda::device::equal_to<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::equal_to<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::equal_to<T>>()).
    define_constructor(Constructor<cv::cuda::device::equal_to<T>, const cv::cuda::device::equal_to<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::not_equal_to<T>> not_equal_to_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::not_equal_to<T>>(parent, name).
    template define_method<bool(cv::cuda::device::not_equal_to<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::not_equal_to<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::not_equal_to<T>>()).
    define_constructor(Constructor<cv::cuda::device::not_equal_to<T>, const cv::cuda::device::not_equal_to<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::greater<T>> greater_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::greater<T>>(parent, name).
    template define_method<bool(cv::cuda::device::greater<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::greater<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::greater<T>>()).
    define_constructor(Constructor<cv::cuda::device::greater<T>, const cv::cuda::device::greater<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::less<T>> less_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::less<T>>(parent, name).
    template define_method<bool(cv::cuda::device::less<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::less<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::less<T>>()).
    define_constructor(Constructor<cv::cuda::device::less<T>, const cv::cuda::device::less<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::greater_equal<T>> greater_equal_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::greater_equal<T>>(parent, name).
    template define_method<bool(cv::cuda::device::greater_equal<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::greater_equal<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::greater_equal<T>>()).
    define_constructor(Constructor<cv::cuda::device::greater_equal<T>, const cv::cuda::device::greater_equal<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::less_equal<T>> less_equal_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::less_equal<T>>(parent, name).
    template define_method<bool(cv::cuda::device::less_equal<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::less_equal<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::less_equal<T>>()).
    define_constructor(Constructor<cv::cuda::device::less_equal<T>, const cv::cuda::device::less_equal<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::logical_and<T>> logical_and_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::logical_and<T>>(parent, name).
    template define_method<bool(cv::cuda::device::logical_and<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::logical_and<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::logical_and<T>>()).
    define_constructor(Constructor<cv::cuda::device::logical_and<T>, const cv::cuda::device::logical_and<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::logical_or<T>> logical_or_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::logical_or<T>>(parent, name).
    template define_method<bool(cv::cuda::device::logical_or<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::logical_or<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::logical_or<T>>()).
    define_constructor(Constructor<cv::cuda::device::logical_or<T>, const cv::cuda::device::logical_or<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::logical_not<T>> logical_not_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::logical_not<T>>(parent, name).
    template define_method<bool(cv::cuda::device::logical_not<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::logical_not<T>::operator(),
      Arg("a")).
    define_constructor(Constructor<cv::cuda::device::logical_not<T>>()).
    define_constructor(Constructor<cv::cuda::device::logical_not<T>, const cv::cuda::device::logical_not<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bit_and<T>> bit_and_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bit_and<T>>(parent, name).
    template define_method<T(cv::cuda::device::bit_and<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::bit_and<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::bit_and<T>>()).
    define_constructor(Constructor<cv::cuda::device::bit_and<T>, const cv::cuda::device::bit_and<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bit_or<T>> bit_or_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bit_or<T>>(parent, name).
    template define_method<T(cv::cuda::device::bit_or<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::bit_or<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::bit_or<T>>()).
    define_constructor(Constructor<cv::cuda::device::bit_or<T>, const cv::cuda::device::bit_or<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bit_xor<T>> bit_xor_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bit_xor<T>>(parent, name).
    template define_method<T(cv::cuda::device::bit_xor<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::bit_xor<T>::operator(),
      Arg("a"), Arg("b")).
    define_constructor(Constructor<cv::cuda::device::bit_xor<T>>()).
    define_constructor(Constructor<cv::cuda::device::bit_xor<T>, const cv::cuda::device::bit_xor<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bit_not<T>> bit_not_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bit_not<T>>(parent, name).
    template define_method<T(cv::cuda::device::bit_not<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::bit_not<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::bit_not<T>>()).
    define_constructor(Constructor<cv::cuda::device::bit_not<T>, const cv::cuda::device::bit_not<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::identity<T>> identity_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::identity<T>>(parent, name).
    template define_method<typename TypeTraits<T>::ParameterType(cv::cuda::device::identity<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::identity<T>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::identity<T>>()).
    define_constructor(Constructor<cv::cuda::device::identity<T>, const cv::cuda::device::identity<T>&>(),
      Arg("arg_0"));
}

template<typename T1, typename T2>
inline Rice::Data_Type<cv::cuda::device::project1st<T1, T2>> project1st_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::project1st<T1, T2>>(parent, name).
    template define_method<typename TypeTraits<T1>::ParameterType(cv::cuda::device::project1st<T1, T2>::*)(typename TypeTraits<T1>::ParameterType, typename TypeTraits<T2>::ParameterType) const>("call", &cv::cuda::device::project1st<T1, T2>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::project1st<T1, T2>>()).
    define_constructor(Constructor<cv::cuda::device::project1st<T1, T2>, const cv::cuda::device::project1st<T1, T2>&>(),
      Arg("arg_0"));
}

template<typename T1, typename T2>
inline Rice::Data_Type<cv::cuda::device::project2nd<T1, T2>> project2nd_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::project2nd<T1, T2>>(parent, name).
    template define_method<typename TypeTraits<T2>::ParameterType(cv::cuda::device::project2nd<T1, T2>::*)(typename TypeTraits<T1>::ParameterType, typename TypeTraits<T2>::ParameterType) const>("call", &cv::cuda::device::project2nd<T1, T2>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::project2nd<T1, T2>>()).
    define_constructor(Constructor<cv::cuda::device::project2nd<T1, T2>, const cv::cuda::device::project2nd<T1, T2>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::maximum<T>> maximum_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::maximum<T>>(parent, name).
    template define_method<T(cv::cuda::device::maximum<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::maximum<T>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::maximum<T>>()).
    define_constructor(Constructor<cv::cuda::device::maximum<T>, const cv::cuda::device::maximum<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::minimum<T>> minimum_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::minimum<T>>(parent, name).
    template define_method<T(cv::cuda::device::minimum<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::minimum<T>::operator(),
      Arg("lhs"), Arg("rhs")).
    define_constructor(Constructor<cv::cuda::device::minimum<T>>()).
    define_constructor(Constructor<cv::cuda::device::minimum<T>, const cv::cuda::device::minimum<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::abs_func<T>> abs_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::abs_func<T>>(parent, name).
    template define_method<T(cv::cuda::device::abs_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::abs_func<T>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::abs_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::abs_func<T>, const cv::cuda::device::abs_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::sqrt_func<T>> sqrt_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::sqrt_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::sqrt_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::sqrt_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sqrt_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::sqrt_func<T>, const cv::cuda::device::sqrt_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::exp_func<T>> exp_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::exp_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::exp_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::exp_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::exp_func<T>, const cv::cuda::device::exp_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::exp2_func<T>> exp2_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::exp2_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::exp2_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::exp2_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp2_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::exp2_func<T>, const cv::cuda::device::exp2_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::exp10_func<T>> exp10_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::exp10_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::exp10_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::exp10_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::exp10_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::exp10_func<T>, const cv::cuda::device::exp10_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::log_func<T>> log_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::log_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::log_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::log_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::log_func<T>, const cv::cuda::device::log_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::log2_func<T>> log2_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::log2_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::log2_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::log2_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log2_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::log2_func<T>, const cv::cuda::device::log2_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::log10_func<T>> log10_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::log10_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::log10_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::log10_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::log10_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::log10_func<T>, const cv::cuda::device::log10_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::sin_func<T>> sin_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::sin_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::sin_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::sin_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sin_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::sin_func<T>, const cv::cuda::device::sin_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::cos_func<T>> cos_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::cos_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::cos_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::cos_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::cos_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::cos_func<T>, const cv::cuda::device::cos_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::tan_func<T>> tan_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::tan_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::tan_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::tan_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::tan_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::tan_func<T>, const cv::cuda::device::tan_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::asin_func<T>> asin_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::asin_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::asin_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::asin_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::asin_func<T>>());
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::acos_func<T>> acos_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::acos_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::acos_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::acos_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::acos_func<T>>());
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::atan_func<T>> atan_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::atan_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::atan_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::atan_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::atan_func<T>>());
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::sinh_func<T>> sinh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::sinh_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::sinh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::sinh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::sinh_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::sinh_func<T>, const cv::cuda::device::sinh_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::cosh_func<T>> cosh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::cosh_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::cosh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::cosh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::cosh_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::cosh_func<T>, const cv::cuda::device::cosh_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::tanh_func<T>> tanh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::tanh_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::tanh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::tanh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::tanh_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::tanh_func<T>, const cv::cuda::device::tanh_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::asinh_func<T>> asinh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::asinh_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::asinh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::asinh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::asinh_func<T>>());
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::acosh_func<T>> acosh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::acosh_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::acosh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::acosh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::acosh_func<T>>());
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::atanh_func<T>> atanh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::atanh_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::atanh_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::atanh_func<T>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::atanh_func<T>>());
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hypot_func<T>> hypot_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hypot_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::hypot_func<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::hypot_func<T>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::hypot_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::hypot_func<T>, const cv::cuda::device::hypot_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::atan2_func<T>> atan2_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::atan2_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::atan2_func<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::atan2_func<T>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::atan2_func<T>>());
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::pow_func<T>> pow_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::pow_func<T>>(parent, name).
    template define_method<float(cv::cuda::device::pow_func<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::pow_func<T>::operator(),
      Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::cuda::device::pow_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::pow_func<T>, const cv::cuda::device::pow_func<T>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hypot_sqr_func<T>> hypot_sqr_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hypot_sqr_func<T>>(parent, name).
    template define_method<T(cv::cuda::device::hypot_sqr_func<T>::*)(typename TypeTraits<T>::ParameterType, typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::hypot_sqr_func<T>::operator(),
      Arg("src1"), Arg("src2")).
    define_constructor(Constructor<cv::cuda::device::hypot_sqr_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::hypot_sqr_func<T>, const cv::cuda::device::hypot_sqr_func<T>&>(),
      Arg("arg_0"));
}

template<typename T, typename D>
inline Rice::Data_Type<cv::cuda::device::saturate_cast_func<T, D>> saturate_cast_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::saturate_cast_func<T, D>>(parent, name).
    template define_method<D(cv::cuda::device::saturate_cast_func<T, D>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::saturate_cast_func<T, D>::operator(),
      Arg("v")).
    define_constructor(Constructor<cv::cuda::device::saturate_cast_func<T, D>>()).
    define_constructor(Constructor<cv::cuda::device::saturate_cast_func<T, D>, const cv::cuda::device::saturate_cast_func<T, D>&>(),
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::thresh_binary_func<T>> thresh_binary_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::thresh_binary_func<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_")).
    template define_method<T(cv::cuda::device::thresh_binary_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_binary_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_func<T>, const cv::cuda::device::thresh_binary_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_binary_func<T>::thresh).
    define_attr("max_val", &cv::cuda::device::thresh_binary_func<T>::maxVal);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::thresh_binary_inv_func<T>> thresh_binary_inv_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::thresh_binary_inv_func<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_inv_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_")).
    template define_method<T(cv::cuda::device::thresh_binary_inv_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_binary_inv_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_inv_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_binary_inv_func<T>, const cv::cuda::device::thresh_binary_inv_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_binary_inv_func<T>::thresh).
    define_attr("max_val", &cv::cuda::device::thresh_binary_inv_func<T>::maxVal);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::thresh_trunc_func<T>> thresh_trunc_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::thresh_trunc_func<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::thresh_trunc_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_") = static_cast<T>(0)).
    template define_method<T(cv::cuda::device::thresh_trunc_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_trunc_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_trunc_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_trunc_func<T>, const cv::cuda::device::thresh_trunc_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_trunc_func<T>::thresh);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::thresh_to_zero_func<T>> thresh_to_zero_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::thresh_to_zero_func<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_") = static_cast<T>(0)).
    template define_method<T(cv::cuda::device::thresh_to_zero_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_to_zero_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_func<T>, const cv::cuda::device::thresh_to_zero_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_to_zero_func<T>::thresh);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::thresh_to_zero_inv_func<T>> thresh_to_zero_inv_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::thresh_to_zero_inv_func<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_inv_func<T>, T, T>(),
      Arg("thresh_"), Arg("max_val_") = static_cast<T>(0)).
    template define_method<T(cv::cuda::device::thresh_to_zero_inv_func<T>::*)(typename TypeTraits<T>::ParameterType) const>("call", &cv::cuda::device::thresh_to_zero_inv_func<T>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_inv_func<T>>()).
    define_constructor(Constructor<cv::cuda::device::thresh_to_zero_inv_func<T>, const cv::cuda::device::thresh_to_zero_inv_func<T>&>(),
      Arg("other")).
    define_attr("thresh", &cv::cuda::device::thresh_to_zero_inv_func<T>::thresh);
}

template<typename Predicate>
inline Rice::Data_Type<cv::cuda::device::unary_negate<Predicate>> unary_negate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::unary_negate<Predicate>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::unary_negate<Predicate>, const Predicate&>(),
      Arg("p")).
    template define_method<bool(cv::cuda::device::unary_negate<Predicate>::*)(typename TypeTraits<typename Predicate::argument_type>::ParameterType) const>("call", &cv::cuda::device::unary_negate<Predicate>::operator(),
      Arg("x")).
    define_constructor(Constructor<cv::cuda::device::unary_negate<Predicate>>()).
    define_constructor(Constructor<cv::cuda::device::unary_negate<Predicate>, const cv::cuda::device::unary_negate<Predicate>&>(),
      Arg("other")).
    define_attr("pred", &cv::cuda::device::unary_negate<Predicate>::pred);
}

template<typename Predicate>
inline Rice::Data_Type<cv::cuda::device::binary_negate<Predicate>> binary_negate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::binary_negate<Predicate>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::binary_negate<Predicate>, const Predicate&>(),
      Arg("p")).
    template define_method<bool(cv::cuda::device::binary_negate<Predicate>::*)(typename TypeTraits<typename Predicate::first_argument_type>::ParameterType, typename TypeTraits<typename Predicate::second_argument_type>::ParameterType) const>("call", &cv::cuda::device::binary_negate<Predicate>::operator(),
      Arg("x"), Arg("y")).
    define_constructor(Constructor<cv::cuda::device::binary_negate<Predicate>>()).
    define_constructor(Constructor<cv::cuda::device::binary_negate<Predicate>, const cv::cuda::device::binary_negate<Predicate>&>(),
      Arg("other")).
    define_attr("pred", &cv::cuda::device::binary_negate<Predicate>::pred);
}

template<typename Op>
inline Rice::Data_Type<cv::cuda::device::binder1st<Op>> binder1st_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::binder1st<Op>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::binder1st<Op>, const Op&, const typename Op::first_argument_type&>(),
      Arg("op_"), Arg("arg1_")).
    template define_method<typename Op::result_type(cv::cuda::device::binder1st<Op>::*)(typename TypeTraits<typename Op::second_argument_type>::ParameterType) const>("call", &cv::cuda::device::binder1st<Op>::operator(),
      Arg("a")).
    define_constructor(Constructor<cv::cuda::device::binder1st<Op>>()).
    define_constructor(Constructor<cv::cuda::device::binder1st<Op>, const cv::cuda::device::binder1st<Op>&>(),
      Arg("other")).
    define_attr("op", &cv::cuda::device::binder1st<Op>::op).
    define_attr("arg1", &cv::cuda::device::binder1st<Op>::arg1);
}

template<typename Op>
inline Rice::Data_Type<cv::cuda::device::binder2nd<Op>> binder2nd_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::binder2nd<Op>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::binder2nd<Op>, const Op&, const typename Op::second_argument_type&>(),
      Arg("op_"), Arg("arg2_")).
    template define_method<typename Op::result_type(cv::cuda::device::binder2nd<Op>::*)(typename TypeTraits<typename Op::first_argument_type>::ParameterType) const>("call", &cv::cuda::device::binder2nd<Op>::operator(),
      Arg("a")).
    define_constructor(Constructor<cv::cuda::device::binder2nd<Op>>()).
    define_constructor(Constructor<cv::cuda::device::binder2nd<Op>, const cv::cuda::device::binder2nd<Op>&>(),
      Arg("other")).
    define_attr("op", &cv::cuda::device::binder2nd<Op>::op).
    define_attr("arg2", &cv::cuda::device::binder2nd<Op>::arg2);
}

template<typename F>
inline Rice::Data_Type<cv::cuda::device::IsUnaryFunction<F>> IsUnaryFunction_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::IsUnaryFunction<F>>(parent, name).
    template define_singleton_function<F(*)()>("make_f", &cv::cuda::device::IsUnaryFunction<F>::makeF).
    define_constant("Value", (int)cv::cuda::device::IsUnaryFunction<F>::value);
}

template<typename F>
inline Rice::Data_Type<cv::cuda::device::IsBinaryFunction<F>> IsBinaryFunction_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::IsBinaryFunction<F>>(parent, name).
    template define_singleton_function<F(*)()>("make_f", &cv::cuda::device::IsBinaryFunction<F>::makeF).
    define_constant("Value", (int)cv::cuda::device::IsBinaryFunction<F>::value);
}

template<size_t src_elem_size, size_t dst_elem_size>
inline Rice::Data_Type<cv::cuda::device::functional_detail::UnOpShift<src_elem_size, dst_elem_size>> UnOpShift_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::functional_detail::UnOpShift<src_elem_size, dst_elem_size>>(parent, name).
    define_constant("Shift", (int)cv::cuda::device::functional_detail::UnOpShift<src_elem_size, dst_elem_size>::shift);
}

template<typename T, typename D>
inline Rice::Data_Type<cv::cuda::device::functional_detail::DefaultUnaryShift<T, D>> DefaultUnaryShift_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::functional_detail::DefaultUnaryShift<T, D>>(parent, name).
    define_constant("Shift", (int)cv::cuda::device::functional_detail::DefaultUnaryShift<T, D>::shift);
}

template<size_t src_elem_size1, size_t src_elem_size2, size_t dst_elem_size>
inline Rice::Data_Type<cv::cuda::device::functional_detail::BinOpShift<src_elem_size1, src_elem_size2, dst_elem_size>> BinOpShift_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::functional_detail::BinOpShift<src_elem_size1, src_elem_size2, dst_elem_size>>(parent, name).
    define_constant("Shift", (int)cv::cuda::device::functional_detail::BinOpShift<src_elem_size1, src_elem_size2, dst_elem_size>::shift);
}

template<typename T1, typename T2, typename D>
inline Rice::Data_Type<cv::cuda::device::functional_detail::DefaultBinaryShift<T1, T2, D>> DefaultBinaryShift_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::functional_detail::DefaultBinaryShift<T1, T2, D>>(parent, name).
    define_constant("Shift", (int)cv::cuda::device::functional_detail::DefaultBinaryShift<T1, T2, D>::shift);
}

template<typename Func>
inline Rice::Data_Type<cv::cuda::device::DefaultTransformShift<Func>> DefaultTransformShift_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::DefaultTransformShift<Func>>(parent, name).
    define_constant("Shift", (int)cv::cuda::device::DefaultTransformShift<Func>::shift);
}

template<typename Func>
inline Rice::Data_Type<cv::cuda::device::DefaultTransformFunctorTraits<Func>> DefaultTransformFunctorTraits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::DefaultTransformFunctorTraits<Func>>(parent, name).
    define_constant("Simple_block_dim_x", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::simple_block_dim_x).
    define_constant("Simple_block_dim_y", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::simple_block_dim_y).
    define_constant("Smart_block_dim_x", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::smart_block_dim_x).
    define_constant("Smart_block_dim_y", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::smart_block_dim_y).
    define_constant("Smart_shift", (int)cv::cuda::device::DefaultTransformFunctorTraits<Func>::smart_shift);
}

