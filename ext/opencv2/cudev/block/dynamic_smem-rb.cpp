#include <opencv2/cudev/block/dynamic_smem.hpp>
#include "dynamic_smem-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void DynamicSharedMem_builder(Data_Type_T& klass)
{
  klass.define_method("to_ptr", [](cv::cudev::DynamicSharedMem<T>& self) -> T*
    {
      return self;
    }).
    define_method("to_const_ptr", [](const cv::cudev::DynamicSharedMem<T>& self) -> const T*
    {
      return self;
    });
};

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