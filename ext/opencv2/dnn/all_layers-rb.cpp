#include <opencv2/dnn/all_layers.hpp>
#include "all_layers-rb.hpp"

using namespace Rice;

void Init_Dnn_AllLayers()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Module rb_mCvDnnDnn4V20241223 = define_module_under(rb_mCvDnn, "Dnn4V20241223");

  Rice::Data_Type<cv::dnn::dnn4_v20241223::BlankLayer> rb_cCvDnnDnn4V20241223BlankLayer = define_class_under<cv::dnn::dnn4_v20241223::BlankLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "BlankLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BlankLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::BlankLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ConstLayer> rb_cCvDnnDnn4V20241223ConstLayer = define_class_under<cv::dnn::dnn4_v20241223::ConstLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ConstLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ConstLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ConstLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::LSTMLayer> rb_cCvDnnDnn4V20241223LSTMLayer = define_class_under<cv::dnn::dnn4_v20241223::LSTMLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "LSTMLayer").
    define_method<void(cv::dnn::dnn4_v20241223::LSTMLayer::*)(const cv::dnn::dnn4_v20241223::MatShape&)>("set_out_shape", &cv::dnn::dnn4_v20241223::LSTMLayer::setOutShape,
      Arg("out_tail_shape") = static_cast<const cv::dnn::dnn4_v20241223::MatShape&>(cv::dnn::dnn4_v20241223::MatShape())).
    define_method<int(cv::dnn::dnn4_v20241223::LSTMLayer::*)(cv::String)>("input_name_to_index", &cv::dnn::dnn4_v20241223::LSTMLayer::inputNameToIndex,
      Arg("input_name")).
    define_method<int(cv::dnn::dnn4_v20241223::LSTMLayer::*)(const cv::String&)>("output_name_to_index", &cv::dnn::dnn4_v20241223::LSTMLayer::outputNameToIndex,
      Arg("output_name")).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::LSTMLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::LSTMLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::GRULayer> rb_cCvDnnDnn4V20241223GRULayer = define_class_under<cv::dnn::dnn4_v20241223::GRULayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "GRULayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GRULayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::GRULayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::GRULayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::RNNLayer> rb_cCvDnnDnn4V20241223RNNLayer = define_class_under<cv::dnn::dnn4_v20241223::RNNLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "RNNLayer").
    define_method<void(cv::dnn::dnn4_v20241223::RNNLayer::*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&)>("set_weights", &cv::dnn::dnn4_v20241223::RNNLayer::setWeights,
      Arg("wxh"), Arg("bh"), Arg("whh"), Arg("who"), Arg("bo")).
    define_method<void(cv::dnn::dnn4_v20241223::RNNLayer::*)(bool)>("set_produce_hidden_output", &cv::dnn::dnn4_v20241223::RNNLayer::setProduceHiddenOutput,
      Arg("produce") = static_cast<bool>(false)).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::RNNLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::RNNLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::EinsumLayer> rb_cCvDnnDnn4V20241223EinsumLayer = define_class_under<cv::dnn::dnn4_v20241223::EinsumLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "EinsumLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::EinsumLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::EinsumLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::EinsumLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::BaseConvolutionLayer> rb_cCvDnnDnn4V20241223BaseConvolutionLayer = define_class_under<cv::dnn::dnn4_v20241223::BaseConvolutionLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "BaseConvolutionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BaseConvolutionLayer>()).
    define_attr("kernel", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::kernel).
    define_attr("stride", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::stride).
    define_attr("pad", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::pad).
    define_attr("dilation", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::dilation).
    define_attr("adjust_pad", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::adjustPad).
    define_attr("adjust_pads", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::adjust_pads).
    define_attr("kernel_size", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::kernel_size).
    define_attr("strides", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::strides).
    define_attr("dilations", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::dilations).
    define_attr("pads_begin", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::pads_begin).
    define_attr("pads_end", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::pads_end).
    define_attr("pad_mode", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::padMode).
    define_attr("num_output", &cv::dnn::dnn4_v20241223::BaseConvolutionLayer::numOutput);

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ConvolutionLayer> rb_cCvDnnDnn4V20241223ConvolutionLayer = define_class_under<cv::dnn::dnn4_v20241223::ConvolutionLayer, cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(rb_mCvDnnDnn4V20241223, "ConvolutionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ConvolutionLayer>()).
    define_attr("fused_activation", &cv::dnn::dnn4_v20241223::ConvolutionLayer::fusedActivation).
    define_attr("fused_add", &cv::dnn::dnn4_v20241223::ConvolutionLayer::fusedAdd).
    define_attr("use_winograd", &cv::dnn::dnn4_v20241223::ConvolutionLayer::useWinograd).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ConvolutionLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ConvolutionLayerInt8> rb_cCvDnnDnn4V20241223ConvolutionLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::ConvolutionLayerInt8, cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(rb_mCvDnnDnn4V20241223, "ConvolutionLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ConvolutionLayerInt8>()).
    define_attr("input_zp", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::output_sc).
    define_attr("per_channel", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::per_channel).
    define_attr("use_winograd", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::useWinograd).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::DeconvolutionLayer> rb_cCvDnnDnn4V20241223DeconvolutionLayer = define_class_under<cv::dnn::dnn4_v20241223::DeconvolutionLayer, cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(rb_mCvDnnDnn4V20241223, "DeconvolutionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DeconvolutionLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::DeconvolutionLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::LRNLayer> rb_cCvDnnDnn4V20241223LRNLayer = define_class_under<cv::dnn::dnn4_v20241223::LRNLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "LRNLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::LRNLayer>()).
    define_attr("type", &cv::dnn::dnn4_v20241223::LRNLayer::type).
    define_attr("size", &cv::dnn::dnn4_v20241223::LRNLayer::size).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::LRNLayer::alpha).
    define_attr("beta", &cv::dnn::dnn4_v20241223::LRNLayer::beta).
    define_attr("bias", &cv::dnn::dnn4_v20241223::LRNLayer::bias).
    define_attr("norm_by_size", &cv::dnn::dnn4_v20241223::LRNLayer::normBySize).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::LRNLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::LRNLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ArgLayer> rb_cCvDnnDnn4V20241223ArgLayer = define_class_under<cv::dnn::dnn4_v20241223::ArgLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ArgLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ArgLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ArgLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ArgLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::GatherLayer> rb_cCvDnnDnn4V20241223GatherLayer = define_class_under<cv::dnn::dnn4_v20241223::GatherLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "GatherLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GatherLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::GatherLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::GatherLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::GatherElementsLayer> rb_cCvDnnDnn4V20241223GatherElementsLayer = define_class_under<cv::dnn::dnn4_v20241223::GatherElementsLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "GatherElementsLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GatherElementsLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::GatherElementsLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::GatherElementsLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::PoolingLayer> rb_cCvDnnDnn4V20241223PoolingLayer = define_class_under<cv::dnn::dnn4_v20241223::PoolingLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "PoolingLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PoolingLayer>()).
    define_attr("type", &cv::dnn::dnn4_v20241223::PoolingLayer::type).
    define_attr("kernel_size", &cv::dnn::dnn4_v20241223::PoolingLayer::kernel_size).
    define_attr("strides", &cv::dnn::dnn4_v20241223::PoolingLayer::strides).
    define_attr("pads_begin", &cv::dnn::dnn4_v20241223::PoolingLayer::pads_begin).
    define_attr("pads_end", &cv::dnn::dnn4_v20241223::PoolingLayer::pads_end).
    define_attr("global_pooling", &cv::dnn::dnn4_v20241223::PoolingLayer::globalPooling).
    define_attr("is_global_pooling", &cv::dnn::dnn4_v20241223::PoolingLayer::isGlobalPooling).
    define_attr("compute_max_idx", &cv::dnn::dnn4_v20241223::PoolingLayer::computeMaxIdx).
    define_attr("pad_mode", &cv::dnn::dnn4_v20241223::PoolingLayer::padMode).
    define_attr("ceil_mode", &cv::dnn::dnn4_v20241223::PoolingLayer::ceilMode).
    define_attr("ave_pool_padded_area", &cv::dnn::dnn4_v20241223::PoolingLayer::avePoolPaddedArea).
    define_attr("pooled_size", &cv::dnn::dnn4_v20241223::PoolingLayer::pooledSize).
    define_attr("spatial_scale", &cv::dnn::dnn4_v20241223::PoolingLayer::spatialScale).
    define_attr("ps_roi_out_channels", &cv::dnn::dnn4_v20241223::PoolingLayer::psRoiOutChannels).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::PoolingLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::PoolingLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::PoolingLayerInt8> rb_cCvDnnDnn4V20241223PoolingLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::PoolingLayerInt8, cv::dnn::dnn4_v20241223::PoolingLayer>(rb_mCvDnnDnn4V20241223, "PoolingLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PoolingLayerInt8>()).
    define_attr("input_zp", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::output_sc).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::PoolingLayerInt8>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ReduceLayer> rb_cCvDnnDnn4V20241223ReduceLayer = define_class_under<cv::dnn::dnn4_v20241223::ReduceLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ReduceLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReduceLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ReduceLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ReduceLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SoftmaxLayer> rb_cCvDnnDnn4V20241223SoftmaxLayer = define_class_under<cv::dnn::dnn4_v20241223::SoftmaxLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "SoftmaxLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SoftmaxLayer>()).
    define_attr("log_soft_max", &cv::dnn::dnn4_v20241223::SoftmaxLayer::logSoftMax).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SoftmaxLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SoftmaxLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SoftmaxLayerInt8> rb_cCvDnnDnn4V20241223SoftmaxLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::SoftmaxLayerInt8, cv::dnn::dnn4_v20241223::SoftmaxLayer>(rb_mCvDnnDnn4V20241223, "SoftmaxLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SoftmaxLayerInt8>()).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::SoftmaxLayerInt8::output_sc).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::SoftmaxLayerInt8::output_zp).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SoftmaxLayerInt8>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SoftmaxLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::InnerProductLayer> rb_cCvDnnDnn4V20241223InnerProductLayer = define_class_under<cv::dnn::dnn4_v20241223::InnerProductLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "InnerProductLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::InnerProductLayer>()).
    define_attr("axis", &cv::dnn::dnn4_v20241223::InnerProductLayer::axis).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::InnerProductLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::InnerProductLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::InnerProductLayerInt8> rb_cCvDnnDnn4V20241223InnerProductLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::InnerProductLayerInt8, cv::dnn::dnn4_v20241223::InnerProductLayer>(rb_mCvDnnDnn4V20241223, "InnerProductLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::InnerProductLayerInt8>()).
    define_attr("input_zp", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::output_sc).
    define_attr("per_channel", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::per_channel).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::InnerProductLayerInt8>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::MVNLayer> rb_cCvDnnDnn4V20241223MVNLayer = define_class_under<cv::dnn::dnn4_v20241223::MVNLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "MVNLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::MVNLayer>()).
    define_attr("eps", &cv::dnn::dnn4_v20241223::MVNLayer::eps).
    define_attr("norm_variance", &cv::dnn::dnn4_v20241223::MVNLayer::normVariance).
    define_attr("across_channels", &cv::dnn::dnn4_v20241223::MVNLayer::acrossChannels).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::MVNLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::MVNLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ReshapeLayer> rb_cCvDnnDnn4V20241223ReshapeLayer = define_class_under<cv::dnn::dnn4_v20241223::ReshapeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ReshapeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReshapeLayer>()).
    define_attr("new_shape_desc", &cv::dnn::dnn4_v20241223::ReshapeLayer::newShapeDesc).
    define_attr("new_shape_range", &cv::dnn::dnn4_v20241223::ReshapeLayer::newShapeRange).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ReshapeLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ReshapeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::FlattenLayer> rb_cCvDnnDnn4V20241223FlattenLayer = define_class_under<cv::dnn::dnn4_v20241223::FlattenLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "FlattenLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::FlattenLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::FlattenLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::FlattenLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::QuantizeLayer> rb_cCvDnnDnn4V20241223QuantizeLayer = define_class_under<cv::dnn::dnn4_v20241223::QuantizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "QuantizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::QuantizeLayer>()).
    define_attr("scales", &cv::dnn::dnn4_v20241223::QuantizeLayer::scales).
    define_attr("zeropoints", &cv::dnn::dnn4_v20241223::QuantizeLayer::zeropoints).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::QuantizeLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::QuantizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::DequantizeLayer> rb_cCvDnnDnn4V20241223DequantizeLayer = define_class_under<cv::dnn::dnn4_v20241223::DequantizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "DequantizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DequantizeLayer>()).
    define_attr("scales", &cv::dnn::dnn4_v20241223::DequantizeLayer::scales).
    define_attr("zeropoints", &cv::dnn::dnn4_v20241223::DequantizeLayer::zeropoints).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::DequantizeLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::DequantizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::RequantizeLayer> rb_cCvDnnDnn4V20241223RequantizeLayer = define_class_under<cv::dnn::dnn4_v20241223::RequantizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "RequantizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::RequantizeLayer>()).
    define_attr("scale", &cv::dnn::dnn4_v20241223::RequantizeLayer::scale).
    define_attr("shift", &cv::dnn::dnn4_v20241223::RequantizeLayer::shift).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::RequantizeLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::RequantizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ConcatLayer> rb_cCvDnnDnn4V20241223ConcatLayer = define_class_under<cv::dnn::dnn4_v20241223::ConcatLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ConcatLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ConcatLayer>()).
    define_attr("axis", &cv::dnn::dnn4_v20241223::ConcatLayer::axis).
    define_attr("padding", &cv::dnn::dnn4_v20241223::ConcatLayer::padding).
    define_attr("padding_value", &cv::dnn::dnn4_v20241223::ConcatLayer::paddingValue).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ConcatLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ConcatLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SplitLayer> rb_cCvDnnDnn4V20241223SplitLayer = define_class_under<cv::dnn::dnn4_v20241223::SplitLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "SplitLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SplitLayer>()).
    define_attr("outputs_count", &cv::dnn::dnn4_v20241223::SplitLayer::outputsCount).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SplitLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SplitLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SliceLayer> rb_cCvDnnDnn4V20241223SliceLayer = define_class_under<cv::dnn::dnn4_v20241223::SliceLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "SliceLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SliceLayer>()).
    define_attr("slice_ranges", &cv::dnn::dnn4_v20241223::SliceLayer::sliceRanges).
    define_attr("slice_steps", &cv::dnn::dnn4_v20241223::SliceLayer::sliceSteps).
    define_attr("axis", &cv::dnn::dnn4_v20241223::SliceLayer::axis).
    define_attr("num_split", &cv::dnn::dnn4_v20241223::SliceLayer::num_split).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SliceLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SliceLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::PermuteLayer> rb_cCvDnnDnn4V20241223PermuteLayer = define_class_under<cv::dnn::dnn4_v20241223::PermuteLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "PermuteLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PermuteLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::PermuteLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::PermuteLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ShuffleChannelLayer> rb_cCvDnnDnn4V20241223ShuffleChannelLayer = define_class_under<cv::dnn::dnn4_v20241223::ShuffleChannelLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ShuffleChannelLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ShuffleChannelLayer>()).
    define_attr("group", &cv::dnn::dnn4_v20241223::ShuffleChannelLayer::group).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ShuffleChannelLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::PaddingLayer> rb_cCvDnnDnn4V20241223PaddingLayer = define_class_under<cv::dnn::dnn4_v20241223::PaddingLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "PaddingLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PaddingLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::PaddingLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::PaddingLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ActivationLayer> rb_cCvDnnDnn4V20241223ActivationLayer = define_class_under<cv::dnn::dnn4_v20241223::ActivationLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ActivationLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ActivationLayer>()).
    define_method<void(cv::dnn::dnn4_v20241223::ActivationLayer::*)(const float*, float*, int, size_t, int, int) const>("forward_slice", &cv::dnn::dnn4_v20241223::ActivationLayer::forwardSlice,
      ArgBuffer("src"), ArgBuffer("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1")).
    define_method<void(cv::dnn::dnn4_v20241223::ActivationLayer::*)(const int*, const int*, int*, int, size_t, int, int) const>("forward_slice", &cv::dnn::dnn4_v20241223::ActivationLayer::forwardSlice,
      ArgBuffer("src"), ArgBuffer("lut"), ArgBuffer("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1")).
    define_method<void(cv::dnn::dnn4_v20241223::ActivationLayer::*)(const int8_t*, const int8_t*, int8_t*, int, size_t, int, int) const>("forward_slice", &cv::dnn::dnn4_v20241223::ActivationLayer::forwardSlice,
      ArgBuffer("src"), ArgBuffer("lut"), ArgBuffer("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ReLULayer> rb_cCvDnnDnn4V20241223ReLULayer = define_class_under<cv::dnn::dnn4_v20241223::ReLULayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ReLULayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReLULayer>()).
    define_attr("negative_slope", &cv::dnn::dnn4_v20241223::ReLULayer::negativeSlope).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ReLULayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ReLULayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ReLU6Layer> rb_cCvDnnDnn4V20241223ReLU6Layer = define_class_under<cv::dnn::dnn4_v20241223::ReLU6Layer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ReLU6Layer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReLU6Layer>()).
    define_attr("min_value", &cv::dnn::dnn4_v20241223::ReLU6Layer::minValue).
    define_attr("max_value", &cv::dnn::dnn4_v20241223::ReLU6Layer::maxValue).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ReLU6Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ReLU6Layer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ChannelsPReLULayer> rb_cCvDnnDnn4V20241223ChannelsPReLULayer = define_class_under<cv::dnn::dnn4_v20241223::ChannelsPReLULayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ChannelsPReLULayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ChannelsPReLULayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ChannelsPReLULayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ELULayer> rb_cCvDnnDnn4V20241223ELULayer = define_class_under<cv::dnn::dnn4_v20241223::ELULayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ELULayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ELULayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::ELULayer::alpha).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ELULayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ELULayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::TanHLayer> rb_cCvDnnDnn4V20241223TanHLayer = define_class_under<cv::dnn::dnn4_v20241223::TanHLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "TanHLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TanHLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::TanHLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::TanHLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SwishLayer> rb_cCvDnnDnn4V20241223SwishLayer = define_class_under<cv::dnn::dnn4_v20241223::SwishLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SwishLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SwishLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SwishLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SwishLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::MishLayer> rb_cCvDnnDnn4V20241223MishLayer = define_class_under<cv::dnn::dnn4_v20241223::MishLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "MishLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::MishLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::MishLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::MishLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SigmoidLayer> rb_cCvDnnDnn4V20241223SigmoidLayer = define_class_under<cv::dnn::dnn4_v20241223::SigmoidLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SigmoidLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SigmoidLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SigmoidLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SigmoidLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::BNLLLayer> rb_cCvDnnDnn4V20241223BNLLLayer = define_class_under<cv::dnn::dnn4_v20241223::BNLLLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "BNLLLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BNLLLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::BNLLLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::BNLLLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AbsLayer> rb_cCvDnnDnn4V20241223AbsLayer = define_class_under<cv::dnn::dnn4_v20241223::AbsLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "AbsLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AbsLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AbsLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AbsLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::PowerLayer> rb_cCvDnnDnn4V20241223PowerLayer = define_class_under<cv::dnn::dnn4_v20241223::PowerLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "PowerLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PowerLayer>()).
    define_attr("power", &cv::dnn::dnn4_v20241223::PowerLayer::power).
    define_attr("scale", &cv::dnn::dnn4_v20241223::PowerLayer::scale).
    define_attr("shift", &cv::dnn::dnn4_v20241223::PowerLayer::shift).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::PowerLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::PowerLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ExpLayer> rb_cCvDnnDnn4V20241223ExpLayer = define_class_under<cv::dnn::dnn4_v20241223::ExpLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ExpLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ExpLayer>()).
    define_attr("base", &cv::dnn::dnn4_v20241223::ExpLayer::base).
    define_attr("scale", &cv::dnn::dnn4_v20241223::ExpLayer::scale).
    define_attr("shift", &cv::dnn::dnn4_v20241223::ExpLayer::shift).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ExpLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ExpLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CeilLayer> rb_cCvDnnDnn4V20241223CeilLayer = define_class_under<cv::dnn::dnn4_v20241223::CeilLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "CeilLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CeilLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::CeilLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CeilLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::FloorLayer> rb_cCvDnnDnn4V20241223FloorLayer = define_class_under<cv::dnn::dnn4_v20241223::FloorLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "FloorLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::FloorLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::FloorLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::FloorLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::LogLayer> rb_cCvDnnDnn4V20241223LogLayer = define_class_under<cv::dnn::dnn4_v20241223::LogLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "LogLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::LogLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::LogLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::LogLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::RoundLayer> rb_cCvDnnDnn4V20241223RoundLayer = define_class_under<cv::dnn::dnn4_v20241223::RoundLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "RoundLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::RoundLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::RoundLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::RoundLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SqrtLayer> rb_cCvDnnDnn4V20241223SqrtLayer = define_class_under<cv::dnn::dnn4_v20241223::SqrtLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SqrtLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SqrtLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SqrtLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SqrtLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::NotLayer> rb_cCvDnnDnn4V20241223NotLayer = define_class_under<cv::dnn::dnn4_v20241223::NotLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "NotLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::NotLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::NotLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::NotLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AcosLayer> rb_cCvDnnDnn4V20241223AcosLayer = define_class_under<cv::dnn::dnn4_v20241223::AcosLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "AcosLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AcosLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AcosLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AcosLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AcoshLayer> rb_cCvDnnDnn4V20241223AcoshLayer = define_class_under<cv::dnn::dnn4_v20241223::AcoshLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "AcoshLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AcoshLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AcoshLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AcoshLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AsinLayer> rb_cCvDnnDnn4V20241223AsinLayer = define_class_under<cv::dnn::dnn4_v20241223::AsinLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "AsinLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AsinLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AsinLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AsinLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AsinhLayer> rb_cCvDnnDnn4V20241223AsinhLayer = define_class_under<cv::dnn::dnn4_v20241223::AsinhLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "AsinhLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AsinhLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AsinhLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AsinhLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AtanLayer> rb_cCvDnnDnn4V20241223AtanLayer = define_class_under<cv::dnn::dnn4_v20241223::AtanLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "AtanLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AtanLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AtanLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AtanLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AtanhLayer> rb_cCvDnnDnn4V20241223AtanhLayer = define_class_under<cv::dnn::dnn4_v20241223::AtanhLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "AtanhLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AtanhLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AtanhLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AtanhLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CosLayer> rb_cCvDnnDnn4V20241223CosLayer = define_class_under<cv::dnn::dnn4_v20241223::CosLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "CosLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CosLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::CosLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CosLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CoshLayer> rb_cCvDnnDnn4V20241223CoshLayer = define_class_under<cv::dnn::dnn4_v20241223::CoshLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "CoshLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CoshLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::CoshLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CoshLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ErfLayer> rb_cCvDnnDnn4V20241223ErfLayer = define_class_under<cv::dnn::dnn4_v20241223::ErfLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ErfLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ErfLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ErfLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ErfLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::HardSwishLayer> rb_cCvDnnDnn4V20241223HardSwishLayer = define_class_under<cv::dnn::dnn4_v20241223::HardSwishLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "HardSwishLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::HardSwishLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::HardSwishLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::HardSwishLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SinLayer> rb_cCvDnnDnn4V20241223SinLayer = define_class_under<cv::dnn::dnn4_v20241223::SinLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SinLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SinLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SinLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SinLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SinhLayer> rb_cCvDnnDnn4V20241223SinhLayer = define_class_under<cv::dnn::dnn4_v20241223::SinhLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SinhLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SinhLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SinhLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SinhLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SoftplusLayer> rb_cCvDnnDnn4V20241223SoftplusLayer = define_class_under<cv::dnn::dnn4_v20241223::SoftplusLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SoftplusLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SoftplusLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SoftplusLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SoftplusLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SoftsignLayer> rb_cCvDnnDnn4V20241223SoftsignLayer = define_class_under<cv::dnn::dnn4_v20241223::SoftsignLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SoftsignLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SoftsignLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SoftsignLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SoftsignLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::TanLayer> rb_cCvDnnDnn4V20241223TanLayer = define_class_under<cv::dnn::dnn4_v20241223::TanLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "TanLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TanLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::TanLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::TanLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CeluLayer> rb_cCvDnnDnn4V20241223CeluLayer = define_class_under<cv::dnn::dnn4_v20241223::CeluLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "CeluLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CeluLayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::CeluLayer::alpha).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::CeluLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CeluLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::HardSigmoidLayer> rb_cCvDnnDnn4V20241223HardSigmoidLayer = define_class_under<cv::dnn::dnn4_v20241223::HardSigmoidLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "HardSigmoidLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::HardSigmoidLayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::HardSigmoidLayer::alpha).
    define_attr("beta", &cv::dnn::dnn4_v20241223::HardSigmoidLayer::beta).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::HardSigmoidLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::HardSigmoidLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SeluLayer> rb_cCvDnnDnn4V20241223SeluLayer = define_class_under<cv::dnn::dnn4_v20241223::SeluLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SeluLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SeluLayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::SeluLayer::alpha).
    define_attr("gamma", &cv::dnn::dnn4_v20241223::SeluLayer::gamma).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SeluLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SeluLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::GeluLayer> rb_cCvDnnDnn4V20241223GeluLayer = define_class_under<cv::dnn::dnn4_v20241223::GeluLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "GeluLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GeluLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::GeluLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::GeluLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::GeluApproximationLayer> rb_cCvDnnDnn4V20241223GeluApproximationLayer = define_class_under<cv::dnn::dnn4_v20241223::GeluApproximationLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "GeluApproximationLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GeluApproximationLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::GeluApproximationLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::GeluApproximationLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ThresholdedReluLayer> rb_cCvDnnDnn4V20241223ThresholdedReluLayer = define_class_under<cv::dnn::dnn4_v20241223::ThresholdedReluLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ThresholdedReluLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ThresholdedReluLayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::ThresholdedReluLayer::alpha).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ThresholdedReluLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ThresholdedReluLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ActivationLayerInt8> rb_cCvDnnDnn4V20241223ActivationLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::ActivationLayerInt8, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ActivationLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ActivationLayerInt8>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ActivationLayerInt8>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ActivationLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SignLayer> rb_cCvDnnDnn4V20241223SignLayer = define_class_under<cv::dnn::dnn4_v20241223::SignLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "SignLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SignLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SignLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SignLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ShrinkLayer> rb_cCvDnnDnn4V20241223ShrinkLayer = define_class_under<cv::dnn::dnn4_v20241223::ShrinkLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ShrinkLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ShrinkLayer>()).
    define_attr("bias", &cv::dnn::dnn4_v20241223::ShrinkLayer::bias).
    define_attr("lambd", &cv::dnn::dnn4_v20241223::ShrinkLayer::lambd).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ShrinkLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ShrinkLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ReciprocalLayer> rb_cCvDnnDnn4V20241223ReciprocalLayer = define_class_under<cv::dnn::dnn4_v20241223::ReciprocalLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ReciprocalLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReciprocalLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ReciprocalLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ReciprocalLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CropLayer> rb_cCvDnnDnn4V20241223CropLayer = define_class_under<cv::dnn::dnn4_v20241223::CropLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "CropLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CropLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CropLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::EltwiseLayer> rb_cCvDnnDnn4V20241223EltwiseLayer = define_class_under<cv::dnn::dnn4_v20241223::EltwiseLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "EltwiseLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::EltwiseLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::EltwiseLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::EltwiseLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::EltwiseLayerInt8> rb_cCvDnnDnn4V20241223EltwiseLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::EltwiseLayerInt8, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "EltwiseLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::EltwiseLayerInt8>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::EltwiseLayerInt8>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::EltwiseLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::NaryEltwiseLayer> rb_cCvDnnDnn4V20241223NaryEltwiseLayer = define_class_under<cv::dnn::dnn4_v20241223::NaryEltwiseLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "NaryEltwiseLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::NaryEltwiseLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::NaryEltwiseLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::NaryEltwiseLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::BatchNormLayer> rb_cCvDnnDnn4V20241223BatchNormLayer = define_class_under<cv::dnn::dnn4_v20241223::BatchNormLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "BatchNormLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BatchNormLayer>()).
    define_attr("has_weights", &cv::dnn::dnn4_v20241223::BatchNormLayer::hasWeights).
    define_attr("has_bias", &cv::dnn::dnn4_v20241223::BatchNormLayer::hasBias).
    define_attr("epsilon", &cv::dnn::dnn4_v20241223::BatchNormLayer::epsilon).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::BatchNormLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::BatchNormLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::BatchNormLayerInt8> rb_cCvDnnDnn4V20241223BatchNormLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::BatchNormLayerInt8, cv::dnn::dnn4_v20241223::BatchNormLayer>(rb_mCvDnnDnn4V20241223, "BatchNormLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BatchNormLayerInt8>()).
    define_attr("input_sc", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::output_sc).
    define_attr("input_zp", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::output_zp).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::BatchNormLayerInt8>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::MaxUnpoolLayer> rb_cCvDnnDnn4V20241223MaxUnpoolLayer = define_class_under<cv::dnn::dnn4_v20241223::MaxUnpoolLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "MaxUnpoolLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::MaxUnpoolLayer>()).
    define_attr("pool_kernel", &cv::dnn::dnn4_v20241223::MaxUnpoolLayer::poolKernel).
    define_attr("pool_pad", &cv::dnn::dnn4_v20241223::MaxUnpoolLayer::poolPad).
    define_attr("pool_stride", &cv::dnn::dnn4_v20241223::MaxUnpoolLayer::poolStride).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::MaxUnpoolLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::MaxUnpoolLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ScaleLayer> rb_cCvDnnDnn4V20241223ScaleLayer = define_class_under<cv::dnn::dnn4_v20241223::ScaleLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ScaleLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ScaleLayer>()).
    define_attr("has_bias", &cv::dnn::dnn4_v20241223::ScaleLayer::hasBias).
    define_attr("axis", &cv::dnn::dnn4_v20241223::ScaleLayer::axis).
    define_attr("mode", &cv::dnn::dnn4_v20241223::ScaleLayer::mode).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ScaleLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ScaleLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ScaleLayerInt8> rb_cCvDnnDnn4V20241223ScaleLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::ScaleLayerInt8, cv::dnn::dnn4_v20241223::ScaleLayer>(rb_mCvDnnDnn4V20241223, "ScaleLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ScaleLayerInt8>()).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::ScaleLayerInt8::output_sc).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::ScaleLayerInt8::output_zp).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ScaleLayerInt8>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ScaleLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ShiftLayer> rb_cCvDnnDnn4V20241223ShiftLayer = define_class_under<cv::dnn::dnn4_v20241223::ShiftLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ShiftLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ShiftLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ShiftLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ShiftLayerInt8> rb_cCvDnnDnn4V20241223ShiftLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::ShiftLayerInt8, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ShiftLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ShiftLayerInt8>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ShiftLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CompareLayer> rb_cCvDnnDnn4V20241223CompareLayer = define_class_under<cv::dnn::dnn4_v20241223::CompareLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "CompareLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CompareLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CompareLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::DataAugmentationLayer> rb_cCvDnnDnn4V20241223DataAugmentationLayer = define_class_under<cv::dnn::dnn4_v20241223::DataAugmentationLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "DataAugmentationLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DataAugmentationLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::DataAugmentationLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::DataAugmentationLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CorrelationLayer> rb_cCvDnnDnn4V20241223CorrelationLayer = define_class_under<cv::dnn::dnn4_v20241223::CorrelationLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "CorrelationLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CorrelationLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::CorrelationLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CorrelationLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AccumLayer> rb_cCvDnnDnn4V20241223AccumLayer = define_class_under<cv::dnn::dnn4_v20241223::AccumLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "AccumLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AccumLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AccumLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AccumLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::FlowWarpLayer> rb_cCvDnnDnn4V20241223FlowWarpLayer = define_class_under<cv::dnn::dnn4_v20241223::FlowWarpLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "FlowWarpLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::FlowWarpLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::FlowWarpLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::FlowWarpLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::PriorBoxLayer> rb_cCvDnnDnn4V20241223PriorBoxLayer = define_class_under<cv::dnn::dnn4_v20241223::PriorBoxLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "PriorBoxLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PriorBoxLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::PriorBoxLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::PriorBoxLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ReorgLayer> rb_cCvDnnDnn4V20241223ReorgLayer = define_class_under<cv::dnn::dnn4_v20241223::ReorgLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ReorgLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReorgLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ReorgLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ReorgLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::RegionLayer> rb_cCvDnnDnn4V20241223RegionLayer = define_class_under<cv::dnn::dnn4_v20241223::RegionLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "RegionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::RegionLayer>()).
    define_attr("nms_threshold", &cv::dnn::dnn4_v20241223::RegionLayer::nmsThreshold).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::RegionLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::RegionLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::DetectionOutputLayer> rb_cCvDnnDnn4V20241223DetectionOutputLayer = define_class_under<cv::dnn::dnn4_v20241223::DetectionOutputLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "DetectionOutputLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DetectionOutputLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::DetectionOutputLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::DetectionOutputLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::NormalizeBBoxLayer> rb_cCvDnnDnn4V20241223NormalizeBBoxLayer = define_class_under<cv::dnn::dnn4_v20241223::NormalizeBBoxLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "NormalizeBBoxLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::NormalizeBBoxLayer>()).
    define_attr("pnorm", &cv::dnn::dnn4_v20241223::NormalizeBBoxLayer::pnorm).
    define_attr("epsilon", &cv::dnn::dnn4_v20241223::NormalizeBBoxLayer::epsilon).
    define_attr("across_spatial", &cv::dnn::dnn4_v20241223::NormalizeBBoxLayer::acrossSpatial).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::NormalizeBBoxLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::NormalizeBBoxLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ResizeLayer> rb_cCvDnnDnn4V20241223ResizeLayer = define_class_under<cv::dnn::dnn4_v20241223::ResizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ResizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ResizeLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ResizeLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ResizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::InterpLayer> rb_cCvDnnDnn4V20241223InterpLayer = define_class_under<cv::dnn::dnn4_v20241223::InterpLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "InterpLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::InterpLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::InterpLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ProposalLayer> rb_cCvDnnDnn4V20241223ProposalLayer = define_class_under<cv::dnn::dnn4_v20241223::ProposalLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ProposalLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ProposalLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ProposalLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ProposalLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CropAndResizeLayer> rb_cCvDnnDnn4V20241223CropAndResizeLayer = define_class_under<cv::dnn::dnn4_v20241223::CropAndResizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "CropAndResizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CropAndResizeLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CropAndResizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::CumSumLayer> rb_cCvDnnDnn4V20241223CumSumLayer = define_class_under<cv::dnn::dnn4_v20241223::CumSumLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "CumSumLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CumSumLayer>()).
    define_attr("exclusive", &cv::dnn::dnn4_v20241223::CumSumLayer::exclusive).
    define_attr("reverse", &cv::dnn::dnn4_v20241223::CumSumLayer::reverse).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::CumSumLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::CumSumLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ScatterLayer> rb_cCvDnnDnn4V20241223ScatterLayer = define_class_under<cv::dnn::dnn4_v20241223::ScatterLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ScatterLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ScatterLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ScatterLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ScatterLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ScatterNDLayer> rb_cCvDnnDnn4V20241223ScatterNDLayer = define_class_under<cv::dnn::dnn4_v20241223::ScatterNDLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ScatterNDLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ScatterNDLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ScatterNDLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ScatterNDLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::TileLayer> rb_cCvDnnDnn4V20241223TileLayer = define_class_under<cv::dnn::dnn4_v20241223::TileLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "TileLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TileLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::TileLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::TileLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::LayerNormLayer> rb_cCvDnnDnn4V20241223LayerNormLayer = define_class_under<cv::dnn::dnn4_v20241223::LayerNormLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "LayerNormLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::LayerNormLayer>()).
    define_attr("has_bias", &cv::dnn::dnn4_v20241223::LayerNormLayer::hasBias).
    define_attr("axis", &cv::dnn::dnn4_v20241223::LayerNormLayer::axis).
    define_attr("epsilon", &cv::dnn::dnn4_v20241223::LayerNormLayer::epsilon).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::LayerNormLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::LayerNormLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::GemmLayer> rb_cCvDnnDnn4V20241223GemmLayer = define_class_under<cv::dnn::dnn4_v20241223::GemmLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "GemmLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GemmLayer>()).
    define_attr("trans_a", &cv::dnn::dnn4_v20241223::GemmLayer::trans_a).
    define_attr("trans_b", &cv::dnn::dnn4_v20241223::GemmLayer::trans_b).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::GemmLayer::alpha).
    define_attr("beta", &cv::dnn::dnn4_v20241223::GemmLayer::beta).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::GemmLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::GemmLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::MatMulLayer> rb_cCvDnnDnn4V20241223MatMulLayer = define_class_under<cv::dnn::dnn4_v20241223::MatMulLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "MatMulLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::MatMulLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::MatMulLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::MatMulLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ExpandLayer> rb_cCvDnnDnn4V20241223ExpandLayer = define_class_under<cv::dnn::dnn4_v20241223::ExpandLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "ExpandLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ExpandLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::ExpandLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::ExpandLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::InstanceNormLayer> rb_cCvDnnDnn4V20241223InstanceNormLayer = define_class_under<cv::dnn::dnn4_v20241223::InstanceNormLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "InstanceNormLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::InstanceNormLayer>()).
    define_attr("epsilon", &cv::dnn::dnn4_v20241223::InstanceNormLayer::epsilon).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::InstanceNormLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::InstanceNormLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::AttentionLayer> rb_cCvDnnDnn4V20241223AttentionLayer = define_class_under<cv::dnn::dnn4_v20241223::AttentionLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "AttentionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AttentionLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::AttentionLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::AttentionLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::GroupNormLayer> rb_cCvDnnDnn4V20241223GroupNormLayer = define_class_under<cv::dnn::dnn4_v20241223::GroupNormLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "GroupNormLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GroupNormLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::GroupNormLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::GroupNormLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::DepthToSpaceLayer> rb_cCvDnnDnn4V20241223DepthToSpaceLayer = define_class_under<cv::dnn::dnn4_v20241223::DepthToSpaceLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "DepthToSpaceLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DepthToSpaceLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::DepthToSpaceLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::DepthToSpaceLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SpaceToDepthLayer> rb_cCvDnnDnn4V20241223SpaceToDepthLayer = define_class_under<cv::dnn::dnn4_v20241223::SpaceToDepthLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "SpaceToDepthLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SpaceToDepthLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::SpaceToDepthLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::SpaceToDepthLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::TopKLayer> rb_cCvDnnDnn4V20241223TopKLayer = define_class_under<cv::dnn::dnn4_v20241223::TopKLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnnDnn4V20241223, "TopKLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TopKLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::dnn4_v20241223::TopKLayer>(*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("create", &cv::dnn::dnn4_v20241223::TopKLayer::create,
      Arg("params"));
}