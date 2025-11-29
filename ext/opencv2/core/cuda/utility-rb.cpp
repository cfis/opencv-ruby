#include <opencv2/core/cuda/utility.hpp>
#include "utility-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceMaskCollection;
Rice::Class rb_cCvCudaDeviceSingleMask;
Rice::Class rb_cCvCudaDeviceSingleMaskChannels;
Rice::Class rb_cCvCudaDeviceThrustAllocator;
Rice::Class rb_cCvCudaDeviceWithOutMask;

void Init_Utility()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceThrustAllocator = define_class_under<cv::cuda::device::ThrustAllocator>(rb_mCvCudaDevice, "ThrustAllocator").
    define_constructor(Constructor<cv::cuda::device::ThrustAllocator>()).
    define_attr("__host__", &cv::cuda::device::ThrustAllocator::__host__).
    define_singleton_function("get_allocator", &cv::cuda::device::ThrustAllocator::getAllocator).
    define_singleton_function("set_allocator", &cv::cuda::device::ThrustAllocator::setAllocator,
      Arg("allocator"));
  
  rb_cCvCudaDeviceSingleMask = define_class_under<cv::cuda::device::SingleMask>(rb_mCvCudaDevice, "SingleMask").
    define_constructor(Constructor<cv::cuda::device::SingleMask>()).
    define_attr("__device__", &cv::cuda::device::SingleMask::__device__);
  
  rb_cCvCudaDeviceSingleMaskChannels = define_class_under<cv::cuda::device::SingleMaskChannels>(rb_mCvCudaDevice, "SingleMaskChannels").
    define_constructor(Constructor<cv::cuda::device::SingleMaskChannels>()).
    define_attr("__device__", &cv::cuda::device::SingleMaskChannels::__device__).
    define_attr("channels", &cv::cuda::device::SingleMaskChannels::channels);
  
  rb_cCvCudaDeviceMaskCollection = define_class_under<cv::cuda::device::MaskCollection>(rb_mCvCudaDevice, "MaskCollection").
    define_constructor(Constructor<cv::cuda::device::MaskCollection>()).
    define_attr("__device__", &cv::cuda::device::MaskCollection::__device__).
    define_attr("cur_mask", &cv::cuda::device::MaskCollection::curMask);
  
  rb_cCvCudaDeviceWithOutMask = define_class_under<cv::cuda::device::WithOutMask>(rb_mCvCudaDevice, "WithOutMask").
    define_constructor(Constructor<cv::cuda::device::WithOutMask>()).
    define_attr("__device__", &cv::cuda::device::WithOutMask::__device__);
  
  rb_mCvCudaDevice.define_module_function("solve2x2?", &cv::cuda::device::solve2x2,
    Arg("a"), Arg("b"), Arg("x"));
  
  rb_mCvCudaDevice.define_module_function("solve3x3?", &cv::cuda::device::solve3x3,
    Arg("a"), Arg("b"), Arg("x"));

}