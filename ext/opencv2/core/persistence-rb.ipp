template<typename _Tp, int numflag>
inline Rice::Data_Type<cv::internal::VecWriterProxy<_Tp, numflag>> VecWriterProxy_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::internal::VecWriterProxy<_Tp, numflag>>(parent, name).
    define_constructor(Constructor<cv::internal::VecWriterProxy<_Tp, numflag>, cv::FileStorage*>(),
      Arg("_fs")).
    template define_method<void(cv::internal::VecWriterProxy<_Tp, numflag>::*)(const std::vector<_Tp>&) const>("call", &cv::internal::VecWriterProxy<_Tp, numflag>::operator(),
      Arg("vec"));
}

template<typename _Tp, int numflag>
inline Rice::Data_Type<cv::internal::VecReaderProxy<_Tp, numflag>> VecReaderProxy_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::internal::VecReaderProxy<_Tp, numflag>>(parent, name).
    define_constructor(Constructor<cv::internal::VecReaderProxy<_Tp, numflag>, cv::FileNodeIterator*>(),
      Arg("_it")).
    template define_method<void(cv::internal::VecReaderProxy<_Tp, numflag>::*)(std::vector<_Tp>&, size_t) const>("call", &cv::internal::VecReaderProxy<_Tp, numflag>::operator(),
      Arg("vec"), Arg("count"));
}

