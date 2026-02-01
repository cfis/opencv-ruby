template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::ResizePtr<SrcPtr>> ResizePtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ResizePtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::ResizePtr<SrcPtr>::src).
    define_attr("fx", &cv::cudev::ResizePtr<SrcPtr>::fx).
    define_attr("fy", &cv::cudev::ResizePtr<SrcPtr>::fy).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::ResizePtr<SrcPtr>::*)(typename PtrTraits<SrcPtr>::index_type, typename PtrTraits<SrcPtr>::index_type) const>("call", &cv::cudev::ResizePtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::ResizePtrSz<SrcPtr>> ResizePtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ResizePtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::ResizePtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::ResizePtrSz<SrcPtr>::cols);
}

