#include <opencv2/tracking/feature.hpp>
#include "feature-rb.hpp"

using namespace Rice;

void Init_Tracking_Feature()
{
  Class(rb_cObject).define_constant("FEATURES", FEATURES);

  Class(rb_cObject).define_constant("CC_FEATURE_PARAMS", CC_FEATURE_PARAMS);

  Class(rb_cObject).define_constant("CC_MAX_CAT_COUNT", CC_MAX_CAT_COUNT);

  Class(rb_cObject).define_constant("CC_FEATURE_SIZE", CC_FEATURE_SIZE);

  Class(rb_cObject).define_constant("CC_NUM_FEATURES", CC_NUM_FEATURES);

  Class(rb_cObject).define_constant("CC_ISINTEGRAL", CC_ISINTEGRAL);

  Class(rb_cObject).define_constant("CC_RECTS", CC_RECTS);

  Class(rb_cObject).define_constant("CC_TILTED", CC_TILTED);

  Class(rb_cObject).define_constant("CC_RECT", CC_RECT);

  Class(rb_cObject).define_constant("LBPF_NAME", LBPF_NAME);

  Class(rb_cObject).define_constant("HOGF_NAME", HOGF_NAME);

  Class(rb_cObject).define_constant("HFP_NAME", HFP_NAME);

  Class(rb_cObject).define_constant("CV_HAAR_FEATURE_MAX", CV_HAAR_FEATURE_MAX);

  Class(rb_cObject).define_constant("N_BINS", N_BINS);

  Class(rb_cObject).define_constant("N_CELLS", N_CELLS);

  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");

  Module rb_mCvDetailTrackingContribFeature = define_module_under(rb_mCvDetailTracking, "ContribFeature");

  rb_mCvDetailTrackingContribFeature.define_module_function<float(*)(const cv::Mat&, const cv::Mat&)>("calc_norm_factor", &cv::detail::tracking::contrib_feature::calcNormFactor,
    Arg("sum"), Arg("sq_sum"));

  Rice::Data_Type<cv::detail::CvParams> rb_cCvDetailCvParams = define_class_under<cv::detail::CvParams>(rb_mCvDetailTrackingContribFeature, "CvParams").
    define_method<void(cv::detail::tracking::contrib_feature::CvParams::*)(cv::FileStorage&) const>("write", &cv::detail::tracking::contrib_feature::CvParams::write,
      Arg("fs")).
    define_method<bool(cv::detail::tracking::contrib_feature::CvParams::*)(const cv::FileNode&)>("read", &cv::detail::tracking::contrib_feature::CvParams::read,
      Arg("node")).
    define_method<void(cv::detail::tracking::contrib_feature::CvParams::*)() const>("print_defaults", &cv::detail::tracking::contrib_feature::CvParams::printDefaults).
    define_method<void(cv::detail::tracking::contrib_feature::CvParams::*)() const>("print_attrs", &cv::detail::tracking::contrib_feature::CvParams::printAttrs).
    define_method<bool(cv::detail::tracking::contrib_feature::CvParams::*)(const std::string, const std::string)>("scan_attr", &cv::detail::tracking::contrib_feature::CvParams::scanAttr,
      Arg("prm_name"), Arg("val")).
    define_attr("name", &cv::detail::tracking::contrib_feature::CvParams::name);

  Rice::Data_Type<cv::detail::CvFeatureParams> rb_cCvDetailCvFeatureParams = define_class_under<cv::detail::CvFeatureParams, cv::detail::CvParams>(rb_mCvDetailTrackingContribFeature, "CvFeatureParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvFeatureParams>()).
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureParams::*)(const cv::detail::tracking::contrib_feature::CvFeatureParams&)>("init", &cv::detail::tracking::contrib_feature::CvFeatureParams::init,
      Arg("fp")).
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureParams::*)(cv::FileStorage&) const>("write", &cv::detail::tracking::contrib_feature::CvFeatureParams::write,
      Arg("fs")).
    define_method<bool(cv::detail::tracking::contrib_feature::CvFeatureParams::*)(const cv::FileNode&)>("read", &cv::detail::tracking::contrib_feature::CvFeatureParams::read,
      Arg("node")).
    define_singleton_function<cv::Ptr<cv::detail::CvFeatureParams>(*)(cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType)>("create", &cv::detail::tracking::contrib_feature::CvFeatureParams::create,
      Arg("feature_type")).
    define_attr("max_cat_count", &cv::detail::tracking::contrib_feature::CvFeatureParams::maxCatCount).
    define_attr("feat_size", &cv::detail::tracking::contrib_feature::CvFeatureParams::featSize).
    define_attr("num_features", &cv::detail::tracking::contrib_feature::CvFeatureParams::numFeatures);

  Enum<cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType> rb_cCvDetailCvFeatureParamsFeatureType = define_enum_under<cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType>("FeatureType", rb_cCvDetailCvFeatureParams).
    define_value("HAAR", cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType::HAAR).
    define_value("LBP", cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType::LBP).
    define_value("HOG", cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType::HOG);

  Rice::Data_Type<cv::detail::CvFeatureEvaluator> rb_cCvDetailCvFeatureEvaluator = define_class_under<cv::detail::CvFeatureEvaluator>(rb_mCvDetailTrackingContribFeature, "CvFeatureEvaluator").
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(const cv::detail::tracking::contrib_feature::CvFeatureParams*, int, cv::Size)>("init", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::init,
      Arg("_feature_params"), Arg("_max_sample_count"), Arg("_win_size")).
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(const cv::Mat&, uchar, int)>("set_image", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::setImage,
      Arg("img"), Arg("cls_label"), Arg("idx")).
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(cv::FileStorage&, const cv::Mat&) const>("write_features", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::writeFeatures,
      Arg("fs"), Arg("feature_map")).
    define_method<float(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(int, int)>("call", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::operator(),
      Arg("feature_idx"), Arg("sample_idx")).
    define_singleton_function<cv::Ptr<cv::detail::CvFeatureEvaluator>(*)(cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType)>("create", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::create,
      Arg("type")).
    define_method<int(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)() const>("get_num_features", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getNumFeatures).
    define_method<int(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)() const>("get_max_cat_count", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getMaxCatCount).
    define_method<int(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)() const>("get_feature_size", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getFeatureSize).
    define_method<const cv::Mat&(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)() const>("get_cls", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getCls).
    define_method<float(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(int) const>("get_cls", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getCls,
      Arg("si"));

  Rice::Data_Type<cv::detail::CvHaarFeatureParams> rb_cCvDetailCvHaarFeatureParams = define_class_under<cv::detail::CvHaarFeatureParams, cv::detail::CvFeatureParams>(rb_mCvDetailTrackingContribFeature, "CvHaarFeatureParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHaarFeatureParams>()).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)(const cv::detail::tracking::contrib_feature::CvFeatureParams&)>("init", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::init,
      Arg("fp")).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)(cv::FileStorage&) const>("write", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::write,
      Arg("fs")).
    define_method<bool(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)(const cv::FileNode&)>("read", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::read,
      Arg("node")).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)() const>("print_defaults", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::printDefaults).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)() const>("print_attrs", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::printAttrs).
    define_method<bool(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)(const std::string, const std::string)>("scan_attr", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::scanAttr,
      Arg("prm"), Arg("val")).
    define_attr("is_integral", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::isIntegral);

  Rice::Data_Type<cv::detail::CvHaarEvaluator> rb_cCvDetailCvHaarEvaluator = define_class_under<cv::detail::CvHaarEvaluator, cv::detail::CvFeatureEvaluator>(rb_mCvDetailTrackingContribFeature, "CvHaarEvaluator").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHaarEvaluator>()).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(const cv::detail::tracking::contrib_feature::CvFeatureParams*, int, cv::Size)>("init", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::init,
      Arg("_feature_params"), Arg("_max_sample_count"), Arg("_win_size")).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(const cv::Mat&, uchar, int)>("set_image", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::setImage,
      Arg("img"), Arg("cls_label") = static_cast<uchar>(0), Arg("idx") = static_cast<int>(1)).
    define_method<float(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(int, int)>("call", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::operator(),
      Arg("feature_idx"), Arg("sample_idx")).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(cv::FileStorage&, const cv::Mat&) const>("write_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::writeFeatures,
      Arg("fs"), Arg("feature_map")).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(cv::FileStorage&) const>("write_feature", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::writeFeature,
      Arg("fs")).
    define_method<const std::vector<cv::detail::CvHaarEvaluator::FeatureHaar>&(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)() const>("get_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::getFeatures).
    define_method<cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar&(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(int)>("get_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::getFeatures,
      Arg("idx")).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(cv::Size)>("set_win_size", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::setWinSize,
      Arg("patch_size")).
    define_method<cv::Size(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)() const>("set_win_size", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::setWinSize).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)()>("generate_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::generateFeatures).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(int)>("generate_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::generateFeatures,
      Arg("num_features"));

  Rice::Data_Type<cv::detail::CvHaarEvaluator::FeatureHaar> rb_cCvDetailCvHaarEvaluatorFeatureHaar = define_class_under<cv::detail::CvHaarEvaluator::FeatureHaar>(rb_cCvDetailCvHaarEvaluator, "FeatureHaar").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar, cv::Size>(),
      Arg("patch_size")).
    define_method<bool(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)(const cv::Mat&, cv::Rect, float*) const>("eval", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::eval,
      Arg("image"), Arg("roi"), ArgBuffer("result")).
    define_method<int(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)()>("get_num_areas", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getNumAreas).
    define_method<const std::vector<float>&(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)() const>("get_weights", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getWeights).
    define_method<const std::vector<cv::Rect_<int>>&(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)() const>("get_areas", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getAreas).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)(cv::FileStorage) const>("write", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::write,
      Arg("arg_0")).
    define_method<float(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)() const>("get_init_mean", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getInitMean).
    define_method<float(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)() const>("get_init_sigma", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getInitSigma);

  Rice::Data_Type<cv::detail::CvHOGFeatureParams> rb_cCvDetailCvHOGFeatureParams = define_class_under<cv::detail::CvHOGFeatureParams, cv::detail::CvFeatureParams>(rb_mCvDetailTrackingContribFeature, "CvHOGFeatureParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHOGFeatureParams>());

  Rice::Data_Type<cv::detail::CvHOGEvaluator> rb_cCvDetailCvHOGEvaluator = define_class_under<cv::detail::CvHOGEvaluator, cv::detail::CvFeatureEvaluator>(rb_mCvDetailTrackingContribFeature, "CvHOGEvaluator").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHOGEvaluator>()).
    define_method<void(cv::detail::tracking::contrib_feature::CvHOGEvaluator::*)(const cv::detail::tracking::contrib_feature::CvFeatureParams*, int, cv::Size)>("init", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::init,
      Arg("_feature_params"), Arg("_max_sample_count"), Arg("_win_size")).
    define_method<void(cv::detail::tracking::contrib_feature::CvHOGEvaluator::*)(const cv::Mat&, uchar, int)>("set_image", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::setImage,
      Arg("img"), Arg("cls_label"), Arg("idx")).
    define_method<float(cv::detail::tracking::contrib_feature::CvHOGEvaluator::*)(int, int)>("call", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::operator(),
      Arg("var_idx"), Arg("sample_idx")).
    define_method<void(cv::detail::tracking::contrib_feature::CvHOGEvaluator::*)(cv::FileStorage&, const cv::Mat&) const>("write_features", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::writeFeatures,
      Arg("fs"), Arg("feature_map"));

  Rice::Data_Type<cv::detail::CvLBPFeatureParams> rb_cCvDetailCvLBPFeatureParams = define_class_under<cv::detail::CvLBPFeatureParams, cv::detail::CvFeatureParams>(rb_mCvDetailTrackingContribFeature, "CvLBPFeatureParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvLBPFeatureParams>());

  Rice::Data_Type<cv::detail::CvLBPEvaluator> rb_cCvDetailCvLBPEvaluator = define_class_under<cv::detail::CvLBPEvaluator, cv::detail::CvFeatureEvaluator>(rb_mCvDetailTrackingContribFeature, "CvLBPEvaluator").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvLBPEvaluator>()).
    define_method<void(cv::detail::tracking::contrib_feature::CvLBPEvaluator::*)(const cv::detail::tracking::contrib_feature::CvFeatureParams*, int, cv::Size)>("init", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::init,
      Arg("_feature_params"), Arg("_max_sample_count"), Arg("_win_size")).
    define_method<void(cv::detail::tracking::contrib_feature::CvLBPEvaluator::*)(const cv::Mat&, uchar, int)>("set_image", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::setImage,
      Arg("img"), Arg("cls_label"), Arg("idx")).
    define_method<float(cv::detail::tracking::contrib_feature::CvLBPEvaluator::*)(int, int)>("call", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::operator(),
      Arg("feature_idx"), Arg("sample_idx")).
    define_method<void(cv::detail::tracking::contrib_feature::CvLBPEvaluator::*)(cv::FileStorage&, const cv::Mat&) const>("write_features", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::writeFeatures,
      Arg("fs"), Arg("feature_map"));
}