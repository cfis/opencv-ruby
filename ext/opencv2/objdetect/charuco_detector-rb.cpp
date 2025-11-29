#include <opencv2/objdetect/charuco_detector.hpp>
#include "charuco_detector-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvArucoCharucoDetector;
Rice::Class rb_cCvArucoCharucoParameters;

void Init_CharucoDetector()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");
  
  rb_cCvArucoCharucoParameters = define_class_under<cv::aruco::CharucoParameters>(rb_mCvAruco, "CharucoParameters").
    define_constructor(Constructor<cv::aruco::CharucoParameters>()).
    define_attr("camera_matrix", &cv::aruco::CharucoParameters::cameraMatrix).
    define_attr("dist_coeffs", &cv::aruco::CharucoParameters::distCoeffs).
    define_attr("min_markers", &cv::aruco::CharucoParameters::minMarkers).
    define_attr("try_refine_markers", &cv::aruco::CharucoParameters::tryRefineMarkers);
  
  rb_cCvArucoCharucoDetector = define_class_under<cv::aruco::CharucoDetector, cv::Algorithm>(rb_mCvAruco, "CharucoDetector").
    define_constructor(Constructor<cv::aruco::CharucoDetector, const cv::aruco::CharucoBoard&, const cv::aruco::CharucoParameters&, const cv::aruco::DetectorParameters&, const cv::aruco::RefineParameters&>(),
      Arg("board"), Arg("charuco_params") = static_cast<const cv::aruco::CharucoParameters &>(cv::aruco::CharucoParameters()), Arg("detector_params") = static_cast<const cv::aruco::DetectorParameters &>(cv::aruco::DetectorParameters()), Arg("refine_params") = static_cast<const cv::aruco::RefineParameters &>(cv::aruco::RefineParameters())).
    define_method("get_board", &cv::aruco::CharucoDetector::getBoard).
    define_method("set_board", &cv::aruco::CharucoDetector::setBoard,
      Arg("board")).
    define_method("get_charuco_parameters", &cv::aruco::CharucoDetector::getCharucoParameters).
    define_method("set_charuco_parameters", &cv::aruco::CharucoDetector::setCharucoParameters,
      Arg("charuco_parameters")).
    define_method("get_detector_parameters", &cv::aruco::CharucoDetector::getDetectorParameters).
    define_method("set_detector_parameters", &cv::aruco::CharucoDetector::setDetectorParameters,
      Arg("detector_parameters")).
    define_method("get_refine_parameters", &cv::aruco::CharucoDetector::getRefineParameters).
    define_method("set_refine_parameters", &cv::aruco::CharucoDetector::setRefineParameters,
      Arg("refine_parameters")).
    define_method("detect_board", &cv::aruco::CharucoDetector::detectBoard,
      Arg("image"), Arg("charuco_corners"), Arg("charuco_ids"), Arg("marker_corners") = static_cast<cv::InputOutputArrayOfArrays>(cv::noArray()), Arg("marker_ids") = static_cast<cv::InputOutputArray>(cv::noArray())).
    define_method("detect_diamonds", &cv::aruco::CharucoDetector::detectDiamonds,
      Arg("image"), Arg("diamond_corners"), Arg("diamond_ids"), Arg("marker_corners") = static_cast<cv::InputOutputArrayOfArrays>(cv::noArray()), Arg("marker_ids") = static_cast<cv::InputOutputArray>(cv::noArray()));
  
  rb_mCvAruco.define_module_function("draw_detected_corners_charuco", &cv::aruco::drawDetectedCornersCharuco,
    Arg("image"), Arg("charuco_corners"), Arg("charuco_ids") = static_cast<cv::InputArray>(cv::noArray()), Arg("corner_color") = static_cast<cv::Scalar>(cv::Scalar(255, 0, 0)));
  
  rb_mCvAruco.define_module_function("draw_detected_diamonds", &cv::aruco::drawDetectedDiamonds,
    Arg("image"), Arg("diamond_corners"), Arg("diamond_ids") = static_cast<cv::InputArray>(cv::noArray()), Arg("border_color") = static_cast<cv::Scalar>(cv::Scalar(0, 0, 255)));

}