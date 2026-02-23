#include <opencv2/flann/dummy.h>
#include "dummy-rb.hpp"

using namespace Rice;

void Init_Flann_Dummy()
{
  Module rb_mCvflann = define_module("Cvflann");
}
