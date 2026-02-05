#include <opencv2/dnn.hpp>
#include "dnn-rb.hpp"

using namespace Rice;

void Init_Dnn_Refinements()
{
  // Alias each_const to each for Dict (read-only iteration)
  rb_define_alias(Data_Type<cv::dnn::Dict>::klass(), "each", "each_const");
}
