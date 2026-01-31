#include <opencv2/stitching/detail/autocalib.hpp>
#include "autocalib-rb.hpp"

using namespace Rice;

void Init_Stitching_Detail_Autocalib()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  rb_mCvDetail.define_module_function<void(*)(const cv::Mat&, double&, double&, bool&, bool&)>("focals_from_homography", &cv::detail::focalsFromHomography,
    Arg("h"), Arg("f0"), Arg("f1"), Arg("f0_ok"), Arg("f1_ok"));

  rb_mCvDetail.define_module_function<void(*)(const std::vector<cv::detail::ImageFeatures>&, const std::vector<cv::detail::MatchesInfo>&, std::vector<double>&)>("estimate_focal", &cv::detail::estimateFocal,
    Arg("features"), Arg("pairwise_matches"), Arg("focals"));

  rb_mCvDetail.define_module_function<bool(*)(const std::vector<cv::Mat>&, cv::Mat&)>("calibrate_rotating_camera", &cv::detail::calibrateRotatingCamera,
    Arg("hs"), Arg("k"));
}