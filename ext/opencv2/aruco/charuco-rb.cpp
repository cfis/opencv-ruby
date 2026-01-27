#include <opencv2/aruco/charuco.hpp>
#include "charuco-rb.hpp"

using namespace Rice;

void Init_Aruco_Charuco()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");

  rb_mCvAruco.define_module_function("interpolate_corners_charuco", &cv::aruco::interpolateCornersCharuco,
    Arg("marker_corners"), Arg("marker_ids"), Arg("image"), Arg("board"), Arg("charuco_corners"), Arg("charuco_ids"), Arg("camera_matrix") = static_cast<cv::InputArray>(cv::noArray()), Arg("dist_coeffs") = static_cast<cv::InputArray>(cv::noArray()), Arg("min_markers") = static_cast<int>(2));

  rb_mCvAruco.define_module_function("detect_charuco_diamond", &cv::aruco::detectCharucoDiamond,
    Arg("image"), Arg("marker_corners"), Arg("marker_ids"), Arg("square_marker_length_rate"), Arg("diamond_corners"), Arg("diamond_ids"), Arg("camera_matrix") = static_cast<cv::InputArray>(cv::noArray()), Arg("dist_coeffs") = static_cast<cv::InputArray>(cv::noArray()), Arg("dictionary") = static_cast<cv::Ptr<cv::aruco::Dictionary>>(cv::makePtr<cv::aruco::Dictionary>
                                                 (cv::aruco::getPredefinedDictionary(cv::aruco::PredefinedDictionaryType::DICT_4X4_50))));

  rb_mCvAruco.define_module_function("draw_charuco_diamond", &cv::aruco::drawCharucoDiamond,
    Arg("dictionary"), Arg("ids"), Arg("square_length"), Arg("marker_length"), Arg("img"), Arg("margin_size") = static_cast<int>(0), Arg("border_bits") = static_cast<int>(1));
}