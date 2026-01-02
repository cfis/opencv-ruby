#include <opencv2/dnn/layer.hpp>
#include "layer-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDnnLayerFactory;

void Init_Layer()
{
  Module rb_mCv = define_module("Cv");
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  
  rb_cCvDnnLayerFactory = define_class_under<cv::dnn::LayerFactory>(rb_mCvDnn, "LayerFactory").
    define_singleton_function("register_layer", &cv::dnn::LayerFactory::registerLayer,
      Arg("type"), Arg("constructor")).
    define_singleton_function("unregister_layer", &cv::dnn::LayerFactory::unregisterLayer,
      Arg("type")).
    define_singleton_function("is_layer_registered", &cv::dnn::LayerFactory::isLayerRegistered,
      Arg("type")).
    define_singleton_function("create_layer_instance", &cv::dnn::LayerFactory::createLayerInstance,
      Arg("type"), Arg("params"));
}