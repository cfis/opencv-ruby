#include <opencv2/imgproc/hal/interface.h>
#include "interface-rb.hpp"

using namespace Rice;

void Init_Imgproc_Hal_Interface()
{
  Class(rb_cObject).define_constant("CV_HAL_INTER_NEAREST", CV_HAL_INTER_NEAREST);

  Class(rb_cObject).define_constant("CV_HAL_INTER_LINEAR", CV_HAL_INTER_LINEAR);

  Class(rb_cObject).define_constant("CV_HAL_INTER_CUBIC", CV_HAL_INTER_CUBIC);

  Class(rb_cObject).define_constant("CV_HAL_INTER_AREA", CV_HAL_INTER_AREA);

  Class(rb_cObject).define_constant("CV_HAL_INTER_LANCZOS4", CV_HAL_INTER_LANCZOS4);

  Class(rb_cObject).define_constant("CV_HAL_INTER_LINEAR_EXACT", CV_HAL_INTER_LINEAR_EXACT);

  Class(rb_cObject).define_constant("CV_HAL_INTER_NEAREST_EXACT", CV_HAL_INTER_NEAREST_EXACT);

  Class(rb_cObject).define_constant("CV_HAL_INTER_MAX", CV_HAL_INTER_MAX);

  Class(rb_cObject).define_constant("CV_HAL_WARP_FILL_OUTLIERS", CV_HAL_WARP_FILL_OUTLIERS);

  Class(rb_cObject).define_constant("CV_HAL_WARP_INVERSE_MAP", CV_HAL_WARP_INVERSE_MAP);

  Class(rb_cObject).define_constant("CV_HAL_WARP_RELATIVE_MAP", CV_HAL_WARP_RELATIVE_MAP);

  Class(rb_cObject).define_constant("CV_HAL_MORPH_ERODE", CV_HAL_MORPH_ERODE);

  Class(rb_cObject).define_constant("CV_HAL_MORPH_DILATE", CV_HAL_MORPH_DILATE);

  Class(rb_cObject).define_constant("CV_HAL_THRESH_BINARY", CV_HAL_THRESH_BINARY);

  Class(rb_cObject).define_constant("CV_HAL_THRESH_BINARY_INV", CV_HAL_THRESH_BINARY_INV);

  Class(rb_cObject).define_constant("CV_HAL_THRESH_TRUNC", CV_HAL_THRESH_TRUNC);

  Class(rb_cObject).define_constant("CV_HAL_THRESH_TOZERO", CV_HAL_THRESH_TOZERO);

  Class(rb_cObject).define_constant("CV_HAL_THRESH_TOZERO_INV", CV_HAL_THRESH_TOZERO_INV);

  Class(rb_cObject).define_constant("CV_HAL_THRESH_MASK", CV_HAL_THRESH_MASK);

  Class(rb_cObject).define_constant("CV_HAL_THRESH_OTSU", CV_HAL_THRESH_OTSU);

  Class(rb_cObject).define_constant("CV_HAL_THRESH_TRIANGLE", CV_HAL_THRESH_TRIANGLE);

  Class(rb_cObject).define_constant("CV_HAL_ADAPTIVE_THRESH_MEAN_C", CV_HAL_ADAPTIVE_THRESH_MEAN_C);

  Class(rb_cObject).define_constant("CV_HAL_ADAPTIVE_THRESH_GAUSSIAN_C", CV_HAL_ADAPTIVE_THRESH_GAUSSIAN_C);
}
