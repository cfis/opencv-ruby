#include <opencv2/core/cuda/utility.hpp>
#include "utility-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_Utility()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::ThrustAllocator> rb_cCvCudaDeviceThrustAllocator = define_class_under<cv::cuda::device::ThrustAllocator>(rb_mCvCudaDevice, "ThrustAllocator").
    define_method<uchar*(cv::cuda::device::ThrustAllocator::*)(size_t)>("allocate", &cv::cuda::device::ThrustAllocator::allocate,
      Arg("num_bytes"), ReturnBuffer()).
    define_method<void(cv::cuda::device::ThrustAllocator::*)(uchar*, size_t)>("deallocate", &cv::cuda::device::ThrustAllocator::deallocate,
      ArgBuffer("ptr"), Arg("num_bytes")).
    define_singleton_function<cv::cuda::device::ThrustAllocator&(*)()>("get_allocator", &cv::cuda::device::ThrustAllocator::getAllocator).
    define_singleton_function<void(*)(cv::cuda::device::ThrustAllocator*)>("set_allocator", &cv::cuda::device::ThrustAllocator::setAllocator,
      Arg("allocator"));

  Rice::Data_Type<cv::cuda::device::SingleMask> rb_cCvCudaDeviceSingleMask = define_class_under<cv::cuda::device::SingleMask>(rb_mCvCudaDevice, "SingleMask").
    define_constructor(Constructor<cv::cuda::device::SingleMask, cv::cuda::PtrStepb>(),
      Arg("mask_")).
    define_constructor(Constructor<cv::cuda::device::SingleMask, const cv::cuda::device::SingleMask&>(),
      Arg("mask_")).
    define_method<bool(cv::cuda::device::SingleMask::*)(int, int) const>("call", &cv::cuda::device::SingleMask::operator(),
      Arg("y"), Arg("x")).
    define_attr("mask", &cv::cuda::device::SingleMask::mask);

  Rice::Data_Type<cv::cuda::device::SingleMaskChannels> rb_cCvCudaDeviceSingleMaskChannels = define_class_under<cv::cuda::device::SingleMaskChannels>(rb_mCvCudaDevice, "SingleMaskChannels").
    define_constructor(Constructor<cv::cuda::device::SingleMaskChannels, cv::cuda::PtrStepb, int>(),
      Arg("mask_"), Arg("channels_")).
    define_constructor(Constructor<cv::cuda::device::SingleMaskChannels, const cv::cuda::device::SingleMaskChannels&>(),
      Arg("mask_")).
    define_method<bool(cv::cuda::device::SingleMaskChannels::*)(int, int) const>("call", &cv::cuda::device::SingleMaskChannels::operator(),
      Arg("y"), Arg("x")).
    define_attr("mask", &cv::cuda::device::SingleMaskChannels::mask).
    define_attr("channels", &cv::cuda::device::SingleMaskChannels::channels);

  Rice::Data_Type<cv::cuda::device::MaskCollection> rb_cCvCudaDeviceMaskCollection = define_class_under<cv::cuda::device::MaskCollection>(rb_mCvCudaDevice, "MaskCollection").
    define_constructor(Constructor<cv::cuda::device::MaskCollection, cv::cuda::PtrStepb*>(),
      Arg("mask_collection_")).
    define_constructor(Constructor<cv::cuda::device::MaskCollection, const cv::cuda::device::MaskCollection&>(),
      Arg("masks_")).
    define_method<void(cv::cuda::device::MaskCollection::*)()>("next", &cv::cuda::device::MaskCollection::next).
    define_method<void(cv::cuda::device::MaskCollection::*)(int)>("set_mask", &cv::cuda::device::MaskCollection::setMask,
      Arg("z")).
    define_method<bool(cv::cuda::device::MaskCollection::*)(int, int) const>("call", &cv::cuda::device::MaskCollection::operator(),
      Arg("y"), Arg("x")).
    define_attr("mask_collection", &cv::cuda::device::MaskCollection::maskCollection).
    define_attr("cur_mask", &cv::cuda::device::MaskCollection::curMask);

  Rice::Data_Type<cv::cuda::device::WithOutMask> rb_cCvCudaDeviceWithOutMask = define_class_under<cv::cuda::device::WithOutMask>(rb_mCvCudaDevice, "WithOutMask").
    define_constructor(Constructor<cv::cuda::device::WithOutMask>()).
    define_constructor(Constructor<cv::cuda::device::WithOutMask, const cv::cuda::device::WithOutMask&>(),
      Arg("arg_0")).
    define_method<void(cv::cuda::device::WithOutMask::*)() const>("next", &cv::cuda::device::WithOutMask::next).
    define_method<void(cv::cuda::device::WithOutMask::*)(int) const>("set_mask", &cv::cuda::device::WithOutMask::setMask,
      Arg("arg_0")).
    define_method<bool(cv::cuda::device::WithOutMask::*)(int, int) const>("call", &cv::cuda::device::WithOutMask::operator(),
      Arg("arg_0"), Arg("arg_1")).
    define_method<bool(cv::cuda::device::WithOutMask::*)(int, int, int) const>("call", &cv::cuda::device::WithOutMask::operator(),
      Arg("arg_0"), Arg("arg_1"), Arg("arg_2")).
    define_singleton_function<bool(*)(int, int)>("check", &cv::cuda::device::WithOutMask::check,
      Arg("arg_0"), Arg("arg_1")).
    define_singleton_function<bool(*)(int, int, int)>("check", &cv::cuda::device::WithOutMask::check,
      Arg("arg_0"), Arg("arg_1"), Arg("arg_2"));
}