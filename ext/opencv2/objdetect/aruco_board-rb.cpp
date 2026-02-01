#include <opencv2/objdetect/aruco_dictionary.hpp> // Manual
#include <opencv2/objdetect/aruco_board.hpp>
#include "aruco_board-rb.hpp"

using namespace Rice;

void Init_Objdetect_ArucoBoard()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");

  Rice::Data_Type<cv::aruco::Board> rb_cCvArucoBoard = define_class_under<cv::aruco::Board>(rb_mCvAruco, "Board");

  Rice::Data_Type<cv::aruco::Board::Impl> rb_cCvArucoBoardImpl = define_class_under<cv::aruco::Board::Impl>(rb_cCvArucoBoard, "Impl");

  rb_cCvArucoBoard.
    define_constructor(Constructor<cv::aruco::Board, cv::InputArrayOfArrays, const cv::aruco::Dictionary&, cv::InputArray>(),
      Arg("obj_points"), Arg("dictionary"), Arg("ids")).
    define_method<const cv::aruco::Dictionary&(cv::aruco::Board::*)() const>("get_dictionary", &cv::aruco::Board::getDictionary).
    define_method<const std::vector<std::vector<cv::Point3_<float>>>&(cv::aruco::Board::*)() const>("get_obj_points", &cv::aruco::Board::getObjPoints).
    define_method<const std::vector<int>&(cv::aruco::Board::*)() const>("get_ids", &cv::aruco::Board::getIds).
    define_method<const cv::Point3f&(cv::aruco::Board::*)() const>("get_right_bottom_corner", &cv::aruco::Board::getRightBottomCorner).
    define_method<void(cv::aruco::Board::*)(cv::InputArrayOfArrays, cv::InputArray, cv::OutputArray, cv::OutputArray) const>("match_image_points", &cv::aruco::Board::matchImagePoints,
      Arg("detected_corners"), Arg("detected_ids"), Arg("obj_points"), Arg("img_points")).
    define_method<void(cv::aruco::Board::*)(cv::Size, cv::OutputArray, int, int) const>("generate_image", &cv::aruco::Board::generateImage,
      Arg("out_size"), Arg("img"), Arg("margin_size") = static_cast<int>(0), Arg("border_bits") = static_cast<int>(1));

  Rice::Data_Type<cv::aruco::GridBoard> rb_cCvArucoGridBoard = define_class_under<cv::aruco::GridBoard, cv::aruco::Board>(rb_mCvAruco, "GridBoard").
    define_constructor(Constructor<cv::aruco::GridBoard, const cv::Size&, float, float, const cv::aruco::Dictionary&, cv::InputArray>(),
      Arg("size"), Arg("marker_length"), Arg("marker_separation"), Arg("dictionary"), Arg("ids") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<cv::Size(cv::aruco::GridBoard::*)() const>("get_grid_size", &cv::aruco::GridBoard::getGridSize).
    define_method<float(cv::aruco::GridBoard::*)() const>("get_marker_length", &cv::aruco::GridBoard::getMarkerLength).
    define_method<float(cv::aruco::GridBoard::*)() const>("get_marker_separation", &cv::aruco::GridBoard::getMarkerSeparation);

  Rice::Data_Type<cv::aruco::CharucoBoard> rb_cCvArucoCharucoBoard = define_class_under<cv::aruco::CharucoBoard, cv::aruco::Board>(rb_mCvAruco, "CharucoBoard").
    define_constructor(Constructor<cv::aruco::CharucoBoard, const cv::Size&, float, float, const cv::aruco::Dictionary&, cv::InputArray>(),
      Arg("size"), Arg("square_length"), Arg("marker_length"), Arg("dictionary"), Arg("ids") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<void(cv::aruco::CharucoBoard::*)(bool)>("set_legacy_pattern", &cv::aruco::CharucoBoard::setLegacyPattern,
      Arg("legacy_pattern")).
    define_method<bool(cv::aruco::CharucoBoard::*)() const>("get_legacy_pattern?", &cv::aruco::CharucoBoard::getLegacyPattern).
    define_method<cv::Size(cv::aruco::CharucoBoard::*)() const>("get_chessboard_size", &cv::aruco::CharucoBoard::getChessboardSize).
    define_method<float(cv::aruco::CharucoBoard::*)() const>("get_square_length", &cv::aruco::CharucoBoard::getSquareLength).
    define_method<float(cv::aruco::CharucoBoard::*)() const>("get_marker_length", &cv::aruco::CharucoBoard::getMarkerLength).
    define_method<std::vector<cv::Point3_<float>>(cv::aruco::CharucoBoard::*)() const>("get_chessboard_corners", &cv::aruco::CharucoBoard::getChessboardCorners).
    define_method<std::vector<std::vector<int>>(cv::aruco::CharucoBoard::*)() const>("get_nearest_marker_idx", &cv::aruco::CharucoBoard::getNearestMarkerIdx).
    define_method<std::vector<std::vector<int>>(cv::aruco::CharucoBoard::*)() const>("get_nearest_marker_corners", &cv::aruco::CharucoBoard::getNearestMarkerCorners).
    define_method<bool(cv::aruco::CharucoBoard::*)(cv::InputArray) const>("check_charuco_corners_collinear", &cv::aruco::CharucoBoard::checkCharucoCornersCollinear,
      Arg("charuco_ids"));
}