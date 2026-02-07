#Cv::Face
## Singleton Methods
create_facemark_aam -> Cv::Ptr≺cv꞉꞉face꞉꞉Facemark≻

[create_facemark_kazemi](https://docs.opencv.org/4.x/db/d7c/group__face.html#gaf5c0923d7f35c5952513e96b4a346853) -> Cv::Ptr≺cv꞉꞉face꞉꞉Facemark≻

create_facemark_lbf -> Cv::Ptr≺cv꞉꞉face꞉꞉Facemark≻

[draw_facemarks](https://docs.opencv.org/4.x/db/d7c/group__face.html#ga318d9669d5ed4dfc6ab9fae2715310f5)(image: [Cv::InputOutputArray](https://docs.opencv.org/4.x/d0/d46/classcv_1_1__InputOutputArray.html), points: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), color: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_faces](https://docs.opencv.org/4.x/db/d7c/group__face.html#ga62cec28ecffa694e1efb272ff0c65da2)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), faces: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), params: [Cv::Face::CParams](https://docs.opencv.org/4.x/d8/dd8/structcv_1_1face_1_1CParams.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

get_faces_haar(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), faces: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), face_cascade_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[load_dataset_list](https://docs.opencv.org/4.x/db/d7c/group__face.html#ga02020fc9f387bb043a478fe5f112bb8d)(image_list: [String](https://docs.ruby-lang.org/en/master/String.html), annotation_list: [String](https://docs.ruby-lang.org/en/master/String.html), images: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html), annotations: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[load_face_points](https://docs.opencv.org/4.x/db/d7c/group__face.html#gab70c6fb08756f867d6160099907202a5)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), points: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), offset: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[load_training_data](https://docs.opencv.org/4.x/db/d7c/group__face.html#gac3a2d046686d932425d2601b640d97d3)(filename: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html), trainlandmarks: [Std::Vector≺vector≺cv꞉꞉Point_≺float≻≻≻](https://en.cppreference.com/w/cpp/container/vector.html), trainimages: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[load_training_data](https://docs.opencv.org/4.x/db/d7c/group__face.html#gac3a2d046686d932425d2601b640d97d3)(image_list: [String](https://docs.ruby-lang.org/en/master/String.html), ground_truth: [String](https://docs.ruby-lang.org/en/master/String.html), images: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html), face_points: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), offset: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[load_training_data](https://docs.opencv.org/4.x/db/d7c/group__face.html#gac3a2d046686d932425d2601b640d97d3)(filename: [String](https://docs.ruby-lang.org/en/master/String.html), images: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html), face_points: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), delim: [String](https://docs.ruby-lang.org/en/master/String.html), offset: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)


