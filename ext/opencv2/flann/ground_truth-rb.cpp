#include <vector>
#include <opencv2/core/base.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/flann/ground_truth.h>
#include "ground_truth-rb.hpp"

using namespace Rice;


void Init_GroundTruth()
{
  Module rb_mCvflann = define_module("Cvflann");
}