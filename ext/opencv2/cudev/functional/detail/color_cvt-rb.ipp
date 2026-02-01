template<typename T>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::ColorChannel<T>> ColorChannel_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::ColorChannel<T>>(parent, name).
    template define_singleton_function<T(*)()>("max", &cv::cudev::color_cvt_detail::ColorChannel<T>::max).
    template define_singleton_function<T(*)()>("half", &cv::cudev::color_cvt_detail::ColorChannel<T>::half);
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB<T, scn, dcn, bidx>> RGB2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::RGB2RGB<T, scn, dcn, bidx>>(parent, name).
    template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::RGB2RGB<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src"));
}

template<typename T, int dcn>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::Gray2RGB<T, dcn>> Gray2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::Gray2RGB<T, dcn>>(parent, name).
    template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::Gray2RGB<T, dcn>::*)(T) const>("call", &cv::cudev::color_cvt_detail::Gray2RGB<T, dcn>::operator(),
      Arg("src"));
}

template<typename T, int scn, int bidx>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2Gray<T, scn, bidx>> RGB2Gray_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::RGB2Gray<T, scn, bidx>>(parent, name).
    template define_method<T(cv::cudev::color_cvt_detail::RGB2Gray<T, scn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2Gray<T, scn, bidx>::operator(),
      Arg("src"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2YUV<T, scn, dcn, bidx>> RGB2YUV_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::RGB2YUV<T, scn, dcn, bidx>>(parent, name).
    template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::RGB2YUV<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2YUV<T, scn, dcn, bidx>::operator(),
      Arg("src"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::YUV2RGB<T, scn, dcn, bidx>> YUV2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::YUV2RGB<T, scn, dcn, bidx>>(parent, name).
    template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::YUV2RGB<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::YUV2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2YCrCb<T, scn, dcn, bidx>> RGB2YCrCb_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::RGB2YCrCb<T, scn, dcn, bidx>>(parent, name).
    template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::RGB2YCrCb<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2YCrCb<T, scn, dcn, bidx>::operator(),
      Arg("src"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::YCrCb2RGB<T, scn, dcn, bidx>> YCrCb2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::YCrCb2RGB<T, scn, dcn, bidx>>(parent, name).
    template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::YCrCb2RGB<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::YCrCb2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2XYZ<T, scn, dcn, bidx>> RGB2XYZ_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::RGB2XYZ<T, scn, dcn, bidx>>(parent, name).
    template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::RGB2XYZ<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2XYZ<T, scn, dcn, bidx>::operator(),
      Arg("src"));
}

template<typename T, int scn, int dcn, int bidx>
inline Rice::Data_Type<cv::cudev::color_cvt_detail::XYZ2RGB<T, scn, dcn, bidx>> XYZ2RGB_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::color_cvt_detail::XYZ2RGB<T, scn, dcn, bidx>>(parent, name).
    template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::XYZ2RGB<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::XYZ2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src"));
}

