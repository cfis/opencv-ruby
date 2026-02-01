template<typename C, typename Ret, typename Args>
inline Rice::Data_Type<cv::sfinae::has_parenthesis_operator<C, Ret, Args>> has_parenthesis_operator_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::sfinae::has_parenthesis_operator<C, Ret, Args>>(parent, name).
    define_constant("Value", cv::sfinae::has_parenthesis_operator<C, Ret, Args>::value);
}

template<typename T>
inline Rice::Data_Type<cv::Ptr<T>> Ptr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Ptr<T>>(parent, name).
    define_constructor(Constructor<cv::Ptr<T>>()).
    define_constructor(Constructor<cv::Ptr<T>, nullptr_t>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::Ptr<T>, const cv::Ptr<T>&>(),
      Arg("o")).
    define_constructor(Constructor<cv::Ptr<T>, const std::shared_ptr<T>&>(),
      Arg("o")).
    define_constructor(Constructor<cv::Ptr<T>, std::shared_ptr<T>&&>(),
      Arg("o")).
    template define_method<void(cv::Ptr<T>::*)() noexcept>("reset", &cv::Ptr<T>::reset).
    template define_method<cv::Ptr<T>&(cv::Ptr<T>::*)(const cv::Ptr<T>&)>("assign", &cv::Ptr<T>::operator=,
      Arg("o")).
    template define_method<T*(cv::Ptr<T>::*)() const noexcept>("arrow", &cv::Ptr<T>::operator->).
    template define_method<typename std::add_lvalue_reference<T>::type(cv::Ptr<T>::*)() const noexcept>("dereference", &cv::Ptr<T>::operator*).
    template define_method<void(cv::Ptr<T>::*)()>("release", &cv::Ptr<T>::release).
    define_method("to_const_ptr", [](const cv::Ptr<T>& self) -> T*
    {
      return self;
    }).
    template define_method<bool(cv::Ptr<T>::*)() const>("empty?", &cv::Ptr<T>::empty);
}

