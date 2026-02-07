#[BlocksGainCompensator](https://docs.opencv.org/4.x/d7/d81/classcv_1_1detail_1_1BlocksGainCompensator.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d7/d81/classcv_1_1detail_1_1BlocksGainCompensator.html#abca43fc0a398de6c15112f045360a9d1)(bl_width: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), bl_height: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))

[initialize](https://docs.opencv.org/4.x/d7/d81/classcv_1_1detail_1_1BlocksGainCompensator.html#abca43fc0a398de6c15112f045360a9d1)(bl_width: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), bl_height: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), nr_feeds: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Methods
[apply](https://docs.opencv.org/4.x/d7/d81/classcv_1_1detail_1_1BlocksGainCompensator.html#acae1be1bd0051e970ec02764a522e325)(index: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), corner: [Cv::Point2i](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), image: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[feed](https://docs.opencv.org/4.x/d7/d81/classcv_1_1detail_1_1BlocksGainCompensator.html#adfebf2569b39ef2599bc2fe98ac80a59)(corners: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), images: [Std::Vector≺cv꞉꞉UMat≻](https://en.cppreference.com/w/cpp/container/vector.html), masks: [Std::Vector≺pair≺cv꞉꞉UMat‚ unsigned char≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_mat_gains](https://docs.opencv.org/4.x/d7/d81/classcv_1_1detail_1_1BlocksGainCompensator.html#a2633da69063915ed6b0bd9e209a54add)(umv: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_mat_gains](https://docs.opencv.org/4.x/d7/d81/classcv_1_1detail_1_1BlocksGainCompensator.html#a7eaadbd98afa74803b63bc149942dc7f)(umv: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


