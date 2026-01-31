#include <opencv2/cudev/grid/histogram.hpp>
#include "histogram-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Histogram()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DefaultHistogramPolicy> rb_cCvCudevDefaultHistogramPolicy = define_class_under<cv::cudev::DefaultHistogramPolicy>(rb_mCvCudev, "DefaultHistogramPolicy").
    define_constructor(Constructor<cv::cudev::DefaultHistogramPolicy>());

  rb_cCvCudevDefaultHistogramPolicy.define_constant("Block_size_x", (int)cv::cudev::DefaultHistogramPolicy::block_size_x);
  rb_cCvCudevDefaultHistogramPolicy.define_constant("Block_size_y", (int)cv::cudev::DefaultHistogramPolicy::block_size_y);
}