#[Feature2D](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html)()


## Methods
[compute](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#ab3cce8d56f4fc5e1d530b5931e1e8dc0)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), keypoints: [Std::Vector≺vector≺cv꞉꞉KeyPoint≻≻](https://en.cppreference.com/w/cpp/container/vector.html), descriptors: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[compute](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#ab3cce8d56f4fc5e1d530b5931e1e8dc0)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), keypoints: [Std::Vector≺cv꞉꞉KeyPoint≻](https://en.cppreference.com/w/cpp/container/vector.html), descriptors: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[default_norm](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#a90e93108d3d7ffdf21889a2f1aa1faa8) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[descriptor_size](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#ae9e03d8657032baa5ecc1368e5adc7a7) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[descriptor_type](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#a54e6b0fa61e69398f3cff77800e142cb) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[detect](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#aa4e9a7082ec61ebc108806704fbd7887)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), keypoints: [Std::Vector≺cv꞉꞉KeyPoint≻](https://en.cppreference.com/w/cpp/container/vector.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#aa4e9a7082ec61ebc108806704fbd7887)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), keypoints: [Std::Vector≺vector≺cv꞉꞉KeyPoint≻≻](https://en.cppreference.com/w/cpp/container/vector.html), masks: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect_and_compute](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#a8be0d1c20b08eb867184b8d74c15a677)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), keypoints: [Std::Vector≺cv꞉꞉KeyPoint≻](https://en.cppreference.com/w/cpp/container/vector.html), descriptors: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), use_provided_keypoints: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[empty?](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#ae5fbe71c7d46427671a0845934ae063b) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[get_default_name](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#a40182e88bf6aa2c74311c9927ba056dc) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[read](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#a484d5df8a2768a38073c581f056d91d7)(file_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[read](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#a484d5df8a2768a38073c581f056d91d7)(arg_0: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#aed9ce99af8afa02ddf2fc78c5f46249b)(arg_0: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#aed9ce99af8afa02ddf2fc78c5f46249b)(file_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#aed9ce99af8afa02ddf2fc78c5f46249b)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html), name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/d0/d13/classcv_1_1Feature2D.html#aed9ce99af8afa02ddf2fc78c5f46249b)(fs: Cv::Ptr≺cv꞉꞉FileStorage≻, name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


