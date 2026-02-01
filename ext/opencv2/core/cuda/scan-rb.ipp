template<ScanKind Kind, typename T, typename F>
inline Rice::Data_Type<cv::cuda::device::WarpScan<Kind, T, F>> WarpScan_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::WarpScan<Kind, T, F>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::WarpScan<Kind, T, F>>()).
    define_constructor(Constructor<cv::cuda::device::WarpScan<Kind, T, F>, const cv::cuda::device::WarpScan<Kind, T, F>&>(),
      Arg("other")).
    template define_method<T(cv::cuda::device::WarpScan<Kind, T, F>::*)(volatile T*, const unsigned int)>("call", &cv::cuda::device::WarpScan<Kind, T, F>::operator(),
      std::conditional_t<std::is_fundamental_v<volatile T>, ArgBuffer, Arg>("ptr"), Arg("idx")).
    template define_method<unsigned int(cv::cuda::device::WarpScan<Kind, T, F>::*)(const unsigned int)>("index", &cv::cuda::device::WarpScan<Kind, T, F>::index,
      Arg("tid")).
    template define_method<void(cv::cuda::device::WarpScan<Kind, T, F>::*)(volatile T*)>("init", &cv::cuda::device::WarpScan<Kind, T, F>::init,
      std::conditional_t<std::is_fundamental_v<volatile T>, ArgBuffer, Arg>("ptr")).
    define_constant("Warp_offset", cv::cuda::device::WarpScan<Kind, T, F>::warp_offset);
}

template<ScanKind Kind, typename T, typename F>
inline Rice::Data_Type<cv::cuda::device::WarpScanNoComp<Kind, T, F>> WarpScanNoComp_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::WarpScanNoComp<Kind, T, F>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::WarpScanNoComp<Kind, T, F>>()).
    define_constructor(Constructor<cv::cuda::device::WarpScanNoComp<Kind, T, F>, const cv::cuda::device::WarpScanNoComp<Kind, T, F>&>(),
      Arg("other")).
    template define_method<T(cv::cuda::device::WarpScanNoComp<Kind, T, F>::*)(volatile T*, const unsigned int)>("call", &cv::cuda::device::WarpScanNoComp<Kind, T, F>::operator(),
      std::conditional_t<std::is_fundamental_v<volatile T>, ArgBuffer, Arg>("ptr"), Arg("idx")).
    template define_method<unsigned int(cv::cuda::device::WarpScanNoComp<Kind, T, F>::*)(const unsigned int)>("index", &cv::cuda::device::WarpScanNoComp<Kind, T, F>::index,
      Arg("tid")).
    template define_method<void(cv::cuda::device::WarpScanNoComp<Kind, T, F>::*)(volatile T*)>("init", &cv::cuda::device::WarpScanNoComp<Kind, T, F>::init,
      std::conditional_t<std::is_fundamental_v<volatile T>, ArgBuffer, Arg>("ptr")).
    define_constant("Warp_smem_stride", cv::cuda::device::WarpScanNoComp<Kind, T, F>::warp_smem_stride).
    define_constant("Warp_offset", cv::cuda::device::WarpScanNoComp<Kind, T, F>::warp_offset).
    define_constant("Warp_log", cv::cuda::device::WarpScanNoComp<Kind, T, F>::warp_log).
    define_constant("Warp_mask", cv::cuda::device::WarpScanNoComp<Kind, T, F>::warp_mask);
}

template<ScanKind Kind, typename T, typename Sc, typename F>
inline Rice::Data_Type<cv::cuda::device::BlockScan<Kind, T, Sc, F>> BlockScan_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BlockScan<Kind, T, Sc, F>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BlockScan<Kind, T, Sc, F>>()).
    define_constructor(Constructor<cv::cuda::device::BlockScan<Kind, T, Sc, F>, const cv::cuda::device::BlockScan<Kind, T, Sc, F>&>(),
      Arg("other")).
    template define_method<T(cv::cuda::device::BlockScan<Kind, T, Sc, F>::*)(volatile T*)>("call", &cv::cuda::device::BlockScan<Kind, T, Sc, F>::operator(),
      std::conditional_t<std::is_fundamental_v<volatile T>, ArgBuffer, Arg>("ptr")).
    define_constant("Warp_log", cv::cuda::device::BlockScan<Kind, T, Sc, F>::warp_log).
    define_constant("Warp_mask", cv::cuda::device::BlockScan<Kind, T, Sc, F>::warp_mask);
}

