#[HOGDescriptor](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html)
## Singleton Methods
[get_daimler_people_detector](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a4eed2d1adfb574d20c2a6511df28d1e6) -> [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html)

[get_default_people_detector](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a721436d76d9b3cce5abf119e114bff52) -> [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a723b95b709cfd3f95cf9e616de988fc8)()

[initialize](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a723b95b709cfd3f95cf9e616de988fc8)(filename: [String](https://docs.ruby-lang.org/en/master/String.html))

[initialize](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a723b95b709cfd3f95cf9e616de988fc8)(_win_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), _block_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), _block_stride: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), _cell_size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), _nbins: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), _deriv_aperture: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), _win_sigma: [Float](https://docs.ruby-lang.org/en/master/Float.html), _histogram_norm_type: Cv::HOGDescriptor::HistogramNormType, _l2_hys_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), _gamma_correction: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), _nlevels: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), _signed_gradient: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html))


## Attributes
[block_size](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a847f3d42f1cf72897d5263fe3217a36d): [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html) (read/write)

[block_stride](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#ac272d532e2a672f302e9a5eab7ca1055): [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html) (read/write)

[cell_size](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a5ef930c38e2b0cfcd5e5252989e056ad): [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html) (read/write)

[deriv_aperture](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a128efda1c45dee2a989547c7b41e6a95): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

free_coef: [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[gamma_correction](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a7dc72b5092c9cec54f380252b125046c): [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html) (read/write)

[histogram_norm_type](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a03bb4bba3f3af82fc2674e4c3d7feb89): [Cv::HOGDescriptor::HistogramNormType]() (read/write)

l2_hys_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[nbins](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#ab1eda37f2e10b14bcd51a9014409b8d3): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[nlevels](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a94a54b27a5d707796c4fa56766497b5f): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[ocl_svm_detector](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a42bb83b4d03a8ead9d54e8c5c8463076): [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html) (read/write)

[signed_gradient](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a0c2f2db8693dbec32092bc659d25c9b9): [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html) (read/write)

[svm_detector](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a904130d56281ba264e097e9895c648f5): [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html) (read/write)

[win_sigma](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#aa63743f4aca740e3fdefd0ca767b8ab9): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[win_size](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a75329167dfdacde41b488e091dd555d1): [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html) (read/write)


## Methods
[check_detector_size?](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a5c6715965fab466de041ad2a39765478) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[compute](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a38cd712cd5a6d9ed0344731fcd121e8b)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), descriptors: [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html), win_stride: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), padding: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), locations: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[compute_gradient](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a1f76c51c08d69f2b8a0f079efc4bd093)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), grad: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), angle_ofs: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), padding_tl: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), padding_br: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#ab133c13641d53944f48bb925f6d96cb1)(c: [Cv::HOGDescriptor](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a309829908ffaf4645755729d7aa90627)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), found_locations: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), hit_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), win_stride: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), padding: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), search_locations: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a309829908ffaf4645755729d7aa90627)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), found_locations: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), weights: [Std::Vector≺double≻](https://en.cppreference.com/w/cpp/container/vector.html), hit_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), win_stride: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), padding: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), search_locations: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect_multi_scale](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a1f631b771af4a3cfa0f2db7ba952e5f4)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), found_locations: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), hit_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), win_stride: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), padding: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), scale: [Float](https://docs.ruby-lang.org/en/master/Float.html), group_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), use_meanshift_grouping: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect_multi_scale](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a1f631b771af4a3cfa0f2db7ba952e5f4)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), found_locations: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), found_weights: [Std::Vector≺double≻](https://en.cppreference.com/w/cpp/container/vector.html), hit_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), win_stride: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), padding: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), scale: [Float](https://docs.ruby-lang.org/en/master/Float.html), group_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), use_meanshift_grouping: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect_multi_scale_roi](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a40aabc4ac4dbab3a855ae9182b91ef73)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), found_locations: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), locations: [Std::Vector≺cv꞉꞉DetectionROI≻](https://en.cppreference.com/w/cpp/container/vector.html), hit_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), group_threshold: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[detect_roi](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a26a3085d2f461f22b98c7b6066f51d3e)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), locations: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), found_locations: [Std::Vector≺cv꞉꞉Point_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), confidences: [Std::Vector≺double≻](https://en.cppreference.com/w/cpp/container/vector.html), hit_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), win_stride: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), padding: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_descriptor_size](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a437dcb4d9b539a0035fb1f63946daa1b) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_win_sigma](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#afe0058890e561cde3ab451f9e097787e) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[group_rectangles](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#ad7c9679b23e8476e332e9114181d656d)(rect_list: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), weights: [Std::Vector≺double≻](https://en.cppreference.com/w/cpp/container/vector.html), group_threshold: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), eps: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[initialize_copy](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a723b95b709cfd3f95cf9e616de988fc8)(d: [Cv::HOGDescriptor](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[load?](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a957f55d36ba2f1a2ae47883c11f4b730)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), objname: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[read?](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a237a16a0646dc7a0dbecc52a93480aeb)(fn: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[save](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a44f2566a83049536a2879f37c977c7fd)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), objname: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_svm_detector(svmdetector: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/d5/d33/structcv_1_1HOGDescriptor.html#a2c13c67988147921d6ba313e15de5fda)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html), objname: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


