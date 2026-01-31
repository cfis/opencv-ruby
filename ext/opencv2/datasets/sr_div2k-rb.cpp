#include <opencv2/datasets/sr_div2k.hpp>
#include "sr_div2k-rb.hpp"

using namespace Rice;

void Init_Datasets_SrDiv2k()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::SR_div2kObj> rb_cCvDatasetsSRDiv2kObj = define_class_under<cv::datasets::SR_div2kObj, cv::datasets::Object>(rb_mCvDatasets, "SRDiv2kObj").
    define_constructor(Constructor<cv::datasets::SR_div2kObj>()).
    define_attr("image_name", &cv::datasets::SR_div2kObj::imageName);

  Rice::Data_Type<cv::datasets::SR_div2k> rb_cCvDatasetsSRDiv2k = define_class_under<cv::datasets::SR_div2k, cv::datasets::Dataset>(rb_mCvDatasets, "SRDiv2k").
    define_method<void(cv::datasets::SR_div2k::*)(const std::string&)>("load", &cv::datasets::SR_div2k::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::SR_div2k>(*)()>("create", &cv::datasets::SR_div2k::create);
}