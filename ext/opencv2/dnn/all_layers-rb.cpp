#include <opencv2/dnn/all_layers.hpp>
#include "../core/cvstd_wrapper-rb.hpp"
#include "all_layers-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDnnAbsLayer;
Rice::Class rb_cCvDnnAccumLayer;
Rice::Class rb_cCvDnnAcosLayer;
Rice::Class rb_cCvDnnAcoshLayer;
Rice::Class rb_cCvDnnActivationLayer;
Rice::Class rb_cCvDnnActivationLayerInt8;
Rice::Class rb_cCvDnnArgLayer;
Rice::Class rb_cCvDnnAsinLayer;
Rice::Class rb_cCvDnnAsinhLayer;
Rice::Class rb_cCvDnnAtanLayer;
Rice::Class rb_cCvDnnAtanhLayer;
Rice::Class rb_cCvDnnAttentionLayer;
Rice::Class rb_cCvDnnBNLLLayer;
Rice::Class rb_cCvDnnBaseConvolutionLayer;
Rice::Class rb_cCvDnnBatchNormLayer;
Rice::Class rb_cCvDnnBatchNormLayerInt8;
Rice::Class rb_cCvDnnBlankLayer;
Rice::Class rb_cCvDnnCeilLayer;
Rice::Class rb_cCvDnnCeluLayer;
Rice::Class rb_cCvDnnChannelsPReLULayer;
Rice::Class rb_cCvDnnCompareLayer;
Rice::Class rb_cCvDnnConcatLayer;
Rice::Class rb_cCvDnnConstLayer;
Rice::Class rb_cCvDnnConvolutionLayer;
Rice::Class rb_cCvDnnConvolutionLayerInt8;
Rice::Class rb_cCvDnnCorrelationLayer;
Rice::Class rb_cCvDnnCosLayer;
Rice::Class rb_cCvDnnCoshLayer;
Rice::Class rb_cCvDnnCropAndResizeLayer;
Rice::Class rb_cCvDnnCropLayer;
Rice::Class rb_cCvDnnCumSumLayer;
Rice::Class rb_cCvDnnDataAugmentationLayer;
Rice::Class rb_cCvDnnDeconvolutionLayer;
Rice::Class rb_cCvDnnDepthToSpaceLayer;
Rice::Class rb_cCvDnnDequantizeLayer;
Rice::Class rb_cCvDnnDetectionOutputLayer;
Rice::Class rb_cCvDnnELULayer;
Rice::Class rb_cCvDnnEinsumLayer;
Rice::Class rb_cCvDnnEltwiseLayer;
Rice::Class rb_cCvDnnEltwiseLayerInt8;
Rice::Class rb_cCvDnnErfLayer;
Rice::Class rb_cCvDnnExpLayer;
Rice::Class rb_cCvDnnExpandLayer;
Rice::Class rb_cCvDnnFlattenLayer;
Rice::Class rb_cCvDnnFloorLayer;
Rice::Class rb_cCvDnnFlowWarpLayer;
Rice::Class rb_cCvDnnGRULayer;
Rice::Class rb_cCvDnnGatherElementsLayer;
Rice::Class rb_cCvDnnGatherLayer;
Rice::Class rb_cCvDnnGeluApproximationLayer;
Rice::Class rb_cCvDnnGeluLayer;
Rice::Class rb_cCvDnnGemmLayer;
Rice::Class rb_cCvDnnGroupNormLayer;
Rice::Class rb_cCvDnnHardSigmoidLayer;
Rice::Class rb_cCvDnnHardSwishLayer;
Rice::Class rb_cCvDnnInnerProductLayer;
Rice::Class rb_cCvDnnInnerProductLayerInt8;
Rice::Class rb_cCvDnnInstanceNormLayer;
Rice::Class rb_cCvDnnInterpLayer;
Rice::Class rb_cCvDnnLRNLayer;
Rice::Class rb_cCvDnnLSTMLayer;
Rice::Class rb_cCvDnnLayerNormLayer;
Rice::Class rb_cCvDnnLogLayer;
Rice::Class rb_cCvDnnMVNLayer;
Rice::Class rb_cCvDnnMatMulLayer;
Rice::Class rb_cCvDnnMaxUnpoolLayer;
Rice::Class rb_cCvDnnMishLayer;
Rice::Class rb_cCvDnnNaryEltwiseLayer;
Rice::Class rb_cCvDnnNormalizeBBoxLayer;
Rice::Class rb_cCvDnnNotLayer;
Rice::Class rb_cCvDnnPaddingLayer;
Rice::Class rb_cCvDnnPermuteLayer;
Rice::Class rb_cCvDnnPoolingLayer;
Rice::Class rb_cCvDnnPoolingLayerInt8;
Rice::Class rb_cCvDnnPowerLayer;
Rice::Class rb_cCvDnnPriorBoxLayer;
Rice::Class rb_cCvDnnProposalLayer;
Rice::Class rb_cCvDnnQuantizeLayer;
Rice::Class rb_cCvDnnRNNLayer;
Rice::Class rb_cCvDnnReLU6Layer;
Rice::Class rb_cCvDnnReLULayer;
Rice::Class rb_cCvDnnReciprocalLayer;
Rice::Class rb_cCvDnnReduceLayer;
Rice::Class rb_cCvDnnRegionLayer;
Rice::Class rb_cCvDnnReorgLayer;
Rice::Class rb_cCvDnnRequantizeLayer;
Rice::Class rb_cCvDnnReshapeLayer;
Rice::Class rb_cCvDnnResizeLayer;
Rice::Class rb_cCvDnnRoundLayer;
Rice::Class rb_cCvDnnScaleLayer;
Rice::Class rb_cCvDnnScaleLayerInt8;
Rice::Class rb_cCvDnnScatterLayer;
Rice::Class rb_cCvDnnScatterNDLayer;
Rice::Class rb_cCvDnnSeluLayer;
Rice::Class rb_cCvDnnShiftLayer;
Rice::Class rb_cCvDnnShiftLayerInt8;
Rice::Class rb_cCvDnnShrinkLayer;
Rice::Class rb_cCvDnnShuffleChannelLayer;
Rice::Class rb_cCvDnnSigmoidLayer;
Rice::Class rb_cCvDnnSignLayer;
Rice::Class rb_cCvDnnSinLayer;
Rice::Class rb_cCvDnnSinhLayer;
Rice::Class rb_cCvDnnSliceLayer;
Rice::Class rb_cCvDnnSoftmaxLayer;
Rice::Class rb_cCvDnnSoftmaxLayerInt8;
Rice::Class rb_cCvDnnSoftplusLayer;
Rice::Class rb_cCvDnnSoftsignLayer;
Rice::Class rb_cCvDnnSpaceToDepthLayer;
Rice::Class rb_cCvDnnSplitLayer;
Rice::Class rb_cCvDnnSqrtLayer;
Rice::Class rb_cCvDnnSwishLayer;
Rice::Class rb_cCvDnnTanHLayer;
Rice::Class rb_cCvDnnTanLayer;
Rice::Class rb_cCvDnnThresholdedReluLayer;
Rice::Class rb_cCvDnnTileLayer;
Rice::Class rb_cCvDnnTopKLayer;

