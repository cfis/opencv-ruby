#include <opencv2/datasets/or_sun.hpp>
#include "or_sun-rb.hpp"

using namespace Rice;

void Init_Datasets_OrSun()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::OR_sunObj> rb_cCvDatasetsORSunObj = define_class_under<cv::datasets::OR_sunObj, cv::datasets::Object>(rb_mCvDatasets, "ORSunObj").
    define_constructor(Constructor<cv::datasets::OR_sunObj>()).
    define_attr("label", &cv::datasets::OR_sunObj::label).
    define_attr("name", &cv::datasets::OR_sunObj::name);

  Rice::Data_Type<cv::datasets::OR_sun> rb_cCvDatasetsORSun = define_class_under<cv::datasets::OR_sun, cv::datasets::Dataset>(rb_mCvDatasets, "ORSun").
    define_method<void(cv::datasets::OR_sun::*)(const std::string&)>("load", &cv::datasets::OR_sun::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::OR_sun>(*)()>("create", &cv::datasets::OR_sun::create).
    define_attr("paths", &cv::datasets::OR_sun::paths);
}
