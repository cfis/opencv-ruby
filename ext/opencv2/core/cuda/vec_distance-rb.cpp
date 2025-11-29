#include <opencv2/core/cuda/vec_distance.hpp>
#include "vec_distance-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceHammingDist;
Rice::Class rb_cCvCudaDeviceL1DistFloat;
Rice::Class rb_cCvCudaDeviceL2Dist;

template<typename Data_Type_T, typename T>
inline void L1Dist_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::L1Dist<T>::__forceinline__);
};

template<typename Data_Type_T, int THREAD_DIM, typename T1>
inline void VecDiffGlobal_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::VecDiffGlobal<THREAD_DIM, T1>::__forceinline__);
};

template<typename Data_Type_T, int THREAD_DIM, int MAX_LEN, bool LEN_EQ_MAX_LEN, typename U>
inline void VecDiffCachedRegister_builder(Data_Type_T& klass)
{
};
void Init_VecDistance()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceL1DistFloat = define_class_under<cv::cuda::device::L1Dist<float>>(rb_mCvCudaDevice, "L1DistFloat").
    define_constructor(Constructor<cv::cuda::device::L1Dist<float>>()).
    define_attr("__forceinline__", &cv::cuda::device::L1Dist<float>::__forceinline__);
  
  rb_cCvCudaDeviceL2Dist = define_class_under<cv::cuda::device::L2Dist>(rb_mCvCudaDevice, "L2Dist").
    define_constructor(Constructor<cv::cuda::device::L2Dist>()).
    define_attr("__forceinline__", &cv::cuda::device::L2Dist::__forceinline__);
  
  rb_cCvCudaDeviceHammingDist = define_class_under<cv::cuda::device::HammingDist>(rb_mCvCudaDevice, "HammingDist").
    define_constructor(Constructor<cv::cuda::device::HammingDist>()).
    define_attr("__forceinline__", &cv::cuda::device::HammingDist::__forceinline__);
  
  rb_mCvCudaDevice.define_module_function("calc_vec_diff_cached", &cv::cuda::device::calcVecDiffCached,
    Arg("vec_cached"), Arg("vec_glob"), Arg("len"), Arg("dist"), Arg("smem"), Arg("tid"));

}