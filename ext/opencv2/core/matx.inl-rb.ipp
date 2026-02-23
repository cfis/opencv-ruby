template<typename _Tp, int m>
inline Rice::Data_Type<cv::internal::Matx_DetOp<_Tp, m>> Matx_DetOp_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::internal::Matx_DetOp<_Tp, m>>(parent, name).
    template define_method<double(cv::internal::Matx_DetOp<_Tp, m>::*)(const cv::Matx<_Tp, m, m>&) const>("call", &cv::internal::Matx_DetOp<_Tp, m>::operator(),
      Arg("a"));
}

template<typename _Tp, int m, int n>
inline Rice::Data_Type<cv::MatxCommaInitializer<_Tp, m, n>> MatxCommaInitializer_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::MatxCommaInitializer<_Tp, m, n>>(parent, name).
    define_constructor(Constructor<cv::MatxCommaInitializer<_Tp, m, n>, cv::Matx<_Tp, m, n>*>(),
      Arg("_mtx")).
    template define_method<cv::Matx<_Tp, m, n>(cv::MatxCommaInitializer<_Tp, m, n>::*)() const>("dereference", &cv::MatxCommaInitializer<_Tp, m, n>::operator*).
    define_attr("dst", &cv::MatxCommaInitializer<_Tp, m, n>::dst).
    define_attr("idx", &cv::MatxCommaInitializer<_Tp, m, n>::idx);
}

template<typename _Tp, int m>
inline Rice::Data_Type<cv::VecCommaInitializer<_Tp, m>> VecCommaInitializer_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::VecCommaInitializer<_Tp, m>>(parent, name).
    define_constructor(Constructor<cv::VecCommaInitializer<_Tp, m>, cv::Vec<_Tp, m>*>(),
      Arg("_vec")).
    template define_method<cv::Vec<_Tp, m>(cv::VecCommaInitializer<_Tp, m>::*)() const>("dereference", &cv::VecCommaInitializer<_Tp, m>::operator*);
}

