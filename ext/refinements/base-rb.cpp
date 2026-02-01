#include <opencv2/core/base.hpp>
#include "base-rb.hpp"

using namespace Rice;

void Init_Core_Base_Refinements()
{
  Module rb_mCv = define_module("Cv");

  // Manual
#if defined _DEBUG || defined CV_STATIC_ANALYSIS
  rb_mCv.const_set("DBG_ASSERT_ENABLED", true);
#else
  rb_mCv.const_set("DBG_ASSERT_ENABLED", false);
#endif
}
