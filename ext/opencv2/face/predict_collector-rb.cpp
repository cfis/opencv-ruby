#include <opencv2/face/predict_collector.hpp>
#include "predict_collector-rb.hpp"

using namespace Rice;

void Init_Face_PredictCollector()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::PredictCollector> rb_cCvFacePredictCollector = define_class_under<cv::face::PredictCollector>(rb_mCvFace, "PredictCollector").
    define_method<void(cv::face::PredictCollector::*)(size_t)>("init", &cv::face::PredictCollector::init,
      Arg("size")).
    define_method<bool(cv::face::PredictCollector::*)(int, double)>("collect", &cv::face::PredictCollector::collect,
      Arg("label"), Arg("dist"));

  Rice::Data_Type<cv::face::StandardCollector> rb_cCvFaceStandardCollector = define_class_under<cv::face::StandardCollector, cv::face::PredictCollector>(rb_mCvFace, "StandardCollector").
    define_constructor(Constructor<cv::face::StandardCollector, double>(),
      Arg("threshold_") = static_cast<double>(DBL_MAX)).
    define_method<void(cv::face::StandardCollector::*)(size_t)>("init", &cv::face::StandardCollector::init,
      Arg("size")).
    define_method<bool(cv::face::StandardCollector::*)(int, double)>("collect", &cv::face::StandardCollector::collect,
      Arg("label"), Arg("dist")).
    define_method<int(cv::face::StandardCollector::*)() const>("get_min_label", &cv::face::StandardCollector::getMinLabel).
    define_method<double(cv::face::StandardCollector::*)() const>("get_min_dist", &cv::face::StandardCollector::getMinDist).
    define_method<std::vector<std::pair<int, double>>(cv::face::StandardCollector::*)(bool) const>("get_results", &cv::face::StandardCollector::getResults,
      Arg("sorted") = static_cast<bool>(false)).
    define_method<std::map<int, double>(cv::face::StandardCollector::*)() const>("get_results_map", &cv::face::StandardCollector::getResultsMap).
    define_singleton_function<cv::Ptr<cv::face::StandardCollector>(*)(double)>("create", &cv::face::StandardCollector::create,
      Arg("threshold") = static_cast<double>(DBL_MAX));

  Rice::Data_Type<cv::face::StandardCollector::PredictResult> rb_cCvFaceStandardCollectorPredictResult = define_class_under<cv::face::StandardCollector::PredictResult>(rb_cCvFaceStandardCollector, "PredictResult").
    define_attr("label", &cv::face::StandardCollector::PredictResult::label).
    define_attr("distance", &cv::face::StandardCollector::PredictResult::distance).
    define_constructor(Constructor<cv::face::StandardCollector::PredictResult, int, double>(),
      Arg("label_") = static_cast<int>(-1), Arg("distance_") = static_cast<double>(DBL_MAX));
}