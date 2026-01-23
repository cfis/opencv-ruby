#include <opencv2/stitching/detail/motion_estimators.hpp>
#include "motion_estimators-rb.hpp"

using namespace Rice;

void Init_Stitching_Detail_MotionEstimators()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Rice::Data_Type<cv::detail::Estimator> rb_cCvDetailEstimator = define_class_under<cv::detail::Estimator>(rb_mCvDetail, "Estimator").
    define_method("call", &cv::detail::Estimator::operator(),
      Arg("features"), Arg("pairwise_matches"), Arg("cameras"));

  Rice::Data_Type<cv::detail::HomographyBasedEstimator> rb_cCvDetailHomographyBasedEstimator = define_class_under<cv::detail::HomographyBasedEstimator, cv::detail::Estimator>(rb_mCvDetail, "HomographyBasedEstimator").
    define_constructor(Constructor<cv::detail::HomographyBasedEstimator, bool>(),
      Arg("is_focals_estimated") = static_cast<bool>(false));

  Rice::Data_Type<cv::detail::AffineBasedEstimator> rb_cCvDetailAffineBasedEstimator = define_class_under<cv::detail::AffineBasedEstimator, cv::detail::Estimator>(rb_mCvDetail, "AffineBasedEstimator").
    define_constructor(Constructor<cv::detail::AffineBasedEstimator>());

  Rice::Data_Type<cv::detail::BundleAdjusterBase> rb_cCvDetailBundleAdjusterBase = define_class_under<cv::detail::BundleAdjusterBase, cv::detail::Estimator>(rb_mCvDetail, "BundleAdjusterBase").
    define_method("refinement_mask", &cv::detail::BundleAdjusterBase::refinementMask).
    define_method("set_refinement_mask", &cv::detail::BundleAdjusterBase::setRefinementMask,
      Arg("mask")).
    define_method("conf_thresh", &cv::detail::BundleAdjusterBase::confThresh).
    define_method("set_conf_thresh", &cv::detail::BundleAdjusterBase::setConfThresh,
      Arg("conf_thresh")).
    define_method("term_criteria", &cv::detail::BundleAdjusterBase::termCriteria).
    define_method("set_term_criteria", &cv::detail::BundleAdjusterBase::setTermCriteria,
      Arg("term_criteria"));

  Rice::Data_Type<cv::detail::NoBundleAdjuster> rb_cCvDetailNoBundleAdjuster = define_class_under<cv::detail::NoBundleAdjuster, cv::detail::BundleAdjusterBase>(rb_mCvDetail, "NoBundleAdjuster").
    define_constructor(Constructor<cv::detail::NoBundleAdjuster>());

  Rice::Data_Type<cv::detail::BundleAdjusterReproj> rb_cCvDetailBundleAdjusterReproj = define_class_under<cv::detail::BundleAdjusterReproj, cv::detail::BundleAdjusterBase>(rb_mCvDetail, "BundleAdjusterReproj").
    define_constructor(Constructor<cv::detail::BundleAdjusterReproj>());

  Rice::Data_Type<cv::detail::BundleAdjusterRay> rb_cCvDetailBundleAdjusterRay = define_class_under<cv::detail::BundleAdjusterRay, cv::detail::BundleAdjusterBase>(rb_mCvDetail, "BundleAdjusterRay").
    define_constructor(Constructor<cv::detail::BundleAdjusterRay>());

  Rice::Data_Type<cv::detail::BundleAdjusterAffine> rb_cCvDetailBundleAdjusterAffine = define_class_under<cv::detail::BundleAdjusterAffine, cv::detail::BundleAdjusterBase>(rb_mCvDetail, "BundleAdjusterAffine").
    define_constructor(Constructor<cv::detail::BundleAdjusterAffine>());

  Rice::Data_Type<cv::detail::BundleAdjusterAffinePartial> rb_cCvDetailBundleAdjusterAffinePartial = define_class_under<cv::detail::BundleAdjusterAffinePartial, cv::detail::BundleAdjusterBase>(rb_mCvDetail, "BundleAdjusterAffinePartial").
    define_constructor(Constructor<cv::detail::BundleAdjusterAffinePartial>());

  Enum<cv::detail::WaveCorrectKind> rb_cCvDetailWaveCorrectKind = define_enum_under<cv::detail::WaveCorrectKind>("WaveCorrectKind", rb_mCvDetail).
    define_value("WAVE_CORRECT_HORIZ", cv::detail::WaveCorrectKind::WAVE_CORRECT_HORIZ).
    define_value("WAVE_CORRECT_VERT", cv::detail::WaveCorrectKind::WAVE_CORRECT_VERT).
    define_value("WAVE_CORRECT_AUTO", cv::detail::WaveCorrectKind::WAVE_CORRECT_AUTO);

  rb_mCvDetail.define_module_function("auto_detect_wave_correct_kind", &cv::detail::autoDetectWaveCorrectKind,
    Arg("rmats"));

  rb_mCvDetail.define_module_function("wave_correct", &cv::detail::waveCorrect,
    Arg("rmats"), Arg("kind"));

  rb_mCvDetail.define_module_function("matches_graph_as_string", &cv::detail::matchesGraphAsString,
    Arg("paths"), Arg("pairwise_matches"), Arg("conf_threshold"));

  rb_mCvDetail.define_module_function("leave_biggest_component", &cv::detail::leaveBiggestComponent,
    Arg("features"), Arg("pairwise_matches"), Arg("conf_threshold"));

  rb_mCvDetail.define_module_function("find_max_spanning_tree", &cv::detail::findMaxSpanningTree,
    Arg("num_images"), Arg("pairwise_matches"), Arg("span_tree"), Arg("centers"));
}