#include <opencv2/core/cuda/type_traits.hpp>
#include "type_traits-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, typename T>
inline void IsSimpleParameter_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::IsSimpleParameter<T>::value);
};

template<typename Data_Type_T, typename T>
inline void TypeTraits_builder(Data_Type_T& klass)
{
  klass.define_constant("IsConst", (int)cv::cuda::device::TypeTraits<T>::isConst).
    define_constant("IsVolatile", (int)cv::cuda::device::TypeTraits<T>::isVolatile).
    define_constant("IsReference", (int)cv::cuda::device::TypeTraits<T>::isReference).
    define_constant("IsPointer", (int)cv::cuda::device::TypeTraits<T>::isPointer).
    define_constant("IsUnsignedInt", (int)cv::cuda::device::TypeTraits<T>::isUnsignedInt).
    define_constant("IsSignedInt", (int)cv::cuda::device::TypeTraits<T>::isSignedInt).
    define_constant("IsIntegral", (int)cv::cuda::device::TypeTraits<T>::isIntegral).
    define_constant("IsFloat", (int)cv::cuda::device::TypeTraits<T>::isFloat).
    define_constant("IsArith", (int)cv::cuda::device::TypeTraits<T>::isArith).
    define_constant("IsVec", (int)cv::cuda::device::TypeTraits<T>::isVec);
};
void Init_TypeTraits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  

}