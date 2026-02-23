#include <opencv2/flann/result_set.h>
#include "result_set-rb.hpp"

using namespace Rice;

#include "result_set-rb.ipp"

void Init_Flann_ResultSet()
{
  Module rb_mCvflann = define_module("Cvflann");
}
