#[VideoCapture](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html)
## Singleton Methods
[wait_any](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#ade1c7b8d276fea4d000bc0af0f1017b3)(streams: [Std::Vector≺cv꞉꞉VideoCapture≻](https://en.cppreference.com/w/cpp/container/vector.html), ready_index: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), timeout_ns: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a57c0e81e83e60f36c83027dc2a188e80)()

[initialize](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a57c0e81e83e60f36c83027dc2a188e80)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))

[initialize](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a57c0e81e83e60f36c83027dc2a188e80)(index: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))

[initialize](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a57c0e81e83e60f36c83027dc2a188e80)(source: Cv::Ptr≺cv꞉꞉IStreamReader≻, api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html))

[initialize](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a57c0e81e83e60f36c83027dc2a188e80)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html))

[initialize](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a57c0e81e83e60f36c83027dc2a188e80)(index: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html))


## Methods
>>(image: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [Cv::VideoCapture](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html)

>>(image: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [Cv::VideoCapture](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html)

[get_backend_name](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a4576e03f447abfdbd602c0809824ec03) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[get](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#aa6480e6972ef4c00d74814ec841a2939)(prop_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_exception_mode?](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a811ac1629c09f4ee0328712a42b7f851) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[grab](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#ae38c2a053d39d6b20c9c649e08ff0146) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[open](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a37913018b736ed917aa3b1976efc3d0c)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[open](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a37913018b736ed917aa3b1976efc3d0c)(index: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[open](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a37913018b736ed917aa3b1976efc3d0c)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[open](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a37913018b736ed917aa3b1976efc3d0c)(source: Cv::Ptr≺cv꞉꞉IStreamReader≻, api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[open](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a37913018b736ed917aa3b1976efc3d0c)(index: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[opened?](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a9d2ca36789e7fcfe7a7be3b328038585) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[read](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a473055e77dd7faa4d26d686226b292c1)(image: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[release](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#afb4ab689e553ba2c8f0fec41b9344ae6) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[retrieve](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a9ac7f4b1cdfe624663478568486e6712)(image: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), flag: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[set](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#a8c6d8c2d37505b5ca61ffd4bb54e9a7c)(prop_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), value: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[set_exception_mode](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html#afcab97adfa090883dce5523e9ebcb995)(enable: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


