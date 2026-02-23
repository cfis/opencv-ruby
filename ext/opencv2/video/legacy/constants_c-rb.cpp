#include <opencv2/video/legacy/constants_c.h>
#include "constants_c-rb.hpp"

using namespace Rice;

void Init_Video_Legacy_ConstantsC()
{
  Class(rb_cObject).define_constant("CV_LKFLOW_PYR_A_READY", (int)::CV_LKFLOW_PYR_A_READY);
  Class(rb_cObject).define_constant("CV_LKFLOW_PYR_B_READY", (int)::CV_LKFLOW_PYR_B_READY);
  Class(rb_cObject).define_constant("CV_LKFLOW_INITIAL_GUESSES", (int)::CV_LKFLOW_INITIAL_GUESSES);
  Class(rb_cObject).define_constant("CV_LKFLOW_GET_MIN_EIGENVALS", (int)::CV_LKFLOW_GET_MIN_EIGENVALS);
}
