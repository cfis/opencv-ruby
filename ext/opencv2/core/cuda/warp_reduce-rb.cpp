#include <opencv2/core/cuda/warp_reduce.hpp>
#include "warp_reduce-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_WarpReduce()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  rb_mCvCudaDevice.define_module_function<T(*)(volatile int*, const unsigned int)>("warp_reduce", &cv::cuda::device::warp_reduce,
    ArgBuffer("ptr"), Arg("tid"));
}