void Init_AllLayers()
{
  Module rb_mCv = define_module("Cv");
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  
  rb_cCvDnnBlankLayer = define_class_under<cv::dnn::dnn4_v20241223::BlankLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "BlankLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BlankLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::BlankLayer::create,
      Arg("params"));
  
  rb_cCvDnnConstLayer = define_class_under<cv::dnn::dnn4_v20241223::ConstLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ConstLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ConstLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ConstLayer::create,
      Arg("params"));
  
  rb_cCvDnnLSTMLayer = define_class_under<cv::dnn::dnn4_v20241223::LSTMLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "LSTMLayer").
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::LSTMLayer::create,
      Arg("params")).
    define_method("set_out_shape", &cv::dnn::dnn4_v20241223::LSTMLayer::setOutShape,
      Arg("out_tail_shape") = static_cast<const cv::dnn::dnn4_v20241223::MatShape &>(cv::dnn::dnn4_v20241223::MatShape())).
    define_method("input_name_to_index", &cv::dnn::dnn4_v20241223::LSTMLayer::inputNameToIndex,
      Arg("input_name")).
    define_method("output_name_to_index", &cv::dnn::dnn4_v20241223::LSTMLayer::outputNameToIndex,
      Arg("output_name"));
  
  rb_cCvDnnGRULayer = define_class_under<cv::dnn::dnn4_v20241223::GRULayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "GRULayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GRULayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::GRULayer::create,
      Arg("params"));
  
  rb_cCvDnnRNNLayer = define_class_under<cv::dnn::dnn4_v20241223::RNNLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "RNNLayer").
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::RNNLayer::create,
      Arg("params")).
    define_method("set_weights", &cv::dnn::dnn4_v20241223::RNNLayer::setWeights,
      Arg("wxh"), Arg("bh"), Arg("whh"), Arg("who"), Arg("bo")).
    define_method("set_produce_hidden_output", &cv::dnn::dnn4_v20241223::RNNLayer::setProduceHiddenOutput,
      Arg("produce") = static_cast<bool>(false));
  
  rb_cCvDnnEinsumLayer = define_class_under<cv::dnn::dnn4_v20241223::EinsumLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "EinsumLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::EinsumLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::EinsumLayer::create,
      Arg("params"));
  
  rb_cCvDnnBaseConvolutionLayer = define_class_under<cv::dnn::dnn4_v20241223::BaseConvolutionLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "BaseConvolutionLayer").
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
  
  rb_cCvDnnConvolutionLayer = define_class_under<cv::dnn::dnn4_v20241223::ConvolutionLayer, cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(rb_mCvDnn, "ConvolutionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ConvolutionLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ConvolutionLayer::create,
      Arg("params")).
    define_attr("fused_activation", &cv::dnn::dnn4_v20241223::ConvolutionLayer::fusedActivation).
    define_attr("fused_add", &cv::dnn::dnn4_v20241223::ConvolutionLayer::fusedAdd).
    define_attr("use_winograd", &cv::dnn::dnn4_v20241223::ConvolutionLayer::useWinograd);
  
  rb_cCvDnnConvolutionLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::ConvolutionLayerInt8, cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(rb_mCvDnn, "ConvolutionLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ConvolutionLayerInt8>()).
    define_attr("input_zp", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::output_sc).
    define_attr("per_channel", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::per_channel).
    define_attr("use_winograd", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::useWinograd).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ConvolutionLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnDeconvolutionLayer = define_class_under<cv::dnn::dnn4_v20241223::DeconvolutionLayer, cv::dnn::dnn4_v20241223::BaseConvolutionLayer>(rb_mCvDnn, "DeconvolutionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DeconvolutionLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::DeconvolutionLayer::create,
      Arg("params"));
  
  rb_cCvDnnLRNLayer = define_class_under<cv::dnn::dnn4_v20241223::LRNLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "LRNLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::LRNLayer>()).
    define_attr("type", &cv::dnn::dnn4_v20241223::LRNLayer::type).
    define_attr("size", &cv::dnn::dnn4_v20241223::LRNLayer::size).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::LRNLayer::alpha).
    define_attr("beta", &cv::dnn::dnn4_v20241223::LRNLayer::beta).
    define_attr("bias", &cv::dnn::dnn4_v20241223::LRNLayer::bias).
    define_attr("norm_by_size", &cv::dnn::dnn4_v20241223::LRNLayer::normBySize).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::LRNLayer::create,
      Arg("params"));
  
  rb_cCvDnnArgLayer = define_class_under<cv::dnn::dnn4_v20241223::ArgLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ArgLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ArgLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ArgLayer::create,
      Arg("params"));
  
  rb_cCvDnnGatherLayer = define_class_under<cv::dnn::dnn4_v20241223::GatherLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "GatherLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GatherLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::GatherLayer::create,
      Arg("params"));
  
  rb_cCvDnnGatherElementsLayer = define_class_under<cv::dnn::dnn4_v20241223::GatherElementsLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "GatherElementsLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GatherElementsLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::GatherElementsLayer::create,
      Arg("params"));
  
  rb_cCvDnnPoolingLayer = define_class_under<cv::dnn::dnn4_v20241223::PoolingLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "PoolingLayer").
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
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::PoolingLayer::create,
      Arg("params"));
  
  rb_cCvDnnPoolingLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::PoolingLayerInt8, cv::dnn::dnn4_v20241223::PoolingLayer>(rb_mCvDnn, "PoolingLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PoolingLayerInt8>()).
    define_attr("input_zp", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::output_sc).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::PoolingLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnReduceLayer = define_class_under<cv::dnn::dnn4_v20241223::ReduceLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ReduceLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReduceLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ReduceLayer::create,
      Arg("params"));
  
  rb_cCvDnnSoftmaxLayer = define_class_under<cv::dnn::dnn4_v20241223::SoftmaxLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "SoftmaxLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SoftmaxLayer>()).
    define_attr("log_soft_max", &cv::dnn::dnn4_v20241223::SoftmaxLayer::logSoftMax).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SoftmaxLayer::create,
      Arg("params"));
  
  rb_cCvDnnSoftmaxLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::SoftmaxLayerInt8, cv::dnn::dnn4_v20241223::SoftmaxLayer>(rb_mCvDnn, "SoftmaxLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SoftmaxLayerInt8>()).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::SoftmaxLayerInt8::output_sc).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::SoftmaxLayerInt8::output_zp).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SoftmaxLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnInnerProductLayer = define_class_under<cv::dnn::dnn4_v20241223::InnerProductLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "InnerProductLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::InnerProductLayer>()).
    define_attr("axis", &cv::dnn::dnn4_v20241223::InnerProductLayer::axis).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::InnerProductLayer::create,
      Arg("params"));
  
  rb_cCvDnnInnerProductLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::InnerProductLayerInt8, cv::dnn::dnn4_v20241223::InnerProductLayer>(rb_mCvDnn, "InnerProductLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::InnerProductLayerInt8>()).
    define_attr("input_zp", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::output_zp).
    define_attr("input_sc", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::output_sc).
    define_attr("per_channel", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::per_channel).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::InnerProductLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnMVNLayer = define_class_under<cv::dnn::dnn4_v20241223::MVNLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "MVNLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::MVNLayer>()).
    define_attr("eps", &cv::dnn::dnn4_v20241223::MVNLayer::eps).
    define_attr("norm_variance", &cv::dnn::dnn4_v20241223::MVNLayer::normVariance).
    define_attr("across_channels", &cv::dnn::dnn4_v20241223::MVNLayer::acrossChannels).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::MVNLayer::create,
      Arg("params"));
  
  rb_cCvDnnReshapeLayer = define_class_under<cv::dnn::dnn4_v20241223::ReshapeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ReshapeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReshapeLayer>()).
    define_attr("new_shape_desc", &cv::dnn::dnn4_v20241223::ReshapeLayer::newShapeDesc).
    define_attr("new_shape_range", &cv::dnn::dnn4_v20241223::ReshapeLayer::newShapeRange).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ReshapeLayer::create,
      Arg("params"));
  
  rb_cCvDnnFlattenLayer = define_class_under<cv::dnn::dnn4_v20241223::FlattenLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "FlattenLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::FlattenLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::FlattenLayer::create,
      Arg("params"));
  
  rb_cCvDnnQuantizeLayer = define_class_under<cv::dnn::dnn4_v20241223::QuantizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "QuantizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::QuantizeLayer>()).
    define_attr("scales", &cv::dnn::dnn4_v20241223::QuantizeLayer::scales).
    define_attr("zeropoints", &cv::dnn::dnn4_v20241223::QuantizeLayer::zeropoints).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::QuantizeLayer::create,
      Arg("params"));
  
  rb_cCvDnnDequantizeLayer = define_class_under<cv::dnn::dnn4_v20241223::DequantizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "DequantizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DequantizeLayer>()).
    define_attr("scales", &cv::dnn::dnn4_v20241223::DequantizeLayer::scales).
    define_attr("zeropoints", &cv::dnn::dnn4_v20241223::DequantizeLayer::zeropoints).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::DequantizeLayer::create,
      Arg("params"));
  
  rb_cCvDnnRequantizeLayer = define_class_under<cv::dnn::dnn4_v20241223::RequantizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "RequantizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::RequantizeLayer>()).
    define_attr("scale", &cv::dnn::dnn4_v20241223::RequantizeLayer::scale).
    define_attr("shift", &cv::dnn::dnn4_v20241223::RequantizeLayer::shift).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::RequantizeLayer::create,
      Arg("params"));
  
  rb_cCvDnnConcatLayer = define_class_under<cv::dnn::dnn4_v20241223::ConcatLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ConcatLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ConcatLayer>()).
    define_attr("axis", &cv::dnn::dnn4_v20241223::ConcatLayer::axis).
    define_attr("padding", &cv::dnn::dnn4_v20241223::ConcatLayer::padding).
    define_attr("padding_value", &cv::dnn::dnn4_v20241223::ConcatLayer::paddingValue).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ConcatLayer::create,
      Arg("params"));
  
  rb_cCvDnnSplitLayer = define_class_under<cv::dnn::dnn4_v20241223::SplitLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "SplitLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SplitLayer>()).
    define_attr("outputs_count", &cv::dnn::dnn4_v20241223::SplitLayer::outputsCount).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SplitLayer::create,
      Arg("params"));
  
  rb_cCvDnnSliceLayer = define_class_under<cv::dnn::dnn4_v20241223::SliceLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "SliceLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SliceLayer>()).
    define_attr("slice_ranges", &cv::dnn::dnn4_v20241223::SliceLayer::sliceRanges).
    define_attr("slice_steps", &cv::dnn::dnn4_v20241223::SliceLayer::sliceSteps).
    define_attr("axis", &cv::dnn::dnn4_v20241223::SliceLayer::axis).
    define_attr("num_split", &cv::dnn::dnn4_v20241223::SliceLayer::num_split).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SliceLayer::create,
      Arg("params"));
  
  rb_cCvDnnPermuteLayer = define_class_under<cv::dnn::dnn4_v20241223::PermuteLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "PermuteLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PermuteLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::PermuteLayer::create,
      Arg("params"));
  
  rb_cCvDnnShuffleChannelLayer = define_class_under<cv::dnn::dnn4_v20241223::ShuffleChannelLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ShuffleChannelLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ShuffleChannelLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ShuffleChannelLayer::create,
      Arg("params")).
    define_attr("group", &cv::dnn::dnn4_v20241223::ShuffleChannelLayer::group);
  
  rb_cCvDnnPaddingLayer = define_class_under<cv::dnn::dnn4_v20241223::PaddingLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "PaddingLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PaddingLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::PaddingLayer::create,
      Arg("params"));
  
  rb_cCvDnnActivationLayer = define_class_under<cv::dnn::dnn4_v20241223::ActivationLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ActivationLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ActivationLayer>()).
    define_method<void(cv::dnn::dnn4_v20241223::ActivationLayer::*)(const float*, float*, int, ::size_t, int, int) const>("forward_slice", &cv::dnn::dnn4_v20241223::ActivationLayer::forwardSlice,
      Arg("src"), Arg("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1")).
    define_method<void(cv::dnn::dnn4_v20241223::ActivationLayer::*)(const int*, const int*, int*, int, ::size_t, int, int) const>("forward_slice", &cv::dnn::dnn4_v20241223::ActivationLayer::forwardSlice,
      Arg("src"), Arg("lut"), Arg("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1")).
    define_method<void(cv::dnn::dnn4_v20241223::ActivationLayer::*)(const int8_t*, const int8_t*, int8_t*, int, ::size_t, int, int) const>("forward_slice", &cv::dnn::dnn4_v20241223::ActivationLayer::forwardSlice,
      Arg("src"), Arg("lut"), Arg("dst"), Arg("len"), Arg("out_plane_size"), Arg("cn0"), Arg("cn1"));
  
  rb_cCvDnnReLULayer = define_class_under<cv::dnn::dnn4_v20241223::ReLULayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ReLULayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReLULayer>()).
    define_attr("negative_slope", &cv::dnn::dnn4_v20241223::ReLULayer::negativeSlope).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ReLULayer::create,
      Arg("params"));
  
  rb_cCvDnnReLU6Layer = define_class_under<cv::dnn::dnn4_v20241223::ReLU6Layer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ReLU6Layer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReLU6Layer>()).
    define_attr("min_value", &cv::dnn::dnn4_v20241223::ReLU6Layer::minValue).
    define_attr("max_value", &cv::dnn::dnn4_v20241223::ReLU6Layer::maxValue).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ReLU6Layer::create,
      Arg("params"));
  
  rb_cCvDnnChannelsPReLULayer = define_class_under<cv::dnn::dnn4_v20241223::ChannelsPReLULayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ChannelsPReLULayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ChannelsPReLULayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ChannelsPReLULayer::create,
      Arg("params"));
  
  rb_cCvDnnELULayer = define_class_under<cv::dnn::dnn4_v20241223::ELULayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ELULayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ELULayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::ELULayer::alpha).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ELULayer::create,
      Arg("params"));
  
  rb_cCvDnnTanHLayer = define_class_under<cv::dnn::dnn4_v20241223::TanHLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "TanHLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TanHLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::TanHLayer::create,
      Arg("params"));
  
  rb_cCvDnnSwishLayer = define_class_under<cv::dnn::dnn4_v20241223::SwishLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SwishLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SwishLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SwishLayer::create,
      Arg("params"));
  
  rb_cCvDnnMishLayer = define_class_under<cv::dnn::dnn4_v20241223::MishLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "MishLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::MishLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::MishLayer::create,
      Arg("params"));
  
  rb_cCvDnnSigmoidLayer = define_class_under<cv::dnn::dnn4_v20241223::SigmoidLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SigmoidLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SigmoidLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SigmoidLayer::create,
      Arg("params"));
  
  rb_cCvDnnBNLLLayer = define_class_under<cv::dnn::dnn4_v20241223::BNLLLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "BNLLLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BNLLLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::BNLLLayer::create,
      Arg("params"));
  
  rb_cCvDnnAbsLayer = define_class_under<cv::dnn::dnn4_v20241223::AbsLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "AbsLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AbsLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AbsLayer::create,
      Arg("params"));
  
  rb_cCvDnnPowerLayer = define_class_under<cv::dnn::dnn4_v20241223::PowerLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "PowerLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PowerLayer>()).
    define_attr("power", &cv::dnn::dnn4_v20241223::PowerLayer::power).
    define_attr("scale", &cv::dnn::dnn4_v20241223::PowerLayer::scale).
    define_attr("shift", &cv::dnn::dnn4_v20241223::PowerLayer::shift).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::PowerLayer::create,
      Arg("params"));
  
  rb_cCvDnnExpLayer = define_class_under<cv::dnn::dnn4_v20241223::ExpLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ExpLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ExpLayer>()).
    define_attr("base", &cv::dnn::dnn4_v20241223::ExpLayer::base).
    define_attr("scale", &cv::dnn::dnn4_v20241223::ExpLayer::scale).
    define_attr("shift", &cv::dnn::dnn4_v20241223::ExpLayer::shift).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ExpLayer::create,
      Arg("params"));
  
  rb_cCvDnnCeilLayer = define_class_under<cv::dnn::dnn4_v20241223::CeilLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "CeilLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CeilLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CeilLayer::create,
      Arg("params"));
  
  rb_cCvDnnFloorLayer = define_class_under<cv::dnn::dnn4_v20241223::FloorLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "FloorLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::FloorLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::FloorLayer::create,
      Arg("params"));
  
  rb_cCvDnnLogLayer = define_class_under<cv::dnn::dnn4_v20241223::LogLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "LogLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::LogLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::LogLayer::create,
      Arg("params"));
  
  rb_cCvDnnRoundLayer = define_class_under<cv::dnn::dnn4_v20241223::RoundLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "RoundLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::RoundLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::RoundLayer::create,
      Arg("params"));
  
  rb_cCvDnnSqrtLayer = define_class_under<cv::dnn::dnn4_v20241223::SqrtLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SqrtLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SqrtLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SqrtLayer::create,
      Arg("params"));
  
  rb_cCvDnnNotLayer = define_class_under<cv::dnn::dnn4_v20241223::NotLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "NotLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::NotLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::NotLayer::create,
      Arg("params"));
  
  rb_cCvDnnAcosLayer = define_class_under<cv::dnn::dnn4_v20241223::AcosLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "AcosLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AcosLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AcosLayer::create,
      Arg("params"));
  
  rb_cCvDnnAcoshLayer = define_class_under<cv::dnn::dnn4_v20241223::AcoshLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "AcoshLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AcoshLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AcoshLayer::create,
      Arg("params"));
  
  rb_cCvDnnAsinLayer = define_class_under<cv::dnn::dnn4_v20241223::AsinLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "AsinLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AsinLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AsinLayer::create,
      Arg("params"));
  
  rb_cCvDnnAsinhLayer = define_class_under<cv::dnn::dnn4_v20241223::AsinhLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "AsinhLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AsinhLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AsinhLayer::create,
      Arg("params"));
  
  rb_cCvDnnAtanLayer = define_class_under<cv::dnn::dnn4_v20241223::AtanLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "AtanLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AtanLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AtanLayer::create,
      Arg("params"));
  
  rb_cCvDnnAtanhLayer = define_class_under<cv::dnn::dnn4_v20241223::AtanhLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "AtanhLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AtanhLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AtanhLayer::create,
      Arg("params"));
  
  rb_cCvDnnCosLayer = define_class_under<cv::dnn::dnn4_v20241223::CosLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "CosLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CosLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CosLayer::create,
      Arg("params"));
  
  rb_cCvDnnCoshLayer = define_class_under<cv::dnn::dnn4_v20241223::CoshLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "CoshLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CoshLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CoshLayer::create,
      Arg("params"));
  
  rb_cCvDnnErfLayer = define_class_under<cv::dnn::dnn4_v20241223::ErfLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ErfLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ErfLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ErfLayer::create,
      Arg("params"));
  
  rb_cCvDnnHardSwishLayer = define_class_under<cv::dnn::dnn4_v20241223::HardSwishLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "HardSwishLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::HardSwishLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::HardSwishLayer::create,
      Arg("params"));
  
  rb_cCvDnnSinLayer = define_class_under<cv::dnn::dnn4_v20241223::SinLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SinLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SinLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SinLayer::create,
      Arg("params"));
  
  rb_cCvDnnSinhLayer = define_class_under<cv::dnn::dnn4_v20241223::SinhLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SinhLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SinhLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SinhLayer::create,
      Arg("params"));
  
  rb_cCvDnnSoftplusLayer = define_class_under<cv::dnn::dnn4_v20241223::SoftplusLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SoftplusLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SoftplusLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SoftplusLayer::create,
      Arg("params"));
  
  rb_cCvDnnSoftsignLayer = define_class_under<cv::dnn::dnn4_v20241223::SoftsignLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SoftsignLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SoftsignLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SoftsignLayer::create,
      Arg("params"));
  
  rb_cCvDnnTanLayer = define_class_under<cv::dnn::dnn4_v20241223::TanLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "TanLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TanLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::TanLayer::create,
      Arg("params"));
  
  rb_cCvDnnCeluLayer = define_class_under<cv::dnn::dnn4_v20241223::CeluLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "CeluLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CeluLayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::CeluLayer::alpha).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CeluLayer::create,
      Arg("params"));
  
  rb_cCvDnnHardSigmoidLayer = define_class_under<cv::dnn::dnn4_v20241223::HardSigmoidLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "HardSigmoidLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::HardSigmoidLayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::HardSigmoidLayer::alpha).
    define_attr("beta", &cv::dnn::dnn4_v20241223::HardSigmoidLayer::beta).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::HardSigmoidLayer::create,
      Arg("params"));
  
  rb_cCvDnnSeluLayer = define_class_under<cv::dnn::dnn4_v20241223::SeluLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SeluLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SeluLayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::SeluLayer::alpha).
    define_attr("gamma", &cv::dnn::dnn4_v20241223::SeluLayer::gamma).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SeluLayer::create,
      Arg("params"));
  
  rb_cCvDnnGeluLayer = define_class_under<cv::dnn::dnn4_v20241223::GeluLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "GeluLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GeluLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::GeluLayer::create,
      Arg("params"));
  
  rb_cCvDnnGeluApproximationLayer = define_class_under<cv::dnn::dnn4_v20241223::GeluApproximationLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "GeluApproximationLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GeluApproximationLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::GeluApproximationLayer::create,
      Arg("params"));
  
  rb_cCvDnnThresholdedReluLayer = define_class_under<cv::dnn::dnn4_v20241223::ThresholdedReluLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ThresholdedReluLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ThresholdedReluLayer>()).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::ThresholdedReluLayer::alpha).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ThresholdedReluLayer::create,
      Arg("params"));
  
  rb_cCvDnnActivationLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::ActivationLayerInt8, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ActivationLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ActivationLayerInt8>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ActivationLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnSignLayer = define_class_under<cv::dnn::dnn4_v20241223::SignLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "SignLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SignLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SignLayer::create,
      Arg("params"));
  
  rb_cCvDnnShrinkLayer = define_class_under<cv::dnn::dnn4_v20241223::ShrinkLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ShrinkLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ShrinkLayer>()).
    define_attr("bias", &cv::dnn::dnn4_v20241223::ShrinkLayer::bias).
    define_attr("lambd", &cv::dnn::dnn4_v20241223::ShrinkLayer::lambd).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ShrinkLayer::create,
      Arg("params"));
  
  rb_cCvDnnReciprocalLayer = define_class_under<cv::dnn::dnn4_v20241223::ReciprocalLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "ReciprocalLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReciprocalLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ReciprocalLayer::create,
      Arg("params"));
  
  rb_cCvDnnCropLayer = define_class_under<cv::dnn::dnn4_v20241223::CropLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "CropLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CropLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CropLayer::create,
      Arg("params"));
  
  rb_cCvDnnEltwiseLayer = define_class_under<cv::dnn::dnn4_v20241223::EltwiseLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "EltwiseLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::EltwiseLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::EltwiseLayer::create,
      Arg("params"));
  
  rb_cCvDnnEltwiseLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::EltwiseLayerInt8, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "EltwiseLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::EltwiseLayerInt8>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::EltwiseLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnNaryEltwiseLayer = define_class_under<cv::dnn::dnn4_v20241223::NaryEltwiseLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "NaryEltwiseLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::NaryEltwiseLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::NaryEltwiseLayer::create,
      Arg("params"));
  
  rb_cCvDnnBatchNormLayer = define_class_under<cv::dnn::dnn4_v20241223::BatchNormLayer, cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnn, "BatchNormLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BatchNormLayer>()).
    define_attr("has_weights", &cv::dnn::dnn4_v20241223::BatchNormLayer::hasWeights).
    define_attr("has_bias", &cv::dnn::dnn4_v20241223::BatchNormLayer::hasBias).
    define_attr("epsilon", &cv::dnn::dnn4_v20241223::BatchNormLayer::epsilon).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::BatchNormLayer::create,
      Arg("params"));
  
  rb_cCvDnnBatchNormLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::BatchNormLayerInt8, cv::dnn::dnn4_v20241223::BatchNormLayer>(rb_mCvDnn, "BatchNormLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::BatchNormLayerInt8>()).
    define_attr("input_sc", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::input_sc).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::output_sc).
    define_attr("input_zp", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::input_zp).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::output_zp).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::BatchNormLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnMaxUnpoolLayer = define_class_under<cv::dnn::dnn4_v20241223::MaxUnpoolLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "MaxUnpoolLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::MaxUnpoolLayer>()).
    define_attr("pool_kernel", &cv::dnn::dnn4_v20241223::MaxUnpoolLayer::poolKernel).
    define_attr("pool_pad", &cv::dnn::dnn4_v20241223::MaxUnpoolLayer::poolPad).
    define_attr("pool_stride", &cv::dnn::dnn4_v20241223::MaxUnpoolLayer::poolStride).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::MaxUnpoolLayer::create,
      Arg("params"));
  
  rb_cCvDnnScaleLayer = define_class_under<cv::dnn::dnn4_v20241223::ScaleLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ScaleLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ScaleLayer>()).
    define_attr("has_bias", &cv::dnn::dnn4_v20241223::ScaleLayer::hasBias).
    define_attr("axis", &cv::dnn::dnn4_v20241223::ScaleLayer::axis).
    define_attr("mode", &cv::dnn::dnn4_v20241223::ScaleLayer::mode).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ScaleLayer::create,
      Arg("params"));
  
  rb_cCvDnnScaleLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::ScaleLayerInt8, cv::dnn::dnn4_v20241223::ScaleLayer>(rb_mCvDnn, "ScaleLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ScaleLayerInt8>()).
    define_attr("output_sc", &cv::dnn::dnn4_v20241223::ScaleLayerInt8::output_sc).
    define_attr("output_zp", &cv::dnn::dnn4_v20241223::ScaleLayerInt8::output_zp).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ScaleLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnShiftLayer = define_class_under<cv::dnn::dnn4_v20241223::ShiftLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ShiftLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ShiftLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ShiftLayer::create,
      Arg("params"));
  
  rb_cCvDnnShiftLayerInt8 = define_class_under<cv::dnn::dnn4_v20241223::ShiftLayerInt8, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ShiftLayerInt8").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ShiftLayerInt8>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ShiftLayerInt8::create,
      Arg("params"));
  
  rb_cCvDnnCompareLayer = define_class_under<cv::dnn::dnn4_v20241223::CompareLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "CompareLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CompareLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CompareLayer::create,
      Arg("params"));
  
  rb_cCvDnnDataAugmentationLayer = define_class_under<cv::dnn::dnn4_v20241223::DataAugmentationLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "DataAugmentationLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DataAugmentationLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::DataAugmentationLayer::create,
      Arg("params"));
  
  rb_cCvDnnCorrelationLayer = define_class_under<cv::dnn::dnn4_v20241223::CorrelationLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "CorrelationLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CorrelationLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CorrelationLayer::create,
      Arg("params"));
  
  rb_cCvDnnAccumLayer = define_class_under<cv::dnn::dnn4_v20241223::AccumLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "AccumLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AccumLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AccumLayer::create,
      Arg("params"));
  
  rb_cCvDnnFlowWarpLayer = define_class_under<cv::dnn::dnn4_v20241223::FlowWarpLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "FlowWarpLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::FlowWarpLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::FlowWarpLayer::create,
      Arg("params"));
  
  rb_cCvDnnPriorBoxLayer = define_class_under<cv::dnn::dnn4_v20241223::PriorBoxLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "PriorBoxLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::PriorBoxLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::PriorBoxLayer::create,
      Arg("params"));
  
  rb_cCvDnnReorgLayer = define_class_under<cv::dnn::dnn4_v20241223::ReorgLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ReorgLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ReorgLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ReorgLayer::create,
      Arg("params"));
  
  rb_cCvDnnRegionLayer = define_class_under<cv::dnn::dnn4_v20241223::RegionLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "RegionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::RegionLayer>()).
    define_attr("nms_threshold", &cv::dnn::dnn4_v20241223::RegionLayer::nmsThreshold).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::RegionLayer::create,
      Arg("params"));
  
  rb_cCvDnnDetectionOutputLayer = define_class_under<cv::dnn::dnn4_v20241223::DetectionOutputLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "DetectionOutputLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DetectionOutputLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::DetectionOutputLayer::create,
      Arg("params"));
  
  rb_cCvDnnNormalizeBBoxLayer = define_class_under<cv::dnn::dnn4_v20241223::NormalizeBBoxLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "NormalizeBBoxLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::NormalizeBBoxLayer>()).
    define_attr("pnorm", &cv::dnn::dnn4_v20241223::NormalizeBBoxLayer::pnorm).
    define_attr("epsilon", &cv::dnn::dnn4_v20241223::NormalizeBBoxLayer::epsilon).
    define_attr("across_spatial", &cv::dnn::dnn4_v20241223::NormalizeBBoxLayer::acrossSpatial).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::NormalizeBBoxLayer::create,
      Arg("params"));
  
  rb_cCvDnnResizeLayer = define_class_under<cv::dnn::dnn4_v20241223::ResizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ResizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ResizeLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ResizeLayer::create,
      Arg("params"));
  
  rb_cCvDnnInterpLayer = define_class_under<cv::dnn::dnn4_v20241223::InterpLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "InterpLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::InterpLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::InterpLayer::create,
      Arg("params"));
  
  rb_cCvDnnProposalLayer = define_class_under<cv::dnn::dnn4_v20241223::ProposalLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ProposalLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ProposalLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ProposalLayer::create,
      Arg("params"));
  
  rb_cCvDnnCropAndResizeLayer = define_class_under<cv::dnn::dnn4_v20241223::CropAndResizeLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "CropAndResizeLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CropAndResizeLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CropAndResizeLayer::create,
      Arg("params"));
  
  rb_cCvDnnCumSumLayer = define_class_under<cv::dnn::dnn4_v20241223::CumSumLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "CumSumLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::CumSumLayer>()).
    define_attr("exclusive", &cv::dnn::dnn4_v20241223::CumSumLayer::exclusive).
    define_attr("reverse", &cv::dnn::dnn4_v20241223::CumSumLayer::reverse).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::CumSumLayer::create,
      Arg("params"));
  
  rb_cCvDnnScatterLayer = define_class_under<cv::dnn::dnn4_v20241223::ScatterLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ScatterLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ScatterLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ScatterLayer::create,
      Arg("params"));
  
  rb_cCvDnnScatterNDLayer = define_class_under<cv::dnn::dnn4_v20241223::ScatterNDLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ScatterNDLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ScatterNDLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ScatterNDLayer::create,
      Arg("params"));
  
  rb_cCvDnnTileLayer = define_class_under<cv::dnn::dnn4_v20241223::TileLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "TileLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TileLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::TileLayer::create,
      Arg("params"));
  
  rb_cCvDnnLayerNormLayer = define_class_under<cv::dnn::dnn4_v20241223::LayerNormLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "LayerNormLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::LayerNormLayer>()).
    define_attr("has_bias", &cv::dnn::dnn4_v20241223::LayerNormLayer::hasBias).
    define_attr("axis", &cv::dnn::dnn4_v20241223::LayerNormLayer::axis).
    define_attr("epsilon", &cv::dnn::dnn4_v20241223::LayerNormLayer::epsilon).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::LayerNormLayer::create,
      Arg("params"));
  
  rb_cCvDnnGemmLayer = define_class_under<cv::dnn::dnn4_v20241223::GemmLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "GemmLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GemmLayer>()).
    define_attr("trans_a", &cv::dnn::dnn4_v20241223::GemmLayer::trans_a).
    define_attr("trans_b", &cv::dnn::dnn4_v20241223::GemmLayer::trans_b).
    define_attr("alpha", &cv::dnn::dnn4_v20241223::GemmLayer::alpha).
    define_attr("beta", &cv::dnn::dnn4_v20241223::GemmLayer::beta).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::GemmLayer::create,
      Arg("params"));
  
  rb_cCvDnnMatMulLayer = define_class_under<cv::dnn::dnn4_v20241223::MatMulLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "MatMulLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::MatMulLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::MatMulLayer::create,
      Arg("params"));
  
  rb_cCvDnnExpandLayer = define_class_under<cv::dnn::dnn4_v20241223::ExpandLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "ExpandLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ExpandLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::ExpandLayer::create,
      Arg("params"));
  
  rb_cCvDnnInstanceNormLayer = define_class_under<cv::dnn::dnn4_v20241223::InstanceNormLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "InstanceNormLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::InstanceNormLayer>()).
    define_attr("epsilon", &cv::dnn::dnn4_v20241223::InstanceNormLayer::epsilon).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::InstanceNormLayer::create,
      Arg("params"));
  
  rb_cCvDnnAttentionLayer = define_class_under<cv::dnn::dnn4_v20241223::AttentionLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "AttentionLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::AttentionLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::AttentionLayer::create,
      Arg("params"));
  
  rb_cCvDnnGroupNormLayer = define_class_under<cv::dnn::dnn4_v20241223::GroupNormLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "GroupNormLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::GroupNormLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::GroupNormLayer::create,
      Arg("params"));
  
  rb_cCvDnnDepthToSpaceLayer = define_class_under<cv::dnn::dnn4_v20241223::DepthToSpaceLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "DepthToSpaceLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DepthToSpaceLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::DepthToSpaceLayer::create,
      Arg("params"));
  
  rb_cCvDnnSpaceToDepthLayer = define_class_under<cv::dnn::dnn4_v20241223::SpaceToDepthLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "SpaceToDepthLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SpaceToDepthLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::SpaceToDepthLayer::create,
      Arg("params"));
  
  rb_cCvDnnTopKLayer = define_class_under<cv::dnn::dnn4_v20241223::TopKLayer, cv::dnn::dnn4_v20241223::Layer>(rb_mCvDnn, "TopKLayer").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TopKLayer>()).
    define_singleton_function("create", &cv::dnn::dnn4_v20241223::TopKLayer::create,
      Arg("params"));
}