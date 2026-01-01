#DetectionModel
## Constructors
initialize(network: Cv::Dnn::Net)

initialize(model: [String](https://docs.ruby-lang.org/en/master/String.html), config: [String](https://docs.ruby-lang.org/en/master/String.html))


## Methods
detect(frame: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), class_ids: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), confidences: [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html), boxes: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), conf_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), nms_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_nms_across_classes -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

set_nms_across_classes(value: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Dnn::DetectionModel


