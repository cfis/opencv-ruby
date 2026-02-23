#include <opencv2/cudev/ptr2d/mask.hpp>
#include "mask-rb.hpp"

using namespace Rice;

#include "mask-rb.ipp"

void Init_Cudev_Ptr2d_Mask()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::WithOutMask> rb_cCvCudevWithOutMask = define_class_under<cv::cudev::WithOutMask>(rb_mCvCudev, "WithOutMask").
    define_constructor(Constructor<cv::cudev::WithOutMask>()).
    define_method<bool(cv::cudev::WithOutMask::*)(int, int) const>("call", &cv::cudev::WithOutMask::operator(),
      Arg("arg_0"), Arg("arg_1"));
}
