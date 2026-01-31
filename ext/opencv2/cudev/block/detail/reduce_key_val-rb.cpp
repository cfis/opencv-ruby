#include <opencv2/cudev/block/detail/reduce_key_val.hpp>
#include "reduce_key_val-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, int I, typename KP, typename KR, typename VP, typename VR, typename Cmp>
inline void Unroll_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<void(*)(KP, KR, VP, VR, uint, Cmp)>("loop", &cv::cudev::block_reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>::loop,
      Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));
};

template<typename Data_Type_T, uint N>
inline void GenericOptimized32_builder(Data_Type_T& klass)
{
  klass.define_constant("M", (int)cv::cudev::block_reduce_key_val_detail::GenericOptimized32<N>::M);
};

void Init_Cudev_Block_Detail_ReduceKeyVal()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevBlockReduceKeyValDetail = define_module_under(rb_mCvCudev, "BlockReduceKeyValDetail");
}