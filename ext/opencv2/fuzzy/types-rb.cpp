#include <opencv2/fuzzy/types.hpp>
#include "types-rb.hpp"

using namespace Rice;

void Init_Fuzzy_Types()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFt = define_module_under(rb_mCv, "Ft");

  rb_mCvFt.define_constant("LINEAR", (int)cv::ft::LINEAR);
  rb_mCvFt.define_constant("SINUS", (int)cv::ft::SINUS);

  rb_mCvFt.define_constant("ONE_STEP", (int)cv::ft::ONE_STEP);
  rb_mCvFt.define_constant("MULTI_STEP", (int)cv::ft::MULTI_STEP);
  rb_mCvFt.define_constant("ITERATIVE", (int)cv::ft::ITERATIVE);
}