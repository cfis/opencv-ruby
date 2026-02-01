template<typename Ptr2D>
inline Rice::Data_Type<cv::cuda::device::PointFilter<Ptr2D>> PointFilter_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::PointFilter<Ptr2D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::PointFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("fx") = static_cast<float>(0.f), Arg("fy") = static_cast<float>(0.f)).
    template define_method<typename cv::cuda::device::PointFilter<Ptr2D>::elem_type(cv::cuda::device::PointFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::PointFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::PointFilter<Ptr2D>::src);
}

template<typename Ptr2D>
inline Rice::Data_Type<cv::cuda::device::LinearFilter<Ptr2D>> LinearFilter_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::LinearFilter<Ptr2D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::LinearFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("fx") = static_cast<float>(0.f), Arg("fy") = static_cast<float>(0.f)).
    template define_method<typename cv::cuda::device::LinearFilter<Ptr2D>::elem_type(cv::cuda::device::LinearFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::LinearFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::LinearFilter<Ptr2D>::src);
}

template<typename Ptr2D>
inline Rice::Data_Type<cv::cuda::device::CubicFilter<Ptr2D>> CubicFilter_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::CubicFilter<Ptr2D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::CubicFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("fx") = static_cast<float>(0.f), Arg("fy") = static_cast<float>(0.f)).
    template define_method<typename cv::cuda::device::CubicFilter<Ptr2D>::elem_type(cv::cuda::device::CubicFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::CubicFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::CubicFilter<Ptr2D>::src).
    template define_singleton_function<float(*)(float)>("bicubic_coeff", &cv::cuda::device::CubicFilter<Ptr2D>::bicubicCoeff,
      Arg("x_"));
}

template<typename Ptr2D>
inline Rice::Data_Type<cv::cuda::device::IntegerAreaFilter<Ptr2D>> IntegerAreaFilter_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::IntegerAreaFilter<Ptr2D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::IntegerAreaFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("scale_x_"), Arg("scale_y_")).
    template define_method<typename cv::cuda::device::IntegerAreaFilter<Ptr2D>::elem_type(cv::cuda::device::IntegerAreaFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::src).
    define_attr("scale_x", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale_x).
    define_attr("scale_y", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale_y).
    define_attr("scale", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale);
}

template<typename Ptr2D>
inline Rice::Data_Type<cv::cuda::device::AreaFilter<Ptr2D>> AreaFilter_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::AreaFilter<Ptr2D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::AreaFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("scale_x_"), Arg("scale_y_")).
    template define_method<typename cv::cuda::device::AreaFilter<Ptr2D>::elem_type(cv::cuda::device::AreaFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::AreaFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::AreaFilter<Ptr2D>::src).
    define_attr("scale_x", &cv::cuda::device::AreaFilter<Ptr2D>::scale_x).
    define_attr("scale_y", &cv::cuda::device::AreaFilter<Ptr2D>::scale_y).
    define_attr("width", &cv::cuda::device::AreaFilter<Ptr2D>::width).
    define_attr("haight", &cv::cuda::device::AreaFilter<Ptr2D>::haight);
}

