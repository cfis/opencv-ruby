#include <opencv2/core/cuda_types.hpp>
#include "cuda_types-rb.hpp"

using namespace Rice;

#include "cuda_types-rb.ipp"

void Init_Core_CudaTypes()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::DevPtr<unsigned char>> rb_cDevPtrUnsignedChar = DevPtr_instantiate<unsigned char>(rb_mCvCuda, "DevPtrUnsignedChar");
  Rice::Data_Type<cv::cuda::PtrStep<unsigned char>> rb_cPtrStepb = PtrStep_instantiate<unsigned char>(rb_mCvCuda, "PtrStepb");
  Rice::Data_Type<cv::cuda::PtrStepSz<unsigned char>> rb_cPtrStepSzb = PtrStepSz_instantiate<unsigned char>(rb_mCvCuda, "PtrStepSzb");

  Rice::Data_Type<cv::cuda::DevPtr<unsigned short>> rb_cDevPtrUnsignedShort = DevPtr_instantiate<unsigned short>(rb_mCvCuda, "DevPtrUnsignedShort");
  Rice::Data_Type<cv::cuda::PtrStep<unsigned short>> rb_cPtrStepus = PtrStep_instantiate<unsigned short>(rb_mCvCuda, "PtrStepus");
  Rice::Data_Type<cv::cuda::PtrStepSz<unsigned short>> rb_cPtrStepSzus = PtrStepSz_instantiate<unsigned short>(rb_mCvCuda, "PtrStepSzus");

  Rice::Data_Type<cv::cuda::DevPtr<float>> rb_cDevPtrFloat = DevPtr_instantiate<float>(rb_mCvCuda, "DevPtrFloat");
  Rice::Data_Type<cv::cuda::PtrStep<float>> rb_cPtrStepf = PtrStep_instantiate<float>(rb_mCvCuda, "PtrStepf");
  Rice::Data_Type<cv::cuda::PtrStepSz<float>> rb_cPtrStepSzf = PtrStepSz_instantiate<float>(rb_mCvCuda, "PtrStepSzf");

  Rice::Data_Type<cv::cuda::DevPtr<int>> rb_cDevPtrInt = DevPtr_instantiate<int>(rb_mCvCuda, "DevPtrInt");
  Rice::Data_Type<cv::cuda::PtrStep<int>> rb_cPtrStepi = PtrStep_instantiate<int>(rb_mCvCuda, "PtrStepi");
  Rice::Data_Type<cv::cuda::PtrStepSz<int>> rb_cPtrStepSzi = PtrStepSz_instantiate<int>(rb_mCvCuda, "PtrStepSzi");
}
