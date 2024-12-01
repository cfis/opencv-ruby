#include <opencv2/core/cuda/detail/reduce_key_val.hpp>
#include "reduce_key_val-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, unsigned int I, unsigned int N>
inline void For_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, unsigned int N>
inline void Generic_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, unsigned int I, typename KP, typename KR, typename VP, typename VR, typename Cmp>
inline void Unroll_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function("loop_shfl", &cv::cuda::device::reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>::loopShfl,
      Arg("key"), Arg("val"), Arg("cmp"), Arg("n")).
    template define_singleton_function("loop", &cv::cuda::device::reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>::loop,
      Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));
};

template<typename Data_Type_T, unsigned int N>
inline void WarpOptimized_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, unsigned int N>
inline void GenericOptimized32_builder(Data_Type_T& klass)
{
  klass.define_constant("M", (int)cv::cuda::device::reduce_key_val_detail::GenericOptimized32<N>::M);
};

template<typename Data_Type_T, unsigned int N>
inline void IsPowerOf2_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::reduce_key_val_detail::IsPowerOf2<N>::value);
};

template<typename Data_Type_T, unsigned int N>
inline void Dispatcher_builder(Data_Type_T& klass)
{
};
void Init_ReduceKeyVal()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceReduceKeyValDetail = define_module_under(rb_mCvCudaDevice, "ReduceKeyValDetail");
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, unsigned int)>("load_to_smem", &cv::cuda::device::reduce_key_val_detail::loadToSmem,
    Arg("smem"), Arg("data"), Arg("tid"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, unsigned int)>("load_from_smem", &cv::cuda::device::reduce_key_val_detail::loadFromSmem,
    Arg("smem"), Arg("data"), Arg("tid"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, unsigned int)>("load_to_smem", &cv::cuda::device::reduce_key_val_detail::loadToSmem,
    Arg("smem"), Arg("data"), Arg("tid"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, unsigned int)>("load_from_smem", &cv::cuda::device::reduce_key_val_detail::loadFromSmem,
    Arg("smem"), Arg("data"), Arg("tid"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(int&, unsigned int, int)>("copy_vals_shfl", &cv::cuda::device::reduce_key_val_detail::copyValsShfl,
    Arg("val"), Arg("delta"), Arg("width"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, unsigned int, unsigned int)>("copy_vals", &cv::cuda::device::reduce_key_val_detail::copyVals,
    Arg("svals"), Arg("val"), Arg("tid"), Arg("delta"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(int&, int&, const int&, unsigned int, int)>("merge_shfl", &cv::cuda::device::reduce_key_val_detail::mergeShfl,
    Arg("key"), Arg("val"), Arg("cmp"), Arg("delta"), Arg("width"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, volatile int*, int&, const int&, unsigned int, unsigned int)>("merge", &cv::cuda::device::reduce_key_val_detail::merge,
    Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("cmp"), Arg("tid"), Arg("delta"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, unsigned int, int)>("copy_vals_shfl", &cv::cuda::device::reduce_key_val_detail::copyValsShfl,
    Arg("val"), Arg("delta"), Arg("width"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, unsigned int, unsigned int)>("copy_vals", &cv::cuda::device::reduce_key_val_detail::copyVals,
    Arg("svals"), Arg("val"), Arg("tid"), Arg("delta"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(int&, const int&, const int&, unsigned int, int)>("merge_shfl", &cv::cuda::device::reduce_key_val_detail::mergeShfl,
    Arg("key"), Arg("val"), Arg("cmp"), Arg("delta"), Arg("width"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, const int&, const int&, const int&, unsigned int, unsigned int)>("merge", &cv::cuda::device::reduce_key_val_detail::merge,
    Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("cmp"), Arg("tid"), Arg("delta"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, const int&, unsigned int, int)>("merge_shfl", &cv::cuda::device::reduce_key_val_detail::mergeShfl,
    Arg("key"), Arg("val"), Arg("cmp"), Arg("delta"), Arg("width"));
  
  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, const int&, const int&, const int&, unsigned int, unsigned int)>("merge", &cv::cuda::device::reduce_key_val_detail::merge,
    Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("cmp"), Arg("tid"), Arg("delta"));

}