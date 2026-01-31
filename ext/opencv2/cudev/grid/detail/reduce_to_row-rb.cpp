#include <opencv2/cudev/grid/detail/reduce_to_row.hpp>
#include "reduce_to_row-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Detail_ReduceToRow()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevGridReduceToVecDetail = define_module_under(rb_mCvCudev, "GridReduceToVecDetail");
}