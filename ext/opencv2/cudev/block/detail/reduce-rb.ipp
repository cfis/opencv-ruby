#include <opencv2/cudev/block/detail/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, int I, typename Pointer, typename Reference, typename Op>
inline void Unroll_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<void(*)(Pointer, Reference, uint, Op)>("loop", &cv::cudev::block_reduce_detail::Unroll<I, Pointer, Reference, Op>::loop,
      Arg("smem"), Arg("val"), Arg("tid"), Arg("op"));
};

template<typename Data_Type_T, int N>
inline void GenericOptimized32_builder(Data_Type_T& klass)
{
  klass.define_constant("M", (int)cv::cudev::block_reduce_detail::GenericOptimized32<N>::M);
};

