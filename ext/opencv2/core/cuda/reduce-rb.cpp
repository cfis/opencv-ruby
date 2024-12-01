#include <opencv2/core/cuda/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;


void Init_Reduce()
{
  Class(rb_cObject).define_constant("THRUST_DEBUG", THRUST_DEBUG);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_mCvCudaDevice.define_module_function<void(*)(volatile int*, int&, unsigned int, const int&)>("reduce", &cv::cuda::device::reduce,
    Arg("smem"), Arg("val"), Arg("tid"), Arg("op"));
  
  rb_mCvCudaDevice.define_module_function<void(*)(volatile int*, int&, volatile int*, int&, unsigned int, const int&)>("reduce_key_val", &cv::cuda::device::reduceKeyVal,
    Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));
  
  rb_mCvCudaDevice.define_module_function<void(*)(const int&, const int&, unsigned int, const int&)>("reduce", &cv::cuda::device::reduce,
    Arg("smem"), Arg("val"), Arg("tid"), Arg("op"));
  
  rb_mCvCudaDevice.define_module_function<void(*)(volatile int*, int&, const int&, const int&, unsigned int, const int&)>("reduce_key_val", &cv::cuda::device::reduceKeyVal,
    Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));
  
  rb_mCvCudaDevice.define_module_function<void(*)(const int&, const int&, const int&, const int&, unsigned int, const int&)>("reduce_key_val", &cv::cuda::device::reduceKeyVal,
    Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"), Arg("t2"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"), Arg("t2"), Arg("t3"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"), Arg("t2"), Arg("t3"), Arg("t4"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"), Arg("t2"), Arg("t3"), Arg("t4"), Arg("t5"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"), Arg("t2"), Arg("t3"), Arg("t4"), Arg("t5"), Arg("t6"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*, int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"), Arg("t2"), Arg("t3"), Arg("t4"), Arg("t5"), Arg("t6"), Arg("t7"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*, int*, int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"), Arg("t2"), Arg("t3"), Arg("t4"), Arg("t5"), Arg("t6"), Arg("t7"), Arg("t8"));
  
  rb_mCvCudaDevice.define_module_function<int(*)(int*, int*, int*, int*, int*, int*, int*, int*, int*, int*)>("smem_tuple", &cv::cuda::device::smem_tuple,
    Arg("t0"), Arg("t1"), Arg("t2"), Arg("t3"), Arg("t4"), Arg("t5"), Arg("t6"), Arg("t7"), Arg("t8"), Arg("t9"));

}