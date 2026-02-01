

template<typename T>
inline Rice::Data_Type<cv::cudev::plus<T>> plus_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::plus<T>>(parent, name).
    template define_method<T(cv::cudev::plus<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::plus<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::minus<T>> minus_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::minus<T>>(parent, name).
    template define_method<T(cv::cudev::minus<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::minus<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::multiplies<T>> multiplies_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::multiplies<T>>(parent, name).
    template define_method<T(cv::cudev::multiplies<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::multiplies<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::divides<T>> divides_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::divides<T>>(parent, name).
    template define_method<T(cv::cudev::divides<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::divides<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::modulus<T>> modulus_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::modulus<T>>(parent, name).
    template define_method<T(cv::cudev::modulus<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::modulus<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::negate<T>> negate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::negate<T>>(parent, name).
    template define_method<T(cv::cudev::negate<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::negate<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::equal_to<T>> equal_to_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::equal_to<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::equal_to<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::equal_to<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::not_equal_to<T>> not_equal_to_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::not_equal_to<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::not_equal_to<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::not_equal_to<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::greater<T>> greater_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::greater<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::greater<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::greater<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::less<T>> less_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::less<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::less<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::less<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::greater_equal<T>> greater_equal_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::greater_equal<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::greater_equal<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::greater_equal<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::less_equal<T>> less_equal_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::less_equal<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::less_equal<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::less_equal<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::logical_and<T>> logical_and_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::logical_and<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::logical_and<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::logical_and<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::logical_or<T>> logical_or_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::logical_or<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::logical_or<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::logical_or<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::logical_not<T>> logical_not_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::logical_not<T>>(parent, name).
    template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::logical_not<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::logical_not<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::bit_and<T>> bit_and_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::bit_and<T>>(parent, name).
    template define_method<T(cv::cudev::bit_and<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_and<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::bit_or<T>> bit_or_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::bit_or<T>>(parent, name).
    template define_method<T(cv::cudev::bit_or<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_or<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::bit_xor<T>> bit_xor_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::bit_xor<T>>(parent, name).
    template define_method<T(cv::cudev::bit_xor<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_xor<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::bit_not<T>> bit_not_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::bit_not<T>>(parent, name).
    template define_method<T(cv::cudev::bit_not<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_not<T>::operator(),
      Arg("v"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::bit_lshift<T>> bit_lshift_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::bit_lshift<T>>(parent, name).
    template define_method<T(cv::cudev::bit_lshift<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_lshift<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::bit_rshift<T>> bit_rshift_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::bit_rshift<T>>(parent, name).
    template define_method<T(cv::cudev::bit_rshift<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_rshift<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::identity<T>> identity_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::identity<T>>(parent, name).
    template define_method<T(cv::cudev::identity<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::identity<T>::operator(),
      Arg("x"));
}

template<typename T1, typename T2>
inline Rice::Data_Type<cv::cudev::project1st<T1, T2>> project1st_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::project1st<T1, T2>>(parent, name).
    template define_method<T1(cv::cudev::project1st<T1, T2>::*)(typename TypeTraits<T1>::parameter_type, typename TypeTraits<T2>::parameter_type) const>("call", &cv::cudev::project1st<T1, T2>::operator(),
      Arg("lhs"), Arg("arg_1"));
}

template<typename T1, typename T2>
inline Rice::Data_Type<cv::cudev::project2nd<T1, T2>> project2nd_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::project2nd<T1, T2>>(parent, name).
    template define_method<T2(cv::cudev::project2nd<T1, T2>::*)(typename TypeTraits<T1>::parameter_type, typename TypeTraits<T2>::parameter_type) const>("call", &cv::cudev::project2nd<T1, T2>::operator(),
      Arg("arg_0"), Arg("rhs"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::maximum<T>> maximum_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::maximum<T>>(parent, name).
    template define_method<T(cv::cudev::maximum<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::maximum<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::minimum<T>> minimum_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::minimum<T>>(parent, name).
    template define_method<T(cv::cudev::minimum<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::minimum<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::abs_func<T>> abs_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::abs_func<T>>(parent, name).
    template define_method<T(cv::cudev::abs_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::abs_func<T>::operator(),
      Arg("x"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::absdiff_func<T>> absdiff_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::absdiff_func<T>>(parent, name).
    template define_method<T(cv::cudev::absdiff_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::absdiff_func<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::sqr_func<T>> sqr_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::sqr_func<T>>(parent, name).
    template define_method<T(cv::cudev::sqr_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::sqr_func<T>::operator(),
      Arg("x"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::sqrt_func<T>> sqrt_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::sqrt_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::sqrt_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::sqrt_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::exp_func<T>> exp_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::exp_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::exp_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::exp_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::exp2_func<T>> exp2_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::exp2_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::exp2_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::exp2_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::exp10_func<T>> exp10_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::exp10_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::exp10_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::exp10_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::log_func<T>> log_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::log_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::log_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::log_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::log2_func<T>> log2_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::log2_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::log2_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::log2_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::log10_func<T>> log10_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::log10_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::log10_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::log10_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::sin_func<T>> sin_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::sin_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::sin_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::sin_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::cos_func<T>> cos_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::cos_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::cos_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::cos_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::tan_func<T>> tan_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::tan_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::tan_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::tan_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::asin_func<T>> asin_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::asin_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::asin_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::asin_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::acos_func<T>> acos_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::acos_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::acos_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::acos_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::atan_func<T>> atan_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::atan_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::atan_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::atan_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::sinh_func<T>> sinh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::sinh_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::sinh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::sinh_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::cosh_func<T>> cosh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::cosh_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::cosh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::cosh_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::tanh_func<T>> tanh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::tanh_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::tanh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::tanh_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::asinh_func<T>> asinh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::asinh_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::asinh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::asinh_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::acosh_func<T>> acosh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::acosh_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::acosh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::acosh_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::atanh_func<T>> atanh_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::atanh_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::atanh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::atanh_func<T>::operator(),
      Arg("a"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::hypot_func<T>> hypot_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::hypot_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::hypot_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::hypot_func<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::atan2_func<T>> atan2_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::atan2_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::atan2_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::atan2_func<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::magnitude_func<T>> magnitude_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::magnitude_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::magnitude_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::magnitude_func<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T2>
inline Rice::Data_Type<cv::cudev::magnitude_interleaved_func<T2>> magnitude_interleaved_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::magnitude_interleaved_func<T2>>(parent, name).
    template define_method<typename cv::cudev::magnitude_interleaved_func<T2>::T(cv::cudev::magnitude_interleaved_func<T2>::*)(typename cv::cudev::magnitude_interleaved_func<T2>::parameter_type) const>("call", &cv::cudev::magnitude_interleaved_func<T2>::operator(),
      Arg("ab"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::magnitude_sqr_func<T>> magnitude_sqr_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::magnitude_sqr_func<T>>(parent, name).
    template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::magnitude_sqr_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::magnitude_sqr_func<T>::operator(),
      Arg("a"), Arg("b"));
}

template<typename T2>
inline Rice::Data_Type<cv::cudev::magnitude_sqr_interleaved_func<T2>> magnitude_sqr_interleaved_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::magnitude_sqr_interleaved_func<T2>>(parent, name).
    template define_method<typename cv::cudev::magnitude_sqr_interleaved_func<T2>::T(cv::cudev::magnitude_sqr_interleaved_func<T2>::*)(typename cv::cudev::magnitude_sqr_interleaved_func<T2>::parameter_type) const>("call", &cv::cudev::magnitude_sqr_interleaved_func<T2>::operator(),
      Arg("ab"));
}

template<typename T, bool angleInDegrees>
inline Rice::Data_Type<cv::cudev::direction_func<T, angleInDegrees>> direction_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::direction_func<T, angleInDegrees>>(parent, name).
    template define_method<T(cv::cudev::direction_func<T, angleInDegrees>::*)(T, T) const>("call", &cv::cudev::direction_func<T, angleInDegrees>::operator(),
      Arg("x"), Arg("y"));
}

template<typename T2, bool angleInDegrees>
inline Rice::Data_Type<cv::cudev::direction_interleaved_func<T2, angleInDegrees>> direction_interleaved_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::direction_interleaved_func<T2, angleInDegrees>>(parent, name).
    template define_method<typename cv::cudev::direction_interleaved_func<T2, angleInDegrees>::T(cv::cudev::direction_interleaved_func<T2, angleInDegrees>::*)(T2) const>("call", &cv::cudev::direction_interleaved_func<T2, angleInDegrees>::operator(),
      Arg("xy"));
}

template<typename T2, bool angleInDegrees>
inline Rice::Data_Type<cv::cudev::magnitude_direction_interleaved_func<T2, angleInDegrees>> magnitude_direction_interleaved_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::magnitude_direction_interleaved_func<T2, angleInDegrees>>(parent, name).
    template define_method<T2(cv::cudev::magnitude_direction_interleaved_func<T2, angleInDegrees>::*)(T2) const>("call", &cv::cudev::magnitude_direction_interleaved_func<T2, angleInDegrees>::operator(),
      Arg("xy"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::pow_func<T>> pow_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::pow_func<T>>(parent, name).
    template define_method<float(cv::cudev::pow_func<T>::*)(T, float) const>("call", &cv::cudev::pow_func<T>::operator(),
      Arg("val"), Arg("power"));
}

template<typename T, typename D>
inline Rice::Data_Type<cv::cudev::saturate_cast_func<T, D>> saturate_cast_func_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::saturate_cast_func<T, D>>(parent, name).
    template define_method<D(cv::cudev::saturate_cast_func<T, D>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::saturate_cast_func<T, D>::operator(),
      Arg("v"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::ThreshBinaryFunc<T>> ThreshBinaryFunc_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ThreshBinaryFunc<T>>(parent, name).
    define_attr("thresh", &cv::cudev::ThreshBinaryFunc<T>::thresh).
    define_attr("max_val", &cv::cudev::ThreshBinaryFunc<T>::maxVal).
    template define_method<T(cv::cudev::ThreshBinaryFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshBinaryFunc<T>::operator(),
      Arg("src"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::ThreshBinaryInvFunc<T>> ThreshBinaryInvFunc_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ThreshBinaryInvFunc<T>>(parent, name).
    define_attr("thresh", &cv::cudev::ThreshBinaryInvFunc<T>::thresh).
    define_attr("max_val", &cv::cudev::ThreshBinaryInvFunc<T>::maxVal).
    template define_method<T(cv::cudev::ThreshBinaryInvFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshBinaryInvFunc<T>::operator(),
      Arg("src"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::ThreshTruncFunc<T>> ThreshTruncFunc_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ThreshTruncFunc<T>>(parent, name).
    define_attr("thresh", &cv::cudev::ThreshTruncFunc<T>::thresh).
    template define_method<T(cv::cudev::ThreshTruncFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshTruncFunc<T>::operator(),
      Arg("src"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::ThreshToZeroFunc<T>> ThreshToZeroFunc_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ThreshToZeroFunc<T>>(parent, name).
    define_attr("thresh", &cv::cudev::ThreshToZeroFunc<T>::thresh).
    template define_method<T(cv::cudev::ThreshToZeroFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshToZeroFunc<T>::operator(),
      Arg("src"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::ThreshToZeroInvFunc<T>> ThreshToZeroInvFunc_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ThreshToZeroInvFunc<T>>(parent, name).
    define_attr("thresh", &cv::cudev::ThreshToZeroInvFunc<T>::thresh).
    template define_method<T(cv::cudev::ThreshToZeroInvFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshToZeroInvFunc<T>::operator(),
      Arg("src"));
}

template<typename T, int cn, int i>
inline Rice::Data_Type<cv::cudev::InRangeComparator<T, cn, i>> InRangeComparator_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::InRangeComparator<T, cn, i>>(parent, name).
    template define_method<bool(cv::cudev::InRangeComparator<T, cn, i>::*)(const typename MakeVec<T, cn>::type&, const typename MakeVec<T, cn>::type&, const typename MakeVec<T, cn>::type&) const>("call", &cv::cudev::InRangeComparator<T, cn, i>::operator(),
      Arg("lowerb"), Arg("upperb"), Arg("v"));
}

template<typename T, int cn, int i>
inline Rice::Data_Type<cv::cudev::InRangeCopier<T, cn, i>> InRangeCopier_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::InRangeCopier<T, cn, i>>(parent, name).
    template define_method<void(cv::cudev::InRangeCopier<T, cn, i>::*)(const cv::Scalar&, typename MakeVec<T, cn>::type&) const>("call", &cv::cudev::InRangeCopier<T, cn, i>::operator(),
      Arg("in"), Arg("out"));
}

template<typename T, int cn>
inline Rice::Data_Type<cv::cudev::InRangeFunc<T, cn>> InRangeFunc_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::InRangeFunc<T, cn>>(parent, name).
    define_attr("lowerb", &cv::cudev::InRangeFunc<T, cn>::lowerb).
    define_attr("upperb", &cv::cudev::InRangeFunc<T, cn>::upperb).
    define_constructor(Constructor<cv::cudev::InRangeFunc<T, cn>, const cv::Scalar&, const cv::Scalar&>(),
      Arg("lowerb_scalar"), Arg("upperb_scalar")).
    template define_method<uchar(cv::cudev::InRangeFunc<T, cn>::*)(const typename MakeVec<T, cn>::type&) const>("call", &cv::cudev::InRangeFunc<T, cn>::operator(),
      Arg("src"));
}

template<typename Predicate>
inline Rice::Data_Type<cv::cudev::UnaryNegate<Predicate>> UnaryNegate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::UnaryNegate<Predicate>>(parent, name).
    define_attr("pred", &cv::cudev::UnaryNegate<Predicate>::pred).
    template define_method<typename Predicate::result_type(cv::cudev::UnaryNegate<Predicate>::*)(typename TypeTraits<typename Predicate::argument_type>::parameter_type) const>("call", &cv::cudev::UnaryNegate<Predicate>::operator(),
      Arg("x"));
}

template<typename Predicate>
inline Rice::Data_Type<cv::cudev::BinaryNegate<Predicate>> BinaryNegate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::BinaryNegate<Predicate>>(parent, name).
    define_attr("pred", &cv::cudev::BinaryNegate<Predicate>::pred).
    template define_method<typename Predicate::result_type(cv::cudev::BinaryNegate<Predicate>::*)(typename TypeTraits<typename Predicate::first_argument_type>::parameter_type, typename TypeTraits<typename Predicate::second_argument_type>::parameter_type) const>("call", &cv::cudev::BinaryNegate<Predicate>::operator(),
      Arg("x"), Arg("y"));
}

template<typename Op>
inline Rice::Data_Type<cv::cudev::Binder1st<Op>> Binder1st_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Binder1st<Op>>(parent, name).
    define_attr("op", &cv::cudev::Binder1st<Op>::op).
    define_attr("arg1", &cv::cudev::Binder1st<Op>::arg1).
    template define_method<typename Op::result_type(cv::cudev::Binder1st<Op>::*)(typename TypeTraits<typename Op::second_argument_type>::parameter_type) const>("call", &cv::cudev::Binder1st<Op>::operator(),
      Arg("a"));
}

template<typename Op>
inline Rice::Data_Type<cv::cudev::Binder2nd<Op>> Binder2nd_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Binder2nd<Op>>(parent, name).
    define_attr("op", &cv::cudev::Binder2nd<Op>::op).
    define_attr("arg2", &cv::cudev::Binder2nd<Op>::arg2).
    template define_method<typename Op::result_type(cv::cudev::Binder2nd<Op>::*)(typename TypeTraits<typename Op::first_argument_type>::parameter_type) const>("call", &cv::cudev::Binder2nd<Op>::operator(),
      Arg("a"));
}

template<typename F>
inline Rice::Data_Type<cv::cudev::IsUnaryFunction<F>> IsUnaryFunction_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::IsUnaryFunction<F>>(parent, name).
    define_constant("Value", (int)cv::cudev::IsUnaryFunction<F>::value).
    template define_singleton_function<F(*)()>("make_f", &cv::cudev::IsUnaryFunction<F>::makeF);
}

template<typename F>
inline Rice::Data_Type<cv::cudev::IsBinaryFunction<F>> IsBinaryFunction_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::IsBinaryFunction<F>>(parent, name).
    define_constant("Value", (int)cv::cudev::IsBinaryFunction<F>::value).
    template define_singleton_function<F(*)()>("make_f", &cv::cudev::IsBinaryFunction<F>::makeF);
}

