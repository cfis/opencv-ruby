#include <opencv2/core/cuda/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_Reduce()
{
  Class(rb_cObject).define_constant("THRUST_DEBUG", THRUST_DEBUG);

  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  rb_mCvCudaDevice.define_module_function<void(*)(volatile int*, int&, unsigned int, const int&)>("reduce", &cv::cuda::device::reduce,
    ArgBuffer("smem"), Arg("val"), Arg("tid"), Arg("op"));

  rb_mCvCudaDevice.define_module_function<void(*)(volatile int*, int&, volatile int*, int&, unsigned int, const int&)>("reduce_key_val", &cv::cuda::device::reduceKeyVal,
    ArgBuffer("skeys"), Arg("key"), ArgBuffer("svals"), Arg("val"), Arg("tid"), Arg("cmp"));

  rb_mCvCudaDevice.define_module_function<void(*)(const int&, const int&, unsigned int, const int&)>("reduce", &cv::cuda::device::reduce,
    Arg("smem"), Arg("val"), Arg("tid"), Arg("op"));

  rb_mCvCudaDevice.define_module_function<void(*)(volatile int*, int&, const int&, const int&, unsigned int, const int&)>("reduce_key_val", &cv::cuda::device::reduceKeyVal,
    ArgBuffer("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));

  rb_mCvCudaDevice.define_module_function<void(*)(const int&, const int&, const int&, const int&, unsigned int, const int&)>("reduce_key_val", &cv::cuda::device::reduceKeyVal,
    Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *>(*)(int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *>(*)(int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *, volatile T2 *>(*)(int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"), ArgBuffer("t2"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *, volatile T2 *, volatile T3 *>(*)(int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"), ArgBuffer("t2"), ArgBuffer("t3"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *, volatile T2 *, volatile T3 *, volatile T4 *>(*)(int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"), ArgBuffer("t2"), ArgBuffer("t3"), ArgBuffer("t4"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *, volatile T2 *, volatile T3 *, volatile T4 *, volatile T5 *>(*)(int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"), ArgBuffer("t2"), ArgBuffer("t3"), ArgBuffer("t4"), ArgBuffer("t5"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *, volatile T2 *, volatile T3 *, volatile T4 *, volatile T5 *, volatile T6 *>(*)(int*, int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"), ArgBuffer("t2"), ArgBuffer("t3"), ArgBuffer("t4"), ArgBuffer("t5"), ArgBuffer("t6"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *, volatile T2 *, volatile T3 *, volatile T4 *, volatile T5 *, volatile T6 *, volatile T7 *>(*)(int*, int*, int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"), ArgBuffer("t2"), ArgBuffer("t3"), ArgBuffer("t4"), ArgBuffer("t5"), ArgBuffer("t6"), ArgBuffer("t7"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *, volatile T2 *, volatile T3 *, volatile T4 *, volatile T5 *, volatile T6 *, volatile T7 *, volatile T8 *>(*)(int*, int*, int*, int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"), ArgBuffer("t2"), ArgBuffer("t3"), ArgBuffer("t4"), ArgBuffer("t5"), ArgBuffer("t6"), ArgBuffer("t7"), ArgBuffer("t8"));

  rb_mCvCudaDevice.define_module_function<thrust::tuple<volatile T0 *, volatile T1 *, volatile T2 *, volatile T3 *, volatile T4 *, volatile T5 *, volatile T6 *, volatile T7 *, volatile T8 *, volatile T9 *>(*)(int*, int*, int*, int*, int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    ArgBuffer("t0"), ArgBuffer("t1"), ArgBuffer("t2"), ArgBuffer("t3"), ArgBuffer("t4"), ArgBuffer("t5"), ArgBuffer("t6"), ArgBuffer("t7"), ArgBuffer("t8"), ArgBuffer("t9"));
}
