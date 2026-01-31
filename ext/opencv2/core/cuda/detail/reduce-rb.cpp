#include "reduce-rb.ipp"

void Init_Core_Cuda_Detail_Reduce()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Module rb_mCvCudaDeviceReduceDetail = define_module_under(rb_mCvCudaDevice, "ReduceDetail");

  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(volatile int*, int&, unsigned int)>("load_to_smem", &cv::cuda::device::reduce_detail::loadToSmem,
    ArgBuffer("smem"), Arg("val"), Arg("tid"));

  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(volatile int*, int&, unsigned int)>("load_from_smem", &cv::cuda::device::reduce_detail::loadFromSmem,
    ArgBuffer("smem"), Arg("val"), Arg("tid"));

  rb_mCvCudaDeviceReduceDetail.define_module_function<void(*)(volatile int*, int&, unsigned int, unsigned int, const int&)>("merge", &cv::cuda::device::reduce_detail::merge,
    ArgBuffer("smem"), Arg("val"), Arg("tid"), Arg("delta"), Arg("op"));

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