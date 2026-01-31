#include <opencv2/datasets/pd_inria.hpp>
#include "pd_inria-rb.hpp"

using namespace Rice;

void Init_Datasets_PdInria()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Enum<cv::datasets::sampleType> rb_cCvDatasetsSampleType = define_enum_under<cv::datasets::sampleType>("SampleType", rb_mCvDatasets).
    define_value("POS", cv::datasets::sampleType::POS).
    define_value("NEG", cv::datasets::sampleType::NEG);

  Rice::Data_Type<cv::datasets::PD_inriaObj> rb_cCvDatasetsPDInriaObj = define_class_under<cv::datasets::PD_inriaObj, cv::datasets::Object>(rb_mCvDatasets, "PDInriaObj").
    define_constructor(Constructor<cv::datasets::PD_inriaObj>()).
    define_attr("filename", &cv::datasets::PD_inriaObj::filename).
    define_attr("s_type", &cv::datasets::PD_inriaObj::sType).
    define_attr("width", &cv::datasets::PD_inriaObj::width).
    define_attr("height", &cv::datasets::PD_inriaObj::height).
    define_attr("depth", &cv::datasets::PD_inriaObj::depth).
    define_attr("bndboxes", &cv::datasets::PD_inriaObj::bndboxes);

  Rice::Data_Type<cv::datasets::PD_inria> rb_cCvDatasetsPDInria = define_class_under<cv::datasets::PD_inria, cv::datasets::Dataset>(rb_mCvDatasets, "PDInria").
    define_method<void(cv::datasets::PD_inria::*)(const std::string&)>("load", &cv::datasets::PD_inria::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::PD_inria>(*)()>("create", &cv::datasets::PD_inria::create);
}