#include <opencv2/features2d.hpp>
#include "../opencv_ruby_version.hpp"
#include "core/cvstd_wrapper-rb.hpp"
#include "features2d-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvAKAZE;
Rice::Class rb_cCvAccumulatorChar;
Rice::Class rb_cCvAccumulatorShort;
Rice::Class rb_cCvAccumulatorUnsignedChar;
Rice::Class rb_cCvAccumulatorUnsignedShort;
Rice::Class rb_cCvAffineFeature;
Rice::Class rb_cCvAgastFeatureDetector;
Rice::Class rb_cCvBFMatcher;
Rice::Class rb_cCvBOWImgDescriptorExtractor;
Rice::Class rb_cCvBOWKMeansTrainer;
Rice::Class rb_cCvBOWTrainer;
Rice::Class rb_cCvBRISK;
Rice::Class rb_cCvDescriptorMatcher;
Rice::Class rb_cCvFastFeatureDetector;
Rice::Class rb_cCvFeature2D;
Rice::Class rb_cCvFlannBasedMatcher;
Rice::Class rb_cCvGFTTDetector;
Rice::Class rb_cCvKAZE;
Rice::Class rb_cCvKeyPointsFilter;
Rice::Class rb_cCvMSER;
Rice::Class rb_cCvORB;
Rice::Class rb_cCvSIFT;
Rice::Class rb_cCvSimpleBlobDetector;
Data_Type<cv::SimpleBlobDetector::Params> rb_cCvSimpleBlobDetectorParams;

template<typename Data_Type_T, typename T>
inline void Accumulator_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void SL2_builder(Data_Type_T& klass)
{
  klass.define_constant("NormType", cv::SL2<T>::normType).
    template define_method("call", &cv::SL2<T>::operator(),
      Arg("a"), Arg("b"), Arg("size"));
};

template<typename Data_Type_T, typename T>
inline void L2_builder(Data_Type_T& klass)
{
  klass.define_constant("NormType", cv::L2<T>::normType).
    template define_method("call", &cv::L2<T>::operator(),
      Arg("a"), Arg("b"), Arg("size"));
};

template<typename Data_Type_T, typename T>
inline void L1_builder(Data_Type_T& klass)
{
  klass.define_constant("NormType", cv::L1<T>::normType).
    template define_method("call", &cv::L1<T>::operator(),
      Arg("a"), Arg("b"), Arg("size"));
};

