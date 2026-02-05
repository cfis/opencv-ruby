#include <opencv2/aruco/aruco_calib.hpp>
#include "aruco_calib-rb.hpp"

using namespace Rice;

void Init_Aruco_ArucoCalib()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");

  Enum<cv::aruco::PatternPositionType> rb_cCvArucoPatternPositionType = define_enum_under<cv::aruco::PatternPositionType>("PatternPositionType", rb_mCvAruco).
    define_value("ARUCO_CCW_CENTER", cv::aruco::PatternPositionType::ARUCO_CCW_CENTER).
    define_value("ARUCO_CW_TOP_LEFT_CORNER", cv::aruco::PatternPositionType::ARUCO_CW_TOP_LEFT_CORNER);

  Rice::Data_Type<cv::aruco::EstimateParameters> rb_cCvArucoEstimateParameters = define_class_under<cv::aruco::EstimateParameters>(rb_mCvAruco, "EstimateParameters").
    define_attr("pattern", &cv::aruco::EstimateParameters::pattern).
    define_attr("use_extrinsic_guess", &cv::aruco::EstimateParameters::useExtrinsicGuess).
    define_attr("solve_pn_p_method", &cv::aruco::EstimateParameters::solvePnPMethod).
    define_constructor(Constructor<cv::aruco::EstimateParameters>());

  rb_mCvAruco.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArray, cv::InputArray, const cv::Ptr<cv::aruco::Board>&, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, const cv::TermCriteria&)>("calibrate_camera_aruco", &cv::aruco::calibrateCameraAruco,
    Arg("corners"), Arg("ids"), Arg("counter"), Arg("board"), Arg("image_size"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("std_deviations_intrinsics"), Arg("std_deviations_extrinsics"), Arg("per_view_errors"), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<const cv::TermCriteria&>(cv::TermCriteria(cv::TermCriteria::Type::COUNT + cv::TermCriteria::Type::EPS, 30, DBL_EPSILON)));

  rb_mCvAruco.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArray, cv::InputArray, const cv::Ptr<cv::aruco::Board>&, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, int, const cv::TermCriteria&)>("calibrate_camera_aruco", &cv::aruco::calibrateCameraAruco,
    Arg("corners"), Arg("ids"), Arg("counter"), Arg("board"), Arg("image_size"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs") = static_cast<cv::OutputArrayOfArrays>(cv::noArray()), Arg("tvecs") = static_cast<cv::OutputArrayOfArrays>(cv::noArray()), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<const cv::TermCriteria&>(cv::TermCriteria(cv::TermCriteria::Type::COUNT + cv::TermCriteria::Type::EPS,
                                                                                       30, DBL_EPSILON)));

  rb_mCvAruco.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, const cv::Ptr<cv::aruco::CharucoBoard>&, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, const cv::TermCriteria&)>("calibrate_camera_charuco", &cv::aruco::calibrateCameraCharuco,
    Arg("charuco_corners"), Arg("charuco_ids"), Arg("board"), Arg("image_size"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("std_deviations_intrinsics"), Arg("std_deviations_extrinsics"), Arg("per_view_errors"), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<const cv::TermCriteria&>(cv::TermCriteria(
                                cv::TermCriteria::Type::COUNT + cv::TermCriteria::Type::EPS, 30, DBL_EPSILON)));

  rb_mCvAruco.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, const cv::Ptr<cv::aruco::CharucoBoard>&, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, int, const cv::TermCriteria&)>("calibrate_camera_charuco", &cv::aruco::calibrateCameraCharuco,
    Arg("charuco_corners"), Arg("charuco_ids"), Arg("board"), Arg("image_size"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs") = static_cast<cv::OutputArrayOfArrays>(cv::noArray()), Arg("tvecs") = static_cast<cv::OutputArrayOfArrays>(cv::noArray()), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<const cv::TermCriteria&>(cv::TermCriteria(cv::TermCriteria::Type::COUNT +
                                                                   cv::TermCriteria::Type::EPS, 30, DBL_EPSILON)));
}