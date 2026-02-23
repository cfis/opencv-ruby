#include <opencv2/cudev/grid/detail/pyr_up.hpp>
#include "pyr_up-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Detail_PyrUp()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevPyramidsDetail = define_module_under(rb_mCvCudev, "PyramidsDetail");
}
