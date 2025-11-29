#include <opencv2/opencv.hpp>
#include <opencv2/core/softfloat.hpp>
#include "softfloat-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvSoftdouble;
Rice::Class rb_cCvSoftfloat;

void Init_Softfloat()
{
  Class(rb_cObject).define_constant("Softfloat_h", softfloat_h);
  
  Module rb_mCv = define_module("Cv");
  
  rb_cCvSoftfloat = define_class_under<cv::softfloat>(rb_mCv, "Softfloat").
    define_constructor(Constructor<cv::softfloat>()).
    define_constructor(Constructor<cv::softfloat, const cv::softfloat&>(),
      Arg("c")).
    define_method("assign", &cv::softfloat::operator=,
      Arg("c")).
    define_singleton_function("from_raw", &cv::softfloat::fromRaw,
      Arg("a")).
    define_constructor(Constructor<cv::softfloat, const uint32_t>(),
      Arg("")).
    define_constructor(Constructor<cv::softfloat, const uint64_t>(),
      Arg("")).
    define_constructor(Constructor<cv::softfloat, const int32_t>(),
      Arg("")).
    define_constructor(Constructor<cv::softfloat, const int64_t>(),
      Arg("")).
    define_constructor(Constructor<cv::softfloat, const float>(),
      Arg("a")).
    define_method("to_softdouble", [](const cv::softfloat& self) -> cv::softdouble
    {
      return self;
    }).
    define_method("to_float", [](const cv::softfloat& self) -> float
    {
      return self;
    }).
    define_method("+", &cv::softfloat::operator+,
      Arg("")).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("-", &cv::softfloat::operator-,
      Arg("")).
    define_method("dereference", &cv::softfloat::operator*,
      Arg("")).
    define_method("/", &cv::softfloat::operator/,
      Arg("")).
    define_method<cv::softfloat(cv::softfloat::*)() const>("-", &cv::softfloat::operator-).
    define_method("%", &cv::softfloat::operator%,
      Arg("")).
    define_method("assign_plus", &cv::softfloat::operator+=,
      Arg("a")).
    define_method("assign_minus", &cv::softfloat::operator-=,
      Arg("a")).
    define_method("assign_multiply", &cv::softfloat::operator*=,
      Arg("a")).
    define_method("assign_divide", &cv::softfloat::operator/=,
      Arg("a")).
    define_method("assign_modulus", &cv::softfloat::operator%=,
      Arg("a")).
    define_method("==", &cv::softfloat::operator==,
      Arg("")).
    define_method("!=", &cv::softfloat::operator!=,
      Arg("")).
    define_method(">", &cv::softfloat::operator>,
      Arg("")).
    define_method(">=", &cv::softfloat::operator>=,
      Arg("")).
    define_method("<", &cv::softfloat::operator<,
      Arg("")).
    define_method("<=", &cv::softfloat::operator<=,
      Arg("")).
    define_method("na_n?", &cv::softfloat::isNaN).
    define_method("inf?", &cv::softfloat::isInf).
    define_method("subnormal?", &cv::softfloat::isSubnormal).
    define_method("get_sign?", &cv::softfloat::getSign).
    define_method("set_sign", &cv::softfloat::setSign,
      Arg("sign")).
    define_method("get_exp", &cv::softfloat::getExp).
    define_method("set_exp", &cv::softfloat::setExp,
      Arg("e")).
    define_method("get_frac", &cv::softfloat::getFrac).
    define_method("set_frac", &cv::softfloat::setFrac,
      Arg("s")).
    define_singleton_function("zero", &cv::softfloat::zero).
    define_singleton_function("inf", &cv::softfloat::inf).
    define_singleton_function("nan", &cv::softfloat::nan).
    define_singleton_function("one", &cv::softfloat::one).
    define_singleton_function("min", &cv::softfloat::min).
    define_singleton_function("eps", &cv::softfloat::eps).
    define_singleton_function("max", &cv::softfloat::max).
    define_singleton_function("pi", &cv::softfloat::pi).
    define_attr("v", &cv::softfloat::v);
  
  rb_cCvSoftdouble = define_class_under<cv::softdouble>(rb_mCv, "Softdouble").
    define_constructor(Constructor<cv::softdouble>()).
    define_constructor(Constructor<cv::softdouble, const cv::softdouble&>(),
      Arg("c")).
    define_method("assign", &cv::softdouble::operator=,
      Arg("c")).
    define_singleton_function("from_raw", &cv::softdouble::fromRaw,
      Arg("a")).
    define_constructor(Constructor<cv::softdouble, const uint32_t>(),
      Arg("")).
    define_constructor(Constructor<cv::softdouble, const uint64_t>(),
      Arg("")).
    define_constructor(Constructor<cv::softdouble, const int32_t>(),
      Arg("")).
    define_constructor(Constructor<cv::softdouble, const int64_t>(),
      Arg("")).
    define_constructor(Constructor<cv::softdouble, const double>(),
      Arg("a")).
    define_method("to_softfloat", [](const cv::softdouble& self) -> cv::softfloat
    {
      return self;
    }).
    define_method("to_double", [](const cv::softdouble& self) -> double
    {
      return self;
    }).
    define_method("+", &cv::softdouble::operator+,
      Arg("")).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("-", &cv::softdouble::operator-,
      Arg("")).
    define_method("dereference", &cv::softdouble::operator*,
      Arg("")).
    define_method("/", &cv::softdouble::operator/,
      Arg("")).
    define_method<cv::softdouble(cv::softdouble::*)() const>("-", &cv::softdouble::operator-).
    define_method("%", &cv::softdouble::operator%,
      Arg("")).
    define_method("assign_plus", &cv::softdouble::operator+=,
      Arg("a")).
    define_method("assign_minus", &cv::softdouble::operator-=,
      Arg("a")).
    define_method("assign_multiply", &cv::softdouble::operator*=,
      Arg("a")).
    define_method("assign_divide", &cv::softdouble::operator/=,
      Arg("a")).
    define_method("assign_modulus", &cv::softdouble::operator%=,
      Arg("a")).
    define_method("==", &cv::softdouble::operator==,
      Arg("")).
    define_method("!=", &cv::softdouble::operator!=,
      Arg("")).
    define_method(">", &cv::softdouble::operator>,
      Arg("")).
    define_method(">=", &cv::softdouble::operator>=,
      Arg("")).
    define_method("<", &cv::softdouble::operator<,
      Arg("")).
    define_method("<=", &cv::softdouble::operator<=,
      Arg("")).
    define_method("na_n?", &cv::softdouble::isNaN).
    define_method("inf?", &cv::softdouble::isInf).
    define_method("subnormal?", &cv::softdouble::isSubnormal).
    define_method("get_sign?", &cv::softdouble::getSign).
    define_method("set_sign", &cv::softdouble::setSign,
      Arg("sign")).
    define_method("get_exp", &cv::softdouble::getExp).
    define_method("set_exp", &cv::softdouble::setExp,
      Arg("e")).
    define_method("get_frac", &cv::softdouble::getFrac).
    define_method("set_frac", &cv::softdouble::setFrac,
      Arg("s")).
    define_singleton_function("zero", &cv::softdouble::zero).
    define_singleton_function("inf", &cv::softdouble::inf).
    define_singleton_function("nan", &cv::softdouble::nan).
    define_singleton_function("one", &cv::softdouble::one).
    define_singleton_function("min", &cv::softdouble::min).
    define_singleton_function("eps", &cv::softdouble::eps).
    define_singleton_function("max", &cv::softdouble::max).
    define_singleton_function("pi", &cv::softdouble::pi).
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
  
  define_global_function("cv_round64", &cvRound64,
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
  
  rb_mCv.define_module_function("cbrt", &cv::cbrt,
    Arg("a"));
  
  rb_mCv.define_module_function("sin", &cv::sin,
    Arg("a"));
  
  rb_mCv.define_module_function("cos", &cv::cos,
    Arg("a"));

}