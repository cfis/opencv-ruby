#include <opencv2/cudev/util/tuple.hpp>
#include "tuple-rb.hpp"

using namespace Rice;

#include "tuple-rb.ipp"

void Init_Cudev_Util_Tuple()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}