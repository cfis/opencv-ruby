#[BarcodeDetector](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#a32cd1e18079a627a5e076fadd4dd8cb8)()

[initialize](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#a32cd1e18079a627a5e076fadd4dd8cb8)(prototxt_path: [String](https://docs.ruby-lang.org/en/master/String.html), model_path: [String](https://docs.ruby-lang.org/en/master/String.html))


## Methods
[decode_with_type](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#aa29ffabea4173ed22b648f73c8058f0d)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), points: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), decoded_info: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html), decoded_type: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[detect_and_decode_with_type](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#a305fe500187fd79111f6542b39885a03)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), decoded_info: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html), decoded_type: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html), points: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[get_detector_scales](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#a06726e841beb2ef1a509207b065313d7)(sizes: [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_downsampling_threshold](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#a160aeff69ed30f8a72b4354501ba96d3) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_gradient_threshold](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#a4c1302dc1c0959614b9436818f725722) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[set_detector_scales](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#a0b7a48d55162ef058536fb63bd7ed5c7)(sizes: [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Cv::Barcode::BarcodeDetector](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html)

[set_downsampling_threshold](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#a2c6295b1a403027b12cd66fa7c0a77aa)(thresh: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Barcode::BarcodeDetector](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html)

[set_gradient_threshold](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html#acc9ccc56e8a9301a719873db671483bc)(thresh: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Barcode::BarcodeDetector](https://docs.opencv.org/4.x/dc/df7/classcv_1_1barcode_1_1BarcodeDetector.html)


