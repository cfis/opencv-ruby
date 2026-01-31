#include <opencv2/cudev/grid/detail/copy.hpp>
#include "copy-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Detail_Copy()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevGridCopyDetail = define_module_under(rb_mCvCudev, "GridCopyDetail");

  Rice::Data_Type<cv::cudev::grid_copy_detail::Unroll<0>> rb_cCvCudevGridCopyDetailUnroll0 = define_class_under<cv::cudev::grid_copy_detail::Unroll<0>>(rb_mCvCudevGridCopyDetail, "Unroll0").
    define_constructor(Constructor<cv::cudev::grid_copy_detail::Unroll<0>>());
}