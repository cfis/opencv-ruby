#include <opencv2/datasets/tr_svt.hpp>
#include "tr_svt-rb.hpp"

using namespace Rice;

void Init_Datasets_TrSvt()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::tag> rb_cCvDatasetsTag = define_class_under<cv::datasets::tag>(rb_mCvDatasets, "Tag").
    define_constructor(Constructor<cv::datasets::tag>()).
    define_attr("value", &cv::datasets::tag::value).
    define_attr("height", &cv::datasets::tag::height).
    define_attr("width", &cv::datasets::tag::width).
    define_attr("x", &cv::datasets::tag::x).
    define_attr("y", &cv::datasets::tag::y);

  Rice::Data_Type<cv::datasets::TR_svtObj> rb_cCvDatasetsTRSvtObj = define_class_under<cv::datasets::TR_svtObj, cv::datasets::Object>(rb_mCvDatasets, "TRSvtObj").
    define_constructor(Constructor<cv::datasets::TR_svtObj>()).
    define_attr("file_name", &cv::datasets::TR_svtObj::fileName).
    define_attr("lex", &cv::datasets::TR_svtObj::lex).
    define_attr("tags", &cv::datasets::TR_svtObj::tags);

  Rice::Data_Type<cv::datasets::TR_svt> rb_cCvDatasetsTRSvt = define_class_under<cv::datasets::TR_svt, cv::datasets::Dataset>(rb_mCvDatasets, "TRSvt").
    define_method<void(cv::datasets::TR_svt::*)(const std::string&)>("load", &cv::datasets::TR_svt::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::TR_svt>(*)()>("create", &cv::datasets::TR_svt::create);
}