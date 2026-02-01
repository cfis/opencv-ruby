template<typename T>
inline Rice::Data_Type<cvflann::Matrix<T>> Matrix_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::Matrix<T>>(parent, name).
    define_attr("rows", &cvflann::Matrix<T>::rows).
    define_attr("cols", &cvflann::Matrix<T>::cols).
    define_attr("stride", &cvflann::Matrix<T>::stride).
    define_attr("data", &cvflann::Matrix<T>::data).
    define_constructor(Constructor<cvflann::Matrix<T>>()).
    define_constructor(Constructor<cvflann::Matrix<T>, T*, size_t, size_t, size_t>(),
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_"), Arg("rows_"), Arg("cols_"), Arg("stride_") = static_cast<size_t>(0)).
    template define_method<T*(cvflann::Matrix<T>::*)(size_t) const>("[]", &cvflann::Matrix<T>::operator[],
      Arg("index"));
}