void Init_Features2d()
{
  Module rb_mCv = define_module("Cv");
  
  rb_cCvKeyPointsFilter = define_class_under<cv::KeyPointsFilter>(rb_mCv, "KeyPointsFilter").
    define_constructor(Constructor<cv::KeyPointsFilter>()).
    define_singleton_function("run_by_image_border", &cv::KeyPointsFilter::runByImageBorder,
      Arg("keypoints"), Arg("image_size"), Arg("border_size")).
    define_singleton_function("run_by_keypoint_size", &cv::KeyPointsFilter::runByKeypointSize,
      Arg("keypoints"), Arg("min_size"), Arg("max_size") = static_cast<float>(FLT_MAX)).
    define_singleton_function("run_by_pixels_mask", &cv::KeyPointsFilter::runByPixelsMask,
      Arg("keypoints"), Arg("mask")).
    define_singleton_function("remove_duplicated", &cv::KeyPointsFilter::removeDuplicated,
      Arg("keypoints")).
    define_singleton_function("remove_duplicated_sorted", &cv::KeyPointsFilter::removeDuplicatedSorted,
      Arg("keypoints")).
    define_singleton_function("retain_best", &cv::KeyPointsFilter::retainBest,
      Arg("keypoints"), Arg("npoints"));
  
#if RUBY_CV_VERSION >= 407
  rb_cCvKeyPointsFilter.
    define_singleton_function("run_by_pixels_mask2_vector_point", &cv::KeyPointsFilter::runByPixelsMask2VectorPoint,
      Arg("keypoints"), Arg("remove_from"), Arg("mask"));
#endif

  rb_cCvFeature2D = define_class_under<cv::Feature2D, cv::Algorithm>(rb_mCv, "Feature2D").
    define_constructor(Constructor<cv::Feature2D>()).
    define_method<void(cv::Feature2D::*)(cv::InputArray, std::vector<cv::KeyPoint>&, cv::InputArray)>("detect", &cv::Feature2D::detect,
      Arg("image"), Arg("keypoints"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<void(cv::Feature2D::*)(cv::InputArrayOfArrays, std::vector<std::vector<cv::KeyPoint>>&, cv::InputArrayOfArrays)>("detect", &cv::Feature2D::detect,
      Arg("images"), Arg("keypoints"), Arg("masks") = static_cast<cv::InputArrayOfArrays>(cv::noArray())).
    define_method<void(cv::Feature2D::*)(cv::InputArray, std::vector<cv::KeyPoint>&, cv::OutputArray)>("compute", &cv::Feature2D::compute,
      Arg("image"), Arg("keypoints"), Arg("descriptors")).
    define_method<void(cv::Feature2D::*)(cv::InputArrayOfArrays, std::vector<std::vector<cv::KeyPoint>>&, cv::OutputArrayOfArrays)>("compute", &cv::Feature2D::compute,
      Arg("images"), Arg("keypoints"), Arg("descriptors")).
    define_method("detect_and_compute", &cv::Feature2D::detectAndCompute,
      Arg("image"), Arg("mask"), Arg("keypoints"), Arg("descriptors"), Arg("use_provided_keypoints") = static_cast<bool>(false)).
    define_method("descriptor_size", &cv::Feature2D::descriptorSize).
    define_method("descriptor_type", &cv::Feature2D::descriptorType).
    define_method("default_norm", &cv::Feature2D::defaultNorm).
    define_method<void(cv::Feature2D::*)(const cv::String&) const>("write", &cv::Feature2D::write,
      Arg("file_name")).
    define_method<void(cv::Feature2D::*)(const cv::String&)>("read", &cv::Feature2D::read,
      Arg("file_name")).
    define_method<void(cv::Feature2D::*)(cv::FileStorage&) const>("write", &cv::Feature2D::write,
      Arg("")).
    define_method<void(cv::Feature2D::*)(const cv::FileNode&)>("read", &cv::Feature2D::read,
      Arg("")).
    define_method("empty?", &cv::Feature2D::empty).
    define_method("get_default_name", &cv::Feature2D::getDefaultName);

#if RUBY_CV_VERSION >= 407
  rb_cCvFeature2D.
    define_method<void(cv::Feature2D::*)(cv::FileStorage&, const cv::String&) const>("write", &cv::Feature2D::write,
      Arg("fs"), Arg("name")).
    define_method<void(cv::Feature2D::*)(const cv::Ptr<cv::FileStorage>&, const cv::String&) const>("write", &cv::Feature2D::write,
      Arg("fs"), Arg("name"));
#endif

  rb_cCvAffineFeature = define_class_under<cv::AffineFeature, cv::Feature2D>(rb_mCv, "AffineFeature").
    define_singleton_function("create", &cv::AffineFeature::create,
      Arg("backend"), Arg("max_tilt") = static_cast<int>(5), Arg("min_tilt") = static_cast<int>(0), Arg("tilt_step") = static_cast<float>(1.4142135623730951f), Arg("rotate_step_base") = static_cast<float>(72)).
    define_method("set_view_params", &cv::AffineFeature::setViewParams,
      Arg("tilts"), Arg("rolls")).
    define_method("get_view_params", &cv::AffineFeature::getViewParams,
      Arg("tilts"), Arg("rolls")).
    define_method("get_default_name", &cv::AffineFeature::getDefaultName);

#if RUBY_CV_VERSION >= 407
  rb_cCvSIFT = define_class_under<cv::SIFT, cv::Feature2D>(rb_mCv, "SIFT").
    define_singleton_function<cv::Ptr<cv::SIFT>(*)(int, int, double, double, double, bool)>("create", &cv::SIFT::create,
      Arg("nfeatures") = static_cast<int>(0), Arg("n_octave_layers") = static_cast<int>(3), Arg("contrast_threshold") = static_cast<double>(0.04), Arg("edge_threshold") = static_cast<double>(10), Arg("sigma") = static_cast<double>(1.6), Arg("enable_precise_upscale") = static_cast<bool>(false)).
    define_singleton_function<cv::Ptr<cv::SIFT>(*)(int, int, double, double, double, int, bool)>("create", &cv::SIFT::create,
      Arg("nfeatures"), Arg("n_octave_layers"), Arg("contrast_threshold"), Arg("edge_threshold"), Arg("sigma"), Arg("descriptor_type"), Arg("enable_precise_upscale") = static_cast<bool>(false)).
    define_method("get_default_name", &cv::SIFT::getDefaultName).
    define_method("set_n_features", &cv::SIFT::setNFeatures,
      Arg("max_features")).
    define_method("get_n_features", &cv::SIFT::getNFeatures).
    define_method("set_n_octave_layers", &cv::SIFT::setNOctaveLayers,
      Arg("n_octave_layers")).
    define_method("get_n_octave_layers", &cv::SIFT::getNOctaveLayers).
    define_method("set_contrast_threshold", &cv::SIFT::setContrastThreshold,
      Arg("contrast_threshold")).
    define_method("get_contrast_threshold", &cv::SIFT::getContrastThreshold).
    define_method("set_edge_threshold", &cv::SIFT::setEdgeThreshold,
      Arg("edge_threshold")).
    define_method("get_edge_threshold", &cv::SIFT::getEdgeThreshold).
    define_method("set_sigma", &cv::SIFT::setSigma,
      Arg("sigma")).
    define_method("get_sigma", &cv::SIFT::getSigma);
#endif

  rb_cCvBRISK = define_class_under<cv::BRISK, cv::Feature2D>(rb_mCv, "BRISK").
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(int, int, float)>("create", &cv::BRISK::create,
      Arg("thresh") = static_cast<int>(30), Arg("octaves") = static_cast<int>(3), Arg("pattern_scale") = static_cast<float>(1.0f)).
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(const std::vector<float>&, const std::vector<int>&, float, float, const std::vector<int>&)>("create", &cv::BRISK::create,
      Arg("radius_list"), Arg("number_list"), Arg("d_max") = static_cast<float>(5.85f), Arg("d_min") = static_cast<float>(8.2f), Arg("index_change") = static_cast<const std::vector<int> &>(std::vector<int>())).
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(int, int, const std::vector<float>&, const std::vector<int>&, float, float, const std::vector<int>&)>("create", &cv::BRISK::create,
      Arg("thresh"), Arg("octaves"), Arg("radius_list"), Arg("number_list"), Arg("d_max") = static_cast<float>(5.85f), Arg("d_min") = static_cast<float>(8.2f), Arg("index_change") = static_cast<const std::vector<int> &>(std::vector<int>())).
    define_method("get_default_name", &cv::BRISK::getDefaultName).
    define_method("set_threshold", &cv::BRISK::setThreshold,
      Arg("threshold")).
    define_method("get_threshold", &cv::BRISK::getThreshold).
    define_method("set_octaves", &cv::BRISK::setOctaves,
      Arg("octaves")).
    define_method("get_octaves", &cv::BRISK::getOctaves);

#if RUBY_CV_VERSION >= 407
  rb_cCvBRISK.
    define_method("set_pattern_scale", &cv::BRISK::setPatternScale,
      Arg("pattern_scale")).
    define_method("get_pattern_scale", &cv::BRISK::getPatternScale);
#endif

  rb_cCvORB = define_class_under<cv::ORB, cv::Feature2D>(rb_mCv, "ORB").
    define_constant("KBytes", cv::ORB::kBytes).
    define_singleton_function("create", &cv::ORB::create,
      Arg("nfeatures") = static_cast<int>(500), Arg("scale_factor") = static_cast<float>(1.2f), Arg("nlevels") = static_cast<int>(8), Arg("edge_threshold") = static_cast<int>(31), Arg("first_level") = static_cast<int>(0), Arg("wta_k") = static_cast<int>(2), Arg("score_type") = static_cast<cv::ORB::ScoreType>(cv::ORB::HARRIS_SCORE), Arg("patch_size") = static_cast<int>(31), Arg("fast_threshold") = static_cast<int>(20)).
    define_method("set_max_features", &cv::ORB::setMaxFeatures,
      Arg("max_features")).
    define_method("get_max_features", &cv::ORB::getMaxFeatures).
    define_method("set_scale_factor", &cv::ORB::setScaleFactor,
      Arg("scale_factor")).
    define_method("get_scale_factor", &cv::ORB::getScaleFactor).
    define_method("set_n_levels", &cv::ORB::setNLevels,
      Arg("nlevels")).
    define_method("get_n_levels", &cv::ORB::getNLevels).
    define_method("set_edge_threshold", &cv::ORB::setEdgeThreshold,
      Arg("edge_threshold")).
    define_method("get_edge_threshold", &cv::ORB::getEdgeThreshold).
    define_method("set_first_level", &cv::ORB::setFirstLevel,
      Arg("first_level")).
    define_method("get_first_level", &cv::ORB::getFirstLevel).
    define_method("set_wta_k", &cv::ORB::setWTA_K,
      Arg("wta_k")).
    define_method("get_wta_k", &cv::ORB::getWTA_K).
    define_method("set_score_type", &cv::ORB::setScoreType,
      Arg("score_type")).
    define_method("get_score_type", &cv::ORB::getScoreType).
    define_method("set_patch_size", &cv::ORB::setPatchSize,
      Arg("patch_size")).
    define_method("get_patch_size", &cv::ORB::getPatchSize).
    define_method("set_fast_threshold", &cv::ORB::setFastThreshold,
      Arg("fast_threshold")).
    define_method("get_fast_threshold", &cv::ORB::getFastThreshold).
    define_method("get_default_name", &cv::ORB::getDefaultName);
  
  Enum<cv::ORB::ScoreType> rb_cCvORBScoreType = define_enum_under<cv::ORB::ScoreType>("ScoreType", rb_cCvORB).
    define_value("HARRIS_SCORE", cv::ORB::ScoreType::HARRIS_SCORE).
    define_value("FAST_SCORE", cv::ORB::ScoreType::FAST_SCORE);
  
  rb_cCvMSER = define_class_under<cv::MSER, cv::Feature2D>(rb_mCv, "MSER").
    define_singleton_function("create", &cv::MSER::create,
      Arg("delta") = static_cast<int>(5), Arg("min_area") = static_cast<int>(60), Arg("max_area") = static_cast<int>(14400), Arg("max_variation") = static_cast<double>(0.25), Arg("min_diversity") = static_cast<double>(.2), Arg("max_evolution") = static_cast<int>(200), Arg("area_threshold") = static_cast<double>(1.01), Arg("min_margin") = static_cast<double>(0.003), Arg("edge_blur_size") = static_cast<int>(5)).
    define_method("detect_regions", &cv::MSER::detectRegions,
      Arg("image"), Arg("msers"), Arg("bboxes")).
    define_method("set_delta", &cv::MSER::setDelta,
      Arg("delta")).
    define_method("get_delta", &cv::MSER::getDelta).
    define_method("set_min_area", &cv::MSER::setMinArea,
      Arg("min_area")).
    define_method("get_min_area", &cv::MSER::getMinArea).
    define_method("set_max_area", &cv::MSER::setMaxArea,
      Arg("max_area")).
    define_method("get_max_area", &cv::MSER::getMaxArea).
    define_method("set_pass2_only", &cv::MSER::setPass2Only,
      Arg("f")).
    define_method("get_pass2_only?", &cv::MSER::getPass2Only).
    define_method("get_default_name", &cv::MSER::getDefaultName);

#if RUBY_CV_VERSION >= 407
  rb_cCvMSER.
    define_method("set_max_variation", &cv::MSER::setMaxVariation,
      Arg("max_variation")).
    define_method("get_max_variation", &cv::MSER::getMaxVariation).
    define_method("set_min_diversity", &cv::MSER::setMinDiversity,
      Arg("min_diversity")).
    define_method("get_min_diversity", &cv::MSER::getMinDiversity).
    define_method("set_max_evolution", &cv::MSER::setMaxEvolution,
      Arg("max_evolution")).
    define_method("get_max_evolution", &cv::MSER::getMaxEvolution).
    define_method("set_area_threshold", &cv::MSER::setAreaThreshold,
      Arg("area_threshold")).
    define_method("get_area_threshold", &cv::MSER::getAreaThreshold).
    define_method("set_min_margin", &cv::MSER::setMinMargin,
      Arg("min_margin")).
    define_method("get_min_margin", &cv::MSER::getMinMargin).
    define_method("set_edge_blur_size", &cv::MSER::setEdgeBlurSize,
      Arg("edge_blur_size")).
    define_method("get_edge_blur_size", &cv::MSER::getEdgeBlurSize);
#endif
  
  rb_cCvFastFeatureDetector = define_class_under<cv::FastFeatureDetector, cv::Feature2D>(rb_mCv, "FastFeatureDetector").
    define_singleton_function("create", &cv::FastFeatureDetector::create,
      Arg("threshold") = static_cast<int>(10), Arg("nonmax_suppression") = static_cast<bool>(true), Arg("type") = static_cast<cv::FastFeatureDetector::DetectorType>(cv::FastFeatureDetector::TYPE_9_16)).
    define_method("set_threshold", &cv::FastFeatureDetector::setThreshold,
      Arg("threshold")).
    define_method("get_threshold", &cv::FastFeatureDetector::getThreshold).
    define_method("set_nonmax_suppression", &cv::FastFeatureDetector::setNonmaxSuppression,
      Arg("f")).
    define_method("get_nonmax_suppression?", &cv::FastFeatureDetector::getNonmaxSuppression).
    define_method("set_type", &cv::FastFeatureDetector::setType,
      Arg("type")).
    define_method("get_type", &cv::FastFeatureDetector::getType).
    define_method("get_default_name", &cv::FastFeatureDetector::getDefaultName);
  
  Enum<cv::FastFeatureDetector::DetectorType> rb_cCvFastFeatureDetectorDetectorType = define_enum_under<cv::FastFeatureDetector::DetectorType>("DetectorType", rb_cCvFastFeatureDetector).
    define_value("TYPE_5_8", cv::FastFeatureDetector::DetectorType::TYPE_5_8).
    define_value("TYPE_7_12", cv::FastFeatureDetector::DetectorType::TYPE_7_12).
    define_value("TYPE_9_16", cv::FastFeatureDetector::DetectorType::TYPE_9_16);
  
  rb_cCvFastFeatureDetector.define_constant("THRESHOLD", (int)cv::FastFeatureDetector::THRESHOLD);
  rb_cCvFastFeatureDetector.define_constant("NONMAX_SUPPRESSION", (int)cv::FastFeatureDetector::NONMAX_SUPPRESSION);
  rb_cCvFastFeatureDetector.define_constant("FAST_N", (int)cv::FastFeatureDetector::FAST_N);
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool)>("fast", &cv::FAST,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression") = static_cast<bool>(true));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool, cv::FastFeatureDetector::DetectorType)>("fast", &cv::FAST,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression"), Arg("type"));
  
  rb_cCvAgastFeatureDetector = define_class_under<cv::AgastFeatureDetector, cv::Feature2D>(rb_mCv, "AgastFeatureDetector").
    define_singleton_function("create", &cv::AgastFeatureDetector::create,
      Arg("threshold") = static_cast<int>(10), Arg("nonmax_suppression") = static_cast<bool>(true), Arg("type") = static_cast<cv::AgastFeatureDetector::DetectorType>(cv::AgastFeatureDetector::OAST_9_16)).
    define_method("set_threshold", &cv::AgastFeatureDetector::setThreshold,
      Arg("threshold")).
    define_method("get_threshold", &cv::AgastFeatureDetector::getThreshold).
    define_method("set_nonmax_suppression", &cv::AgastFeatureDetector::setNonmaxSuppression,
      Arg("f")).
    define_method("get_nonmax_suppression?", &cv::AgastFeatureDetector::getNonmaxSuppression).
    define_method("set_type", &cv::AgastFeatureDetector::setType,
      Arg("type")).
    define_method("get_type", &cv::AgastFeatureDetector::getType).
    define_method("get_default_name", &cv::AgastFeatureDetector::getDefaultName);
  
  Enum<cv::AgastFeatureDetector::DetectorType> rb_cCvAgastFeatureDetectorDetectorType = define_enum_under<cv::AgastFeatureDetector::DetectorType>("DetectorType", rb_cCvAgastFeatureDetector).
    define_value("AGAST_5_8", cv::AgastFeatureDetector::DetectorType::AGAST_5_8).
    define_value("AGAST_7_12d", cv::AgastFeatureDetector::DetectorType::AGAST_7_12d).
    define_value("AGAST_7_12s", cv::AgastFeatureDetector::DetectorType::AGAST_7_12s).
    define_value("OAST_9_16", cv::AgastFeatureDetector::DetectorType::OAST_9_16);
  
  rb_cCvAgastFeatureDetector.define_constant("THRESHOLD", (int)cv::AgastFeatureDetector::THRESHOLD);
  rb_cCvAgastFeatureDetector.define_constant("NONMAX_SUPPRESSION", (int)cv::AgastFeatureDetector::NONMAX_SUPPRESSION);
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool)>("agast", &cv::AGAST,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression") = static_cast<bool>(true));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool, cv::AgastFeatureDetector::DetectorType)>("agast", &cv::AGAST,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression"), Arg("type"));
  
  rb_cCvGFTTDetector = define_class_under<cv::GFTTDetector, cv::Feature2D>(rb_mCv, "GFTTDetector").
    define_singleton_function<cv::Ptr<cv::GFTTDetector>(*)(int, double, double, int, bool, double)>("create", &cv::GFTTDetector::create,
      Arg("max_corners") = static_cast<int>(1000), Arg("quality_level") = static_cast<double>(0.01), Arg("min_distance") = static_cast<double>(1), Arg("block_size") = static_cast<int>(3), Arg("use_harris_detector") = static_cast<bool>(false), Arg("k") = static_cast<double>(0.04)).
    define_singleton_function<cv::Ptr<cv::GFTTDetector>(*)(int, double, double, int, int, bool, double)>("create", &cv::GFTTDetector::create,
      Arg("max_corners"), Arg("quality_level"), Arg("min_distance"), Arg("block_size"), Arg("gradiant_size"), Arg("use_harris_detector") = static_cast<bool>(false), Arg("k") = static_cast<double>(0.04)).
    define_method("set_max_features", &cv::GFTTDetector::setMaxFeatures,
      Arg("max_features")).
    define_method("get_max_features", &cv::GFTTDetector::getMaxFeatures).
    define_method("set_quality_level", &cv::GFTTDetector::setQualityLevel,
      Arg("qlevel")).
    define_method("get_quality_level", &cv::GFTTDetector::getQualityLevel).
    define_method("set_min_distance", &cv::GFTTDetector::setMinDistance,
      Arg("min_distance")).
    define_method("get_min_distance", &cv::GFTTDetector::getMinDistance).
    define_method("set_block_size", &cv::GFTTDetector::setBlockSize,
      Arg("block_size")).
    define_method("get_block_size", &cv::GFTTDetector::getBlockSize).
    define_method("set_harris_detector", &cv::GFTTDetector::setHarrisDetector,
      Arg("val")).
    define_method("get_harris_detector?", &cv::GFTTDetector::getHarrisDetector).
    define_method("set_k", &cv::GFTTDetector::setK,
      Arg("k")).
    define_method("get_k", &cv::GFTTDetector::getK).
    define_method("get_default_name", &cv::GFTTDetector::getDefaultName);

