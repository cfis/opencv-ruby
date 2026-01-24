#define CV_DNN_DONT_ADD_INLINE_NS
#include <opencv2/dnn/version.hpp>
#include "version-rb.hpp"

using namespace Rice;
void Init_Dnn_Version()
{
  Class(rb_cObject).define_constant("OPENCV_DNN_API_VERSION", OPENCV_DNN_API_VERSION);
}