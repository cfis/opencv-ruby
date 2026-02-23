#include <opencv2/cudev/block/scan.hpp>
#include "scan-rb.hpp"

using namespace Rice;

void Init_Cudev_Block_Scan()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
