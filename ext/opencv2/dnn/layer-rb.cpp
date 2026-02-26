#include <opencv2/dnn/layer.hpp>
#include "layer-rb.hpp"

using namespace Rice;

void Init_Dnn_Layer()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Module rb_mCvDnnDnn4V20241223 = define_module_under(rb_mCvDnn, "Dnn4V20241223");

  Rice::Data_Type<cv::dnn::dnn4_v20241223::LayerFactory> rb_cCvDnnDnn4V20241223LayerFactory = define_class_under<cv::dnn::dnn4_v20241223::LayerFactory>(rb_mCvDnnDnn4V20241223, "LayerFactory").
    define_singleton_function<void(*)(const cv::String&, cv::dnn::dnn4_v20241223::LayerFactory::Constructor)>("register_layer", &cv::dnn::dnn4_v20241223::LayerFactory::registerLayer,
      Arg("type"), Arg("constructor")).
    define_singleton_function<void(*)(const cv::String&)>("unregister_layer", &cv::dnn::dnn4_v20241223::LayerFactory::unregisterLayer,
      Arg("type")).
    define_singleton_function<bool(*)(const std::string&)>("layer_registered?", &cv::dnn::dnn4_v20241223::LayerFactory::isLayerRegistered,
      Arg("type")).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::String&, cv::dnn::dnn4_v20241223::LayerParams&)>("create_layer_instance", &cv::dnn::dnn4_v20241223::LayerFactory::createLayerInstance,
      Arg("type"), Arg("params"));
}
