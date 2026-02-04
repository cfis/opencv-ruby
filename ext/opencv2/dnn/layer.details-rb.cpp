#include <opencv2/dnn/layer.details.hpp>
#include "layer.details-rb.hpp"

using namespace Rice;

void Init_Dnn_LayerDetails()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Module rb_mCvDnnDnn4V20241223 = define_module_under(rb_mCvDnn, "Dnn4V20241223");

  Module rb_mCvDnnDnn4V20241223Details = define_module_under(rb_mCvDnnDnn4V20241223, "Details");

  Rice::Data_Type<cv::dnn::dnn4_v20241223::details::_LayerStaticRegisterer> rb_cCvDnnDnn4V20241223DetailsLayerStaticRegisterer = define_class_under<cv::dnn::dnn4_v20241223::details::_LayerStaticRegisterer>(rb_mCvDnnDnn4V20241223Details, "LayerStaticRegisterer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::details::_LayerStaticRegisterer, const cv::String&, cv::dnn::dnn4_v20241223::LayerFactory::Constructor>(),
      Arg("layer_type"), Arg("layer_constructor"));
}