#[AffineWarper](https://docs.opencv.org/4.x/dd/d76/classcv_1_1detail_1_1AffineWarper.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/dd/d76/classcv_1_1detail_1_1AffineWarper.html#a579d8f21ca8ef2e7b68c7c3fe04445a9)(scale: [Float](https://docs.ruby-lang.org/en/master/Float.html))


## Methods
[build_maps](https://docs.opencv.org/4.x/dd/d76/classcv_1_1detail_1_1AffineWarper.html#a489b254ef6deaac009cb07ad27a68ed5)(src_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), h: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), xmap: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), ymap: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Rect](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)

[warp](https://docs.opencv.org/4.x/dd/d76/classcv_1_1detail_1_1AffineWarper.html#acdb3c99a7867ebe15cd8b5b82d33ce29)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), h: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), interp_mode: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), border_mode: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Point](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)

[warp_point](https://docs.opencv.org/4.x/dd/d76/classcv_1_1detail_1_1AffineWarper.html#a2ad6297c62b422ee0f2cb0c6324e24f2)(pt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), h: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)

[warp_point_backward](https://docs.opencv.org/4.x/dd/d76/classcv_1_1detail_1_1AffineWarper.html#a0118c2ffe4aca551bb307e3a7710ad00)(pt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), h: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)

[warp_roi](https://docs.opencv.org/4.x/dd/d76/classcv_1_1detail_1_1AffineWarper.html#acf30b2c7f1cd18405b35d9b3cb1d8031)(src_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), h: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Rect](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)