#if RUBY_CV_VERSION >= 407
  rb_cCvGFTTDetector.
    define_method("set_gradient_size", &cv::GFTTDetector::setGradientSize,
      Arg("gradient_size_")).
    define_method("get_gradient_size", &cv::GFTTDetector::getGradientSize);
#endif
  
  rb_cCvSimpleBlobDetector = define_class_under<cv::SimpleBlobDetector, cv::Feature2D>(rb_mCv, "SimpleBlobDetector").
    define_singleton_function("create", &cv::SimpleBlobDetector::create,
      Arg("parameters") = static_cast<const cv::SimpleBlobDetector::Params&>(cv::SimpleBlobDetector::Params())).
    define_method("get_default_name", &cv::SimpleBlobDetector::getDefaultName);

#if RUBY_CV_VERSION >= 407
  rb_cCvSimpleBlobDetector.
    define_method("set_params", &cv::SimpleBlobDetector::setParams,
      Arg("params")).
    define_method("get_params", &cv::SimpleBlobDetector::getParams).
    define_method("get_blob_contours", &cv::SimpleBlobDetector::getBlobContours);
#endif
  
  rb_cCvSimpleBlobDetectorParams = define_class_under<cv::SimpleBlobDetector::Params>(rb_cCvSimpleBlobDetector, "Params").
    define_constructor(Constructor<cv::SimpleBlobDetector::Params>()).
    define_attr("threshold_step", &cv::SimpleBlobDetector::Params::thresholdStep).
    define_attr("min_threshold", &cv::SimpleBlobDetector::Params::minThreshold).
    define_attr("max_threshold", &cv::SimpleBlobDetector::Params::maxThreshold).
    define_attr("min_repeatability", &cv::SimpleBlobDetector::Params::minRepeatability).
    define_attr("min_dist_between_blobs", &cv::SimpleBlobDetector::Params::minDistBetweenBlobs).
    define_attr("filter_by_color", &cv::SimpleBlobDetector::Params::filterByColor).
    define_attr("blob_color", &cv::SimpleBlobDetector::Params::blobColor).
    define_attr("filter_by_area", &cv::SimpleBlobDetector::Params::filterByArea).
    define_attr("min_area", &cv::SimpleBlobDetector::Params::minArea).
    define_attr("max_area", &cv::SimpleBlobDetector::Params::maxArea).
    define_attr("filter_by_circularity", &cv::SimpleBlobDetector::Params::filterByCircularity).
    define_attr("min_circularity", &cv::SimpleBlobDetector::Params::minCircularity).
    define_attr("max_circularity", &cv::SimpleBlobDetector::Params::maxCircularity).
    define_attr("filter_by_inertia", &cv::SimpleBlobDetector::Params::filterByInertia).
    define_attr("min_inertia_ratio", &cv::SimpleBlobDetector::Params::minInertiaRatio).
    define_attr("max_inertia_ratio", &cv::SimpleBlobDetector::Params::maxInertiaRatio).
    define_attr("filter_by_convexity", &cv::SimpleBlobDetector::Params::filterByConvexity).
    define_attr("min_convexity", &cv::SimpleBlobDetector::Params::minConvexity).
    define_attr("max_convexity", &cv::SimpleBlobDetector::Params::maxConvexity).
    define_method("read", &cv::SimpleBlobDetector::Params::read,
      Arg("fn")).
    define_method("write", &cv::SimpleBlobDetector::Params::write,
      Arg("fs"));

