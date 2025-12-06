#include <opencv2/dnn/layer.hpp>
#include "layer-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDnnLayerFactory;

void Init_Layer()
{
  Module rb_mCv = define_module("Cv");
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  
  rb_cCvDnnLayerFactory = define_class_under<cv::dnn::dnn4_v20241223::LayerFactory>(rb_mCvDnn, "LayerFactory").
    define_singleton_function("register_layer", &cv::dnn::dnn4_v20241223::LayerFactory::registerLayer,
      Arg("type"), Arg("constructor")).
    define_singleton_function("unregister_layer", &cv::dnn::dnn4_v20241223::LayerFactory::unregisterLayer,
      Arg("type")).
    define_singleton_function("", &cv::dnn::dnn4_v20241223::LayerFactory::isLayerRegistered,
      Arg("type")).
    define_singleton_function("create_layer_instance", &cv::dnn::dnn4_v20241223::LayerFactory::createLayerInstance,
      Arg("type"), Arg("params"));
}