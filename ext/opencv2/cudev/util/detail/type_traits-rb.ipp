template<typename T>
inline Rice::Data_Type<cv::cudev::type_traits_detail::IsSignedIntergral<T>> IsSignedIntergral_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::IsSignedIntergral<T>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::IsSignedIntergral<T>::value);
}

template<typename T>
inline Rice::Data_Type<cv::cudev::type_traits_detail::IsUnsignedIntegral<T>> IsUnsignedIntegral_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::IsUnsignedIntegral<T>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::IsUnsignedIntegral<T>::value);
}

template<typename T>
inline Rice::Data_Type<cv::cudev::type_traits_detail::IsIntegral<T>> IsIntegral_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::IsIntegral<T>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::IsIntegral<T>::value);
}

template<typename T>
inline Rice::Data_Type<cv::cudev::type_traits_detail::IsFloat<T>> IsFloat_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::IsFloat<T>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::IsFloat<T>::value);
}

template<typename T>
inline Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<T>> IsVec_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::IsVec<T>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<T>::value);
}

template<typename U>
inline Rice::Data_Type<cv::cudev::type_traits_detail::ReferenceTraits<U>> ReferenceTraits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::ReferenceTraits<U>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::ReferenceTraits<U>::value);
}

template<typename U>
inline Rice::Data_Type<cv::cudev::type_traits_detail::PointerTraits<U>> PointerTraits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::PointerTraits<U>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::PointerTraits<U>::value);
}

template<typename U>
inline Rice::Data_Type<cv::cudev::type_traits_detail::UnConst<U>> UnConst_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::UnConst<U>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::UnConst<U>::value);
}

template<typename U>
inline Rice::Data_Type<cv::cudev::type_traits_detail::UnVolatile<U>> UnVolatile_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::UnVolatile<U>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::UnVolatile<U>::value);
}

template<typename T>
inline Rice::Data_Type<cv::cudev::type_traits_detail::IsSimpleParameter<T>> IsSimpleParameter_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::type_traits_detail::IsSimpleParameter<T>>(parent, name).
    define_constant("Value", (int)cv::cudev::type_traits_detail::IsSimpleParameter<T>::value);
}

