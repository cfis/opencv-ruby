#include <opencv2/ximgproc/sparse_match_interpolator.hpp>
#include "sparse_match_interpolator-rb.hpp"

using namespace Rice;

void Init_Ximgproc_SparseMatchInterpolator()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::SparseMatchInterpolator> rb_cCvXimgprocSparseMatchInterpolator = define_class_under<cv::ximgproc::SparseMatchInterpolator, cv::Algorithm>(rb_mCvXimgproc, "SparseMatchInterpolator").
    define_method<void(cv::ximgproc::SparseMatchInterpolator::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray)>("interpolate", &cv::ximgproc::SparseMatchInterpolator::interpolate,
      Arg("from_image"), Arg("from_points"), Arg("to_image"), Arg("to_points"), Arg("dense_flow"));

  Rice::Data_Type<cv::ximgproc::EdgeAwareInterpolator> rb_cCvXimgprocEdgeAwareInterpolator = define_class_under<cv::ximgproc::EdgeAwareInterpolator, cv::ximgproc::SparseMatchInterpolator>(rb_mCvXimgproc, "EdgeAwareInterpolator").
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(const cv::Mat&)>("set_cost_map", &cv::ximgproc::EdgeAwareInterpolator::setCostMap,
      Arg("_cost_map")).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(int)>("set_k", &cv::ximgproc::EdgeAwareInterpolator::setK,
      Arg("_k")).
    define_method<int(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_k", &cv::ximgproc::EdgeAwareInterpolator::getK).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(float)>("set_sigma", &cv::ximgproc::EdgeAwareInterpolator::setSigma,
      Arg("_sigma")).
    define_method<float(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_sigma", &cv::ximgproc::EdgeAwareInterpolator::getSigma).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(float)>("set_lambda", &cv::ximgproc::EdgeAwareInterpolator::setLambda,
      Arg("_lambda")).
    define_method<float(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_lambda", &cv::ximgproc::EdgeAwareInterpolator::getLambda).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(bool)>("set_use_post_processing", &cv::ximgproc::EdgeAwareInterpolator::setUsePostProcessing,
      Arg("_use_post_proc")).
    define_method<bool(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_use_post_processing?", &cv::ximgproc::EdgeAwareInterpolator::getUsePostProcessing).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(float)>("set_fgs_lambda", &cv::ximgproc::EdgeAwareInterpolator::setFGSLambda,
      Arg("_lambda")).
    define_method<float(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_fgs_lambda", &cv::ximgproc::EdgeAwareInterpolator::getFGSLambda).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(float)>("set_fgs_sigma", &cv::ximgproc::EdgeAwareInterpolator::setFGSSigma,
      Arg("_sigma")).
    define_method<float(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_fgs_sigma", &cv::ximgproc::EdgeAwareInterpolator::getFGSSigma);

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::EdgeAwareInterpolator>(*)()>("create_edge_aware_interpolator", &cv::ximgproc::createEdgeAwareInterpolator);

  Rice::Data_Type<cv::ximgproc::RICInterpolator> rb_cCvXimgprocRICInterpolator = define_class_under<cv::ximgproc::RICInterpolator, cv::ximgproc::SparseMatchInterpolator>(rb_mCvXimgproc, "RICInterpolator").
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_k", &cv::ximgproc::RICInterpolator::setK,
      Arg("k") = static_cast<int>(32)).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_k", &cv::ximgproc::RICInterpolator::getK).
    define_method<void(cv::ximgproc::RICInterpolator::*)(const cv::Mat&)>("set_cost_map", &cv::ximgproc::RICInterpolator::setCostMap,
      Arg("cost_map")).
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_superpixel_size", &cv::ximgproc::RICInterpolator::setSuperpixelSize,
      Arg("sp_size") = static_cast<int>(15)).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_superpixel_size", &cv::ximgproc::RICInterpolator::getSuperpixelSize).
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_superpixel_nn_cnt", &cv::ximgproc::RICInterpolator::setSuperpixelNNCnt,
      Arg("sp_nn") = static_cast<int>(150)).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_superpixel_nn_cnt", &cv::ximgproc::RICInterpolator::getSuperpixelNNCnt).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_superpixel_ruler", &cv::ximgproc::RICInterpolator::setSuperpixelRuler,
      Arg("ruler") = static_cast<float>(15.f)).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_superpixel_ruler", &cv::ximgproc::RICInterpolator::getSuperpixelRuler).
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_superpixel_mode", &cv::ximgproc::RICInterpolator::setSuperpixelMode,
      Arg("mode") = static_cast<int>(100)).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_superpixel_mode", &cv::ximgproc::RICInterpolator::getSuperpixelMode).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_alpha", &cv::ximgproc::RICInterpolator::setAlpha,
      Arg("alpha") = static_cast<float>(0.7f)).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_alpha", &cv::ximgproc::RICInterpolator::getAlpha).
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_model_iter", &cv::ximgproc::RICInterpolator::setModelIter,
      Arg("model_iter") = static_cast<int>(4)).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_model_iter", &cv::ximgproc::RICInterpolator::getModelIter).
    define_method<void(cv::ximgproc::RICInterpolator::*)(bool)>("set_refine_models", &cv::ximgproc::RICInterpolator::setRefineModels,
      Arg("refine_modles") = static_cast<bool>(true)).
    define_method<bool(cv::ximgproc::RICInterpolator::*)() const>("get_refine_models?", &cv::ximgproc::RICInterpolator::getRefineModels).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_max_flow", &cv::ximgproc::RICInterpolator::setMaxFlow,
      Arg("max_flow") = static_cast<float>(250.f)).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_max_flow", &cv::ximgproc::RICInterpolator::getMaxFlow).
    define_method<void(cv::ximgproc::RICInterpolator::*)(bool)>("set_use_variational_refinement", &cv::ximgproc::RICInterpolator::setUseVariationalRefinement,
      Arg("use_variational_refinement") = static_cast<bool>(false)).
    define_method<bool(cv::ximgproc::RICInterpolator::*)() const>("get_use_variational_refinement?", &cv::ximgproc::RICInterpolator::getUseVariationalRefinement).
    define_method<void(cv::ximgproc::RICInterpolator::*)(bool)>("set_use_global_smoother_filter", &cv::ximgproc::RICInterpolator::setUseGlobalSmootherFilter,
      Arg("use_fgs") = static_cast<bool>(true)).
    define_method<bool(cv::ximgproc::RICInterpolator::*)() const>("get_use_global_smoother_filter?", &cv::ximgproc::RICInterpolator::getUseGlobalSmootherFilter).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_fgs_lambda", &cv::ximgproc::RICInterpolator::setFGSLambda,
      Arg("lambda") = static_cast<float>(500.f)).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_fgs_lambda", &cv::ximgproc::RICInterpolator::getFGSLambda).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_fgs_sigma", &cv::ximgproc::RICInterpolator::setFGSSigma,
      Arg("sigma") = static_cast<float>(1.5f)).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_fgs_sigma", &cv::ximgproc::RICInterpolator::getFGSSigma);

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::RICInterpolator>(*)()>("create_ric_interpolator", &cv::ximgproc::createRICInterpolator);
}