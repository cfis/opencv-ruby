#[FaceRecognizerSF](https://docs.opencv.org/4.x/da/d09/classcv_1_1FaceRecognizerSF.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/da/d09/classcv_1_1FaceRecognizerSF.html#a5f43ba1750485e4504f822ba86d7d34e)(model: [String](https://docs.ruby-lang.org/en/master/String.html), config: [String](https://docs.ruby-lang.org/en/master/String.html), backend_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), target_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Ptr≺cv꞉꞉FaceRecognizerSF≻


## Methods
[align_crop](https://docs.opencv.org/4.x/da/d09/classcv_1_1FaceRecognizerSF.html#a84492908abecbc9362b4ddc8d46b8345)(src_img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), face_box: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), aligned_img: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[feature](https://docs.opencv.org/4.x/da/d09/classcv_1_1FaceRecognizerSF.html#ab1b4a3c12213e89091a490c573dc5aba)(aligned_img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), face_feature: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[match](https://docs.opencv.org/4.x/da/d09/classcv_1_1FaceRecognizerSF.html#a2f0362ca1e64320a1f3ba7e1386d0219)(face_feature1: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), face_feature2: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), dis_type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)


