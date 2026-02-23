#include <opencv2/mcc/checker_detector.hpp>
#include "checker_detector-rb.hpp"

using namespace Rice;

void Init_Mcc_CheckerDetector()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvMcc = define_module_under(rb_mCv, "Mcc");

  Rice::Data_Type<cv::mcc::DetectorParameters> rb_cCvMccDetectorParameters = define_class_under<cv::mcc::DetectorParameters>(rb_mCvMcc, "DetectorParameters").
    define_constructor(Constructor<cv::mcc::DetectorParameters>()).
    define_singleton_function<cv::Ptr<cv::mcc::DetectorParameters>(*)()>("create", &cv::mcc::DetectorParameters::create).
    define_attr("adaptive_thresh_win_size_min", &cv::mcc::DetectorParameters::adaptiveThreshWinSizeMin).
    define_attr("adaptive_thresh_win_size_max", &cv::mcc::DetectorParameters::adaptiveThreshWinSizeMax).
    define_attr("adaptive_thresh_win_size_step", &cv::mcc::DetectorParameters::adaptiveThreshWinSizeStep).
    define_attr("adaptive_thresh_constant", &cv::mcc::DetectorParameters::adaptiveThreshConstant).
    define_attr("min_contours_area_rate", &cv::mcc::DetectorParameters::minContoursAreaRate).
    define_attr("min_contours_area", &cv::mcc::DetectorParameters::minContoursArea).
    define_attr("confidence_threshold", &cv::mcc::DetectorParameters::confidenceThreshold).
    define_attr("min_contour_solidity", &cv::mcc::DetectorParameters::minContourSolidity).
    define_attr("find_candidates_approx_poly_dp_eps_multiplier", &cv::mcc::DetectorParameters::findCandidatesApproxPolyDPEpsMultiplier).
    define_attr("border_width", &cv::mcc::DetectorParameters::borderWidth).
    define_attr("b0factor", &cv::mcc::DetectorParameters::B0factor).
    define_attr("max_error", &cv::mcc::DetectorParameters::maxError).
    define_attr("min_contour_points_allowed", &cv::mcc::DetectorParameters::minContourPointsAllowed).
    define_attr("min_contour_length_allowed", &cv::mcc::DetectorParameters::minContourLengthAllowed).
    define_attr("min_inter_contour_distance", &cv::mcc::DetectorParameters::minInterContourDistance).
    define_attr("min_inter_checker_distance", &cv::mcc::DetectorParameters::minInterCheckerDistance).
    define_attr("min_image_size", &cv::mcc::DetectorParameters::minImageSize).
    define_attr("min_group_size", &cv::mcc::DetectorParameters::minGroupSize);

  Rice::Data_Type<cv::mcc::CCheckerDetector> rb_cCvMccCCheckerDetector = define_class_under<cv::mcc::CCheckerDetector, cv::Algorithm>(rb_mCvMcc, "CCheckerDetector").
    define_method<bool(cv::mcc::CCheckerDetector::*)(dnn::Net)>("set_net", &cv::mcc::CCheckerDetector::setNet,
      Arg("net")).
    define_method<bool(cv::mcc::CCheckerDetector::*)(cv::InputArray, const cv::mcc::TYPECHART, const std::vector<cv::Rect_<int>>&, const int, bool, const cv::Ptr<cv::mcc::DetectorParameters>&)>("process", &cv::mcc::CCheckerDetector::process,
      Arg("image"), Arg("chart_type"), Arg("regions_of_interest"), Arg("nc") = static_cast<const int>(1), Arg("use_net") = static_cast<bool>(false), Arg("params") = static_cast<const cv::Ptr<cv::mcc::DetectorParameters>&>(cv::mcc::DetectorParameters::create())).
    define_method<bool(cv::mcc::CCheckerDetector::*)(cv::InputArray, const cv::mcc::TYPECHART, const int, bool, const cv::Ptr<cv::mcc::DetectorParameters>&)>("process", &cv::mcc::CCheckerDetector::process,
      Arg("image"), Arg("chart_type"), Arg("nc") = static_cast<const int>(1), Arg("use_net") = static_cast<bool>(false), Arg("params") = static_cast<const cv::Ptr<cv::mcc::DetectorParameters>&>(cv::mcc::DetectorParameters::create())).
    define_method<cv::Ptr<cv::mcc::CChecker>(cv::mcc::CCheckerDetector::*)()>("get_best_color_checker", &cv::mcc::CCheckerDetector::getBestColorChecker).
    define_method<std::vector<cv::Ptr<cv::mcc::CChecker>>(cv::mcc::CCheckerDetector::*)()>("get_list_color_checker", &cv::mcc::CCheckerDetector::getListColorChecker).
    define_singleton_function<cv::Ptr<cv::mcc::CCheckerDetector>(*)()>("create", &cv::mcc::CCheckerDetector::create);
}
