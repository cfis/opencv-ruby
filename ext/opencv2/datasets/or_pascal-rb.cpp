#include <opencv2/datasets/or_pascal.hpp>
#include "or_pascal-rb.hpp"

using namespace Rice;

void Init_Datasets_OrPascal()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::PascalPart> rb_cCvDatasetsPascalPart = define_class_under<cv::datasets::PascalPart, cv::datasets::Object>(rb_mCvDatasets, "PascalPart").
    define_constructor(Constructor<cv::datasets::PascalPart>()).
    define_attr("name", &cv::datasets::PascalPart::name).
    define_attr("xmin", &cv::datasets::PascalPart::xmin).
    define_attr("ymin", &cv::datasets::PascalPart::ymin).
    define_attr("xmax", &cv::datasets::PascalPart::xmax).
    define_attr("ymax", &cv::datasets::PascalPart::ymax);

  Rice::Data_Type<cv::datasets::PascalObj> rb_cCvDatasetsPascalObj = define_class_under<cv::datasets::PascalObj, cv::datasets::PascalPart>(rb_mCvDatasets, "PascalObj").
    define_constructor(Constructor<cv::datasets::PascalObj>()).
    define_attr("pose", &cv::datasets::PascalObj::pose).
    define_attr("truncated", &cv::datasets::PascalObj::truncated).
    define_attr("difficult", &cv::datasets::PascalObj::difficult).
    define_attr("occluded", &cv::datasets::PascalObj::occluded).
    define_attr("parts", &cv::datasets::PascalObj::parts);

  Rice::Data_Type<cv::datasets::OR_pascalObj> rb_cCvDatasetsORPascalObj = define_class_under<cv::datasets::OR_pascalObj, cv::datasets::Object>(rb_mCvDatasets, "ORPascalObj").
    define_constructor(Constructor<cv::datasets::OR_pascalObj>()).
    define_attr("filename", &cv::datasets::OR_pascalObj::filename).
    define_attr("width", &cv::datasets::OR_pascalObj::width).
    define_attr("height", &cv::datasets::OR_pascalObj::height).
    define_attr("depth", &cv::datasets::OR_pascalObj::depth).
    define_attr("objects", &cv::datasets::OR_pascalObj::objects);

  Rice::Data_Type<cv::datasets::OR_pascal> rb_cCvDatasetsORPascal = define_class_under<cv::datasets::OR_pascal, cv::datasets::Dataset>(rb_mCvDatasets, "ORPascal").
    define_method<void(cv::datasets::OR_pascal::*)(const std::string&)>("load", &cv::datasets::OR_pascal::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::OR_pascal>(*)()>("create", &cv::datasets::OR_pascal::create);
}
