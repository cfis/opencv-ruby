#include <opencv2/cudev/util/saturate_cast.hpp>
#include "saturate_cast-rb.hpp"

using namespace Rice;

void Init_Cudev_Util_SaturateCast()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  rb_mCvCudev.define_module_function<uchar(*)(schar)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uchar(*)(short)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uchar(*)(ushort)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uchar(*)(int)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uchar(*)(uint)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uchar(*)(float)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uchar(*)(double)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<schar(*)(uchar)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<schar(*)(short)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<schar(*)(ushort)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<schar(*)(int)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<schar(*)(uint)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<schar(*)(float)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<schar(*)(double)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<ushort(*)(schar)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<ushort(*)(short)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<ushort(*)(int)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<ushort(*)(uint)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<ushort(*)(float)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<ushort(*)(double)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<short(*)(ushort)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<short(*)(int)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<short(*)(uint)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<short(*)(float)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<short(*)(double)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<int(*)(uint)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<int(*)(float)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<int(*)(double)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uint(*)(schar)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uint(*)(short)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uint(*)(int)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uint(*)(float)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<uint(*)(double)>("saturate_cast", &cv::cudev::saturate_cast,
    Arg("v"));

  rb_mCvCudev.define_module_function<float(*)(short)>("cast_fp16", &cv::cudev::cast_fp16,
    Arg("v"));

  rb_mCvCudev.define_module_function<short(*)(float)>("cast_fp16", &cv::cudev::cast_fp16,
    Arg("v"));
}