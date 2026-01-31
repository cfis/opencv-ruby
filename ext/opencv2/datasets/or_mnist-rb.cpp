#include <opencv2/datasets/or_mnist.hpp>
#include "or_mnist-rb.hpp"

using namespace Rice;

void Init_Datasets_OrMnist()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::OR_mnistObj> rb_cCvDatasetsORMnistObj = define_class_under<cv::datasets::OR_mnistObj, cv::datasets::Object>(rb_mCvDatasets, "ORMnistObj").
    define_constructor(Constructor<cv::datasets::OR_mnistObj>()).
    define_attr("label", &cv::datasets::OR_mnistObj::label).
    define_attr("image", &cv::datasets::OR_mnistObj::image);

  Rice::Data_Type<cv::datasets::OR_mnist> rb_cCvDatasetsORMnist = define_class_under<cv::datasets::OR_mnist, cv::datasets::Dataset>(rb_mCvDatasets, "ORMnist").
    define_method<void(cv::datasets::OR_mnist::*)(const std::string&)>("load", &cv::datasets::OR_mnist::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::OR_mnist>(*)()>("create", &cv::datasets::OR_mnist::create);
}