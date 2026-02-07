#Layer
## Constructors
initialize()

initialize(params: Cv::Dnn::LayerParams)


## Attributes
blobs: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html) (read/write)

name: [String](https://docs.ruby-lang.org/en/master/String.html) (read/write)

preferable_target: [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

type: [String](https://docs.ruby-lang.org/en/master/String.html) (read/write)


## Methods
finalize(inputs: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), outputs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

forward(inputs: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), outputs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), internals: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

forward_fallback(inputs: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), outputs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), internals: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_flops(inputs: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), outputs: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

get_memory_shapes(inputs: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), required_outputs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), outputs: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), internals: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

get_scale_shift(scale: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), shift: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_scale_zeropoint(scale: [Float](https://docs.ruby-lang.org/en/master/Float.html), zeropoint: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

input_name_to_index(input_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

output_name_to_index(output_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

set_activation(layer: Cv::Ptr≺cv꞉꞉dnn꞉꞉dnn4V20241223꞉꞉ActivationLayer≻) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

set_params_from(params: Cv::Dnn::LayerParams) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

support_backend(backend_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

try_fuse(top: Cv::Ptr≺cv꞉꞉dnn꞉꞉dnn4V20241223꞉꞉Layer≻) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

try_quantize(scales: [Std::Vector≺vector≺float≻≻](https://en.cppreference.com/w/cpp/container/vector.html), zeropoints: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), params: Cv::Dnn::LayerParams) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

unset_attached -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

update_memory_shapes(inputs: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)


