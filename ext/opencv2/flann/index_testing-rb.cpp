#include <opencv2/flann/index_testing.h>
#include "index_testing-rb.hpp"

using namespace Rice;

void Init_Flann_IndexTesting()
{
  Module rb_mCvflann = define_module("Cvflann");

  rb_mCvflann.define_module_function("count_correct_matches", &cvflann::countCorrectMatches,
    ArgBuffer("neighbors"), ArgBuffer("ground_truth"), Arg("n"));
}