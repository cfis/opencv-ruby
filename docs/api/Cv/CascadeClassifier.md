#[CascadeClassifier](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html)
## Singleton Methods
[convert](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a6bdc0b45d2a340a7a1dd8d6f9bce4bda)(oldcascade: [String](https://docs.ruby-lang.org/en/master/String.html), newcascade: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#ab3e572643114c43b21074df48c565a27)()

[initialize](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#ab3e572643114c43b21074df48c565a27)(filename: [String](https://docs.ruby-lang.org/en/master/String.html))


## Attributes
[cc](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a028c1d86a8275c82b089510768f853bd): [Cv::Ptr≺cv꞉꞉BaseCascadeClassifier≻]() (read/write)


## Methods
[detect_multi_scale](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#aaf8181cb63968136476ec4204ffca498)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), objects: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), scale_factor: [Float](https://docs.ruby-lang.org/en/master/Float.html), min_neighbors: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), min_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), max_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect_multi_scale](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#aaf8181cb63968136476ec4204ffca498)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), objects: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), num_detections: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), scale_factor: [Float](https://docs.ruby-lang.org/en/master/Float.html), min_neighbors: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), min_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), max_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect_multi_scale](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#aaf8181cb63968136476ec4204ffca498)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), objects: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), reject_levels: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), level_weights: [Std::Vector≺double≻](https://en.cppreference.com/w/cpp/container/vector.html), scale_factor: [Float](https://docs.ruby-lang.org/en/master/Float.html), min_neighbors: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), min_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), max_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), output_reject_levels: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[empty?](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a1753ebe58554fe0673ce46cb4e83f08a) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[get_feature_type](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a0bab6de516c685ba879a4b1f1debdef1) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_mask_generator](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#aa8852b93b370fbfc4be6b0cf5f9945a7) -> Cv::Ptr≺cv꞉꞉BaseCascadeClassifier꞉꞉MaskGenerator≻

[get_old_cascade](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a8a9ed1e89c5a1a50c2945a4e88a4b244) -> [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[get_original_window_size](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a7a131d319ab42a444ff2bcbb433b7b41) -> [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)

[load](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a1a5884c8cc749422f9eb77c2471958bc)(filename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[old_format_cascade?](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a556bdd8738ba96aac07628ec38ff46da) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[read](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a6e3f096b121259fd3bab1c2437e840c5)(node: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[set_mask_generator](https://docs.opencv.org/4.x/d1/de5/classcv_1_1CascadeClassifier.html#a7628a59eefb561ecd79ad9d02bd69073)(mask_generator: Cv::Ptr≺cv꞉꞉BaseCascadeClassifier꞉꞉MaskGenerator≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


