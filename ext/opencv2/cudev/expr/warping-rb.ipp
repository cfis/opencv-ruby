template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::PyrDownBody<SrcPtr>> PyrDownBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::PyrDownBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::PyrDownBody<SrcPtr>::src);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::PyrUpBody<SrcPtr>> PyrUpBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::PyrUpBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::PyrUpBody<SrcPtr>::src);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::TransposeBody<SrcPtr>> TransposeBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::TransposeBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::TransposeBody<SrcPtr>::src);
}

