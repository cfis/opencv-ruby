#[EM](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#aa1c9f6a0b2e2e13725ccf7c564d3cb5c) -> Cv::Ptr≺cv꞉꞉ml꞉꞉EM≻

[load](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#ad13dd054c14fa1f45422d736322b3bec)(filepath: [String](https://docs.ruby-lang.org/en/master/String.html), node_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> Cv::Ptr≺cv꞉꞉ml꞉꞉EM≻


## Methods
[get_clusters_number](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#ae914b688d7546847e4919ac4e005a0fe) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_covariance_matrix_type](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#ae30ad8cb14ec43c524ca8086ac0f9e5f) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_covs](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#a223e28d9c8a2447d6afca6a10dd608c1)(covs: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_means](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#acec62dd55c06711c81d741c2d96603d1) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_term_criteria](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#a80d9ab289b98dfc51f033fd2227bef3e) -> [Cv::TermCriteria](https://docs.opencv.org/4.x/d9/d5d/classcv_1_1TermCriteria.html)

[get_weights](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#af235d6061a5414ebf6defddf7cc070e1) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[predict](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#ae3f12147ba846a53601b60c784ee263d)(samples: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), results: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[predict2](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#a2ea7da92a75bc7a7d665c241f547b9b9)(sample: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), probs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Vec2d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

[set_clusters_number](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#a069ee46c360ed183d5eb96b8b8261d8a)(val: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_covariance_matrix_type](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#a8b383c62697eac9a972931674790f6cd)(val: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_term_criteria](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#ab516e6f125bd4ebc976306e956320313)(val: [Cv::TermCriteria](https://docs.opencv.org/4.x/d9/d5d/classcv_1_1TermCriteria.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[train_e](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#a2d02b45a574d51a72263e9c53cdc4f09)(samples: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), means0: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), covs0: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), weights0: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), log_likelihoods: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), labels: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), probs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

train_em(samples: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), log_likelihoods: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), labels: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), probs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[train_m](https://docs.opencv.org/4.x/d1/dfb/classcv_1_1ml_1_1EM.html#ac21fbae3a09972de0a0a1cb4c2c434d0)(samples: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), probs0: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), log_likelihoods: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), labels: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), probs: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)


