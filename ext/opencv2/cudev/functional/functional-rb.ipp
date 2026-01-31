#include <opencv2/cudev/functional/functional.hpp>
#include "functional-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void plus_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::plus<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::plus<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void minus_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::minus<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::minus<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void multiplies_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::multiplies<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::multiplies<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void divides_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::divides<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::divides<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void modulus_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::modulus<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::modulus<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void negate_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::negate<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::negate<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void equal_to_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::equal_to<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::equal_to<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void not_equal_to_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::not_equal_to<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::not_equal_to<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void greater_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::greater<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::greater<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void less_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::less<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::less<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void greater_equal_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::greater_equal<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::greater_equal<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void less_equal_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::less_equal<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::less_equal<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void logical_and_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::logical_and<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::logical_and<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void logical_or_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::logical_or<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::logical_or<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void logical_not_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<uchar, VecTraits<T>::cn>::type(cv::cudev::logical_not<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::logical_not<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void bit_and_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::bit_and<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_and<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void bit_or_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::bit_or<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_or<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void bit_xor_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::bit_xor<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_xor<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void bit_not_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::bit_not<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_not<T>::operator(),
      Arg("v"));
};

template<typename Data_Type_T, typename T>
inline void bit_lshift_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::bit_lshift<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_lshift<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void bit_rshift_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::bit_rshift<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::bit_rshift<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void identity_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::identity<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::identity<T>::operator(),
      Arg("x"));
};

template<typename Data_Type_T, typename T1, typename T2>
inline void project1st_builder(Data_Type_T& klass)
{
  klass.template define_method<T1(cv::cudev::project1st<T1, T2>::*)(typename TypeTraits<T1>::parameter_type, typename TypeTraits<T2>::parameter_type) const>("call", &cv::cudev::project1st<T1, T2>::operator(),
      Arg("lhs"), Arg("arg_1"));
};

template<typename Data_Type_T, typename T1, typename T2>
inline void project2nd_builder(Data_Type_T& klass)
{
  klass.template define_method<T2(cv::cudev::project2nd<T1, T2>::*)(typename TypeTraits<T1>::parameter_type, typename TypeTraits<T2>::parameter_type) const>("call", &cv::cudev::project2nd<T1, T2>::operator(),
      Arg("arg_0"), Arg("rhs"));
};

template<typename Data_Type_T, typename T>
inline void maximum_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::maximum<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::maximum<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void minimum_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::minimum<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::minimum<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void abs_func_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::abs_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::abs_func<T>::operator(),
      Arg("x"));
};

template<typename Data_Type_T, typename T>
inline void absdiff_func_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::absdiff_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::absdiff_func<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void sqr_func_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::sqr_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::sqr_func<T>::operator(),
      Arg("x"));
};

template<typename Data_Type_T, typename T>
inline void sqrt_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::sqrt_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::sqrt_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void exp_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::exp_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::exp_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void exp2_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::exp2_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::exp2_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void exp10_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::exp10_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::exp10_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void log_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::log_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::log_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void log2_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::log2_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::log2_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void log10_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::log10_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::log10_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void sin_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::sin_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::sin_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void cos_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::cos_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::cos_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void tan_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::tan_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::tan_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void asin_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::asin_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::asin_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void acos_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::acos_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::acos_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void atan_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::atan_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::atan_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void sinh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::sinh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::sinh_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void cosh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::cosh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::cosh_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void tanh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::tanh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::tanh_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void asinh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::asinh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::asinh_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void acosh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::acosh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::acosh_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void atanh_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::atanh_func<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::atanh_func<T>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename T>
inline void hypot_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::hypot_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::hypot_func<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void atan2_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::atan2_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::atan2_func<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T>
inline void magnitude_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::magnitude_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::magnitude_func<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T2>
inline void magnitude_interleaved_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename cv::cudev::magnitude_interleaved_func<T2>::T(cv::cudev::magnitude_interleaved_func<T2>::*)(typename cv::cudev::magnitude_interleaved_func<T2>::parameter_type) const>("call", &cv::cudev::magnitude_interleaved_func<T2>::operator(),
      Arg("ab"));
};

template<typename Data_Type_T, typename T>
inline void magnitude_sqr_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename functional_detail::FloatType<T>::type(cv::cudev::magnitude_sqr_func<T>::*)(typename TypeTraits<T>::parameter_type, typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::magnitude_sqr_func<T>::operator(),
      Arg("a"), Arg("b"));
};

