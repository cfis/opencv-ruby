template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::DerivXPtr<SrcPtr>> DerivXPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::DerivXPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::DerivXPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::DerivXPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::DerivXPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::DerivXPtrSz<SrcPtr>> DerivXPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::DerivXPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::DerivXPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::DerivXPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::DerivYPtr<SrcPtr>> DerivYPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::DerivYPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::DerivYPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::DerivYPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::DerivYPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::DerivYPtrSz<SrcPtr>> DerivYPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::DerivYPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::DerivYPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::DerivYPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::SobelXPtr<SrcPtr>> SobelXPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::SobelXPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::SobelXPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::SobelXPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::SobelXPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::SobelXPtrSz<SrcPtr>> SobelXPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::SobelXPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::SobelXPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::SobelXPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::SobelYPtr<SrcPtr>> SobelYPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::SobelYPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::SobelYPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::SobelYPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::SobelYPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::SobelYPtrSz<SrcPtr>> SobelYPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::SobelYPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::SobelYPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::SobelYPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::ScharrXPtr<SrcPtr>> ScharrXPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ScharrXPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::ScharrXPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::ScharrXPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::ScharrXPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::ScharrXPtrSz<SrcPtr>> ScharrXPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ScharrXPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::ScharrXPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::ScharrXPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::ScharrYPtr<SrcPtr>> ScharrYPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ScharrYPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::ScharrYPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::ScharrYPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::ScharrYPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::ScharrYPtrSz<SrcPtr>> ScharrYPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ScharrYPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::ScharrYPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::ScharrYPtrSz<SrcPtr>::cols);
}

template<int ksize, typename SrcPtr>
inline Rice::Data_Type<cv::cudev::LaplacianPtrSz<ksize, SrcPtr>> LaplacianPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::LaplacianPtrSz<ksize, SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::LaplacianPtrSz<ksize, SrcPtr>::rows).
    define_attr("cols", &cv::cudev::LaplacianPtrSz<ksize, SrcPtr>::cols);
}

