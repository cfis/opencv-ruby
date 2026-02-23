#include <opencv2/cudev/util/atomic.hpp>
#include "atomic-rb.hpp"

using namespace Rice;

void Init_Cudev_Util_Atomic()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  rb_mCvCudev.define_module_function<int(*)(int*, int)>("atomic_add", &cv::cudev::atomicAdd,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<uint(*)(uint*, uint)>("atomic_add", &cv::cudev::atomicAdd,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<float(*)(float*, float)>("atomic_add", &cv::cudev::atomicAdd,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<double(*)(double*, double)>("atomic_add", &cv::cudev::atomicAdd,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<int(*)(int*, int)>("atomic_min", &cv::cudev::atomicMin,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<uint(*)(uint*, uint)>("atomic_min", &cv::cudev::atomicMin,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<float(*)(float*, float)>("atomic_min", &cv::cudev::atomicMin,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<double(*)(double*, double)>("atomic_min", &cv::cudev::atomicMin,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<int(*)(int*, int)>("atomic_max", &cv::cudev::atomicMax,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<uint(*)(uint*, uint)>("atomic_max", &cv::cudev::atomicMax,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<float(*)(float*, float)>("atomic_max", &cv::cudev::atomicMax,
    ArgBuffer("address"), Arg("val"));

  rb_mCvCudev.define_module_function<double(*)(double*, double)>("atomic_max", &cv::cudev::atomicMax,
    ArgBuffer("address"), Arg("val"));
}
