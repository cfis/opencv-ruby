#Model
## Constructors
initialize(network: Cv::Dnn::Net)

initialize(model: [String](https://docs.ruby-lang.org/en/master/String.html), config: [String](https://docs.ruby-lang.org/en/master/String.html))


## Methods
assign(: Cv::Dnn::Model) -> Cv::Dnn::Model

assign(: Cv::Dnn::Model) -> Cv::Dnn::Model

enable_winograd(use_winograd: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Dnn::Model

get_network_ -> Cv::Dnn::Net

get_network_ -> Cv::Dnn::Net

initialize_copy(: Cv::Dnn::Model) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

predict(frame: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), outs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_input_crop(crop: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Dnn::Model

set_input_mean(mean: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html)) -> Cv::Dnn::Model

set_input_params(scale: [Float](https://docs.ruby-lang.org/en/master/Float.html), size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), mean: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html), swap_rb: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), crop: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_input_scale(scale: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html)) -> Cv::Dnn::Model

set_input_size(size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)) -> Cv::Dnn::Model

set_input_size(width: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), height: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Dnn::Model

set_input_swap_rb(swap_rb: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Dnn::Model

set_output_names(out_names: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> Cv::Dnn::Model

set_preferable_backend(backend_id: Cv::Dnn::Backend) -> Cv::Dnn::Model

set_preferable_target(target_id: Cv::Dnn::Target) -> Cv::Dnn::Model


