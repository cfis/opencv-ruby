#include <opencv2/aruco.hpp>
#include "aruco-rb.hpp"

using namespace Rice;

void Init_Aruco()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");

  // TODO - this was incorrectly generated
  rb_mCvAruco.define_module_function("detect_markers", &cv::aruco::detectMarkers,
    Arg("image"), Arg("dictionary"), Arg("corners"), Arg("ids"), Arg("parameters") = static_cast<const cv::Ptr<cv::aruco::DetectorParameters>&>(cv::makePtr<cv::aruco::DetectorParameters>()), Arg("rejected_img_points") = static_cast<cv::OutputArrayOfArrays>(cv::noArray()));

  rb_mCvAruco.define_module_function("refine_detected_markers", &cv::aruco::refineDetectedMarkers,
    Arg("image"), Arg("board"), Arg("detected_corners"), Arg("detected_ids"), Arg("rejected_corners"), Arg("camera_matrix") = static_cast<cv::InputArray>(cv::noArray()), Arg("dist_coeffs") = static_cast<cv::InputArray>(cv::noArray()), Arg("min_rep_distance") = static_cast<float>(10.f), Arg("error_correction_rate") = static_cast<float>(3.f), Arg("check_all_orders") = static_cast<bool>(true), Arg("recovered_idxs") = static_cast<cv::OutputArray>(cv::noArray()), Arg("parameters") = static_cast<const cv::Ptr<cv::aruco::DetectorParameters>&>(cv::makePtr<cv::aruco::DetectorParameters>()));

  rb_mCvAruco.define_module_function("draw_planar_board", &cv::aruco::drawPlanarBoard,
    Arg("board"), Arg("out_size"), Arg("img"), Arg("margin_size"), Arg("border_bits"));

  rb_mCvAruco.define_module_function("get_board_object_and_image_points", &cv::aruco::getBoardObjectAndImagePoints,
    Arg("board"), Arg("detected_corners"), Arg("detected_ids"), Arg("obj_points"), Arg("img_points"));

  rb_mCvAruco.define_module_function("estimate_pose_board", &cv::aruco::estimatePoseBoard,
    Arg("corners"), Arg("ids"), Arg("board"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false));

  rb_mCvAruco.define_module_function("estimate_pose_charuco_board", &cv::aruco::estimatePoseCharucoBoard,
    Arg("charuco_corners"), Arg("charuco_ids"), Arg("board"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false));

  rb_mCvAruco.define_module_function("estimate_pose_single_markers", &cv::aruco::estimatePoseSingleMarkers,
    Arg("corners"), Arg("marker_length"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("obj_points") = static_cast<cv::OutputArray>(cv::noArray()), Arg("estimate_parameters") = static_cast<const cv::Ptr<cv::aruco::EstimateParameters>&>(cv::makePtr<cv::aruco::EstimateParameters>()));

  rb_mCvAruco.define_module_function("test_charuco_corners_collinear", &cv::aruco::testCharucoCornersCollinear,
    Arg("board"), Arg("charuco_ids"));
}