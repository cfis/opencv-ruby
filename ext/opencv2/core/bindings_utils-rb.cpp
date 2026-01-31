#include <opencv2/core/bindings_utils.hpp>
#include "bindings_utils-rb.hpp"

using namespace Rice;

void Init_Core_BindingsUtils()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");

  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputArray)>("dump_input_array", &cv::utils::dumpInputArray,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputArrayOfArrays)>("dump_input_array_of_arrays", &cv::utils::dumpInputArrayOfArrays,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputOutputArray)>("dump_input_output_array", &cv::utils::dumpInputOutputArray,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputOutputArrayOfArrays)>("dump_input_output_array_of_arrays", &cv::utils::dumpInputOutputArrayOfArrays,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(bool)>("dump_bool", &cv::utils::dumpBool,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(int)>("dump_int", &cv::utils::dumpInt,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(int64)>("dump_int64", &cv::utils::dumpInt64,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(size_t)>("dump_size_t", &cv::utils::dumpSizeT,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(float)>("dump_float", &cv::utils::dumpFloat,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(double)>("dump_double", &cv::utils::dumpDouble,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(const char*)>("dump_c_string", &cv::utils::dumpCString,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(const cv::String&)>("dump_string", &cv::utils::dumpString,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(const cv::Rect&)>("dump_rect", &cv::utils::dumpRect,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(const cv::TermCriteria&)>("dump_term_criteria", &cv::utils::dumpTermCriteria,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(const cv::RotatedRect&)>("dump_rotated_rect", &cv::utils::dumpRotatedRect,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(const cv::Range&)>("dump_range", &cv::utils::dumpRange,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(const std::vector<int>&)>("dump_vector_of_int", &cv::utils::dumpVectorOfInt,
    Arg("vec"));

  rb_mCvUtils.define_module_function<cv::String(*)(const std::vector<double>&)>("dump_vector_of_double", &cv::utils::dumpVectorOfDouble,
    Arg("vec"));

  rb_mCvUtils.define_module_function<cv::String(*)(const std::vector<cv::Rect_<int>>&)>("dump_vector_of_rect", &cv::utils::dumpVectorOfRect,
    Arg("vec"));

  rb_mCvUtils.define_module_function<cv::String(*)(int, const cv::Point&)>("test_overload_resolution", &cv::utils::testOverloadResolution,
    Arg("value"), Arg("point") = static_cast<const cv::Point&>(cv::Point(42, 24)));

  rb_mCvUtils.define_module_function<cv::String(*)(const cv::Rect&)>("test_overload_resolution", &cv::utils::testOverloadResolution,
    Arg("rect"));

  rb_mCvUtils.define_module_function<cv::RotatedRect(*)(float, float, float, float, float)>("test_rotated_rect", &cv::utils::testRotatedRect,
    Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("angle"));

  rb_mCvUtils.define_module_function<std::vector<cv::RotatedRect>(*)(float, float, float, float, float)>("test_rotated_rect_vector", &cv::utils::testRotatedRectVector,
    Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("angle"));

  rb_mCvUtils.define_module_function<int(*)(int)>("test_overwrite_native_method", &cv::utils::testOverwriteNativeMethod,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::String(*)(int, int, int)>("test_reserved_keyword_conversion", &cv::utils::testReservedKeywordConversion,
    Arg("positional_argument"), Arg("lambda") = static_cast<int>(2), Arg("from") = static_cast<int>(3));

  rb_mCvUtils.define_module_function<void(*)(size_t, std::vector<cv::Rect_<int>>&)>("generate_vector_of_rect", &cv::utils::generateVectorOfRect,
    Arg("len"), Arg("vec"));

  rb_mCvUtils.define_module_function<void(*)(size_t, std::vector<int>&)>("generate_vector_of_int", &cv::utils::generateVectorOfInt,
    Arg("len"), Arg("vec"));

  rb_mCvUtils.define_module_function<void(*)(size_t, int, int, int, std::vector<cv::Mat>&)>("generate_vector_of_mat", &cv::utils::generateVectorOfMat,
    Arg("len"), Arg("rows"), Arg("cols"), Arg("dtype"), Arg("vec"));

  rb_mCvUtils.define_module_function<void(*)()>("test_raise_general_exception", &cv::utils::testRaiseGeneralException);

  rb_mCvUtils.define_module_function<cv::AsyncArray(*)(cv::InputArray)>("test_async_array", &cv::utils::testAsyncArray,
    Arg("argument"));

  rb_mCvUtils.define_module_function<cv::AsyncArray(*)()>("test_async_exception", &cv::utils::testAsyncException);

  rb_mCvUtils.define_module_function<cv::String(*)(const cv::Vec2i)>("dump_vec2i", &cv::utils::dumpVec2i,
    Arg("value") = static_cast<const cv::Vec2i>(cv::Vec2i(42, 24)));

  Rice::Data_Type<cv::utils::ClassWithKeywordProperties> rb_cCvUtilsClassWithKeywordProperties = define_class_under<cv::utils::ClassWithKeywordProperties>(rb_mCvUtils, "ClassWithKeywordProperties").
    define_attr("lambda", &cv::utils::ClassWithKeywordProperties::lambda).
    define_attr("except", &cv::utils::ClassWithKeywordProperties::except).
    define_constructor(Constructor<cv::utils::ClassWithKeywordProperties, int, int>(),
      Arg("lambda_arg") = static_cast<int>(24), Arg("except_arg") = static_cast<int>(42));

  Rice::Data_Type<cv::utils::FunctionParams> rb_cCvUtilsFunctionParams = define_class_under<cv::utils::FunctionParams>(rb_mCvUtils, "FunctionParams").
    define_constructor(Constructor<cv::utils::FunctionParams>()).
    define_attr("lambda", &cv::utils::FunctionParams::lambda).
    define_attr("sigma", &cv::utils::FunctionParams::sigma).
    define_method<cv::utils::FunctionParams&(cv::utils::FunctionParams::*)(int) noexcept>("set_lambda", &cv::utils::FunctionParams::setLambda,
      Arg("value")).
    define_method<cv::utils::FunctionParams&(cv::utils::FunctionParams::*)(float) noexcept>("set_sigma", &cv::utils::FunctionParams::setSigma,
      Arg("value"));

  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputArray, cv::OutputArray, const cv::utils::FunctionParams&)>("copy_mat_and_dump_named_arguments", &cv::utils::copyMatAndDumpNamedArguments,
    Arg("src"), Arg("dst"), Arg("params") = static_cast<const cv::utils::FunctionParams&>(cv::utils::FunctionParams()));

  Module rb_mCvUtilsNested = define_module_under(rb_mCvUtils, "Nested");

  rb_mCvUtilsNested.define_module_function<bool(*)(bool)>("test_echo_boolean_function", &cv::utils::nested::testEchoBooleanFunction,
    Arg("flag"));

  Rice::Data_Type<cv::utils::nested::OriginalClassName> rb_cCvUtilsNestedOriginalClassName = define_class_under<cv::utils::nested::OriginalClassName>(rb_mCvUtilsNested, "OriginalClassName").
    define_constructor(Constructor<cv::utils::nested::OriginalClassName, const cv::utils::nested::OriginalClassName::Params&>(),
      Arg("params") = static_cast<const cv::utils::nested::OriginalClassName::Params&>(cv::utils::nested::OriginalClassName::Params())).
    define_method<int(cv::utils::nested::OriginalClassName::*)() const>("get_int_param", &cv::utils::nested::OriginalClassName::getIntParam).
    define_method<float(cv::utils::nested::OriginalClassName::*)() const>("get_float_param", &cv::utils::nested::OriginalClassName::getFloatParam).
    define_singleton_function<std::string(*)()>("original_name", &cv::utils::nested::OriginalClassName::originalName).
    define_singleton_function<cv::Ptr<cv::utils::nested::OriginalClassName>(*)(const cv::utils::nested::OriginalClassName::Params&)>("create", &cv::utils::nested::OriginalClassName::create,
      Arg("params") = static_cast<const cv::utils::nested::OriginalClassName::Params&>(cv::utils::nested::OriginalClassName::Params()));

  Rice::Data_Type<cv::utils::nested::OriginalClassName::Params> rb_cCvUtilsNestedOriginalClassNameParams = define_class_under<cv::utils::nested::OriginalClassName::Params>(rb_cCvUtilsNestedOriginalClassName, "Params").
    define_attr("int_value", &cv::utils::nested::OriginalClassName::Params::int_value).
    define_attr("float_value", &cv::utils::nested::OriginalClassName::Params::float_value).
    define_constructor(Constructor<cv::utils::nested::OriginalClassName::Params, int, float>(),
      Arg("int_param") = static_cast<int>(123), Arg("float_param") = static_cast<float>(3.5f));

  Module rb_mCvUtilsFs = define_module_under(rb_mCvUtils, "Fs");

  rb_mCvUtilsFs.define_module_function<cv::String(*)()>("get_cache_directory_for_downloads", &cv::utils::fs::getCacheDirectoryForDownloads);

  rb_mCv.define_module_function<int(*)(int)>("set_log_level", &cv::setLogLevel,
    Arg("level"));

  rb_mCv.define_module_function<int(*)()>("get_log_level", &cv::getLogLevel);
}