#include <opencv2/core/cuda/saturate_cast.hpp>
#include "saturate_cast-rb.hpp"

using namespace Rice;


void Init_SaturateCast()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_mCvCudaDevice.define_module_function<int(*)(uchar)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(schar)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(ushort)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(uint)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast,
    Arg("v"));
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_singleton_attr("SaturateCast", &cv::cuda::device::saturate_cast);

}