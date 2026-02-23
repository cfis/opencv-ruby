#include <opencv2/datasets/sr_bsds.hpp>
#include "sr_bsds-rb.hpp"

using namespace Rice;

void Init_Datasets_SrBsds()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::SR_bsdsObj> rb_cCvDatasetsSRBsdsObj = define_class_under<cv::datasets::SR_bsdsObj, cv::datasets::Object>(rb_mCvDatasets, "SRBsdsObj").
    define_constructor(Constructor<cv::datasets::SR_bsdsObj>()).
    define_attr("image_name", &cv::datasets::SR_bsdsObj::imageName);

  Rice::Data_Type<cv::datasets::SR_bsds> rb_cCvDatasetsSRBsds = define_class_under<cv::datasets::SR_bsds, cv::datasets::Dataset>(rb_mCvDatasets, "SRBsds").
    define_method<void(cv::datasets::SR_bsds::*)(const std::string&)>("load", &cv::datasets::SR_bsds::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::SR_bsds>(*)()>("create", &cv::datasets::SR_bsds::create);
}
