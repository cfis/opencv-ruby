template<typename src_type, typename work_type>
inline Rice::Data_Type<cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>> SumReductor_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>>(parent, name).
    define_constant("Cn", (int)cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>::cn).
    define_attr("sum", &cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>::sum).
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>>()).
    template define_method<void(cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>::*)(typename TypeTraits<src_type>::parameter_type)>("reduce_val", &cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>::reduceVal,
      Arg("src_val"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::grid_reduce_detail::minop<T>> minop_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::grid_reduce_detail::minop<T>>(parent, name).
    template define_singleton_function<T(*)()>("initial", &cv::cudev::grid_reduce_detail::minop<T>::initial).
    template define_singleton_function<void(*)(T*, T)>("atomic", &cv::cudev::grid_reduce_detail::minop<T>::atomic,
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("result"), Arg("myval"));
}

template<typename T>
inline Rice::Data_Type<cv::cudev::grid_reduce_detail::maxop<T>> maxop_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::grid_reduce_detail::maxop<T>>(parent, name).
    template define_singleton_function<T(*)()>("initial", &cv::cudev::grid_reduce_detail::maxop<T>::initial).
    template define_singleton_function<void(*)(T*, T)>("atomic", &cv::cudev::grid_reduce_detail::maxop<T>::atomic,
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("result"), Arg("myval"));
}

template<typename Op, typename src_type, typename work_type>
inline Rice::Data_Type<cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>> MinMaxReductor_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>>(parent, name).
    define_attr("myval", &cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>::myval).
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>>()).
    template define_method<void(cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>::*)(typename TypeTraits<src_type>::parameter_type)>("reduce_val", &cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>::reduceVal,
      Arg("src_val"));
}

