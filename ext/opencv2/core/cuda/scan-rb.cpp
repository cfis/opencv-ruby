#include <opencv2/core/cuda/scan.hpp>
#include "scan-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, ScanKind Kind, typename T, typename F>
inline void WarpScan_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::WarpScan<Kind, T, F>::__forceinline__);
};

template<typename Data_Type_T, ScanKind Kind, typename T, typename F>
inline void WarpScanNoComp_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::WarpScanNoComp<Kind, T, F>::__forceinline__).
    define_constant("Warp_offset", cv::cuda::device::WarpScanNoComp<Kind, T, F>::warp_offset).
    define_constant("Warp_log", cv::cuda::device::WarpScanNoComp<Kind, T, F>::warp_log).
    define_constant("Warp_mask", cv::cuda::device::WarpScanNoComp<Kind, T, F>::warp_mask);
};

template<typename Data_Type_T, ScanKind Kind, typename T, typename Sc, typename F>
inline void BlockScan_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::BlockScan<Kind, T, Sc, F>::__forceinline__).
    define_constant("Warp_mask", cv::cuda::device::BlockScan<Kind, T, Sc, F>::warp_mask);
};
void Init_Scan()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Enum<cv::cuda::device::ScanKind> rb_cCvCudaDeviceScanKind = define_enum_under<cv::cuda::device::ScanKind>("ScanKind", rb_mCvCudaDevice).
    define_value("EXCLUSIVE", cv::cuda::device::ScanKind::EXCLUSIVE).
    define_value("INCLUSIVE", cv::cuda::device::ScanKind::INCLUSIVE);
  
  rb_mCvCudaDevice.define_module_function("warp_scan_inclusive", &cv::cuda::device::warpScanInclusive,
    Arg("idata"), Arg("s_data"), Arg("tid"));
  
  rb_mCvCudaDevice.define_module_function("warp_scan_exclusive", &cv::cuda::device::warpScanExclusive,
    Arg("idata"), Arg("s_data"), Arg("tid"));
  
  rb_mCvCudaDevice.define_module_function("block_scan_inclusive", &cv::cuda::device::blockScanInclusive,
    Arg("idata"), Arg("s_data"), Arg("tid"));

}