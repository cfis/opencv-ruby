#include <opencv2/aruco/charuco.hpp>
#include "charuco-rb.hpp"

using namespace Rice;

void Init_Aruco_Charuco()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");

  rb_mCvAruco.define_module_function<int(*)(cv::InputArrayOfArrays, cv::InputArray, cv::InputArray, const cv::Ptr<cv::aruco::CharucoBoard>&, cv::OutputArray, cv::OutputArray, cv::InputArray, cv::InputArray, int)>("interpolate_corners_charuco", &cv::aruco::interpolateCornersCharuco,
    Arg("marker_corners"), Arg("marker_ids"), Arg("image"), Arg("board"), Arg("charuco_corners"), Arg("charuco_ids"), Arg("camera_matrix") = static_cast<cv::InputArray>(cv::noArray()), Arg("dist_coeffs") = static_cast<cv::InputArray>(cv::noArray()), Arg("min_markers") = static_cast<int>(2));

  rb_mCvAruco.define_module_function<void(*)(cv::InputArray, cv::InputArrayOfArrays, cv::InputArray, float, cv::OutputArrayOfArrays, cv::OutputArray, cv::InputArray, cv::InputArray, cv::Ptr<cv::aruco::Dictionary>)>("detect_charuco_diamond", &cv::aruco::detectCharucoDiamond,
    Arg("image"), Arg("marker_corners"), Arg("marker_ids"), Arg("square_marker_length_rate"), Arg("diamond_corners"), Arg("diamond_ids"), Arg("camera_matrix") = static_cast<cv::InputArray>(cv::noArray()), Arg("dist_coeffs") = static_cast<cv::InputArray>(cv::noArray()), Arg("dictionary") = static_cast<cv::Ptr<cv::aruco::Dictionary>>(cv::makePtr<cv::aruco::Dictionary>
                                                 (cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50))));

  rb_mCvAruco.define_module_function<void(*)(const cv::Ptr<cv::aruco::Dictionary>&, cv::Vec4i, int, int, cv::OutputArray, int, int)>("draw_charuco_diamond", &cv::aruco::drawCharucoDiamond,
    Arg("dictionary"), Arg("ids"), Arg("square_length"), Arg("marker_length"), Arg("img"), Arg("margin_size") = static_cast<int>(0), Arg("border_bits") = static_cast<int>(1));
}