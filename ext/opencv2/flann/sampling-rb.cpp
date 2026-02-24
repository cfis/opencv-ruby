#include <opencv2/core/core.hpp> // Manual
#include <opencv2/flann/defines.h> // Manual
#include <opencv2/flann/sampling.h>
#include "sampling-rb.hpp"

using namespace Rice;

void Init_Flann_Sampling()
{
  Module rb_mCvflann = define_module("Cvflann");
}
