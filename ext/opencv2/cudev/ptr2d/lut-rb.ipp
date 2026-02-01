template<typename SrcPtr, typename TablePtr>
inline Rice::Data_Type<cv::cudev::LutPtr<SrcPtr, TablePtr>> LutPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::LutPtr<SrcPtr, TablePtr>>(parent, name).
    define_attr("src", &cv::cudev::LutPtr<SrcPtr, TablePtr>::src).
    define_attr("tbl", &cv::cudev::LutPtr<SrcPtr, TablePtr>::tbl).
    template define_method<typename PtrTraits<TablePtr>::value_type(cv::cudev::LutPtr<SrcPtr, TablePtr>::*)(typename PtrTraits<SrcPtr>::index_type, typename PtrTraits<SrcPtr>::index_type) const>("call", &cv::cudev::LutPtr<SrcPtr, TablePtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr, typename TablePtr>
inline Rice::Data_Type<cv::cudev::LutPtrSz<SrcPtr, TablePtr>> LutPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::LutPtrSz<SrcPtr, TablePtr>>(parent, name).
    define_attr("rows", &cv::cudev::LutPtrSz<SrcPtr, TablePtr>::rows).
    define_attr("cols", &cv::cudev::LutPtrSz<SrcPtr, TablePtr>::cols);
}

