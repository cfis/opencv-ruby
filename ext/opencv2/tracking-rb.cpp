#include <opencv2/tracking.hpp>
#include "tracking-rb.hpp"

using namespace Rice;

void Init_Tracking()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvTracking = define_module_under(rb_mCv, "Tracking");

  Rice::Data_Type<cv::TrackerCSRT> rb_cCvTrackerCSRT = define_class_under<cv::TrackerCSRT, cv::Tracker>(rb_mCvTracking, "TrackerCSRT").
    define_singleton_function<cv::Ptr<cv::TrackerCSRT>(*)(const cv::tracking::TrackerCSRT::Params&)>("create", &cv::tracking::TrackerCSRT::create,
      Arg("parameters") = static_cast<const cv::tracking::TrackerCSRT::Params&>(cv::tracking::TrackerCSRT::Params())).
    define_method<void(cv::tracking::TrackerCSRT::*)(cv::InputArray)>("set_initial_mask", &cv::tracking::TrackerCSRT::setInitialMask,
      Arg("mask"));

  Rice::Data_Type<cv::TrackerCSRT::Params> rb_cCvTrackerCSRTParams = define_class_under<cv::TrackerCSRT::Params>(rb_cCvTrackerCSRT, "Params").
    define_constructor(Constructor<cv::tracking::TrackerCSRT::Params>()).
    define_attr("use_hog", &cv::tracking::TrackerCSRT::Params::use_hog).
    define_attr("use_color_names", &cv::tracking::TrackerCSRT::Params::use_color_names).
    define_attr("use_gray", &cv::tracking::TrackerCSRT::Params::use_gray).
    define_attr("use_rgb", &cv::tracking::TrackerCSRT::Params::use_rgb).
    define_attr("use_channel_weights", &cv::tracking::TrackerCSRT::Params::use_channel_weights).
    define_attr("use_segmentation", &cv::tracking::TrackerCSRT::Params::use_segmentation).
    define_attr("window_function", &cv::tracking::TrackerCSRT::Params::window_function).
    define_attr("kaiser_alpha", &cv::tracking::TrackerCSRT::Params::kaiser_alpha).
    define_attr("cheb_attenuation", &cv::tracking::TrackerCSRT::Params::cheb_attenuation).
    define_attr("template_size", &cv::tracking::TrackerCSRT::Params::template_size).
    define_attr("gsl_sigma", &cv::tracking::TrackerCSRT::Params::gsl_sigma).
    define_attr("hog_orientations", &cv::tracking::TrackerCSRT::Params::hog_orientations).
    define_attr("hog_clip", &cv::tracking::TrackerCSRT::Params::hog_clip).
    define_attr("padding", &cv::tracking::TrackerCSRT::Params::padding).
    define_attr("filter_lr", &cv::tracking::TrackerCSRT::Params::filter_lr).
    define_attr("weights_lr", &cv::tracking::TrackerCSRT::Params::weights_lr).
    define_attr("num_hog_channels_used", &cv::tracking::TrackerCSRT::Params::num_hog_channels_used).
    define_attr("admm_iterations", &cv::tracking::TrackerCSRT::Params::admm_iterations).
    define_attr("histogram_bins", &cv::tracking::TrackerCSRT::Params::histogram_bins).
    define_attr("histogram_lr", &cv::tracking::TrackerCSRT::Params::histogram_lr).
    define_attr("background_ratio", &cv::tracking::TrackerCSRT::Params::background_ratio).
    define_attr("number_of_scales", &cv::tracking::TrackerCSRT::Params::number_of_scales).
    define_attr("scale_sigma_factor", &cv::tracking::TrackerCSRT::Params::scale_sigma_factor).
    define_attr("scale_model_max_area", &cv::tracking::TrackerCSRT::Params::scale_model_max_area).
    define_attr("scale_lr", &cv::tracking::TrackerCSRT::Params::scale_lr).
    define_attr("scale_step", &cv::tracking::TrackerCSRT::Params::scale_step).
    define_attr("psr_threshold", &cv::tracking::TrackerCSRT::Params::psr_threshold);

  Rice::Data_Type<cv::TrackerKCF> rb_cCvTrackerKCF = define_class_under<cv::TrackerKCF, cv::Tracker>(rb_mCvTracking, "TrackerKCF").
    define_singleton_function<cv::Ptr<cv::TrackerKCF>(*)(const cv::tracking::TrackerKCF::Params&)>("create", &cv::tracking::TrackerKCF::create,
      Arg("parameters") = static_cast<const cv::tracking::TrackerKCF::Params&>(cv::tracking::TrackerKCF::Params())).
    define_method<void(cv::tracking::TrackerKCF::*)(cv::tracking::TrackerKCF::FeatureExtractorCallbackFN, bool)>("set_feature_extractor", &cv::tracking::TrackerKCF::setFeatureExtractor,
      Arg("callback"), Arg("pca_func") = static_cast<bool>(false));

  Rice::Data_Type<cv::TrackerKCF::Params> rb_cCvTrackerKCFParams = define_class_under<cv::TrackerKCF::Params>(rb_cCvTrackerKCF, "Params").
    define_constructor(Constructor<cv::tracking::TrackerKCF::Params>()).
    define_attr("detect_thresh", &cv::tracking::TrackerKCF::Params::detect_thresh).
    define_attr("sigma", &cv::tracking::TrackerKCF::Params::sigma).
    define_attr("lambda", &cv::tracking::TrackerKCF::Params::lambda).
    define_attr("interp_factor", &cv::tracking::TrackerKCF::Params::interp_factor).
    define_attr("output_sigma_factor", &cv::tracking::TrackerKCF::Params::output_sigma_factor).
    define_attr("pca_learning_rate", &cv::tracking::TrackerKCF::Params::pca_learning_rate).
    define_attr("resize", &cv::tracking::TrackerKCF::Params::resize).
    define_attr("split_coeff", &cv::tracking::TrackerKCF::Params::split_coeff).
    define_attr("wrap_kernel", &cv::tracking::TrackerKCF::Params::wrap_kernel).
    define_attr("compress_feature", &cv::tracking::TrackerKCF::Params::compress_feature).
    define_attr("max_patch_size", &cv::tracking::TrackerKCF::Params::max_patch_size).
    define_attr("compressed_size", &cv::tracking::TrackerKCF::Params::compressed_size).
    define_attr("desc_pca", &cv::tracking::TrackerKCF::Params::desc_pca).
    define_attr("desc_npca", &cv::tracking::TrackerKCF::Params::desc_npca);

  Enum<cv::tracking::TrackerKCF::MODE> rb_cCvTrackerKCFMODE = define_enum_under<cv::tracking::TrackerKCF::MODE>("MODE", rb_cCvTrackerKCF).
    define_value("GRAY", cv::tracking::TrackerKCF::MODE::GRAY).
    define_value("CN", cv::tracking::TrackerKCF::MODE::CN).
    define_value("CUSTOM", cv::tracking::TrackerKCF::MODE::CUSTOM);
}
