#[ChannelsCompensator](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#a82d0c3108d6bd9bd91f4f96424ce224a)(nr_feeds: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Methods
[apply](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#ab45c3aa811a6d380cc77a86dbb87520a)(index: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), corner: [Cv::Point2i](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), image: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[feed](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#adbe4fab11316d30158a89a5602a10e4f)(corners: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), images: [Std::Vector≺cv꞉꞉UMat≻](https://en.cppreference.com/w/cpp/container/vector.html), masks: [Std::Vector≺pair≺cv꞉꞉UMat‚ unsigned char≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[gains](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#a09cf0481d4d4844d0128907a218e8383) -> [Std::Vector≺cv꞉꞉Scalar_≺double≻≻](https://en.cppreference.com/w/cpp/container/vector.html)

[get_mat_gains](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#ae9025ce3ef7fefba4ac9d595ec52942b)(umv: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_nr_feeds](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#ae2b9873838e6b5e4593a30066a65b3e3) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_similarity_threshold](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#a0745134e4aba277eb638fd813c8496de) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[set_mat_gains](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#a85d57777086b146524334bc4224f9f80)(umv: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_nr_feeds](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#a0e88972a7011b2a112e4fe20346d4f35)(nr_feeds: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_similarity_threshold](https://docs.opencv.org/4.x/d4/ddd/classcv_1_1detail_1_1ChannelsCompensator.html#a5ece2d2f10bb1c4a14e874da0914df82)(similarity_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


