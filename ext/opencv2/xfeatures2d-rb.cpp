#include <opencv2/xfeatures2d.hpp>
#include "xfeatures2d-rb.hpp"

using namespace Rice;

void Init_Xfeatures2d()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXfeatures2d = define_module_under(rb_mCv, "Xfeatures2d");

  Rice::Data_Type<cv::xfeatures2d::FREAK> rb_cCvXfeatures2dFREAK = define_class_under<cv::xfeatures2d::FREAK, cv::Feature2D>(rb_mCvXfeatures2d, "FREAK").
    define_constant("NB_SCALES", cv::xfeatures2d::FREAK::NB_SCALES).
    define_constant("NB_PAIRS", cv::xfeatures2d::FREAK::NB_PAIRS).
    define_constant("NB_ORIENPAIRS", cv::xfeatures2d::FREAK::NB_ORIENPAIRS).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::FREAK>(*)(bool, bool, float, int, const std::vector<int>&)>("create", &cv::xfeatures2d::FREAK::create,
      Arg("orientation_normalized") = static_cast<bool>(true), Arg("scale_normalized") = static_cast<bool>(true), Arg("pattern_scale") = static_cast<float>(22.0f), Arg("n_octaves") = static_cast<int>(4), Arg("selected_pairs") = static_cast<const std::vector<int>&>(std::vector<int>())).
    define_method<void(cv::xfeatures2d::FREAK::*)(bool)>("set_orientation_normalized", &cv::xfeatures2d::FREAK::setOrientationNormalized,
      Arg("orientation_normalized")).
    define_method<bool(cv::xfeatures2d::FREAK::*)() const>("get_orientation_normalized?", &cv::xfeatures2d::FREAK::getOrientationNormalized).
    define_method<void(cv::xfeatures2d::FREAK::*)(bool)>("set_scale_normalized", &cv::xfeatures2d::FREAK::setScaleNormalized,
      Arg("scale_normalized")).
    define_method<bool(cv::xfeatures2d::FREAK::*)() const>("get_scale_normalized?", &cv::xfeatures2d::FREAK::getScaleNormalized).
    define_method<void(cv::xfeatures2d::FREAK::*)(double)>("set_pattern_scale", &cv::xfeatures2d::FREAK::setPatternScale,
      Arg("pattern_scale")).
    define_method<double(cv::xfeatures2d::FREAK::*)() const>("get_pattern_scale", &cv::xfeatures2d::FREAK::getPatternScale).
    define_method<void(cv::xfeatures2d::FREAK::*)(int)>("set_n_octaves", &cv::xfeatures2d::FREAK::setNOctaves,
      Arg("n_octaves")).
    define_method<int(cv::xfeatures2d::FREAK::*)() const>("get_n_octaves", &cv::xfeatures2d::FREAK::getNOctaves).
    define_method<cv::String(cv::xfeatures2d::FREAK::*)() const>("get_default_name", &cv::xfeatures2d::FREAK::getDefaultName);

  Rice::Data_Type<cv::xfeatures2d::StarDetector> rb_cCvXfeatures2dStarDetector = define_class_under<cv::xfeatures2d::StarDetector, cv::Feature2D>(rb_mCvXfeatures2d, "StarDetector").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::StarDetector>(*)(int, int, int, int, int)>("create", &cv::xfeatures2d::StarDetector::create,
      Arg("max_size") = static_cast<int>(45), Arg("response_threshold") = static_cast<int>(30), Arg("line_threshold_projected") = static_cast<int>(10), Arg("line_threshold_binarized") = static_cast<int>(8), Arg("suppress_nonmax_size") = static_cast<int>(5)).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_max_size", &cv::xfeatures2d::StarDetector::setMaxSize,
      Arg("_max_size")).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_max_size", &cv::xfeatures2d::StarDetector::getMaxSize).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_response_threshold", &cv::xfeatures2d::StarDetector::setResponseThreshold,
      Arg("_response_threshold")).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_response_threshold", &cv::xfeatures2d::StarDetector::getResponseThreshold).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_line_threshold_projected", &cv::xfeatures2d::StarDetector::setLineThresholdProjected,
      Arg("_line_threshold_projected")).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_line_threshold_projected", &cv::xfeatures2d::StarDetector::getLineThresholdProjected).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_line_threshold_binarized", &cv::xfeatures2d::StarDetector::setLineThresholdBinarized,
      Arg("_line_threshold_binarized")).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_line_threshold_binarized", &cv::xfeatures2d::StarDetector::getLineThresholdBinarized).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_suppress_nonmax_size", &cv::xfeatures2d::StarDetector::setSuppressNonmaxSize,
      Arg("_suppress_nonmax_size")).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_suppress_nonmax_size", &cv::xfeatures2d::StarDetector::getSuppressNonmaxSize).
    define_method<cv::String(cv::xfeatures2d::StarDetector::*)() const>("get_default_name", &cv::xfeatures2d::StarDetector::getDefaultName);

  Rice::Data_Type<cv::xfeatures2d::BriefDescriptorExtractor> rb_cCvXfeatures2dBriefDescriptorExtractor = define_class_under<cv::xfeatures2d::BriefDescriptorExtractor, cv::Feature2D>(rb_mCvXfeatures2d, "BriefDescriptorExtractor").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::BriefDescriptorExtractor>(*)(int, bool)>("create", &cv::xfeatures2d::BriefDescriptorExtractor::create,
      Arg("bytes") = static_cast<int>(32), Arg("use_orientation") = static_cast<bool>(false)).
    define_method<void(cv::xfeatures2d::BriefDescriptorExtractor::*)(int)>("set_descriptor_size", &cv::xfeatures2d::BriefDescriptorExtractor::setDescriptorSize,
      Arg("bytes")).
    define_method<int(cv::xfeatures2d::BriefDescriptorExtractor::*)() const>("get_descriptor_size", &cv::xfeatures2d::BriefDescriptorExtractor::getDescriptorSize).
    define_method<void(cv::xfeatures2d::BriefDescriptorExtractor::*)(bool)>("set_use_orientation", &cv::xfeatures2d::BriefDescriptorExtractor::setUseOrientation,
      Arg("use_orientation")).
    define_method<bool(cv::xfeatures2d::BriefDescriptorExtractor::*)() const>("get_use_orientation?", &cv::xfeatures2d::BriefDescriptorExtractor::getUseOrientation).
    define_method<cv::String(cv::xfeatures2d::BriefDescriptorExtractor::*)() const>("get_default_name", &cv::xfeatures2d::BriefDescriptorExtractor::getDefaultName);

  Rice::Data_Type<cv::xfeatures2d::LUCID> rb_cCvXfeatures2dLUCID = define_class_under<cv::xfeatures2d::LUCID, cv::Feature2D>(rb_mCvXfeatures2d, "LUCID").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::LUCID>(*)(const int, const int)>("create", &cv::xfeatures2d::LUCID::create,
      Arg("lucid_kernel") = static_cast<const int>(1), Arg("blur_kernel") = static_cast<const int>(2)).
    define_method<void(cv::xfeatures2d::LUCID::*)(int)>("set_lucid_kernel", &cv::xfeatures2d::LUCID::setLucidKernel,
      Arg("lucid_kernel")).
    define_method<int(cv::xfeatures2d::LUCID::*)() const>("get_lucid_kernel", &cv::xfeatures2d::LUCID::getLucidKernel).
    define_method<void(cv::xfeatures2d::LUCID::*)(int)>("set_blur_kernel", &cv::xfeatures2d::LUCID::setBlurKernel,
      Arg("blur_kernel")).
    define_method<int(cv::xfeatures2d::LUCID::*)() const>("get_blur_kernel", &cv::xfeatures2d::LUCID::getBlurKernel).
    define_method<cv::String(cv::xfeatures2d::LUCID::*)() const>("get_default_name", &cv::xfeatures2d::LUCID::getDefaultName);

  Rice::Data_Type<cv::xfeatures2d::LATCH> rb_cCvXfeatures2dLATCH = define_class_under<cv::xfeatures2d::LATCH, cv::Feature2D>(rb_mCvXfeatures2d, "LATCH").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::LATCH>(*)(int, bool, int, double)>("create", &cv::xfeatures2d::LATCH::create,
      Arg("bytes") = static_cast<int>(32), Arg("rotation_invariance") = static_cast<bool>(true), Arg("half_ssd_size") = static_cast<int>(3), Arg("sigma") = static_cast<double>(2.0)).
    define_method<void(cv::xfeatures2d::LATCH::*)(int)>("set_bytes", &cv::xfeatures2d::LATCH::setBytes,
      Arg("bytes")).
    define_method<int(cv::xfeatures2d::LATCH::*)() const>("get_bytes", &cv::xfeatures2d::LATCH::getBytes).
    define_method<void(cv::xfeatures2d::LATCH::*)(bool)>("set_rotation_invariance", &cv::xfeatures2d::LATCH::setRotationInvariance,
      Arg("rotation_invariance")).
    define_method<bool(cv::xfeatures2d::LATCH::*)() const>("get_rotation_invariance?", &cv::xfeatures2d::LATCH::getRotationInvariance).
    define_method<void(cv::xfeatures2d::LATCH::*)(int)>("set_half_ss_dsize", &cv::xfeatures2d::LATCH::setHalfSSDsize,
      Arg("half_ssd_size")).
    define_method<int(cv::xfeatures2d::LATCH::*)() const>("get_half_ss_dsize", &cv::xfeatures2d::LATCH::getHalfSSDsize).
    define_method<void(cv::xfeatures2d::LATCH::*)(double)>("set_sigma", &cv::xfeatures2d::LATCH::setSigma,
      Arg("sigma")).
    define_method<double(cv::xfeatures2d::LATCH::*)() const>("get_sigma", &cv::xfeatures2d::LATCH::getSigma).
    define_method<cv::String(cv::xfeatures2d::LATCH::*)() const>("get_default_name", &cv::xfeatures2d::LATCH::getDefaultName);

  Rice::Data_Type<cv::xfeatures2d::BEBLID> rb_cCvXfeatures2dBEBLID = define_class_under<cv::xfeatures2d::BEBLID, cv::Feature2D>(rb_mCvXfeatures2d, "BEBLID").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::BEBLID>(*)(float, int)>("create", &cv::xfeatures2d::BEBLID::create,
      Arg("scale_factor"), Arg("n_bits") = static_cast<int>(cv::xfeatures2d::BEBLID::BeblidSize::SIZE_512_BITS)).
    define_method<void(cv::xfeatures2d::BEBLID::*)(float)>("set_scale_factor", &cv::xfeatures2d::BEBLID::setScaleFactor,
      Arg("scale_factor")).
    define_method<float(cv::xfeatures2d::BEBLID::*)() const>("get_scale_factor", &cv::xfeatures2d::BEBLID::getScaleFactor).
    define_method<cv::String(cv::xfeatures2d::BEBLID::*)() const>("get_default_name", &cv::xfeatures2d::BEBLID::getDefaultName);

  Enum<cv::xfeatures2d::BEBLID::BeblidSize> rb_cCvXfeatures2dBEBLIDBeblidSize = define_enum_under<cv::xfeatures2d::BEBLID::BeblidSize>("BeblidSize", rb_cCvXfeatures2dBEBLID).
    define_value("SIZE_512_BITS", cv::xfeatures2d::BEBLID::BeblidSize::SIZE_512_BITS).
    define_value("SIZE_256_BITS", cv::xfeatures2d::BEBLID::BeblidSize::SIZE_256_BITS);

  Rice::Data_Type<cv::xfeatures2d::TEBLID> rb_cCvXfeatures2dTEBLID = define_class_under<cv::xfeatures2d::TEBLID, cv::Feature2D>(rb_mCvXfeatures2d, "TEBLID").
    define_constructor(Constructor<cv::xfeatures2d::TEBLID>()).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::TEBLID>(*)(float, int)>("create", &cv::xfeatures2d::TEBLID::create,
      Arg("scale_factor"), Arg("n_bits") = static_cast<int>(cv::xfeatures2d::TEBLID::TeblidSize::SIZE_256_BITS)).
    define_method<cv::String(cv::xfeatures2d::TEBLID::*)() const>("get_default_name", &cv::xfeatures2d::TEBLID::getDefaultName);

  Enum<cv::xfeatures2d::TEBLID::TeblidSize> rb_cCvXfeatures2dTEBLIDTeblidSize = define_enum_under<cv::xfeatures2d::TEBLID::TeblidSize>("TeblidSize", rb_cCvXfeatures2dTEBLID).
    define_value("SIZE_256_BITS", cv::xfeatures2d::TEBLID::TeblidSize::SIZE_256_BITS).
    define_value("SIZE_512_BITS", cv::xfeatures2d::TEBLID::TeblidSize::SIZE_512_BITS);

  Rice::Data_Type<cv::xfeatures2d::DAISY> rb_cCvXfeatures2dDAISY = define_class_under<cv::xfeatures2d::DAISY, cv::Feature2D>(rb_mCvXfeatures2d, "DAISY").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::DAISY>(*)(float, int, int, int, cv::xfeatures2d::DAISY::NormalizationType, cv::InputArray, bool, bool)>("create", &cv::xfeatures2d::DAISY::create,
      Arg("radius") = static_cast<float>(15), Arg("q_radius") = static_cast<int>(3), Arg("q_theta") = static_cast<int>(8), Arg("q_hist") = static_cast<int>(8), Arg("norm") = static_cast<cv::xfeatures2d::DAISY::NormalizationType>(cv::xfeatures2d::DAISY::NormalizationType::NRM_NONE), Arg("h") = static_cast<cv::InputArray>(cv::noArray()), Arg("interpolation") = static_cast<bool>(true), Arg("use_orientation") = static_cast<bool>(false)).
    define_method<void(cv::xfeatures2d::DAISY::*)(float)>("set_radius", &cv::xfeatures2d::DAISY::setRadius,
      Arg("radius")).
    define_method<float(cv::xfeatures2d::DAISY::*)() const>("get_radius", &cv::xfeatures2d::DAISY::getRadius).
    define_method<void(cv::xfeatures2d::DAISY::*)(int)>("set_q_radius", &cv::xfeatures2d::DAISY::setQRadius,
      Arg("q_radius")).
    define_method<int(cv::xfeatures2d::DAISY::*)() const>("get_q_radius", &cv::xfeatures2d::DAISY::getQRadius).
    define_method<void(cv::xfeatures2d::DAISY::*)(int)>("set_q_theta", &cv::xfeatures2d::DAISY::setQTheta,
      Arg("q_theta")).
    define_method<int(cv::xfeatures2d::DAISY::*)() const>("get_q_theta", &cv::xfeatures2d::DAISY::getQTheta).
    define_method<void(cv::xfeatures2d::DAISY::*)(int)>("set_q_hist", &cv::xfeatures2d::DAISY::setQHist,
      Arg("q_hist")).
    define_method<int(cv::xfeatures2d::DAISY::*)() const>("get_q_hist", &cv::xfeatures2d::DAISY::getQHist).
    define_method<void(cv::xfeatures2d::DAISY::*)(int)>("set_norm", &cv::xfeatures2d::DAISY::setNorm,
      Arg("norm")).
    define_method<int(cv::xfeatures2d::DAISY::*)() const>("get_norm", &cv::xfeatures2d::DAISY::getNorm).
    define_method<void(cv::xfeatures2d::DAISY::*)(cv::InputArray)>("set_h", &cv::xfeatures2d::DAISY::setH,
      Arg("h")).
    define_method<cv::Mat(cv::xfeatures2d::DAISY::*)() const>("get_h", &cv::xfeatures2d::DAISY::getH).
    define_method<void(cv::xfeatures2d::DAISY::*)(bool)>("set_interpolation", &cv::xfeatures2d::DAISY::setInterpolation,
      Arg("interpolation")).
    define_method<bool(cv::xfeatures2d::DAISY::*)() const>("get_interpolation?", &cv::xfeatures2d::DAISY::getInterpolation).
    define_method<void(cv::xfeatures2d::DAISY::*)(bool)>("set_use_orientation", &cv::xfeatures2d::DAISY::setUseOrientation,
      Arg("use_orientation")).
    define_method<bool(cv::xfeatures2d::DAISY::*)() const>("get_use_orientation?", &cv::xfeatures2d::DAISY::getUseOrientation).
    define_method<cv::String(cv::xfeatures2d::DAISY::*)() const>("get_default_name", &cv::xfeatures2d::DAISY::getDefaultName).
    define_method<void(cv::xfeatures2d::DAISY::*)(cv::InputArray, std::vector<cv::KeyPoint>&, cv::OutputArray)>("compute", &cv::xfeatures2d::DAISY::compute,
      Arg("image"), Arg("keypoints"), Arg("descriptors")).
    define_method<void(cv::xfeatures2d::DAISY::*)(cv::InputArrayOfArrays, std::vector<std::vector<cv::KeyPoint>>&, cv::OutputArrayOfArrays)>("compute", &cv::xfeatures2d::DAISY::compute,
      Arg("images"), Arg("keypoints"), Arg("descriptors")).
    define_method<void(cv::xfeatures2d::DAISY::*)(cv::InputArray, cv::Rect, cv::OutputArray)>("compute", &cv::xfeatures2d::DAISY::compute,
      Arg("image"), Arg("roi"), Arg("descriptors")).
    define_method<void(cv::xfeatures2d::DAISY::*)(cv::InputArray, cv::OutputArray)>("compute", &cv::xfeatures2d::DAISY::compute,
      Arg("image"), Arg("descriptors")).
    define_method<void(cv::xfeatures2d::DAISY::*)(double, double, int, float*) const>("get_descriptor", &cv::xfeatures2d::DAISY::GetDescriptor,
      Arg("y"), Arg("x"), Arg("orientation"), ArgBuffer("descriptor")).
    define_method<bool(cv::xfeatures2d::DAISY::*)(double, double, int, float*, double*) const>("get_descriptor", &cv::xfeatures2d::DAISY::GetDescriptor,
      Arg("y"), Arg("x"), Arg("orientation"), ArgBuffer("descriptor"), ArgBuffer("h")).
    define_method<void(cv::xfeatures2d::DAISY::*)(double, double, int, float*) const>("get_unnormalized_descriptor", &cv::xfeatures2d::DAISY::GetUnnormalizedDescriptor,
      Arg("y"), Arg("x"), Arg("orientation"), ArgBuffer("descriptor")).
    define_method<bool(cv::xfeatures2d::DAISY::*)(double, double, int, float*, double*) const>("get_unnormalized_descriptor", &cv::xfeatures2d::DAISY::GetUnnormalizedDescriptor,
      Arg("y"), Arg("x"), Arg("orientation"), ArgBuffer("descriptor"), ArgBuffer("h"));

  Enum<cv::xfeatures2d::DAISY::NormalizationType> rb_cCvXfeatures2dDAISYNormalizationType = define_enum_under<cv::xfeatures2d::DAISY::NormalizationType>("NormalizationType", rb_cCvXfeatures2dDAISY).
    define_value("NRM_NONE", cv::xfeatures2d::DAISY::NormalizationType::NRM_NONE).
    define_value("NRM_PARTIAL", cv::xfeatures2d::DAISY::NormalizationType::NRM_PARTIAL).
    define_value("NRM_FULL", cv::xfeatures2d::DAISY::NormalizationType::NRM_FULL).
    define_value("NRM_SIFT", cv::xfeatures2d::DAISY::NormalizationType::NRM_SIFT);

  Rice::Data_Type<cv::xfeatures2d::MSDDetector> rb_cCvXfeatures2dMSDDetector = define_class_under<cv::xfeatures2d::MSDDetector, cv::Feature2D>(rb_mCvXfeatures2d, "MSDDetector").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::MSDDetector>(*)(int, int, int, int, float, int, float, int, bool)>("create", &cv::xfeatures2d::MSDDetector::create,
      Arg("m_patch_radius") = static_cast<int>(3), Arg("m_search_area_radius") = static_cast<int>(5), Arg("m_nms_radius") = static_cast<int>(5), Arg("m_nms_scale_radius") = static_cast<int>(0), Arg("m_th_saliency") = static_cast<float>(250.0f), Arg("m_k_nn") = static_cast<int>(4), Arg("m_scale_factor") = static_cast<float>(1.25f), Arg("m_n_scales") = static_cast<int>(-1), Arg("m_compute_orientation") = static_cast<bool>(false)).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_patch_radius", &cv::xfeatures2d::MSDDetector::setPatchRadius,
      Arg("patch_radius")).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_patch_radius", &cv::xfeatures2d::MSDDetector::getPatchRadius).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_search_area_radius", &cv::xfeatures2d::MSDDetector::setSearchAreaRadius,
      Arg("use_orientation")).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_search_area_radius", &cv::xfeatures2d::MSDDetector::getSearchAreaRadius).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_nms_radius", &cv::xfeatures2d::MSDDetector::setNmsRadius,
      Arg("nms_radius")).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_nms_radius", &cv::xfeatures2d::MSDDetector::getNmsRadius).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_nms_scale_radius", &cv::xfeatures2d::MSDDetector::setNmsScaleRadius,
      Arg("nms_scale_radius")).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_nms_scale_radius", &cv::xfeatures2d::MSDDetector::getNmsScaleRadius).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(float)>("set_th_saliency", &cv::xfeatures2d::MSDDetector::setThSaliency,
      Arg("th_saliency")).
    define_method<float(cv::xfeatures2d::MSDDetector::*)() const>("get_th_saliency", &cv::xfeatures2d::MSDDetector::getThSaliency).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_knn", &cv::xfeatures2d::MSDDetector::setKNN,
      Arg("k_nn")).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_knn", &cv::xfeatures2d::MSDDetector::getKNN).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(float)>("set_scale_factor", &cv::xfeatures2d::MSDDetector::setScaleFactor,
      Arg("scale_factor")).
    define_method<float(cv::xfeatures2d::MSDDetector::*)() const>("get_scale_factor", &cv::xfeatures2d::MSDDetector::getScaleFactor).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_n_scales", &cv::xfeatures2d::MSDDetector::setNScales,
      Arg("use_orientation")).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_n_scales", &cv::xfeatures2d::MSDDetector::getNScales).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(bool)>("set_compute_orientation", &cv::xfeatures2d::MSDDetector::setComputeOrientation,
      Arg("compute_orientation")).
    define_method<bool(cv::xfeatures2d::MSDDetector::*)() const>("get_compute_orientation?", &cv::xfeatures2d::MSDDetector::getComputeOrientation).
    define_method<cv::String(cv::xfeatures2d::MSDDetector::*)() const>("get_default_name", &cv::xfeatures2d::MSDDetector::getDefaultName);

  Rice::Data_Type<cv::xfeatures2d::VGG> rb_cCvXfeatures2dVGG = define_class_under<cv::xfeatures2d::VGG, cv::Feature2D>(rb_mCvXfeatures2d, "VGG").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::VGG>(*)(int, float, bool, bool, float, bool)>("create", &cv::xfeatures2d::VGG::create,
      Arg("desc") = static_cast<int>(cv::xfeatures2d::VGG::VGG_120), Arg("isigma") = static_cast<float>(1.4f), Arg("img_normalize") = static_cast<bool>(true), Arg("use_scale_orientation") = static_cast<bool>(true), Arg("scale_factor") = static_cast<float>(6.25f), Arg("dsc_normalize") = static_cast<bool>(false)).
    define_method<cv::String(cv::xfeatures2d::VGG::*)() const>("get_default_name", &cv::xfeatures2d::VGG::getDefaultName).
    define_method<void(cv::xfeatures2d::VGG::*)(const float)>("set_sigma", &cv::xfeatures2d::VGG::setSigma,
      Arg("isigma")).
    define_method<float(cv::xfeatures2d::VGG::*)() const>("get_sigma", &cv::xfeatures2d::VGG::getSigma).
    define_method<void(cv::xfeatures2d::VGG::*)(const bool)>("set_use_normalize_image", &cv::xfeatures2d::VGG::setUseNormalizeImage,
      Arg("img_normalize")).
    define_method<bool(cv::xfeatures2d::VGG::*)() const>("get_use_normalize_image?", &cv::xfeatures2d::VGG::getUseNormalizeImage).
    define_method<void(cv::xfeatures2d::VGG::*)(const bool)>("set_use_scale_orientation", &cv::xfeatures2d::VGG::setUseScaleOrientation,
      Arg("use_scale_orientation")).
    define_method<bool(cv::xfeatures2d::VGG::*)() const>("get_use_scale_orientation?", &cv::xfeatures2d::VGG::getUseScaleOrientation).
    define_method<void(cv::xfeatures2d::VGG::*)(const float)>("set_scale_factor", &cv::xfeatures2d::VGG::setScaleFactor,
      Arg("scale_factor")).
    define_method<float(cv::xfeatures2d::VGG::*)() const>("get_scale_factor", &cv::xfeatures2d::VGG::getScaleFactor).
    define_method<void(cv::xfeatures2d::VGG::*)(const bool)>("set_use_normalize_descriptor", &cv::xfeatures2d::VGG::setUseNormalizeDescriptor,
      Arg("dsc_normalize")).
    define_method<bool(cv::xfeatures2d::VGG::*)() const>("get_use_normalize_descriptor?", &cv::xfeatures2d::VGG::getUseNormalizeDescriptor);

  rb_cCvXfeatures2dVGG.define_constant("VGG_120", (int)cv::xfeatures2d::VGG::VGG_120);
  rb_cCvXfeatures2dVGG.define_constant("VGG_80", (int)cv::xfeatures2d::VGG::VGG_80);
  rb_cCvXfeatures2dVGG.define_constant("VGG_64", (int)cv::xfeatures2d::VGG::VGG_64);
  rb_cCvXfeatures2dVGG.define_constant("VGG_48", (int)cv::xfeatures2d::VGG::VGG_48);

  Rice::Data_Type<cv::xfeatures2d::BoostDesc> rb_cCvXfeatures2dBoostDesc = define_class_under<cv::xfeatures2d::BoostDesc, cv::Feature2D>(rb_mCvXfeatures2d, "BoostDesc").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::BoostDesc>(*)(int, bool, float)>("create", &cv::xfeatures2d::BoostDesc::create,
      Arg("desc") = static_cast<int>(cv::xfeatures2d::BoostDesc::BINBOOST_256), Arg("use_scale_orientation") = static_cast<bool>(true), Arg("scale_factor") = static_cast<float>(6.25f)).
    define_method<cv::String(cv::xfeatures2d::BoostDesc::*)() const>("get_default_name", &cv::xfeatures2d::BoostDesc::getDefaultName).
    define_method<void(cv::xfeatures2d::BoostDesc::*)(const bool)>("set_use_scale_orientation", &cv::xfeatures2d::BoostDesc::setUseScaleOrientation,
      Arg("use_scale_orientation")).
    define_method<bool(cv::xfeatures2d::BoostDesc::*)() const>("get_use_scale_orientation?", &cv::xfeatures2d::BoostDesc::getUseScaleOrientation).
    define_method<void(cv::xfeatures2d::BoostDesc::*)(const float)>("set_scale_factor", &cv::xfeatures2d::BoostDesc::setScaleFactor,
      Arg("scale_factor")).
    define_method<float(cv::xfeatures2d::BoostDesc::*)() const>("get_scale_factor", &cv::xfeatures2d::BoostDesc::getScaleFactor);

  rb_cCvXfeatures2dBoostDesc.define_constant("BGM", (int)cv::xfeatures2d::BoostDesc::BGM);
  rb_cCvXfeatures2dBoostDesc.define_constant("BGM_HARD", (int)cv::xfeatures2d::BoostDesc::BGM_HARD);
  rb_cCvXfeatures2dBoostDesc.define_constant("BGM_BILINEAR", (int)cv::xfeatures2d::BoostDesc::BGM_BILINEAR);
  rb_cCvXfeatures2dBoostDesc.define_constant("LBGM", (int)cv::xfeatures2d::BoostDesc::LBGM);
  rb_cCvXfeatures2dBoostDesc.define_constant("BINBOOST_64", (int)cv::xfeatures2d::BoostDesc::BINBOOST_64);
  rb_cCvXfeatures2dBoostDesc.define_constant("BINBOOST_128", (int)cv::xfeatures2d::BoostDesc::BINBOOST_128);
  rb_cCvXfeatures2dBoostDesc.define_constant("BINBOOST_256", (int)cv::xfeatures2d::BoostDesc::BINBOOST_256);

  Rice::Data_Type<cv::xfeatures2d::PCTSignatures> rb_cCvXfeatures2dPCTSignatures = define_class_under<cv::xfeatures2d::PCTSignatures, cv::Algorithm>(rb_mCvXfeatures2d, "PCTSignatures").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::PCTSignatures>(*)(const int, const int, const int)>("create", &cv::xfeatures2d::PCTSignatures::create,
      Arg("init_sample_count") = static_cast<const int>(2000), Arg("init_seed_count") = static_cast<const int>(400), Arg("point_distribution") = static_cast<const int>(0)).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::PCTSignatures>(*)(const std::vector<cv::Point_<float>>&, const int)>("create", &cv::xfeatures2d::PCTSignatures::create,
      Arg("init_sampling_points"), Arg("init_seed_count")).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::PCTSignatures>(*)(const std::vector<cv::Point_<float>>&, const std::vector<int>&)>("create", &cv::xfeatures2d::PCTSignatures::create,
      Arg("init_sampling_points"), Arg("init_cluster_seed_indexes")).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(cv::InputArray, cv::OutputArray) const>("compute_signature", &cv::xfeatures2d::PCTSignatures::computeSignature,
      Arg("image"), Arg("signature")).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(const std::vector<cv::Mat>&, std::vector<cv::Mat>&) const>("compute_signatures", &cv::xfeatures2d::PCTSignatures::computeSignatures,
      Arg("images"), Arg("signatures")).
    define_singleton_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, float, int)>("draw_signature", &cv::xfeatures2d::PCTSignatures::drawSignature,
      Arg("source"), Arg("signature"), Arg("result"), Arg("radius_to_shorter_side_ratio") = static_cast<float>(1.0 / 8), Arg("border_thickness") = static_cast<int>(1)).
    define_singleton_function<void(*)(std::vector<cv::Point_<float>>&, const int, int)>("generate_init_points", &cv::xfeatures2d::PCTSignatures::generateInitPoints,
      Arg("init_points"), Arg("count"), Arg("point_distribution")).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_sample_count", &cv::xfeatures2d::PCTSignatures::getSampleCount).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_grayscale_bits", &cv::xfeatures2d::PCTSignatures::getGrayscaleBits).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_grayscale_bits", &cv::xfeatures2d::PCTSignatures::setGrayscaleBits,
      Arg("grayscale_bits")).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_window_radius", &cv::xfeatures2d::PCTSignatures::getWindowRadius).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_window_radius", &cv::xfeatures2d::PCTSignatures::setWindowRadius,
      Arg("radius")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_x", &cv::xfeatures2d::PCTSignatures::getWeightX).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_x", &cv::xfeatures2d::PCTSignatures::setWeightX,
      Arg("weight")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_y", &cv::xfeatures2d::PCTSignatures::getWeightY).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_y", &cv::xfeatures2d::PCTSignatures::setWeightY,
      Arg("weight")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_l", &cv::xfeatures2d::PCTSignatures::getWeightL).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_l", &cv::xfeatures2d::PCTSignatures::setWeightL,
      Arg("weight")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_a", &cv::xfeatures2d::PCTSignatures::getWeightA).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_a", &cv::xfeatures2d::PCTSignatures::setWeightA,
      Arg("weight")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_b", &cv::xfeatures2d::PCTSignatures::getWeightB).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_b", &cv::xfeatures2d::PCTSignatures::setWeightB,
      Arg("weight")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_contrast", &cv::xfeatures2d::PCTSignatures::getWeightContrast).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_contrast", &cv::xfeatures2d::PCTSignatures::setWeightContrast,
      Arg("weight")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_entropy", &cv::xfeatures2d::PCTSignatures::getWeightEntropy).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_entropy", &cv::xfeatures2d::PCTSignatures::setWeightEntropy,
      Arg("weight")).
    define_method<std::vector<cv::Point_<float>>(cv::xfeatures2d::PCTSignatures::*)() const>("get_sampling_points", &cv::xfeatures2d::PCTSignatures::getSamplingPoints).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int, float)>("set_weight", &cv::xfeatures2d::PCTSignatures::setWeight,
      Arg("idx"), Arg("value")).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(const std::vector<float>&)>("set_weights", &cv::xfeatures2d::PCTSignatures::setWeights,
      Arg("weights")).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int, float)>("set_translation", &cv::xfeatures2d::PCTSignatures::setTranslation,
      Arg("idx"), Arg("value")).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(const std::vector<float>&)>("set_translations", &cv::xfeatures2d::PCTSignatures::setTranslations,
      Arg("translations")).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(std::vector<cv::Point_<float>>)>("set_sampling_points", &cv::xfeatures2d::PCTSignatures::setSamplingPoints,
      Arg("sampling_points")).
    define_method<std::vector<int>(cv::xfeatures2d::PCTSignatures::*)() const>("get_init_seed_indexes", &cv::xfeatures2d::PCTSignatures::getInitSeedIndexes).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(std::vector<int>)>("set_init_seed_indexes", &cv::xfeatures2d::PCTSignatures::setInitSeedIndexes,
      Arg("init_seed_indexes")).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_init_seed_count", &cv::xfeatures2d::PCTSignatures::getInitSeedCount).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_iteration_count", &cv::xfeatures2d::PCTSignatures::getIterationCount).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_iteration_count", &cv::xfeatures2d::PCTSignatures::setIterationCount,
      Arg("iteration_count")).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_max_clusters_count", &cv::xfeatures2d::PCTSignatures::getMaxClustersCount).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_max_clusters_count", &cv::xfeatures2d::PCTSignatures::setMaxClustersCount,
      Arg("max_clusters_count")).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_cluster_min_size", &cv::xfeatures2d::PCTSignatures::getClusterMinSize).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_cluster_min_size", &cv::xfeatures2d::PCTSignatures::setClusterMinSize,
      Arg("cluster_min_size")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_joining_distance", &cv::xfeatures2d::PCTSignatures::getJoiningDistance).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_joining_distance", &cv::xfeatures2d::PCTSignatures::setJoiningDistance,
      Arg("joining_distance")).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_drop_threshold", &cv::xfeatures2d::PCTSignatures::getDropThreshold).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_drop_threshold", &cv::xfeatures2d::PCTSignatures::setDropThreshold,
      Arg("drop_threshold")).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_distance_function", &cv::xfeatures2d::PCTSignatures::getDistanceFunction).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_distance_function", &cv::xfeatures2d::PCTSignatures::setDistanceFunction,
      Arg("distance_function"));

  Enum<cv::xfeatures2d::PCTSignatures::DistanceFunction> rb_cCvXfeatures2dPCTSignaturesDistanceFunction = define_enum_under<cv::xfeatures2d::PCTSignatures::DistanceFunction>("DistanceFunction", rb_cCvXfeatures2dPCTSignatures).
    define_value("L0_25", cv::xfeatures2d::PCTSignatures::DistanceFunction::L0_25).
    define_value("L0_5", cv::xfeatures2d::PCTSignatures::DistanceFunction::L0_5).
    define_value("L1", cv::xfeatures2d::PCTSignatures::DistanceFunction::L1).
    define_value("L2", cv::xfeatures2d::PCTSignatures::DistanceFunction::L2).
    define_value("L2SQUARED", cv::xfeatures2d::PCTSignatures::DistanceFunction::L2SQUARED).
    define_value("L5", cv::xfeatures2d::PCTSignatures::DistanceFunction::L5).
    define_value("L_INFINITY", cv::xfeatures2d::PCTSignatures::DistanceFunction::L_INFINITY);

  Enum<cv::xfeatures2d::PCTSignatures::PointDistribution> rb_cCvXfeatures2dPCTSignaturesPointDistribution = define_enum_under<cv::xfeatures2d::PCTSignatures::PointDistribution>("PointDistribution", rb_cCvXfeatures2dPCTSignatures).
    define_value("UNIFORM", cv::xfeatures2d::PCTSignatures::PointDistribution::UNIFORM).
    define_value("REGULAR", cv::xfeatures2d::PCTSignatures::PointDistribution::REGULAR).
    define_value("NORMAL", cv::xfeatures2d::PCTSignatures::PointDistribution::NORMAL);

  Enum<cv::xfeatures2d::PCTSignatures::SimilarityFunction> rb_cCvXfeatures2dPCTSignaturesSimilarityFunction = define_enum_under<cv::xfeatures2d::PCTSignatures::SimilarityFunction>("SimilarityFunction", rb_cCvXfeatures2dPCTSignatures).
    define_value("MINUS", cv::xfeatures2d::PCTSignatures::SimilarityFunction::MINUS).
    define_value("GAUSSIAN", cv::xfeatures2d::PCTSignatures::SimilarityFunction::GAUSSIAN).
    define_value("HEURISTIC", cv::xfeatures2d::PCTSignatures::SimilarityFunction::HEURISTIC);

  Rice::Data_Type<cv::xfeatures2d::PCTSignaturesSQFD> rb_cCvXfeatures2dPCTSignaturesSQFD = define_class_under<cv::xfeatures2d::PCTSignaturesSQFD, cv::Algorithm>(rb_mCvXfeatures2d, "PCTSignaturesSQFD").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::PCTSignaturesSQFD>(*)(const int, const int, const float)>("create", &cv::xfeatures2d::PCTSignaturesSQFD::create,
      Arg("distance_function") = static_cast<const int>(3), Arg("similarity_function") = static_cast<const int>(2), Arg("similarity_parameter") = static_cast<const float>(1.0f)).
    define_method<float(cv::xfeatures2d::PCTSignaturesSQFD::*)(cv::InputArray, cv::InputArray) const>("compute_quadratic_form_distance", &cv::xfeatures2d::PCTSignaturesSQFD::computeQuadraticFormDistance,
      Arg("_signature0"), Arg("_signature1")).
    define_method<void(cv::xfeatures2d::PCTSignaturesSQFD::*)(const cv::Mat&, const std::vector<cv::Mat>&, std::vector<float>&) const>("compute_quadratic_form_distances", &cv::xfeatures2d::PCTSignaturesSQFD::computeQuadraticFormDistances,
      Arg("source_signature"), Arg("image_signatures"), Arg("distances"));

  Rice::Data_Type<cv::xfeatures2d::Elliptic_KeyPoint> rb_cCvXfeatures2dEllipticKeyPoint = define_class_under<cv::xfeatures2d::Elliptic_KeyPoint, cv::KeyPoint>(rb_mCvXfeatures2d, "EllipticKeyPoint").
    define_attr("axes", &cv::xfeatures2d::Elliptic_KeyPoint::axes).
    define_attr("si", &cv::xfeatures2d::Elliptic_KeyPoint::si).
    define_attr("transf", &cv::xfeatures2d::Elliptic_KeyPoint::transf).
    define_constructor(Constructor<cv::xfeatures2d::Elliptic_KeyPoint>()).
    define_constructor(Constructor<cv::xfeatures2d::Elliptic_KeyPoint, cv::Point2f, float, cv::Size, float, float>(),
      Arg("pt"), Arg("angle"), Arg("axes"), Arg("size"), Arg("si"));

  Rice::Data_Type<cv::xfeatures2d::HarrisLaplaceFeatureDetector> rb_cCvXfeatures2dHarrisLaplaceFeatureDetector = define_class_under<cv::xfeatures2d::HarrisLaplaceFeatureDetector, cv::Feature2D>(rb_mCvXfeatures2d, "HarrisLaplaceFeatureDetector").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>(*)(int, float, float, int, int)>("create", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::create,
      Arg("num_octaves") = static_cast<int>(6), Arg("corn_thresh") = static_cast<float>(0.01f), Arg("dog_thresh") = static_cast<float>(0.01f), Arg("max_corners") = static_cast<int>(5000), Arg("num_layers") = static_cast<int>(4)).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(int)>("set_num_octaves", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setNumOctaves,
      Arg("num_octaves_")).
    define_method<int(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_num_octaves", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getNumOctaves).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(float)>("set_corn_thresh", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setCornThresh,
      Arg("corn_thresh_")).
    define_method<float(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_corn_thresh", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getCornThresh).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(float)>("set_dog_thresh", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setDOGThresh,
      Arg("dog_thresh_")).
    define_method<float(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_dog_thresh", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getDOGThresh).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(int)>("set_max_corners", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setMaxCorners,
      Arg("max_corners_")).
    define_method<int(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_max_corners", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getMaxCorners).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(int)>("set_num_layers", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setNumLayers,
      Arg("num_layers_")).
    define_method<int(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_num_layers", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getNumLayers).
    define_method<cv::String(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_default_name", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getDefaultName);

  Rice::Data_Type<cv::xfeatures2d::AffineFeature2D> rb_cCvXfeatures2dAffineFeature2D = define_class_under<cv::xfeatures2d::AffineFeature2D, cv::Feature2D>(rb_mCvXfeatures2d, "AffineFeature2D").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::AffineFeature2D>(*)(cv::Ptr<cv::Feature2D>, cv::Ptr<cv::Feature2D>)>("create", &cv::xfeatures2d::AffineFeature2D::create,
      Arg("keypoint_detector"), Arg("descriptor_extractor")).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::AffineFeature2D>(*)(cv::Ptr<cv::Feature2D>)>("create", &cv::xfeatures2d::AffineFeature2D::create,
      Arg("keypoint_detector")).
    define_method<void(cv::xfeatures2d::AffineFeature2D::*)(cv::InputArray, std::vector<cv::xfeatures2d::Elliptic_KeyPoint>&, cv::InputArray)>("detect", &cv::xfeatures2d::AffineFeature2D::detect,
      Arg("image"), Arg("keypoints"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<void(cv::xfeatures2d::AffineFeature2D::*)(cv::InputArray, cv::InputArray, std::vector<cv::xfeatures2d::Elliptic_KeyPoint>&, cv::OutputArray, bool)>("detect_and_compute", &cv::xfeatures2d::AffineFeature2D::detectAndCompute,
      Arg("image"), Arg("mask"), Arg("keypoints"), Arg("descriptors"), Arg("use_provided_keypoints") = static_cast<bool>(false));

  Rice::Data_Type<cv::xfeatures2d::TBMR> rb_cCvXfeatures2dTBMR = define_class_under<cv::xfeatures2d::TBMR, cv::xfeatures2d::AffineFeature2D>(rb_mCvXfeatures2d, "TBMR").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::TBMR>(*)(int, float, float, int)>("create", &cv::xfeatures2d::TBMR::create,
      Arg("min_area") = static_cast<int>(60), Arg("max_area_relative") = static_cast<float>(0.01f), Arg("scale_factor") = static_cast<float>(1.25f), Arg("n_scales") = static_cast<int>(-1)).
    define_method<void(cv::xfeatures2d::TBMR::*)(int)>("set_min_area", &cv::xfeatures2d::TBMR::setMinArea,
      Arg("min_area")).
    define_method<int(cv::xfeatures2d::TBMR::*)() const>("get_min_area", &cv::xfeatures2d::TBMR::getMinArea).
    define_method<void(cv::xfeatures2d::TBMR::*)(float)>("set_max_area_relative", &cv::xfeatures2d::TBMR::setMaxAreaRelative,
      Arg("max_area")).
    define_method<float(cv::xfeatures2d::TBMR::*)() const>("get_max_area_relative", &cv::xfeatures2d::TBMR::getMaxAreaRelative).
    define_method<void(cv::xfeatures2d::TBMR::*)(float)>("set_scale_factor", &cv::xfeatures2d::TBMR::setScaleFactor,
      Arg("scale_factor")).
    define_method<float(cv::xfeatures2d::TBMR::*)() const>("get_scale_factor", &cv::xfeatures2d::TBMR::getScaleFactor).
    define_method<void(cv::xfeatures2d::TBMR::*)(int)>("set_n_scales", &cv::xfeatures2d::TBMR::setNScales,
      Arg("n_scales")).
    define_method<int(cv::xfeatures2d::TBMR::*)() const>("get_n_scales", &cv::xfeatures2d::TBMR::getNScales).
    define_method<cv::String(cv::xfeatures2d::TBMR::*)() const>("get_default_name", &cv::xfeatures2d::TBMR::getDefaultName);

  rb_mCvXfeatures2d.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool, cv::FastFeatureDetector::DetectorType)>("fast_for_point_set", &cv::xfeatures2d::FASTForPointSet,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression") = static_cast<bool>(true), Arg("type") = static_cast<cv::FastFeatureDetector::DetectorType>(cv::FastFeatureDetector::DetectorType::TYPE_9_16));

  rb_mCvXfeatures2d.define_module_function<void(*)(const cv::Size&, const cv::Size&, const std::vector<cv::KeyPoint>&, const std::vector<cv::KeyPoint>&, const std::vector<cv::DMatch>&, std::vector<cv::DMatch>&, const bool, const bool, const double)>("match_gms", &cv::xfeatures2d::matchGMS,
    Arg("size1"), Arg("size2"), Arg("keypoints1"), Arg("keypoints2"), Arg("matches1to2"), Arg("matches_gms"), Arg("with_rotation") = static_cast<const bool>(false), Arg("with_scale") = static_cast<const bool>(false), Arg("threshold_factor") = static_cast<const double>(6.0));

  rb_mCvXfeatures2d.define_module_function<void(*)(const std::vector<cv::KeyPoint>&, const std::vector<cv::KeyPoint>&, const std::vector<int>&, const std::vector<int>&, std::vector<cv::DMatch>&)>("match_logos", &cv::xfeatures2d::matchLOGOS,
    Arg("keypoints1"), Arg("keypoints2"), Arg("nn1"), Arg("nn2"), Arg("matches1to2"));
}
