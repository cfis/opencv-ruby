template<typename SrcPtr, typename Op>
inline Rice::Data_Type<cv::cudev::UnaryTransformPtr<SrcPtr, Op>> UnaryTransformPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::UnaryTransformPtr<SrcPtr, Op>>(parent, name).
    define_attr("src", &cv::cudev::UnaryTransformPtr<SrcPtr, Op>::src).
    define_attr("op", &cv::cudev::UnaryTransformPtr<SrcPtr, Op>::op).
    template define_method<typename Op::result_type(cv::cudev::UnaryTransformPtr<SrcPtr, Op>::*)(typename PtrTraits<SrcPtr>::index_type, typename PtrTraits<SrcPtr>::index_type) const>("call", &cv::cudev::UnaryTransformPtr<SrcPtr, Op>::operator(),
      Arg("y"), Arg("x"));
}

template<typename SrcPtr, typename Op>
inline Rice::Data_Type<cv::cudev::UnaryTransformPtrSz<SrcPtr, Op>> UnaryTransformPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::UnaryTransformPtrSz<SrcPtr, Op>>(parent, name).
    define_attr("rows", &cv::cudev::UnaryTransformPtrSz<SrcPtr, Op>::rows).
    define_attr("cols", &cv::cudev::UnaryTransformPtrSz<SrcPtr, Op>::cols);
}

template<typename Src1Ptr, typename Src2Ptr, typename Op>
inline Rice::Data_Type<cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>> BinaryTransformPtr_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>>(parent, name).
    define_attr("src1", &cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::src1).
    define_attr("src2", &cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::src2).
    define_attr("op", &cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::op).
    template define_method<typename Op::result_type(cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::*)(typename PtrTraits<Src1Ptr>::index_type, typename PtrTraits<Src1Ptr>::index_type) const>("call", &cv::cudev::BinaryTransformPtr<Src1Ptr, Src2Ptr, Op>::operator(),
      Arg("y"), Arg("x"));
}

template<typename Src1Ptr, typename Src2Ptr, typename Op>
inline Rice::Data_Type<cv::cudev::BinaryTransformPtrSz<Src1Ptr, Src2Ptr, Op>> BinaryTransformPtrSz_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::BinaryTransformPtrSz<Src1Ptr, Src2Ptr, Op>>(parent, name).
    define_attr("rows", &cv::cudev::BinaryTransformPtrSz<Src1Ptr, Src2Ptr, Op>::rows).
    define_attr("cols", &cv::cudev::BinaryTransformPtrSz<Src1Ptr, Src2Ptr, Op>::cols);
}

