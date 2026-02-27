template<typename T>
inline Rice::Data_Type<cv::cuda::DevPtr<T>> DevPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::DevPtr<T>>(parent, name).
    define_constant("Elem_size", (int)cv::cuda::DevPtr<T>::elem_size).
    define_attr("data", &cv::cuda::DevPtr<T>::data).
    define_constructor(Constructor<cv::cuda::DevPtr<T>>()).
    define_constructor(Constructor<cv::cuda::DevPtr<T>, T*>(),
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_")).
    template define_method<size_t(cv::cuda::DevPtr<T>::*)() const>("elem_size", &cv::cuda::DevPtr<T>::elemSize).
    define_method("to_ptr", [](cv::cuda::DevPtr<T>& self) -> T*
    {
      return self;
    }).
    define_method("to_const_ptr", [](const cv::cuda::DevPtr<T>& self) -> const T*
    {
      return self;
    });
}

template<typename T>
inline Rice::Data_Type<cv::cuda::PtrSz<T>> PtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::PtrSz<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::PtrSz<T>>()).
    define_constructor(Constructor<cv::cuda::PtrSz<T>, T*, size_t>(),
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_"), Arg("size_")).
    define_attr("size", &cv::cuda::PtrSz<T>::size);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::PtrStep<T>> PtrStep_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::PtrStep<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::PtrStep<T>>()).
    define_constructor(Constructor<cv::cuda::PtrStep<T>, T*, size_t>(),
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_"), Arg("step_")).
    define_attr("step", &cv::cuda::PtrStep<T>::step).
    template define_method<T*(cv::cuda::PtrStep<T>::*)(int)>("ptr", &cv::cuda::PtrStep<T>::ptr,
      Arg("y") = static_cast<int>(0)).
    template define_method<const T*(cv::cuda::PtrStep<T>::*)(int) const>("ptr", &cv::cuda::PtrStep<T>::ptr,
      Arg("y") = static_cast<int>(0)).
    template define_method<T&(cv::cuda::PtrStep<T>::*)(int, int)>("call", &cv::cuda::PtrStep<T>::operator(),
      Arg("y"), Arg("x")).
    template define_method<const T&(cv::cuda::PtrStep<T>::*)(int, int) const>("call", &cv::cuda::PtrStep<T>::operator(),
      Arg("y"), Arg("x"));
}

template<typename T>
inline Rice::Data_Type<cv::cuda::PtrStepSz<T>> PtrStepSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::PtrStepSz<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::PtrStepSz<T>>()).
    define_constructor(Constructor<cv::cuda::PtrStepSz<T>, int, int, T*, size_t>(),
      Arg("rows_"), Arg("cols_"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_"), Arg("step_")).
    define_attr("cols", &cv::cuda::PtrStepSz<T>::cols).
    define_attr("rows", &cv::cuda::PtrStepSz<T>::rows).
    template define_method<cv::Size(cv::cuda::PtrStepSz<T>::*)() const>("size", &cv::cuda::PtrStepSz<T>::size).
    template define_method<T&(cv::cuda::PtrStepSz<T>::*)(const cv::Point&)>("call", &cv::cuda::PtrStepSz<T>::operator(),
      Arg("pos")).
    template define_method<const T&(cv::cuda::PtrStepSz<T>::*)(const cv::Point&) const>("call", &cv::cuda::PtrStepSz<T>::operator(),
      Arg("pos"));
}

