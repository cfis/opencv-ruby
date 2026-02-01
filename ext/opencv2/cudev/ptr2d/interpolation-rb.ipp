template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::NearestInterPtr<SrcPtr>> NearestInterPtr_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::NearestInterPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::NearestInterPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::NearestInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::NearestInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::NearestInterPtrSz<SrcPtr>> NearestInterPtrSz_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::NearestInterPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::NearestInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::NearestInterPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::LinearInterPtr<SrcPtr>> LinearInterPtr_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::LinearInterPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::LinearInterPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::LinearInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::LinearInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::LinearInterPtrSz<SrcPtr>> LinearInterPtrSz_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::LinearInterPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::LinearInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::LinearInterPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::CubicInterPtr<SrcPtr>> CubicInterPtr_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::CubicInterPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::CubicInterPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::CubicInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::CubicInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x")).
    template define_singleton_function<float(*)(float)>("bicubic_coeff", &cv::cudev::CubicInterPtr<SrcPtr>::bicubicCoeff,
      Arg("x_"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::CubicInterPtrSz<SrcPtr>> CubicInterPtrSz_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::CubicInterPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::CubicInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::CubicInterPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::IntegerAreaInterPtr<SrcPtr>> IntegerAreaInterPtr_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::IntegerAreaInterPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::IntegerAreaInterPtr<SrcPtr>::src).
    define_attr("area_width", &cv::cudev::IntegerAreaInterPtr<SrcPtr>::area_width).
    define_attr("area_height", &cv::cudev::IntegerAreaInterPtr<SrcPtr>::area_height).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::IntegerAreaInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::IntegerAreaInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::IntegerAreaInterPtrSz<SrcPtr>> IntegerAreaInterPtrSz_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::IntegerAreaInterPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::IntegerAreaInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::IntegerAreaInterPtrSz<SrcPtr>::cols);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::CommonAreaInterPtr<SrcPtr>> CommonAreaInterPtr_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::CommonAreaInterPtr<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::CommonAreaInterPtr<SrcPtr>::src).
    define_attr("area_width", &cv::cudev::CommonAreaInterPtr<SrcPtr>::area_width).
    define_attr("area_height", &cv::cudev::CommonAreaInterPtr<SrcPtr>::area_height).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::CommonAreaInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::CommonAreaInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::CommonAreaInterPtrSz<SrcPtr>> CommonAreaInterPtrSz_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::CommonAreaInterPtrSz<SrcPtr>>(parent, name).
    define_attr("rows", &cv::cudev::CommonAreaInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::CommonAreaInterPtrSz<SrcPtr>::cols);
}

