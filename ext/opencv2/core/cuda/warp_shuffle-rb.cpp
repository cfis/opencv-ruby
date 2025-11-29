#include <opencv2/core/cuda/warp_shuffle.hpp>
#include "warp_shuffle-rb.hpp"

using namespace Rice;


void Init_WarpShuffle()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_mCvCudaDevice.define_module_function<int(*)(int, int, int)>("shfl", &cv::cuda::device::shfl,
    Arg("val"), Arg("src_lane"), Arg("width") = static_cast<int>());
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, int, int)>("shfl", &cv::cuda::device::shfl,
    Arg("val"), Arg("src_lane"), Arg("width") = static_cast<int>());
  
  rb_mCvCudaDevice.define_module_function<double(*)(double, int, int)>("shfl", &cv::cuda::device::shfl,
    Arg("val"), Arg("src_lane"), Arg("width") = static_cast<int>());
  
  rb_mCvCudaDevice.define_module_function<int(*)(int, unsigned int, int)>("shfl_down", &cv::cuda::device::shfl_down,
    Arg("val"), Arg("delta"), Arg("width") = static_cast<int>());
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int, int)>("shfl_down", &cv::cuda::device::shfl_down,
    Arg("val"), Arg("delta"), Arg("width") = static_cast<int>());
  
  rb_mCvCudaDevice.define_module_function<double(*)(double, unsigned int, int)>("shfl_down", &cv::cuda::device::shfl_down,
    Arg("val"), Arg("delta"), Arg("width") = static_cast<int>());
  
  rb_mCvCudaDevice.define_module_function<int(*)(int, unsigned int, int)>("shfl_up", &cv::cuda::device::shfl_up,
    Arg("val"), Arg("delta"), Arg("width") = static_cast<int>());
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int, int)>("shfl_up", &cv::cuda::device::shfl_up,
    Arg("val"), Arg("delta"), Arg("width") = static_cast<int>());
  
  rb_mCvCudaDevice.define_module_function<double(*)(double, unsigned int, int)>("shfl_up", &cv::cuda::device::shfl_up,
    Arg("val"), Arg("delta"), Arg("width") = static_cast<int>());

}