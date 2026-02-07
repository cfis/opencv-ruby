#ClassificationModel
## Constructors
initialize(network: Cv::Dnn::Net)

initialize(model: [String](https://docs.ruby-lang.org/en/master/String.html), config: [String](https://docs.ruby-lang.org/en/master/String.html))


## Methods
classify(frame: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Std::Pair≺int‚ float≻](https://en.cppreference.com/w/cpp/utility/pair.html)

classify(frame: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), class_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), conf: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_enable_softmax_post_processing? -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

set_enable_softmax_post_processing(enable: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Dnn::ClassificationModel


