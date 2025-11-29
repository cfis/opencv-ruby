#include <opencv2/core/cuda/detail/type_traits_detail.hpp>
#include "type_traits_detail-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceTypeTraitsDetailAddParameterTypeVoid;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsFloatDouble;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsFloatFloat;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsIntegralBool;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsIntegralChar;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralSchar;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort;
Rice::Class rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble8;

template<typename Data_Type_T, bool , typename T1, typename T2>
inline void Select_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void IsSignedIntergral_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<T>::value);
};

template<typename Data_Type_T, typename T>
inline void IsUnsignedIntegral_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<T>::value);
};

template<typename Data_Type_T, typename T>
inline void IsIntegral_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsIntegral<T>::value);
};

template<typename Data_Type_T, typename T>
inline void IsFloat_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsFloat<T>::value);
};

template<typename Data_Type_T, typename T>
inline void IsVec_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<T>::value);
};

template<typename Data_Type_T, typename U>
inline void AddParameterType_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename U>
inline void ReferenceTraits_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::ReferenceTraits<U>::value);
};

template<typename Data_Type_T, typename U>
inline void PointerTraits_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::PointerTraits<U>::value);
};

template<typename Data_Type_T, typename U>
inline void UnConst_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::UnConst<U>::value);
};

template<typename Data_Type_T, typename U>
inline void UnVolatile_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::UnVolatile<U>::value);
};
void Init_TypeTraitsDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceTypeTraitsDetail = define_module_under(rb_mCvCudaDevice, "TypeTraitsDetail");
  
  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralSchar = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralSchar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralSchar.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<short>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralShort").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<short>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<short>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<int>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralInt").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<int>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<int>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUchar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUshort").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUint").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsIntegralChar = define_class_under<cv::cuda::device::type_traits_detail::IsIntegral<char>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsIntegralChar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsIntegral<char>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsIntegralChar.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsIntegral<char>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsIntegralBool = define_class_under<cv::cuda::device::type_traits_detail::IsIntegral<bool>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsIntegralBool").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsIntegral<bool>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsIntegralBool.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsIntegral<bool>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsFloatFloat = define_class_under<cv::cuda::device::type_traits_detail::IsFloat<float>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsFloatFloat").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsFloat<float>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsFloatFloat.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsFloat<float>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsFloatDouble = define_class_under<cv::cuda::device::type_traits_detail::IsFloat<double>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsFloatDouble").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsFloat<double>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsFloatDouble.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsFloat<double>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::double8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::double8>>());
  
  rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<double8>::value);
  
  rb_cCvCudaDeviceTypeTraitsDetailAddParameterTypeVoid = define_class_under<cv::cuda::device::type_traits_detail::AddParameterType<void>>(rb_mCvCudaDeviceTypeTraitsDetail, "AddParameterTypeVoid").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::AddParameterType<void>>());

}