#[PCTSignatures](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a5bdd6ea2daf834a7c6ba5fe23360fad5)(init_sampling_points: [Std::Vector≺cv꞉꞉Point_≺float≻≻](https://en.cppreference.com/w/cpp/container/vector.html), init_seed_count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Ptr≺cv꞉꞉xfeatures2d꞉꞉PCTSignatures≻

[create](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a5bdd6ea2daf834a7c6ba5fe23360fad5)(init_sampling_points: [Std::Vector≺cv꞉꞉Point_≺float≻≻](https://en.cppreference.com/w/cpp/container/vector.html), init_cluster_seed_indexes: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> Cv::Ptr≺cv꞉꞉xfeatures2d꞉꞉PCTSignatures≻

[create](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a5bdd6ea2daf834a7c6ba5fe23360fad5)(init_sample_count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), init_seed_count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), point_distribution: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Ptr≺cv꞉꞉xfeatures2d꞉꞉PCTSignatures≻

[draw_signature](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a3e206c0847ce9f4474b6084deec1bc84)(source: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), signature: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), result: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), radius_to_shorter_side_ratio: [Float](https://docs.ruby-lang.org/en/master/Float.html), border_thickness: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[generate_init_points](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#ace362f4b93ef4a1c5fd9c419f9a05630)(init_points: [Std::Vector≺cv꞉꞉Point_≺float≻≻](https://en.cppreference.com/w/cpp/container/vector.html), count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), point_distribution: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


## Methods
[compute_signature](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a23afba0a61f447c839fbf0134af817eb)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), signature: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[compute_signatures](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a7e64cf57c74009277db78e99d14af4d2)(images: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html), signatures: [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_cluster_min_size](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a80b1bcbb2621d01887f0ce0cf2153d27) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_distance_function](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a00e5d015965077e63a3d026315d99fb7) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_drop_threshold](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#aa0de847070a8f7557feed32220f6d097) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_grayscale_bits](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a147d4d9af6c8f0fac8509a4f62d20306) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_init_seed_count](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a2d73ca7a104084525f33f76b8f062da7) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_init_seed_indexes](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#add3cac10b71e347201c8ddfa1e3b3054) -> [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)

[get_iteration_count](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#aa09a2face423a7042bdec81e6526190b) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_joining_distance](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#ab140533fa85a158ebbbed43d9e03973b) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_max_clusters_count](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a68d214927159651492e648e5adde1345) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_sample_count](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a16c500a45db6acdf2d5989d2f0563bfc) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_sampling_points](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a6cff5b933b81873b41831c9aadcd0e41) -> [Std::Vector≺cv꞉꞉Point_≺float≻≻](https://en.cppreference.com/w/cpp/container/vector.html)

[get_weight_a](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a92ea655d80cc73ebc4d9c4528a2e13aa) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_weight_b](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a2c05236f9cb324ea0b457cc4aad73002) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_weight_contrast](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a8ba46a2ee95336bd50ce38c5f7bfe895) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_weight_entropy](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a2c13123bc1ca583006de657ab640e921) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_weight_l](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a66b254681f41fe131ce9f9355de977ff) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_weight_x](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a1b3c726c6d7485a9f20ab9ecdecb79a1) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_weight_y](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#afca4d096cd24693c007c8197f2242591) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_window_radius](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#ae382e1d59ca2eaf13c482c6cffc50749) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[set_cluster_min_size](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a9b1788e47f815b0bdba559062e1be914)(cluster_min_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_distance_function](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a828b6802c9960647a128b966f7a79045)(distance_function: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_drop_threshold](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a48a8b9dcd84024b8cbdcd6d9eae220b7)(drop_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_grayscale_bits](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a1d9a4dd5b5b91d8e9f8195c7e496b9c3)(grayscale_bits: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_init_seed_indexes](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a0aa3ed847a3bd993e34a9bdb294212f5)(init_seed_indexes: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_iteration_count](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#aa2f1491f6cc4f99feed74a55c84a6950)(iteration_count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_joining_distance](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a3b34e63ce62c9759d7a9747ba6549a78)(joining_distance: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_max_clusters_count](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a4450e6f3e2676caaf4c78c9da7e6af6f)(max_clusters_count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_sampling_points](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a04adf50e23489c41975a6b7524c189d4)(sampling_points: [Std::Vector≺cv꞉꞉Point_≺float≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_translation](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a326cff067288459c6fefa0f3fe313a14)(idx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), value: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_translations](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a48a29104ac014ba9adc426ec67568ed7)(translations: [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weight](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a644513e799afdefdb0e37a1bb4abc2d7)(idx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), value: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weight_a](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#adb1cdee9bc21e1486795970ad4f5226f)(weight: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weight_b](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a076170589f3fe0c1f306e42a5a3e2962)(weight: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weight_contrast](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#aefbda82326aa30a385616a609e653097)(weight: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weight_entropy](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#ad4284dee436fef8bbc5153cf01cc69db)(weight: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weight_l](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#abc703d4edfecaeae94dfdab813fff5f1)(weight: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weight_x](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#ab92c90a1047a839b7946c6711eafb678)(weight: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weight_y](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#ac7a4326f24547f0e21f5b14c0e91d7f7)(weight: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_weights](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a0fcdbc44a5a48b4b24e6c182ca7045f7)(weights: [Std::Vector≺float≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_window_radius](https://docs.opencv.org/4.x/d0/d74/classcv_1_1xfeatures2d_1_1PCTSignatures.html#a424bb76f76544c6f04777d806a033541)(radius: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


