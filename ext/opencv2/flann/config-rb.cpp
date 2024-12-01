#include <opencv2/flann/config.h>
#include "config-rb.hpp"

using namespace Rice;


void Init_Config()
{
  Class(rb_cObject).define_constant("FLANN_VERSION_", FLANN_VERSION_);

}