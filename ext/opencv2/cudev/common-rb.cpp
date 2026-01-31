#include <opencv2/cudev/common.hpp>
#include "common-rb.hpp"

using namespace Rice;

void Init_Cudev_Common()
{
  Class(rb_cObject).define_constant("CV_CUDEV_ARCH", CV_CUDEV_ARCH);

  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  rb_mCvCudev.define_module_function<void(*)(cudaError_t, const char*, const int, const char*)>("check_cuda_error", &cv::cudev::checkCudaError,
    Arg("err"), Arg("file"), Arg("line"), Arg("func"));

  rb_mCvCudev.define_module_function<int(*)(int, int)>("div_up", &cv::cudev::divUp,
    Arg("total"), Arg("grain"));
}