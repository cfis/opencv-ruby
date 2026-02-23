#include <opencv2/imgproc/types_c.h>
#include "types_c-rb.hpp"

using namespace Rice;

void Init_Imgproc_TypesC()
{
  define_global_function<CvMoments(*)()>("cv_moments", &cvMoments);

  define_global_function<CvMoments(*)(const cv::Moments&)>("cv_moments", &cvMoments,
    Arg("m"));
}