template<typename Data_Type_T, typename T2>
inline void magnitude_sqr_interleaved_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename cv::cudev::magnitude_sqr_interleaved_func<T2>::T(cv::cudev::magnitude_sqr_interleaved_func<T2>::*)(typename cv::cudev::magnitude_sqr_interleaved_func<T2>::parameter_type) const>("call", &cv::cudev::magnitude_sqr_interleaved_func<T2>::operator(),
      Arg("ab"));
};

template<typename Data_Type_T, typename T, bool angleInDegrees>
inline void direction_func_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::direction_func<T, angleInDegrees>::*)(T, T) const>("call", &cv::cudev::direction_func<T, angleInDegrees>::operator(),
      Arg("x"), Arg("y"));
};

template<typename Data_Type_T, typename T2, bool angleInDegrees>
inline void direction_interleaved_func_builder(Data_Type_T& klass)
{
  klass.template define_method<typename cv::cudev::direction_interleaved_func<T2, angleInDegrees>::T(cv::cudev::direction_interleaved_func<T2, angleInDegrees>::*)(T2) const>("call", &cv::cudev::direction_interleaved_func<T2, angleInDegrees>::operator(),
      Arg("xy"));
};

template<typename Data_Type_T, typename T2, bool angleInDegrees>
inline void magnitude_direction_interleaved_func_builder(Data_Type_T& klass)
{
  klass.template define_method<T2(cv::cudev::magnitude_direction_interleaved_func<T2, angleInDegrees>::*)(T2) const>("call", &cv::cudev::magnitude_direction_interleaved_func<T2, angleInDegrees>::operator(),
      Arg("xy"));
};

template<typename Data_Type_T, typename T>
inline void pow_func_builder(Data_Type_T& klass)
{
  klass.template define_method<float(cv::cudev::pow_func<T>::*)(T, float) const>("call", &cv::cudev::pow_func<T>::operator(),
      Arg("val"), Arg("power"));
};

template<typename Data_Type_T, typename T, typename D>
inline void saturate_cast_func_builder(Data_Type_T& klass)
{
  klass.template define_method<D(cv::cudev::saturate_cast_func<T, D>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::saturate_cast_func<T, D>::operator(),
      Arg("v"));
};

