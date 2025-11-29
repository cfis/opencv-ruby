#include <opencv2/objdetect/aruco_dictionary.hpp>
#include <opencv2/objdetect/aruco_board.hpp>
#include "aruco_board-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvArucoBoard;
Rice::Class rb_cCvArucoCharucoBoard;
Rice::Class rb_cCvArucoGridBoard;

void Init_ArucoBoard()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");
  
  rb_cCvArucoBoard = define_class_under<cv::aruco::Board>(rb_mCvAruco, "Board").
    define_constructor(Constructor<cv::aruco::Board, cv::InputArrayOfArrays, const cv::aruco::Dictionary&, cv::InputArray>(),
      Arg("obj_points"), Arg("dictionary"), Arg("ids")).
    define_method("get_dictionary", &cv::aruco::Board::getDictionary).
    define_method("get_obj_points", &cv::aruco::Board::getObjPoints).
    define_method("get_ids", &cv::aruco::Board::getIds).
    define_method("get_right_bottom_corner", &cv::aruco::Board::getRightBottomCorner).
    define_method("match_image_points", &cv::aruco::Board::matchImagePoints,
      Arg("detected_corners"), Arg("detected_ids"), Arg("obj_points"), Arg("img_points")).
    define_method("generate_image", &cv::aruco::Board::generateImage,
      Arg("out_size"), Arg("img"), Arg("margin_size") = static_cast<int>(0), Arg("border_bits") = static_cast<int>(1));
  
  rb_cCvArucoGridBoard = define_class_under<cv::aruco::GridBoard, cv::aruco::Board>(rb_mCvAruco, "GridBoard").
    define_constructor(Constructor<cv::aruco::GridBoard, const cv::Size&, float, float, const cv::aruco::Dictionary&, cv::InputArray>(),
      Arg("size"), Arg("marker_length"), Arg("marker_separation"), Arg("dictionary"), Arg("ids") = static_cast<cv::InputArray>(cv::noArray())).
    define_method("get_grid_size", &cv::aruco::GridBoard::getGridSize).
    define_method("get_marker_length", &cv::aruco::GridBoard::getMarkerLength).
    define_method("get_marker_separation", &cv::aruco::GridBoard::getMarkerSeparation);
  
  rb_cCvArucoCharucoBoard = define_class_under<cv::aruco::CharucoBoard, cv::aruco::Board>(rb_mCvAruco, "CharucoBoard").
    define_constructor(Constructor<cv::aruco::CharucoBoard, const cv::Size&, float, float, const cv::aruco::Dictionary&, cv::InputArray>(),
      Arg("size"), Arg("square_length"), Arg("marker_length"), Arg("dictionary"), Arg("ids") = static_cast<cv::InputArray>(cv::noArray())).
    define_method("set_legacy_pattern", &cv::aruco::CharucoBoard::setLegacyPattern,
      Arg("legacy_pattern")).
    define_method("get_legacy_pattern?", &cv::aruco::CharucoBoard::getLegacyPattern).
    define_method("get_chessboard_size", &cv::aruco::CharucoBoard::getChessboardSize).
    define_method("get_square_length", &cv::aruco::CharucoBoard::getSquareLength).
    define_method("get_marker_length", &cv::aruco::CharucoBoard::getMarkerLength).
    define_method("get_chessboard_corners", &cv::aruco::CharucoBoard::getChessboardCorners).
    define_method("get_nearest_marker_idx", &cv::aruco::CharucoBoard::getNearestMarkerIdx).
    define_method("get_nearest_marker_corners", &cv::aruco::CharucoBoard::getNearestMarkerCorners).
    define_method("check_charuco_corners_collinear?", &cv::aruco::CharucoBoard::checkCharucoCornersCollinear,
      Arg("charuco_ids"));
}