#[Board](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html#af01f0962e1083b3eabbca837177d2811)(obj_points: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), dictionary: [Cv::Aruco::Dictionary](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html), ids: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html))


## Methods
[generate_image](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html#a25b6823cad11256f1043bfd0e51b7c14)(out_size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), img: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), margin_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), border_bits: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_dictionary](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html#ae23d7d30921a16f72f1cc48cec0d2069) -> [Cv::Aruco::Dictionary](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html)

[get_ids](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html#adfa9ca6e48d6cf1cb8b4dfb7dd5c9fef) -> [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)

[get_obj_points](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html#a87e36eafea7b2302bca9cc843ed63663) -> [Std::Vector≺vector≺cv꞉꞉Point3_≺float≻≻≻](https://en.cppreference.com/w/cpp/container/vector.html)

[get_right_bottom_corner](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html#a922ffca04e48b6edf6aa1df873c931ce) -> [Cv::Point3f](https://docs.opencv.org/4.x/df/d6c/classcv_1_1Point3__.html)

[match_image_points](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html#a305c3c47c1f87562ed06de5c7e703e4f)(detected_corners: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), detected_ids: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), obj_points: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), img_points: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


