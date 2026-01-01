#[FeatherBlender](https://docs.opencv.org/4.x/d4/d69/classcv_1_1detail_1_1FeatherBlender.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d9/d46/group__stitching__blend.html#ga8af0665c8cb305e32a208a873addece9)(sharpness: [Float](https://docs.ruby-lang.org/en/master/Float.html))


## Methods
[blend](https://docs.opencv.org/4.x/d4/d69/classcv_1_1detail_1_1FeatherBlender.html#a27a1a875fb094c8d0cef755f9cac5955)(dst: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), dst_mask: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[create_weight_maps](https://docs.opencv.org/4.x/d4/d69/classcv_1_1detail_1_1FeatherBlender.html#a8ce9b0e8ccc9cbf68d935782e14e37d3)(masks: [Std::Vector≺cv꞉꞉UMat≻](https://en.cppreference.com/w/cpp/container/vector.html), corners: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), weight_maps: [Std::Vector≺cv꞉꞉UMat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Cv::Rect](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)

[feed](https://docs.opencv.org/4.x/d4/d69/classcv_1_1detail_1_1FeatherBlender.html#a2524f767f9651491a7f81bd363e63e39)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), tl: [Cv::Point](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[prepare](https://docs.opencv.org/4.x/d4/d69/classcv_1_1detail_1_1FeatherBlender.html#a086623ff68da90071aca0fa79ebeaac0)(dst_roi: [Cv::Rect](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_sharpness](https://docs.opencv.org/4.x/d4/d69/classcv_1_1detail_1_1FeatherBlender.html#aa4c09de778a01cdad7af1aabc443b279)(val: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[sharpness](https://docs.opencv.org/4.x/d4/d69/classcv_1_1detail_1_1FeatherBlender.html#a52175c9bf5fb8ccbe692dcec2f575320) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)


