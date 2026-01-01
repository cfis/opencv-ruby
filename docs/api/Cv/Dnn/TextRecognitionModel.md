#TextRecognitionModel
## Constructors
initialize(network: Cv::Dnn::Net)

initialize(model: [String](https://docs.ruby-lang.org/en/master/String.html), config: [String](https://docs.ruby-lang.org/en/master/String.html))


## Methods
get_decode_type -> [String](https://docs.ruby-lang.org/en/master/String.html)

get_vocabulary -> [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)

recognize(frame: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [String](https://docs.ruby-lang.org/en/master/String.html)

recognize(frame: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), roi_rects: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), results: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_decode_opts_ctc_prefix_beam_search(beam_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), voc_prune_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Dnn::TextRecognitionModel

set_decode_type(decode_type: [String](https://docs.ruby-lang.org/en/master/String.html)) -> Cv::Dnn::TextRecognitionModel

set_vocabulary(vocabulary: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> Cv::Dnn::TextRecognitionModel


