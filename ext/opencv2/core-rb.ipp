template<typename _Tp, typename _EnumTp>
inline Rice::Data_Type<cv::ParamType<_Tp, _EnumTp>> ParamType_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::ParamType<_Tp, _EnumTp>>(parent, name);
}

