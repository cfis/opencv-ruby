#include <opencv2/cudev/util/type_traits.hpp>
#include "type_traits-rb.hpp"

using namespace Rice;

#include "type_traits-rb.ipp"

void Init_Cudev_Util_TypeTraits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::NullType> rb_cCvCudevNullType = define_class_under<cv::cudev::NullType>(rb_mCvCudev, "NullType").
    define_constructor(Constructor<cv::cudev::NullType>());
}