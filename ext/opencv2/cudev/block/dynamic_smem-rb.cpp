#include "dynamic_smem-rb.ipp"

void Init_Cudev_Block_DynamicSmem()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DynamicSharedMem<double>> rb_cCvCudevDynamicSharedMemDouble = define_class_under<cv::cudev::DynamicSharedMem<double>>(rb_mCvCudev, "DynamicSharedMemDouble").
    define_constructor(Constructor<cv::cudev::DynamicSharedMem<double>>()).
    define_method("to_double", [](cv::cudev::DynamicSharedMem<double>& self) -> double*
    {
      return self;
    }).
    define_method("to_const double", [](const cv::cudev::DynamicSharedMem<double>& self) -> const double*
    {
      return self;
    });
}