#if RUBY_CV_VERSION >= 407
  rb_cCvSimpleBlobDetectorParams.
    define_attr("collect_contours", &cv::SimpleBlobDetector::Params::collectContours);
#endif
  
  rb_cCvKAZE = define_class_under<cv::KAZE, cv::Feature2D>(rb_mCv, "KAZE").
    define_singleton_function("create", &cv::KAZE::create,
      Arg("extended") = static_cast<bool>(false), Arg("upright") = static_cast<bool>(false), Arg("threshold") = static_cast<float>(0.001f), Arg("n_octaves") = static_cast<int>(4), Arg("n_octave_layers") = static_cast<int>(4), Arg("diffusivity") = static_cast<cv::KAZE::DiffusivityType>(cv::KAZE::DIFF_PM_G2)).
    define_method("set_extended", &cv::KAZE::setExtended,
      Arg("extended")).
    define_method("get_extended?", &cv::KAZE::getExtended).
    define_method("set_upright", &cv::KAZE::setUpright,
      Arg("upright")).
    define_method("get_upright?", &cv::KAZE::getUpright).
    define_method("set_threshold", &cv::KAZE::setThreshold,
      Arg("threshold")).
    define_method("get_threshold", &cv::KAZE::getThreshold).
    define_method("set_n_octaves", &cv::KAZE::setNOctaves,
      Arg("octaves")).
    define_method("get_n_octaves", &cv::KAZE::getNOctaves).
    define_method("set_n_octave_layers", &cv::KAZE::setNOctaveLayers,
      Arg("octave_layers")).
    define_method("get_n_octave_layers", &cv::KAZE::getNOctaveLayers).
    define_method("set_diffusivity", &cv::KAZE::setDiffusivity,
      Arg("diff")).
    define_method("get_diffusivity", &cv::KAZE::getDiffusivity).
    define_method("get_default_name", &cv::KAZE::getDefaultName);
  
  Enum<cv::KAZE::DiffusivityType> rb_cCvKAZEDiffusivityType = define_enum_under<cv::KAZE::DiffusivityType>("DiffusivityType", rb_cCvKAZE).
    define_value("DIFF_PM_G1", cv::KAZE::DiffusivityType::DIFF_PM_G1).
    define_value("DIFF_PM_G2", cv::KAZE::DiffusivityType::DIFF_PM_G2).
    define_value("DIFF_WEICKERT", cv::KAZE::DiffusivityType::DIFF_WEICKERT).
    define_value("DIFF_CHARBONNIER", cv::KAZE::DiffusivityType::DIFF_CHARBONNIER);
  
  rb_cCvAKAZE = define_class_under<cv::AKAZE, cv::Feature2D>(rb_mCv, "AKAZE").
    define_singleton_function("create", &cv::AKAZE::create,
      Arg("descriptor_type") = static_cast<cv::AKAZE::DescriptorType>(cv::AKAZE::DESCRIPTOR_MLDB), Arg("descriptor_size") = static_cast<int>(0), Arg("descriptor_channels") = static_cast<int>(3), Arg("threshold") = static_cast<float>(0.001f), Arg("n_octaves") = static_cast<int>(4), Arg("n_octave_layers") = static_cast<int>(4), Arg("diffusivity") = static_cast<cv::KAZE::DiffusivityType>(cv::KAZE::DIFF_PM_G2), Arg("max_points") = static_cast<int>(-1)).
    define_method("set_descriptor_type", &cv::AKAZE::setDescriptorType,
      Arg("dtype")).
    define_method("get_descriptor_type", &cv::AKAZE::getDescriptorType).
    define_method("set_descriptor_size", &cv::AKAZE::setDescriptorSize,
      Arg("dsize")).
    define_method("get_descriptor_size", &cv::AKAZE::getDescriptorSize).
    define_method("set_descriptor_channels", &cv::AKAZE::setDescriptorChannels,
      Arg("dch")).
    define_method("get_descriptor_channels", &cv::AKAZE::getDescriptorChannels).
    define_method("set_threshold", &cv::AKAZE::setThreshold,
      Arg("threshold")).
    define_method("get_threshold", &cv::AKAZE::getThreshold).
    define_method("set_n_octaves", &cv::AKAZE::setNOctaves,
      Arg("octaves")).
    define_method("get_n_octaves", &cv::AKAZE::getNOctaves).
    define_method("set_n_octave_layers", &cv::AKAZE::setNOctaveLayers,
      Arg("octave_layers")).
    define_method("get_n_octave_layers", &cv::AKAZE::getNOctaveLayers).
    define_method("set_diffusivity", &cv::AKAZE::setDiffusivity,
      Arg("diff")).
    define_method("get_diffusivity", &cv::AKAZE::getDiffusivity).
    define_method("get_default_name", &cv::AKAZE::getDefaultName);

