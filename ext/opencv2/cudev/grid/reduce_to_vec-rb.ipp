template<typename T>
inline Rice::Data_Type<cv::cudev::Sum<T>> Sum_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Sum<T>>(parent, name).
    template define_singleton_function<T(*)()>("initial_value", &cv::cudev::Sum<T>::initialValue).
    template define_singleton_function<T(*)(T, int)>("result", &cv::cudev::Sum<T>::result,
      Arg("r"), Arg("arg_1"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::Avg<T>> Avg_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Avg<T>>(parent, name).
    template define_singleton_function<T(*)()>("initial_value", &cv::cudev::Avg<T>::initialValue).
    template define_singleton_function<T(*)(T, float)>("result", &cv::cudev::Avg<T>::result,
      Arg("r"), Arg("sz"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::Min<T>> Min_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Min<T>>(parent, name).
    template define_singleton_function<T(*)()>("initial_value", &cv::cudev::Min<T>::initialValue).
    template define_singleton_function<T(*)(T, int)>("result", &cv::cudev::Min<T>::result,
      Arg("r"), Arg("arg_1"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::Max<T>> Max_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Max<T>>(parent, name).
    template define_singleton_function<T(*)()>("initial_value", &cv::cudev::Max<T>::initialValue).
    template define_singleton_function<T(*)(T, int)>("result", &cv::cudev::Max<T>::result,
      Arg("r"), Arg("arg_1"));
}

