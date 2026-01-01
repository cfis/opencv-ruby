#Net
## Singleton Methods
read_from_model_optimizer(buffer_model_config: [Std::Vector≺unsigned char≻](https://en.cppreference.com/w/cpp/container/vector.html), buffer_weights: [Std::Vector≺unsigned char≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> Cv::Dnn::Net

read_from_model_optimizer(xml: [String](https://docs.ruby-lang.org/en/master/String.html), bin: [String](https://docs.ruby-lang.org/en/master/String.html)) -> Cv::Dnn::Net

read_from_model_optimizer(buffer_model_config_ptr: [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), buffer_model_config_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), buffer_weights_ptr: [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), buffer_weights_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Dnn::Net


## Constructors
initialize()


## Methods
add_layer(name: [String](https://docs.ruby-lang.org/en/master/String.html), type: [String](https://docs.ruby-lang.org/en/master/String.html), params: Cv::Dnn::LayerParams) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

add_layer(name: [String](https://docs.ruby-lang.org/en/master/String.html), type: [String](https://docs.ruby-lang.org/en/master/String.html), dtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: Cv::Dnn::LayerParams) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

add_layer_to_prev(name: [String](https://docs.ruby-lang.org/en/master/String.html), type: [String](https://docs.ruby-lang.org/en/master/String.html), params: Cv::Dnn::LayerParams) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

add_layer_to_prev(name: [String](https://docs.ruby-lang.org/en/master/String.html), type: [String](https://docs.ruby-lang.org/en/master/String.html), dtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: Cv::Dnn::LayerParams) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

connect(out_pin: [String](https://docs.ruby-lang.org/en/master/String.html), inp_pin: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

connect(out_layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), out_num: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), inp_layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), inp_num: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

dump -> [String](https://docs.ruby-lang.org/en/master/String.html)

dump_to_file(path: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

dump_to_pbtxt(path: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

empty? -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

enable_fusion(fusion: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

enable_winograd(use_winograd: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

forward(output_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

forward(output_blobs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), output_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

forward(output_blobs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), out_blob_names: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

forward(output_blobs: [Std::Vector≺vector≺cv꞉꞉Mat≻≻](https://en.cppreference.com/w/cpp/container/vector.html), out_blob_names: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

forward_async(output_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Cv::AsyncArray](https://docs.opencv.org/4.x/d4/d20/classcv_1_1AsyncArray.html)

get_flops(net_input_shape: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

get_flops(net_input_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

get_flops(layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), net_input_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

get_flops(layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), net_input_shape: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

get_input_details(scales: [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html), zeropoints: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_layer(layer_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> Cv::Ptr≺cv꞉꞉dnn꞉꞉dnn4V20241223꞉꞉Layer≻

get_layer(layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Ptr≺cv꞉꞉dnn꞉꞉dnn4V20241223꞉꞉Layer≻

get_layer(layer_id: Cv::Dnn::Dnn4V20241223::DictValue) -> Cv::Ptr≺cv꞉꞉dnn꞉꞉dnn4V20241223꞉꞉Layer≻

get_layer_id(layer: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

get_layer_inputs(layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Std::Vector≺cv꞉꞉Ptr≺cv꞉꞉dnn꞉꞉dnn4V20241223꞉꞉Layer≻≻](https://en.cppreference.com/w/cpp/container/vector.html)

get_layer_names -> [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)

get_layer_shapes(net_input_shape: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), in_layer_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), out_layer_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_layer_shapes(net_input_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), in_layer_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), out_layer_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_layer_types(layers_types: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_layers_count(layer_type: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

get_layers_shapes(net_input_shape: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), layers_ids: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), in_layers_shapes: [Std::Vector≺vector≺vector≺int≻≻≻](https://en.cppreference.com/w/cpp/container/vector.html), out_layers_shapes: [Std::Vector≺vector≺vector≺int≻≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_layers_shapes(net_input_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), layers_ids: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), in_layers_shapes: [Std::Vector≺vector≺vector≺int≻≻≻](https://en.cppreference.com/w/cpp/container/vector.html), out_layers_shapes: [Std::Vector≺vector≺vector≺int≻≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_memory_consumption(net_input_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), weights: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), blobs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_memory_consumption(net_input_shape: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), weights: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), blobs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_memory_consumption(layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), net_input_shape: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), weights: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), blobs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_memory_consumption(layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), net_input_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), weights: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), blobs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_memory_consumption(net_input_shapes: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), layer_ids: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), weights: [Std::Vector≺unsigned Int64≻](https://en.cppreference.com/w/cpp/container/vector.html), blobs: [Std::Vector≺unsigned Int64≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_memory_consumption(net_input_shape: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), layer_ids: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), weights: [Std::Vector≺unsigned Int64≻](https://en.cppreference.com/w/cpp/container/vector.html), blobs: [Std::Vector≺unsigned Int64≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_output_details(scales: [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html), zeropoints: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_param(layer: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), num_param: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

get_param(layer_name: [String](https://docs.ruby-lang.org/en/master/String.html), num_param: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

get_perf_profile(timings: [Std::Vector≺double≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

get_unconnected_out_layers -> [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)

get_unconnected_out_layers_names -> [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)

quantize(calib_data: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), inputs_dtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), outputs_dtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), per_channel: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Dnn::Net

register_output(output_name: [String](https://docs.ruby-lang.org/en/master/String.html), layer_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), output_port: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

set_halide_scheduler(scheduler: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_input(blob: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), name: [String](https://docs.ruby-lang.org/en/master/String.html), scalefactor: [Float](https://docs.ruby-lang.org/en/master/Float.html), mean: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_input_shape(input_name: [String](https://docs.ruby-lang.org/en/master/String.html), shape: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_inputs_names(input_blob_names: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_param(layer_name: [String](https://docs.ruby-lang.org/en/master/String.html), num_param: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), blob: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_param(layer: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), num_param: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), blob: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_preferable_backend(backend_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_preferable_target(target_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


