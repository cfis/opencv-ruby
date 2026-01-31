#include <opencv2/cudev/warp/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

void Init_Cudev_Warp_Reduce()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}