#include <opencv2/core/hal/interface.h>
#include "hal-rb.hpp"

using namespace Rice;

void Init_Core_Hal_Refinements()
{
  Class(rb_cObject).define_constant("CV_8UC1", CV_8UC1);
  Class(rb_cObject).define_constant("CV_8UC2", CV_8UC2);
  Class(rb_cObject).define_constant("CV_8UC3", CV_8UC3);
  Class(rb_cObject).define_constant("CV_8UC4", CV_8UC4);

  Class(rb_cObject).define_constant("CV_8SC1", CV_8SC1);
  Class(rb_cObject).define_constant("CV_8SC2", CV_8SC2);
  Class(rb_cObject).define_constant("CV_8SC3", CV_8SC3);
  Class(rb_cObject).define_constant("CV_8SC4", CV_8SC4);

  Class(rb_cObject).define_constant("CV_16UC1", CV_16UC1);
  Class(rb_cObject).define_constant("CV_16UC2", CV_16UC2);
  Class(rb_cObject).define_constant("CV_16UC3", CV_16UC3);
  Class(rb_cObject).define_constant("CV_16UC4", CV_16UC4);

  Class(rb_cObject).define_constant("CV_16SC1", CV_16SC1);
  Class(rb_cObject).define_constant("CV_16SC2", CV_16SC2);
  Class(rb_cObject).define_constant("CV_16SC3", CV_16SC3);
  Class(rb_cObject).define_constant("CV_16SC4", CV_16SC4);

  Class(rb_cObject).define_constant("CV_32SC1", CV_32SC1);
  Class(rb_cObject).define_constant("CV_32SC2", CV_32SC2);
  Class(rb_cObject).define_constant("CV_32SC3", CV_32SC3);
  Class(rb_cObject).define_constant("CV_32SC4", CV_32SC4);

  Class(rb_cObject).define_constant("CV_32FC1", CV_32FC1);
  Class(rb_cObject).define_constant("CV_32FC2", CV_32FC2);
  Class(rb_cObject).define_constant("CV_32FC3", CV_32FC3);
  Class(rb_cObject).define_constant("CV_32FC4", CV_32FC4);

  // For corner_eigen_vals_and_vecs
  Class(rb_cObject).define_constant("CV_32FC6", CV_32FC(6));

  Class(rb_cObject).define_constant("CV_64FC1", CV_64FC1);
  Class(rb_cObject).define_constant("CV_64FC2", CV_64FC2);
  Class(rb_cObject).define_constant("CV_64FC3", CV_64FC3);
  Class(rb_cObject).define_constant("CV_64FC4", CV_64FC4);

  Class(rb_cObject).define_constant("CV_16FC1", CV_16FC1);
  Class(rb_cObject).define_constant("CV_16FC2", CV_16FC2);
  Class(rb_cObject).define_constant("CV_16FC3", CV_16FC3);
  Class(rb_cObject).define_constant("CV_16FC4", CV_16FC4);
}
