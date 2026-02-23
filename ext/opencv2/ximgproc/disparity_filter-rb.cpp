#include <opencv2/ximgproc/disparity_filter.hpp>
#include "disparity_filter-rb.hpp"

using namespace Rice;

void Init_Ximgproc_DisparityFilter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::DisparityFilter> rb_cCvXimgprocDisparityFilter = define_class_under<cv::ximgproc::DisparityFilter, cv::Algorithm>(rb_mCvXimgproc, "DisparityFilter").
    define_method<void(cv::ximgproc::DisparityFilter::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray, cv::Rect, cv::InputArray)>("filter", &cv::ximgproc::DisparityFilter::filter,
      Arg("disparity_map_left"), Arg("left_view"), Arg("filtered_disparity_map"), Arg("disparity_map_right") = static_cast<cv::InputArray>(cv::Mat()), Arg("roi") = static_cast<cv::Rect>(cv::Rect()), Arg("right_view") = static_cast<cv::InputArray>(cv::Mat()));

  Rice::Data_Type<cv::ximgproc::DisparityWLSFilter> rb_cCvXimgprocDisparityWLSFilter = define_class_under<cv::ximgproc::DisparityWLSFilter, cv::ximgproc::DisparityFilter>(rb_mCvXimgproc, "DisparityWLSFilter").
    define_method<double(cv::ximgproc::DisparityWLSFilter::*)()>("get_lambda", &cv::ximgproc::DisparityWLSFilter::getLambda).
    define_method<void(cv::ximgproc::DisparityWLSFilter::*)(double)>("set_lambda", &cv::ximgproc::DisparityWLSFilter::setLambda,
      Arg("_lambda")).
    define_method<double(cv::ximgproc::DisparityWLSFilter::*)()>("get_sigma_color", &cv::ximgproc::DisparityWLSFilter::getSigmaColor).
    define_method<void(cv::ximgproc::DisparityWLSFilter::*)(double)>("set_sigma_color", &cv::ximgproc::DisparityWLSFilter::setSigmaColor,
      Arg("_sigma_color")).
    define_method<int(cv::ximgproc::DisparityWLSFilter::*)()>("get_lr_cthresh", &cv::ximgproc::DisparityWLSFilter::getLRCthresh).
    define_method<void(cv::ximgproc::DisparityWLSFilter::*)(int)>("set_lr_cthresh", &cv::ximgproc::DisparityWLSFilter::setLRCthresh,
      Arg("_lrc_thresh")).
    define_method<int(cv::ximgproc::DisparityWLSFilter::*)()>("get_depth_discontinuity_radius", &cv::ximgproc::DisparityWLSFilter::getDepthDiscontinuityRadius).
    define_method<void(cv::ximgproc::DisparityWLSFilter::*)(int)>("set_depth_discontinuity_radius", &cv::ximgproc::DisparityWLSFilter::setDepthDiscontinuityRadius,
      Arg("_disc_radius")).
    define_method<cv::Mat(cv::ximgproc::DisparityWLSFilter::*)()>("get_confidence_map", &cv::ximgproc::DisparityWLSFilter::getConfidenceMap).
    define_method<cv::Rect(cv::ximgproc::DisparityWLSFilter::*)()>("get_roi", &cv::ximgproc::DisparityWLSFilter::getROI);

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::DisparityWLSFilter>(*)(cv::Ptr<cv::StereoMatcher>)>("create_disparity_wls_filter", &cv::ximgproc::createDisparityWLSFilter,
    Arg("matcher_left"));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::StereoMatcher>(*)(cv::Ptr<cv::StereoMatcher>)>("create_right_matcher", &cv::ximgproc::createRightMatcher,
    Arg("matcher_left"));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::DisparityWLSFilter>(*)(bool)>("create_disparity_wls_filter_generic", &cv::ximgproc::createDisparityWLSFilterGeneric,
    Arg("use_confidence"));

  rb_mCvXimgproc.define_module_function<int(*)(cv::String, cv::OutputArray)>("read_gt", &cv::ximgproc::readGT,
    Arg("src_path"), Arg("dst"));

  rb_mCvXimgproc.define_module_function<double(*)(cv::InputArray, cv::InputArray, cv::Rect)>("compute_mse", &cv::ximgproc::computeMSE,
    Arg("gt"), Arg("src"), Arg("roi"));

  rb_mCvXimgproc.define_module_function<double(*)(cv::InputArray, cv::InputArray, cv::Rect, int)>("compute_bad_pixel_percent", &cv::ximgproc::computeBadPixelPercent,
    Arg("gt"), Arg("src"), Arg("roi"), Arg("thresh") = static_cast<int>(24));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double)>("get_disparity_vis", &cv::ximgproc::getDisparityVis,
    Arg("src"), Arg("dst"), Arg("scale") = static_cast<double>(1.0));
}
