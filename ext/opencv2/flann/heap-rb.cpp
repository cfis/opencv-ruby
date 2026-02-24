#include <opencv2/core/base.hpp> // Manual
#include <opencv2/flann/heap.h>
#include "heap-rb.hpp"

using namespace Rice;

#include "heap-rb.ipp"

void Init_Flann_Heap()
{
  Module rb_mCvflann = define_module("Cvflann");
}
