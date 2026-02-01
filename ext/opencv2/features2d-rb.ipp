
template<typename T>
inline Rice::Data_Type<cv::SL2<T>> SL2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::SL2<T>>(parent, name).
    define_constant("NormType", cv::SL2<T>::normType).
    template define_method<typename cv::SL2<T>::ResultType(cv::SL2<T>::*)(const T*, const T*, int) const>("call", &cv::SL2<T>::operator(),
      std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("a"), std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("b"), Arg("size"));
}

template<typename T>
inline Rice::Data_Type<cv::L2<T>> L2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::L2<T>>(parent, name).
    define_constant("NormType", cv::L2<T>::normType).
    template define_method<typename cv::L2<T>::ResultType(cv::L2<T>::*)(const T*, const T*, int) const>("call", &cv::L2<T>::operator(),
      std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("a"), std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("b"), Arg("size"));
}

template<typename T>
inline Rice::Data_Type<cv::L1<T>> L1_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::L1<T>>(parent, name).
    define_constant("NormType", cv::L1<T>::normType).
    template define_method<typename cv::L1<T>::ResultType(cv::L1<T>::*)(const T*, const T*, int) const>("call", &cv::L1<T>::operator(),
      std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("a"), std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("b"), Arg("size"));
}

