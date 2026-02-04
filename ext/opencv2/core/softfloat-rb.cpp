#include <opencv2/core/softfloat.hpp>
#include "softfloat-rb.hpp"

using namespace Rice;

void Init_Core_Softfloat()
{
  Class(rb_cObject).define_constant("Softfloat_h", softfloat_h);

  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::softfloat> rb_cCvSoftfloat = define_class_under<cv::softfloat>(rb_mCv, "Softfloat").
    define_constructor(Constructor<cv::softfloat>()).
    define_constructor(Constructor<cv::softfloat, const cv::softfloat&>(),
      Arg("c")).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("assign", &cv::softfloat::operator=,
      Arg("c")).
    define_singleton_function<const cv::softfloat(*)(const uint32_t)>("from_raw", &cv::softfloat::fromRaw,
      Arg("a")).
    define_constructor(Constructor<cv::softfloat, const uint32_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::softfloat, const uint64_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::softfloat, const int32_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::softfloat, const int64_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::softfloat, const float>(),
      Arg("a")).
    define_method("to_softdouble", [](const cv::softfloat& self) -> cv::softdouble
    {
      return self;
    }).
    define_method("to_f32", [](const cv::softfloat& self) -> float
    {
      return self;
    }).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("+", &cv::softfloat::operator+,
      Arg("arg_0")).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("-", &cv::softfloat::operator-,
      Arg("arg_0")).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("*", &cv::softfloat::operator*,
      Arg("arg_0")).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("/", &cv::softfloat::operator/,
      Arg("arg_0")).
    define_method<cv::softfloat(cv::softfloat::*)() const>("-@", &cv::softfloat::operator-).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("%", &cv::softfloat::operator%,
      Arg("arg_0")).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("assign_plus", &cv::softfloat::operator+=,
      Arg("a")).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("assign_minus", &cv::softfloat::operator-=,
      Arg("a")).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("assign_multiply", &cv::softfloat::operator*=,
      Arg("a")).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("assign_divide", &cv::softfloat::operator/=,
      Arg("a")).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("assign_modulus", &cv::softfloat::operator%=,
      Arg("a")).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("==", &cv::softfloat::operator==,
      Arg("arg_0")).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("!=", &cv::softfloat::operator!=,
      Arg("arg_0")).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>(">", &cv::softfloat::operator>,
      Arg("arg_0")).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>(">=", &cv::softfloat::operator>=,
      Arg("arg_0")).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("<", &cv::softfloat::operator<,
      Arg("arg_0")).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("<=", &cv::softfloat::operator<=,
      Arg("arg_0")).
    define_method<bool(cv::softfloat::*)() const>("na_n?", &cv::softfloat::isNaN).
    define_method<bool(cv::softfloat::*)() const>("inf?", &cv::softfloat::isInf).
    define_method<bool(cv::softfloat::*)() const>("subnormal?", &cv::softfloat::isSubnormal).
    define_method<bool(cv::softfloat::*)() const>("get_sign?", &cv::softfloat::getSign).
    define_method<cv::softfloat(cv::softfloat::*)(bool) const>("set_sign", &cv::softfloat::setSign,
      Arg("sign")).
    define_method<int(cv::softfloat::*)() const>("get_exp", &cv::softfloat::getExp).
    define_method<cv::softfloat(cv::softfloat::*)(int) const>("set_exp", &cv::softfloat::setExp,
      Arg("e")).
    define_method<cv::softfloat(cv::softfloat::*)() const>("get_frac", &cv::softfloat::getFrac).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("set_frac", &cv::softfloat::setFrac,
      Arg("s")).
    define_singleton_function<cv::softfloat(*)()>("zero", &cv::softfloat::zero).
    define_singleton_function<cv::softfloat(*)()>("inf", &cv::softfloat::inf).
    define_singleton_function<cv::softfloat(*)()>("nan", &cv::softfloat::nan).
    define_singleton_function<cv::softfloat(*)()>("one", &cv::softfloat::one).
    define_singleton_function<cv::softfloat(*)()>("min", &cv::softfloat::min).
    define_singleton_function<cv::softfloat(*)()>("eps", &cv::softfloat::eps).
    define_singleton_function<cv::softfloat(*)()>("max", &cv::softfloat::max).
    define_singleton_function<cv::softfloat(*)()>("pi", &cv::softfloat::pi).
    define_attr("v", &cv::softfloat::v);

  Rice::Data_Type<cv::softdouble> rb_cCvSoftdouble = define_class_under<cv::softdouble>(rb_mCv, "Softdouble").
    define_constructor(Constructor<cv::softdouble>()).
    define_constructor(Constructor<cv::softdouble, const cv::softdouble&>(),
      Arg("c")).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("assign", &cv::softdouble::operator=,
      Arg("c")).
    define_singleton_function<cv::softdouble(*)(const uint64_t)>("from_raw", &cv::softdouble::fromRaw,
      Arg("a")).
    define_constructor(Constructor<cv::softdouble, const uint32_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::softdouble, const uint64_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::softdouble, const int32_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::softdouble, const int64_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::softdouble, const double>(),
      Arg("a")).
    define_method("to_softfloat", [](const cv::softdouble& self) -> cv::softfloat
    {
      return self;
    }).
    define_method("to_f", [](const cv::softdouble& self) -> double
    {
      return self;
    }).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("+", &cv::softdouble::operator+,
      Arg("arg_0")).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("-", &cv::softdouble::operator-,
      Arg("arg_0")).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("*", &cv::softdouble::operator*,
      Arg("arg_0")).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("/", &cv::softdouble::operator/,
      Arg("arg_0")).
    define_method<cv::softdouble(cv::softdouble::*)() const>("-@", &cv::softdouble::operator-).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("%", &cv::softdouble::operator%,
      Arg("arg_0")).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("assign_plus", &cv::softdouble::operator+=,
      Arg("a")).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("assign_minus", &cv::softdouble::operator-=,
      Arg("a")).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("assign_multiply", &cv::softdouble::operator*=,
      Arg("a")).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("assign_divide", &cv::softdouble::operator/=,
      Arg("a")).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("assign_modulus", &cv::softdouble::operator%=,
      Arg("a")).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("==", &cv::softdouble::operator==,
      Arg("arg_0")).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("!=", &cv::softdouble::operator!=,
      Arg("arg_0")).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>(">", &cv::softdouble::operator>,
      Arg("arg_0")).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>(">=", &cv::softdouble::operator>=,
      Arg("arg_0")).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("<", &cv::softdouble::operator<,
      Arg("arg_0")).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("<=", &cv::softdouble::operator<=,
      Arg("arg_0")).
    define_method<bool(cv::softdouble::*)() const>("na_n?", &cv::softdouble::isNaN).
    define_method<bool(cv::softdouble::*)() const>("inf?", &cv::softdouble::isInf).
    define_method<bool(cv::softdouble::*)() const>("subnormal?", &cv::softdouble::isSubnormal).
    define_method<bool(cv::softdouble::*)() const>("get_sign?", &cv::softdouble::getSign).
    define_method<cv::softdouble(cv::softdouble::*)(bool) const>("set_sign", &cv::softdouble::setSign,
      Arg("sign")).
    define_method<int(cv::softdouble::*)() const>("get_exp", &cv::softdouble::getExp).
    define_method<cv::softdouble(cv::softdouble::*)(int) const>("set_exp", &cv::softdouble::setExp,
      Arg("e")).
    define_method<cv::softdouble(cv::softdouble::*)() const>("get_frac", &cv::softdouble::getFrac).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("set_frac", &cv::softdouble::setFrac,
      Arg("s")).
    define_singleton_function<cv::softdouble(*)()>("zero", &cv::softdouble::zero).
    define_singleton_function<cv::softdouble(*)()>("inf", &cv::softdouble::inf).
    define_singleton_function<cv::softdouble(*)()>("nan", &cv::softdouble::nan).
    define_singleton_function<cv::softdouble(*)()>("one", &cv::softdouble::one).
    define_singleton_function<cv::softdouble(*)()>("min", &cv::softdouble::min).
    define_singleton_function<cv::softdouble(*)()>("eps", &cv::softdouble::eps).
    define_singleton_function<cv::softdouble(*)()>("max", &cv::softdouble::max).
    define_singleton_function<cv::softdouble(*)()>("pi", &cv::softdouble::pi).
    define_attr("v", &cv::softdouble::v);

  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&, const cv::softfloat&, const cv::softfloat&)>("mul_add", &cv::mulAdd,
    Arg("a"), Arg("b"), Arg("c"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&, const cv::softdouble&, const cv::softdouble&)>("mul_add", &cv::mulAdd,
    Arg("a"), Arg("b"), Arg("c"));

  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&)>("sqrt", &cv::sqrt,
    Arg("a"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("sqrt", &cv::sqrt,
    Arg("a"));

  define_global_function<int(*)(const cv::softfloat&)>("cv_trunc", &cvTrunc,
    Arg("a"));

  define_global_function<int(*)(const cv::softdouble&)>("cv_trunc", &cvTrunc,
    Arg("a"));

  define_global_function<int(*)(const cv::softfloat&)>("cv_round", &cvRound,
    Arg("a"));

  define_global_function<int(*)(const cv::softdouble&)>("cv_round", &cvRound,
    Arg("a"));

  define_global_function<int64_t(*)(const cv::softdouble&)>("cv_round64", &cvRound64,
    Arg("a"));

  define_global_function<int(*)(const cv::softfloat&)>("cv_floor", &cvFloor,
    Arg("a"));

  define_global_function<int(*)(const cv::softdouble&)>("cv_floor", &cvFloor,
    Arg("a"));

  define_global_function<int(*)(const cv::softfloat&)>("cv_ceil", &cvCeil,
    Arg("a"));

  define_global_function<int(*)(const cv::softdouble&)>("cv_ceil", &cvCeil,
    Arg("a"));

  rb_mCv.define_module_function<uchar(*)(cv::softfloat)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<uchar(*)(cv::softdouble)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<schar(*)(cv::softfloat)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<schar(*)(cv::softdouble)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<ushort(*)(cv::softfloat)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<ushort(*)(cv::softdouble)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<short(*)(cv::softfloat)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<short(*)(cv::softdouble)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<int(*)(cv::softfloat)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<int(*)(cv::softdouble)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<int64_t(*)(cv::softfloat)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<int64_t(*)(cv::softdouble)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<unsigned int(*)(cv::softfloat)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<unsigned int(*)(cv::softdouble)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<uint64_t(*)(cv::softfloat)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<uint64_t(*)(cv::softdouble)>("saturate_cast", &cv::saturate_cast,
    Arg("a"));

  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&, const cv::softfloat&)>("min", &cv::min,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&, const cv::softdouble&)>("min", &cv::min,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&, const cv::softfloat&)>("max", &cv::max,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&, const cv::softdouble&)>("max", &cv::max,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<cv::softfloat(*)(cv::softfloat)>("abs", &cv::abs,
    Arg("a"));

  rb_mCv.define_module_function<cv::softdouble(*)(cv::softdouble)>("abs", &cv::abs,
    Arg("a"));

  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&)>("exp", &cv::exp,
    Arg("a"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("exp", &cv::exp,
    Arg("a"));

  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&)>("log", &cv::log,
    Arg("a"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("log", &cv::log,
    Arg("a"));

  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&, const cv::softfloat&)>("pow", &cv::pow,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&, const cv::softdouble&)>("pow", &cv::pow,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&)>("cbrt", &cv::cbrt,
    Arg("a"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("sin", &cv::sin,
    Arg("a"));

  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("cos", &cv::cos,
    Arg("a"));
}