#include <opencv2/datasets/dataset.hpp>
#include "dataset-rb.hpp"

using namespace Rice;

void Init_Datasets_Dataset()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::Object> rb_cCvDatasetsObject = define_class_under<cv::datasets::Object>(rb_mCvDatasets, "Object").
    define_constructor(Constructor<cv::datasets::Object>());

  Rice::Data_Type<cv::datasets::Dataset> rb_cCvDatasetsDataset = define_class_under<cv::datasets::Dataset>(rb_mCvDatasets, "Dataset").
    define_method<void(cv::datasets::Dataset::*)(const std::string&)>("load", &cv::datasets::Dataset::load,
      Arg("path")).
    define_method<std::vector<cv::Ptr<cv::datasets::Object>>&(cv::datasets::Dataset::*)(int)>("get_train", &cv::datasets::Dataset::getTrain,
      Arg("split_num") = static_cast<int>(0)).
    define_method<std::vector<cv::Ptr<cv::datasets::Object>>&(cv::datasets::Dataset::*)(int)>("get_test", &cv::datasets::Dataset::getTest,
      Arg("split_num") = static_cast<int>(0)).
    define_method<std::vector<cv::Ptr<cv::datasets::Object>>&(cv::datasets::Dataset::*)(int)>("get_validation", &cv::datasets::Dataset::getValidation,
      Arg("split_num") = static_cast<int>(0)).
    define_method<int(cv::datasets::Dataset::*)() const>("get_num_splits", &cv::datasets::Dataset::getNumSplits);
}