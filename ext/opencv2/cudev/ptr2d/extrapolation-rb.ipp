template<typename SrcPtr>
inline Rice::Data_Type<cv::cudev::BrdConstant<SrcPtr>> BrdConstant_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::BrdConstant<SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::BrdConstant<SrcPtr>::src).
    define_attr("rows", &cv::cudev::BrdConstant<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::BrdConstant<SrcPtr>::cols).
    define_attr("val", &cv::cudev::BrdConstant<SrcPtr>::val).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::BrdConstant<SrcPtr>::*)(int, int) const>("call", &cv::cudev::BrdConstant<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

template<typename BrdImpl, typename SrcPtr>
inline Rice::Data_Type<cv::cudev::BrdBase<BrdImpl, SrcPtr>> BrdBase_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::BrdBase<BrdImpl, SrcPtr>>(parent, name).
    define_attr("src", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::src).
    define_attr("rows", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::rows).
    define_attr("cols", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::cols).
    template define_method<int(cv::cudev::BrdBase<BrdImpl, SrcPtr>::*)(int) const>("idx_row", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::idx_row,
      Arg("y")).
    template define_method<int(cv::cudev::BrdBase<BrdImpl, SrcPtr>::*)(int) const>("idx_col", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::idx_col,
      Arg("x")).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::BrdBase<BrdImpl, SrcPtr>::*)(int, int) const>("call", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::operator(),
      Arg("y"), Arg("x"));
}

