#include <opencv2/core/cvstd.hpp>
#include "cvstd-rb.hpp"

using namespace Rice;

#include "cvstd-rb.ipp"

void Init_Core_Cvstd()
{
  Module rb_mCv = define_module("Cv");

  rb_mCv.define_module_function<uchar(*)(uchar)>("abs", &cv::abs,
    Arg("a"));

  rb_mCv.define_module_function<ushort(*)(ushort)>("abs", &cv::abs,
    Arg("a"));

  rb_mCv.define_module_function<unsigned int(*)(unsigned int)>("abs", &cv::abs,
    Arg("a"));

  rb_mCv.define_module_function<uint64(*)(uint64)>("abs", &cv::abs,
    Arg("a"));

  rb_mCv.define_module_function<void*(*)(size_t)>("fast_malloc", &cv::fastMalloc,
    Arg("buf_size"), ReturnBuffer());

  rb_mCv.define_module_function<void(*)(void*)>("fast_free", &cv::fastFree,
    ArgBuffer("ptr"));

  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");

  rb_mCvDetails.define_module_function<char(*)(char)>("char_tolower", &cv::details::char_tolower,
    Arg("ch"));

  rb_mCvDetails.define_module_function<char(*)(char)>("char_toupper", &cv::details::char_toupper,
    Arg("ch"));

  rb_mCv.define_module_function<std::string(*)(const std::string&)>("to_lower_case", &cv::toLowerCase,
    Arg("str"));

  rb_mCv.define_module_function<std::string(*)(const std::string&)>("to_upper_case", &cv::toUpperCase,
    Arg("str"));
}