#include <opencv2/core/cuda/detail/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, unsigned int I, typename Pointer, typename Reference, typename Op>
inline void Unroll_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<int(*)(Reference, Op, unsigned int)>("loop_shfl", &cv::cuda::device::reduce_detail::Unroll<I, Pointer, Reference, Op>::loopShfl,
      Arg("val"), Arg("op"), Arg("n")).
    template define_singleton_function<int(*)(Pointer, Reference, unsigned int, Op)>("loop", &cv::cuda::device::reduce_detail::Unroll<I, Pointer, Reference, Op>::loop,
      Arg("smem"), Arg("val"), Arg("tid"), Arg("op"));
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