template<typename Data_Type_T, typename T>
inline void ThreshBinaryFunc_builder(Data_Type_T& klass)
{
  klass.define_attr("thresh", &cv::cudev::ThreshBinaryFunc<T>::thresh).
    define_attr("max_val", &cv::cudev::ThreshBinaryFunc<T>::maxVal).
    template define_method<T(cv::cudev::ThreshBinaryFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshBinaryFunc<T>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T>
inline void ThreshBinaryInvFunc_builder(Data_Type_T& klass)
{
  klass.define_attr("thresh", &cv::cudev::ThreshBinaryInvFunc<T>::thresh).
    define_attr("max_val", &cv::cudev::ThreshBinaryInvFunc<T>::maxVal).
    template define_method<T(cv::cudev::ThreshBinaryInvFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshBinaryInvFunc<T>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T>
inline void ThreshTruncFunc_builder(Data_Type_T& klass)
{
  klass.define_attr("thresh", &cv::cudev::ThreshTruncFunc<T>::thresh).
    template define_method<T(cv::cudev::ThreshTruncFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshTruncFunc<T>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T>
inline void ThreshToZeroFunc_builder(Data_Type_T& klass)
{
  klass.define_attr("thresh", &cv::cudev::ThreshToZeroFunc<T>::thresh).
    template define_method<T(cv::cudev::ThreshToZeroFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshToZeroFunc<T>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T>
inline void ThreshToZeroInvFunc_builder(Data_Type_T& klass)
{
  klass.define_attr("thresh", &cv::cudev::ThreshToZeroInvFunc<T>::thresh).
    template define_method<T(cv::cudev::ThreshToZeroInvFunc<T>::*)(typename TypeTraits<T>::parameter_type) const>("call", &cv::cudev::ThreshToZeroInvFunc<T>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int cn, int i>
inline void InRangeComparator_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::cudev::InRangeComparator<T, cn, i>::*)(const typename MakeVec<T, cn>::type&, const typename MakeVec<T, cn>::type&, const typename MakeVec<T, cn>::type&) const>("call", &cv::cudev::InRangeComparator<T, cn, i>::operator(),
      Arg("lowerb"), Arg("upperb"), Arg("v"));
};

template<typename Data_Type_T, typename T, int cn, int i>
inline void InRangeCopier_builder(Data_Type_T& klass)
{
  klass.template define_method<void(cv::cudev::InRangeCopier<T, cn, i>::*)(const cv::Scalar&, typename MakeVec<T, cn>::type&) const>("call", &cv::cudev::InRangeCopier<T, cn, i>::operator(),
      Arg("in"), Arg("out"));
};

template<typename Data_Type_T, typename T, int cn>
inline void InRangeFunc_builder(Data_Type_T& klass)
{
  klass.define_attr("lowerb", &cv::cudev::InRangeFunc<T, cn>::lowerb).
    define_attr("upperb", &cv::cudev::InRangeFunc<T, cn>::upperb).
    define_constructor(Constructor<cv::cudev::InRangeFunc<T, cn>, const cv::Scalar&, const cv::Scalar&>(),
      Arg("lowerb_scalar"), Arg("upperb_scalar")).
    template define_method<uchar(cv::cudev::InRangeFunc<T, cn>::*)(const typename MakeVec<T, cn>::type&) const>("call", &cv::cudev::InRangeFunc<T, cn>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename Predicate>
inline void UnaryNegate_builder(Data_Type_T& klass)
{
  klass.define_attr("pred", &cv::cudev::UnaryNegate<Predicate>::pred).
    template define_method<typename Predicate::result_type(cv::cudev::UnaryNegate<Predicate>::*)(typename TypeTraits<typename Predicate::argument_type>::parameter_type) const>("call", &cv::cudev::UnaryNegate<Predicate>::operator(),
      Arg("x"));
};

template<typename Data_Type_T, typename Predicate>
inline void BinaryNegate_builder(Data_Type_T& klass)
{
  klass.define_attr("pred", &cv::cudev::BinaryNegate<Predicate>::pred).
    template define_method<typename Predicate::result_type(cv::cudev::BinaryNegate<Predicate>::*)(typename TypeTraits<typename Predicate::first_argument_type>::parameter_type, typename TypeTraits<typename Predicate::second_argument_type>::parameter_type) const>("call", &cv::cudev::BinaryNegate<Predicate>::operator(),
      Arg("x"), Arg("y"));
};

template<typename Data_Type_T, typename Op>
inline void Binder1st_builder(Data_Type_T& klass)
{
  klass.define_attr("op", &cv::cudev::Binder1st<Op>::op).
    define_attr("arg1", &cv::cudev::Binder1st<Op>::arg1).
    template define_method<typename Op::result_type(cv::cudev::Binder1st<Op>::*)(typename TypeTraits<typename Op::second_argument_type>::parameter_type) const>("call", &cv::cudev::Binder1st<Op>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename Op>
inline void Binder2nd_builder(Data_Type_T& klass)
{
  klass.define_attr("op", &cv::cudev::Binder2nd<Op>::op).
    define_attr("arg2", &cv::cudev::Binder2nd<Op>::arg2).
    template define_method<typename Op::result_type(cv::cudev::Binder2nd<Op>::*)(typename TypeTraits<typename Op::first_argument_type>::parameter_type) const>("call", &cv::cudev::Binder2nd<Op>::operator(),
      Arg("a"));
};

template<typename Data_Type_T, typename F>
inline void IsUnaryFunction_builder(Data_Type_T& klass)
{
  klass.Rice::Data_Type<cv::cudev::IsUnaryFunction::No> rb_cCvCudevIsUnaryFunctionNo = define_class<cv::cudev::IsUnaryFunction::No>("No").
      define_constructor(Constructor<cv::cudev::IsUnaryFunction<F>::No>()).
      define_attr("a", &cv::cudev::IsUnaryFunction<F>::No::a, Rice::AttrAccess::Read);.
    define_constant("Value", (int)cv::cudev::IsUnaryFunction<F>::value).
    template define_singleton_function<F(*)()>("make_f", &cv::cudev::IsUnaryFunction<F>::makeF);
};

template<typename Data_Type_T, typename F>
inline void IsBinaryFunction_builder(Data_Type_T& klass)
{
  klass.Rice::Data_Type<cv::cudev::IsBinaryFunction::No> rb_cCvCudevIsBinaryFunctionNo = define_class<cv::cudev::IsBinaryFunction::No>("No").
      define_constructor(Constructor<cv::cudev::IsBinaryFunction<F>::No>()).
      define_attr("a", &cv::cudev::IsBinaryFunction<F>::No::a, Rice::AttrAccess::Read);.
    define_constant("Value", (int)cv::cudev::IsBinaryFunction<F>::value).
    template define_singleton_function<F(*)()>("make_f", &cv::cudev::IsBinaryFunction<F>::makeF);
};

