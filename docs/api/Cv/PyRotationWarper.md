#[PyRotationWarper](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a965c0546abb140199df38238e72e23f5)()

[initialize](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a965c0546abb140199df38238e72e23f5)(type: [String](https://docs.ruby-lang.org/en/master/String.html), scale: [Float](https://docs.ruby-lang.org/en/master/Float.html))


## Methods
[build_maps](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a1f00fe4be63c3afde6cc62632880ef76)(src_size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), r: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), xmap: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), ymap: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Rect2i](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)

[get_scale](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a328c357d3533d200adcf19037c93fdce) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[set_scale](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a90b000bb75f95294f9b0b6ec9859eb55)(arg_0: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[warp](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#aaaeb825550de56efc469d8fb10967acb)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), r: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), interp_mode: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), border_mode: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Point2i](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)

[warp_backward](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a1d9553ae2b6bdd1ad34e1903e6d1f6c7)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), r: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), interp_mode: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), border_mode: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), dst_size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[warp_point](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a566d46df185295ddc5e09ee1c3ce5d9d)(pt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), r: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)

[warp_point_backward](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a5664bd69b4bb64a5d5740f3f59579e5d)(pt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), r: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)

[warp_roi](https://docs.opencv.org/4.x/d5/d76/classcv_1_1PyRotationWarper.html#a3afece82103726fd89e9954015b18da3)(src_size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), k: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), r: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Rect2i](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)


