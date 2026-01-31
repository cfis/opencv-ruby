#include <opencv2/core/operations.hpp>
#include "operations-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp, int m, int n>
inline void Matx_FastInvOp_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::internal::Matx_FastInvOp<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&, cv::Matx<_Tp, n, m>&, int) const>("call", &cv::internal::Matx_FastInvOp<_Tp, m, n>::operator(),
      Arg("a"), Arg("b"), Arg("method"));
};

template<typename Data_Type_T, typename _Tp, int m, int l, int n>
inline void Matx_FastSolveOp_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::internal::Matx_FastSolveOp<_Tp, m, l, n>::*)(const cv::Matx<_Tp, m, l>&, const cv::Matx<_Tp, m, n>&, cv::Matx<_Tp, l, n>&, int) const>("call", &cv::internal::Matx_FastSolveOp<_Tp, m, l, n>::operator(),
      Arg("a"), Arg("b"), Arg("x"), Arg("method"));
};

