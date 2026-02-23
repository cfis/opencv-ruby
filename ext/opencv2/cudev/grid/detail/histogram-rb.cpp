#include <opencv2/cudev/grid/detail/histogram.hpp>
#include "histogram-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Detail_Histogram()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevGridHistogramDetail = define_module_under(rb_mCvCudev, "GridHistogramDetail");
}
