#include <opencv2/core/cvdef.h> // Manual
#include <opencv2/core/operations.hpp> // Manual
#include <opencv2/ml/ml.inl.hpp>
#include "ml.inl-rb.hpp"

using namespace Rice;

void Init_Ml_MlInl()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvMl = define_module_under(rb_mCv, "Ml");
}
