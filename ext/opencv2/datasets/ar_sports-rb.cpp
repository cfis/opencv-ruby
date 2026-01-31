#include <opencv2/datasets/ar_sports.hpp>
#include "ar_sports-rb.hpp"

using namespace Rice;

void Init_Datasets_ArSports()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::AR_sportsObj> rb_cCvDatasetsARSportsObj = define_class_under<cv::datasets::AR_sportsObj, cv::datasets::Object>(rb_mCvDatasets, "ARSportsObj").
    define_constructor(Constructor<cv::datasets::AR_sportsObj>()).
    define_attr("video_url", &cv::datasets::AR_sportsObj::videoUrl).
    define_attr("labels", &cv::datasets::AR_sportsObj::labels);

  Rice::Data_Type<cv::datasets::AR_sports> rb_cCvDatasetsARSports = define_class_under<cv::datasets::AR_sports, cv::datasets::Dataset>(rb_mCvDatasets, "ARSports").
    define_method<void(cv::datasets::AR_sports::*)(const std::string&)>("load", &cv::datasets::AR_sports::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::AR_sports>(*)()>("create", &cv::datasets::AR_sports::create);
}