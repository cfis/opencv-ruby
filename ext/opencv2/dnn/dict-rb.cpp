#include <opencv2/dnn/dict.hpp>
#include "dict-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDnnDnn4V20241223Dict;
Rice::Class rb_cCvDnnDnn4V20241223DictValue;

void Init_Dict()
{
  Module rb_mCv = define_module("Cv");
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  
  Module rb_mCvDnnDnn4V20241223 = define_module_under(rb_mCvDnn, "Dnn4V20241223");
  
  rb_cCvDnnDnn4V20241223DictValue = define_class_under<cv::dnn::dnn4_v20241223::DictValue>(rb_mCvDnnDnn4V20241223, "DictValue").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DictValue, const cv::dnn::dnn4_v20241223::DictValue&>(),
      Arg("r")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DictValue, bool>(),
      Arg("i")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DictValue, int64>(),
      Arg("i") = static_cast<int64>(0)).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DictValue, int>(),
      Arg("i")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DictValue, unsigned int>(),
      Arg("p")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DictValue, double>(),
      Arg("p")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DictValue, const cv::String&>(),
      Arg("s")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DictValue, const char*>(),
      Arg("s")).
    define_method("size", &cv::dnn::dnn4_v20241223::DictValue::size).
    define_method("int?", &cv::dnn::dnn4_v20241223::DictValue::isInt).
    define_method("string?", &cv::dnn::dnn4_v20241223::DictValue::isString).
    define_method("real?", &cv::dnn::dnn4_v20241223::DictValue::isReal).
    define_method("get_int_value", &cv::dnn::dnn4_v20241223::DictValue::getIntValue,
      Arg("idx") = static_cast<int>(-1)).
    define_method("get_real_value", &cv::dnn::dnn4_v20241223::DictValue::getRealValue,
      Arg("idx") = static_cast<int>(-1)).
    define_method("get_string_value", &cv::dnn::dnn4_v20241223::DictValue::getStringValue,
      Arg("idx") = static_cast<int>(-1)).
    define_method("assign", &cv::dnn::dnn4_v20241223::DictValue::operator=,
      Arg("r"));
  
  rb_cCvDnnDnn4V20241223Dict = define_class_under<cv::dnn::dnn4_v20241223::Dict>(rb_mCvDnnDnn4V20241223, "Dict").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Dict>()).
    define_method("has?", &cv::dnn::dnn4_v20241223::Dict::has,
      Arg("key")).
    define_method<cv::dnn::dnn4_v20241223::DictValue*(cv::dnn::dnn4_v20241223::Dict::*)(const cv::String&)>("ptr", &cv::dnn::dnn4_v20241223::Dict::ptr,
      Arg("key")).
    define_method<const cv::dnn::dnn4_v20241223::DictValue*(cv::dnn::dnn4_v20241223::Dict::*)(const cv::String&) const>("ptr", &cv::dnn::dnn4_v20241223::Dict::ptr,
      Arg("key")).
  //  define_method("get", &cv::dnn::dnn4_v20241223::Dict::get,
   //   Arg("key")).
    define_method("erase", &cv::dnn::dnn4_v20241223::Dict::erase,
      Arg("key"));
  //  define_iterator<std::map::const_iterator(cv::dnn::dnn4_v20241223::Dict::*)() const>(&cv::dnn::dnn4_v20241223::Dict::begin, &cv::dnn::dnn4_v20241223::Dict::end, "each_const");
}