#include <opencv2/core/cuda/emulation.hpp>
#include "emulation-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceEmulation;
Rice::Class rb_cCvCudaDeviceEmulationGlob;

void Init_Emulation()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceEmulation = define_class_under<cv::cuda::device::Emulation>(rb_mCvCudaDevice, "Emulation").
    define_constructor(Constructor<cv::cuda::device::Emulation>());
  
  rb_cCvCudaDeviceEmulationGlob = define_class_under<cv::cuda::device::Emulation::glob>(rb_cCvCudaDeviceEmulation, "Glob").
    define_constructor(Constructor<cv::cuda::device::Emulation::glob>());

}