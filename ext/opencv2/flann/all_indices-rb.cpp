#include <opencv2/flann/all_indices.h>
#include "all_indices-rb.hpp"

using namespace Rice;

#include "all_indices-rb.ipp"

void Init_Flann_AllIndices()
{
  Module rb_mCvflann = define_module("Cvflann");
}
