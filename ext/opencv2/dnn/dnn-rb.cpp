#include <opencv2/dnn/dnn.hpp>
#include "dnn-rb.hpp"

using namespace Rice;

void Init_Dnn_Dnn()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Module rb_mCvDnnAccessor = define_module_under(rb_mCvDnn, "Accessor");

  Rice::Data_Type<cv::dnn::accessor::DnnNetAccessor> rb_cCvDnnAccessorDnnNetAccessor = define_class_under<cv::dnn::accessor::DnnNetAccessor>(rb_mCvDnnAccessor, "DnnNetAccessor");

  Enum<cv::dnn::Backend> rb_cCvDnnBackend = define_enum_under<cv::dnn::Backend>("Backend", rb_mCvDnn).
    define_value("DNN_BACKEND_DEFAULT", cv::dnn::Backend::DNN_BACKEND_DEFAULT).
    define_value("DNN_BACKEND_HALIDE", cv::dnn::Backend::DNN_BACKEND_HALIDE).
    define_value("DNN_BACKEND_INFERENCE_ENGINE", cv::dnn::Backend::DNN_BACKEND_INFERENCE_ENGINE).
    define_value("DNN_BACKEND_OPENCV", cv::dnn::Backend::DNN_BACKEND_OPENCV).
    define_value("DNN_BACKEND_VKCOM", cv::dnn::Backend::DNN_BACKEND_VKCOM).
    define_value("DNN_BACKEND_CUDA", cv::dnn::Backend::DNN_BACKEND_CUDA).
    define_value("DNN_BACKEND_WEBNN", cv::dnn::Backend::DNN_BACKEND_WEBNN).
    define_value("DNN_BACKEND_TIMVX", cv::dnn::Backend::DNN_BACKEND_TIMVX).
    define_value("DNN_BACKEND_CANN", cv::dnn::Backend::DNN_BACKEND_CANN);

  Enum<cv::dnn::Target> rb_cCvDnnTarget = define_enum_under<cv::dnn::Target>("Target", rb_mCvDnn).
    define_value("DNN_TARGET_CPU", cv::dnn::Target::DNN_TARGET_CPU).
    define_value("DNN_TARGET_OPENCL", cv::dnn::Target::DNN_TARGET_OPENCL).
    define_value("DNN_TARGET_OPENCL_FP16", cv::dnn::Target::DNN_TARGET_OPENCL_FP16).
    define_value("DNN_TARGET_MYRIAD", cv::dnn::Target::DNN_TARGET_MYRIAD).
    define_value("DNN_TARGET_VULKAN", cv::dnn::Target::DNN_TARGET_VULKAN).
    define_value("DNN_TARGET_FPGA", cv::dnn::Target::DNN_TARGET_FPGA).
    define_value("DNN_TARGET_CUDA", cv::dnn::Target::DNN_TARGET_CUDA).
    define_value("DNN_TARGET_CUDA_FP16", cv::dnn::Target::DNN_TARGET_CUDA_FP16).
    define_value("DNN_TARGET_HDDL", cv::dnn::Target::DNN_TARGET_HDDL).
    define_value("DNN_TARGET_NPU", cv::dnn::Target::DNN_TARGET_NPU).
    define_value("DNN_TARGET_CPU_FP16", cv::dnn::Target::DNN_TARGET_CPU_FP16);

  Enum<cv::dnn::DataLayout> rb_cCvDnnDataLayout = define_enum_under<cv::dnn::DataLayout>("DataLayout", rb_mCvDnn).
    define_value("DNN_LAYOUT_UNKNOWN", cv::dnn::DataLayout::DNN_LAYOUT_UNKNOWN).
    define_value("DNN_LAYOUT_ND", cv::dnn::DataLayout::DNN_LAYOUT_ND).
    define_value("DNN_LAYOUT_NCHW", cv::dnn::DataLayout::DNN_LAYOUT_NCHW).
    define_value("DNN_LAYOUT_NCDHW", cv::dnn::DataLayout::DNN_LAYOUT_NCDHW).
    define_value("DNN_LAYOUT_NHWC", cv::dnn::DataLayout::DNN_LAYOUT_NHWC).
    define_value("DNN_LAYOUT_NDHWC", cv::dnn::DataLayout::DNN_LAYOUT_NDHWC).
    define_value("DNN_LAYOUT_PLANAR", cv::dnn::DataLayout::DNN_LAYOUT_PLANAR);

  rb_mCvDnn.define_module_function("get_available_backends", &cv::dnn::getAvailableBackends);

  rb_mCvDnn.define_module_function("get_available_targets", &cv::dnn::getAvailableTargets,
    Arg("be"));

  rb_mCvDnn.define_module_function("enable_model_diagnostics", &cv::dnn::enableModelDiagnostics,
    Arg("is_diagnostics_mode"));

  Rice::Data_Type<cv::dnn::LayerParams> rb_cCvDnnLayerParams = define_class_under<cv::dnn::LayerParams, cv::dnn::Dict>(rb_mCvDnn, "LayerParams").
    define_constructor(Constructor<cv::dnn::LayerParams>()).
    define_attr("blobs", &cv::dnn::LayerParams::blobs).
    define_attr("name", &cv::dnn::LayerParams::name).
    define_attr("type", &cv::dnn::LayerParams::type);

  // TODO - Not exported by OpenCV on Windows
  // Rice::Data_Type<cv::dnn::BackendNode> rb_cCvDnnBackendNode = define_class_under<cv::dnn::BackendNode>(rb_mCvDnn, "BackendNode").
  // define_constructor(Constructor<cv::dnn::BackendNode, int>(),
  //   Arg("backend_id")).
  // define_attr("backend_id", &cv::dnn::BackendNode::backendId);

  Rice::Data_Type<cv::dnn::BackendWrapper> rb_cCvDnnBackendWrapper = define_class_under<cv::dnn::BackendWrapper>(rb_mCvDnn, "BackendWrapper").
    define_method("copy_to_host", &cv::dnn::BackendWrapper::copyToHost).
    define_method("set_host_dirty", &cv::dnn::BackendWrapper::setHostDirty).
    define_attr("backend_id", &cv::dnn::BackendWrapper::backendId).
    define_attr("target_id", &cv::dnn::BackendWrapper::targetId);

  Rice::Data_Type<cv::dnn::ActivationLayer> rb_cCvDnnActivationLayer = define_class_under<cv::dnn::ActivationLayer>(rb_mCvDnn, "ActivationLayer");

  Rice::Data_Type<cv::dnn::Layer> rb_cCvDnnLayer = define_class_under<cv::dnn::Layer, cv::Algorithm>(rb_mCvDnn, "Layer").
    define_attr("blobs", &cv::dnn::Layer::blobs).
    define_method<void(cv::dnn::Layer::*)(cv::InputArrayOfArrays, cv::OutputArrayOfArrays)>("finalize", &cv::dnn::Layer::finalize,
      Arg("inputs"), Arg("outputs")).
    define_method<void(cv::dnn::Layer::*)(cv::InputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays)>("forward", &cv::dnn::Layer::forward,
      Arg("inputs"), Arg("outputs"), Arg("internals")).
    define_method("try_quantize", &cv::dnn::Layer::tryQuantize,
      Arg("scales"), Arg("zeropoints"), Arg("params")).
    define_method("forward_fallback", &cv::dnn::Layer::forward_fallback,
      Arg("inputs"), Arg("outputs"), Arg("internals")).
    define_method("input_name_to_index", &cv::dnn::Layer::inputNameToIndex,
      Arg("input_name")).
    define_method("output_name_to_index", &cv::dnn::Layer::outputNameToIndex,
      Arg("output_name")).
    define_method("support_backend", &cv::dnn::Layer::supportBackend,
      Arg("backend_id")).
    // Skipped: init* methods use Ptr<BackendNode> which isn't exported
    define_method("set_activation", &cv::dnn::Layer::setActivation,
      Arg("layer")).
    define_method("try_fuse", &cv::dnn::Layer::tryFuse,
      Arg("top")).
    define_method("get_scale_shift", &cv::dnn::Layer::getScaleShift,
      Arg("scale"), Arg("shift")).
    define_method("get_scale_zeropoint", &cv::dnn::Layer::getScaleZeropoint,
      Arg("scale"), Arg("zeropoint")).
    define_method("unset_attached", &cv::dnn::Layer::unsetAttached).
    define_method("get_memory_shapes", &cv::dnn::Layer::getMemoryShapes,
      Arg("inputs"), Arg("required_outputs"), Arg("outputs"), Arg("internals")).
    define_method("get_flops", &cv::dnn::Layer::getFLOPS,
      Arg("inputs"), Arg("outputs")).
    define_method("update_memory_shapes", &cv::dnn::Layer::updateMemoryShapes,
      Arg("inputs")).
    define_attr("name", &cv::dnn::Layer::name).
    define_attr("type", &cv::dnn::Layer::type).
    define_attr("preferable_target", &cv::dnn::Layer::preferableTarget).
    define_constructor(Constructor<cv::dnn::Layer>()).
    define_constructor(Constructor<cv::dnn::Layer, const cv::dnn::LayerParams&>(),
      Arg("params")).
    define_method("set_params_from", &cv::dnn::Layer::setParamsFrom,
      Arg("params"));

  Rice::Data_Type<cv::dnn::Net> rb_cCvDnnNet = define_class_under<cv::dnn::Net>(rb_mCvDnn, "Net");

  Rice::Data_Type<cv::dnn::Net::Impl> rb_cCvDnnNetImpl = define_class_under<cv::dnn::Net::Impl>(rb_cCvDnnNet, "Impl");

  rb_cCvDnnNet.
    define_constructor(Constructor<cv::dnn::Net>()).
    define_method("empty?", &cv::dnn::Net::empty).
    define_method("dump", &cv::dnn::Net::dump).
    define_method("dump_to_file", &cv::dnn::Net::dumpToFile,
      Arg("path")).
    define_method("dump_to_pbtxt", &cv::dnn::Net::dumpToPbtxt,
      Arg("path")).
    define_method<int(cv::dnn::Net::*)(const cv::String&, const cv::String&, const int&, cv::dnn::LayerParams&)>("add_layer", &cv::dnn::Net::addLayer,
      Arg("name"), Arg("type"), Arg("dtype"), Arg("params")).
    define_method<int(cv::dnn::Net::*)(const cv::String&, const cv::String&, cv::dnn::LayerParams&)>("add_layer", &cv::dnn::Net::addLayer,
      Arg("name"), Arg("type"), Arg("params")).
    define_method<int(cv::dnn::Net::*)(const cv::String&, const cv::String&, const int&, cv::dnn::LayerParams&)>("add_layer_to_prev", &cv::dnn::Net::addLayerToPrev,
      Arg("name"), Arg("type"), Arg("dtype"), Arg("params")).
    define_method<int(cv::dnn::Net::*)(const cv::String&, const cv::String&, cv::dnn::LayerParams&)>("add_layer_to_prev", &cv::dnn::Net::addLayerToPrev,
      Arg("name"), Arg("type"), Arg("params")).
    define_method("get_layer_id", &cv::dnn::Net::getLayerId,
      Arg("layer")).
    define_method("get_layer_names", &cv::dnn::Net::getLayerNames).
    define_method<cv::Ptr<cv::dnn::Layer>(cv::dnn::Net::*)(int) const>("get_layer", &cv::dnn::Net::getLayer,
      Arg("layer_id")).
    define_method<cv::Ptr<cv::dnn::Layer>(cv::dnn::Net::*)(const cv::String&) const>("get_layer", &cv::dnn::Net::getLayer,
      Arg("layer_name")).
    define_method<cv::Ptr<cv::dnn::Layer>(cv::dnn::Net::*)(const cv::dnn::Net::LayerId&) const>("get_layer", &cv::dnn::Net::getLayer,
      Arg("layer_id")).
    define_method("get_layer_inputs", &cv::dnn::Net::getLayerInputs,
      Arg("layer_id")).
    define_method<void(cv::dnn::Net::*)(cv::String, cv::String)>("connect", &cv::dnn::Net::connect,
      Arg("out_pin"), Arg("inp_pin")).
    define_method<void(cv::dnn::Net::*)(int, int, int, int)>("connect", &cv::dnn::Net::connect,
      Arg("out_layer_id"), Arg("out_num"), Arg("inp_layer_id"), Arg("inp_num")).
    define_method("register_output", &cv::dnn::Net::registerOutput,
      Arg("output_name"), Arg("layer_id"), Arg("output_port")).
    define_method("set_inputs_names", &cv::dnn::Net::setInputsNames,
      Arg("input_blob_names")).
    define_method("set_input_shape", &cv::dnn::Net::setInputShape,
      Arg("input_name"), Arg("shape")).
    define_method<cv::Mat(cv::dnn::Net::*)(const cv::String&)>("forward", &cv::dnn::Net::forward,
      Arg("output_name") = static_cast<const cv::String&>(cv::String())).
    define_method("forward_async", &cv::dnn::Net::forwardAsync,
      Arg("output_name") = static_cast<const cv::String&>(cv::String())).
    define_method<void(cv::dnn::Net::*)(cv::OutputArrayOfArrays, const cv::String&)>("forward", &cv::dnn::Net::forward,
      Arg("output_blobs"), Arg("output_name") = static_cast<const cv::String&>(cv::String())).
    define_method<void(cv::dnn::Net::*)(cv::OutputArrayOfArrays, const std::vector<std::basic_string<char>>&)>("forward", &cv::dnn::Net::forward,
      Arg("output_blobs"), Arg("out_blob_names")).
    define_method<void(cv::dnn::Net::*)(std::vector<std::vector<cv::Mat>>&, const std::vector<std::basic_string<char>>&)>("forward", &cv::dnn::Net::forward,
      Arg("output_blobs"), Arg("out_blob_names")).
    define_method("quantize", &cv::dnn::Net::quantize,
      Arg("calib_data"), Arg("inputs_dtype"), Arg("outputs_dtype"), Arg("per_channel") = static_cast<bool>(true)).
    define_method("get_input_details", &cv::dnn::Net::getInputDetails,
      Arg("scales"), Arg("zeropoints")).
    define_method("get_output_details", &cv::dnn::Net::getOutputDetails,
      Arg("scales"), Arg("zeropoints")).
    define_method("set_halide_scheduler", &cv::dnn::Net::setHalideScheduler,
      Arg("scheduler")).
    define_method("set_preferable_backend", &cv::dnn::Net::setPreferableBackend,
      Arg("backend_id")).
    define_method("set_preferable_target", &cv::dnn::Net::setPreferableTarget,
      Arg("target_id")).
    define_method("set_input", &cv::dnn::Net::setInput,
      Arg("blob"), Arg("name") = static_cast<const cv::String&>(""), Arg("scalefactor") = static_cast<double>(1.0), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar())).
    define_method<void(cv::dnn::Net::*)(int, int, const cv::Mat&)>("set_param", &cv::dnn::Net::setParam,
      Arg("layer"), Arg("num_param"), Arg("blob")).
    define_method<void(cv::dnn::Net::*)(const cv::String&, int, const cv::Mat&)>("set_param", &cv::dnn::Net::setParam,
      Arg("layer_name"), Arg("num_param"), Arg("blob")).
    define_method<cv::Mat(cv::dnn::Net::*)(int, int) const>("get_param", &cv::dnn::Net::getParam,
      Arg("layer"), Arg("num_param") = static_cast<int>(0)).
    define_method<cv::Mat(cv::dnn::Net::*)(const cv::String&, int) const>("get_param", &cv::dnn::Net::getParam,
      Arg("layer_name"), Arg("num_param") = static_cast<int>(0)).
    define_method("get_unconnected_out_layers", &cv::dnn::Net::getUnconnectedOutLayers).
    define_method("get_unconnected_out_layers_names", &cv::dnn::Net::getUnconnectedOutLayersNames).
    define_method<void(cv::dnn::Net::*)(const std::vector<std::vector<int>>&, std::vector<int>&, std::vector<std::vector<std::vector<int>>>&, std::vector<std::vector<std::vector<int>>>&) const>("get_layers_shapes", &cv::dnn::Net::getLayersShapes,
      Arg("net_input_shapes"), Arg("layers_ids"), Arg("in_layers_shapes"), Arg("out_layers_shapes")).
    define_method<void(cv::dnn::Net::*)(const cv::dnn::MatShape&, std::vector<int>&, std::vector<std::vector<std::vector<int>>>&, std::vector<std::vector<std::vector<int>>>&) const>("get_layers_shapes", &cv::dnn::Net::getLayersShapes,
      Arg("net_input_shape"), Arg("layers_ids"), Arg("in_layers_shapes"), Arg("out_layers_shapes")).
    define_method<void(cv::dnn::Net::*)(const cv::dnn::MatShape&, const int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&) const>("get_layer_shapes", &cv::dnn::Net::getLayerShapes,
      Arg("net_input_shape"), Arg("layer_id"), Arg("in_layer_shapes"), Arg("out_layer_shapes")).
    define_method<void(cv::dnn::Net::*)(const std::vector<std::vector<int>>&, const int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&) const>("get_layer_shapes", &cv::dnn::Net::getLayerShapes,
      Arg("net_input_shapes"), Arg("layer_id"), Arg("in_layer_shapes"), Arg("out_layer_shapes")).
    define_method<int64(cv::dnn::Net::*)(const std::vector<std::vector<int>>&) const>("get_flops", &cv::dnn::Net::getFLOPS,
      Arg("net_input_shapes")).
    define_method<int64(cv::dnn::Net::*)(const cv::dnn::MatShape&) const>("get_flops", &cv::dnn::Net::getFLOPS,
      Arg("net_input_shape")).
    define_method<int64(cv::dnn::Net::*)(const int, const std::vector<std::vector<int>>&) const>("get_flops", &cv::dnn::Net::getFLOPS,
      Arg("layer_id"), Arg("net_input_shapes")).
    define_method<int64(cv::dnn::Net::*)(const int, const cv::dnn::MatShape&) const>("get_flops", &cv::dnn::Net::getFLOPS,
      Arg("layer_id"), Arg("net_input_shape")).
    define_method("get_layer_types", &cv::dnn::Net::getLayerTypes,
      Arg("layers_types")).
    define_method("get_layers_count", &cv::dnn::Net::getLayersCount,
      Arg("layer_type")).
    define_method<void(cv::dnn::Net::*)(const std::vector<std::vector<int>>&, size_t&, size_t&) const>("get_memory_consumption", &cv::dnn::Net::getMemoryConsumption,
      Arg("net_input_shapes"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::Net::*)(const cv::dnn::MatShape&, size_t&, size_t&) const>("get_memory_consumption", &cv::dnn::Net::getMemoryConsumption,
      Arg("net_input_shape"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::Net::*)(const int, const std::vector<std::vector<int>>&, size_t&, size_t&) const>("get_memory_consumption", &cv::dnn::Net::getMemoryConsumption,
      Arg("layer_id"), Arg("net_input_shapes"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::Net::*)(const int, const cv::dnn::MatShape&, size_t&, size_t&) const>("get_memory_consumption", &cv::dnn::Net::getMemoryConsumption,
      Arg("layer_id"), Arg("net_input_shape"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::Net::*)(const std::vector<std::vector<int>>&, std::vector<int>&, std::vector<size_t>&, std::vector<size_t>&) const>("get_memory_consumption", &cv::dnn::Net::getMemoryConsumption,
      Arg("net_input_shapes"), Arg("layer_ids"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::Net::*)(const cv::dnn::MatShape&, std::vector<int>&, std::vector<size_t>&, std::vector<size_t>&) const>("get_memory_consumption", &cv::dnn::Net::getMemoryConsumption,
      Arg("net_input_shape"), Arg("layer_ids"), Arg("weights"), Arg("blobs")).
    define_method("enable_fusion", &cv::dnn::Net::enableFusion,
      Arg("fusion")).
    define_method("enable_winograd", &cv::dnn::Net::enableWinograd,
      Arg("use_winograd")).
    define_method("get_perf_profile", &cv::dnn::Net::getPerfProfile,
      Arg("timings")).
    define_method("get_impl", &cv::dnn::Net::getImpl).
    define_method("get_impl_ref", &cv::dnn::Net::getImplRef).
    define_singleton_function<cv::dnn::Net(*)(const cv::String&, const cv::String&)>("read_from_model_optimizer", &cv::dnn::Net::readFromModelOptimizer,
      Arg("xml"), Arg("bin")).
    define_singleton_function<cv::dnn::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_from_model_optimizer", &cv::dnn::Net::readFromModelOptimizer,
      Arg("buffer_model_config"), Arg("buffer_weights")).
    define_singleton_function<cv::dnn::Net(*)(const uchar*, size_t, const uchar*, size_t)>("read_from_model_optimizer", &cv::dnn::Net::readFromModelOptimizer,
      Arg("buffer_model_config_ptr"), Arg("buffer_model_config_size"), Arg("buffer_weights_ptr"), Arg("buffer_weights_size"));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const cv::String&, const cv::String&)>("read_net_from_darknet", &cv::dnn::readNetFromDarknet,
    Arg("cfg_file"), Arg("darknet_model") = static_cast<const cv::String&>(cv::String()));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_net_from_darknet", &cv::dnn::readNetFromDarknet,
    Arg("buffer_cfg"), Arg("buffer_model") = static_cast<const std::vector<uchar>&>(std::vector<uchar>()));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const char*, size_t, const char*, size_t)>("read_net_from_darknet", &cv::dnn::readNetFromDarknet,
    Arg("buffer_cfg"), Arg("len_cfg"), Arg("buffer_model") = static_cast<const char*>(NULL), Arg("len_model") = static_cast<size_t>(0));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const cv::String&, const cv::String&)>("read_net_from_caffe", &cv::dnn::readNetFromCaffe,
    Arg("prototxt"), Arg("caffe_model") = static_cast<const cv::String&>(cv::String()));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_net_from_caffe", &cv::dnn::readNetFromCaffe,
    Arg("buffer_proto"), Arg("buffer_model") = static_cast<const std::vector<uchar>&>(std::vector<uchar>()));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const char*, size_t, const char*, size_t)>("read_net_from_caffe", &cv::dnn::readNetFromCaffe,
    Arg("buffer_proto"), Arg("len_proto"), Arg("buffer_model") = static_cast<const char*>(NULL), Arg("len_model") = static_cast<size_t>(0));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const cv::String&, const cv::String&)>("read_net_from_tensorflow", &cv::dnn::readNetFromTensorflow,
    Arg("model"), Arg("config") = static_cast<const cv::String&>(cv::String()));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_net_from_tensorflow", &cv::dnn::readNetFromTensorflow,
    Arg("buffer_model"), Arg("buffer_config") = static_cast<const std::vector<uchar>&>(std::vector<uchar>()));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const char*, size_t, const char*, size_t)>("read_net_from_tensorflow", &cv::dnn::readNetFromTensorflow,
    Arg("buffer_model"), Arg("len_model"), Arg("buffer_config") = static_cast<const char*>(NULL), Arg("len_config") = static_cast<size_t>(0));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const cv::String&)>("read_net_from_tf_lite", &cv::dnn::readNetFromTFLite,
    Arg("model"));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const std::vector<uchar>&)>("read_net_from_tf_lite", &cv::dnn::readNetFromTFLite,
    Arg("buffer_model"));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const char*, size_t)>("read_net_from_tf_lite", &cv::dnn::readNetFromTFLite,
    Arg("buffer_model"), Arg("len_model"));

  rb_mCvDnn.define_module_function("read_net_from_torch", &cv::dnn::readNetFromTorch,
    Arg("model"), Arg("is_binary") = static_cast<bool>(true), Arg("evaluate") = static_cast<bool>(true));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const cv::String&, const cv::String&, const cv::String&)>("read_net", &cv::dnn::readNet,
    Arg("model"), Arg("config") = static_cast<const cv::String&>(""), Arg("framework") = static_cast<const cv::String&>(""));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const cv::String&, const std::vector<uchar>&, const std::vector<uchar>&)>("read_net", &cv::dnn::readNet,
    Arg("framework"), Arg("buffer_model"), Arg("buffer_config") = static_cast<const std::vector<uchar>&>(std::vector<uchar>()));

  rb_mCvDnn.define_module_function("read_torch_blob", &cv::dnn::readTorchBlob,
    Arg("filename"), Arg("is_binary") = static_cast<bool>(true));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const cv::String&, const cv::String&)>("read_net_from_model_optimizer", &cv::dnn::readNetFromModelOptimizer,
    Arg("xml"), Arg("bin") = static_cast<const cv::String&>(""));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_net_from_model_optimizer", &cv::dnn::readNetFromModelOptimizer,
    Arg("buffer_model_config"), Arg("buffer_weights"));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const uchar*, size_t, const uchar*, size_t)>("read_net_from_model_optimizer", &cv::dnn::readNetFromModelOptimizer,
    Arg("buffer_model_config_ptr"), Arg("buffer_model_config_size"), Arg("buffer_weights_ptr"), Arg("buffer_weights_size"));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const cv::String&)>("read_net_from_onnx", &cv::dnn::readNetFromONNX,
    Arg("onnx_file"));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const char*, size_t)>("read_net_from_onnx", &cv::dnn::readNetFromONNX,
    Arg("buffer"), Arg("size_buffer"));

  rb_mCvDnn.define_module_function<cv::dnn::Net(*)(const std::vector<uchar>&)>("read_net_from_onnx", &cv::dnn::readNetFromONNX,
    Arg("buffer"));

  rb_mCvDnn.define_module_function("read_tensor_from_onnx", &cv::dnn::readTensorFromONNX,
    Arg("path"));

  rb_mCvDnn.define_module_function<cv::Mat(*)(cv::InputArray, double, const cv::Size&, const cv::Scalar&, bool, bool, int)>("blob_from_image", &cv::dnn::blobFromImage,
    Arg("image"), Arg("scalefactor") = static_cast<double>(1.0), Arg("size") = static_cast<const cv::Size&>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F));

  rb_mCvDnn.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, const cv::Size&, const cv::Scalar&, bool, bool, int)>("blob_from_image", &cv::dnn::blobFromImage,
    Arg("image"), Arg("blob"), Arg("scalefactor") = static_cast<double>(1.0), Arg("size") = static_cast<const cv::Size&>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F));

  rb_mCvDnn.define_module_function<cv::Mat(*)(cv::InputArrayOfArrays, double, cv::Size, const cv::Scalar&, bool, bool, int)>("blob_from_images", &cv::dnn::blobFromImages,
    Arg("images"), Arg("scalefactor") = static_cast<double>(1.0), Arg("size") = static_cast<cv::Size>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F));

  rb_mCvDnn.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, double, cv::Size, const cv::Scalar&, bool, bool, int)>("blob_from_images", &cv::dnn::blobFromImages,
    Arg("images"), Arg("blob"), Arg("scalefactor") = static_cast<double>(1.0), Arg("size") = static_cast<cv::Size>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F));

  Enum<cv::dnn::ImagePaddingMode> rb_cCvDnnImagePaddingMode = define_enum_under<cv::dnn::ImagePaddingMode>("ImagePaddingMode", rb_mCvDnn).
    define_value("DNN_PMODE_NULL", cv::dnn::ImagePaddingMode::DNN_PMODE_NULL).
    define_value("DNN_PMODE_CROP_CENTER", cv::dnn::ImagePaddingMode::DNN_PMODE_CROP_CENTER).
    define_value("DNN_PMODE_LETTERBOX", cv::dnn::ImagePaddingMode::DNN_PMODE_LETTERBOX);

  Rice::Data_Type<cv::dnn::Image2BlobParams> rb_cCvDnnImage2BlobParams = define_class_under<cv::dnn::Image2BlobParams>(rb_mCvDnn, "Image2BlobParams").
    define_constructor(Constructor<cv::dnn::Image2BlobParams>()).
    define_constructor(Constructor<cv::dnn::Image2BlobParams, const cv::Scalar&, const cv::Size&, const cv::Scalar&, bool, int, cv::dnn::DataLayout, cv::dnn::ImagePaddingMode, cv::Scalar>(),
      Arg("scalefactor"), Arg("size") = static_cast<const cv::Size&>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F), Arg("datalayout") = static_cast<cv::dnn::DataLayout>(cv::dnn::DNN_LAYOUT_NCHW), Arg("mode") = static_cast<cv::dnn::ImagePaddingMode>(cv::dnn::DNN_PMODE_NULL), Arg("border_value") = static_cast<cv::Scalar>(0.0)).
    define_attr("scalefactor", &cv::dnn::Image2BlobParams::scalefactor).
    define_attr("size", &cv::dnn::Image2BlobParams::size).
    define_attr("mean", &cv::dnn::Image2BlobParams::mean).
    define_attr("swap_rb", &cv::dnn::Image2BlobParams::swapRB).
    define_attr("ddepth", &cv::dnn::Image2BlobParams::ddepth).
    define_attr("datalayout", &cv::dnn::Image2BlobParams::datalayout).
    define_attr("paddingmode", &cv::dnn::Image2BlobParams::paddingmode).
    define_attr("border_value", &cv::dnn::Image2BlobParams::borderValue).
    define_method("blob_rect_to_image_rect", &cv::dnn::Image2BlobParams::blobRectToImageRect,
      Arg("r_blob"), Arg("size")).
    define_method("blob_rects_to_image_rects", &cv::dnn::Image2BlobParams::blobRectsToImageRects,
      Arg("r_blob"), Arg("r_img"), Arg("size"));

  rb_mCvDnn.define_module_function<cv::Mat(*)(cv::InputArray, const cv::dnn::Image2BlobParams&)>("blob_from_image_with_params", &cv::dnn::blobFromImageWithParams,
    Arg("image"), Arg("param") = static_cast<const cv::dnn::Image2BlobParams&>(cv::dnn::Image2BlobParams()));

  rb_mCvDnn.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const cv::dnn::Image2BlobParams&)>("blob_from_image_with_params", &cv::dnn::blobFromImageWithParams,
    Arg("image"), Arg("blob"), Arg("param") = static_cast<const cv::dnn::Image2BlobParams&>(cv::dnn::Image2BlobParams()));

  rb_mCvDnn.define_module_function<cv::Mat(*)(cv::InputArrayOfArrays, const cv::dnn::Image2BlobParams&)>("blob_from_images_with_params", &cv::dnn::blobFromImagesWithParams,
    Arg("images"), Arg("param") = static_cast<const cv::dnn::Image2BlobParams&>(cv::dnn::Image2BlobParams()));

  rb_mCvDnn.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, const cv::dnn::Image2BlobParams&)>("blob_from_images_with_params", &cv::dnn::blobFromImagesWithParams,
    Arg("images"), Arg("blob"), Arg("param") = static_cast<const cv::dnn::Image2BlobParams&>(cv::dnn::Image2BlobParams()));

  rb_mCvDnn.define_module_function("images_from_blob", &cv::dnn::imagesFromBlob,
    Arg("blob_"), Arg("images_"));

  rb_mCvDnn.define_module_function("shrink_caffe_model", &cv::dnn::shrinkCaffeModel,
    Arg("src"), Arg("dst"), Arg("layers_types") = static_cast<const std::vector<std::basic_string<char>>&>(std::vector<cv::String>()));

  rb_mCvDnn.define_module_function("write_text_graph", &cv::dnn::writeTextGraph,
    Arg("model"), Arg("output"));

  rb_mCvDnn.define_module_function<void(*)(const std::vector<cv::Rect_<int>>&, const std::vector<float>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes", &cv::dnn::NMSBoxes,
    Arg("bboxes"), Arg("scores"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  rb_mCvDnn.define_module_function<void(*)(const std::vector<cv::Rect_<double>>&, const std::vector<float>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes", &cv::dnn::NMSBoxes,
    Arg("bboxes"), Arg("scores"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  rb_mCvDnn.define_module_function<void(*)(const std::vector<cv::RotatedRect>&, const std::vector<float>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes", &cv::dnn::NMSBoxes,
    Arg("bboxes"), Arg("scores"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  rb_mCvDnn.define_module_function<void(*)(const std::vector<cv::Rect_<int>>&, const std::vector<float>&, const std::vector<int>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes_batched", &cv::dnn::NMSBoxesBatched,
    Arg("bboxes"), Arg("scores"), Arg("class_ids"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  rb_mCvDnn.define_module_function<void(*)(const std::vector<cv::Rect_<double>>&, const std::vector<float>&, const std::vector<int>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes_batched", &cv::dnn::NMSBoxesBatched,
    Arg("bboxes"), Arg("scores"), Arg("class_ids"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  Enum<cv::dnn::SoftNMSMethod> rb_cCvDnnSoftNMSMethod = define_enum_under<cv::dnn::SoftNMSMethod>("SoftNMSMethod", rb_mCvDnn).
    define_value("SOFTNMS_LINEAR", cv::dnn::SoftNMSMethod::SOFTNMS_LINEAR).
    define_value("SOFTNMS_GAUSSIAN", cv::dnn::SoftNMSMethod::SOFTNMS_GAUSSIAN);

  rb_mCvDnn.define_module_function("soft_nms_boxes", &cv::dnn::softNMSBoxes,
    Arg("bboxes"), Arg("scores"), Arg("updated_scores"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("top_k") = static_cast<size_t>(0), Arg("sigma") = static_cast<const float>(0.5), Arg("method") = static_cast<cv::dnn::SoftNMSMethod>(cv::dnn::SoftNMSMethod::SOFTNMS_GAUSSIAN));

  Rice::Data_Type<cv::dnn::Model> rb_cCvDnnModel = define_class_under<cv::dnn::Model>(rb_mCvDnn, "Model");

  Rice::Data_Type<cv::dnn::Model::Impl> rb_cCvDnnModelImpl = define_class_under<cv::dnn::Model::Impl>(rb_cCvDnnModel, "Impl");

  rb_cCvDnnModel.
    define_constructor(Constructor<cv::dnn::Model, const cv::dnn::Model&>(),
      Arg("arg_0")).
    define_method<cv::dnn::Model&(cv::dnn::Model::*)(const cv::dnn::Model&)>("assign", &cv::dnn::Model::operator=,
      Arg("arg_0")).
    define_method<cv::dnn::Model&(cv::dnn::Model::*)(cv::dnn::Model&&)>("assign", &cv::dnn::Model::operator=,
      Arg("arg_0")).
    define_constructor(Constructor<cv::dnn::Model, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::Model, const cv::dnn::Net&>(),
      Arg("network")).
    define_method<cv::dnn::Model&(cv::dnn::Model::*)(const cv::Size&)>("set_input_size", &cv::dnn::Model::setInputSize,
      Arg("size")).
    define_method<cv::dnn::Model&(cv::dnn::Model::*)(int, int)>("set_input_size", &cv::dnn::Model::setInputSize,
      Arg("width"), Arg("height")).
    define_method("set_input_mean", &cv::dnn::Model::setInputMean,
      Arg("mean")).
    define_method("set_input_scale", &cv::dnn::Model::setInputScale,
      Arg("scale")).
    define_method("set_input_crop", &cv::dnn::Model::setInputCrop,
      Arg("crop")).
    define_method("set_input_swap_rb", &cv::dnn::Model::setInputSwapRB,
      Arg("swap_rb")).
    define_method("set_output_names", &cv::dnn::Model::setOutputNames,
      Arg("out_names")).
    define_method("set_input_params", &cv::dnn::Model::setInputParams,
      Arg("scale") = static_cast<double>(1.0), Arg("size") = static_cast<const cv::Size&>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false)).
    define_method("predict", &cv::dnn::Model::predict,
      Arg("frame"), Arg("outs")).
    define_method("set_preferable_backend", &cv::dnn::Model::setPreferableBackend,
      Arg("backend_id")).
    define_method("set_preferable_target", &cv::dnn::Model::setPreferableTarget,
      Arg("target_id")).
    define_method("enable_winograd", &cv::dnn::Model::enableWinograd,
      Arg("use_winograd")).
    define_method("get_impl", &cv::dnn::Model::getImpl).
    define_method("get_impl_ref", &cv::dnn::Model::getImplRef);

  Rice::Data_Type<cv::dnn::ClassificationModel> rb_cCvDnnClassificationModel = define_class_under<cv::dnn::ClassificationModel, cv::dnn::Model>(rb_mCvDnn, "ClassificationModel").
    define_constructor(Constructor<cv::dnn::ClassificationModel, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::ClassificationModel, const cv::dnn::Net&>(),
      Arg("network")).
    define_method("set_enable_softmax_post_processing", &cv::dnn::ClassificationModel::setEnableSoftmaxPostProcessing,
      Arg("enable")).
    define_method("get_enable_softmax_post_processing?", &cv::dnn::ClassificationModel::getEnableSoftmaxPostProcessing).
    define_method<std::pair<int, float>(cv::dnn::ClassificationModel::*)(cv::InputArray)>("classify", &cv::dnn::ClassificationModel::classify,
      Arg("frame")).
    define_method<void(cv::dnn::ClassificationModel::*)(cv::InputArray, int&, float&)>("classify", &cv::dnn::ClassificationModel::classify,
      Arg("frame"), Arg("class_id"), Arg("conf"));

  Rice::Data_Type<cv::dnn::KeypointsModel> rb_cCvDnnKeypointsModel = define_class_under<cv::dnn::KeypointsModel, cv::dnn::Model>(rb_mCvDnn, "KeypointsModel").
    define_constructor(Constructor<cv::dnn::KeypointsModel, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::KeypointsModel, const cv::dnn::Net&>(),
      Arg("network")).
    define_method("estimate", &cv::dnn::KeypointsModel::estimate,
      Arg("frame"), Arg("thresh") = static_cast<float>(0.5));

  Rice::Data_Type<cv::dnn::SegmentationModel> rb_cCvDnnSegmentationModel = define_class_under<cv::dnn::SegmentationModel, cv::dnn::Model>(rb_mCvDnn, "SegmentationModel").
    define_constructor(Constructor<cv::dnn::SegmentationModel, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::SegmentationModel, const cv::dnn::Net&>(),
      Arg("network")).
    define_method("segment", &cv::dnn::SegmentationModel::segment,
      Arg("frame"), Arg("mask"));

  Rice::Data_Type<cv::dnn::DetectionModel> rb_cCvDnnDetectionModel = define_class_under<cv::dnn::DetectionModel, cv::dnn::Model>(rb_mCvDnn, "DetectionModel").
    define_constructor(Constructor<cv::dnn::DetectionModel, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::DetectionModel, const cv::dnn::Net&>(),
      Arg("network")).
    define_method("set_nms_across_classes", &cv::dnn::DetectionModel::setNmsAcrossClasses,
      Arg("value")).
    define_method("get_nms_across_classes?", &cv::dnn::DetectionModel::getNmsAcrossClasses).
    define_method("detect", &cv::dnn::DetectionModel::detect,
      Arg("frame"), Arg("class_ids"), Arg("confidences"), Arg("boxes"), Arg("conf_threshold") = static_cast<float>(0.5f), Arg("nms_threshold") = static_cast<float>(0.0f));

  Rice::Data_Type<cv::dnn::TextRecognitionModel> rb_cCvDnnTextRecognitionModel = define_class_under<cv::dnn::TextRecognitionModel, cv::dnn::Model>(rb_mCvDnn, "TextRecognitionModel").
    define_constructor(Constructor<cv::dnn::TextRecognitionModel, const cv::dnn::Net&>(),
      Arg("network")).
    define_constructor(Constructor<cv::dnn::TextRecognitionModel, const std::string&, const std::string&>(),
      Arg("model"), Arg("config") = static_cast<const std::string&>("")).
    define_method("set_decode_type", &cv::dnn::TextRecognitionModel::setDecodeType,
      Arg("decode_type")).
    define_method("get_decode_type", &cv::dnn::TextRecognitionModel::getDecodeType).
    define_method("set_decode_opts_ctc_prefix_beam_search", &cv::dnn::TextRecognitionModel::setDecodeOptsCTCPrefixBeamSearch,
      Arg("beam_size"), Arg("voc_prune_size") = static_cast<int>(0)).
    define_method("set_vocabulary", &cv::dnn::TextRecognitionModel::setVocabulary,
      Arg("vocabulary")).
    define_method("get_vocabulary", &cv::dnn::TextRecognitionModel::getVocabulary).
    define_method<std::string(cv::dnn::TextRecognitionModel::*)(cv::InputArray) const>("recognize", &cv::dnn::TextRecognitionModel::recognize,
      Arg("frame")).
    define_method<void(cv::dnn::TextRecognitionModel::*)(cv::InputArray, cv::InputArrayOfArrays, std::vector<std::string>&) const>("recognize", &cv::dnn::TextRecognitionModel::recognize,
      Arg("frame"), Arg("roi_rects"), Arg("results"));

  Rice::Data_Type<cv::dnn::TextDetectionModel> rb_cCvDnnTextDetectionModel = define_class_under<cv::dnn::TextDetectionModel, cv::dnn::Model>(rb_mCvDnn, "TextDetectionModel").
    define_method<void(cv::dnn::TextDetectionModel::*)(cv::InputArray, std::vector<std::vector<cv::Point_<int>>>&, std::vector<float>&) const>("detect", &cv::dnn::TextDetectionModel::detect,
      Arg("frame"), Arg("detections"), Arg("confidences")).
    define_method<void(cv::dnn::TextDetectionModel::*)(cv::InputArray, std::vector<std::vector<cv::Point_<int>>>&) const>("detect", &cv::dnn::TextDetectionModel::detect,
      Arg("frame"), Arg("detections")).
    define_method<void(cv::dnn::TextDetectionModel::*)(cv::InputArray, std::vector<cv::RotatedRect>&, std::vector<float>&) const>("detect_text_rectangles", &cv::dnn::TextDetectionModel::detectTextRectangles,
      Arg("frame"), Arg("detections"), Arg("confidences")).
    define_method<void(cv::dnn::TextDetectionModel::*)(cv::InputArray, std::vector<cv::RotatedRect>&) const>("detect_text_rectangles", &cv::dnn::TextDetectionModel::detectTextRectangles,
      Arg("frame"), Arg("detections"));

  Rice::Data_Type<cv::dnn::TextDetectionModel_EAST> rb_cCvDnnTextDetectionModelEAST = define_class_under<cv::dnn::TextDetectionModel_EAST, cv::dnn::TextDetectionModel>(rb_mCvDnn, "TextDetectionModelEAST").
    define_constructor(Constructor<cv::dnn::TextDetectionModel_EAST, const cv::dnn::Net&>(),
      Arg("network")).
    define_constructor(Constructor<cv::dnn::TextDetectionModel_EAST, const std::string&, const std::string&>(),
      Arg("model"), Arg("config") = static_cast<const std::string&>("")).
    define_method("set_confidence_threshold", &cv::dnn::TextDetectionModel_EAST::setConfidenceThreshold,
      Arg("conf_threshold")).
    define_method("get_confidence_threshold", &cv::dnn::TextDetectionModel_EAST::getConfidenceThreshold).
    define_method("set_nms_threshold", &cv::dnn::TextDetectionModel_EAST::setNMSThreshold,
      Arg("nms_threshold")).
    define_method("get_nms_threshold", &cv::dnn::TextDetectionModel_EAST::getNMSThreshold);

  Rice::Data_Type<cv::dnn::TextDetectionModel_DB> rb_cCvDnnTextDetectionModelDB = define_class_under<cv::dnn::TextDetectionModel_DB, cv::dnn::TextDetectionModel>(rb_mCvDnn, "TextDetectionModelDB").
    define_constructor(Constructor<cv::dnn::TextDetectionModel_DB, const cv::dnn::Net&>(),
      Arg("network")).
    define_constructor(Constructor<cv::dnn::TextDetectionModel_DB, const std::string&, const std::string&>(),
      Arg("model"), Arg("config") = static_cast<const std::string&>("")).
    define_method("set_binary_threshold", &cv::dnn::TextDetectionModel_DB::setBinaryThreshold,
      Arg("binary_threshold")).
    define_method("get_binary_threshold", &cv::dnn::TextDetectionModel_DB::getBinaryThreshold).
    define_method("set_polygon_threshold", &cv::dnn::TextDetectionModel_DB::setPolygonThreshold,
      Arg("polygon_threshold")).
    define_method("get_polygon_threshold", &cv::dnn::TextDetectionModel_DB::getPolygonThreshold).
    define_method("set_unclip_ratio", &cv::dnn::TextDetectionModel_DB::setUnclipRatio,
      Arg("unclip_ratio")).
    define_method("get_unclip_ratio", &cv::dnn::TextDetectionModel_DB::getUnclipRatio).
    define_method("set_max_candidates", &cv::dnn::TextDetectionModel_DB::setMaxCandidates,
      Arg("max_candidates")).
    define_method("get_max_candidates", &cv::dnn::TextDetectionModel_DB::getMaxCandidates);
}