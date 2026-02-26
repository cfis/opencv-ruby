#include <opencv2/dnn/layer.hpp>
#include "layer-rb.hpp"

using namespace Rice;

void Init_Dnn_Layer()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");


  Rice::Data_Type<cv::dnn::LayerFactory> rb_cCvDnnLayerFactory = define_class_under<cv::dnn::LayerFactory>(rb_mCvDnn, "LayerFactory").
    define_singleton_function<void(*)(const cv::String&, cv::dnn::LayerFactory::Constructor)>("register_layer", &cv::dnn::LayerFactory::registerLayer,
      Arg("type"), Arg("constructor")).
    define_singleton_function<void(*)(const cv::String&)>("unregister_layer", &cv::dnn::LayerFactory::unregisterLayer,
      Arg("type")).
    define_singleton_function<bool(*)(const std::string&)>("layer_registered?", &cv::dnn::LayerFactory::isLayerRegistered,
      Arg("type")).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::String&, cv::dnn::LayerParams&)>("create_layer_instance", &cv::dnn::LayerFactory::createLayerInstance,
      Arg("type"), Arg("params"));
}
