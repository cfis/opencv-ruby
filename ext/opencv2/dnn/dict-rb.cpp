#include <opencv2/dnn/dict.hpp>
#include "dict-rb.hpp"

using namespace Rice;

void Init_Dnn_Dict()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Rice::Data_Type<cv::dnn::DictValue> rb_cCvDnnDictValue = define_class_under<cv::dnn::DictValue>(rb_mCvDnn, "DictValue").
    define_constructor(Constructor<cv::dnn::DictValue, const cv::dnn::DictValue&>(),
      Arg("r")).
    define_constructor(Constructor<cv::dnn::DictValue, bool>(),
      Arg("i")).
    define_constructor(Constructor<cv::dnn::DictValue, int64>(),
      Arg("i") = static_cast<int64>(0)).
    define_constructor(Constructor<cv::dnn::DictValue, int>(),
      Arg("i")).
    define_constructor(Constructor<cv::dnn::DictValue, unsigned int>(),
      Arg("p")).
    define_constructor(Constructor<cv::dnn::DictValue, double>(),
      Arg("p")).
    define_constructor(Constructor<cv::dnn::DictValue, const cv::String&>(),
      Arg("s")).
    define_constructor(Constructor<cv::dnn::DictValue, const char*>(),
      Arg("s")).
    define_method<int(cv::dnn::DictValue::*)() const>("size", &cv::dnn::DictValue::size).
    define_method<bool(cv::dnn::DictValue::*)() const>("int?", &cv::dnn::DictValue::isInt).
    define_method<bool(cv::dnn::DictValue::*)() const>("string?", &cv::dnn::DictValue::isString).
    define_method<bool(cv::dnn::DictValue::*)() const>("real?", &cv::dnn::DictValue::isReal).
    define_method<int(cv::dnn::DictValue::*)(int) const>("get_int_value", &cv::dnn::DictValue::getIntValue,
      Arg("idx") = static_cast<int>(-1)).
    define_method<double(cv::dnn::DictValue::*)(int) const>("get_real_value", &cv::dnn::DictValue::getRealValue,
      Arg("idx") = static_cast<int>(-1)).
    define_method<cv::String(cv::dnn::DictValue::*)(int) const>("get_string_value", &cv::dnn::DictValue::getStringValue,
      Arg("idx") = static_cast<int>(-1)).
    define_method<cv::dnn::DictValue&(cv::dnn::DictValue::*)(const cv::dnn::DictValue&)>("assign", &cv::dnn::DictValue::operator=,
      Arg("r"));

  Rice::Data_Type<cv::dnn::Dict> rb_cCvDnnDict = define_class_under<cv::dnn::Dict>(rb_mCvDnn, "Dict").
    define_constructor(Constructor<cv::dnn::Dict>()).
    define_method<bool(cv::dnn::Dict::*)(const cv::String&) const>("has", &cv::dnn::Dict::has,
      Arg("key")).
    define_method<cv::dnn::DictValue*(cv::dnn::Dict::*)(const cv::String&)>("ptr", &cv::dnn::Dict::ptr,
      Arg("key")).
    define_method<const cv::dnn::DictValue*(cv::dnn::Dict::*)(const cv::String&) const>("ptr", &cv::dnn::Dict::ptr,
      Arg("key")).
    define_method<const cv::dnn::DictValue&(cv::dnn::Dict::*)(const cv::String&) const>("get", &cv::dnn::Dict::get,
      Arg("key")).
    define_method<void(cv::dnn::Dict::*)(const cv::String&)>("erase", &cv::dnn::Dict::erase,
      Arg("key")).
    define_iterator<std::map<cv::String, cv::dnn::DictValue>::const_iterator(cv::dnn::Dict::*)() const>(&cv::dnn::Dict::begin, &cv::dnn::Dict::end, "each_const");
}