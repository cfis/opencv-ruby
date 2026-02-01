template<typename _Tp, int m, int n>
inline Rice::Data_Type<cv::internal::Matx_FastInvOp<_Tp, m, n>> Matx_FastInvOp_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::internal::Matx_FastInvOp<_Tp, m, n>>(parent, name).
    template define_method<bool(cv::internal::Matx_FastInvOp<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&, cv::Matx<_Tp, n, m>&, int) const>("call", &cv::internal::Matx_FastInvOp<_Tp, m, n>::operator(),
      Arg("a"), Arg("b"), Arg("method"));
}

template<typename _Tp, int m, int l, int n>
inline Rice::Data_Type<cv::internal::Matx_FastSolveOp<_Tp, m, l, n>> Matx_FastSolveOp_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::internal::Matx_FastSolveOp<_Tp, m, l, n>>(parent, name).
    template define_method<bool(cv::internal::Matx_FastSolveOp<_Tp, m, l, n>::*)(const cv::Matx<_Tp, m, l>&, const cv::Matx<_Tp, m, n>&, cv::Matx<_Tp, l, n>&, int) const>("call", &cv::internal::Matx_FastSolveOp<_Tp, m, l, n>::operator(),
      Arg("a"), Arg("b"), Arg("x"), Arg("method"));
}

