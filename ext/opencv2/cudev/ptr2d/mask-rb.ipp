template<typename MaskPtr>
inline Rice::Data_Type<cv::cudev::SingleMaskChannels<MaskPtr>> SingleMaskChannels_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::SingleMaskChannels<MaskPtr>>(parent, name).
    define_attr("mask", &cv::cudev::SingleMaskChannels<MaskPtr>::mask).
    define_attr("channels", &cv::cudev::SingleMaskChannels<MaskPtr>::channels).
    template define_method<typename cv::cudev::SingleMaskChannels<MaskPtr>::value_type(cv::cudev::SingleMaskChannels<MaskPtr>::*)(typename cv::cudev::SingleMaskChannels<MaskPtr>::index_type, typename cv::cudev::SingleMaskChannels<MaskPtr>::index_type) const>("call", &cv::cudev::SingleMaskChannels<MaskPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename MaskPtr>
inline Rice::Data_Type<cv::cudev::SingleMaskChannelsSz<MaskPtr>> SingleMaskChannelsSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::SingleMaskChannelsSz<MaskPtr>>(parent, name).
    define_attr("rows", &cv::cudev::SingleMaskChannelsSz<MaskPtr>::rows).
    define_attr("cols", &cv::cudev::SingleMaskChannelsSz<MaskPtr>::cols);
}

