#include <opencv2/core/cuda/detail/reduce_key_val.hpp>
#include "reduce_key_val-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, unsigned int I, typename KP, typename KR, typename VP, typename VR, typename Cmp>
inline void Unroll_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<int(*)(KR, VR, Cmp, unsigned int)>("loop_shfl", &cv::cuda::device::reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>::loopShfl,
      Arg("key"), Arg("val"), Arg("cmp"), Arg("n")).
    template define_singleton_function<int(*)(KP, KR, VP, VR, unsigned int, Cmp)>("loop", &cv::cuda::device::reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>::loop,
      Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));
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

