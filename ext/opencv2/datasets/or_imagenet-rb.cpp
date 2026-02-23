#include <opencv2/datasets/or_imagenet.hpp>
#include "or_imagenet-rb.hpp"

using namespace Rice;

void Init_Datasets_OrImagenet()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::OR_imagenetObj> rb_cCvDatasetsORImagenetObj = define_class_under<cv::datasets::OR_imagenetObj, cv::datasets::Object>(rb_mCvDatasets, "ORImagenetObj").
    define_constructor(Constructor<cv::datasets::OR_imagenetObj>()).
    define_attr("id", &cv::datasets::OR_imagenetObj::id).
    define_attr("image", &cv::datasets::OR_imagenetObj::image);

  Rice::Data_Type<cv::datasets::OR_imagenet> rb_cCvDatasetsORImagenet = define_class_under<cv::datasets::OR_imagenet, cv::datasets::Dataset>(rb_mCvDatasets, "ORImagenet").
    define_method<void(cv::datasets::OR_imagenet::*)(const std::string&)>("load", &cv::datasets::OR_imagenet::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::OR_imagenet>(*)()>("create", &cv::datasets::OR_imagenet::create);
}
