#include <opencv2/flann/nn_index.h>
#include "nn_index-rb.hpp"

using namespace Rice;

#include "nn_index-rb.ipp"

void Init_Flann_NnIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
}