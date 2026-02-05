#include <opencv2/core/cuda/color.hpp>
#include "color-rb.hpp"

using namespace Rice;

#include "color-rb.ipp"

void Init_Core_Cuda_Color()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::bgr_to_bgr555_traits> rb_cCvCudaDeviceBgrToBgr555Traits = define_class_under<cv::cuda::device::bgr_to_bgr555_traits>(rb_mCvCudaDevice, "BgrToBgr555Traits").
    define_constructor(Constructor<cv::cuda::device::bgr_to_bgr555_traits>()).
    define_singleton_function<cv::cuda::device::bgr_to_bgr555_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_bgr555_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_bgr565_traits> rb_cCvCudaDeviceBgrToBgr565Traits = define_class_under<cv::cuda::device::bgr_to_bgr565_traits>(rb_mCvCudaDevice, "BgrToBgr565Traits").
    define_constructor(Constructor<cv::cuda::device::bgr_to_bgr565_traits>()).
    define_singleton_function<cv::cuda::device::bgr_to_bgr565_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_bgr565_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_bgr555_traits> rb_cCvCudaDeviceRgbToBgr555Traits = define_class_under<cv::cuda::device::rgb_to_bgr555_traits>(rb_mCvCudaDevice, "RgbToBgr555Traits").
    define_constructor(Constructor<cv::cuda::device::rgb_to_bgr555_traits>()).
    define_singleton_function<cv::cuda::device::rgb_to_bgr555_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_bgr555_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_bgr565_traits> rb_cCvCudaDeviceRgbToBgr565Traits = define_class_under<cv::cuda::device::rgb_to_bgr565_traits>(rb_mCvCudaDevice, "RgbToBgr565Traits").
    define_constructor(Constructor<cv::cuda::device::rgb_to_bgr565_traits>()).
    define_singleton_function<cv::cuda::device::rgb_to_bgr565_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_bgr565_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_bgr555_traits> rb_cCvCudaDeviceBgraToBgr555Traits = define_class_under<cv::cuda::device::bgra_to_bgr555_traits>(rb_mCvCudaDevice, "BgraToBgr555Traits").
    define_constructor(Constructor<cv::cuda::device::bgra_to_bgr555_traits>()).
    define_singleton_function<cv::cuda::device::bgra_to_bgr555_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_bgr555_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_bgr565_traits> rb_cCvCudaDeviceBgraToBgr565Traits = define_class_under<cv::cuda::device::bgra_to_bgr565_traits>(rb_mCvCudaDevice, "BgraToBgr565Traits").
    define_constructor(Constructor<cv::cuda::device::bgra_to_bgr565_traits>()).
    define_singleton_function<cv::cuda::device::bgra_to_bgr565_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_bgr565_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_bgr555_traits> rb_cCvCudaDeviceRgbaToBgr555Traits = define_class_under<cv::cuda::device::rgba_to_bgr555_traits>(rb_mCvCudaDevice, "RgbaToBgr555Traits").
    define_constructor(Constructor<cv::cuda::device::rgba_to_bgr555_traits>()).
    define_singleton_function<cv::cuda::device::rgba_to_bgr555_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_bgr555_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_bgr565_traits> rb_cCvCudaDeviceRgbaToBgr565Traits = define_class_under<cv::cuda::device::rgba_to_bgr565_traits>(rb_mCvCudaDevice, "RgbaToBgr565Traits").
    define_constructor(Constructor<cv::cuda::device::rgba_to_bgr565_traits>()).
    define_singleton_function<cv::cuda::device::rgba_to_bgr565_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_bgr565_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr555_to_rgb_traits> rb_cCvCudaDeviceBgr555ToRgbTraits = define_class_under<cv::cuda::device::bgr555_to_rgb_traits>(rb_mCvCudaDevice, "Bgr555ToRgbTraits").
    define_constructor(Constructor<cv::cuda::device::bgr555_to_rgb_traits>()).
    define_singleton_function<cv::cuda::device::bgr555_to_rgb_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr555_to_rgb_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr565_to_rgb_traits> rb_cCvCudaDeviceBgr565ToRgbTraits = define_class_under<cv::cuda::device::bgr565_to_rgb_traits>(rb_mCvCudaDevice, "Bgr565ToRgbTraits").
    define_constructor(Constructor<cv::cuda::device::bgr565_to_rgb_traits>()).
    define_singleton_function<cv::cuda::device::bgr565_to_rgb_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr565_to_rgb_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr555_to_bgr_traits> rb_cCvCudaDeviceBgr555ToBgrTraits = define_class_under<cv::cuda::device::bgr555_to_bgr_traits>(rb_mCvCudaDevice, "Bgr555ToBgrTraits").
    define_constructor(Constructor<cv::cuda::device::bgr555_to_bgr_traits>()).
    define_singleton_function<cv::cuda::device::bgr555_to_bgr_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr555_to_bgr_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr565_to_bgr_traits> rb_cCvCudaDeviceBgr565ToBgrTraits = define_class_under<cv::cuda::device::bgr565_to_bgr_traits>(rb_mCvCudaDevice, "Bgr565ToBgrTraits").
    define_constructor(Constructor<cv::cuda::device::bgr565_to_bgr_traits>()).
    define_singleton_function<cv::cuda::device::bgr565_to_bgr_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr565_to_bgr_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr555_to_rgba_traits> rb_cCvCudaDeviceBgr555ToRgbaTraits = define_class_under<cv::cuda::device::bgr555_to_rgba_traits>(rb_mCvCudaDevice, "Bgr555ToRgbaTraits").
    define_constructor(Constructor<cv::cuda::device::bgr555_to_rgba_traits>()).
    define_singleton_function<cv::cuda::device::bgr555_to_rgba_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr555_to_rgba_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr565_to_rgba_traits> rb_cCvCudaDeviceBgr565ToRgbaTraits = define_class_under<cv::cuda::device::bgr565_to_rgba_traits>(rb_mCvCudaDevice, "Bgr565ToRgbaTraits").
    define_constructor(Constructor<cv::cuda::device::bgr565_to_rgba_traits>()).
    define_singleton_function<cv::cuda::device::bgr565_to_rgba_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr565_to_rgba_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr555_to_bgra_traits> rb_cCvCudaDeviceBgr555ToBgraTraits = define_class_under<cv::cuda::device::bgr555_to_bgra_traits>(rb_mCvCudaDevice, "Bgr555ToBgraTraits").
    define_constructor(Constructor<cv::cuda::device::bgr555_to_bgra_traits>()).
    define_singleton_function<cv::cuda::device::bgr555_to_bgra_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr555_to_bgra_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr565_to_bgra_traits> rb_cCvCudaDeviceBgr565ToBgraTraits = define_class_under<cv::cuda::device::bgr565_to_bgra_traits>(rb_mCvCudaDevice, "Bgr565ToBgraTraits").
    define_constructor(Constructor<cv::cuda::device::bgr565_to_bgra_traits>()).
    define_singleton_function<cv::cuda::device::bgr565_to_bgra_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr565_to_bgra_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::gray_to_bgr555_traits> rb_cCvCudaDeviceGrayToBgr555Traits = define_class_under<cv::cuda::device::gray_to_bgr555_traits>(rb_mCvCudaDevice, "GrayToBgr555Traits").
    define_constructor(Constructor<cv::cuda::device::gray_to_bgr555_traits>()).
    define_singleton_function<cv::cuda::device::gray_to_bgr555_traits::functor_type(*)()>("create_functor", &cv::cuda::device::gray_to_bgr555_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::gray_to_bgr565_traits> rb_cCvCudaDeviceGrayToBgr565Traits = define_class_under<cv::cuda::device::gray_to_bgr565_traits>(rb_mCvCudaDevice, "GrayToBgr565Traits").
    define_constructor(Constructor<cv::cuda::device::gray_to_bgr565_traits>()).
    define_singleton_function<cv::cuda::device::gray_to_bgr565_traits::functor_type(*)()>("create_functor", &cv::cuda::device::gray_to_bgr565_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr555_to_gray_traits> rb_cCvCudaDeviceBgr555ToGrayTraits = define_class_under<cv::cuda::device::bgr555_to_gray_traits>(rb_mCvCudaDevice, "Bgr555ToGrayTraits").
    define_constructor(Constructor<cv::cuda::device::bgr555_to_gray_traits>()).
    define_singleton_function<cv::cuda::device::bgr555_to_gray_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr555_to_gray_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr565_to_gray_traits> rb_cCvCudaDeviceBgr565ToGrayTraits = define_class_under<cv::cuda::device::bgr565_to_gray_traits>(rb_mCvCudaDevice, "Bgr565ToGrayTraits").
    define_constructor(Constructor<cv::cuda::device::bgr565_to_gray_traits>()).
    define_singleton_function<cv::cuda::device::bgr565_to_gray_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr565_to_gray_traits::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_hsv_traits<float>> rb_cCvCudaDeviceRgbToHsvTraitsFloat = define_class_under<cv::cuda::device::rgb_to_hsv_traits<float>>(rb_mCvCudaDevice, "RgbToHsvTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgb_to_hsv_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgb_to_hsv_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_hsv_full_traits<float>> rb_cCvCudaDeviceRgbToHsvFullTraitsFloat = define_class_under<cv::cuda::device::rgb_to_hsv_full_traits<float>>(rb_mCvCudaDevice, "RgbToHsvFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgb_to_hsv_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgb_to_hsv_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_hsv_traits<float>> rb_cCvCudaDeviceRgbaToHsvTraitsFloat = define_class_under<cv::cuda::device::rgba_to_hsv_traits<float>>(rb_mCvCudaDevice, "RgbaToHsvTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgba_to_hsv_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgba_to_hsv_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_hsv_full_traits<float>> rb_cCvCudaDeviceRgbaToHsvFullTraitsFloat = define_class_under<cv::cuda::device::rgba_to_hsv_full_traits<float>>(rb_mCvCudaDevice, "RgbaToHsvFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgba_to_hsv_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgba_to_hsv_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_hsv4_traits<float>> rb_cCvCudaDeviceRgbToHsv4TraitsFloat = define_class_under<cv::cuda::device::rgb_to_hsv4_traits<float>>(rb_mCvCudaDevice, "RgbToHsv4TraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgb_to_hsv4_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgb_to_hsv4_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv4_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_hsv4_full_traits<float>> rb_cCvCudaDeviceRgbToHsv4FullTraitsFloat = define_class_under<cv::cuda::device::rgb_to_hsv4_full_traits<float>>(rb_mCvCudaDevice, "RgbToHsv4FullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgb_to_hsv4_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgb_to_hsv4_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv4_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_hsv4_traits<float>> rb_cCvCudaDeviceRgbaToHsv4TraitsFloat = define_class_under<cv::cuda::device::rgba_to_hsv4_traits<float>>(rb_mCvCudaDevice, "RgbaToHsv4TraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgba_to_hsv4_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgba_to_hsv4_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv4_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_hsv4_full_traits<float>> rb_cCvCudaDeviceRgbaToHsv4FullTraitsFloat = define_class_under<cv::cuda::device::rgba_to_hsv4_full_traits<float>>(rb_mCvCudaDevice, "RgbaToHsv4FullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgba_to_hsv4_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgba_to_hsv4_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv4_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_hsv_traits<float>> rb_cCvCudaDeviceBgrToHsvTraitsFloat = define_class_under<cv::cuda::device::bgr_to_hsv_traits<float>>(rb_mCvCudaDevice, "BgrToHsvTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgr_to_hsv_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgr_to_hsv_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_hsv_full_traits<float>> rb_cCvCudaDeviceBgrToHsvFullTraitsFloat = define_class_under<cv::cuda::device::bgr_to_hsv_full_traits<float>>(rb_mCvCudaDevice, "BgrToHsvFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgr_to_hsv_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgr_to_hsv_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_hsv_traits<float>> rb_cCvCudaDeviceBgraToHsvTraitsFloat = define_class_under<cv::cuda::device::bgra_to_hsv_traits<float>>(rb_mCvCudaDevice, "BgraToHsvTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgra_to_hsv_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgra_to_hsv_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_hsv_full_traits<float>> rb_cCvCudaDeviceBgraToHsvFullTraitsFloat = define_class_under<cv::cuda::device::bgra_to_hsv_full_traits<float>>(rb_mCvCudaDevice, "BgraToHsvFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgra_to_hsv_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgra_to_hsv_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_hsv4_traits<float>> rb_cCvCudaDeviceBgrToHsv4TraitsFloat = define_class_under<cv::cuda::device::bgr_to_hsv4_traits<float>>(rb_mCvCudaDevice, "BgrToHsv4TraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgr_to_hsv4_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgr_to_hsv4_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv4_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_hsv4_full_traits<float>> rb_cCvCudaDeviceBgrToHsv4FullTraitsFloat = define_class_under<cv::cuda::device::bgr_to_hsv4_full_traits<float>>(rb_mCvCudaDevice, "BgrToHsv4FullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgr_to_hsv4_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgr_to_hsv4_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv4_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_hsv4_traits<float>> rb_cCvCudaDeviceBgraToHsv4TraitsFloat = define_class_under<cv::cuda::device::bgra_to_hsv4_traits<float>>(rb_mCvCudaDevice, "BgraToHsv4TraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgra_to_hsv4_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgra_to_hsv4_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv4_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_hsv4_full_traits<float>> rb_cCvCudaDeviceBgraToHsv4FullTraitsFloat = define_class_under<cv::cuda::device::bgra_to_hsv4_full_traits<float>>(rb_mCvCudaDevice, "BgraToHsv4FullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgra_to_hsv4_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgra_to_hsv4_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv4_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv_to_rgb_traits<float>> rb_cCvCudaDeviceHsvToRgbTraitsFloat = define_class_under<cv::cuda::device::hsv_to_rgb_traits<float>>(rb_mCvCudaDevice, "HsvToRgbTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv_to_rgb_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv_to_rgb_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgb_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv_to_rgb_full_traits<float>> rb_cCvCudaDeviceHsvToRgbFullTraitsFloat = define_class_under<cv::cuda::device::hsv_to_rgb_full_traits<float>>(rb_mCvCudaDevice, "HsvToRgbFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv_to_rgb_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv_to_rgb_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgb_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv_to_rgba_traits<float>> rb_cCvCudaDeviceHsvToRgbaTraitsFloat = define_class_under<cv::cuda::device::hsv_to_rgba_traits<float>>(rb_mCvCudaDevice, "HsvToRgbaTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv_to_rgba_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv_to_rgba_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgba_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv_to_rgba_full_traits<float>> rb_cCvCudaDeviceHsvToRgbaFullTraitsFloat = define_class_under<cv::cuda::device::hsv_to_rgba_full_traits<float>>(rb_mCvCudaDevice, "HsvToRgbaFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv_to_rgba_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv_to_rgba_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgba_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv4_to_rgb_traits<float>> rb_cCvCudaDeviceHsv4ToRgbTraitsFloat = define_class_under<cv::cuda::device::hsv4_to_rgb_traits<float>>(rb_mCvCudaDevice, "Hsv4ToRgbTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv4_to_rgb_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv4_to_rgb_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgb_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv4_to_rgb_full_traits<float>> rb_cCvCudaDeviceHsv4ToRgbFullTraitsFloat = define_class_under<cv::cuda::device::hsv4_to_rgb_full_traits<float>>(rb_mCvCudaDevice, "Hsv4ToRgbFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv4_to_rgb_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv4_to_rgb_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgb_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv4_to_rgba_traits<float>> rb_cCvCudaDeviceHsv4ToRgbaTraitsFloat = define_class_under<cv::cuda::device::hsv4_to_rgba_traits<float>>(rb_mCvCudaDevice, "Hsv4ToRgbaTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv4_to_rgba_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv4_to_rgba_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgba_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv4_to_rgba_full_traits<float>> rb_cCvCudaDeviceHsv4ToRgbaFullTraitsFloat = define_class_under<cv::cuda::device::hsv4_to_rgba_full_traits<float>>(rb_mCvCudaDevice, "Hsv4ToRgbaFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv4_to_rgba_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv4_to_rgba_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgba_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv_to_bgr_traits<float>> rb_cCvCudaDeviceHsvToBgrTraitsFloat = define_class_under<cv::cuda::device::hsv_to_bgr_traits<float>>(rb_mCvCudaDevice, "HsvToBgrTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv_to_bgr_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv_to_bgr_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgr_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv_to_bgr_full_traits<float>> rb_cCvCudaDeviceHsvToBgrFullTraitsFloat = define_class_under<cv::cuda::device::hsv_to_bgr_full_traits<float>>(rb_mCvCudaDevice, "HsvToBgrFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv_to_bgr_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv_to_bgr_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgr_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv_to_bgra_traits<float>> rb_cCvCudaDeviceHsvToBgraTraitsFloat = define_class_under<cv::cuda::device::hsv_to_bgra_traits<float>>(rb_mCvCudaDevice, "HsvToBgraTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv_to_bgra_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv_to_bgra_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgra_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv_to_bgra_full_traits<float>> rb_cCvCudaDeviceHsvToBgraFullTraitsFloat = define_class_under<cv::cuda::device::hsv_to_bgra_full_traits<float>>(rb_mCvCudaDevice, "HsvToBgraFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv_to_bgra_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv_to_bgra_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgra_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv4_to_bgr_traits<float>> rb_cCvCudaDeviceHsv4ToBgrTraitsFloat = define_class_under<cv::cuda::device::hsv4_to_bgr_traits<float>>(rb_mCvCudaDevice, "Hsv4ToBgrTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv4_to_bgr_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv4_to_bgr_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgr_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv4_to_bgr_full_traits<float>> rb_cCvCudaDeviceHsv4ToBgrFullTraitsFloat = define_class_under<cv::cuda::device::hsv4_to_bgr_full_traits<float>>(rb_mCvCudaDevice, "Hsv4ToBgrFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv4_to_bgr_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv4_to_bgr_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgr_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv4_to_bgra_traits<float>> rb_cCvCudaDeviceHsv4ToBgraTraitsFloat = define_class_under<cv::cuda::device::hsv4_to_bgra_traits<float>>(rb_mCvCudaDevice, "Hsv4ToBgraTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv4_to_bgra_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv4_to_bgra_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgra_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hsv4_to_bgra_full_traits<float>> rb_cCvCudaDeviceHsv4ToBgraFullTraitsFloat = define_class_under<cv::cuda::device::hsv4_to_bgra_full_traits<float>>(rb_mCvCudaDevice, "Hsv4ToBgraFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hsv4_to_bgra_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hsv4_to_bgra_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgra_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_hls_traits<float>> rb_cCvCudaDeviceRgbToHlsTraitsFloat = define_class_under<cv::cuda::device::rgb_to_hls_traits<float>>(rb_mCvCudaDevice, "RgbToHlsTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgb_to_hls_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgb_to_hls_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_hls_full_traits<float>> rb_cCvCudaDeviceRgbToHlsFullTraitsFloat = define_class_under<cv::cuda::device::rgb_to_hls_full_traits<float>>(rb_mCvCudaDevice, "RgbToHlsFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgb_to_hls_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgb_to_hls_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_hls_traits<float>> rb_cCvCudaDeviceRgbaToHlsTraitsFloat = define_class_under<cv::cuda::device::rgba_to_hls_traits<float>>(rb_mCvCudaDevice, "RgbaToHlsTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgba_to_hls_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgba_to_hls_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_hls_full_traits<float>> rb_cCvCudaDeviceRgbaToHlsFullTraitsFloat = define_class_under<cv::cuda::device::rgba_to_hls_full_traits<float>>(rb_mCvCudaDevice, "RgbaToHlsFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgba_to_hls_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgba_to_hls_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_hls4_traits<float>> rb_cCvCudaDeviceRgbToHls4TraitsFloat = define_class_under<cv::cuda::device::rgb_to_hls4_traits<float>>(rb_mCvCudaDevice, "RgbToHls4TraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgb_to_hls4_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgb_to_hls4_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls4_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgb_to_hls4_full_traits<float>> rb_cCvCudaDeviceRgbToHls4FullTraitsFloat = define_class_under<cv::cuda::device::rgb_to_hls4_full_traits<float>>(rb_mCvCudaDevice, "RgbToHls4FullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgb_to_hls4_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgb_to_hls4_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls4_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_hls4_traits<float>> rb_cCvCudaDeviceRgbaToHls4TraitsFloat = define_class_under<cv::cuda::device::rgba_to_hls4_traits<float>>(rb_mCvCudaDevice, "RgbaToHls4TraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgba_to_hls4_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgba_to_hls4_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls4_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::rgba_to_hls4_full_traits<float>> rb_cCvCudaDeviceRgbaToHls4FullTraitsFloat = define_class_under<cv::cuda::device::rgba_to_hls4_full_traits<float>>(rb_mCvCudaDevice, "RgbaToHls4FullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::rgba_to_hls4_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::rgba_to_hls4_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls4_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_hls_traits<float>> rb_cCvCudaDeviceBgrToHlsTraitsFloat = define_class_under<cv::cuda::device::bgr_to_hls_traits<float>>(rb_mCvCudaDevice, "BgrToHlsTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgr_to_hls_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgr_to_hls_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_hls_full_traits<float>> rb_cCvCudaDeviceBgrToHlsFullTraitsFloat = define_class_under<cv::cuda::device::bgr_to_hls_full_traits<float>>(rb_mCvCudaDevice, "BgrToHlsFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgr_to_hls_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgr_to_hls_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_hls_traits<float>> rb_cCvCudaDeviceBgraToHlsTraitsFloat = define_class_under<cv::cuda::device::bgra_to_hls_traits<float>>(rb_mCvCudaDevice, "BgraToHlsTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgra_to_hls_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgra_to_hls_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_hls_full_traits<float>> rb_cCvCudaDeviceBgraToHlsFullTraitsFloat = define_class_under<cv::cuda::device::bgra_to_hls_full_traits<float>>(rb_mCvCudaDevice, "BgraToHlsFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgra_to_hls_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgra_to_hls_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_hls4_traits<float>> rb_cCvCudaDeviceBgrToHls4TraitsFloat = define_class_under<cv::cuda::device::bgr_to_hls4_traits<float>>(rb_mCvCudaDevice, "BgrToHls4TraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgr_to_hls4_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgr_to_hls4_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls4_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgr_to_hls4_full_traits<float>> rb_cCvCudaDeviceBgrToHls4FullTraitsFloat = define_class_under<cv::cuda::device::bgr_to_hls4_full_traits<float>>(rb_mCvCudaDevice, "BgrToHls4FullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgr_to_hls4_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgr_to_hls4_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls4_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_hls4_traits<float>> rb_cCvCudaDeviceBgraToHls4TraitsFloat = define_class_under<cv::cuda::device::bgra_to_hls4_traits<float>>(rb_mCvCudaDevice, "BgraToHls4TraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgra_to_hls4_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgra_to_hls4_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls4_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::bgra_to_hls4_full_traits<float>> rb_cCvCudaDeviceBgraToHls4FullTraitsFloat = define_class_under<cv::cuda::device::bgra_to_hls4_full_traits<float>>(rb_mCvCudaDevice, "BgraToHls4FullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::bgra_to_hls4_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::bgra_to_hls4_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls4_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls_to_rgb_traits<float>> rb_cCvCudaDeviceHlsToRgbTraitsFloat = define_class_under<cv::cuda::device::hls_to_rgb_traits<float>>(rb_mCvCudaDevice, "HlsToRgbTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls_to_rgb_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls_to_rgb_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgb_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls_to_rgb_full_traits<float>> rb_cCvCudaDeviceHlsToRgbFullTraitsFloat = define_class_under<cv::cuda::device::hls_to_rgb_full_traits<float>>(rb_mCvCudaDevice, "HlsToRgbFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls_to_rgb_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls_to_rgb_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgb_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls_to_rgba_traits<float>> rb_cCvCudaDeviceHlsToRgbaTraitsFloat = define_class_under<cv::cuda::device::hls_to_rgba_traits<float>>(rb_mCvCudaDevice, "HlsToRgbaTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls_to_rgba_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls_to_rgba_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgba_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls_to_rgba_full_traits<float>> rb_cCvCudaDeviceHlsToRgbaFullTraitsFloat = define_class_under<cv::cuda::device::hls_to_rgba_full_traits<float>>(rb_mCvCudaDevice, "HlsToRgbaFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls_to_rgba_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls_to_rgba_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgba_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls4_to_rgb_traits<float>> rb_cCvCudaDeviceHls4ToRgbTraitsFloat = define_class_under<cv::cuda::device::hls4_to_rgb_traits<float>>(rb_mCvCudaDevice, "Hls4ToRgbTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls4_to_rgb_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls4_to_rgb_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgb_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls4_to_rgb_full_traits<float>> rb_cCvCudaDeviceHls4ToRgbFullTraitsFloat = define_class_under<cv::cuda::device::hls4_to_rgb_full_traits<float>>(rb_mCvCudaDevice, "Hls4ToRgbFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls4_to_rgb_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls4_to_rgb_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgb_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls4_to_rgba_traits<float>> rb_cCvCudaDeviceHls4ToRgbaTraitsFloat = define_class_under<cv::cuda::device::hls4_to_rgba_traits<float>>(rb_mCvCudaDevice, "Hls4ToRgbaTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls4_to_rgba_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls4_to_rgba_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgba_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls4_to_rgba_full_traits<float>> rb_cCvCudaDeviceHls4ToRgbaFullTraitsFloat = define_class_under<cv::cuda::device::hls4_to_rgba_full_traits<float>>(rb_mCvCudaDevice, "Hls4ToRgbaFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls4_to_rgba_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls4_to_rgba_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgba_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls_to_bgr_traits<float>> rb_cCvCudaDeviceHlsToBgrTraitsFloat = define_class_under<cv::cuda::device::hls_to_bgr_traits<float>>(rb_mCvCudaDevice, "HlsToBgrTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls_to_bgr_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls_to_bgr_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgr_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls_to_bgr_full_traits<float>> rb_cCvCudaDeviceHlsToBgrFullTraitsFloat = define_class_under<cv::cuda::device::hls_to_bgr_full_traits<float>>(rb_mCvCudaDevice, "HlsToBgrFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls_to_bgr_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls_to_bgr_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgr_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls_to_bgra_traits<float>> rb_cCvCudaDeviceHlsToBgraTraitsFloat = define_class_under<cv::cuda::device::hls_to_bgra_traits<float>>(rb_mCvCudaDevice, "HlsToBgraTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls_to_bgra_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls_to_bgra_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgra_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls_to_bgra_full_traits<float>> rb_cCvCudaDeviceHlsToBgraFullTraitsFloat = define_class_under<cv::cuda::device::hls_to_bgra_full_traits<float>>(rb_mCvCudaDevice, "HlsToBgraFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls_to_bgra_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls_to_bgra_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgra_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls4_to_bgr_traits<float>> rb_cCvCudaDeviceHls4ToBgrTraitsFloat = define_class_under<cv::cuda::device::hls4_to_bgr_traits<float>>(rb_mCvCudaDevice, "Hls4ToBgrTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls4_to_bgr_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls4_to_bgr_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgr_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls4_to_bgr_full_traits<float>> rb_cCvCudaDeviceHls4ToBgrFullTraitsFloat = define_class_under<cv::cuda::device::hls4_to_bgr_full_traits<float>>(rb_mCvCudaDevice, "Hls4ToBgrFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls4_to_bgr_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls4_to_bgr_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgr_full_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls4_to_bgra_traits<float>> rb_cCvCudaDeviceHls4ToBgraTraitsFloat = define_class_under<cv::cuda::device::hls4_to_bgra_traits<float>>(rb_mCvCudaDevice, "Hls4ToBgraTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls4_to_bgra_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls4_to_bgra_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgra_traits<float>::create_functor);

  Rice::Data_Type<cv::cuda::device::hls4_to_bgra_full_traits<float>> rb_cCvCudaDeviceHls4ToBgraFullTraitsFloat = define_class_under<cv::cuda::device::hls4_to_bgra_full_traits<float>>(rb_mCvCudaDevice, "Hls4ToBgraFullTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::hls4_to_bgra_full_traits<float>>()).
    define_singleton_function<cv::cuda::device::hls4_to_bgra_full_traits::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgra_full_traits<float>::create_functor);
}