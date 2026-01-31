#include <opencv2/cudev/functional/tuple_adapter.hpp>
#include "tuple_adapter-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Op, int n>
inline void UnaryTupleAdapter_builder(Data_Type_T& klass)
{
  klass.define_attr("op", &cv::cudev::UnaryTupleAdapter<Op, n>::op);
};

template<typename Data_Type_T, typename Op, int n0, int n1>
inline void BinaryTupleAdapter_builder(Data_Type_T& klass)
{
  klass.define_attr("op", &cv::cudev::BinaryTupleAdapter<Op, n0, n1>::op);
};

