#include <opencv2/core.hpp> // Manual
#include <opencv2/imgproc/detail/gcgraph.hpp>
#include "gcgraph-rb.hpp"

using namespace Rice;

#include "gcgraph-rb.ipp"

void Init_Imgproc_Detail_Gcgraph()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
}
