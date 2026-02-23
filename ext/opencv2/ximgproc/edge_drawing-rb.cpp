#include <opencv2/ximgproc/edge_drawing.hpp>
#include "edge_drawing-rb.hpp"

using namespace Rice;

void Init_Ximgproc_EdgeDrawing()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::EdgeDrawing> rb_cCvXimgprocEdgeDrawing = define_class_under<cv::ximgproc::EdgeDrawing, cv::Algorithm>(rb_mCvXimgproc, "EdgeDrawing").
    define_method<void(cv::ximgproc::EdgeDrawing::*)(cv::InputArray)>("detect_edges", &cv::ximgproc::EdgeDrawing::detectEdges,
      Arg("src")).
    define_method<void(cv::ximgproc::EdgeDrawing::*)(cv::OutputArray)>("get_edge_image", &cv::ximgproc::EdgeDrawing::getEdgeImage,
      Arg("dst")).
    define_method<void(cv::ximgproc::EdgeDrawing::*)(cv::OutputArray)>("get_gradient_image", &cv::ximgproc::EdgeDrawing::getGradientImage,
      Arg("dst")).
    define_method<std::vector<std::vector<cv::Point_<int>>>(cv::ximgproc::EdgeDrawing::*)()>("get_segments", &cv::ximgproc::EdgeDrawing::getSegments).
    define_method<std::vector<int>(cv::ximgproc::EdgeDrawing::*)() const>("get_segment_indices_of_lines", &cv::ximgproc::EdgeDrawing::getSegmentIndicesOfLines).
    define_method<void(cv::ximgproc::EdgeDrawing::*)(cv::OutputArray)>("detect_lines", &cv::ximgproc::EdgeDrawing::detectLines,
      Arg("lines")).
    define_method<void(cv::ximgproc::EdgeDrawing::*)(cv::OutputArray)>("detect_ellipses", &cv::ximgproc::EdgeDrawing::detectEllipses,
      Arg("ellipses")).
    define_attr("params", &cv::ximgproc::EdgeDrawing::params).
    define_method<void(cv::ximgproc::EdgeDrawing::*)(const cv::ximgproc::EdgeDrawing::Params&)>("set_params", &cv::ximgproc::EdgeDrawing::setParams,
      Arg("parameters"));

  Rice::Data_Type<cv::ximgproc::EdgeDrawing::Params> rb_cCvXimgprocEdgeDrawingParams = define_class_under<cv::ximgproc::EdgeDrawing::Params>(rb_cCvXimgprocEdgeDrawing, "Params").
    define_constructor(Constructor<cv::ximgproc::EdgeDrawing::Params>()).
    define_attr("p_fmode", &cv::ximgproc::EdgeDrawing::Params::PFmode).
    define_attr("edge_detection_operator", &cv::ximgproc::EdgeDrawing::Params::EdgeDetectionOperator).
    define_attr("gradient_threshold_value", &cv::ximgproc::EdgeDrawing::Params::GradientThresholdValue).
    define_attr("anchor_threshold_value", &cv::ximgproc::EdgeDrawing::Params::AnchorThresholdValue).
    define_attr("scan_interval", &cv::ximgproc::EdgeDrawing::Params::ScanInterval).
    define_attr("min_path_length", &cv::ximgproc::EdgeDrawing::Params::MinPathLength).
    define_attr("sigma", &cv::ximgproc::EdgeDrawing::Params::Sigma).
    define_attr("sum_flag", &cv::ximgproc::EdgeDrawing::Params::SumFlag).
    define_attr("nfa_validation", &cv::ximgproc::EdgeDrawing::Params::NFAValidation).
    define_attr("min_line_length", &cv::ximgproc::EdgeDrawing::Params::MinLineLength).
    define_attr("max_distance_between_two_lines", &cv::ximgproc::EdgeDrawing::Params::MaxDistanceBetweenTwoLines).
    define_attr("line_fit_error_threshold", &cv::ximgproc::EdgeDrawing::Params::LineFitErrorThreshold).
    define_attr("max_error_threshold", &cv::ximgproc::EdgeDrawing::Params::MaxErrorThreshold).
    define_method<void(cv::ximgproc::EdgeDrawing::Params::*)(const cv::FileNode&)>("read", &cv::ximgproc::EdgeDrawing::Params::read,
      Arg("fn")).
    define_method<void(cv::ximgproc::EdgeDrawing::Params::*)(cv::FileStorage&) const>("write", &cv::ximgproc::EdgeDrawing::Params::write,
      Arg("fs"));

  Enum<cv::ximgproc::EdgeDrawing::GradientOperator> rb_cCvXimgprocEdgeDrawingGradientOperator = define_enum_under<cv::ximgproc::EdgeDrawing::GradientOperator>("GradientOperator", rb_cCvXimgprocEdgeDrawing).
    define_value("PREWITT", cv::ximgproc::EdgeDrawing::GradientOperator::PREWITT).
    define_value("SOBEL", cv::ximgproc::EdgeDrawing::GradientOperator::SOBEL).
    define_value("SCHARR", cv::ximgproc::EdgeDrawing::GradientOperator::SCHARR).
    define_value("LSD", cv::ximgproc::EdgeDrawing::GradientOperator::LSD);

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::EdgeDrawing>(*)()>("create_edge_drawing", &cv::ximgproc::createEdgeDrawing);
}
