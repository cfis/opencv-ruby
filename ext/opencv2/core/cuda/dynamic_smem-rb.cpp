#include <opencv2/core/cuda/dynamic_smem.hpp>
#include "dynamic_smem-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceDynamicSharedMemDouble;

template<typename Data_Type_T, typename T>
inline void DynamicSharedMem_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::DynamicSharedMem<T>::__forceinline__);
};
void Init_DynamicSmem()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceDynamicSharedMemDouble = define_class_under<cv::cuda::device::DynamicSharedMem<double>>(rb_mCvCudaDevice, "DynamicSharedMemDouble").
    define_constructor(Constructor<cv::cuda::device::DynamicSharedMem<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::DynamicSharedMem<double>::__forceinline__);

}