#[GainCompensator](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#a3dc6bb6e656a6c06c63fe9fc068be65d)()

[initialize](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#a3dc6bb6e656a6c06c63fe9fc068be65d)(nr_feeds: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Methods
[apply](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#a46c3121e915fd439f88bbbe3a54b18ef)(index: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), corner: [Cv::Point2i](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), image: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[feed](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#a82008c64988de865ef4ae34491ece331)(corners: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), images: [Std::Vector≺cv꞉꞉UMat≻](https://en.cppreference.com/w/cpp/container/vector.html), masks: [Std::Vector≺pair≺cv꞉꞉UMat‚ unsigned char≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[gains](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#ad197058e2e8ef67551cd00dfa26883dd) -> [Std::Vector≺double≻](https://en.cppreference.com/w/cpp/container/vector.html)

[get_mat_gains](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#a22c649c8e1fc96028f45de20fb75bcee)(umv: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_nr_feeds](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#adcd5d9a43965661f9c9135bbd8f99669) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_similarity_threshold](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#ab4890727b0f3394e2a415d2f25d9b53f) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[prepare_similarity_mask](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#a62bad342fd81c58c8400be8e73ef5e37)(corners: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), images: [Std::Vector≺cv꞉꞉UMat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_mat_gains](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#acbdf968e6b9b3631f612403ac874bedc)(umv: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_nr_feeds](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#aa1b612c1f334592c084cdf057ce15805)(nr_feeds: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_similarity_threshold](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#a3e41f5f2c4fcebbe74a3b3dee742f44d)(similarity_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[single_feed](https://docs.opencv.org/4.x/d0/de1/classcv_1_1detail_1_1GainCompensator.html#aededd4813e3e2d35f79c04ac40fea9e3)(corners: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), images: [Std::Vector≺cv꞉꞉UMat≻](https://en.cppreference.com/w/cpp/container/vector.html), masks: [Std::Vector≺pair≺cv꞉꞉UMat‚ unsigned char≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


