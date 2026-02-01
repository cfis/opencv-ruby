#include <opencv2/core/cuda/vec_distance.hpp>
#include "vec_distance-rb.hpp"

using namespace Rice;

#include "vec_distance-rb.ipp"

void Init_Core_Cuda_VecDistance()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::L1Dist<float>> rb_cCvCudaDeviceL1DistFloat = define_class_under<cv::cuda::device::L1Dist<float>>(rb_mCvCudaDevice, "L1DistFloat").
    define_constructor(Constructor<cv::cuda::device::L1Dist<float>>()).
    define_method<void(cv::cuda::device::L1Dist<float>::*)(float, float)>("reduce_iter", &cv::cuda::device::L1Dist<float>::reduceIter,
      Arg("val1"), Arg("val2")).
    define_method("to_f32", [](const cv::cuda::device::L1Dist<float>& self) -> float
    {
      return self;
    }).
    define_attr("my_sum", &cv::cuda::device::L1Dist<float>::mySum);

  Rice::Data_Type<cv::cuda::device::L2Dist> rb_cCvCudaDeviceL2Dist = define_class_under<cv::cuda::device::L2Dist>(rb_mCvCudaDevice, "L2Dist").
    define_constructor(Constructor<cv::cuda::device::L2Dist>()).
    define_method<void(cv::cuda::device::L2Dist::*)(float, float)>("reduce_iter", &cv::cuda::device::L2Dist::reduceIter,
      Arg("val1"), Arg("val2")).
    define_method("to_f32", [](const cv::cuda::device::L2Dist& self) -> float
    {
      return self;
    }).
    define_attr("my_sum", &cv::cuda::device::L2Dist::mySum);

  Rice::Data_Type<cv::cuda::device::HammingDist> rb_cCvCudaDeviceHammingDist = define_class_under<cv::cuda::device::HammingDist>(rb_mCvCudaDevice, "HammingDist").
    define_constructor(Constructor<cv::cuda::device::HammingDist>()).
    define_method<void(cv::cuda::device::HammingDist::*)(int, int)>("reduce_iter", &cv::cuda::device::HammingDist::reduceIter,
      Arg("val1"), Arg("val2")).
    define_method("to_i", [](const cv::cuda::device::HammingDist& self) -> int
    {
      return self;
    }).
    define_attr("my_sum", &cv::cuda::device::HammingDist::mySum);
}