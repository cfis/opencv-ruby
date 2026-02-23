#include <opencv2/cudev/grid/detail/minmaxloc.hpp>
#include "minmaxloc-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Detail_Minmaxloc()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevGridMinmaxlocDetail = define_module_under(rb_mCvCudev, "GridMinmaxlocDetail");
}
