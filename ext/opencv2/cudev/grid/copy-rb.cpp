#include <opencv2/cudev/grid/copy.hpp>
#include "copy-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Copy()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DefaultCopyPolicy> rb_cCvCudevDefaultCopyPolicy = define_class_under<cv::cudev::DefaultCopyPolicy>(rb_mCvCudev, "DefaultCopyPolicy").
    define_constructor(Constructor<cv::cudev::DefaultCopyPolicy>());

  rb_cCvCudevDefaultCopyPolicy.define_constant("Block_size_x", (int)cv::cudev::DefaultCopyPolicy::block_size_x);
  rb_cCvCudevDefaultCopyPolicy.define_constant("Block_size_y", (int)cv::cudev::DefaultCopyPolicy::block_size_y);
}
