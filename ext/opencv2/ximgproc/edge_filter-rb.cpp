#include <opencv2/ximgproc/edge_filter.hpp>
#include "edge_filter-rb.hpp"

using namespace Rice;

void Init_Ximgproc_EdgeFilter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Enum<cv::ximgproc::EdgeAwareFiltersList> rb_cCvXimgprocEdgeAwareFiltersList = define_enum_under<cv::ximgproc::EdgeAwareFiltersList>("EdgeAwareFiltersList", rb_mCvXimgproc).
    define_value("DTF_NC", cv::ximgproc::EdgeAwareFiltersList::DTF_NC).
    define_value("DTF_IC", cv::ximgproc::EdgeAwareFiltersList::DTF_IC).
    define_value("DTF_RF", cv::ximgproc::EdgeAwareFiltersList::DTF_RF).
    define_value("GUIDED_FILTER", cv::ximgproc::EdgeAwareFiltersList::GUIDED_FILTER).
    define_value("AM_FILTER", cv::ximgproc::EdgeAwareFiltersList::AM_FILTER);

  Rice::Data_Type<cv::ximgproc::DTFilter> rb_cCvXimgprocDTFilter = define_class_under<cv::ximgproc::DTFilter, cv::Algorithm>(rb_mCvXimgproc, "DTFilter").
    define_method<void(cv::ximgproc::DTFilter::*)(cv::InputArray, cv::OutputArray, int)>("filter", &cv::ximgproc::DTFilter::filter,
      Arg("src"), Arg("dst"), Arg("d_depth") = static_cast<int>(-1));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::DTFilter>(*)(cv::InputArray, double, double, int, int)>("create_dt_filter", &cv::ximgproc::createDTFilter,
    Arg("guide"), Arg("sigma_spatial"), Arg("sigma_color"), Arg("mode") = static_cast<int>(cv::ximgproc::DTF_NC), Arg("num_iters") = static_cast<int>(3));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double, double, int, int)>("dt_filter", &cv::ximgproc::dtFilter,
    Arg("guide"), Arg("src"), Arg("dst"), Arg("sigma_spatial"), Arg("sigma_color"), Arg("mode") = static_cast<int>(cv::ximgproc::DTF_NC), Arg("num_iters") = static_cast<int>(3));

  Rice::Data_Type<cv::ximgproc::GuidedFilter> rb_cCvXimgprocGuidedFilter = define_class_under<cv::ximgproc::GuidedFilter, cv::Algorithm>(rb_mCvXimgproc, "GuidedFilter").
    define_method<void(cv::ximgproc::GuidedFilter::*)(cv::InputArray, cv::OutputArray, int)>("filter", &cv::ximgproc::GuidedFilter::filter,
      Arg("src"), Arg("dst"), Arg("d_depth") = static_cast<int>(-1));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::GuidedFilter>(*)(cv::InputArray, int, double, double)>("create_guided_filter", &cv::ximgproc::createGuidedFilter,
    Arg("guide"), Arg("radius"), Arg("eps"), Arg("scale") = static_cast<double>(1.0));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, double, int, double)>("guided_filter", &cv::ximgproc::guidedFilter,
    Arg("guide"), Arg("src"), Arg("dst"), Arg("radius"), Arg("eps"), Arg("d_depth") = static_cast<int>(-1), Arg("scale") = static_cast<double>(1.0));

  Rice::Data_Type<cv::ximgproc::AdaptiveManifoldFilter> rb_cCvXimgprocAdaptiveManifoldFilter = define_class_under<cv::ximgproc::AdaptiveManifoldFilter, cv::Algorithm>(rb_mCvXimgproc, "AdaptiveManifoldFilter").
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(cv::InputArray, cv::OutputArray, cv::InputArray)>("filter", &cv::ximgproc::AdaptiveManifoldFilter::filter,
      Arg("src"), Arg("dst"), Arg("joint") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)()>("collect_garbage", &cv::ximgproc::AdaptiveManifoldFilter::collectGarbage).
    define_method<double(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_sigma_s", &cv::ximgproc::AdaptiveManifoldFilter::getSigmaS).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(double)>("set_sigma_s", &cv::ximgproc::AdaptiveManifoldFilter::setSigmaS,
      Arg("val")).
    define_method<double(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_sigma_r", &cv::ximgproc::AdaptiveManifoldFilter::getSigmaR).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(double)>("set_sigma_r", &cv::ximgproc::AdaptiveManifoldFilter::setSigmaR,
      Arg("val")).
    define_method<int(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_tree_height", &cv::ximgproc::AdaptiveManifoldFilter::getTreeHeight).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(int)>("set_tree_height", &cv::ximgproc::AdaptiveManifoldFilter::setTreeHeight,
      Arg("val")).
    define_method<int(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_pca_iterations", &cv::ximgproc::AdaptiveManifoldFilter::getPCAIterations).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(int)>("set_pca_iterations", &cv::ximgproc::AdaptiveManifoldFilter::setPCAIterations,
      Arg("val")).
    define_method<bool(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_adjust_outliers?", &cv::ximgproc::AdaptiveManifoldFilter::getAdjustOutliers).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(bool)>("set_adjust_outliers", &cv::ximgproc::AdaptiveManifoldFilter::setAdjustOutliers,
      Arg("val")).
    define_method<bool(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_use_rng?", &cv::ximgproc::AdaptiveManifoldFilter::getUseRNG).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(bool)>("set_use_rng", &cv::ximgproc::AdaptiveManifoldFilter::setUseRNG,
      Arg("val")).
    define_singleton_function<cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>(*)()>("create", &cv::ximgproc::AdaptiveManifoldFilter::create);

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>(*)(double, double, bool)>("create_am_filter", &cv::ximgproc::createAMFilter,
    Arg("sigma_s"), Arg("sigma_r"), Arg("adjust_outliers") = static_cast<bool>(false));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double, double, bool)>("am_filter", &cv::ximgproc::amFilter,
    Arg("joint"), Arg("src"), Arg("dst"), Arg("sigma_s"), Arg("sigma_r"), Arg("adjust_outliers") = static_cast<bool>(false));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, double, double, int)>("joint_bilateral_filter", &cv::ximgproc::jointBilateralFilter,
    Arg("joint"), Arg("src"), Arg("dst"), Arg("d"), Arg("sigma_color"), Arg("sigma_space"), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, double, double)>("bilateral_texture_filter", &cv::ximgproc::bilateralTextureFilter,
    Arg("src"), Arg("dst"), Arg("fr") = static_cast<int>(3), Arg("num_iter") = static_cast<int>(1), Arg("sigma_alpha") = static_cast<double>(-1.), Arg("sigma_avg") = static_cast<double>(-1.));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, int, int)>("rolling_guidance_filter", &cv::ximgproc::rollingGuidanceFilter,
    Arg("src"), Arg("dst"), Arg("d") = static_cast<int>(-1), Arg("sigma_color") = static_cast<double>(25), Arg("sigma_space") = static_cast<double>(3), Arg("num_of_iter") = static_cast<int>(4), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  Rice::Data_Type<cv::ximgproc::FastBilateralSolverFilter> rb_cCvXimgprocFastBilateralSolverFilter = define_class_under<cv::ximgproc::FastBilateralSolverFilter, cv::Algorithm>(rb_mCvXimgproc, "FastBilateralSolverFilter").
    define_method<void(cv::ximgproc::FastBilateralSolverFilter::*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("filter", &cv::ximgproc::FastBilateralSolverFilter::filter,
      Arg("src"), Arg("confidence"), Arg("dst"));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::FastBilateralSolverFilter>(*)(cv::InputArray, double, double, double, double, int, double)>("create_fast_bilateral_solver_filter", &cv::ximgproc::createFastBilateralSolverFilter,
    Arg("guide"), Arg("sigma_spatial"), Arg("sigma_luma"), Arg("sigma_chroma"), Arg("lambda") = static_cast<double>(128.0), Arg("num_iter") = static_cast<int>(25), Arg("max_tol") = static_cast<double>(1e-5));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, double, double, double, double, int, double)>("fast_bilateral_solver_filter", &cv::ximgproc::fastBilateralSolverFilter,
    Arg("guide"), Arg("src"), Arg("confidence"), Arg("dst"), Arg("sigma_spatial") = static_cast<double>(8), Arg("sigma_luma") = static_cast<double>(8), Arg("sigma_chroma") = static_cast<double>(8), Arg("lambda") = static_cast<double>(128.0), Arg("num_iter") = static_cast<int>(25), Arg("max_tol") = static_cast<double>(1e-5));

  Rice::Data_Type<cv::ximgproc::FastGlobalSmootherFilter> rb_cCvXimgprocFastGlobalSmootherFilter = define_class_under<cv::ximgproc::FastGlobalSmootherFilter, cv::Algorithm>(rb_mCvXimgproc, "FastGlobalSmootherFilter").
    define_method<void(cv::ximgproc::FastGlobalSmootherFilter::*)(cv::InputArray, cv::OutputArray)>("filter", &cv::ximgproc::FastGlobalSmootherFilter::filter,
      Arg("src"), Arg("dst"));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::FastGlobalSmootherFilter>(*)(cv::InputArray, double, double, double, int)>("create_fast_global_smoother_filter", &cv::ximgproc::createFastGlobalSmootherFilter,
    Arg("guide"), Arg("lambda"), Arg("sigma_color"), Arg("lambda_attenuation") = static_cast<double>(0.25), Arg("num_iter") = static_cast<int>(3));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double, double, double, int)>("fast_global_smoother_filter", &cv::ximgproc::fastGlobalSmootherFilter,
    Arg("guide"), Arg("src"), Arg("dst"), Arg("lambda"), Arg("sigma_color"), Arg("lambda_attenuation") = static_cast<double>(0.25), Arg("num_iter") = static_cast<int>(3));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double)>("l0_smooth", &cv::ximgproc::l0Smooth,
    Arg("src"), Arg("dst"), Arg("lambda") = static_cast<double>(0.02), Arg("kappa") = static_cast<double>(2.0));
}