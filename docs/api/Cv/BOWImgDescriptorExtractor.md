#[BOWImgDescriptorExtractor](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#aa37f98c0c292cfb0e9ec23ef4fbb11c1)(dmatcher: Cv::Ptr≺cv꞉꞉DescriptorMatcher≻)

[initialize](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#aa37f98c0c292cfb0e9ec23ef4fbb11c1)(dextractor: Cv::Ptr≺cv꞉꞉Feature2D≻, dmatcher: Cv::Ptr≺cv꞉꞉DescriptorMatcher≻)


## Methods
[compute](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#ac4e1019795995a9395aded0a9c1c3ed6)(keypoint_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), img_descriptor: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), point_idxs_of_clusters: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[compute](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#ac4e1019795995a9395aded0a9c1c3ed6)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), keypoints: [Std::Vector≺cv꞉꞉KeyPoint≻](https://en.cppreference.com/w/cpp/container/vector.html), img_descriptor: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), point_idxs_of_clusters: [Std::Vector≺vector≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), descriptors: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[compute2](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#a2c3540b57b4f74b4e87778e3cb338bb0)(image: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), keypoints: [Std::Vector≺cv꞉꞉KeyPoint≻](https://en.cppreference.com/w/cpp/container/vector.html), img_descriptor: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[descriptor_size](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#a0f41a68e3326e1bffd2f32aa64a9871d) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[descriptor_type](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#a4abb4c684a25f843b2f033f2bc7f52eb) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_vocabulary](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#a3829bc29c30c890623aaa9c89a643b8a) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[set_vocabulary](https://docs.opencv.org/4.x/d2/d6b/classcv_1_1BOWImgDescriptorExtractor.html#a9d8425d78fc4e81991a80e471d6089e6)(vocabulary: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


