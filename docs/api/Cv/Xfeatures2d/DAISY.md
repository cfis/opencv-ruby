#[DAISY](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a338622dd3e7d71e51914c40e55be7a41)(radius: [Float](https://docs.ruby-lang.org/en/master/Float.html), q_radius: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), q_theta: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), q_hist: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), norm: [Cv::Xfeatures2d::DAISY::NormalizationType](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#aaf3a347b21a1fd2eeb0b56cce5276151), h: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), interpolation: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), use_orientation: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Ptr≺cv꞉꞉xfeatures2d꞉꞉DAISY≻


## Methods
[compute](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a989b3fe67aadfebf4180ec85dc2cfc4d)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), descriptors: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[compute](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a989b3fe67aadfebf4180ec85dc2cfc4d)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), roi: [Cv::Rect2i](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html), descriptors: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[compute](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a989b3fe67aadfebf4180ec85dc2cfc4d)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), keypoints: [Std::Vector≺vector≺cv꞉꞉KeyPoint≻≻](https://en.cppreference.com/w/cpp/container/vector.html), descriptors: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[compute](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a989b3fe67aadfebf4180ec85dc2cfc4d)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), keypoints: [Std::Vector≺cv꞉꞉KeyPoint≻](https://en.cppreference.com/w/cpp/container/vector.html), descriptors: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_default_name](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#ae123a1067853cc137cfa821b8ada2d2b) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[get_descriptor](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a07ee4ebed1b537167c425952eb15443f)(y: [Float](https://docs.ruby-lang.org/en/master/Float.html), x: [Float](https://docs.ruby-lang.org/en/master/Float.html), orientation: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), descriptor: [Rice::Pointer≺float≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_descriptor](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a07ee4ebed1b537167c425952eb15443f)(y: [Float](https://docs.ruby-lang.org/en/master/Float.html), x: [Float](https://docs.ruby-lang.org/en/master/Float.html), orientation: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), descriptor: [Rice::Pointer≺float≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), h: [Rice::Pointer≺double≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[get_h](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a47bcf3547f6d404dde06c22e5a6d31dd) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_interpolation?](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a3a0585cd8bac16ed065e24f5a54d2e82) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[get_norm](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a8c2c1fbeca34a32b077a481b080920ed) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_q_hist](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a02ee883a00c2b33894e699f2c8f837ef) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_q_radius](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#aecf2371869759c7c28a907f6e4b639b8) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_q_theta](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#aa7d5d28d32100c825302f785bc9b1252) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_radius](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#aee745cbe5aa134d2f520d4aaddcdc6e1) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_unnormalized_descriptor](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#ab4918160e1fad4f37e4286ac7bd8dddc)(y: [Float](https://docs.ruby-lang.org/en/master/Float.html), x: [Float](https://docs.ruby-lang.org/en/master/Float.html), orientation: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), descriptor: [Rice::Pointer≺float≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_unnormalized_descriptor](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#ab4918160e1fad4f37e4286ac7bd8dddc)(y: [Float](https://docs.ruby-lang.org/en/master/Float.html), x: [Float](https://docs.ruby-lang.org/en/master/Float.html), orientation: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), descriptor: [Rice::Pointer≺float≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), h: [Rice::Pointer≺double≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[get_use_orientation?](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#afddaa97532e120bc16baadd8aea618e8) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[set_h](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#aecf6240190eb82ef601dcc88313026f2)(h: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_interpolation](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#aa746f002e2d119cae1c48caf116a0d3a)(interpolation: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_norm](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a26cbd9535e64810d4dc0c7aff87d85b4)(norm: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_q_hist](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a11bbb53f55636b7227ecf5629bd7f25f)(q_hist: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_q_radius](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#ae21e7473a59fa56aa9da879a0e81cd3b)(q_radius: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_q_theta](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#a7050c9316df960bfd9c11f4f14df6145)(q_theta: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_radius](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#aef836e63264f4fdc39bb488ae2b17d70)(radius: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_use_orientation](https://docs.opencv.org/4.x/d9/d37/classcv_1_1xfeatures2d_1_1DAISY.html#adeebcfb72d851f65bbad80290498a84d)(use_orientation: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


