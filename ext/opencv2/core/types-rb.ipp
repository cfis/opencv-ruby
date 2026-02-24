template<typename _Tp>
inline Rice::Data_Type<cv::Complex<_Tp>> Complex_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Complex<_Tp>>(parent, name).
    define_constructor(Constructor<cv::Complex<_Tp>>()).
    define_constructor(Constructor<cv::Complex<_Tp>, _Tp, _Tp>(),
      Arg("_re"), Arg("_im") = static_cast<_Tp>(0)).
    template define_method<cv::Complex<_Tp>(cv::Complex<_Tp>::*)() const>("conj", &cv::Complex<_Tp>::conj).
    define_attr("re", &cv::Complex<_Tp>::re).
    define_attr("im", &cv::Complex<_Tp>::im);
}

template<typename _Tp>
inline Rice::Data_Type<cv::Point_<_Tp>> Point__instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Point_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::Point_<_Tp>>()).
    define_constructor(Constructor<cv::Point_<_Tp>, _Tp, _Tp>(),
      Arg("_x"), Arg("_y")).
    define_constructor(Constructor<cv::Point_<_Tp>, const cv::Point_<_Tp>&>(),
      Arg("pt")).
    define_constructor(Constructor<cv::Point_<_Tp>, const cv::Size_<_Tp>&>(),
      Arg("sz")).
    define_constructor(Constructor<cv::Point_<_Tp>, const cv::Vec<_Tp, 2>&>(),
      Arg("v")).
    template define_method<cv::Point_<_Tp>&(cv::Point_<_Tp>::*)(const cv::Point_<_Tp>&)>("assign", &cv::Point_<_Tp>::operator=,
      Arg("pt")).
    template define_method<cv::Point_<_Tp>&(cv::Point_<_Tp>::*)(cv::Point_<_Tp>&&) noexcept>("assign", &cv::Point_<_Tp>::operator=,
      Arg("pt")).
    template define_method<_Tp(cv::Point_<_Tp>::*)(const cv::Point_<_Tp>&) const>("dot", &cv::Point_<_Tp>::dot,
      Arg("pt")).
    template define_method<double(cv::Point_<_Tp>::*)(const cv::Point_<_Tp>&) const>("ddot", &cv::Point_<_Tp>::ddot,
      Arg("pt")).
    template define_method<double(cv::Point_<_Tp>::*)(const cv::Point_<_Tp>&) const>("cross", &cv::Point_<_Tp>::cross,
      Arg("pt")).
    template define_method<bool(cv::Point_<_Tp>::*)(const cv::Rect_<_Tp>&) const>("inside", &cv::Point_<_Tp>::inside,
      Arg("r")).
    define_attr("x", &cv::Point_<_Tp>::x).
    define_attr("y", &cv::Point_<_Tp>::y);
}

template<typename _Tp>
inline Rice::Data_Type<cv::Point3_<_Tp>> Point3__instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Point3_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::Point3_<_Tp>>()).
    define_constructor(Constructor<cv::Point3_<_Tp>, _Tp, _Tp, _Tp>(),
      Arg("_x"), Arg("_y"), Arg("_z")).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Point3_<_Tp>&>(),
      Arg("pt")).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Point_<_Tp>&>(),
      Arg("pt")).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Vec<_Tp, 3>&>(),
      Arg("v")).
    template define_method<cv::Point3_<_Tp>&(cv::Point3_<_Tp>::*)(const cv::Point3_<_Tp>&)>("assign", &cv::Point3_<_Tp>::operator=,
      Arg("pt")).
    template define_method<cv::Point3_<_Tp>&(cv::Point3_<_Tp>::*)(cv::Point3_<_Tp>&&) noexcept>("assign", &cv::Point3_<_Tp>::operator=,
      Arg("pt")).
    template define_method<_Tp(cv::Point3_<_Tp>::*)(const cv::Point3_<_Tp>&) const>("dot", &cv::Point3_<_Tp>::dot,
      Arg("pt")).
    template define_method<double(cv::Point3_<_Tp>::*)(const cv::Point3_<_Tp>&) const>("ddot", &cv::Point3_<_Tp>::ddot,
      Arg("pt")).
    template define_method<cv::Point3_<_Tp>(cv::Point3_<_Tp>::*)(const cv::Point3_<_Tp>&) const>("cross", &cv::Point3_<_Tp>::cross,
      Arg("pt")).
    define_attr("x", &cv::Point3_<_Tp>::x).
    define_attr("y", &cv::Point3_<_Tp>::y).
    define_attr("z", &cv::Point3_<_Tp>::z);
}

