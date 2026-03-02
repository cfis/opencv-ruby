template<typename _Tp>
inline Rice::Data_Type<cv::DataType<_Tp>> DataType_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::DataType<_Tp>>(parent, name);
}

template<typename _Tp>
inline Rice::Data_Type<cv::DataDepth<_Tp>> DataDepth_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::DataDepth<_Tp>>(parent, name)
    .define_constant("Value", (int)cv::DataDepth<_Tp>::value)
    .define_constant("Fmt", (int)cv::DataDepth<_Tp>::fmt);
}

template<typename T>
inline Rice::Data_Type<cv::traits::internal::CheckMember_fmt<T>> CheckMember_fmt_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::traits::internal::CheckMember_fmt<T>>(parent, name)
    .define_constant("Value", (int)cv::traits::internal::CheckMember_fmt<T>::value);
}

template<typename T>
inline Rice::Data_Type<cv::traits::internal::CheckMember_type<T>> CheckMember_type_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::traits::internal::CheckMember_type<T>>(parent, name)
    .define_constant("Value", (int)cv::traits::internal::CheckMember_type<T>::value);
}

template<typename T>
inline Rice::Data_Type<cv::traits::Depth<T>> Depth_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::traits::Depth<T>>(parent, name)
    .define_constant("Value", (int)cv::traits::Depth<T>::value);
}

template<typename T>
inline Rice::Data_Type<cv::traits::Type<T>> Type_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::traits::Type<T>>(parent, name)
    .define_constant("Value", (int)cv::traits::Type<T>::value);
}

template<typename T, bool available>
inline Rice::Data_Type<cv::traits::SafeType<T, available>> SafeType_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::traits::SafeType<T, available>>(parent, name);
}

template<typename T, bool available>
inline Rice::Data_Type<cv::traits::SafeFmt<T, available>> SafeFmt_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::traits::SafeFmt<T, available>>(parent, name);
}

