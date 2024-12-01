#include <opencv2/core/cuda/detail/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, unsigned int I, unsigned int N>
inline void For_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, unsigned int N>
inline void Generic_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, unsigned int I, typename Pointer, typename Reference, typename Op>
inline void Unroll_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function("loop_shfl", &cv::cuda::device::reduce_detail::Unroll<I, Pointer, Reference, Op>::loopShfl,
      Arg("val"), Arg("op"), Arg("n")).
    template define_singleton_function("loop", &cv::cuda::device::reduce_detail::Unroll<I, Pointer, Reference, Op>::loop,
      Arg("smem"), Arg("val"), Arg("tid"), Arg("op"));
};

template<typename Data_Type_T, unsigned int N>
inline void WarpOptimized_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, unsigned int N>
inline void GenericOptimized32_builder(Data_Type_T& klass)
{
  klass.define_constant("M", (int)cv::cuda::device::reduce_detail::GenericOptimized32<N>::M);
};

template<typename Data_Type_T, unsigned int N>
inline void IsPowerOf2_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::reduce_detail::IsPowerOf2<N>::value);
};

template<typename Data_Type_T, unsigned int N>
inline void Dispatcher_builder(Data_Type_T& klass)
{
};
void Init_Reduce()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceReduceDetail = define_module_under(rb_mCvCudaDevice, "ReduceDetail");
  
  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(volatile int*, int&, unsigned int)>("load_to_smem", &cv::cuda::device::reduce_detail::loadToSmem,
    Arg("smem"), Arg("val"), Arg("tid"));
  
  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(volatile int*, int&, unsigned int)>("load_from_smem", &cv::cuda::device::reduce_detail::loadFromSmem,
    Arg("smem"), Arg("val"), Arg("tid"));
  
  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(volatile int*, int&, unsigned int, unsigned int, const int&)>("merge", &cv::cuda::device::reduce_detail::merge,
    Arg("smem"), Arg("val"), Arg("tid"), Arg("delta"), Arg("op"));
  
  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(int&, unsigned int, unsigned int, const int&)>("merge_shfl", &cv::cuda::device::reduce_detail::mergeShfl,
    Arg("val"), Arg("delta"), Arg("width"), Arg("op"));
  
  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(const int&, const int&, unsigned int)>("load_to_smem", &cv::cuda::device::reduce_detail::loadToSmem,
    Arg("smem"), Arg("val"), Arg("tid"));
  
  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(const int&, const int&, unsigned int)>("load_from_smem", &cv::cuda::device::reduce_detail::loadFromSmem,
    Arg("smem"), Arg("val"), Arg("tid"));
  
  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(const int&, const int&, unsigned int, unsigned int, const int&)>("merge", &cv::cuda::device::reduce_detail::merge,
    Arg("smem"), Arg("val"), Arg("tid"), Arg("delta"), Arg("op"));
  
  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(const int&, unsigned int, unsigned int, const int&)>("merge_shfl", &cv::cuda::device::reduce_detail::mergeShfl,
    Arg("val"), Arg("delta"), Arg("width"), Arg("op"));

}