#include <opencv2/core/base.hpp> // Manual
#include <opencv2/flann/ground_truth.h>
#include "ground_truth-rb.hpp"

using namespace Rice;

void Init_Flann_GroundTruth()
{
  Module rb_mCvflann = define_module("Cvflann");
}
