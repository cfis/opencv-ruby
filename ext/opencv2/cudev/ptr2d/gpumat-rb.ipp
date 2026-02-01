template<typename T>
inline Rice::Data_Type<cv::cudev::GpuMat_<T>> GpuMat__instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::GpuMat_<T>>(parent, name).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, cv::cuda::GpuMat::Allocator*>(),
      Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, int, int, cv::cuda::GpuMat::Allocator*>(),
      Arg("arows"), Arg("acols"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, cv::Size, cv::cuda::GpuMat::Allocator*>(),
      Arg("asize"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, int, int, cv::Scalar, cv::cuda::GpuMat::Allocator*>(),
      Arg("arows"), Arg("acols"), Arg("val"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, cv::Size, cv::Scalar, cv::cuda::GpuMat::Allocator*>(),
      Arg("asize"), Arg("val"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, const cv::cudev::GpuMat_<_Tp>&>(),
      Arg("m")).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, const cv::cuda::GpuMat&, cv::cuda::GpuMat::Allocator*>(),
      Arg("m"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, int, int, T*, size_t>(),
      Arg("arows"), Arg("acols"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("adata"), Arg("astep") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, cv::Size, T*, size_t>(),
      Arg("asize"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("adata"), Arg("astep") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, const cv::cudev::GpuMat_<_Tp>&, cv::Range, cv::Range>(),
      Arg("m"), Arg("arow_range"), Arg("acol_range")).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, const cv::cudev::GpuMat_<_Tp>&, cv::Rect>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::cudev::GpuMat_<T>, cv::InputArray, cv::cuda::GpuMat::Allocator*>(),
      Arg("arr"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    template define_method<cv::cudev::GpuMat_<_Tp>&(cv::cudev::GpuMat_<T>::*)(const cv::cudev::GpuMat_<_Tp>&)>("assign", &cv::cudev::GpuMat_<T>::operator=,
      Arg("m")).
    template define_method<void(cv::cudev::GpuMat_<T>::*)(int, int)>("create", &cv::cudev::GpuMat_<T>::create,
      Arg("arows"), Arg("acols")).
    template define_method<void(cv::cudev::GpuMat_<T>::*)(cv::Size)>("create", &cv::cudev::GpuMat_<T>::create,
      Arg("asize")).
    template define_method<void(cv::cudev::GpuMat_<T>::*)(cv::cudev::GpuMat_<_Tp>&)>("swap", &cv::cudev::GpuMat_<T>::swap,
      Arg("mat")).
    template define_method<void(cv::cudev::GpuMat_<T>::*)(cv::InputArray)>("upload", &cv::cudev::GpuMat_<T>::upload,
      Arg("arr")).
    template define_method<void(cv::cudev::GpuMat_<T>::*)(cv::InputArray, cv::cuda::Stream&)>("upload", &cv::cudev::GpuMat_<T>::upload,
      Arg("arr"), Arg("stream")).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)() const>("clone", &cv::cudev::GpuMat_<T>::clone).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)(int) const>("row", &cv::cudev::GpuMat_<T>::row,
      Arg("y")).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)(int) const>("col", &cv::cudev::GpuMat_<T>::col,
      Arg("x")).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)(int, int) const>("row_range", &cv::cudev::GpuMat_<T>::rowRange,
      Arg("startrow"), Arg("endrow")).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)(cv::Range) const>("row_range", &cv::cudev::GpuMat_<T>::rowRange,
      Arg("r")).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)(int, int) const>("col_range", &cv::cudev::GpuMat_<T>::colRange,
      Arg("startcol"), Arg("endcol")).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)(cv::Range) const>("col_range", &cv::cudev::GpuMat_<T>::colRange,
      Arg("r")).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)(cv::Range, cv::Range) const>("call", &cv::cudev::GpuMat_<T>::operator(),
      Arg("row_range"), Arg("col_range")).
    template define_method<cv::cudev::GpuMat_<_Tp>(cv::cudev::GpuMat_<T>::*)(cv::Rect) const>("call", &cv::cudev::GpuMat_<T>::operator(),
      Arg("roi")).
    template define_method<cv::cudev::GpuMat_<_Tp>&(cv::cudev::GpuMat_<T>::*)(int, int, int, int)>("adjust_roi", &cv::cudev::GpuMat_<T>::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    template define_method<size_t(cv::cudev::GpuMat_<T>::*)() const>("elem_size", &cv::cudev::GpuMat_<T>::elemSize).
    template define_method<size_t(cv::cudev::GpuMat_<T>::*)() const>("elem_size1", &cv::cudev::GpuMat_<T>::elemSize1).
    template define_method<int(cv::cudev::GpuMat_<T>::*)() const>("type", &cv::cudev::GpuMat_<T>::type).
    template define_method<int(cv::cudev::GpuMat_<T>::*)() const>("depth", &cv::cudev::GpuMat_<T>::depth).
    template define_method<int(cv::cudev::GpuMat_<T>::*)() const>("channels", &cv::cudev::GpuMat_<T>::channels).
    template define_method<size_t(cv::cudev::GpuMat_<T>::*)() const>("step1", &cv::cudev::GpuMat_<T>::step1).
    template define_method<size_t(cv::cudev::GpuMat_<T>::*)() const>("step_t", &cv::cudev::GpuMat_<T>::stepT).
    template define_method<T*(cv::cudev::GpuMat_<T>::*)(int)>("[]", &cv::cudev::GpuMat_<T>::operator[],
      Arg("y")).
    template define_method<const T*(cv::cudev::GpuMat_<T>::*)(int) const>("[]", &cv::cudev::GpuMat_<T>::operator[],
      Arg("y"));
}

