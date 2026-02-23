#include <opencv2/datasets/hpe_parse.hpp>
#include "hpe_parse-rb.hpp"

using namespace Rice;

void Init_Datasets_HpeParse()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::HPE_parseObj> rb_cCvDatasetsHPEParseObj = define_class_under<cv::datasets::HPE_parseObj, cv::datasets::Object>(rb_mCvDatasets, "HPEParseObj").
    define_constructor(Constructor<cv::datasets::HPE_parseObj>()).
    define_attr("name", &cv::datasets::HPE_parseObj::name);

  Rice::Data_Type<cv::datasets::HPE_parse> rb_cCvDatasetsHPEParse = define_class_under<cv::datasets::HPE_parse, cv::datasets::Dataset>(rb_mCvDatasets, "HPEParse").
    define_method<void(cv::datasets::HPE_parse::*)(const std::string&)>("load", &cv::datasets::HPE_parse::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::HPE_parse>(*)()>("create", &cv::datasets::HPE_parse::create);
}
