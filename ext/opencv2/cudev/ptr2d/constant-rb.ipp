template<typename T>
inline Rice::Data_Type<cv::cudev::ConstantPtr<T>> ConstantPtr_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ConstantPtr<T>>(parent, name).
    define_attr("value", &cv::cudev::ConstantPtr<T>::value).
    template define_method<T(cv::cudev::ConstantPtr<T>::*)(int, int) const>("call", &cv::cudev::ConstantPtr<T>::operator(),
      Arg("arg_0"), Arg("arg_1"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::ConstantPtrSz<T>> ConstantPtrSz_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ConstantPtrSz<T>>(parent, name).
    define_attr("rows", &cv::cudev::ConstantPtrSz<T>::rows).
    define_attr("cols", &cv::cudev::ConstantPtrSz<T>::cols);
}

