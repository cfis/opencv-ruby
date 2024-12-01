#include <opencv2/core/cuda/vec_traits.hpp>
#include "vec_traits-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceDouble8;
Rice::Class rb_cCvCudaDeviceTypeVecBool1;
Rice::Class rb_cCvCudaDeviceTypeVecBool2;
Rice::Class rb_cCvCudaDeviceTypeVecBool3;
Rice::Class rb_cCvCudaDeviceTypeVecBool4;
Rice::Class rb_cCvCudaDeviceTypeVecBool8;
Rice::Class rb_cCvCudaDeviceTypeVecSchar1;
Rice::Class rb_cCvCudaDeviceTypeVecSchar2;
Rice::Class rb_cCvCudaDeviceTypeVecSchar3;
Rice::Class rb_cCvCudaDeviceTypeVecSchar4;
Rice::Class rb_cCvCudaDeviceTypeVecSchar8;
Rice::Class rb_cCvCudaDeviceVecTraitsChar;
Rice::Class rb_cCvCudaDeviceVecTraitsSchar;

void Init_VecTraits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_cCvCudaDeviceDouble8 = define_class_under<cv::cuda::device::double8>(rb_mCvCudaDevice, "Double8").
    define_constructor(Constructor<cv::cuda::device::double8>()).
    define_attr("a0", &cv::cuda::device::double8::a0).
    define_attr("a1", &cv::cuda::device::double8::a1).
    define_attr("a2", &cv::cuda::device::double8::a2).
    define_attr("a3", &cv::cuda::device::double8::a3).
    define_attr("a4", &cv::cuda::device::double8::a4).
    define_attr("a5", &cv::cuda::device::double8::a5).
    define_attr("a6", &cv::cuda::device::double8::a6).
    define_attr("a7", &cv::cuda::device::double8::a7);
  
  rb_cCvCudaDeviceTypeVecSchar1 = define_class_under<cv::cuda::device::TypeVec<schar, 1>>(rb_mCvCudaDevice, "TypeVecSchar1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 1>>());
  
  rb_cCvCudaDeviceTypeVecSchar2 = define_class_under<cv::cuda::device::TypeVec<schar, 2>>(rb_mCvCudaDevice, "TypeVecSchar2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 2>>());
  
  rb_cCvCudaDeviceTypeVecSchar3 = define_class_under<cv::cuda::device::TypeVec<schar, 3>>(rb_mCvCudaDevice, "TypeVecSchar3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 3>>());
  
  rb_cCvCudaDeviceTypeVecSchar4 = define_class_under<cv::cuda::device::TypeVec<schar, 4>>(rb_mCvCudaDevice, "TypeVecSchar4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 4>>());
  
  rb_cCvCudaDeviceTypeVecSchar8 = define_class_under<cv::cuda::device::TypeVec<schar, 8>>(rb_mCvCudaDevice, "TypeVecSchar8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 8>>());
  
  rb_cCvCudaDeviceTypeVecBool1 = define_class_under<cv::cuda::device::TypeVec<bool, 1>>(rb_mCvCudaDevice, "TypeVecBool1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 1>>());
  
  rb_cCvCudaDeviceTypeVecBool2 = define_class_under<cv::cuda::device::TypeVec<bool, 2>>(rb_mCvCudaDevice, "TypeVecBool2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 2>>());
  
  rb_cCvCudaDeviceTypeVecBool3 = define_class_under<cv::cuda::device::TypeVec<bool, 3>>(rb_mCvCudaDevice, "TypeVecBool3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 3>>());
  
  rb_cCvCudaDeviceTypeVecBool4 = define_class_under<cv::cuda::device::TypeVec<bool, 4>>(rb_mCvCudaDevice, "TypeVecBool4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 4>>());
  
  rb_cCvCudaDeviceTypeVecBool8 = define_class_under<cv::cuda::device::TypeVec<bool, 8>>(rb_mCvCudaDevice, "TypeVecBool8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 8>>());
  
  rb_cCvCudaDeviceVecTraitsChar = define_class_under<cv::cuda::device::VecTraits<char>>(rb_mCvCudaDevice, "VecTraitsChar").
    define_constructor(Constructor<cv::cuda::device::VecTraits<char>>());
  
  rb_cCvCudaDeviceVecTraitsChar.define_constant("Cn", (int)cv::cuda::device::VecTraits<char>::cn);
  
  rb_cCvCudaDeviceVecTraitsSchar = define_class_under<cv::cuda::device::VecTraits<schar>>(rb_mCvCudaDevice, "VecTraitsSchar").
    define_constructor(Constructor<cv::cuda::device::VecTraits<schar>>());
  
  rb_cCvCudaDeviceVecTraitsSchar.define_constant("Cn", (int)cv::cuda::device::VecTraits<schar>::cn);

}