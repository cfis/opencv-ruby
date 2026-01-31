#include <opencv2/cudev/ptr2d/transform.hpp>
#include "transform-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr, typename Op>
inline void UnaryTransformPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::UnaryTransformPtr<SrcPtr, Op>::src).
    define_attr("op", &cv::cudev::UnaryTransformPtr<SrcPtr, Op>::op).
    template define_method<typename Op::result_type(cv::cudev::UnaryTransformPtr<SrcPtr, Op>::*)(typename PtrTraits<SrcPtr>::index_type, typename PtrTraits<SrcPtr>::index_type) const>("call", &cv::cudev::UnaryTransformPtr<SrcPtr, Op>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr, typename Op>
inline void UnaryTransformPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::UnaryTransformPtrSz<SrcPtr, Op>::rows).
    define_attr("cols", &cv::cudev::UnaryTransformPtrSz<SrcPtr, Op>::cols);
};

template<typename Data_Type_T, typename Src1Ptr, typename Src2Ptr, typename Op>
inline void BinaryTransformPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src1", &cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::src1).
    define_attr("src2", &cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::src2).
    define_attr("op", &cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::op).
    template define_method<typename Op::result_type(cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::*)(typename PtrTraits<Src1Ptr>::index_type, typename PtrTraits<Src1Ptr>::index_type) const>("call", &cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename Src1Ptr, typename Src2Ptr, typename Op>
inline void BinaryTransformPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::BinaryTransformPtrSz<Src1Ptr, Src2Ptr, Op>::rows).
    define_attr("cols", &cv::cudev::BinaryTransformPtrSz<Src1Ptr, Src2Ptr, Op>::cols);
};

