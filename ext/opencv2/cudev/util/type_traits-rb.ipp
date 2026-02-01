template<int A>
inline Rice::Data_Type<cv::cudev::Int2Type<A>> Int2Type_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Int2Type<A>>(parent, name).
    define_constant("Value", (int)cv::cudev::Int2Type<A>::value);
}

template<typename T, int COUNT>
inline Rice::Data_Type<cv::cudev::ArrayWrapper<T, COUNT>> ArrayWrapper_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ArrayWrapper<T, COUNT>>(parent, name).
    define_attr("array", &cv::cudev::ArrayWrapper<T, COUNT>::array, Rice::AttrAccess::Read);
}

template<int N, int CURRENT_VAL, int COUNT>
inline Rice::Data_Type<cv::cudev::Log2<N, CURRENT_VAL, COUNT>> Log2_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Log2<N, CURRENT_VAL, COUNT>>(parent, name).
    define_constant("Value", (int)cv::cudev::Log2<N, CURRENT_VAL, COUNT>::value);
}

template<int N>
inline Rice::Data_Type<cv::cudev::IsPowerOf2<N>> IsPowerOf2_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::IsPowerOf2<N>>(parent, name).
    define_constant("Value", (int)cv::cudev::IsPowerOf2<N>::value);
}

template<typename A, typename B>
inline Rice::Data_Type<cv::cudev::TypesEquals<A, B>> TypesEquals_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::TypesEquals<A, B>>(parent, name).
    define_constant("Value", (int)cv::cudev::TypesEquals<A, B>::value);
}

template<typename T>
inline Rice::Data_Type<cv::cudev::TypeTraits<T>> TypeTraits_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::TypeTraits<T>>(parent, name).
    define_constant("Is_const", (int)cv::cudev::TypeTraits<T>::is_const).
    define_constant("Is_volatile", (int)cv::cudev::TypeTraits<T>::is_volatile).
    define_constant("Is_reference", (int)cv::cudev::TypeTraits<T>::is_reference).
    define_constant("Is_pointer", (int)cv::cudev::TypeTraits<T>::is_pointer).
    define_constant("Is_unsigned_int", (int)cv::cudev::TypeTraits<T>::is_unsigned_int).
    define_constant("Is_signed_int", (int)cv::cudev::TypeTraits<T>::is_signed_int).
    define_constant("Is_integral", (int)cv::cudev::TypeTraits<T>::is_integral).
    define_constant("Is_float", (int)cv::cudev::TypeTraits<T>::is_float).
    define_constant("Is_scalar", (int)cv::cudev::TypeTraits<T>::is_scalar).
    define_constant("Is_vec", (int)cv::cudev::TypeTraits<T>::is_vec);
}

