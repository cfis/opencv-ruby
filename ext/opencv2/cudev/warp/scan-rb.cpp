#include <opencv2/cudev/warp/scan.hpp>
#include "scan-rb.hpp"

using namespace Rice;

void Init_Cudev_Warp_Scan()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}