#include <opencv2/datasets/tr_chars.hpp>
#include "tr_chars-rb.hpp"

using namespace Rice;

void Init_Datasets_TrChars()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::TR_charsObj> rb_cCvDatasetsTRCharsObj = define_class_under<cv::datasets::TR_charsObj, cv::datasets::Object>(rb_mCvDatasets, "TRCharsObj").
    define_constructor(Constructor<cv::datasets::TR_charsObj>()).
    define_attr("img_name", &cv::datasets::TR_charsObj::imgName).
    define_attr("label", &cv::datasets::TR_charsObj::label);

  Rice::Data_Type<cv::datasets::TR_chars> rb_cCvDatasetsTRChars = define_class_under<cv::datasets::TR_chars, cv::datasets::Dataset>(rb_mCvDatasets, "TRChars").
    define_method<void(cv::datasets::TR_chars::*)(const std::string&)>("load", &cv::datasets::TR_chars::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::TR_chars>(*)()>("create", &cv::datasets::TR_chars::create);
}