#include <opencv2/cudev/expr/reduction.hpp>
#include "reduction-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr>
inline void SumExprBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::SumExprBody<SrcPtr>::src);
};

template<typename Data_Type_T, typename SrcPtr>
inline void FindMinValExprBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::FindMinValExprBody<SrcPtr>::src);
};

template<typename Data_Type_T, typename SrcPtr>
inline void FindMaxValExprBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::FindMaxValExprBody<SrcPtr>::src);
};

template<typename Data_Type_T, typename SrcPtr>
inline void FindMinMaxValExprBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::FindMinMaxValExprBody<SrcPtr>::src);
};

template<typename Data_Type_T, typename SrcPtr>
inline void CountNonZeroExprBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::CountNonZeroExprBody<SrcPtr>::src);
};

template<typename Data_Type_T, typename Reductor, typename SrcPtr>
inline void ReduceToRowBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::ReduceToRowBody<Reductor, SrcPtr>::src);
};

template<typename Data_Type_T, typename Reductor, typename SrcPtr>
inline void ReduceToColumnBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::ReduceToColumnBody<Reductor, SrcPtr>::src);
};

template<typename Data_Type_T, int BIN_COUNT, typename SrcPtr>
inline void HistogramBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::HistogramBody<BIN_COUNT, SrcPtr>::src);
};

template<typename Data_Type_T, typename SrcPtr>
inline void IntegralBody_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::IntegralBody<SrcPtr>::src);
};

