#include <opencv2/cudev/grid/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Reduce()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DefaultGlobReducePolicy> rb_cCvCudevDefaultGlobReducePolicy = define_class_under<cv::cudev::DefaultGlobReducePolicy>(rb_mCvCudev, "DefaultGlobReducePolicy").
    define_constructor(Constructor<cv::cudev::DefaultGlobReducePolicy>());

  rb_cCvCudevDefaultGlobReducePolicy.define_constant("Block_size_x", (int)cv::cudev::DefaultGlobReducePolicy::block_size_x);
  rb_cCvCudevDefaultGlobReducePolicy.define_constant("Block_size_y", (int)cv::cudev::DefaultGlobReducePolicy::block_size_y);
  rb_cCvCudevDefaultGlobReducePolicy.define_constant("Patch_size_x", (int)cv::cudev::DefaultGlobReducePolicy::patch_size_x);
  rb_cCvCudevDefaultGlobReducePolicy.define_constant("Patch_size_y", (int)cv::cudev::DefaultGlobReducePolicy::patch_size_y);
}
