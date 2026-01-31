#include "scan-rb.ipp"

void Init_Core_Cuda_Scan()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Enum<cv::cuda::device::ScanKind> rb_cCvCudaDeviceScanKind = define_enum_under<cv::cuda::device::ScanKind>("ScanKind", rb_mCvCudaDevice).
    define_value("EXCLUSIVE", cv::cuda::device::ScanKind::EXCLUSIVE).
    define_value("INCLUSIVE", cv::cuda::device::ScanKind::INCLUSIVE);
}