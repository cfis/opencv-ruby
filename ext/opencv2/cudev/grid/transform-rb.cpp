#include <opencv2/cudev/grid/transform.hpp>
#include "transform-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Transform()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DefaultTransformPolicy> rb_cCvCudevDefaultTransformPolicy = define_class_under<cv::cudev::DefaultTransformPolicy>(rb_mCvCudev, "DefaultTransformPolicy").
    define_constructor(Constructor<cv::cudev::DefaultTransformPolicy>());

  rb_cCvCudevDefaultTransformPolicy.define_constant("Block_size_x", (int)cv::cudev::DefaultTransformPolicy::block_size_x);
  rb_cCvCudevDefaultTransformPolicy.define_constant("Block_size_y", (int)cv::cudev::DefaultTransformPolicy::block_size_y);
  rb_cCvCudevDefaultTransformPolicy.define_constant("Shift", (int)cv::cudev::DefaultTransformPolicy::shift);
}
