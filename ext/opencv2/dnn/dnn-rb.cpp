#include <opencv2/dnn/dnn.hpp>
#include "dnn-rb.hpp"

using namespace Rice;

void Init_Dnn_Dnn()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Module rb_mCvDnnAccessor = define_module_under(rb_mCvDnn, "Accessor");

  Rice::Data_Type<cv::dnn::accessor::DnnNetAccessor> rb_cCvDnnAccessorDnnNetAccessor = define_class_under<cv::dnn::accessor::DnnNetAccessor>(rb_mCvDnnAccessor, "DnnNetAccessor");

  Module rb_mCvDnnDnn4V20241223 = define_module_under(rb_mCvDnn, "Dnn4V20241223");

  Enum<cv::dnn::dnn4_v20241223::Backend> rb_cCvDnnDnn4V20241223Backend = define_enum_under<cv::dnn::dnn4_v20241223::Backend>("Backend", rb_mCvDnnDnn4V20241223).
    define_value("DNN_BACKEND_DEFAULT", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_DEFAULT).
    define_value("DNN_BACKEND_HALIDE", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_HALIDE).
    define_value("DNN_BACKEND_INFERENCE_ENGINE", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_INFERENCE_ENGINE).
    define_value("DNN_BACKEND_OPENCV", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_OPENCV).
    define_value("DNN_BACKEND_VKCOM", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_VKCOM).
    define_value("DNN_BACKEND_CUDA", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_CUDA).
    define_value("DNN_BACKEND_WEBNN", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_WEBNN).
    define_value("DNN_BACKEND_TIMVX", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_TIMVX).
    define_value("DNN_BACKEND_CANN", cv::dnn::dnn4_v20241223::Backend::DNN_BACKEND_CANN);

  Enum<cv::dnn::dnn4_v20241223::Target> rb_cCvDnnDnn4V20241223Target = define_enum_under<cv::dnn::dnn4_v20241223::Target>("Target", rb_mCvDnnDnn4V20241223).
    define_value("DNN_TARGET_CPU", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_CPU).
    define_value("DNN_TARGET_OPENCL", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_OPENCL).
    define_value("DNN_TARGET_OPENCL_FP16", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_OPENCL_FP16).
    define_value("DNN_TARGET_MYRIAD", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_MYRIAD).
    define_value("DNN_TARGET_VULKAN", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_VULKAN).
    define_value("DNN_TARGET_FPGA", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_FPGA).
    define_value("DNN_TARGET_CUDA", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_CUDA).
    define_value("DNN_TARGET_CUDA_FP16", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_CUDA_FP16).
    define_value("DNN_TARGET_HDDL", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_HDDL).
    define_value("DNN_TARGET_NPU", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_NPU).
    define_value("DNN_TARGET_CPU_FP16", cv::dnn::dnn4_v20241223::Target::DNN_TARGET_CPU_FP16);

  Enum<cv::dnn::dnn4_v20241223::DataLayout> rb_cCvDnnDnn4V20241223DataLayout = define_enum_under<cv::dnn::dnn4_v20241223::DataLayout>("DataLayout", rb_mCvDnnDnn4V20241223).
    define_value("DNN_LAYOUT_UNKNOWN", cv::dnn::dnn4_v20241223::DataLayout::DNN_LAYOUT_UNKNOWN).
    define_value("DNN_LAYOUT_ND", cv::dnn::dnn4_v20241223::DataLayout::DNN_LAYOUT_ND).
    define_value("DNN_LAYOUT_NCHW", cv::dnn::dnn4_v20241223::DataLayout::DNN_LAYOUT_NCHW).
    define_value("DNN_LAYOUT_NCDHW", cv::dnn::dnn4_v20241223::DataLayout::DNN_LAYOUT_NCDHW).
    define_value("DNN_LAYOUT_NHWC", cv::dnn::dnn4_v20241223::DataLayout::DNN_LAYOUT_NHWC).
    define_value("DNN_LAYOUT_NDHWC", cv::dnn::dnn4_v20241223::DataLayout::DNN_LAYOUT_NDHWC).
    define_value("DNN_LAYOUT_PLANAR", cv::dnn::dnn4_v20241223::DataLayout::DNN_LAYOUT_PLANAR);

  rb_mCvDnnDnn4V20241223.define_module_function<std::vector<std::pair<cv::dnn::dnn4_v20241223::Backend, cv::dnn::dnn4_v20241223::Target>>(*)()>("get_available_backends", &cv::dnn::dnn4_v20241223::getAvailableBackends);

  rb_mCvDnnDnn4V20241223.define_module_function<std::vector<cv::dnn::dnn4_v20241223::Target>(*)(cv::dnn::dnn4_v20241223::Backend)>("get_available_targets", &cv::dnn::dnn4_v20241223::getAvailableTargets,
    Arg("be"));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(bool)>("enable_model_diagnostics", &cv::dnn::dnn4_v20241223::enableModelDiagnostics,
    Arg("is_diagnostics_mode"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::LayerParams> rb_cCvDnnDnn4V20241223LayerParams = define_class_under<cv::dnn::dnn4_v20241223::LayerParams, cv::dnn::dnn4_v20241223::Dict>(rb_mCvDnnDnn4V20241223, "LayerParams").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::LayerParams>()).
    define_attr("blobs", &cv::dnn::dnn4_v20241223::LayerParams::blobs).
    define_attr("name", &cv::dnn::dnn4_v20241223::LayerParams::name).
    define_attr("type", &cv::dnn::dnn4_v20241223::LayerParams::type);

  Rice::Data_Type<cv::dnn::dnn4_v20241223::BackendWrapper> rb_cCvDnnDnn4V20241223BackendWrapper = define_class_under<cv::dnn::dnn4_v20241223::BackendWrapper>(rb_mCvDnnDnn4V20241223, "BackendWrapper").
    define_method<void(cv::dnn::dnn4_v20241223::BackendWrapper::*)()>("copy_to_host", &cv::dnn::dnn4_v20241223::BackendWrapper::copyToHost).
    define_method<void(cv::dnn::dnn4_v20241223::BackendWrapper::*)()>("set_host_dirty", &cv::dnn::dnn4_v20241223::BackendWrapper::setHostDirty).
    define_attr("backend_id", &cv::dnn::dnn4_v20241223::BackendWrapper::backendId).
    define_attr("target_id", &cv::dnn::dnn4_v20241223::BackendWrapper::targetId);

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ActivationLayer> rb_cCvDnnDnn4V20241223ActivationLayer = define_class_under<cv::dnn::dnn4_v20241223::ActivationLayer>(rb_mCvDnnDnn4V20241223, "ActivationLayer");

  Rice::Data_Type<cv::dnn::dnn4_v20241223::Layer> rb_cCvDnnDnn4V20241223Layer = define_class_under<cv::dnn::dnn4_v20241223::Layer, cv::Algorithm>(rb_mCvDnnDnn4V20241223, "Layer").
    define_attr("blobs", &cv::dnn::dnn4_v20241223::Layer::blobs).
    define_method<void(cv::dnn::dnn4_v20241223::Layer::*)(cv::InputArrayOfArrays, cv::OutputArrayOfArrays)>("finalize", &cv::dnn::dnn4_v20241223::Layer::finalize,
      Arg("inputs"), Arg("outputs")).
    define_method<void(cv::dnn::dnn4_v20241223::Layer::*)(cv::InputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays)>("forward", &cv::dnn::dnn4_v20241223::Layer::forward,
      Arg("inputs"), Arg("outputs"), Arg("internals")).
    define_method<bool(cv::dnn::dnn4_v20241223::Layer::*)(const std::vector<std::vector<float>>&, const std::vector<std::vector<int>>&, cv::dnn::dnn4_v20241223::LayerParams&)>("try_quantize", &cv::dnn::dnn4_v20241223::Layer::tryQuantize,
      Arg("scales"), Arg("zeropoints"), Arg("params")).
    define_method<void(cv::dnn::dnn4_v20241223::Layer::*)(cv::InputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays)>("forward_fallback", &cv::dnn::dnn4_v20241223::Layer::forward_fallback,
      Arg("inputs"), Arg("outputs"), Arg("internals")).
    define_method<int(cv::dnn::dnn4_v20241223::Layer::*)(cv::String)>("input_name_to_index", &cv::dnn::dnn4_v20241223::Layer::inputNameToIndex,
      Arg("input_name")).
    define_method<int(cv::dnn::dnn4_v20241223::Layer::*)(const cv::String&)>("output_name_to_index", &cv::dnn::dnn4_v20241223::Layer::outputNameToIndex,
      Arg("output_name")).
    define_method<bool(cv::dnn::dnn4_v20241223::Layer::*)(int)>("support_backend", &cv::dnn::dnn4_v20241223::Layer::supportBackend,
      Arg("backend_id")).
    define_method<bool(cv::dnn::dnn4_v20241223::Layer::*)(const cv::Ptr<cv::dnn::dnn4_v20241223::ActivationLayer>&)>("set_activation", &cv::dnn::dnn4_v20241223::Layer::setActivation,
      Arg("layer")).
    define_method<bool(cv::dnn::dnn4_v20241223::Layer::*)(cv::Ptr<cv::dnn::dnn4_v20241223::Layer>&)>("try_fuse", &cv::dnn::dnn4_v20241223::Layer::tryFuse,
      Arg("top")).
    define_method<void(cv::dnn::dnn4_v20241223::Layer::*)(cv::Mat&, cv::Mat&) const>("get_scale_shift", &cv::dnn::dnn4_v20241223::Layer::getScaleShift,
      Arg("scale"), Arg("shift")).
    define_method<void(cv::dnn::dnn4_v20241223::Layer::*)(float&, int&) const>("get_scale_zeropoint", &cv::dnn::dnn4_v20241223::Layer::getScaleZeropoint,
      Arg("scale"), Arg("zeropoint")).
    define_method<void(cv::dnn::dnn4_v20241223::Layer::*)()>("unset_attached", &cv::dnn::dnn4_v20241223::Layer::unsetAttached).
    define_method<bool(cv::dnn::dnn4_v20241223::Layer::*)(const std::vector<std::vector<int>>&, const int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&) const>("get_memory_shapes", &cv::dnn::dnn4_v20241223::Layer::getMemoryShapes,
      Arg("inputs"), Arg("required_outputs"), Arg("outputs"), Arg("internals")).
    define_method<int64(cv::dnn::dnn4_v20241223::Layer::*)(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&) const>("get_flops", &cv::dnn::dnn4_v20241223::Layer::getFLOPS,
      Arg("inputs"), Arg("outputs")).
    define_method<bool(cv::dnn::dnn4_v20241223::Layer::*)(const std::vector<std::vector<int>>&)>("update_memory_shapes", &cv::dnn::dnn4_v20241223::Layer::updateMemoryShapes,
      Arg("inputs")).
    define_attr("name", &cv::dnn::dnn4_v20241223::Layer::name).
    define_attr("type", &cv::dnn::dnn4_v20241223::Layer::type).
    define_attr("preferable_target", &cv::dnn::dnn4_v20241223::Layer::preferableTarget).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Layer>()).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Layer, const cv::dnn::dnn4_v20241223::LayerParams&>(),
      Arg("params")).
    define_method<void(cv::dnn::dnn4_v20241223::Layer::*)(const cv::dnn::dnn4_v20241223::LayerParams&)>("set_params_from", &cv::dnn::dnn4_v20241223::Layer::setParamsFrom,
      Arg("params"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::Net> rb_cCvDnnDnn4V20241223Net = define_class_under<cv::dnn::dnn4_v20241223::Net>(rb_mCvDnnDnn4V20241223, "Net");

  Rice::Data_Type<cv::dnn::dnn4_v20241223::Net::Impl> rb_cCvDnnDnn4V20241223NetImpl = define_class_under<cv::dnn::dnn4_v20241223::Net::Impl>(rb_cCvDnnDnn4V20241223Net, "Impl");

  rb_cCvDnnDnn4V20241223Net.
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Net>()).
    define_method<bool(cv::dnn::dnn4_v20241223::Net::*)() const>("empty?", &cv::dnn::dnn4_v20241223::Net::empty).
    define_method<cv::String(cv::dnn::dnn4_v20241223::Net::*)()>("dump", &cv::dnn::dnn4_v20241223::Net::dump).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&)>("dump_to_file", &cv::dnn::dnn4_v20241223::Net::dumpToFile,
      Arg("path")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&)>("dump_to_pbtxt", &cv::dnn::dnn4_v20241223::Net::dumpToPbtxt,
      Arg("path")).
    define_method<int(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&, const cv::String&, const int&, cv::dnn::dnn4_v20241223::LayerParams&)>("add_layer", &cv::dnn::dnn4_v20241223::Net::addLayer,
      Arg("name"), Arg("type"), Arg("dtype"), Arg("params")).
    define_method<int(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&, const cv::String&, cv::dnn::dnn4_v20241223::LayerParams&)>("add_layer", &cv::dnn::dnn4_v20241223::Net::addLayer,
      Arg("name"), Arg("type"), Arg("params")).
    define_method<int(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&, const cv::String&, const int&, cv::dnn::dnn4_v20241223::LayerParams&)>("add_layer_to_prev", &cv::dnn::dnn4_v20241223::Net::addLayerToPrev,
      Arg("name"), Arg("type"), Arg("dtype"), Arg("params")).
    define_method<int(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&, const cv::String&, cv::dnn::dnn4_v20241223::LayerParams&)>("add_layer_to_prev", &cv::dnn::dnn4_v20241223::Net::addLayerToPrev,
      Arg("name"), Arg("type"), Arg("params")).
    define_method<int(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&) const>("get_layer_id", &cv::dnn::dnn4_v20241223::Net::getLayerId,
      Arg("layer")).
    define_method<std::vector<std::basic_string<char>>(cv::dnn::dnn4_v20241223::Net::*)() const>("get_layer_names", &cv::dnn::dnn4_v20241223::Net::getLayerNames).
    define_method<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(cv::dnn::dnn4_v20241223::Net::*)(int) const>("get_layer", &cv::dnn::dnn4_v20241223::Net::getLayer,
      Arg("layer_id")).
    define_method<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&) const>("get_layer", &cv::dnn::dnn4_v20241223::Net::getLayer,
      Arg("layer_name")).
    define_method<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>(cv::dnn::dnn4_v20241223::Net::*)(const cv::dnn::dnn4_v20241223::Net::LayerId&) const>("get_layer", &cv::dnn::dnn4_v20241223::Net::getLayer,
      Arg("layer_id")).
    define_method<std::vector<cv::Ptr<cv::dnn::dnn4_v20241223::Layer>>(cv::dnn::dnn4_v20241223::Net::*)(int) const>("get_layer_inputs", &cv::dnn::dnn4_v20241223::Net::getLayerInputs,
      Arg("layer_id")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(cv::String, cv::String)>("connect", &cv::dnn::dnn4_v20241223::Net::connect,
      Arg("out_pin"), Arg("inp_pin")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(int, int, int, int)>("connect", &cv::dnn::dnn4_v20241223::Net::connect,
      Arg("out_layer_id"), Arg("out_num"), Arg("inp_layer_id"), Arg("inp_num")).
    define_method<int(cv::dnn::dnn4_v20241223::Net::*)(const std::string&, int, int)>("register_output", &cv::dnn::dnn4_v20241223::Net::registerOutput,
      Arg("output_name"), Arg("layer_id"), Arg("output_port")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const std::vector<std::basic_string<char>>&)>("set_inputs_names", &cv::dnn::dnn4_v20241223::Net::setInputsNames,
      Arg("input_blob_names")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&, const cv::dnn::dnn4_v20241223::MatShape&)>("set_input_shape", &cv::dnn::dnn4_v20241223::Net::setInputShape,
      Arg("input_name"), Arg("shape")).
    define_method<cv::Mat(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&)>("forward", &cv::dnn::dnn4_v20241223::Net::forward,
      Arg("output_name") = static_cast<const cv::String&>(cv::String())).
    define_method<cv::AsyncArray(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&)>("forward_async", &cv::dnn::dnn4_v20241223::Net::forwardAsync,
      Arg("output_name") = static_cast<const cv::String&>(cv::String())).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(cv::OutputArrayOfArrays, const cv::String&)>("forward", &cv::dnn::dnn4_v20241223::Net::forward,
      Arg("output_blobs"), Arg("output_name") = static_cast<const cv::String&>(cv::String())).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(cv::OutputArrayOfArrays, const std::vector<std::basic_string<char>>&)>("forward", &cv::dnn::dnn4_v20241223::Net::forward,
      Arg("output_blobs"), Arg("out_blob_names")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(std::vector<std::vector<cv::Mat>>&, const std::vector<std::basic_string<char>>&)>("forward", &cv::dnn::dnn4_v20241223::Net::forward,
      Arg("output_blobs"), Arg("out_blob_names")).
    define_method<cv::dnn::dnn4_v20241223::Net(cv::dnn::dnn4_v20241223::Net::*)(cv::InputArrayOfArrays, int, int, bool)>("quantize", &cv::dnn::dnn4_v20241223::Net::quantize,
      Arg("calib_data"), Arg("inputs_dtype"), Arg("outputs_dtype"), Arg("per_channel") = static_cast<bool>(true)).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(std::vector<float>&, std::vector<int>&) const>("get_input_details", &cv::dnn::dnn4_v20241223::Net::getInputDetails,
      Arg("scales"), Arg("zeropoints")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(std::vector<float>&, std::vector<int>&) const>("get_output_details", &cv::dnn::dnn4_v20241223::Net::getOutputDetails,
      Arg("scales"), Arg("zeropoints")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&)>("set_halide_scheduler", &cv::dnn::dnn4_v20241223::Net::setHalideScheduler,
      Arg("scheduler")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(int)>("set_preferable_backend", &cv::dnn::dnn4_v20241223::Net::setPreferableBackend,
      Arg("backend_id")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(int)>("set_preferable_target", &cv::dnn::dnn4_v20241223::Net::setPreferableTarget,
      Arg("target_id")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(cv::InputArray, const cv::String&, double, const cv::Scalar&)>("set_input", &cv::dnn::dnn4_v20241223::Net::setInput,
      Arg("blob"), Arg("name") = static_cast<const cv::String&>(""), Arg("scalefactor") = static_cast<double>(1.0), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar())).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(int, int, const cv::Mat&)>("set_param", &cv::dnn::dnn4_v20241223::Net::setParam,
      Arg("layer"), Arg("num_param"), Arg("blob")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&, int, const cv::Mat&)>("set_param", &cv::dnn::dnn4_v20241223::Net::setParam,
      Arg("layer_name"), Arg("num_param"), Arg("blob")).
    define_method<cv::Mat(cv::dnn::dnn4_v20241223::Net::*)(int, int) const>("get_param", &cv::dnn::dnn4_v20241223::Net::getParam,
      Arg("layer"), Arg("num_param") = static_cast<int>(0)).
    define_method<cv::Mat(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&, int) const>("get_param", &cv::dnn::dnn4_v20241223::Net::getParam,
      Arg("layer_name"), Arg("num_param") = static_cast<int>(0)).
    define_method<std::vector<int>(cv::dnn::dnn4_v20241223::Net::*)() const>("get_unconnected_out_layers", &cv::dnn::dnn4_v20241223::Net::getUnconnectedOutLayers).
    define_method<std::vector<std::basic_string<char>>(cv::dnn::dnn4_v20241223::Net::*)() const>("get_unconnected_out_layers_names", &cv::dnn::dnn4_v20241223::Net::getUnconnectedOutLayersNames).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const std::vector<std::vector<int>>&, std::vector<int>&, std::vector<std::vector<std::vector<int>>>&, std::vector<std::vector<std::vector<int>>>&) const>("get_layers_shapes", &cv::dnn::dnn4_v20241223::Net::getLayersShapes,
      Arg("net_input_shapes"), Arg("layers_ids"), Arg("in_layers_shapes"), Arg("out_layers_shapes")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::dnn::dnn4_v20241223::MatShape&, std::vector<int>&, std::vector<std::vector<std::vector<int>>>&, std::vector<std::vector<std::vector<int>>>&) const>("get_layers_shapes", &cv::dnn::dnn4_v20241223::Net::getLayersShapes,
      Arg("net_input_shape"), Arg("layers_ids"), Arg("in_layers_shapes"), Arg("out_layers_shapes")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::dnn::dnn4_v20241223::MatShape&, const int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&) const>("get_layer_shapes", &cv::dnn::dnn4_v20241223::Net::getLayerShapes,
      Arg("net_input_shape"), Arg("layer_id"), Arg("in_layer_shapes"), Arg("out_layer_shapes")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const std::vector<std::vector<int>>&, const int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&) const>("get_layer_shapes", &cv::dnn::dnn4_v20241223::Net::getLayerShapes,
      Arg("net_input_shapes"), Arg("layer_id"), Arg("in_layer_shapes"), Arg("out_layer_shapes")).
    define_method<int64(cv::dnn::dnn4_v20241223::Net::*)(const std::vector<std::vector<int>>&) const>("get_flops", &cv::dnn::dnn4_v20241223::Net::getFLOPS,
      Arg("net_input_shapes")).
    define_method<int64(cv::dnn::dnn4_v20241223::Net::*)(const cv::dnn::dnn4_v20241223::MatShape&) const>("get_flops", &cv::dnn::dnn4_v20241223::Net::getFLOPS,
      Arg("net_input_shape")).
    define_method<int64(cv::dnn::dnn4_v20241223::Net::*)(const int, const std::vector<std::vector<int>>&) const>("get_flops", &cv::dnn::dnn4_v20241223::Net::getFLOPS,
      Arg("layer_id"), Arg("net_input_shapes")).
    define_method<int64(cv::dnn::dnn4_v20241223::Net::*)(const int, const cv::dnn::dnn4_v20241223::MatShape&) const>("get_flops", &cv::dnn::dnn4_v20241223::Net::getFLOPS,
      Arg("layer_id"), Arg("net_input_shape")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(std::vector<std::basic_string<char>>&) const>("get_layer_types", &cv::dnn::dnn4_v20241223::Net::getLayerTypes,
      Arg("layers_types")).
    define_method<int(cv::dnn::dnn4_v20241223::Net::*)(const cv::String&) const>("get_layers_count", &cv::dnn::dnn4_v20241223::Net::getLayersCount,
      Arg("layer_type")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const std::vector<std::vector<int>>&, size_t&, size_t&) const>("get_memory_consumption", &cv::dnn::dnn4_v20241223::Net::getMemoryConsumption,
      Arg("net_input_shapes"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::dnn::dnn4_v20241223::MatShape&, size_t&, size_t&) const>("get_memory_consumption", &cv::dnn::dnn4_v20241223::Net::getMemoryConsumption,
      Arg("net_input_shape"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const int, const std::vector<std::vector<int>>&, size_t&, size_t&) const>("get_memory_consumption", &cv::dnn::dnn4_v20241223::Net::getMemoryConsumption,
      Arg("layer_id"), Arg("net_input_shapes"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const int, const cv::dnn::dnn4_v20241223::MatShape&, size_t&, size_t&) const>("get_memory_consumption", &cv::dnn::dnn4_v20241223::Net::getMemoryConsumption,
      Arg("layer_id"), Arg("net_input_shape"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const std::vector<std::vector<int>>&, std::vector<int>&, std::vector<size_t>&, std::vector<size_t>&) const>("get_memory_consumption", &cv::dnn::dnn4_v20241223::Net::getMemoryConsumption,
      Arg("net_input_shapes"), Arg("layer_ids"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(const cv::dnn::dnn4_v20241223::MatShape&, std::vector<int>&, std::vector<size_t>&, std::vector<size_t>&) const>("get_memory_consumption", &cv::dnn::dnn4_v20241223::Net::getMemoryConsumption,
      Arg("net_input_shape"), Arg("layer_ids"), Arg("weights"), Arg("blobs")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(bool)>("enable_fusion", &cv::dnn::dnn4_v20241223::Net::enableFusion,
      Arg("fusion")).
    define_method<void(cv::dnn::dnn4_v20241223::Net::*)(bool)>("enable_winograd", &cv::dnn::dnn4_v20241223::Net::enableWinograd,
      Arg("use_winograd")).
    define_method<int64(cv::dnn::dnn4_v20241223::Net::*)(std::vector<double>&)>("get_perf_profile", &cv::dnn::dnn4_v20241223::Net::getPerfProfile,
      Arg("timings")).
    define_method<cv::dnn::dnn4_v20241223::Net::Impl*(cv::dnn::dnn4_v20241223::Net::*)() const>("get_impl", &cv::dnn::dnn4_v20241223::Net::getImpl).
    define_method<cv::dnn::dnn4_v20241223::Net::Impl&(cv::dnn::dnn4_v20241223::Net::*)() const>("get_impl_ref", &cv::dnn::dnn4_v20241223::Net::getImplRef).
    define_singleton_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&, const cv::String&)>("read_from_model_optimizer", &cv::dnn::dnn4_v20241223::Net::readFromModelOptimizer,
      Arg("xml"), Arg("bin")).
    define_singleton_function<cv::dnn::dnn4_v20241223::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_from_model_optimizer", &cv::dnn::dnn4_v20241223::Net::readFromModelOptimizer,
      Arg("buffer_model_config"), Arg("buffer_weights")).
    define_singleton_function<cv::dnn::dnn4_v20241223::Net(*)(const uchar*, size_t, const uchar*, size_t)>("read_from_model_optimizer", &cv::dnn::dnn4_v20241223::Net::readFromModelOptimizer,
      ArgBuffer("buffer_model_config_ptr"), Arg("buffer_model_config_size"), ArgBuffer("buffer_weights_ptr"), Arg("buffer_weights_size"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&, const cv::String&)>("read_net_from_darknet", &cv::dnn::dnn4_v20241223::readNetFromDarknet,
    Arg("cfg_file"), Arg("darknet_model") = static_cast<const cv::String&>(cv::String()));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_net_from_darknet", &cv::dnn::dnn4_v20241223::readNetFromDarknet,
    Arg("buffer_cfg"), Arg("buffer_model") = static_cast<const std::vector<uchar>&>(std::vector<uchar>()));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const char*, size_t, const char*, size_t)>("read_net_from_darknet", &cv::dnn::dnn4_v20241223::readNetFromDarknet,
    Arg("buffer_cfg"), Arg("len_cfg"), Arg("buffer_model") = static_cast<const char*>(NULL), Arg("len_model") = static_cast<size_t>(0));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&, const cv::String&)>("read_net_from_caffe", &cv::dnn::dnn4_v20241223::readNetFromCaffe,
    Arg("prototxt"), Arg("caffe_model") = static_cast<const cv::String&>(cv::String()));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_net_from_caffe", &cv::dnn::dnn4_v20241223::readNetFromCaffe,
    Arg("buffer_proto"), Arg("buffer_model") = static_cast<const std::vector<uchar>&>(std::vector<uchar>()));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const char*, size_t, const char*, size_t)>("read_net_from_caffe", &cv::dnn::dnn4_v20241223::readNetFromCaffe,
    Arg("buffer_proto"), Arg("len_proto"), Arg("buffer_model") = static_cast<const char*>(NULL), Arg("len_model") = static_cast<size_t>(0));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&, const cv::String&)>("read_net_from_tensorflow", &cv::dnn::dnn4_v20241223::readNetFromTensorflow,
    Arg("model"), Arg("config") = static_cast<const cv::String&>(cv::String()));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_net_from_tensorflow", &cv::dnn::dnn4_v20241223::readNetFromTensorflow,
    Arg("buffer_model"), Arg("buffer_config") = static_cast<const std::vector<uchar>&>(std::vector<uchar>()));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const char*, size_t, const char*, size_t)>("read_net_from_tensorflow", &cv::dnn::dnn4_v20241223::readNetFromTensorflow,
    Arg("buffer_model"), Arg("len_model"), Arg("buffer_config") = static_cast<const char*>(NULL), Arg("len_config") = static_cast<size_t>(0));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&)>("read_net_from_tf_lite", &cv::dnn::dnn4_v20241223::readNetFromTFLite,
    Arg("model"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const std::vector<uchar>&)>("read_net_from_tf_lite", &cv::dnn::dnn4_v20241223::readNetFromTFLite,
    Arg("buffer_model"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const char*, size_t)>("read_net_from_tf_lite", &cv::dnn::dnn4_v20241223::readNetFromTFLite,
    Arg("buffer_model"), Arg("len_model"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&, bool, bool)>("read_net_from_torch", &cv::dnn::dnn4_v20241223::readNetFromTorch,
    Arg("model"), Arg("is_binary") = static_cast<bool>(true), Arg("evaluate") = static_cast<bool>(true));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&, const cv::String&, const cv::String&)>("read_net", &cv::dnn::dnn4_v20241223::readNet,
    Arg("model"), Arg("config") = static_cast<const cv::String&>(""), Arg("framework") = static_cast<const cv::String&>(""));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&, const std::vector<uchar>&, const std::vector<uchar>&)>("read_net", &cv::dnn::dnn4_v20241223::readNet,
    Arg("framework"), Arg("buffer_model"), Arg("buffer_config") = static_cast<const std::vector<uchar>&>(std::vector<uchar>()));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(const cv::String&, bool)>("read_torch_blob", &cv::dnn::dnn4_v20241223::readTorchBlob,
    Arg("filename"), Arg("is_binary") = static_cast<bool>(true));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&, const cv::String&)>("read_net_from_model_optimizer", &cv::dnn::dnn4_v20241223::readNetFromModelOptimizer,
    Arg("xml"), Arg("bin") = static_cast<const cv::String&>(""));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const std::vector<uchar>&, const std::vector<uchar>&)>("read_net_from_model_optimizer", &cv::dnn::dnn4_v20241223::readNetFromModelOptimizer,
    Arg("buffer_model_config"), Arg("buffer_weights"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const uchar*, size_t, const uchar*, size_t)>("read_net_from_model_optimizer", &cv::dnn::dnn4_v20241223::readNetFromModelOptimizer,
    ArgBuffer("buffer_model_config_ptr"), Arg("buffer_model_config_size"), ArgBuffer("buffer_weights_ptr"), Arg("buffer_weights_size"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const cv::String&)>("read_net_from_onnx", &cv::dnn::dnn4_v20241223::readNetFromONNX,
    Arg("onnx_file"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const char*, size_t)>("read_net_from_onnx", &cv::dnn::dnn4_v20241223::readNetFromONNX,
    Arg("buffer"), Arg("size_buffer"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::Net(*)(const std::vector<uchar>&)>("read_net_from_onnx", &cv::dnn::dnn4_v20241223::readNetFromONNX,
    Arg("buffer"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(const cv::String&)>("read_tensor_from_onnx", &cv::dnn::dnn4_v20241223::readTensorFromONNX,
    Arg("path"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(cv::InputArray, double, const cv::Size&, const cv::Scalar&, bool, bool, int)>("blob_from_image", &cv::dnn::dnn4_v20241223::blobFromImage,
    Arg("image"), Arg("scalefactor") = static_cast<double>(1.0), Arg("size") = static_cast<const cv::Size&>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, const cv::Size&, const cv::Scalar&, bool, bool, int)>("blob_from_image", &cv::dnn::dnn4_v20241223::blobFromImage,
    Arg("image"), Arg("blob"), Arg("scalefactor") = static_cast<double>(1.0), Arg("size") = static_cast<const cv::Size&>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(cv::InputArrayOfArrays, double, cv::Size, const cv::Scalar&, bool, bool, int)>("blob_from_images", &cv::dnn::dnn4_v20241223::blobFromImages,
    Arg("images"), Arg("scalefactor") = static_cast<double>(1.0), Arg("size") = static_cast<cv::Size>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, double, cv::Size, const cv::Scalar&, bool, bool, int)>("blob_from_images", &cv::dnn::dnn4_v20241223::blobFromImages,
    Arg("images"), Arg("blob"), Arg("scalefactor") = static_cast<double>(1.0), Arg("size") = static_cast<cv::Size>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F));

  Enum<cv::dnn::dnn4_v20241223::ImagePaddingMode> rb_cCvDnnDnn4V20241223ImagePaddingMode = define_enum_under<cv::dnn::dnn4_v20241223::ImagePaddingMode>("ImagePaddingMode", rb_mCvDnnDnn4V20241223).
    define_value("DNN_PMODE_NULL", cv::dnn::dnn4_v20241223::ImagePaddingMode::DNN_PMODE_NULL).
    define_value("DNN_PMODE_CROP_CENTER", cv::dnn::dnn4_v20241223::ImagePaddingMode::DNN_PMODE_CROP_CENTER).
    define_value("DNN_PMODE_LETTERBOX", cv::dnn::dnn4_v20241223::ImagePaddingMode::DNN_PMODE_LETTERBOX);

  Rice::Data_Type<cv::dnn::dnn4_v20241223::Image2BlobParams> rb_cCvDnnDnn4V20241223Image2BlobParams = define_class_under<cv::dnn::dnn4_v20241223::Image2BlobParams>(rb_mCvDnnDnn4V20241223, "Image2BlobParams").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Image2BlobParams>()).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Image2BlobParams, const cv::Scalar&, const cv::Size&, const cv::Scalar&, bool, int, cv::dnn::dnn4_v20241223::DataLayout, cv::dnn::dnn4_v20241223::ImagePaddingMode, cv::Scalar>(),
      Arg("scalefactor"), Arg("size") = static_cast<const cv::Size&>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(CV_32F), Arg("datalayout") = static_cast<cv::dnn::dnn4_v20241223::DataLayout>(cv::dnn::dnn4_v20241223::DNN_LAYOUT_NCHW), Arg("mode") = static_cast<cv::dnn::dnn4_v20241223::ImagePaddingMode>(cv::dnn::dnn4_v20241223::DNN_PMODE_NULL), Arg("border_value") = static_cast<cv::Scalar>(0.0)).
    define_attr("scalefactor", &cv::dnn::dnn4_v20241223::Image2BlobParams::scalefactor).
    define_attr("size", &cv::dnn::dnn4_v20241223::Image2BlobParams::size).
    define_attr("mean", &cv::dnn::dnn4_v20241223::Image2BlobParams::mean).
    define_attr("swap_rb", &cv::dnn::dnn4_v20241223::Image2BlobParams::swapRB).
    define_attr("ddepth", &cv::dnn::dnn4_v20241223::Image2BlobParams::ddepth).
    define_attr("datalayout", &cv::dnn::dnn4_v20241223::Image2BlobParams::datalayout).
    define_attr("paddingmode", &cv::dnn::dnn4_v20241223::Image2BlobParams::paddingmode).
    define_attr("border_value", &cv::dnn::dnn4_v20241223::Image2BlobParams::borderValue).
    define_method<cv::Rect(cv::dnn::dnn4_v20241223::Image2BlobParams::*)(const cv::Rect&, const cv::Size&)>("blob_rect_to_image_rect", &cv::dnn::dnn4_v20241223::Image2BlobParams::blobRectToImageRect,
      Arg("r_blob"), Arg("size")).
    define_method<void(cv::dnn::dnn4_v20241223::Image2BlobParams::*)(const std::vector<cv::Rect_<int>>&, std::vector<cv::Rect_<int>>&, const cv::Size&)>("blob_rects_to_image_rects", &cv::dnn::dnn4_v20241223::Image2BlobParams::blobRectsToImageRects,
      Arg("r_blob"), Arg("r_img"), Arg("size"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(cv::InputArray, const cv::dnn::dnn4_v20241223::Image2BlobParams&)>("blob_from_image_with_params", &cv::dnn::dnn4_v20241223::blobFromImageWithParams,
    Arg("image"), Arg("param") = static_cast<const cv::dnn::dnn4_v20241223::Image2BlobParams&>(cv::dnn::dnn4_v20241223::Image2BlobParams()));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const cv::dnn::dnn4_v20241223::Image2BlobParams&)>("blob_from_image_with_params", &cv::dnn::dnn4_v20241223::blobFromImageWithParams,
    Arg("image"), Arg("blob"), Arg("param") = static_cast<const cv::dnn::dnn4_v20241223::Image2BlobParams&>(cv::dnn::dnn4_v20241223::Image2BlobParams()));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(cv::InputArrayOfArrays, const cv::dnn::dnn4_v20241223::Image2BlobParams&)>("blob_from_images_with_params", &cv::dnn::dnn4_v20241223::blobFromImagesWithParams,
    Arg("images"), Arg("param") = static_cast<const cv::dnn::dnn4_v20241223::Image2BlobParams&>(cv::dnn::dnn4_v20241223::Image2BlobParams()));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, const cv::dnn::dnn4_v20241223::Image2BlobParams&)>("blob_from_images_with_params", &cv::dnn::dnn4_v20241223::blobFromImagesWithParams,
    Arg("images"), Arg("blob"), Arg("param") = static_cast<const cv::dnn::dnn4_v20241223::Image2BlobParams&>(cv::dnn::dnn4_v20241223::Image2BlobParams()));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const cv::Mat&, cv::OutputArrayOfArrays)>("images_from_blob", &cv::dnn::dnn4_v20241223::imagesFromBlob,
    Arg("blob_"), Arg("images_"));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const cv::String&, const cv::String&, const std::vector<std::basic_string<char>>&)>("shrink_caffe_model", &cv::dnn::dnn4_v20241223::shrinkCaffeModel,
    Arg("src"), Arg("dst"), Arg("layers_types") = static_cast<const std::vector<std::basic_string<char>>&>(std::vector<cv::String>()));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const cv::String&, const cv::String&)>("write_text_graph", &cv::dnn::dnn4_v20241223::writeTextGraph,
    Arg("model"), Arg("output"));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const std::vector<cv::Rect_<int>>&, const std::vector<float>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes", &cv::dnn::dnn4_v20241223::NMSBoxes,
    Arg("bboxes"), Arg("scores"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const std::vector<cv::Rect_<double>>&, const std::vector<float>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes", &cv::dnn::dnn4_v20241223::NMSBoxes,
    Arg("bboxes"), Arg("scores"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const std::vector<cv::RotatedRect>&, const std::vector<float>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes", &cv::dnn::dnn4_v20241223::NMSBoxes,
    Arg("bboxes"), Arg("scores"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const std::vector<cv::Rect_<int>>&, const std::vector<float>&, const std::vector<int>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes_batched", &cv::dnn::dnn4_v20241223::NMSBoxesBatched,
    Arg("bboxes"), Arg("scores"), Arg("class_ids"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const std::vector<cv::Rect_<double>>&, const std::vector<float>&, const std::vector<int>&, const float, const float, std::vector<int>&, const float, const int)>("nms_boxes_batched", &cv::dnn::dnn4_v20241223::NMSBoxesBatched,
    Arg("bboxes"), Arg("scores"), Arg("class_ids"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("eta") = static_cast<const float>(1.f), Arg("top_k") = static_cast<const int>(0));

  Enum<cv::dnn::dnn4_v20241223::SoftNMSMethod> rb_cCvDnnDnn4V20241223SoftNMSMethod = define_enum_under<cv::dnn::dnn4_v20241223::SoftNMSMethod>("SoftNMSMethod", rb_mCvDnnDnn4V20241223).
    define_value("SOFTNMS_LINEAR", cv::dnn::dnn4_v20241223::SoftNMSMethod::SOFTNMS_LINEAR).
    define_value("SOFTNMS_GAUSSIAN", cv::dnn::dnn4_v20241223::SoftNMSMethod::SOFTNMS_GAUSSIAN);

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(const std::vector<cv::Rect_<int>>&, const std::vector<float>&, std::vector<float>&, const float, const float, std::vector<int>&, size_t, const float, cv::dnn::dnn4_v20241223::SoftNMSMethod)>("soft_nms_boxes", &cv::dnn::dnn4_v20241223::softNMSBoxes,
    Arg("bboxes"), Arg("scores"), Arg("updated_scores"), Arg("score_threshold"), Arg("nms_threshold"), Arg("indices"), Arg("top_k") = static_cast<size_t>(0), Arg("sigma") = static_cast<const float>(0.5), Arg("method") = static_cast<cv::dnn::dnn4_v20241223::SoftNMSMethod>(cv::dnn::dnn4_v20241223::SoftNMSMethod::SOFTNMS_GAUSSIAN));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::Model> rb_cCvDnnDnn4V20241223Model = define_class_under<cv::dnn::dnn4_v20241223::Model>(rb_mCvDnnDnn4V20241223, "Model");

  Rice::Data_Type<cv::dnn::dnn4_v20241223::Model::Impl> rb_cCvDnnDnn4V20241223ModelImpl = define_class_under<cv::dnn::dnn4_v20241223::Model::Impl>(rb_cCvDnnDnn4V20241223Model, "Impl");

  rb_cCvDnnDnn4V20241223Model.
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Model, const cv::dnn::dnn4_v20241223::Model&>(),
      Arg("arg_0")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(const cv::dnn::dnn4_v20241223::Model&)>("assign", &cv::dnn::dnn4_v20241223::Model::operator=,
      Arg("arg_0")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(cv::dnn::dnn4_v20241223::Model&&)>("assign", &cv::dnn::dnn4_v20241223::Model::operator=,
      Arg("arg_0")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Model, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::Model, const cv::dnn::dnn4_v20241223::Net&>(),
      Arg("network")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(const cv::Size&)>("set_input_size", &cv::dnn::dnn4_v20241223::Model::setInputSize,
      Arg("size")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(int, int)>("set_input_size", &cv::dnn::dnn4_v20241223::Model::setInputSize,
      Arg("width"), Arg("height")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(const cv::Scalar&)>("set_input_mean", &cv::dnn::dnn4_v20241223::Model::setInputMean,
      Arg("mean")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(const cv::Scalar&)>("set_input_scale", &cv::dnn::dnn4_v20241223::Model::setInputScale,
      Arg("scale")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(bool)>("set_input_crop", &cv::dnn::dnn4_v20241223::Model::setInputCrop,
      Arg("crop")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(bool)>("set_input_swap_rb", &cv::dnn::dnn4_v20241223::Model::setInputSwapRB,
      Arg("swap_rb")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(const std::vector<std::basic_string<char>>&)>("set_output_names", &cv::dnn::dnn4_v20241223::Model::setOutputNames,
      Arg("out_names")).
    define_method<void(cv::dnn::dnn4_v20241223::Model::*)(double, const cv::Size&, const cv::Scalar&, bool, bool)>("set_input_params", &cv::dnn::dnn4_v20241223::Model::setInputParams,
      Arg("scale") = static_cast<double>(1.0), Arg("size") = static_cast<const cv::Size&>(cv::Size()), Arg("mean") = static_cast<const cv::Scalar&>(cv::Scalar()), Arg("swap_rb") = static_cast<bool>(false), Arg("crop") = static_cast<bool>(false)).
    define_method<void(cv::dnn::dnn4_v20241223::Model::*)(cv::InputArray, cv::OutputArrayOfArrays) const>("predict", &cv::dnn::dnn4_v20241223::Model::predict,
      Arg("frame"), Arg("outs")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(cv::dnn::dnn4_v20241223::Backend)>("set_preferable_backend", &cv::dnn::dnn4_v20241223::Model::setPreferableBackend,
      Arg("backend_id")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(cv::dnn::dnn4_v20241223::Target)>("set_preferable_target", &cv::dnn::dnn4_v20241223::Model::setPreferableTarget,
      Arg("target_id")).
    define_method<cv::dnn::dnn4_v20241223::Model&(cv::dnn::dnn4_v20241223::Model::*)(bool)>("enable_winograd", &cv::dnn::dnn4_v20241223::Model::enableWinograd,
      Arg("use_winograd")).
    define_method<cv::dnn::dnn4_v20241223::Model::Impl*(cv::dnn::dnn4_v20241223::Model::*)() const>("get_impl", &cv::dnn::dnn4_v20241223::Model::getImpl).
    define_method<cv::dnn::dnn4_v20241223::Model::Impl&(cv::dnn::dnn4_v20241223::Model::*)() const>("get_impl_ref", &cv::dnn::dnn4_v20241223::Model::getImplRef);

  Rice::Data_Type<cv::dnn::dnn4_v20241223::ClassificationModel> rb_cCvDnnDnn4V20241223ClassificationModel = define_class_under<cv::dnn::dnn4_v20241223::ClassificationModel, cv::dnn::dnn4_v20241223::Model>(rb_mCvDnnDnn4V20241223, "ClassificationModel").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ClassificationModel, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::ClassificationModel, const cv::dnn::dnn4_v20241223::Net&>(),
      Arg("network")).
    define_method<cv::dnn::dnn4_v20241223::ClassificationModel&(cv::dnn::dnn4_v20241223::ClassificationModel::*)(bool)>("set_enable_softmax_post_processing", &cv::dnn::dnn4_v20241223::ClassificationModel::setEnableSoftmaxPostProcessing,
      Arg("enable")).
    define_method<bool(cv::dnn::dnn4_v20241223::ClassificationModel::*)() const>("get_enable_softmax_post_processing?", &cv::dnn::dnn4_v20241223::ClassificationModel::getEnableSoftmaxPostProcessing).
    define_method<std::pair<int, float>(cv::dnn::dnn4_v20241223::ClassificationModel::*)(cv::InputArray)>("classify", &cv::dnn::dnn4_v20241223::ClassificationModel::classify,
      Arg("frame")).
    define_method<void(cv::dnn::dnn4_v20241223::ClassificationModel::*)(cv::InputArray, int&, float&)>("classify", &cv::dnn::dnn4_v20241223::ClassificationModel::classify,
      Arg("frame"), Arg("class_id"), Arg("conf"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::KeypointsModel> rb_cCvDnnDnn4V20241223KeypointsModel = define_class_under<cv::dnn::dnn4_v20241223::KeypointsModel, cv::dnn::dnn4_v20241223::Model>(rb_mCvDnnDnn4V20241223, "KeypointsModel").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::KeypointsModel, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::KeypointsModel, const cv::dnn::dnn4_v20241223::Net&>(),
      Arg("network")).
    define_method<std::vector<cv::Point_<float>>(cv::dnn::dnn4_v20241223::KeypointsModel::*)(cv::InputArray, float)>("estimate", &cv::dnn::dnn4_v20241223::KeypointsModel::estimate,
      Arg("frame"), Arg("thresh") = static_cast<float>(0.5));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::SegmentationModel> rb_cCvDnnDnn4V20241223SegmentationModel = define_class_under<cv::dnn::dnn4_v20241223::SegmentationModel, cv::dnn::dnn4_v20241223::Model>(rb_mCvDnnDnn4V20241223, "SegmentationModel").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SegmentationModel, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::SegmentationModel, const cv::dnn::dnn4_v20241223::Net&>(),
      Arg("network")).
    define_method<void(cv::dnn::dnn4_v20241223::SegmentationModel::*)(cv::InputArray, cv::OutputArray)>("segment", &cv::dnn::dnn4_v20241223::SegmentationModel::segment,
      Arg("frame"), Arg("mask"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::DetectionModel> rb_cCvDnnDnn4V20241223DetectionModel = define_class_under<cv::dnn::dnn4_v20241223::DetectionModel, cv::dnn::dnn4_v20241223::Model>(rb_mCvDnnDnn4V20241223, "DetectionModel").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DetectionModel, const cv::String&, const cv::String&>(),
      Arg("model"), Arg("config") = static_cast<const cv::String&>("")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::DetectionModel, const cv::dnn::dnn4_v20241223::Net&>(),
      Arg("network")).
    define_method<cv::dnn::dnn4_v20241223::DetectionModel&(cv::dnn::dnn4_v20241223::DetectionModel::*)(bool)>("set_nms_across_classes", &cv::dnn::dnn4_v20241223::DetectionModel::setNmsAcrossClasses,
      Arg("value")).
    define_method<bool(cv::dnn::dnn4_v20241223::DetectionModel::*)()>("get_nms_across_classes?", &cv::dnn::dnn4_v20241223::DetectionModel::getNmsAcrossClasses).
    define_method<void(cv::dnn::dnn4_v20241223::DetectionModel::*)(cv::InputArray, std::vector<int>&, std::vector<float>&, std::vector<cv::Rect_<int>>&, float, float)>("detect", &cv::dnn::dnn4_v20241223::DetectionModel::detect,
      Arg("frame"), Arg("class_ids"), Arg("confidences"), Arg("boxes"), Arg("conf_threshold") = static_cast<float>(0.5f), Arg("nms_threshold") = static_cast<float>(0.0f));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::TextRecognitionModel> rb_cCvDnnDnn4V20241223TextRecognitionModel = define_class_under<cv::dnn::dnn4_v20241223::TextRecognitionModel, cv::dnn::dnn4_v20241223::Model>(rb_mCvDnnDnn4V20241223, "TextRecognitionModel").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TextRecognitionModel, const cv::dnn::dnn4_v20241223::Net&>(),
      Arg("network")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TextRecognitionModel, const std::string&, const std::string&>(),
      Arg("model"), Arg("config") = static_cast<const std::string&>("")).
    define_method<cv::dnn::dnn4_v20241223::TextRecognitionModel&(cv::dnn::dnn4_v20241223::TextRecognitionModel::*)(const std::string&)>("set_decode_type", &cv::dnn::dnn4_v20241223::TextRecognitionModel::setDecodeType,
      Arg("decode_type")).
    define_method<const std::string&(cv::dnn::dnn4_v20241223::TextRecognitionModel::*)() const>("get_decode_type", &cv::dnn::dnn4_v20241223::TextRecognitionModel::getDecodeType).
    define_method<cv::dnn::dnn4_v20241223::TextRecognitionModel&(cv::dnn::dnn4_v20241223::TextRecognitionModel::*)(int, int)>("set_decode_opts_ctc_prefix_beam_search", &cv::dnn::dnn4_v20241223::TextRecognitionModel::setDecodeOptsCTCPrefixBeamSearch,
      Arg("beam_size"), Arg("voc_prune_size") = static_cast<int>(0)).
    define_method<cv::dnn::dnn4_v20241223::TextRecognitionModel&(cv::dnn::dnn4_v20241223::TextRecognitionModel::*)(const std::vector<std::string>&)>("set_vocabulary", &cv::dnn::dnn4_v20241223::TextRecognitionModel::setVocabulary,
      Arg("vocabulary")).
    define_method<const std::vector<std::string>&(cv::dnn::dnn4_v20241223::TextRecognitionModel::*)() const>("get_vocabulary", &cv::dnn::dnn4_v20241223::TextRecognitionModel::getVocabulary).
    define_method<std::string(cv::dnn::dnn4_v20241223::TextRecognitionModel::*)(cv::InputArray) const>("recognize", &cv::dnn::dnn4_v20241223::TextRecognitionModel::recognize,
      Arg("frame")).
    define_method<void(cv::dnn::dnn4_v20241223::TextRecognitionModel::*)(cv::InputArray, cv::InputArrayOfArrays, std::vector<std::string>&) const>("recognize", &cv::dnn::dnn4_v20241223::TextRecognitionModel::recognize,
      Arg("frame"), Arg("roi_rects"), Arg("results"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::TextDetectionModel> rb_cCvDnnDnn4V20241223TextDetectionModel = define_class_under<cv::dnn::dnn4_v20241223::TextDetectionModel, cv::dnn::dnn4_v20241223::Model>(rb_mCvDnnDnn4V20241223, "TextDetectionModel").
    define_method<void(cv::dnn::dnn4_v20241223::TextDetectionModel::*)(cv::InputArray, std::vector<std::vector<cv::Point_<int>>>&, std::vector<float>&) const>("detect", &cv::dnn::dnn4_v20241223::TextDetectionModel::detect,
      Arg("frame"), Arg("detections"), Arg("confidences")).
    define_method<void(cv::dnn::dnn4_v20241223::TextDetectionModel::*)(cv::InputArray, std::vector<std::vector<cv::Point_<int>>>&) const>("detect", &cv::dnn::dnn4_v20241223::TextDetectionModel::detect,
      Arg("frame"), Arg("detections")).
    define_method<void(cv::dnn::dnn4_v20241223::TextDetectionModel::*)(cv::InputArray, std::vector<cv::RotatedRect>&, std::vector<float>&) const>("detect_text_rectangles", &cv::dnn::dnn4_v20241223::TextDetectionModel::detectTextRectangles,
      Arg("frame"), Arg("detections"), Arg("confidences")).
    define_method<void(cv::dnn::dnn4_v20241223::TextDetectionModel::*)(cv::InputArray, std::vector<cv::RotatedRect>&) const>("detect_text_rectangles", &cv::dnn::dnn4_v20241223::TextDetectionModel::detectTextRectangles,
      Arg("frame"), Arg("detections"));

  Rice::Data_Type<cv::dnn::dnn4_v20241223::TextDetectionModel_EAST> rb_cCvDnnDnn4V20241223TextDetectionModelEAST = define_class_under<cv::dnn::dnn4_v20241223::TextDetectionModel_EAST, cv::dnn::dnn4_v20241223::TextDetectionModel>(rb_mCvDnnDnn4V20241223, "TextDetectionModelEAST").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TextDetectionModel_EAST, const cv::dnn::dnn4_v20241223::Net&>(),
      Arg("network")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TextDetectionModel_EAST, const std::string&, const std::string&>(),
      Arg("model"), Arg("config") = static_cast<const std::string&>("")).
    define_method<cv::dnn::dnn4_v20241223::TextDetectionModel_EAST&(cv::dnn::dnn4_v20241223::TextDetectionModel_EAST::*)(float)>("set_confidence_threshold", &cv::dnn::dnn4_v20241223::TextDetectionModel_EAST::setConfidenceThreshold,
      Arg("conf_threshold")).
    define_method<float(cv::dnn::dnn4_v20241223::TextDetectionModel_EAST::*)() const>("get_confidence_threshold", &cv::dnn::dnn4_v20241223::TextDetectionModel_EAST::getConfidenceThreshold).
    define_method<cv::dnn::dnn4_v20241223::TextDetectionModel_EAST&(cv::dnn::dnn4_v20241223::TextDetectionModel_EAST::*)(float)>("set_nms_threshold", &cv::dnn::dnn4_v20241223::TextDetectionModel_EAST::setNMSThreshold,
      Arg("nms_threshold")).
    define_method<float(cv::dnn::dnn4_v20241223::TextDetectionModel_EAST::*)() const>("get_nms_threshold", &cv::dnn::dnn4_v20241223::TextDetectionModel_EAST::getNMSThreshold);

  Rice::Data_Type<cv::dnn::dnn4_v20241223::TextDetectionModel_DB> rb_cCvDnnDnn4V20241223TextDetectionModelDB = define_class_under<cv::dnn::dnn4_v20241223::TextDetectionModel_DB, cv::dnn::dnn4_v20241223::TextDetectionModel>(rb_mCvDnnDnn4V20241223, "TextDetectionModelDB").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TextDetectionModel_DB, const cv::dnn::dnn4_v20241223::Net&>(),
      Arg("network")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::TextDetectionModel_DB, const std::string&, const std::string&>(),
      Arg("model"), Arg("config") = static_cast<const std::string&>("")).
    define_method<cv::dnn::dnn4_v20241223::TextDetectionModel_DB&(cv::dnn::dnn4_v20241223::TextDetectionModel_DB::*)(float)>("set_binary_threshold", &cv::dnn::dnn4_v20241223::TextDetectionModel_DB::setBinaryThreshold,
      Arg("binary_threshold")).
    define_method<float(cv::dnn::dnn4_v20241223::TextDetectionModel_DB::*)() const>("get_binary_threshold", &cv::dnn::dnn4_v20241223::TextDetectionModel_DB::getBinaryThreshold).
    define_method<cv::dnn::dnn4_v20241223::TextDetectionModel_DB&(cv::dnn::dnn4_v20241223::TextDetectionModel_DB::*)(float)>("set_polygon_threshold", &cv::dnn::dnn4_v20241223::TextDetectionModel_DB::setPolygonThreshold,
      Arg("polygon_threshold")).
    define_method<float(cv::dnn::dnn4_v20241223::TextDetectionModel_DB::*)() const>("get_polygon_threshold", &cv::dnn::dnn4_v20241223::TextDetectionModel_DB::getPolygonThreshold).
    define_method<cv::dnn::dnn4_v20241223::TextDetectionModel_DB&(cv::dnn::dnn4_v20241223::TextDetectionModel_DB::*)(double)>("set_unclip_ratio", &cv::dnn::dnn4_v20241223::TextDetectionModel_DB::setUnclipRatio,
      Arg("unclip_ratio")).
    define_method<double(cv::dnn::dnn4_v20241223::TextDetectionModel_DB::*)() const>("get_unclip_ratio", &cv::dnn::dnn4_v20241223::TextDetectionModel_DB::getUnclipRatio).
    define_method<cv::dnn::dnn4_v20241223::TextDetectionModel_DB&(cv::dnn::dnn4_v20241223::TextDetectionModel_DB::*)(int)>("set_max_candidates", &cv::dnn::dnn4_v20241223::TextDetectionModel_DB::setMaxCandidates,
      Arg("max_candidates")).
    define_method<int(cv::dnn::dnn4_v20241223::TextDetectionModel_DB::*)() const>("get_max_candidates", &cv::dnn::dnn4_v20241223::TextDetectionModel_DB::getMaxCandidates);
}