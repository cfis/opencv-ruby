#include <opencv2/core/saturate.hpp>
#include "saturate-rb.hpp"

using namespace Rice;

void Init_Core_Saturate()
{
  Module rb_mCv = define_module("Cv");

  rb_mCv.define_module_function<uchar(*)(schar)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uchar(*)(ushort)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uchar(*)(int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uchar(*)(short)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uchar(*)(unsigned int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uchar(*)(float)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uchar(*)(double)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uchar(*)(int64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uchar(*)(uint64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(uchar)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(ushort)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(short)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(unsigned int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(float)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(double)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(int64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<schar(*)(uint64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<ushort(*)(schar)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<ushort(*)(short)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<ushort(*)(int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<ushort(*)(unsigned int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<ushort(*)(float)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<ushort(*)(double)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<ushort(*)(int64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<ushort(*)(uint64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<short(*)(ushort)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<short(*)(int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<short(*)(unsigned int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<short(*)(float)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<short(*)(double)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<short(*)(int64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<short(*)(uint64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<int(*)(unsigned int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<int(*)(int64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<int(*)(uint64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<int(*)(float)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<int(*)(double)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<unsigned int(*)(schar)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<unsigned int(*)(short)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<unsigned int(*)(int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<unsigned int(*)(int64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<unsigned int(*)(uint64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<unsigned int(*)(float)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<unsigned int(*)(double)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uint64(*)(schar)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uint64(*)(short)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uint64(*)(int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<uint64(*)(int64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<int64(*)(uint64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(uchar)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(schar)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(ushort)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(short)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(unsigned int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(int)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(uint64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(int64)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(float)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));

  rb_mCv.define_module_function<cv::hfloat(*)(double)>("saturate_cast", &cv::saturate_cast,
    Arg("v"));
}