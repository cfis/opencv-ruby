#include <opencv2/core/hal/intrin.hpp>
#include "intrin-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, typename _Tp>
inline void V_TypeTraits_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename _Tp>
inline void V_RegTraits_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void VTraits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function("vlanes", &cv::hal_baseline::simd128_cpp::VTraits<T>::vlanes).
    define_constant("Nlanes", (int)cv::hal_baseline::simd128_cpp::VTraits<T>::nlanes).
    define_constant("Max_nlanes", (int)cv::hal_baseline::simd128_cpp::VTraits<T>::max_nlanes);
};
void Init_Intrin()
{
  Class(rb_cObject).define_constant("CV__SIMD_FORWARD", CV__SIMD_FORWARD);
  
  Class(rb_cObject).define_constant("CV_SIMD128_CPP", CV_SIMD128_CPP);
  
  Class(rb_cObject).define_constant("CV_SIMD256", CV_SIMD256);
  
  Class(rb_cObject).define_constant("CV_SIMD256_64F", CV_SIMD256_64F);
  
  Class(rb_cObject).define_constant("CV_SIMD512", CV_SIMD512);
  
  Class(rb_cObject).define_constant("CV_SIMD512_64F", CV_SIMD512_64F);
  
  Class(rb_cObject).define_constant("CV_SIMD256_FP16", CV_SIMD256_FP16);
  
  Class(rb_cObject).define_constant("CV_SIMD512_FP16", CV_SIMD512_FP16);
  
  Class(rb_cObject).define_constant("CV_SIMD_SCALABLE", CV_SIMD_SCALABLE);
  
  Class(rb_cObject).define_constant("CV_SIMD_SCALABLE_64F", CV_SIMD_SCALABLE_64F);
  
  Class(rb_cObject).define_constant("CV_SIMD_WIDTH", CV_SIMD_WIDTH);
  
  Class(rb_cObject).define_constant("CV_SIMD_FP16", CV_SIMD_FP16);
  
  Module rb_mAnonymous = define_module("Anonymous");
  
  rb_mAnonymous.define_module_function("trailing_zeros32", &::trailingZeros32,
    Arg("value"));
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvHal = define_module_under(rb_mCv, "Hal");
  
  Enum<cv::hal::StoreMode> rb_cCvHalStoreMode = define_enum_under<cv::hal::StoreMode>("StoreMode", rb_mCvHal).
    define_value("STORE_UNALIGNED", cv::hal::StoreMode::STORE_UNALIGNED).
    define_value("STORE_ALIGNED", cv::hal::StoreMode::STORE_ALIGNED).
    define_value("STORE_ALIGNED_NOCACHE", cv::hal::StoreMode::STORE_ALIGNED_NOCACHE);
  

}