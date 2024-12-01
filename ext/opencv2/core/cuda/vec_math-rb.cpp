#include <opencv2/core/cuda/vec_math.hpp>
#include "vec_math-rb.hpp"

using namespace Rice;


void Init_VecMath()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceVecMathDetail = define_module_under(rb_mCvCudaDevice, "VecMathDetail");
  
  rb_mCvCudaDeviceVecMathDetail.define_module_function("saturate_cast_helper", &cv::cuda::device::vec_math_detail::saturate_cast_helper,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(const int&)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));

}