#include <opencv2/core/cuda/dynamic_smem.hpp>
#include "dynamic_smem-rb.hpp"

using namespace Rice;

#include "dynamic_smem-rb.ipp"

void Init_Core_Cuda_DynamicSmem()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::DynamicSharedMem<double>> rb_cCvCudaDeviceDynamicSharedMemDouble = define_class_under<cv::cuda::device::DynamicSharedMem<double>>(rb_mCvCudaDevice, "DynamicSharedMemDouble").
    define_constructor(Constructor<cv::cuda::device::DynamicSharedMem<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::DynamicSharedMem<double>::__forceinline__);
}