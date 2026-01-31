#include "cuda_types-rb.ipp"

void Init_Core_CudaTypes()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::DevPtr<unsigned char>> rb_cDevPtrUnsignedChar = define_class_under<cv::cuda::DevPtr<unsigned char>>(rb_mCvCuda, "DevPtrUnsignedChar").
    define(&DevPtr_builder<Data_Type<cv::cuda::DevPtr<unsigned char>>, unsigned char>);
  Rice::Data_Type<cv::cuda::PtrStep<unsigned char>> rb_cPtrStepb = define_class_under<cv::cuda::PtrStep<unsigned char>, cv::cuda::DevPtr<unsigned char>>(rb_mCvCuda, "PtrStepb").
    define(&PtrStep_builder<Data_Type<cv::cuda::PtrStep<unsigned char>>, unsigned char>);
  Rice::Data_Type<cv::cuda::PtrStepSz<unsigned char>> rb_cPtrStepSzb = define_class_under<cv::cuda::PtrStepSz<unsigned char>, cv::cuda::PtrStep<unsigned char>>(rb_mCvCuda, "PtrStepSzb").
    define(&PtrStepSz_builder<Data_Type<cv::cuda::PtrStepSz<unsigned char>>, unsigned char>);

  Rice::Data_Type<cv::cuda::DevPtr<unsigned short>> rb_cDevPtrUnsignedShort = define_class_under<cv::cuda::DevPtr<unsigned short>>(rb_mCvCuda, "DevPtrUnsignedShort").
    define(&DevPtr_builder<Data_Type<cv::cuda::DevPtr<unsigned short>>, unsigned short>);
  Rice::Data_Type<cv::cuda::PtrStep<unsigned short>> rb_cPtrStepus = define_class_under<cv::cuda::PtrStep<unsigned short>, cv::cuda::DevPtr<unsigned short>>(rb_mCvCuda, "PtrStepus").
    define(&PtrStep_builder<Data_Type<cv::cuda::PtrStep<unsigned short>>, unsigned short>);
  Rice::Data_Type<cv::cuda::PtrStepSz<unsigned short>> rb_cPtrStepSzus = define_class_under<cv::cuda::PtrStepSz<unsigned short>, cv::cuda::PtrStep<unsigned short>>(rb_mCvCuda, "PtrStepSzus").
    define(&PtrStepSz_builder<Data_Type<cv::cuda::PtrStepSz<unsigned short>>, unsigned short>);

  Rice::Data_Type<cv::cuda::DevPtr<float>> rb_cDevPtrFloat = define_class_under<cv::cuda::DevPtr<float>>(rb_mCvCuda, "DevPtrFloat").
    define(&DevPtr_builder<Data_Type<cv::cuda::DevPtr<float>>, float>);
  Rice::Data_Type<cv::cuda::PtrStep<float>> rb_cPtrStepf = define_class_under<cv::cuda::PtrStep<float>, cv::cuda::DevPtr<float>>(rb_mCvCuda, "PtrStepf").
    define(&PtrStep_builder<Data_Type<cv::cuda::PtrStep<float>>, float>);
  Rice::Data_Type<cv::cuda::PtrStepSz<float>> rb_cPtrStepSzf = define_class_under<cv::cuda::PtrStepSz<float>, cv::cuda::PtrStep<float>>(rb_mCvCuda, "PtrStepSzf").
    define(&PtrStepSz_builder<Data_Type<cv::cuda::PtrStepSz<float>>, float>);

  Rice::Data_Type<cv::cuda::DevPtr<int>> rb_cDevPtrInt = define_class_under<cv::cuda::DevPtr<int>>(rb_mCvCuda, "DevPtrInt").
    define(&DevPtr_builder<Data_Type<cv::cuda::DevPtr<int>>, int>);
  Rice::Data_Type<cv::cuda::PtrStep<int>> rb_cPtrStepi = define_class_under<cv::cuda::PtrStep<int>, cv::cuda::DevPtr<int>>(rb_mCvCuda, "PtrStepi").
    define(&PtrStep_builder<Data_Type<cv::cuda::PtrStep<int>>, int>);
  Rice::Data_Type<cv::cuda::PtrStepSz<int>> rb_cPtrStepSzi = define_class_under<cv::cuda::PtrStepSz<int>, cv::cuda::PtrStep<int>>(rb_mCvCuda, "PtrStepSzi").
    define(&PtrStepSz_builder<Data_Type<cv::cuda::PtrStepSz<int>>, int>);
}