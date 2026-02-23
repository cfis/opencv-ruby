#include <opencv2/datasets/ar_hmdb.hpp>
#include "ar_hmdb-rb.hpp"

using namespace Rice;

void Init_Datasets_ArHmdb()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::AR_hmdbObj> rb_cCvDatasetsARHmdbObj = define_class_under<cv::datasets::AR_hmdbObj, cv::datasets::Object>(rb_mCvDatasets, "ARHmdbObj").
    define_constructor(Constructor<cv::datasets::AR_hmdbObj>()).
    define_attr("id", &cv::datasets::AR_hmdbObj::id).
    define_attr("name", &cv::datasets::AR_hmdbObj::name).
    define_attr("video_name", &cv::datasets::AR_hmdbObj::videoName);

  Rice::Data_Type<cv::datasets::AR_hmdb> rb_cCvDatasetsARHmdb = define_class_under<cv::datasets::AR_hmdb, cv::datasets::Dataset>(rb_mCvDatasets, "ARHmdb").
    define_method<void(cv::datasets::AR_hmdb::*)(const std::string&)>("load", &cv::datasets::AR_hmdb::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::AR_hmdb>(*)()>("create", &cv::datasets::AR_hmdb::create);
}
