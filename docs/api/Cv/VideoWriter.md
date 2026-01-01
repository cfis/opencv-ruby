#[VideoWriter](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html)
## Singleton Methods
[fourcc](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#afec93f94dc6c0b3e28f4dd153bc5a7f0)(c1: [String](https://docs.ruby-lang.org/en/master/String.html), c2: [String](https://docs.ruby-lang.org/en/master/String.html), c3: [String](https://docs.ruby-lang.org/en/master/String.html), c4: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#ad59c61d8881ba2b2da22cff5487465b5)()

[initialize](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#ad59c61d8881ba2b2da22cff5487465b5)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), fourcc: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fps: [Float](https://docs.ruby-lang.org/en/master/Float.html), frame_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), is_color: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html))

[initialize](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#ad59c61d8881ba2b2da22cff5487465b5)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), fourcc: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fps: [Float](https://docs.ruby-lang.org/en/master/Float.html), frame_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html))

[initialize](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#ad59c61d8881ba2b2da22cff5487465b5)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fourcc: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fps: [Float](https://docs.ruby-lang.org/en/master/Float.html), frame_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), is_color: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html))

[initialize](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#ad59c61d8881ba2b2da22cff5487465b5)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fourcc: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fps: [Float](https://docs.ruby-lang.org/en/master/Float.html), frame_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html))


## Methods
[<<](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#ae29ac7d5b4b964f707efc598fb37dfc5)(image: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [Cv::VideoWriter](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html)

[<<](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#ae29ac7d5b4b964f707efc598fb37dfc5)(image: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [Cv::VideoWriter](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html)

[get](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a284e798e95847789024954abeec945d5)(prop_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_backend_name](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a1dced14e3773cc1239972342afc274fc) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[open](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a8b44d21f9bb5a02f531b50bbb15b9527)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), fourcc: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fps: [Float](https://docs.ruby-lang.org/en/master/Float.html), frame_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[open](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a8b44d21f9bb5a02f531b50bbb15b9527)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), fourcc: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fps: [Float](https://docs.ruby-lang.org/en/master/Float.html), frame_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), is_color: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[open](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a8b44d21f9bb5a02f531b50bbb15b9527)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fourcc: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fps: [Float](https://docs.ruby-lang.org/en/master/Float.html), frame_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), params: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[open](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a8b44d21f9bb5a02f531b50bbb15b9527)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), api_preference: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fourcc: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), fps: [Float](https://docs.ruby-lang.org/en/master/Float.html), frame_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), is_color: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[opened?](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a9a40803e5f671968ac9efa877c984d75) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[release](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a667f737e56d5ba6b0533c6c7bf941140) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a7ba668f440d8af5e1a92df58b2475816)(prop_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), value: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[write](https://docs.opencv.org/4.x/dd/d9e/classcv_1_1VideoWriter.html#a30ebbc09c122332f62bd706b43f02a98)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


