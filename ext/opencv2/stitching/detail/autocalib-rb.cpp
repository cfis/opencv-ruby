#include <opencv2/stitching/detail/autocalib.hpp>
#include "autocalib-rb.hpp"

using namespace Rice;


void Init_Autocalib()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_mCvDetail.define_module_function("focals_from_homography", &cv::detail::focalsFromHomography,
    Arg("h"), Arg("f0"), Arg("f1"), Arg("f0_ok"), Arg("f1_ok"));
  
  rb_mCvDetail.define_module_function("estimate_focal", &cv::detail::estimateFocal,
    Arg("features"), Arg("pairwise_matches"), Arg("focals"));
  
  rb_mCvDetail.define_module_function("calibrate_rotating_camera?", &cv::detail::calibrateRotatingCamera,
    Arg("hs"), Arg("k"));

}