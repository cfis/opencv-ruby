#include <opencv2/cudev/warp/shuffle.hpp>
#include "shuffle-rb.hpp"

using namespace Rice;

void Init_Cudev_Warp_Shuffle()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}