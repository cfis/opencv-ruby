template<typename T>
inline Rice::Data_Type<cv::cudev::GlobPtr<T>> GlobPtr_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::GlobPtr<T>>(parent, name).
    define_attr("data", &cv::cudev::GlobPtr<T>::data).
    define_attr("step", &cv::cudev::GlobPtr<T>::step).
    template define_method<T*(cv::cudev::GlobPtr<T>::*)(int)>("row", &cv::cudev::GlobPtr<T>::row,
      Arg("y")).
    template define_method<const T*(cv::cudev::GlobPtr<T>::*)(int) const>("row", &cv::cudev::GlobPtr<T>::row,
      Arg("y")).
    template define_method<T&(cv::cudev::GlobPtr<T>::*)(int, int)>("call", &cv::cudev::GlobPtr<T>::operator(),
      Arg("y"), Arg("x")).
    template define_method<const T&(cv::cudev::GlobPtr<T>::*)(int, int) const>("call", &cv::cudev::GlobPtr<T>::operator(),
      Arg("y"), Arg("x"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::GlobPtrSz<T>> GlobPtrSz_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::GlobPtrSz<T>>(parent, name).
    define_attr("rows", &cv::cudev::GlobPtrSz<T>::rows).
    define_attr("cols", &cv::cudev::GlobPtrSz<T>::cols);
}

