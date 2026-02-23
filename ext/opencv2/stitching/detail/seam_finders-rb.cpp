#include <opencv2/stitching/detail/seam_finders.hpp>
#include "seam_finders-rb.hpp"

using namespace Rice;

void Init_Stitching_Detail_SeamFinders()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Rice::Data_Type<cv::detail::SeamFinder> rb_cCvDetailSeamFinder = define_class_under<cv::detail::SeamFinder>(rb_mCvDetail, "SeamFinder").
    define_method<void(cv::detail::SeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::SeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks")).
    define_singleton_function<cv::Ptr<cv::detail::SeamFinder>(*)(int)>("create_default", &cv::detail::SeamFinder::createDefault,
      Arg("type"));

  rb_cCvDetailSeamFinder.define_constant("NO", (int)cv::detail::SeamFinder::NO);
  rb_cCvDetailSeamFinder.define_constant("VORONOI_SEAM", (int)cv::detail::SeamFinder::VORONOI_SEAM);
  rb_cCvDetailSeamFinder.define_constant("DP_SEAM", (int)cv::detail::SeamFinder::DP_SEAM);

  Rice::Data_Type<cv::detail::NoSeamFinder> rb_cCvDetailNoSeamFinder = define_class_under<cv::detail::NoSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "NoSeamFinder").
    define_constructor(Constructor<cv::detail::NoSeamFinder>()).
    define_method<void(cv::detail::NoSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::NoSeamFinder::find,
      Arg("arg_0"), Arg("arg_1"), Arg("arg_2"));

  Rice::Data_Type<cv::detail::PairwiseSeamFinder> rb_cCvDetailPairwiseSeamFinder = define_class_under<cv::detail::PairwiseSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "PairwiseSeamFinder").
    define_method<void(cv::detail::PairwiseSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::PairwiseSeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks"));

  Rice::Data_Type<cv::detail::VoronoiSeamFinder> rb_cCvDetailVoronoiSeamFinder = define_class_under<cv::detail::VoronoiSeamFinder, cv::detail::PairwiseSeamFinder>(rb_mCvDetail, "VoronoiSeamFinder").
    define_constructor(Constructor<cv::detail::VoronoiSeamFinder>()).
    define_method<void(cv::detail::VoronoiSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::VoronoiSeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks")).
    define_method<void(cv::detail::VoronoiSeamFinder::*)(const std::vector<cv::Size_<int>>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::VoronoiSeamFinder::find,
      Arg("size"), Arg("corners"), Arg("masks"));

  Rice::Data_Type<cv::detail::DpSeamFinder> rb_cCvDetailDpSeamFinder = define_class_under<cv::detail::DpSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "DpSeamFinder").
    define_constructor(Constructor<cv::detail::DpSeamFinder, cv::detail::DpSeamFinder::CostFunction>(),
      Arg("cost_func") = static_cast<cv::detail::DpSeamFinder::CostFunction>(cv::detail::DpSeamFinder::CostFunction::COLOR)).
    define_constructor(Constructor<cv::detail::DpSeamFinder, cv::String>(),
      Arg("cost_func")).
    define_method<cv::detail::DpSeamFinder::CostFunction(cv::detail::DpSeamFinder::*)() const>("cost_function", &cv::detail::DpSeamFinder::costFunction).
    define_method<void(cv::detail::DpSeamFinder::*)(cv::detail::DpSeamFinder::CostFunction)>("set_cost_function", &cv::detail::DpSeamFinder::setCostFunction,
      Arg("val")).
    define_method<void(cv::detail::DpSeamFinder::*)(cv::String)>("set_cost_function", &cv::detail::DpSeamFinder::setCostFunction,
      Arg("val")).
    define_method<void(cv::detail::DpSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::DpSeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks"));

  Enum<cv::detail::DpSeamFinder::CostFunction> rb_cCvDetailDpSeamFinderCostFunction = define_enum_under<cv::detail::DpSeamFinder::CostFunction>("CostFunction", rb_cCvDetailDpSeamFinder).
    define_value("COLOR", cv::detail::DpSeamFinder::CostFunction::COLOR).
    define_value("COLOR_GRAD", cv::detail::DpSeamFinder::CostFunction::COLOR_GRAD);

  Rice::Data_Type<cv::detail::GraphCutSeamFinderBase> rb_cCvDetailGraphCutSeamFinderBase = define_class_under<cv::detail::GraphCutSeamFinderBase>(rb_mCvDetail, "GraphCutSeamFinderBase").
    define_constructor(Constructor<cv::detail::GraphCutSeamFinderBase>());

  Enum<cv::detail::GraphCutSeamFinderBase::CostType> rb_cCvDetailGraphCutSeamFinderBaseCostType = define_enum_under<cv::detail::GraphCutSeamFinderBase::CostType>("CostType", rb_cCvDetailGraphCutSeamFinderBase).
    define_value("COST_COLOR", cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR).
    define_value("COST_COLOR_GRAD", cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR_GRAD);

  Rice::Data_Type<cv::detail::GraphCutSeamFinder> rb_cCvDetailGraphCutSeamFinder = define_class_under<cv::detail::GraphCutSeamFinder, cv::detail::GraphCutSeamFinderBase>(rb_mCvDetail, "GraphCutSeamFinder").
    define_constructor(Constructor<cv::detail::GraphCutSeamFinder, int, float, float>(),
      Arg("cost_type") = static_cast<int>(cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR_GRAD), Arg("terminal_cost") = static_cast<float>(10000.f), Arg("bad_region_penalty") = static_cast<float>(1000.f)).
    define_constructor(Constructor<cv::detail::GraphCutSeamFinder, cv::String, float, float>(),
      Arg("cost_type"), Arg("terminal_cost") = static_cast<float>(10000.f), Arg("bad_region_penalty") = static_cast<float>(1000.f)).
    define_method<void(cv::detail::GraphCutSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::GraphCutSeamFinder::find,
      Arg("src"), Arg("corners"), Arg("masks"));

  Rice::Data_Type<cv::detail::GraphCutSeamFinderGpu> rb_cCvDetailGraphCutSeamFinderGpu = define_class_under<cv::detail::GraphCutSeamFinderGpu, cv::detail::GraphCutSeamFinderBase>(rb_mCvDetail, "GraphCutSeamFinderGpu").
    define_constructor(Constructor<cv::detail::GraphCutSeamFinderGpu, int, float, float>(),
      Arg("cost_type") = static_cast<int>(cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR_GRAD), Arg("terminal_cost") = static_cast<float>(10000.f), Arg("bad_region_penalty") = static_cast<float>(1000.f)).
    define_method<void(cv::detail::GraphCutSeamFinderGpu::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point>&, std::vector<cv::UMat>&)>("find", &cv::detail::GraphCutSeamFinderGpu::find,
      Arg("src"), Arg("corners"), Arg("masks")).
    define_method<void(cv::detail::GraphCutSeamFinderGpu::*)(size_t, size_t, cv::Rect)>("find_in_pair", &cv::detail::GraphCutSeamFinderGpu::findInPair,
      Arg("first"), Arg("second"), Arg("roi"));
}
