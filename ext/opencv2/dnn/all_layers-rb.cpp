#include <opencv2/dnn/all_layers.hpp>
#include "all_layers-rb.hpp"

using namespace Rice;

void Init_Dnn_AllLayers()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");


  Rice::Data_Type<cv::dnn::BlankLayer> rb_cCvDnnBlankLayer = define_class_under<cv::dnn::BlankLayer, cv::dnn::Layer>(rb_mCvDnn, "BlankLayer").
    define_constructor(Constructor<cv::dnn::BlankLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::BlankLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ConstLayer> rb_cCvDnnConstLayer = define_class_under<cv::dnn::ConstLayer, cv::dnn::Layer>(rb_mCvDnn, "ConstLayer").
    define_constructor(Constructor<cv::dnn::ConstLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ConstLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::LSTMLayer> rb_cCvDnnLSTMLayer = define_class_under<cv::dnn::LSTMLayer, cv::dnn::Layer>(rb_mCvDnn, "LSTMLayer").
    define_singleton_function<cv::Ptr<cv::dnn::LSTMLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::LSTMLayer::create,
      Arg("params")).
    define_method<void(cv::dnn::LSTMLayer::*)(const cv::dnn::MatShape&)>("set_out_shape", &cv::dnn::LSTMLayer::setOutShape,
      Arg("out_tail_shape") = static_cast<const cv::dnn::MatShape&>(cv::dnn::MatShape())).
    define_method<int(cv::dnn::LSTMLayer::*)(cv::String)>("input_name_to_index", &cv::dnn::LSTMLayer::inputNameToIndex,
      Arg("input_name")).
    define_method<int(cv::dnn::LSTMLayer::*)(const cv::String&)>("output_name_to_index", &cv::dnn::LSTMLayer::outputNameToIndex,
      Arg("output_name"));

  Rice::Data_Type<cv::dnn::GRULayer> rb_cCvDnnGRULayer = define_class_under<cv::dnn::GRULayer, cv::dnn::Layer>(rb_mCvDnn, "GRULayer").
    define_constructor(Constructor<cv::dnn::GRULayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::GRULayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::GRULayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::RNNLayer> rb_cCvDnnRNNLayer = define_class_under<cv::dnn::RNNLayer, cv::dnn::Layer>(rb_mCvDnn, "RNNLayer").
    define_singleton_function<cv::Ptr<cv::dnn::RNNLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::RNNLayer::create,
      Arg("params")).
    define_method<void(cv::dnn::RNNLayer::*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&)>("set_weights", &cv::dnn::RNNLayer::setWeights,
      Arg("wxh"), Arg("bh"), Arg("whh"), Arg("who"), Arg("bo")).
    define_method<void(cv::dnn::RNNLayer::*)(bool)>("set_produce_hidden_output", &cv::dnn::RNNLayer::setProduceHiddenOutput,
      Arg("produce") = static_cast<bool>(false));

  Rice::Data_Type<cv::dnn::EinsumLayer> rb_cCvDnnEinsumLayer = define_class_under<cv::dnn::EinsumLayer, cv::dnn::Layer>(rb_mCvDnn, "EinsumLayer").
    define_constructor(Constructor<cv::dnn::EinsumLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::EinsumLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::EinsumLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::BaseConvolutionLayer> rb_cCvDnnBaseConvolutionLayer = define_class_under<cv::dnn::BaseConvolutionLayer, cv::dnn::Layer>(rb_mCvDnn, "BaseConvolutionLayer").
    define_constructor(Constructor<cv::dnn::BaseConvolutionLayer>()).
    define_attr("kernel", &cv::dnn::BaseConvolutionLayer::kernel).
    define_attr("stride", &cv::dnn::BaseConvolutionLayer::stride).
    define_attr("pad", &cv::dnn::BaseConvolutionLayer::pad).
    define_attr("dilation", &cv::dnn::BaseConvolutionLayer::dilation).
    define_attr("adjust_pad", &cv::dnn::BaseConvolutionLayer::adjustPad).
    define_attr("adjust_pads", &cv::dnn::BaseConvolutionLayer::adjust_pads).
    define_attr("kernel_size", &cv::dnn::BaseConvolutionLayer::kernel_size).
    define_attr("strides", &cv::dnn::BaseConvolutionLayer::strides).
    define_attr("dilations", &cv::dnn::BaseConvolutionLayer::dilations).
    define_attr("pads_begin", &cv::dnn::BaseConvolutionLayer::pads_begin).
    define_attr("pads_end", &cv::dnn::BaseConvolutionLayer::pads_end).
    define_attr("pad_mode", &cv::dnn::BaseConvolutionLayer::padMode).
    define_attr("num_output", &cv::dnn::BaseConvolutionLayer::numOutput);

  Rice::Data_Type<cv::dnn::ConvolutionLayer> rb_cCvDnnConvolutionLayer = define_class_under<cv::dnn::ConvolutionLayer, cv::dnn::BaseConvolutionLayer>(rb_mCvDnn, "ConvolutionLayer").
    define_constructor(Constructor<cv::dnn::ConvolutionLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::BaseConvolutionLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ConvolutionLayer::create,
      Arg("params")).
    define_attr("fused_activation", &cv::dnn::ConvolutionLayer::fusedActivation).
    define_attr("fused_add", &cv::dnn::ConvolutionLayer::fusedAdd).
    define_attr("use_winograd", &cv::dnn::ConvolutionLayer::useWinograd);

  Rice::Data_Type<cv::dnn::ConvolutionLayerInt8> rb_cCvDnnConvolutionLayerInt8 = define_class_under<cv::dnn::ConvolutionLayerInt8, cv::dnn::BaseConvolutionLayer>(rb_mCvDnn, "ConvolutionLayerInt8").
    define_constructor(Constructor<cv::dnn::ConvolutionLayerInt8>()).
    define_attr("input_zp", &cv::dnn::ConvolutionLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::ConvolutionLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::ConvolutionLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::ConvolutionLayerInt8::output_sc).
    define_attr("per_channel", &cv::dnn::ConvolutionLayerInt8::per_channel).
    define_attr("use_winograd", &cv::dnn::ConvolutionLayerInt8::useWinograd).
    define_singleton_function<cv::Ptr<cv::dnn::BaseConvolutionLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ConvolutionLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::DeconvolutionLayer> rb_cCvDnnDeconvolutionLayer = define_class_under<cv::dnn::DeconvolutionLayer, cv::dnn::BaseConvolutionLayer>(rb_mCvDnn, "DeconvolutionLayer").
    define_constructor(Constructor<cv::dnn::DeconvolutionLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::BaseConvolutionLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::DeconvolutionLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::LRNLayer> rb_cCvDnnLRNLayer = define_class_under<cv::dnn::LRNLayer, cv::dnn::Layer>(rb_mCvDnn, "LRNLayer").
    define_constructor(Constructor<cv::dnn::LRNLayer>()).
    define_attr("type", &cv::dnn::LRNLayer::type).
    define_attr("size", &cv::dnn::LRNLayer::size).
    define_attr("alpha", &cv::dnn::LRNLayer::alpha).
    define_attr("beta", &cv::dnn::LRNLayer::beta).
    define_attr("bias", &cv::dnn::LRNLayer::bias).
    define_attr("norm_by_size", &cv::dnn::LRNLayer::normBySize).
    define_singleton_function<cv::Ptr<cv::dnn::LRNLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::LRNLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ArgLayer> rb_cCvDnnArgLayer = define_class_under<cv::dnn::ArgLayer, cv::dnn::Layer>(rb_mCvDnn, "ArgLayer").
    define_constructor(Constructor<cv::dnn::ArgLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ArgLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ArgLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::GatherLayer> rb_cCvDnnGatherLayer = define_class_under<cv::dnn::GatherLayer, cv::dnn::Layer>(rb_mCvDnn, "GatherLayer").
    define_constructor(Constructor<cv::dnn::GatherLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::GatherLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::GatherLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::GatherElementsLayer> rb_cCvDnnGatherElementsLayer = define_class_under<cv::dnn::GatherElementsLayer, cv::dnn::Layer>(rb_mCvDnn, "GatherElementsLayer").
    define_constructor(Constructor<cv::dnn::GatherElementsLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::GatherElementsLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::GatherElementsLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::PoolingLayer> rb_cCvDnnPoolingLayer = define_class_under<cv::dnn::PoolingLayer, cv::dnn::Layer>(rb_mCvDnn, "PoolingLayer").
    define_constructor(Constructor<cv::dnn::PoolingLayer>()).
    define_attr("type", &cv::dnn::PoolingLayer::type).
    define_attr("kernel_size", &cv::dnn::PoolingLayer::kernel_size).
    define_attr("strides", &cv::dnn::PoolingLayer::strides).
    define_attr("pads_begin", &cv::dnn::PoolingLayer::pads_begin).
    define_attr("pads_end", &cv::dnn::PoolingLayer::pads_end).
    define_attr("global_pooling", &cv::dnn::PoolingLayer::globalPooling).
    define_attr("is_global_pooling", &cv::dnn::PoolingLayer::isGlobalPooling).
    define_attr("compute_max_idx", &cv::dnn::PoolingLayer::computeMaxIdx).
    define_attr("pad_mode", &cv::dnn::PoolingLayer::padMode).
    define_attr("ceil_mode", &cv::dnn::PoolingLayer::ceilMode).
    define_attr("ave_pool_padded_area", &cv::dnn::PoolingLayer::avePoolPaddedArea).
    define_attr("pooled_size", &cv::dnn::PoolingLayer::pooledSize).
    define_attr("spatial_scale", &cv::dnn::PoolingLayer::spatialScale).
    define_attr("ps_roi_out_channels", &cv::dnn::PoolingLayer::psRoiOutChannels).
    define_singleton_function<cv::Ptr<cv::dnn::PoolingLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::PoolingLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::PoolingLayerInt8> rb_cCvDnnPoolingLayerInt8 = define_class_under<cv::dnn::PoolingLayerInt8, cv::dnn::PoolingLayer>(rb_mCvDnn, "PoolingLayerInt8").
    define_constructor(Constructor<cv::dnn::PoolingLayerInt8>()).
    define_attr("input_zp", &cv::dnn::PoolingLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::PoolingLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::PoolingLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::PoolingLayerInt8::output_sc).
    define_singleton_function<cv::Ptr<cv::dnn::PoolingLayerInt8>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::PoolingLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ReduceLayer> rb_cCvDnnReduceLayer = define_class_under<cv::dnn::ReduceLayer, cv::dnn::Layer>(rb_mCvDnn, "ReduceLayer").
    define_constructor(Constructor<cv::dnn::ReduceLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ReduceLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ReduceLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SoftmaxLayer> rb_cCvDnnSoftmaxLayer = define_class_under<cv::dnn::SoftmaxLayer, cv::dnn::Layer>(rb_mCvDnn, "SoftmaxLayer").
    define_constructor(Constructor<cv::dnn::SoftmaxLayer>()).
    define_attr("log_soft_max", &cv::dnn::SoftmaxLayer::logSoftMax).
    define_singleton_function<cv::Ptr<cv::dnn::SoftmaxLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SoftmaxLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SoftmaxLayerInt8> rb_cCvDnnSoftmaxLayerInt8 = define_class_under<cv::dnn::SoftmaxLayerInt8, cv::dnn::SoftmaxLayer>(rb_mCvDnn, "SoftmaxLayerInt8").
    define_constructor(Constructor<cv::dnn::SoftmaxLayerInt8>()).
    define_attr("output_sc", &cv::dnn::SoftmaxLayerInt8::output_sc).
    define_attr("output_zp", &cv::dnn::SoftmaxLayerInt8::output_zp).
    define_singleton_function<cv::Ptr<cv::dnn::SoftmaxLayerInt8>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SoftmaxLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::InnerProductLayer> rb_cCvDnnInnerProductLayer = define_class_under<cv::dnn::InnerProductLayer, cv::dnn::Layer>(rb_mCvDnn, "InnerProductLayer").
    define_constructor(Constructor<cv::dnn::InnerProductLayer>()).
    define_attr("axis", &cv::dnn::InnerProductLayer::axis).
    define_singleton_function<cv::Ptr<cv::dnn::InnerProductLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::InnerProductLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::InnerProductLayerInt8> rb_cCvDnnInnerProductLayerInt8 = define_class_under<cv::dnn::InnerProductLayerInt8, cv::dnn::InnerProductLayer>(rb_mCvDnn, "InnerProductLayerInt8").
    define_constructor(Constructor<cv::dnn::InnerProductLayerInt8>()).
    define_attr("input_zp", &cv::dnn::InnerProductLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::InnerProductLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::InnerProductLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::InnerProductLayerInt8::output_sc).
    define_attr("per_channel", &cv::dnn::InnerProductLayerInt8::per_channel).
    define_singleton_function<cv::Ptr<cv::dnn::InnerProductLayerInt8>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::InnerProductLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::MVNLayer> rb_cCvDnnMVNLayer = define_class_under<cv::dnn::MVNLayer, cv::dnn::Layer>(rb_mCvDnn, "MVNLayer").
    define_constructor(Constructor<cv::dnn::MVNLayer>()).
    define_attr("eps", &cv::dnn::MVNLayer::eps).
    define_attr("norm_variance", &cv::dnn::MVNLayer::normVariance).
    define_attr("across_channels", &cv::dnn::MVNLayer::acrossChannels).
    define_singleton_function<cv::Ptr<cv::dnn::MVNLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::MVNLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ReshapeLayer> rb_cCvDnnReshapeLayer = define_class_under<cv::dnn::ReshapeLayer, cv::dnn::Layer>(rb_mCvDnn, "ReshapeLayer").
    define_constructor(Constructor<cv::dnn::ReshapeLayer>()).
    define_attr("new_shape_desc", &cv::dnn::ReshapeLayer::newShapeDesc).
    define_attr("new_shape_range", &cv::dnn::ReshapeLayer::newShapeRange).
    define_singleton_function<cv::Ptr<cv::dnn::ReshapeLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ReshapeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::FlattenLayer> rb_cCvDnnFlattenLayer = define_class_under<cv::dnn::FlattenLayer, cv::dnn::Layer>(rb_mCvDnn, "FlattenLayer").
    define_constructor(Constructor<cv::dnn::FlattenLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::FlattenLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::FlattenLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::QuantizeLayer> rb_cCvDnnQuantizeLayer = define_class_under<cv::dnn::QuantizeLayer, cv::dnn::Layer>(rb_mCvDnn, "QuantizeLayer").
    define_constructor(Constructor<cv::dnn::QuantizeLayer>()).
    define_attr("scales", &cv::dnn::QuantizeLayer::scales).
    define_attr("zeropoints", &cv::dnn::QuantizeLayer::zeropoints).
    define_singleton_function<cv::Ptr<cv::dnn::QuantizeLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::QuantizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::DequantizeLayer> rb_cCvDnnDequantizeLayer = define_class_under<cv::dnn::DequantizeLayer, cv::dnn::Layer>(rb_mCvDnn, "DequantizeLayer").
    define_constructor(Constructor<cv::dnn::DequantizeLayer>()).
    define_attr("scales", &cv::dnn::DequantizeLayer::scales).
    define_attr("zeropoints", &cv::dnn::DequantizeLayer::zeropoints).
    define_singleton_function<cv::Ptr<cv::dnn::DequantizeLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::DequantizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::RequantizeLayer> rb_cCvDnnRequantizeLayer = define_class_under<cv::dnn::RequantizeLayer, cv::dnn::Layer>(rb_mCvDnn, "RequantizeLayer").
    define_constructor(Constructor<cv::dnn::RequantizeLayer>()).
    define_attr("scale", &cv::dnn::RequantizeLayer::scale).
    define_attr("shift", &cv::dnn::RequantizeLayer::shift).
    define_singleton_function<cv::Ptr<cv::dnn::RequantizeLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::RequantizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ConcatLayer> rb_cCvDnnConcatLayer = define_class_under<cv::dnn::ConcatLayer, cv::dnn::Layer>(rb_mCvDnn, "ConcatLayer").
    define_constructor(Constructor<cv::dnn::ConcatLayer>()).
    define_attr("axis", &cv::dnn::ConcatLayer::axis).
    define_attr("padding", &cv::dnn::ConcatLayer::padding).
    define_attr("padding_value", &cv::dnn::ConcatLayer::paddingValue).
    define_singleton_function<cv::Ptr<cv::dnn::ConcatLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ConcatLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SplitLayer> rb_cCvDnnSplitLayer = define_class_under<cv::dnn::SplitLayer, cv::dnn::Layer>(rb_mCvDnn, "SplitLayer").
    define_constructor(Constructor<cv::dnn::SplitLayer>()).
    define_attr("outputs_count", &cv::dnn::SplitLayer::outputsCount).
    define_singleton_function<cv::Ptr<cv::dnn::SplitLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SplitLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SliceLayer> rb_cCvDnnSliceLayer = define_class_under<cv::dnn::SliceLayer, cv::dnn::Layer>(rb_mCvDnn, "SliceLayer").
    define_constructor(Constructor<cv::dnn::SliceLayer>()).
    define_attr("slice_ranges", &cv::dnn::SliceLayer::sliceRanges).
    define_attr("slice_steps", &cv::dnn::SliceLayer::sliceSteps).
    define_attr("axis", &cv::dnn::SliceLayer::axis).
    define_attr("num_split", &cv::dnn::SliceLayer::num_split).
    define_singleton_function<cv::Ptr<cv::dnn::SliceLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SliceLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::PermuteLayer> rb_cCvDnnPermuteLayer = define_class_under<cv::dnn::PermuteLayer, cv::dnn::Layer>(rb_mCvDnn, "PermuteLayer").
    define_constructor(Constructor<cv::dnn::PermuteLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::PermuteLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::PermuteLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ShuffleChannelLayer> rb_cCvDnnShuffleChannelLayer = define_class_under<cv::dnn::ShuffleChannelLayer, cv::dnn::Layer>(rb_mCvDnn, "ShuffleChannelLayer").
    define_constructor(Constructor<cv::dnn::ShuffleChannelLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ShuffleChannelLayer::create,
      Arg("params")).
    define_attr("group", &cv::dnn::ShuffleChannelLayer::group);

  Rice::Data_Type<cv::dnn::PaddingLayer> rb_cCvDnnPaddingLayer = define_class_under<cv::dnn::PaddingLayer, cv::dnn::Layer>(rb_mCvDnn, "PaddingLayer").
    define_constructor(Constructor<cv::dnn::PaddingLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::PaddingLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::PaddingLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ActivationLayer> rb_cCvDnnActivationLayer = define_class_under<cv::dnn::ActivationLayer, cv::dnn::Layer>(rb_mCvDnn, "ActivationLayer").
    define_constructor(Constructor<cv::dnn::ActivationLayer>()).
    define_method<void(cv::dnn::ActivationLayer::*)(const float*, float*, int, size_t, int, int) const>("forward_slice", &cv::dnn::ActivationLayer::forwardSlice,
      ArgBuffer("src"), ArgBuffer("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1")).
    define_method<void(cv::dnn::ActivationLayer::*)(const int*, const int*, int*, int, size_t, int, int) const>("forward_slice", &cv::dnn::ActivationLayer::forwardSlice,
      ArgBuffer("src"), ArgBuffer("lut"), ArgBuffer("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1")).
    define_method<void(cv::dnn::ActivationLayer::*)(const int8_t*, const int8_t*, int8_t*, int, size_t, int, int) const>("forward_slice", &cv::dnn::ActivationLayer::forwardSlice,
      ArgBuffer("src"), ArgBuffer("lut"), ArgBuffer("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1"));

  Rice::Data_Type<cv::dnn::ReLULayer> rb_cCvDnnReLULayer = define_class_under<cv::dnn::ReLULayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ReLULayer").
    define_constructor(Constructor<cv::dnn::ReLULayer>()).
    define_attr("negative_slope", &cv::dnn::ReLULayer::negativeSlope).
    define_singleton_function<cv::Ptr<cv::dnn::ReLULayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ReLULayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ReLU6Layer> rb_cCvDnnReLU6Layer = define_class_under<cv::dnn::ReLU6Layer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ReLU6Layer").
    define_constructor(Constructor<cv::dnn::ReLU6Layer>()).
    define_attr("min_value", &cv::dnn::ReLU6Layer::minValue).
    define_attr("max_value", &cv::dnn::ReLU6Layer::maxValue).
    define_singleton_function<cv::Ptr<cv::dnn::ReLU6Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ReLU6Layer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ChannelsPReLULayer> rb_cCvDnnChannelsPReLULayer = define_class_under<cv::dnn::ChannelsPReLULayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ChannelsPReLULayer").
    define_constructor(Constructor<cv::dnn::ChannelsPReLULayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ChannelsPReLULayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ELULayer> rb_cCvDnnELULayer = define_class_under<cv::dnn::ELULayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ELULayer").
    define_constructor(Constructor<cv::dnn::ELULayer>()).
    define_attr("alpha", &cv::dnn::ELULayer::alpha).
    define_singleton_function<cv::Ptr<cv::dnn::ELULayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ELULayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::TanHLayer> rb_cCvDnnTanHLayer = define_class_under<cv::dnn::TanHLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "TanHLayer").
    define_constructor(Constructor<cv::dnn::TanHLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::TanHLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::TanHLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SwishLayer> rb_cCvDnnSwishLayer = define_class_under<cv::dnn::SwishLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SwishLayer").
    define_constructor(Constructor<cv::dnn::SwishLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SwishLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SwishLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::MishLayer> rb_cCvDnnMishLayer = define_class_under<cv::dnn::MishLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "MishLayer").
    define_constructor(Constructor<cv::dnn::MishLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::MishLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::MishLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SigmoidLayer> rb_cCvDnnSigmoidLayer = define_class_under<cv::dnn::SigmoidLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SigmoidLayer").
    define_constructor(Constructor<cv::dnn::SigmoidLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SigmoidLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SigmoidLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::BNLLLayer> rb_cCvDnnBNLLLayer = define_class_under<cv::dnn::BNLLLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "BNLLLayer").
    define_constructor(Constructor<cv::dnn::BNLLLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::BNLLLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::BNLLLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AbsLayer> rb_cCvDnnAbsLayer = define_class_under<cv::dnn::AbsLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "AbsLayer").
    define_constructor(Constructor<cv::dnn::AbsLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AbsLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AbsLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::PowerLayer> rb_cCvDnnPowerLayer = define_class_under<cv::dnn::PowerLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "PowerLayer").
    define_constructor(Constructor<cv::dnn::PowerLayer>()).
    define_attr("power", &cv::dnn::PowerLayer::power).
    define_attr("scale", &cv::dnn::PowerLayer::scale).
    define_attr("shift", &cv::dnn::PowerLayer::shift).
    define_singleton_function<cv::Ptr<cv::dnn::PowerLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::PowerLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ExpLayer> rb_cCvDnnExpLayer = define_class_under<cv::dnn::ExpLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ExpLayer").
    define_constructor(Constructor<cv::dnn::ExpLayer>()).
    define_attr("base", &cv::dnn::ExpLayer::base).
    define_attr("scale", &cv::dnn::ExpLayer::scale).
    define_attr("shift", &cv::dnn::ExpLayer::shift).
    define_singleton_function<cv::Ptr<cv::dnn::ExpLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ExpLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CeilLayer> rb_cCvDnnCeilLayer = define_class_under<cv::dnn::CeilLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "CeilLayer").
    define_constructor(Constructor<cv::dnn::CeilLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::CeilLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CeilLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::FloorLayer> rb_cCvDnnFloorLayer = define_class_under<cv::dnn::FloorLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "FloorLayer").
    define_constructor(Constructor<cv::dnn::FloorLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::FloorLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::FloorLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::LogLayer> rb_cCvDnnLogLayer = define_class_under<cv::dnn::LogLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "LogLayer").
    define_constructor(Constructor<cv::dnn::LogLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::LogLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::LogLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::RoundLayer> rb_cCvDnnRoundLayer = define_class_under<cv::dnn::RoundLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "RoundLayer").
    define_constructor(Constructor<cv::dnn::RoundLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::RoundLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::RoundLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SqrtLayer> rb_cCvDnnSqrtLayer = define_class_under<cv::dnn::SqrtLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SqrtLayer").
    define_constructor(Constructor<cv::dnn::SqrtLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SqrtLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SqrtLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::NotLayer> rb_cCvDnnNotLayer = define_class_under<cv::dnn::NotLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "NotLayer").
    define_constructor(Constructor<cv::dnn::NotLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::NotLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::NotLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AcosLayer> rb_cCvDnnAcosLayer = define_class_under<cv::dnn::AcosLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "AcosLayer").
    define_constructor(Constructor<cv::dnn::AcosLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AcosLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AcosLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AcoshLayer> rb_cCvDnnAcoshLayer = define_class_under<cv::dnn::AcoshLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "AcoshLayer").
    define_constructor(Constructor<cv::dnn::AcoshLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AcoshLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AcoshLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AsinLayer> rb_cCvDnnAsinLayer = define_class_under<cv::dnn::AsinLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "AsinLayer").
    define_constructor(Constructor<cv::dnn::AsinLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AsinLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AsinLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AsinhLayer> rb_cCvDnnAsinhLayer = define_class_under<cv::dnn::AsinhLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "AsinhLayer").
    define_constructor(Constructor<cv::dnn::AsinhLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AsinhLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AsinhLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AtanLayer> rb_cCvDnnAtanLayer = define_class_under<cv::dnn::AtanLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "AtanLayer").
    define_constructor(Constructor<cv::dnn::AtanLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AtanLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AtanLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AtanhLayer> rb_cCvDnnAtanhLayer = define_class_under<cv::dnn::AtanhLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "AtanhLayer").
    define_constructor(Constructor<cv::dnn::AtanhLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AtanhLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AtanhLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CosLayer> rb_cCvDnnCosLayer = define_class_under<cv::dnn::CosLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "CosLayer").
    define_constructor(Constructor<cv::dnn::CosLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::CosLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CosLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CoshLayer> rb_cCvDnnCoshLayer = define_class_under<cv::dnn::CoshLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "CoshLayer").
    define_constructor(Constructor<cv::dnn::CoshLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::CoshLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CoshLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ErfLayer> rb_cCvDnnErfLayer = define_class_under<cv::dnn::ErfLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ErfLayer").
    define_constructor(Constructor<cv::dnn::ErfLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ErfLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ErfLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::HardSwishLayer> rb_cCvDnnHardSwishLayer = define_class_under<cv::dnn::HardSwishLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "HardSwishLayer").
    define_constructor(Constructor<cv::dnn::HardSwishLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::HardSwishLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::HardSwishLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SinLayer> rb_cCvDnnSinLayer = define_class_under<cv::dnn::SinLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SinLayer").
    define_constructor(Constructor<cv::dnn::SinLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SinLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SinLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SinhLayer> rb_cCvDnnSinhLayer = define_class_under<cv::dnn::SinhLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SinhLayer").
    define_constructor(Constructor<cv::dnn::SinhLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SinhLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SinhLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SoftplusLayer> rb_cCvDnnSoftplusLayer = define_class_under<cv::dnn::SoftplusLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SoftplusLayer").
    define_constructor(Constructor<cv::dnn::SoftplusLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SoftplusLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SoftplusLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SoftsignLayer> rb_cCvDnnSoftsignLayer = define_class_under<cv::dnn::SoftsignLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SoftsignLayer").
    define_constructor(Constructor<cv::dnn::SoftsignLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SoftsignLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SoftsignLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::TanLayer> rb_cCvDnnTanLayer = define_class_under<cv::dnn::TanLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "TanLayer").
    define_constructor(Constructor<cv::dnn::TanLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::TanLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::TanLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CeluLayer> rb_cCvDnnCeluLayer = define_class_under<cv::dnn::CeluLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "CeluLayer").
    define_constructor(Constructor<cv::dnn::CeluLayer>()).
    define_attr("alpha", &cv::dnn::CeluLayer::alpha).
    define_singleton_function<cv::Ptr<cv::dnn::CeluLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CeluLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::HardSigmoidLayer> rb_cCvDnnHardSigmoidLayer = define_class_under<cv::dnn::HardSigmoidLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "HardSigmoidLayer").
    define_constructor(Constructor<cv::dnn::HardSigmoidLayer>()).
    define_attr("alpha", &cv::dnn::HardSigmoidLayer::alpha).
    define_attr("beta", &cv::dnn::HardSigmoidLayer::beta).
    define_singleton_function<cv::Ptr<cv::dnn::HardSigmoidLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::HardSigmoidLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SeluLayer> rb_cCvDnnSeluLayer = define_class_under<cv::dnn::SeluLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SeluLayer").
    define_constructor(Constructor<cv::dnn::SeluLayer>()).
    define_attr("alpha", &cv::dnn::SeluLayer::alpha).
    define_attr("gamma", &cv::dnn::SeluLayer::gamma).
    define_singleton_function<cv::Ptr<cv::dnn::SeluLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SeluLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::GeluLayer> rb_cCvDnnGeluLayer = define_class_under<cv::dnn::GeluLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "GeluLayer").
    define_constructor(Constructor<cv::dnn::GeluLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::GeluLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::GeluLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::GeluApproximationLayer> rb_cCvDnnGeluApproximationLayer = define_class_under<cv::dnn::GeluApproximationLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "GeluApproximationLayer").
    define_constructor(Constructor<cv::dnn::GeluApproximationLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::GeluApproximationLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::GeluApproximationLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ThresholdedReluLayer> rb_cCvDnnThresholdedReluLayer = define_class_under<cv::dnn::ThresholdedReluLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ThresholdedReluLayer").
    define_constructor(Constructor<cv::dnn::ThresholdedReluLayer>()).
    define_attr("alpha", &cv::dnn::ThresholdedReluLayer::alpha).
    define_singleton_function<cv::Ptr<cv::dnn::ThresholdedReluLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ThresholdedReluLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ActivationLayerInt8> rb_cCvDnnActivationLayerInt8 = define_class_under<cv::dnn::ActivationLayerInt8, cv::dnn::ActivationLayer>(rb_mCvDnn, "ActivationLayerInt8").
    define_constructor(Constructor<cv::dnn::ActivationLayerInt8>()).
    define_singleton_function<cv::Ptr<cv::dnn::ActivationLayerInt8>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ActivationLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SignLayer> rb_cCvDnnSignLayer = define_class_under<cv::dnn::SignLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "SignLayer").
    define_constructor(Constructor<cv::dnn::SignLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SignLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SignLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ShrinkLayer> rb_cCvDnnShrinkLayer = define_class_under<cv::dnn::ShrinkLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ShrinkLayer").
    define_constructor(Constructor<cv::dnn::ShrinkLayer>()).
    define_attr("bias", &cv::dnn::ShrinkLayer::bias).
    define_attr("lambd", &cv::dnn::ShrinkLayer::lambd).
    define_singleton_function<cv::Ptr<cv::dnn::ShrinkLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ShrinkLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ReciprocalLayer> rb_cCvDnnReciprocalLayer = define_class_under<cv::dnn::ReciprocalLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "ReciprocalLayer").
    define_constructor(Constructor<cv::dnn::ReciprocalLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ReciprocalLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ReciprocalLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CropLayer> rb_cCvDnnCropLayer = define_class_under<cv::dnn::CropLayer, cv::dnn::Layer>(rb_mCvDnn, "CropLayer").
    define_constructor(Constructor<cv::dnn::CropLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CropLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::EltwiseLayer> rb_cCvDnnEltwiseLayer = define_class_under<cv::dnn::EltwiseLayer, cv::dnn::Layer>(rb_mCvDnn, "EltwiseLayer").
    define_constructor(Constructor<cv::dnn::EltwiseLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::EltwiseLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::EltwiseLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::EltwiseLayerInt8> rb_cCvDnnEltwiseLayerInt8 = define_class_under<cv::dnn::EltwiseLayerInt8, cv::dnn::Layer>(rb_mCvDnn, "EltwiseLayerInt8").
    define_constructor(Constructor<cv::dnn::EltwiseLayerInt8>()).
    define_singleton_function<cv::Ptr<cv::dnn::EltwiseLayerInt8>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::EltwiseLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::NaryEltwiseLayer> rb_cCvDnnNaryEltwiseLayer = define_class_under<cv::dnn::NaryEltwiseLayer, cv::dnn::Layer>(rb_mCvDnn, "NaryEltwiseLayer").
    define_constructor(Constructor<cv::dnn::NaryEltwiseLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::NaryEltwiseLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::NaryEltwiseLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::BatchNormLayer> rb_cCvDnnBatchNormLayer = define_class_under<cv::dnn::BatchNormLayer, cv::dnn::ActivationLayer>(rb_mCvDnn, "BatchNormLayer").
    define_constructor(Constructor<cv::dnn::BatchNormLayer>()).
    define_attr("has_weights", &cv::dnn::BatchNormLayer::hasWeights).
    define_attr("has_bias", &cv::dnn::BatchNormLayer::hasBias).
    define_attr("epsilon", &cv::dnn::BatchNormLayer::epsilon).
    define_singleton_function<cv::Ptr<cv::dnn::BatchNormLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::BatchNormLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::BatchNormLayerInt8> rb_cCvDnnBatchNormLayerInt8 = define_class_under<cv::dnn::BatchNormLayerInt8, cv::dnn::BatchNormLayer>(rb_mCvDnn, "BatchNormLayerInt8").
    define_constructor(Constructor<cv::dnn::BatchNormLayerInt8>()).
    define_attr("input_sc", &cv::dnn::BatchNormLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::BatchNormLayerInt8::output_sc).
    define_attr("input_zp", &cv::dnn::BatchNormLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::BatchNormLayerInt8::output_zp).
    define_singleton_function<cv::Ptr<cv::dnn::BatchNormLayerInt8>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::BatchNormLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::MaxUnpoolLayer> rb_cCvDnnMaxUnpoolLayer = define_class_under<cv::dnn::MaxUnpoolLayer, cv::dnn::Layer>(rb_mCvDnn, "MaxUnpoolLayer").
    define_constructor(Constructor<cv::dnn::MaxUnpoolLayer>()).
    define_attr("pool_kernel", &cv::dnn::MaxUnpoolLayer::poolKernel).
    define_attr("pool_pad", &cv::dnn::MaxUnpoolLayer::poolPad).
    define_attr("pool_stride", &cv::dnn::MaxUnpoolLayer::poolStride).
    define_singleton_function<cv::Ptr<cv::dnn::MaxUnpoolLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::MaxUnpoolLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ScaleLayer> rb_cCvDnnScaleLayer = define_class_under<cv::dnn::ScaleLayer, cv::dnn::Layer>(rb_mCvDnn, "ScaleLayer").
    define_constructor(Constructor<cv::dnn::ScaleLayer>()).
    define_attr("has_bias", &cv::dnn::ScaleLayer::hasBias).
    define_attr("axis", &cv::dnn::ScaleLayer::axis).
    define_attr("mode", &cv::dnn::ScaleLayer::mode).
    define_singleton_function<cv::Ptr<cv::dnn::ScaleLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ScaleLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ScaleLayerInt8> rb_cCvDnnScaleLayerInt8 = define_class_under<cv::dnn::ScaleLayerInt8, cv::dnn::ScaleLayer>(rb_mCvDnn, "ScaleLayerInt8").
    define_constructor(Constructor<cv::dnn::ScaleLayerInt8>()).
    define_attr("output_sc", &cv::dnn::ScaleLayerInt8::output_sc).
    define_attr("output_zp", &cv::dnn::ScaleLayerInt8::output_zp).
    define_singleton_function<cv::Ptr<cv::dnn::ScaleLayerInt8>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ScaleLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ShiftLayer> rb_cCvDnnShiftLayer = define_class_under<cv::dnn::ShiftLayer, cv::dnn::Layer>(rb_mCvDnn, "ShiftLayer").
    define_constructor(Constructor<cv::dnn::ShiftLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ShiftLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ShiftLayerInt8> rb_cCvDnnShiftLayerInt8 = define_class_under<cv::dnn::ShiftLayerInt8, cv::dnn::Layer>(rb_mCvDnn, "ShiftLayerInt8").
    define_constructor(Constructor<cv::dnn::ShiftLayerInt8>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ShiftLayerInt8::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CompareLayer> rb_cCvDnnCompareLayer = define_class_under<cv::dnn::CompareLayer, cv::dnn::Layer>(rb_mCvDnn, "CompareLayer").
    define_constructor(Constructor<cv::dnn::CompareLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CompareLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::DataAugmentationLayer> rb_cCvDnnDataAugmentationLayer = define_class_under<cv::dnn::DataAugmentationLayer, cv::dnn::Layer>(rb_mCvDnn, "DataAugmentationLayer").
    define_constructor(Constructor<cv::dnn::DataAugmentationLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::DataAugmentationLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::DataAugmentationLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CorrelationLayer> rb_cCvDnnCorrelationLayer = define_class_under<cv::dnn::CorrelationLayer, cv::dnn::Layer>(rb_mCvDnn, "CorrelationLayer").
    define_constructor(Constructor<cv::dnn::CorrelationLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::CorrelationLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CorrelationLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AccumLayer> rb_cCvDnnAccumLayer = define_class_under<cv::dnn::AccumLayer, cv::dnn::Layer>(rb_mCvDnn, "AccumLayer").
    define_constructor(Constructor<cv::dnn::AccumLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AccumLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AccumLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::FlowWarpLayer> rb_cCvDnnFlowWarpLayer = define_class_under<cv::dnn::FlowWarpLayer, cv::dnn::Layer>(rb_mCvDnn, "FlowWarpLayer").
    define_constructor(Constructor<cv::dnn::FlowWarpLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::FlowWarpLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::FlowWarpLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::PriorBoxLayer> rb_cCvDnnPriorBoxLayer = define_class_under<cv::dnn::PriorBoxLayer, cv::dnn::Layer>(rb_mCvDnn, "PriorBoxLayer").
    define_constructor(Constructor<cv::dnn::PriorBoxLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::PriorBoxLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::PriorBoxLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ReorgLayer> rb_cCvDnnReorgLayer = define_class_under<cv::dnn::ReorgLayer, cv::dnn::Layer>(rb_mCvDnn, "ReorgLayer").
    define_constructor(Constructor<cv::dnn::ReorgLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ReorgLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ReorgLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::RegionLayer> rb_cCvDnnRegionLayer = define_class_under<cv::dnn::RegionLayer, cv::dnn::Layer>(rb_mCvDnn, "RegionLayer").
    define_constructor(Constructor<cv::dnn::RegionLayer>()).
    define_attr("nms_threshold", &cv::dnn::RegionLayer::nmsThreshold).
    define_singleton_function<cv::Ptr<cv::dnn::RegionLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::RegionLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::DetectionOutputLayer> rb_cCvDnnDetectionOutputLayer = define_class_under<cv::dnn::DetectionOutputLayer, cv::dnn::Layer>(rb_mCvDnn, "DetectionOutputLayer").
    define_constructor(Constructor<cv::dnn::DetectionOutputLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::DetectionOutputLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::DetectionOutputLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::NormalizeBBoxLayer> rb_cCvDnnNormalizeBBoxLayer = define_class_under<cv::dnn::NormalizeBBoxLayer, cv::dnn::Layer>(rb_mCvDnn, "NormalizeBBoxLayer").
    define_constructor(Constructor<cv::dnn::NormalizeBBoxLayer>()).
    define_attr("pnorm", &cv::dnn::NormalizeBBoxLayer::pnorm).
    define_attr("epsilon", &cv::dnn::NormalizeBBoxLayer::epsilon).
    define_attr("across_spatial", &cv::dnn::NormalizeBBoxLayer::acrossSpatial).
    define_singleton_function<cv::Ptr<cv::dnn::NormalizeBBoxLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::NormalizeBBoxLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ResizeLayer> rb_cCvDnnResizeLayer = define_class_under<cv::dnn::ResizeLayer, cv::dnn::Layer>(rb_mCvDnn, "ResizeLayer").
    define_constructor(Constructor<cv::dnn::ResizeLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ResizeLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ResizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::InterpLayer> rb_cCvDnnInterpLayer = define_class_under<cv::dnn::InterpLayer, cv::dnn::Layer>(rb_mCvDnn, "InterpLayer").
    define_constructor(Constructor<cv::dnn::InterpLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::InterpLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ProposalLayer> rb_cCvDnnProposalLayer = define_class_under<cv::dnn::ProposalLayer, cv::dnn::Layer>(rb_mCvDnn, "ProposalLayer").
    define_constructor(Constructor<cv::dnn::ProposalLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ProposalLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ProposalLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CropAndResizeLayer> rb_cCvDnnCropAndResizeLayer = define_class_under<cv::dnn::CropAndResizeLayer, cv::dnn::Layer>(rb_mCvDnn, "CropAndResizeLayer").
    define_constructor(Constructor<cv::dnn::CropAndResizeLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::Layer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CropAndResizeLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::CumSumLayer> rb_cCvDnnCumSumLayer = define_class_under<cv::dnn::CumSumLayer, cv::dnn::Layer>(rb_mCvDnn, "CumSumLayer").
    define_constructor(Constructor<cv::dnn::CumSumLayer>()).
    define_attr("exclusive", &cv::dnn::CumSumLayer::exclusive).
    define_attr("reverse", &cv::dnn::CumSumLayer::reverse).
    define_singleton_function<cv::Ptr<cv::dnn::CumSumLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::CumSumLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ScatterLayer> rb_cCvDnnScatterLayer = define_class_under<cv::dnn::ScatterLayer, cv::dnn::Layer>(rb_mCvDnn, "ScatterLayer").
    define_constructor(Constructor<cv::dnn::ScatterLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ScatterLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ScatterLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ScatterNDLayer> rb_cCvDnnScatterNDLayer = define_class_under<cv::dnn::ScatterNDLayer, cv::dnn::Layer>(rb_mCvDnn, "ScatterNDLayer").
    define_constructor(Constructor<cv::dnn::ScatterNDLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ScatterNDLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ScatterNDLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::TileLayer> rb_cCvDnnTileLayer = define_class_under<cv::dnn::TileLayer, cv::dnn::Layer>(rb_mCvDnn, "TileLayer").
    define_constructor(Constructor<cv::dnn::TileLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::TileLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::TileLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::LayerNormLayer> rb_cCvDnnLayerNormLayer = define_class_under<cv::dnn::LayerNormLayer, cv::dnn::Layer>(rb_mCvDnn, "LayerNormLayer").
    define_constructor(Constructor<cv::dnn::LayerNormLayer>()).
    define_attr("has_bias", &cv::dnn::LayerNormLayer::hasBias).
    define_attr("axis", &cv::dnn::LayerNormLayer::axis).
    define_attr("epsilon", &cv::dnn::LayerNormLayer::epsilon).
    define_singleton_function<cv::Ptr<cv::dnn::LayerNormLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::LayerNormLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::GemmLayer> rb_cCvDnnGemmLayer = define_class_under<cv::dnn::GemmLayer, cv::dnn::Layer>(rb_mCvDnn, "GemmLayer").
    define_constructor(Constructor<cv::dnn::GemmLayer>()).
    define_attr("trans_a", &cv::dnn::GemmLayer::trans_a).
    define_attr("trans_b", &cv::dnn::GemmLayer::trans_b).
    define_attr("alpha", &cv::dnn::GemmLayer::alpha).
    define_attr("beta", &cv::dnn::GemmLayer::beta).
    define_singleton_function<cv::Ptr<cv::dnn::GemmLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::GemmLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::MatMulLayer> rb_cCvDnnMatMulLayer = define_class_under<cv::dnn::MatMulLayer, cv::dnn::Layer>(rb_mCvDnn, "MatMulLayer").
    define_constructor(Constructor<cv::dnn::MatMulLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::MatMulLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::MatMulLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::ExpandLayer> rb_cCvDnnExpandLayer = define_class_under<cv::dnn::ExpandLayer, cv::dnn::Layer>(rb_mCvDnn, "ExpandLayer").
    define_constructor(Constructor<cv::dnn::ExpandLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::ExpandLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::ExpandLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::InstanceNormLayer> rb_cCvDnnInstanceNormLayer = define_class_under<cv::dnn::InstanceNormLayer, cv::dnn::Layer>(rb_mCvDnn, "InstanceNormLayer").
    define_constructor(Constructor<cv::dnn::InstanceNormLayer>()).
    define_attr("epsilon", &cv::dnn::InstanceNormLayer::epsilon).
    define_singleton_function<cv::Ptr<cv::dnn::InstanceNormLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::InstanceNormLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::AttentionLayer> rb_cCvDnnAttentionLayer = define_class_under<cv::dnn::AttentionLayer, cv::dnn::Layer>(rb_mCvDnn, "AttentionLayer").
    define_constructor(Constructor<cv::dnn::AttentionLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::AttentionLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::AttentionLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::GroupNormLayer> rb_cCvDnnGroupNormLayer = define_class_under<cv::dnn::GroupNormLayer, cv::dnn::Layer>(rb_mCvDnn, "GroupNormLayer").
    define_constructor(Constructor<cv::dnn::GroupNormLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::GroupNormLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::GroupNormLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::DepthToSpaceLayer> rb_cCvDnnDepthToSpaceLayer = define_class_under<cv::dnn::DepthToSpaceLayer, cv::dnn::Layer>(rb_mCvDnn, "DepthToSpaceLayer").
    define_constructor(Constructor<cv::dnn::DepthToSpaceLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::DepthToSpaceLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::DepthToSpaceLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::SpaceToDepthLayer> rb_cCvDnnSpaceToDepthLayer = define_class_under<cv::dnn::SpaceToDepthLayer, cv::dnn::Layer>(rb_mCvDnn, "SpaceToDepthLayer").
    define_constructor(Constructor<cv::dnn::SpaceToDepthLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::SpaceToDepthLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::SpaceToDepthLayer::create,
      Arg("params"));

  Rice::Data_Type<cv::dnn::TopKLayer> rb_cCvDnnTopKLayer = define_class_under<cv::dnn::TopKLayer, cv::dnn::Layer>(rb_mCvDnn, "TopKLayer").
    define_constructor(Constructor<cv::dnn::TopKLayer>()).
    define_singleton_function<cv::Ptr<cv::dnn::TopKLayer>(*)(const cv::dnn::LayerParams&)>("create", &cv::dnn::TopKLayer::create,
      Arg("params"));
}