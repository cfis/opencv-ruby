#[DnnSuperResImpl](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#af2927388b3fee0a18ec7e198d7a5f718) -> Cv::Ptr≺cv꞉꞉dnnSuperres꞉꞉DnnSuperResImpl≻


## Constructors
[initialize](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#a5a9a8d189caa273fc210441f0858a8a3)()

[initialize](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#a5a9a8d189caa273fc210441f0858a8a3)(algo: [String](https://docs.ruby-lang.org/en/master/String.html), scale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Methods
[get_algorithm](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#af345f7283533961302b854ccc5266f57) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[get_scale](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#a03ddb65b1a6ae8b0064b91ffe7785eeb) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[read_model](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#af56741a70ee1346efcc69789f99200d8)(path: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[read_model](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#af56741a70ee1346efcc69789f99200d8)(weights: [String](https://docs.ruby-lang.org/en/master/String.html), definition: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_model](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#ab4d5e45240e7dbc436f077d34bff8854)(algo: [String](https://docs.ruby-lang.org/en/master/String.html), scale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_preferable_backend](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#a11b32bf3c6d7e162d0d8e8f5bb1544cc)(backend_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_preferable_target](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#aa320f11cbe5cfaa40392870fcd6a752c)(target_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[upsample](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#a3d8bf9e39c75939ab8d2de8396201a89)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), result: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[upsample_multioutput](https://docs.opencv.org/4.x/d8/d11/classcv_1_1dnn__superres_1_1DnnSuperResImpl.html#a0834ecb99e6dfcef340ec34e41aa2c09)(img: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), imgs_new: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html), scale_factors: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), node_names: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


