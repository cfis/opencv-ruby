#include <opencv2/core/detail/dispatch_helper.impl.hpp>
#include "dispatch_helper.impl-rb.hpp"

using namespace Rice;

void Init_Core_Detail_DispatchHelperImpl()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
}
