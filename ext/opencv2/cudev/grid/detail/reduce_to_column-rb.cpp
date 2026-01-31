#include <opencv2/cudev/grid/detail/reduce_to_column.hpp>
#include "reduce_to_column-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Detail_ReduceToColumn()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevGridReduceToVecDetail = define_module_under(rb_mCvCudev, "GridReduceToVecDetail");
}