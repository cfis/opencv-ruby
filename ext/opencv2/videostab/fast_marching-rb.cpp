#include <opencv2/videostab/fast_marching.hpp>
#include "fast_marching-rb.hpp"

using namespace Rice;

void Init_Videostab_FastMarching()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  Rice::Data_Type<cv::videostab::FastMarchingMethod> rb_cCvVideostabFastMarchingMethod = define_class_under<cv::videostab::FastMarchingMethod>(rb_mCvVideostab, "FastMarchingMethod").
    define_constructor(Constructor<cv::videostab::FastMarchingMethod>()).
    define_method<cv::Mat(cv::videostab::FastMarchingMethod::*)() const>("distance_map", &cv::videostab::FastMarchingMethod::distanceMap);
}
