#include <opencv2/datasets/ir_affine.hpp>
#include "ir_affine-rb.hpp"

using namespace Rice;

void Init_Datasets_IrAffine()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::IR_affineObj> rb_cCvDatasetsIRAffineObj = define_class_under<cv::datasets::IR_affineObj, cv::datasets::Object>(rb_mCvDatasets, "IRAffineObj").
    define_constructor(Constructor<cv::datasets::IR_affineObj>()).
    define_attr("image_name", &cv::datasets::IR_affineObj::imageName).
    define_attr("mat", &cv::datasets::IR_affineObj::mat);

  Rice::Data_Type<cv::datasets::IR_affine> rb_cCvDatasetsIRAffine = define_class_under<cv::datasets::IR_affine, cv::datasets::Dataset>(rb_mCvDatasets, "IRAffine").
    define_method<void(cv::datasets::IR_affine::*)(const std::string&)>("load", &cv::datasets::IR_affine::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::IR_affine>(*)()>("create", &cv::datasets::IR_affine::create);
}
