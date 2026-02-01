template<typename SrcPtr, typename MapPtr>
inline Rice::Data_Type<cv::cudev::RemapPtr1<SrcPtr, MapPtr>> RemapPtr1_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::RemapPtr1<SrcPtr, MapPtr>>(parent, name).
    define_attr("src", &cv::cudev::RemapPtr1<SrcPtr, MapPtr>::src).
    define_attr("map", &cv::cudev::RemapPtr1<SrcPtr, MapPtr>::map).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::RemapPtr1<SrcPtr, MapPtr>::*)(typename PtrTraits<MapPtr>::index_type, typename PtrTraits<MapPtr>::index_type) const>("call", &cv::cudev::RemapPtr1<SrcPtr, MapPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr, typename MapXPtr, typename MapYPtr>
inline Rice::Data_Type<cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>> RemapPtr2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>>(parent, name).
    define_attr("src", &cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::src).
    define_attr("mapx", &cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::mapx).
    define_attr("mapy", &cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::mapy).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::*)(typename PtrTraits<MapXPtr>::index_type, typename PtrTraits<MapXPtr>::index_type) const>("call", &cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr, typename MapPtr>
inline Rice::Data_Type<cv::cudev::RemapPtr1Sz<SrcPtr, MapPtr>> RemapPtr1Sz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::RemapPtr1Sz<SrcPtr, MapPtr>>(parent, name).
    define_attr("rows", &cv::cudev::RemapPtr1Sz<SrcPtr, MapPtr>::rows).
    define_attr("cols", &cv::cudev::RemapPtr1Sz<SrcPtr, MapPtr>::cols);
}

template<typename SrcPtr, typename MapXPtr, typename MapYPtr>
inline Rice::Data_Type<cv::cudev::RemapPtr2Sz<SrcPtr, MapXPtr, MapYPtr>> RemapPtr2Sz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::RemapPtr2Sz<SrcPtr, MapXPtr, MapYPtr>>(parent, name).
    define_attr("rows", &cv::cudev::RemapPtr2Sz<SrcPtr, MapXPtr, MapYPtr>::rows).
    define_attr("cols", &cv::cudev::RemapPtr2Sz<SrcPtr, MapXPtr, MapYPtr>::cols);
}