template<typename _Tp>
inline Rice::Data_Type<cv::Size_<_Tp>> Size__instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Size_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::Size_<_Tp>>()).
    define_constructor(Constructor<cv::Size_<_Tp>, _Tp, _Tp>(),
      Arg("_width"), Arg("_height")).
    define_constructor(Constructor<cv::Size_<_Tp>, const cv::Size_<_Tp>&>(),
      Arg("sz")).
    define_constructor(Constructor<cv::Size_<_Tp>, const cv::Point_<_Tp>&>(),
      Arg("pt")).
    template define_method<cv::Size_<_Tp>&(cv::Size_<_Tp>::*)(const cv::Size_<_Tp>&)>("assign", &cv::Size_<_Tp>::operator=,
      Arg("sz")).
    template define_method<cv::Size_<_Tp>&(cv::Size_<_Tp>::*)(cv::Size_<_Tp>&&) noexcept>("assign", &cv::Size_<_Tp>::operator=,
      Arg("sz")).
    template define_method<_Tp(cv::Size_<_Tp>::*)() const>("area", &cv::Size_<_Tp>::area).
    template define_method<double(cv::Size_<_Tp>::*)() const>("aspect_ratio", &cv::Size_<_Tp>::aspectRatio).
    template define_method<bool(cv::Size_<_Tp>::*)() const>("empty?", &cv::Size_<_Tp>::empty).
    define_attr("width", &cv::Size_<_Tp>::width).
    define_attr("height", &cv::Size_<_Tp>::height);
}

template<typename _Tp>
inline Rice::Data_Type<cv::Rect_<_Tp>> Rect__instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Rect_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::Rect_<_Tp>>()).
    define_constructor(Constructor<cv::Rect_<_Tp>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("_x"), Arg("_y"), Arg("_width"), Arg("_height")).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Rect_<_Tp>&>(),
      Arg("r")).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Point_<_Tp>&, const cv::Size_<_Tp>&>(),
      Arg("org"), Arg("sz")).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Point_<_Tp>&, const cv::Point_<_Tp>&>(),
      Arg("pt1"), Arg("pt2")).
    template define_method<cv::Rect_<_Tp>&(cv::Rect_<_Tp>::*)(const cv::Rect_<_Tp>&)>("assign", &cv::Rect_<_Tp>::operator=,
      Arg("r")).
    template define_method<cv::Rect_<_Tp>&(cv::Rect_<_Tp>::*)(cv::Rect_<_Tp>&&) noexcept>("assign", &cv::Rect_<_Tp>::operator=,
      Arg("r")).
    template define_method<cv::Point_<_Tp>(cv::Rect_<_Tp>::*)() const>("tl", &cv::Rect_<_Tp>::tl).
    template define_method<cv::Point_<_Tp>(cv::Rect_<_Tp>::*)() const>("br", &cv::Rect_<_Tp>::br).
    template define_method<cv::Size_<_Tp>(cv::Rect_<_Tp>::*)() const>("size", &cv::Rect_<_Tp>::size).
    template define_method<_Tp(cv::Rect_<_Tp>::*)() const>("area", &cv::Rect_<_Tp>::area).
    template define_method<bool(cv::Rect_<_Tp>::*)() const>("empty?", &cv::Rect_<_Tp>::empty).
    define_attr("x", &cv::Rect_<_Tp>::x).
    define_attr("y", &cv::Rect_<_Tp>::y).
    define_attr("width", &cv::Rect_<_Tp>::width).
    define_attr("height", &cv::Rect_<_Tp>::height);
}

template<typename _Tp>
inline Rice::Data_Type<cv::Scalar_<_Tp>> Scalar__instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Scalar_<_Tp>, cv::Vec<_Tp, 4>>(parent, name). // Manual - Scalar_ inherits from Vec
    define_constructor(Constructor<cv::Scalar_<_Tp>>()).
    define_constructor(Constructor<cv::Scalar_<_Tp>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2") = static_cast<_Tp>(0), Arg("v3") = static_cast<_Tp>(0)).
    define_constructor(Constructor<cv::Scalar_<_Tp>, _Tp>(),
      Arg("v0")).
    define_constructor(Constructor<cv::Scalar_<_Tp>, const cv::Scalar_<_Tp>&>(),
      Arg("s")).
    template define_method<cv::Scalar_<_Tp>&(cv::Scalar_<_Tp>::*)(const cv::Scalar_<_Tp>&)>("assign", &cv::Scalar_<_Tp>::operator=,
      Arg("s")).
    template define_method<cv::Scalar_<_Tp>&(cv::Scalar_<_Tp>::*)(cv::Scalar_<_Tp>&&) noexcept>("assign", &cv::Scalar_<_Tp>::operator=,
      Arg("s")).
    template define_singleton_function<cv::Scalar_<_Tp>(*)(_Tp)>("all", &cv::Scalar_<_Tp>::all,
      Arg("v0")).
    template define_method<cv::Scalar_<_Tp>(cv::Scalar_<_Tp>::*)(const cv::Scalar_<_Tp>&, double) const>("mul", &cv::Scalar_<_Tp>::mul,
      Arg("a"), Arg("scale") = static_cast<double>(1)).
    template define_method<cv::Scalar_<_Tp>(cv::Scalar_<_Tp>::*)() const>("conj", &cv::Scalar_<_Tp>::conj).
    template define_method<bool(cv::Scalar_<_Tp>::*)() const>("real?", &cv::Scalar_<_Tp>::isReal);
}

