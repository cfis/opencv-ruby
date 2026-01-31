#include <opencv2/datasets/fr_lfw.hpp>
#include "fr_lfw-rb.hpp"

using namespace Rice;

void Init_Datasets_FrLfw()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::FR_lfwObj> rb_cCvDatasetsFRLfwObj = define_class_under<cv::datasets::FR_lfwObj, cv::datasets::Object>(rb_mCvDatasets, "FRLfwObj").
    define_constructor(Constructor<cv::datasets::FR_lfwObj>()).
    define_attr("image1", &cv::datasets::FR_lfwObj::image1).
    define_attr("image2", &cv::datasets::FR_lfwObj::image2).
    define_attr("same", &cv::datasets::FR_lfwObj::same);

  Rice::Data_Type<cv::datasets::FR_lfw> rb_cCvDatasetsFRLfw = define_class_under<cv::datasets::FR_lfw, cv::datasets::Dataset>(rb_mCvDatasets, "FRLfw").
    define_method<void(cv::datasets::FR_lfw::*)(const std::string&)>("load", &cv::datasets::FR_lfw::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::FR_lfw>(*)()>("create", &cv::datasets::FR_lfw::create);
}