#include <opencv2/core/base.hpp>
#include <opencv2/core.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/sampling.h>
#include "sampling-rb.hpp"

using namespace Rice;

void Init_Sampling()
{
  Module rb_mCvflann = define_module("Cvflann");
}