#include <opencv2/core/cuda/scan.hpp>
#include "scan-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, ScanKind Kind, typename T, typename F>
inline void WarpScan_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::WarpScan<Kind, T, F>>()).
    define_constructor(Constructor<cv::cuda::device::WarpScan<Kind, T, F>, const cv::cuda::device::WarpScan<Kind, T, F>&>(),
      Arg("other")).
    template define_method<T(cv::cuda::device::WarpScan<Kind, T, F>::*)(volatile T*, const unsigned int)>("call", &cv::cuda::device::WarpScan<Kind, T, F>::operator(),
      std::conditional_t<std::is_fundamental_v<volatile T>, ArgBuffer, Arg>("ptr"), Arg("idx")).
    template define_method<unsigned int(cv::cuda::device::WarpScan<Kind, T, F>::*)(const unsigned int)>("index", &cv::cuda::device::WarpScan<Kind, T, F>::index,
      Arg("tid")).
    template define_method<void(cv::cuda::device::WarpScan<Kind, T, F>::*)(volatile T*)>("init", &cv::cuda::device::WarpScan<Kind, T, F>::init,
      std::conditional_t<std::is_fundamental_v<volatile T>, ArgBuffer, Arg>("ptr")).
    define_constant("Warp_offset", cv::cuda::device::WarpScan<Kind, T, F>::warp_offset);
};

template<typename Data_Type_T, ScanKind Kind, typename T, typename F>
inline void WarpScanNoComp_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::WarpScanNoComp<Kind, T, F>>()).
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
};

template<typename Data_Type_T, ScanKind Kind, typename T, typename Sc, typename F>
inline void BlockScan_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::BlockScan<Kind, T, Sc, F>>()).
    define_constructor(Constructor<cv::cuda::device::BlockScan<Kind, T, Sc, F>, const cv::cuda::device::BlockScan<Kind, T, Sc, F>&>(),
      Arg("other")).
    template define_method<T(cv::cuda::device::BlockScan<Kind, T, Sc, F>::*)(volatile T*)>("call", &cv::cuda::device::BlockScan<Kind, T, Sc, F>::operator(),
      std::conditional_t<std::is_fundamental_v<volatile T>, ArgBuffer, Arg>("ptr")).
    define_constant("Warp_log", cv::cuda::device::BlockScan<Kind, T, Sc, F>::warp_log).
    define_constant("Warp_mask", cv::cuda::device::BlockScan<Kind, T, Sc, F>::warp_mask);
};

void Init_Core_Cuda_Scan()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Enum<cv::cuda::device::ScanKind> rb_cCvCudaDeviceScanKind = define_enum_under<cv::cuda::device::ScanKind>("ScanKind", rb_mCvCudaDevice).
    define_value("EXCLUSIVE", cv::cuda::device::ScanKind::EXCLUSIVE).
    define_value("INCLUSIVE", cv::cuda::device::ScanKind::INCLUSIVE);
}