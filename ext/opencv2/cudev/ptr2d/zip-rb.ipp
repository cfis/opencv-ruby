template<typename PtrTuple>
inline Rice::Data_Type<cv::cudev::ZipPtrSz<PtrTuple>> ZipPtrSz_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::ZipPtrSz<PtrTuple>>(parent, name).
    define_attr("rows", &cv::cudev::ZipPtrSz<PtrTuple>::rows).
    define_attr("cols", &cv::cudev::ZipPtrSz<PtrTuple>::cols).
    define_constructor(Constructor<cv::cudev::ZipPtrSz<PtrTuple>>()).
    define_constructor(Constructor<cv::cudev::ZipPtrSz<PtrTuple>, const PtrTuple&>(),
      Arg("t"));
}

