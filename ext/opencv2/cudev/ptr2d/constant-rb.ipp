#include <opencv2/cudev/ptr2d/constant.hpp>
#include "constant-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void ConstantPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("value", &cv::cudev::ConstantPtr<T>::value).
    template define_method<T(cv::cudev::ConstantPtr<T>::*)(int, int) const>("call", &cv::cudev::ConstantPtr<T>::operator(),
      Arg("arg_0"), Arg("arg_1"));
};

template<typename Data_Type_T, typename T>
inline void ConstantPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::ConstantPtrSz<T>::rows).
    define_attr("cols", &cv::cudev::ConstantPtrSz<T>::cols);
};

