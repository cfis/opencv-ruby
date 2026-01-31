#include <opencv2/datasets/is_bsds.hpp>
#include "is_bsds-rb.hpp"

using namespace Rice;

void Init_Datasets_IsBsds()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::IS_bsdsObj> rb_cCvDatasetsISBsdsObj = define_class_under<cv::datasets::IS_bsdsObj, cv::datasets::Object>(rb_mCvDatasets, "ISBsdsObj").
    define_constructor(Constructor<cv::datasets::IS_bsdsObj>()).
    define_attr("name", &cv::datasets::IS_bsdsObj::name);

  Rice::Data_Type<cv::datasets::IS_bsds> rb_cCvDatasetsISBsds = define_class_under<cv::datasets::IS_bsds, cv::datasets::Dataset>(rb_mCvDatasets, "ISBsds").
    define_method<void(cv::datasets::IS_bsds::*)(const std::string&)>("load", &cv::datasets::IS_bsds::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::IS_bsds>(*)()>("create", &cv::datasets::IS_bsds::create);
}