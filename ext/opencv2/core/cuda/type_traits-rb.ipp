template<typename T>
inline Rice::Data_Type<cv::cuda::device::IsSimpleParameter<T>> IsSimpleParameter_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::IsSimpleParameter<T>>(parent, name).
    define_constant("Value", (int)cv::cuda::device::IsSimpleParameter<T>::value);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::TypeTraits<T>> TypeTraits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::TypeTraits<T>>(parent, name).
    define_constant("IsConst", (int)cv::cuda::device::TypeTraits<T>::isConst).
    define_constant("IsVolatile", (int)cv::cuda::device::TypeTraits<T>::isVolatile).
    define_constant("IsReference", (int)cv::cuda::device::TypeTraits<T>::isReference).
    define_constant("IsPointer", (int)cv::cuda::device::TypeTraits<T>::isPointer).
    define_constant("IsUnsignedInt", (int)cv::cuda::device::TypeTraits<T>::isUnsignedInt).
    define_constant("IsSignedInt", (int)cv::cuda::device::TypeTraits<T>::isSignedInt).
    define_constant("IsIntegral", (int)cv::cuda::device::TypeTraits<T>::isIntegral).
    define_constant("IsFloat", (int)cv::cuda::device::TypeTraits<T>::isFloat).
    define_constant("IsArith", (int)cv::cuda::device::TypeTraits<T>::isArith).
    define_constant("IsVec", (int)cv::cuda::device::TypeTraits<T>::isVec);
}

