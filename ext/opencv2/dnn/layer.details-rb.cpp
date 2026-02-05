#include <opencv2/dnn/layer.details.hpp>
#include "layer.details-rb.hpp"

using namespace Rice;

void Init_Dnn_LayerDetails()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");


  Module rb_mCvDnnDetails = define_module_under(rb_mCvDnn, "Details");

  Rice::Data_Type<cv::dnn::details::_LayerStaticRegisterer> rb_cCvDnnDetailsLayerStaticRegisterer = define_class_under<cv::dnn::details::_LayerStaticRegisterer>(rb_mCvDnnDetails, "LayerStaticRegisterer").
    define_constructor(Constructor<cv::dnn::details::_LayerStaticRegisterer, const cv::String&, cv::dnn::LayerFactory::Constructor>(),
      Arg("layer_type"), Arg("layer_constructor"));
}