#if RUBY_CV_VERSION >= 409
  rb_cCvAKAZE.
    define_method("set_max_points", &cv::AKAZE::setMaxPoints,
      Arg("max_points")).
    define_method("get_max_points", &cv::AKAZE::getMaxPoints);
#endif
  
  Enum<cv::AKAZE::DescriptorType> rb_cCvAKAZEDescriptorType = define_enum_under<cv::AKAZE::DescriptorType>("DescriptorType", rb_cCvAKAZE).
    define_value("DESCRIPTOR_KAZE_UPRIGHT", cv::AKAZE::DescriptorType::DESCRIPTOR_KAZE_UPRIGHT).
    define_value("DESCRIPTOR_KAZE", cv::AKAZE::DescriptorType::DESCRIPTOR_KAZE).
    define_value("DESCRIPTOR_MLDB_UPRIGHT", cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB_UPRIGHT).
    define_value("DESCRIPTOR_MLDB", cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB);
  
  rb_cCvAccumulatorUnsignedChar = define_class_under<cv::Accumulator<unsigned char>>(rb_mCv, "AccumulatorUnsignedChar").
    define_constructor(Constructor<cv::Accumulator<unsigned char>>());
  
  rb_cCvAccumulatorUnsignedShort = define_class_under<cv::Accumulator<unsigned short>>(rb_mCv, "AccumulatorUnsignedShort").
    define_constructor(Constructor<cv::Accumulator<unsigned short>>());
  
  rb_cCvAccumulatorChar = define_class_under<cv::Accumulator<char>>(rb_mCv, "AccumulatorChar").
    define_constructor(Constructor<cv::Accumulator<char>>());
  
  rb_cCvAccumulatorShort = define_class_under<cv::Accumulator<short>>(rb_mCv, "AccumulatorShort").
    define_constructor(Constructor<cv::Accumulator<short>>());
  
  rb_cCvDescriptorMatcher = define_class_under<cv::DescriptorMatcher, cv::Algorithm>(rb_mCv, "DescriptorMatcher").
    define_method("add", &cv::DescriptorMatcher::add,
      Arg("descriptors")).
    define_method("get_train_descriptors", &cv::DescriptorMatcher::getTrainDescriptors).
    define_method("clear", &cv::DescriptorMatcher::clear).
    define_method("empty?", &cv::DescriptorMatcher::empty).
    define_method("mask_supported?", &cv::DescriptorMatcher::isMaskSupported).
    define_method("train", &cv::DescriptorMatcher::train).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<cv::DMatch>&, cv::InputArray) const>("match", &cv::DescriptorMatcher::match,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<std::vector<cv::DMatch>>&, int, cv::InputArray, bool) const>("knn_match", &cv::DescriptorMatcher::knnMatch,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("k"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<std::vector<cv::DMatch>>&, float, cv::InputArray, bool) const>("radius_match", &cv::DescriptorMatcher::radiusMatch,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("max_distance"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, std::vector<cv::DMatch>&, cv::InputArrayOfArrays)>("match", &cv::DescriptorMatcher::match,
      Arg("query_descriptors"), Arg("matches"), Arg("masks") = static_cast<cv::InputArrayOfArrays>(cv::noArray())).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, std::vector<std::vector<cv::DMatch>>&, int, cv::InputArrayOfArrays, bool)>("knn_match", &cv::DescriptorMatcher::knnMatch,
      Arg("query_descriptors"), Arg("matches"), Arg("k"), Arg("masks") = static_cast<cv::InputArrayOfArrays>(cv::noArray()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, std::vector<std::vector<cv::DMatch>>&, float, cv::InputArrayOfArrays, bool)>("radius_match", &cv::DescriptorMatcher::radiusMatch,
      Arg("query_descriptors"), Arg("matches"), Arg("max_distance"), Arg("masks") = static_cast<cv::InputArrayOfArrays>(cv::noArray()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::DescriptorMatcher::*)(const cv::String&) const>("write", &cv::DescriptorMatcher::write,
      Arg("file_name")).
    define_method<void(cv::DescriptorMatcher::*)(const cv::String&)>("read", &cv::DescriptorMatcher::read,
      Arg("file_name")).
    define_method<void(cv::DescriptorMatcher::*)(const cv::FileNode&)>("read", &cv::DescriptorMatcher::read,
      Arg("")).
    define_method<void(cv::DescriptorMatcher::*)(cv::FileStorage&) const>("write", &cv::DescriptorMatcher::write,
      Arg("")).
    define_method("clone", &cv::DescriptorMatcher::clone,
      Arg("empty_train_data") = static_cast<bool>(false)).
    define_singleton_function<cv::Ptr<cv::DescriptorMatcher>(*)(const cv::String&)>("create", &cv::DescriptorMatcher::create,
      Arg("descriptor_matcher_type")).
    define_singleton_function<cv::Ptr<cv::DescriptorMatcher>(*)(const cv::DescriptorMatcher::MatcherType&)>("create", &cv::DescriptorMatcher::create,
      Arg("matcher_type"));

#if RUBY_CV_VERSION >= 409
  rb_cCvDescriptorMatcher.
    define_method<void(cv::DescriptorMatcher::*)(cv::FileStorage&, const cv::String&) const>("write", &cv::DescriptorMatcher::write,
      Arg("fs"), Arg("name")).
    define_method<void(cv::DescriptorMatcher::*)(const cv::Ptr<cv::FileStorage>&, const cv::String&) const>("write", &cv::DescriptorMatcher::write,
      Arg("fs"), Arg("name"));
#endif
  
  Enum<cv::DescriptorMatcher::MatcherType> rb_cCvDescriptorMatcherMatcherType = define_enum_under<cv::DescriptorMatcher::MatcherType>("MatcherType", rb_cCvDescriptorMatcher).
    define_value("FLANNBASED", cv::DescriptorMatcher::MatcherType::FLANNBASED).
    define_value("BRUTEFORCE", cv::DescriptorMatcher::MatcherType::BRUTEFORCE).
    define_value("BRUTEFORCE_L1", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_L1).
    define_value("BRUTEFORCE_HAMMING", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_HAMMING).
    define_value("BRUTEFORCE_HAMMINGLUT", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_HAMMINGLUT).
    define_value("BRUTEFORCE_SL2", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_SL2);
  
  rb_cCvBFMatcher = define_class_under<cv::BFMatcher, cv::DescriptorMatcher>(rb_mCv, "BFMatcher").
    define_constructor(Constructor<cv::BFMatcher, int, bool>(),
      Arg("norm_type") = static_cast<int>(cv::NormTypes::NORM_L2), Arg("cross_check") = static_cast<bool>(false)).
    define_method("mask_supported?", &cv::BFMatcher::isMaskSupported).
    define_singleton_function("create", &cv::BFMatcher::create,
      Arg("norm_type") = static_cast<int>(cv::NormTypes::NORM_L2), Arg("cross_check") = static_cast<bool>(false)).
    define_method("clone", &cv::BFMatcher::clone,
      Arg("empty_train_data") = static_cast<bool>(false));
  
  rb_cCvFlannBasedMatcher = define_class_under<cv::FlannBasedMatcher, cv::DescriptorMatcher>(rb_mCv, "FlannBasedMatcher").
    define_constructor(Constructor<cv::FlannBasedMatcher, const cv::Ptr<cv::flann::IndexParams>&, const cv::Ptr<cv::flann::SearchParams>&>(),
      Arg("index_params") = static_cast<const cv::Ptr<cv::flann::IndexParams> &>(cv::makePtr<cv::flann::KDTreeIndexParams>()), Arg("search_params") = static_cast<const cv::Ptr<cv::flann::SearchParams> &>(cv::makePtr<cv::flann::SearchParams>())).
    define_method("add", &cv::FlannBasedMatcher::add,
      Arg("descriptors")).
    define_method("clear", &cv::FlannBasedMatcher::clear).
    define_method("read", &cv::FlannBasedMatcher::read,
      Arg("")).
    define_method("write", &cv::FlannBasedMatcher::write,
      Arg("")).
    define_method("train", &cv::FlannBasedMatcher::train).
    define_method("mask_supported?", &cv::FlannBasedMatcher::isMaskSupported).
    define_singleton_function("create", &cv::FlannBasedMatcher::create).
    define_method("clone", &cv::FlannBasedMatcher::clone,
      Arg("empty_train_data") = static_cast<bool>(false));
  
  Enum<cv::DrawMatchesFlags> rb_cCvDrawMatchesFlags = define_enum_under<cv::DrawMatchesFlags>("DrawMatchesFlags", rb_mCv).
    define_value("DEFAULT", cv::DrawMatchesFlags::DEFAULT).
    define_value("DRAW_OVER_OUTIMG", cv::DrawMatchesFlags::DRAW_OVER_OUTIMG).
    define_value("NOT_DRAW_SINGLE_POINTS", cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS).
    define_value("DRAW_RICH_KEYPOINTS", cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
  
  rb_mCv.define_module_function("draw_keypoints", &cv::drawKeypoints,
    Arg("image"), Arg("keypoints"), Arg("out_image"), Arg("color") = static_cast<const cv::Scalar &>(cv::Scalar::all(-1)), Arg("flags") = static_cast<cv::DrawMatchesFlags>(cv::DrawMatchesFlags::DEFAULT));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, const std::vector<cv::KeyPoint>&, cv::InputArray, const std::vector<cv::KeyPoint>&, const std::vector<cv::DMatch>&, cv::InputOutputArray, const cv::Scalar&, const cv::Scalar&, const std::vector<char>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches,
    Arg("img1"), Arg("keypoints1"), Arg("img2"), Arg("keypoints2"), Arg("matches1to2"), Arg("out_img"), Arg("match_color") = static_cast<const cv::Scalar &>(cv::Scalar::all(-1)), Arg("single_point_color") = static_cast<const cv::Scalar &>(cv::Scalar::all(-1)), Arg("matches_mask") = static_cast<const std::vector<char> &>(std::vector<char>()), Arg("flags") = static_cast<cv::DrawMatchesFlags>(cv::DrawMatchesFlags::DEFAULT));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, const std::vector<cv::KeyPoint>&, cv::InputArray, const std::vector<cv::KeyPoint>&, const std::vector<cv::DMatch>&, cv::InputOutputArray, const int, const cv::Scalar&, const cv::Scalar&, const std::vector<char>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches,
    Arg("img1"), Arg("keypoints1"), Arg("img2"), Arg("keypoints2"), Arg("matches1to2"), Arg("out_img"), Arg("matches_thickness"), Arg("match_color") = static_cast<const cv::Scalar &>(cv::Scalar::all(-1)), Arg("single_point_color") = static_cast<const cv::Scalar &>(cv::Scalar::all(-1)), Arg("matches_mask") = static_cast<const std::vector<char> &>(std::vector<char>()), Arg("flags") = static_cast<cv::DrawMatchesFlags>(cv::DrawMatchesFlags::DEFAULT));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, const std::vector<cv::KeyPoint>&, cv::InputArray, const std::vector<cv::KeyPoint>&, const std::vector<std::vector<cv::DMatch>>&, cv::InputOutputArray, const cv::Scalar&, const cv::Scalar&, const std::vector<std::vector<char>>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches,
    Arg("img1"), Arg("keypoints1"), Arg("img2"), Arg("keypoints2"), Arg("matches1to2"), Arg("out_img"), Arg("match_color") = static_cast<const cv::Scalar &>(cv::Scalar::all(-1)), Arg("single_point_color") = static_cast<const cv::Scalar &>(cv::Scalar::all(-1)), Arg("matches_mask") = static_cast<const std::vector<std::vector<char>> &>(std::vector<std::vector<char> >()), Arg("flags") = static_cast<cv::DrawMatchesFlags>(cv::DrawMatchesFlags::DEFAULT));
  
  rb_mCv.define_module_function("evaluate_feature_detector", &cv::evaluateFeatureDetector,
    Arg("img1"), Arg("img2"), Arg("h1to2"), Arg("keypoints1"), Arg("keypoints2"), Arg("repeatability"), Arg("corresp_count"), Arg("fdetector") = static_cast<const cv::Ptr<cv::FeatureDetector> &>(cv::Ptr<cv::FeatureDetector>()));
  
  rb_mCv.define_module_function("compute_recall_precision_curve", &cv::computeRecallPrecisionCurve,
    Arg("matches1to2"), Arg("correct_matches1to2_mask"), Arg("recall_precision_curve"));
  
  rb_mCv.define_module_function("get_recall", &cv::getRecall,
    Arg("recall_precision_curve"), Arg("l_precision"));
  
  rb_mCv.define_module_function("get_nearest_point", &cv::getNearestPoint,
    Arg("recall_precision_curve"), Arg("l_precision"));
  
  rb_cCvBOWTrainer = define_class_under<cv::BOWTrainer>(rb_mCv, "BOWTrainer").
    define_method("add", &cv::BOWTrainer::add,
      Arg("descriptors")).
    define_method("get_descriptors", &cv::BOWTrainer::getDescriptors).
    define_method("descriptors_count", &cv::BOWTrainer::descriptorsCount).
    define_method("clear", &cv::BOWTrainer::clear).
    define_method<cv::Mat(cv::BOWTrainer::*)() const>("cluster", &cv::BOWTrainer::cluster).
    define_method<cv::Mat(cv::BOWTrainer::*)(const cv::Mat&) const>("cluster", &cv::BOWTrainer::cluster,
      Arg("descriptors"));
  
  rb_cCvBOWKMeansTrainer = define_class_under<cv::BOWKMeansTrainer, cv::BOWTrainer>(rb_mCv, "BOWKMeansTrainer").
    define_constructor(Constructor<cv::BOWKMeansTrainer, int, const cv::TermCriteria&, int, int>(),
      Arg("cluster_count"), Arg("termcrit") = static_cast<const cv::TermCriteria &>(cv::TermCriteria()), Arg("attempts") = static_cast<int>(3), Arg("flags") = static_cast<int>(cv::KmeansFlags::KMEANS_PP_CENTERS)).
    define_method<cv::Mat(cv::BOWKMeansTrainer::*)() const>("cluster", &cv::BOWKMeansTrainer::cluster).
    define_method<cv::Mat(cv::BOWKMeansTrainer::*)(const cv::Mat&) const>("cluster", &cv::BOWKMeansTrainer::cluster,
      Arg("descriptors"));
  
  rb_cCvBOWImgDescriptorExtractor = define_class_under<cv::BOWImgDescriptorExtractor>(rb_mCv, "BOWImgDescriptorExtractor").
    define_constructor(Constructor<cv::BOWImgDescriptorExtractor, const cv::Ptr<cv::Feature2D>&, const cv::Ptr<cv::DescriptorMatcher>&>(),
      Arg("dextractor"), Arg("dmatcher")).
    define_constructor(Constructor<cv::BOWImgDescriptorExtractor, const cv::Ptr<cv::DescriptorMatcher>&>(),
      Arg("dmatcher")).
    define_method("set_vocabulary", &cv::BOWImgDescriptorExtractor::setVocabulary,
      Arg("vocabulary")).
    define_method("get_vocabulary", &cv::BOWImgDescriptorExtractor::getVocabulary).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(cv::InputArray, std::vector<cv::KeyPoint>&, cv::OutputArray, std::vector<std::vector<int>>*, cv::Mat*)>("compute", &cv::BOWImgDescriptorExtractor::compute,
      Arg("image"), Arg("keypoints"), Arg("img_descriptor"), Arg("point_idxs_of_clusters") = static_cast<std::vector<std::vector<int>> *>(0), Arg("descriptors") = static_cast<cv::Mat *>(0)).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(cv::InputArray, cv::OutputArray, std::vector<std::vector<int>>*)>("compute", &cv::BOWImgDescriptorExtractor::compute,
      Arg("keypoint_descriptors"), Arg("img_descriptor"), Arg("point_idxs_of_clusters") = static_cast<std::vector<std::vector<int>> *>(0)).
    define_method("compute2", &cv::BOWImgDescriptorExtractor::compute2,
      Arg("image"), Arg("keypoints"), Arg("img_descriptor")).
    define_method("descriptor_size", &cv::BOWImgDescriptorExtractor::descriptorSize).
    define_method("descriptor_type", &cv::BOWImgDescriptorExtractor::descriptorType);
}