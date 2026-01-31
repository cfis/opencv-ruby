#include <opencv2/cudev/block/vec_distance.hpp>
#include "vec_distance-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void NormL1_builder(Data_Type_T& klass)
{
  klass.define_attr("my_sum", &cv::cudev::NormL1<T>::mySum).
    define_constructor(Constructor<cv::cudev::NormL1<T>>()).
    template define_method<void(cv::cudev::NormL1<T>::*)(typename cv::cudev::NormL1<T>::value_type, typename cv::cudev::NormL1<T>::value_type)>("reduce_thread", &cv::cudev::NormL1<T>::reduceThread,
      Arg("val1"), Arg("val2")).
    template define_method<void(cv::cudev::NormL1<T>::*)(typename cv::cudev::NormL1<T>::result_type*, uint)>("reduce_warp", &cv::cudev::NormL1<T>::reduceWarp,
      ArgBuffer("smem"), Arg("tid")).
    define_method("to_result_type", [](const cv::cudev::NormL1<T>& self) -> typename cv::cudev::NormL1<T>::result_type
    {
      return self;
    });
};

void Init_Cudev_Block_VecDistance()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::NormL1<float>> rb_cCvCudevNormL1Float = define_class_under<cv::cudev::NormL1<float>>(rb_mCvCudev, "NormL1Float").
    define_attr("my_sum", &cv::cudev::NormL1<float>::mySum).
    define_constructor(Constructor<cv::cudev::NormL1<float>>()).
    define_method<void(cv::cudev::NormL1<float>::*)(cv::cudev::NormL1::value_type, cv::cudev::NormL1::value_type)>("reduce_thread", &cv::cudev::NormL1<float>::reduceThread,
      Arg("val1"), Arg("val2")).
    define_method<void(cv::cudev::NormL1<float>::*)(cv::cudev::NormL1::result_type*, uint)>("reduce_warp", &cv::cudev::NormL1<float>::reduceWarp,
      ArgBuffer("smem"), Arg("tid")).
    define_method("to_result_type", [](const cv::cudev::NormL1<float>& self) -> cv::cudev::NormL1::result_type
    {
      return self;
    });

  Rice::Data_Type<cv::cudev::NormL2> rb_cCvCudevNormL2 = define_class_under<cv::cudev::NormL2>(rb_mCvCudev, "NormL2").
    define_attr("my_sum", &cv::cudev::NormL2::mySum).
    define_constructor(Constructor<cv::cudev::NormL2>()).
    define_method<void(cv::cudev::NormL2::*)(cv::cudev::NormL2::value_type, cv::cudev::NormL2::value_type)>("reduce_thread", &cv::cudev::NormL2::reduceThread,
      Arg("val1"), Arg("val2")).
    define_method<void(cv::cudev::NormL2::*)(cv::cudev::NormL2::result_type*, uint)>("reduce_warp", &cv::cudev::NormL2::reduceWarp,
      ArgBuffer("smem"), Arg("tid")).
    define_method("to_result_type", [](const cv::cudev::NormL2& self) -> cv::cudev::NormL2::result_type
    {
      return self;
    });

  Rice::Data_Type<cv::cudev::NormHamming> rb_cCvCudevNormHamming = define_class_under<cv::cudev::NormHamming>(rb_mCvCudev, "NormHamming").
    define_attr("my_sum", &cv::cudev::NormHamming::mySum).
    define_constructor(Constructor<cv::cudev::NormHamming>()).
    define_method<void(cv::cudev::NormHamming::*)(cv::cudev::NormHamming::value_type, cv::cudev::NormHamming::value_type)>("reduce_thread", &cv::cudev::NormHamming::reduceThread,
      Arg("val1"), Arg("val2")).
    define_method<void(cv::cudev::NormHamming::*)(cv::cudev::NormHamming::result_type*, uint)>("reduce_warp", &cv::cudev::NormHamming::reduceWarp,
      ArgBuffer("smem"), Arg("tid")).
    define_method("to_result_type", [](const cv::cudev::NormHamming& self) -> cv::cudev::NormHamming::result_type
    {
      return self;
    });
}