#[FaceDetectorYN](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#aa0796a4bfe2d4709bef81abbae9a927a)(model: [String](https://docs.ruby-lang.org/en/master/String.html), config: [String](https://docs.ruby-lang.org/en/master/String.html), input_size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), score_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), nms_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), top_k: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), backend_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), target_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Ptr≺cv꞉꞉FaceDetectorYN≻

[create](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#aa0796a4bfe2d4709bef81abbae9a927a)(framework: [String](https://docs.ruby-lang.org/en/master/String.html), buffer_model: [Std::Vector≺unsigned char≻](https://en.cppreference.com/w/cpp/container/vector.html), buffer_config: [Std::Vector≺unsigned char≻](https://en.cppreference.com/w/cpp/container/vector.html), input_size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), score_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), nms_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), top_k: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), backend_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), target_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Ptr≺cv꞉꞉FaceDetectorYN≻


## Methods
[detect](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#ac05bd075ca3e6edc0e328927aae6f45b)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), faces: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_input_size](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#a68b6fb9bffbed0f3d5c104996113f247) -> [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)

[get_nms_threshold](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#a40749dc04b9578631d55122be9ab10c3) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_score_threshold](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#a5329744e10441e1c01526f1ff10b80de) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_top_k](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#acc6139ba763acd67f4aa738cee45b7ec) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[set_input_size](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#a072418e5ce7beeb69c41edda75c41d2e)(input_size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_nms_threshold(nms_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_score_threshold](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#a37f3c23b82158fac7fdad967d315f85a)(score_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_top_k](https://docs.opencv.org/4.x/df/d20/classcv_1_1FaceDetectorYN.html#aa88d20e1e2df75ea36b851534089856a)(top_k: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


