#include <opencv2/datasets/is_weizmann.hpp>
#include "is_weizmann-rb.hpp"

using namespace Rice;

void Init_Datasets_IsWeizmann()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::IS_weizmannObj> rb_cCvDatasetsISWeizmannObj = define_class_under<cv::datasets::IS_weizmannObj, cv::datasets::Object>(rb_mCvDatasets, "ISWeizmannObj").
    define_constructor(Constructor<cv::datasets::IS_weizmannObj>()).
    define_attr("image_name", &cv::datasets::IS_weizmannObj::imageName).
    define_attr("src_bw", &cv::datasets::IS_weizmannObj::srcBw).
    define_attr("src_color", &cv::datasets::IS_weizmannObj::srcColor).
    define_attr("human_seg", &cv::datasets::IS_weizmannObj::humanSeg);

  Rice::Data_Type<cv::datasets::IS_weizmann> rb_cCvDatasetsISWeizmann = define_class_under<cv::datasets::IS_weizmann, cv::datasets::Dataset>(rb_mCvDatasets, "ISWeizmann").
    define_method<void(cv::datasets::IS_weizmann::*)(const std::string&)>("load", &cv::datasets::IS_weizmann::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::IS_weizmann>(*)()>("create", &cv::datasets::IS_weizmann::create);
}
