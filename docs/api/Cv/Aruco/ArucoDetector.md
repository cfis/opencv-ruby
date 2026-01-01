#[ArucoDetector](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#aebb849a70f107f72ff5b0504d89120de)(dictionary: [Cv::Aruco::Dictionary](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html), detector_params: [Cv::Aruco::DetectorParameters](https://docs.opencv.org/4.x/d1/dcd/structcv_1_1aruco_1_1DetectorParameters.html), refine_params: [Cv::Aruco::RefineParameters](https://docs.opencv.org/4.x/d5/d09/structcv_1_1aruco_1_1RefineParameters.html))


## Methods
[detect_markers](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#a0c1d14251bf1cbb06277f49cfe1c9b61)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), corners: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), ids: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), rejected_img_points: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_detector_parameters](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#a25a429995d1056167d223cf349b5bc52) -> [Cv::Aruco::DetectorParameters](https://docs.opencv.org/4.x/d1/dcd/structcv_1_1aruco_1_1DetectorParameters.html)

[get_dictionary](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#add5fe8783368d754a262abbdbc28c6ea) -> [Cv::Aruco::Dictionary](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html)

[get_refine_parameters](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#af860062d5307cd978b9c2be84652a532) -> [Cv::Aruco::RefineParameters](https://docs.opencv.org/4.x/d5/d09/structcv_1_1aruco_1_1RefineParameters.html)

[read](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#aafd0e64c1be5a122fc4ac41a0d252342)(fn: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[refine_detected_markers](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#ad806c9310cfc826a178b0aefdf09bab6)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), board: [Cv::Aruco::Board](https://docs.opencv.org/4.x/d4/db2/classcv_1_1aruco_1_1Board.html), detected_corners: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), detected_ids: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), rejected_corners: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), camera_matrix: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), dist_coeffs: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), recovered_idxs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_detector_parameters](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#a0aa1ed97aff906b35858e72c5619aa4d)(detector_parameters: [Cv::Aruco::DetectorParameters](https://docs.opencv.org/4.x/d1/dcd/structcv_1_1aruco_1_1DetectorParameters.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_dictionary](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#a412aaf79af8810c533f9f5ad7c1ba688)(dictionary: [Cv::Aruco::Dictionary](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_refine_parameters](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#a5ec6230925d52802cf594f5f357feaae)(refine_parameters: [Cv::Aruco::RefineParameters](https://docs.opencv.org/4.x/d5/d09/structcv_1_1aruco_1_1RefineParameters.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#a025911030c402ec45cf3a102df748eb4)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/d2/d1a/classcv_1_1aruco_1_1ArucoDetector.html#a025911030c402ec45cf3a102df748eb4)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html), name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


