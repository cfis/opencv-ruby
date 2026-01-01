#[TrainData](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a7755186f510669f35fbdee8c044ced10)(samples: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), layout: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), responses: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), var_idx: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), sample_idx: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), sample_weights: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), var_type: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> Cv::Ptr≺cv꞉꞉ml꞉꞉TrainData≻

[get_sub_matrix](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ac3c8a080653b64495a13913903b4667c)(matrix: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), idx: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), layout: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_sub_vector](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a3d01eda6a2eb795bd7ab223b6d065e52)(vec: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), idx: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

load_from_csv(filename: [String](https://docs.ruby-lang.org/en/master/String.html), header_line_count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), response_start_idx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), response_end_idx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), var_type_spec: [String](https://docs.ruby-lang.org/en/master/String.html), delimiter: [String](https://docs.ruby-lang.org/en/master/String.html), missch: [String](https://docs.ruby-lang.org/en/master/String.html)) -> Cv::Ptr≺cv꞉꞉ml꞉꞉TrainData≻

[missing_value](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a852e02da238303d33fd5923b75657584) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)


## Methods
[get_cat_count](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a7e687b7ee8325380bced49f5cd5baf15)(vi: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_cat_map](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a3c2c8c6bf46955d9c52f256fdfa9097c) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_cat_ofs](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a65ad5f0565ffe9ac26fbff8026faec36) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_class_labels](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a0e40c6bd62aa9ad0ae6f5273d2bd824b) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_default_subst_values](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ab8c65d4efcb364be41febd8e3c2dae70) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_layout](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#aa2d2889b6dddad5e663cb18b206ac3f1) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_missing](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a71f13029c92961dc432fcfeec376ad9a) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_n_all_vars](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a4c81aad5723a86d1f9f97e0ca2cf271b) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_n_samples](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a38b6da04d4765000e890d614a01be446) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_n_test_samples](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a0f3265d83658f7effd2cb4c05fe6b8c8) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_n_train_samples](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ac34c8467851769cac20d99cde52f3812) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_n_vars](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#acafca98ec8fb43ddcec59af1cc906611) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_names](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ae14e1e1c607472f3c72a5a63679d08cb)(names: [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_norm_cat_responses](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a2f6bd6ae08ded472532b28e1b1266230) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_norm_cat_values](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ac535b6932fa5bb7d89cd50f6d7b86dc7)(vi: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), sidx: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), values: [Rice::Pointer≺int≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_response_type](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#afc86c4d4670e535dee2459742f87ea95) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_responses](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a10c5bb5ac7c4b70fbc9db0d3a94684e2) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_sample](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#acad3498d09f7d9b91fa9378b50a6c12a)(var_idx: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), sidx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), buf: [Rice::Pointer≺float≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_sample_weights](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a7ab7348f09a9a44bf1e30df1b979e034) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_samples](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a86fc3bbc9a6d0fef62ec97b28eb452fe) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_test_norm_cat_responses](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a4fc48158587fe44f863788aefed5d245) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_test_responses](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ae83fc71c776cd9971463c2e4dbab0427) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_test_sample_idx](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a923fc78e64e96543bf8ebe87d179ea29) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_test_sample_weights](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#acddb9c4642e9b4f39a4bf1337ceb06f7) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_test_samples](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ae8549c2b1e3b16b8f0fc64917ffd6fd6) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_train_norm_cat_responses](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a0901c9bed4728e3fa29b93a0afa46371) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_train_responses](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ac248adbafbc43a1c00bfa32e2526cf4c) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_train_sample_idx](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#aaefa64f1e3c208d4dc38127b6739eff7) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_train_sample_weights](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ad2de4f384f28259ac849e289be8d970d) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_train_samples](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#af35073f4d4e0777159c57622df56117c)(layout: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), compress_samples: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), compress_vars: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_values](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a38d657b15e30bc94124c31cd3c23d816)(vi: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), sidx: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), values: [Rice::Pointer≺float≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_var_idx](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#aee63a2fc0f0679e3f8dd65dbc2c2b571) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_var_symbol_flags](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a7d08ff25ec3eed7c970a707e3000d212) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_var_type](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a56959ac3541cd7d8d3bbcba02f8a1308) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[set_train_test_split](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ab444173f4d980bb3c18d856df706c920)(count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), shuffle: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_train_test_split_ratio](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#ad59c8df14e133ba492ff5cbfa21244cc)(ratio: [Float](https://docs.ruby-lang.org/en/master/Float.html), shuffle: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[shuffle_train_test](https://docs.opencv.org/4.x/dc/d32/classcv_1_1ml_1_1TrainData.html#a0515ddd44168aa5c42478536375c760b) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


