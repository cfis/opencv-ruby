#[DetectionBasedTracker](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#aab415fa71206b900ad52ae650ab96636)(main_detector: Cv::Ptr≺cv꞉꞉DetectionBasedTracker꞉꞉IDetector≻, tracking_detector: Cv::Ptr≺cv꞉꞉DetectionBasedTracker꞉꞉IDetector≻, params: [Parameters](https://docs.ruby-lang.org/en/master/Parameters.html))


## Methods
[add_object](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#a91602bf61863fc3126be05a0d3e5416b)(location: [Cv::Rect](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_objects](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#a05c9412496500098db81f1c75421df84)(result: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_objects](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#a05c9412496500098db81f1c75421df84)(result: [Std::Vector≺pair≺cv꞉꞉Rect_≺int≻‚ int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_objects](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#a05c9412496500098db81f1c75421df84)(result: [Std::Vector≺cv꞉꞉DetectionBasedTracker꞉꞉ExtObject≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_parameters](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#a0385adfdbb8a62c5075567d28a1bc6a3) -> [Parameters](https://docs.ruby-lang.org/en/master/Parameters.html)

[process](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#a04010a77df58e838a781889eb4edd303)(image_gray: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[reset_tracking](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#ac5069e92d25b70eb15ca31d856f70ef8) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[run](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#a1038295b9626937e0d3c34c728f23ab1) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[set_parameters?](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#a9d662e7707bc6d8fcc8e6cf687ec273a)(params: [Parameters](https://docs.ruby-lang.org/en/master/Parameters.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[stop](https://docs.opencv.org/4.x/db/de9/classcv_1_1DetectionBasedTracker.html#ac4061f2d28cf54e48360c8aa06135f38) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


