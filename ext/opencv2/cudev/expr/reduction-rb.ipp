template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::SumExprBody<SrcPtr>> SumExprBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::SumExprBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::SumExprBody<SrcPtr>::src);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::FindMinValExprBody<SrcPtr>> FindMinValExprBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::FindMinValExprBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::FindMinValExprBody<SrcPtr>::src);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::FindMaxValExprBody<SrcPtr>> FindMaxValExprBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::FindMaxValExprBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::FindMaxValExprBody<SrcPtr>::src);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::FindMinMaxValExprBody<SrcPtr>> FindMinMaxValExprBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::FindMinMaxValExprBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::FindMinMaxValExprBody<SrcPtr>::src);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::CountNonZeroExprBody<SrcPtr>> CountNonZeroExprBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::CountNonZeroExprBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::CountNonZeroExprBody<SrcPtr>::src);
}

template<typename Reductor, typename SrcPtr>
inline Rice::Data_Type<cv::cudev::ReduceToRowBody<Reductor, SrcPtr>> ReduceToRowBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ReduceToRowBody<Reductor, SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::ReduceToRowBody<Reductor, SrcPtr>::src);
}

template<typename Reductor, typename SrcPtr>
inline Rice::Data_Type<cv::cudev::ReduceToColumnBody<Reductor, SrcPtr>> ReduceToColumnBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ReduceToColumnBody<Reductor, SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::ReduceToColumnBody<Reductor, SrcPtr>::src);
}

template<int BIN_COUNT, typename SrcPtr>
inline Rice::Data_Type<cv::cudev::HistogramBody<BIN_COUNT, SrcPtr>> HistogramBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::HistogramBody<BIN_COUNT, SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::HistogramBody<BIN_COUNT, SrcPtr>::src);
}

template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::IntegralBody<SrcPtr>> IntegralBody_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::IntegralBody<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::IntegralBody<SrcPtr>::src);
}

