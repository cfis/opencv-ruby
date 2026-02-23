#include <opencv2/cudev/grid/transpose.hpp>
#include "transpose-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Transpose()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DefaultTransposePolicy> rb_cCvCudevDefaultTransposePolicy = define_class_under<cv::cudev::DefaultTransposePolicy>(rb_mCvCudev, "DefaultTransposePolicy").
    define_constructor(Constructor<cv::cudev::DefaultTransposePolicy>());

  rb_cCvCudevDefaultTransposePolicy.define_constant("Tile_dim", (int)cv::cudev::DefaultTransposePolicy::tile_dim);
  rb_cCvCudevDefaultTransposePolicy.define_constant("Block_dim_y", (int)cv::cudev::DefaultTransposePolicy::block_dim_y);
}
