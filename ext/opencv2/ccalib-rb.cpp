#include <opencv2/ccalib.hpp>
#include "ccalib-rb.hpp"

using namespace Rice;

void Init_Ccalib()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCcalib = define_module_under(rb_mCv, "Ccalib");

  Rice::Data_Type<cv::ccalib::CustomPattern> rb_cCvCcalibCustomPattern = define_class_under<cv::ccalib::CustomPattern, cv::Algorithm>(rb_mCvCcalib, "CustomPattern").
    define_constructor(Constructor<cv::ccalib::CustomPattern>()).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::InputArray, const cv::Size2f, cv::OutputArray)>("create", &cv::ccalib::CustomPattern::create,
      Arg("pattern"), Arg("board_size"), Arg("output") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::InputArray, cv::OutputArray, cv::OutputArray, const double, const double, const bool, cv::OutputArray, cv::OutputArray, cv::OutputArray)>("find_pattern", &cv::ccalib::CustomPattern::findPattern,
      Arg("image"), Arg("matched_features"), Arg("pattern_points"), Arg("ratio") = static_cast<const double>(0.7), Arg("proj_error") = static_cast<const double>(8.0), Arg("refine_position") = static_cast<const bool>(false), Arg("out") = static_cast<cv::OutputArray>(cv::noArray()), Arg("h") = static_cast<cv::OutputArray>(cv::noArray()), Arg("pattern_corners") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<bool(cv::ccalib::CustomPattern::*)()>("initialized?", &cv::ccalib::CustomPattern::isInitialized).
    define_method<void(cv::ccalib::CustomPattern::*)(std::vector<cv::KeyPoint>&)>("get_pattern_points", &cv::ccalib::CustomPattern::getPatternPoints,
      Arg("original_points")).
    define_method<double(cv::ccalib::CustomPattern::*)()>("get_pixel_size", &cv::ccalib::CustomPattern::getPixelSize).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::Ptr<cv::Feature2D>)>("set_feature_detector", &cv::ccalib::CustomPattern::setFeatureDetector,
      Arg("feature_detector")).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::Ptr<cv::Feature2D>)>("set_descriptor_extractor", &cv::ccalib::CustomPattern::setDescriptorExtractor,
      Arg("extractor")).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::Ptr<cv::DescriptorMatcher>)>("set_descriptor_matcher", &cv::ccalib::CustomPattern::setDescriptorMatcher,
      Arg("matcher")).
    define_method<cv::Ptr<cv::Feature2D>(cv::ccalib::CustomPattern::*)()>("get_feature_detector", &cv::ccalib::CustomPattern::getFeatureDetector).
    define_method<cv::Ptr<cv::Feature2D>(cv::ccalib::CustomPattern::*)()>("get_descriptor_extractor", &cv::ccalib::CustomPattern::getDescriptorExtractor).
    define_method<cv::Ptr<cv::DescriptorMatcher>(cv::ccalib::CustomPattern::*)()>("get_descriptor_matcher", &cv::ccalib::CustomPattern::getDescriptorMatcher).
    define_method<double(cv::ccalib::CustomPattern::*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, int, cv::TermCriteria)>("calibrate", &cv::ccalib::CustomPattern::calibrate,
      Arg("object_points"), Arg("image_points"), Arg("image_size"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::COUNT + cv::TermCriteria::Type::EPS, 30, DBL_EPSILON))).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, bool, int)>("find_rt", &cv::ccalib::CustomPattern::findRt,
      Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("flags") = static_cast<int>(cv::SOLVEPNP_ITERATIVE)).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, bool, int)>("find_rt", &cv::ccalib::CustomPattern::findRt,
      Arg("image"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("flags") = static_cast<int>(cv::SOLVEPNP_ITERATIVE)).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, bool, int, float, int, cv::OutputArray, int)>("find_rt_ransac", &cv::ccalib::CustomPattern::findRtRANSAC,
      Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("iterations_count") = static_cast<int>(100), Arg("reprojection_error") = static_cast<float>(8.0), Arg("min_inliers_count") = static_cast<int>(100), Arg("inliers") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(cv::SOLVEPNP_ITERATIVE)).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, bool, int, float, int, cv::OutputArray, int)>("find_rt_ransac", &cv::ccalib::CustomPattern::findRtRANSAC,
      Arg("image"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("iterations_count") = static_cast<int>(100), Arg("reprojection_error") = static_cast<float>(8.0), Arg("min_inliers_count") = static_cast<int>(100), Arg("inliers") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(cv::SOLVEPNP_ITERATIVE)).
    define_method<void(cv::ccalib::CustomPattern::*)(cv::InputOutputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, double, int)>("draw_orientation", &cv::ccalib::CustomPattern::drawOrientation,
      Arg("image"), Arg("tvec"), Arg("rvec"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("axis_length") = static_cast<double>(3), Arg("axis_width") = static_cast<int>(2));
}