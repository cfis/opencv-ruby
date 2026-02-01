#include <opencv2/core/cuda/detail/reduce_key_val.hpp>
#include "reduce_key_val-rb.hpp"

using namespace Rice;

#include "reduce_key_val-rb.ipp"

void Init_Core_Cuda_Detail_ReduceKeyVal()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Module rb_mCvCudaDeviceReduceKeyValDetail = define_module_under(rb_mCvCudaDevice, "ReduceKeyValDetail");

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, unsigned int)>("load_to_smem", &cv::cuda::device::reduce_key_val_detail::loadToSmem,
    ArgBuffer("smem"), Arg("data"), Arg("tid"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, unsigned int)>("load_from_smem", &cv::cuda::device::reduce_key_val_detail::loadFromSmem,
    ArgBuffer("smem"), Arg("data"), Arg("tid"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, unsigned int)>("load_to_smem", &cv::cuda::device::reduce_key_val_detail::loadToSmem,
    Arg("smem"), Arg("data"), Arg("tid"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, unsigned int)>("load_from_smem", &cv::cuda::device::reduce_key_val_detail::loadFromSmem,
    Arg("smem"), Arg("data"), Arg("tid"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(int&, unsigned int, int)>("copy_vals_shfl", &cv::cuda::device::reduce_key_val_detail::copyValsShfl,
    Arg("val"), Arg("delta"), Arg("width"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, unsigned int, unsigned int)>("copy_vals", &cv::cuda::device::reduce_key_val_detail::copyVals,
    ArgBuffer("svals"), Arg("val"), Arg("tid"), Arg("delta"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(int&, int&, const int&, unsigned int, int)>("merge_shfl", &cv::cuda::device::reduce_key_val_detail::mergeShfl,
    Arg("key"), Arg("val"), Arg("cmp"), Arg("delta"), Arg("width"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, volatile int*, int&, const int&, unsigned int, unsigned int)>("merge", &cv::cuda::device::reduce_key_val_detail::merge,
    ArgBuffer("skeys"), Arg("key"), ArgBuffer("svals"), Arg("val"), Arg("cmp"), Arg("tid"), Arg("delta"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, unsigned int, int)>("copy_vals_shfl", &cv::cuda::device::reduce_key_val_detail::copyValsShfl,
    Arg("val"), Arg("delta"), Arg("width"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, unsigned int, unsigned int)>("copy_vals", &cv::cuda::device::reduce_key_val_detail::copyVals,
    Arg("svals"), Arg("val"), Arg("tid"), Arg("delta"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(int&, const int&, const int&, unsigned int, int)>("merge_shfl", &cv::cuda::device::reduce_key_val_detail::mergeShfl,
    Arg("key"), Arg("val"), Arg("cmp"), Arg("delta"), Arg("width"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(volatile int*, int&, const int&, const int&, const int&, unsigned int, unsigned int)>("merge", &cv::cuda::device::reduce_key_val_detail::merge,
    ArgBuffer("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("cmp"), Arg("tid"), Arg("delta"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, const int&, unsigned int, int)>("merge_shfl", &cv::cuda::device::reduce_key_val_detail::mergeShfl,
    Arg("key"), Arg("val"), Arg("cmp"), Arg("delta"), Arg("width"));

  rb_mCvCudaDeviceReduceKeyValDetail.define_module_function<void(*)(const int&, const int&, const int&, const int&, const int&, unsigned int, unsigned int)>("merge", &cv::cuda::device::reduce_key_val_detail::merge,
    Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("cmp"), Arg("tid"), Arg("delta"));
}