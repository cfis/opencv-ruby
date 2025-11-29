#include <utility>
using std::swap;
#include <opencv2/opencv.hpp>
#include <opencv2/flann/simplex_downhill.h>
#include "simplex_downhill-rb.hpp"

using namespace Rice;
void Init_SimplexDownhill()
{
  Module rb_mCvflann = define_module("Cvflann");
}