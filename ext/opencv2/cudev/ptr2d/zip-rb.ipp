#include <opencv2/cudev/ptr2d/zip.hpp>
#include "zip-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename PtrTuple>
inline void ZipPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::ZipPtrSz<PtrTuple>::rows).
    define_attr("cols", &cv::cudev::ZipPtrSz<PtrTuple>::cols).
    define_constructor(Constructor<cv::cudev::ZipPtrSz<PtrTuple>>()).
    define_constructor(Constructor<cv::cudev::ZipPtrSz<PtrTuple>, const PtrTuple&>(),
      Arg("t"));
};

