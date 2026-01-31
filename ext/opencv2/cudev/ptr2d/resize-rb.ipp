#include <opencv2/cudev/ptr2d/resize.hpp>
#include "resize-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr>
inline void ResizePtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::ResizePtr<SrcPtr>::src).
    define_attr("fx", &cv::cudev::ResizePtr<SrcPtr>::fx).
    define_attr("fy", &cv::cudev::ResizePtr<SrcPtr>::fy).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::ResizePtr<SrcPtr>::*)(typename PtrTraits<SrcPtr>::index_type, typename PtrTraits<SrcPtr>::index_type) const>("call", &cv::cudev::ResizePtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void ResizePtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::ResizePtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::ResizePtrSz<SrcPtr>::cols);
};

