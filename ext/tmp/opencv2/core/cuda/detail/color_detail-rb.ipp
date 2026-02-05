template<typename T>
inline Rice::Data_Type<cv::cuda::device::color_detail::ColorChannel<T>> ColorChannel_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::ColorChannel<T>>(parent, name).
    template define_singleton_function<T(*)()>("max", &cv::cuda::device::color_detail::ColorChannel<T>::max).
    template define_singleton_function<T(*)()>("half", &cv::cuda::device::color_detail::ColorChannel<T>::half);
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>> RGB2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
}

template<typename T, int dcn>
inline Rice::Data_Type<cv::cuda::device::color_detail::Gray2RGB<T, dcn>> Gray2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::Gray2RGB<T, dcn>, cv::cuda::device::unary_function<T, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::Gray2RGB<T, dcn>::*)(T) const>("call", &cv::cuda::device::color_detail::Gray2RGB<T, dcn>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB<T, dcn>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB<T, dcn>, const cv::cuda::device::color_detail::Gray2RGB<T, dcn>&>(),
      Arg("arg_0"));
}

template<int green_bits>
inline Rice::Data_Type<cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>> Gray2RGB5x5_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>, cv::cuda::device::unary_function<uchar, ushort>>(parent, name).
    template define_method<ushort(cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>::*)(uint) const>("call", &cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>, const cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>&>(),
      Arg("arg_0"));
}

template<int green_bits>
inline Rice::Data_Type<cv::cuda::device::color_detail::RGB5x52Gray<green_bits>> RGB5x52Gray_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::RGB5x52Gray<green_bits>, cv::cuda::device::unary_function<ushort, uchar>>(parent, name).
    template define_method<uchar(cv::cuda::device::color_detail::RGB5x52Gray<green_bits>::*)(uint) const>("call", &cv::cuda::device::color_detail::RGB5x52Gray<green_bits>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52Gray<green_bits>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52Gray<green_bits>, const cv::cuda::device::color_detail::RGB5x52Gray<green_bits>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int bidx>
inline Rice::Data_Type<cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>> RGB2Gray_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, T>>(parent, name).
    template define_method<T(cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>, const cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>> RGB2YUV_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>> YUV2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>> RGB2YCrCb_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>> YCrCb2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>> RGB2XYZ_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>> XYZ2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx, int hr>
inline Rice::Data_Type<cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>> RGB2HSV_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>, const cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx, int hr>
inline Rice::Data_Type<cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>> HSV2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>, const cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx, int hr>
inline Rice::Data_Type<cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>> RGB2HLS_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>, const cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>&>(),
      Arg("arg_0"));
}

template<typename T, int scn, int dcn, int bidx, int hr>
inline Rice::Data_Type<cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>> HLS2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>, cv::cuda::device::unary_function<typename TypeVec<T, scn>::vec_type, typename TypeVec<T, dcn>::vec_type>>(parent, name).
    template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>, const cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>&>(),
      Arg("arg_0"));
}

