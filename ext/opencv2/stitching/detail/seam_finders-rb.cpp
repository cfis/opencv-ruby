#include <opencv2/stitching/detail/seam_finders.hpp>
#include "../../core/cvstd_wrapper-rb.hpp"
#include "seam_finders-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailDpSeamFinder;
Rice::Class rb_cCvDetailGraphCutSeamFinder;
Rice::Class rb_cCvDetailGraphCutSeamFinderBase;
Rice::Class rb_cCvDetailNoSeamFinder;
Rice::Class rb_cCvDetailPairwiseSeamFinder;
Rice::Class rb_cCvDetailSeamFinder;
Rice::Class rb_cCvDetailVoronoiSeamFinder;

void Init_SeamFinders()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_cCvDetailSeamFinder = define_class_under<cv::detail::SeamFinder>(rb_mCvDetail, "SeamFinder").
    define_method("find", &cv::detail::SeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks")).
    define_singleton_function("create_default", &cv::detail::SeamFinder::createDefault,
      Arg("type"));
  
  rb_cCvDetailSeamFinder.define_constant("NO", (int)cv::detail::SeamFinder::NO);
  rb_cCvDetailSeamFinder.define_constant("VORONOI_SEAM", (int)cv::detail::SeamFinder::VORONOI_SEAM);
  rb_cCvDetailSeamFinder.define_constant("DP_SEAM", (int)cv::detail::SeamFinder::DP_SEAM);
  
  rb_cCvDetailNoSeamFinder = define_class_under<cv::detail::NoSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "NoSeamFinder").
    define_constructor(Constructor<cv::detail::NoSeamFinder>()).
    define_method("find", &cv::detail::NoSeamFinder::find,
      Arg(""), Arg(""), Arg(""));
  
  rb_cCvDetailPairwiseSeamFinder = define_class_under<cv::detail::PairwiseSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "PairwiseSeamFinder").
    define_method("find", &cv::detail::PairwiseSeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks"));
  
  rb_cCvDetailVoronoiSeamFinder = define_class_under<cv::detail::VoronoiSeamFinder, cv::detail::PairwiseSeamFinder>(rb_mCvDetail, "VoronoiSeamFinder").
    define_constructor(Constructor<cv::detail::VoronoiSeamFinder>()).
    define_method<void(cv::detail::VoronoiSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::VoronoiSeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks")).
    define_method<void(cv::detail::VoronoiSeamFinder::*)(const std::vector<cv::Size_<int>>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::VoronoiSeamFinder::find,
      Arg("size"), Arg("corners"), Arg("masks"));
  
  rb_cCvDetailDpSeamFinder = define_class_under<cv::detail::DpSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "DpSeamFinder").
    define_constructor(Constructor<cv::detail::DpSeamFinder, cv::detail::DpSeamFinder::CostFunction>(),
      Arg("cost_func") = static_cast<cv::detail::DpSeamFinder::CostFunction>(cv::detail::DpSeamFinder::CostFunction::COLOR)).
    define_constructor(Constructor<cv::detail::DpSeamFinder, cv::String>(),
      Arg("cost_func")).
    define_method("cost_function", &cv::detail::DpSeamFinder::costFunction).
    define_method<void(cv::detail::DpSeamFinder::*)(cv::detail::DpSeamFinder::CostFunction)>("set_cost_function", &cv::detail::DpSeamFinder::setCostFunction,
      Arg("val")).
    define_method<void(cv::detail::DpSeamFinder::*)(cv::String)>("set_cost_function", &cv::detail::DpSeamFinder::setCostFunction,
      Arg("val")).
    define_method("find", &cv::detail::DpSeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks"));
  
  Enum<cv::detail::DpSeamFinder::CostFunction> rb_cCvDetailDpSeamFinderCostFunction = define_enum_under<cv::detail::DpSeamFinder::CostFunction>("CostFunction", rb_cCvDetailDpSeamFinder).
    define_value("COLOR", cv::detail::DpSeamFinder::CostFunction::COLOR).
    define_value("COLOR_GRAD", cv::detail::DpSeamFinder::CostFunction::COLOR_GRAD);
  
  rb_cCvDetailGraphCutSeamFinderBase = define_class_under<cv::detail::GraphCutSeamFinderBase>(rb_mCvDetail, "GraphCutSeamFinderBase").
    define_constructor(Constructor<cv::detail::GraphCutSeamFinderBase>());
  
  Enum<cv::detail::GraphCutSeamFinderBase::CostType> rb_cCvDetailGraphCutSeamFinderBaseCostType = define_enum_under<cv::detail::GraphCutSeamFinderBase::CostType>("CostType", rb_cCvDetailGraphCutSeamFinderBase).
    define_value("COST_COLOR", cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR).
    define_value("COST_COLOR_GRAD", cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR_GRAD);
  
  rb_cCvDetailGraphCutSeamFinder = define_class_under<cv::detail::GraphCutSeamFinder, cv::detail::GraphCutSeamFinderBase>(rb_mCvDetail, "GraphCutSeamFinder").
    define_constructor(Constructor<cv::detail::GraphCutSeamFinder, int, float, float>(),
      Arg("cost_type") = static_cast<int>(cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR_GRAD), Arg("terminal_cost") = static_cast<float>(10000.f), Arg("bad_region_penalty") = static_cast<float>(1000.f)).
    define_constructor(Constructor<cv::detail::GraphCutSeamFinder, cv::String, float, float>(),
      Arg("cost_type"), Arg("terminal_cost") = static_cast<float>(10000.f), Arg("bad_region_penalty") = static_cast<float>(1000.f)).
    define_method("find", &cv::detail::GraphCutSeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks"));

}