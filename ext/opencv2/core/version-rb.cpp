#include <opencv2/core/version.hpp>
#include "version-rb.hpp"

using namespace Rice;


void Init_Version()
{
  Class(rb_cObject).define_constant("CV_VERSION", CV_VERSION);
  Class(rb_cObject).define_constant("CV_VERSION_MAJOR", CV_VERSION_MAJOR);
  Class(rb_cObject).define_constant("CV_VERSION_MINOR", CV_VERSION_MINOR);
  Class(rb_cObject).define_constant("CV_VERSION_REVISION", CV_VERSION_REVISION);
  Class(rb_cObject).define_constant("CV_VERSION_STATUS", CV_VERSION_STATUS);
}