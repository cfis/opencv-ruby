#include <opencv2/core/cuda/emulation.hpp>
#include "emulation-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_Emulation()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::Emulation> rb_cCvCudaDeviceEmulation = define_class_under<cv::cuda::device::Emulation>(rb_mCvCudaDevice, "Emulation").
    define_constructor(Constructor<cv::cuda::device::Emulation>()).
    define_singleton_function<int(*)(int)>("syncthreads_or", &cv::cuda::device::Emulation::syncthreadsOr,
      Arg("pred"));

  Rice::Data_Type<cv::cuda::device::Emulation::smem> rb_cCvCudaDeviceEmulationSmem = define_class_under<cv::cuda::device::Emulation::smem>(rb_cCvCudaDeviceEmulation, "Smem").
    define_constructor(Constructor<cv::cuda::device::Emulation::smem>());

  rb_cCvCudaDeviceEmulationSmem.define_constant("TAG_MASK", (int)cv::cuda::device::Emulation::smem::TAG_MASK);

  Rice::Data_Type<cv::cuda::device::Emulation::glob> rb_cCvCudaDeviceEmulationGlob = define_class_under<cv::cuda::device::Emulation::glob>(rb_cCvCudaDeviceEmulation, "Glob").
    define_constructor(Constructor<cv::cuda::device::Emulation::glob>()).
    define_singleton_function<int(*)(int*, int)>("atomic_add", &cv::cuda::device::Emulation::glob::atomicAdd,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<unsigned int(*)(unsigned int*, unsigned int)>("atomic_add", &cv::cuda::device::Emulation::glob::atomicAdd,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<float(*)(float*, float)>("atomic_add", &cv::cuda::device::Emulation::glob::atomicAdd,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<double(*)(double*, double)>("atomic_add", &cv::cuda::device::Emulation::glob::atomicAdd,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<int(*)(int*, int)>("atomic_min", &cv::cuda::device::Emulation::glob::atomicMin,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<float(*)(float*, float)>("atomic_min", &cv::cuda::device::Emulation::glob::atomicMin,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<double(*)(double*, double)>("atomic_min", &cv::cuda::device::Emulation::glob::atomicMin,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<int(*)(int*, int)>("atomic_max", &cv::cuda::device::Emulation::glob::atomicMax,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<float(*)(float*, float)>("atomic_max", &cv::cuda::device::Emulation::glob::atomicMax,
      ArgBuffer("address"), Arg("val")).
    define_singleton_function<double(*)(double*, double)>("atomic_max", &cv::cuda::device::Emulation::glob::atomicMax,
      ArgBuffer("address"), Arg("val"));
}
