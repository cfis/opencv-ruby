#include <opencv2/cudev/block/detail/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

#include "reduce-rb.ipp"

void Init_Cudev_Block_Detail_Reduce()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevBlockReduceDetail = define_module_under(rb_mCvCudev, "BlockReduceDetail");
}