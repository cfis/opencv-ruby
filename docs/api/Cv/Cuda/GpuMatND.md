#[GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a0121ae48309b703132bdd1c62a74e8b9)()

[initialize](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a0121ae48309b703132bdd1c62a74e8b9)(size: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))

[initialize](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a0121ae48309b703132bdd1c62a74e8b9)(size: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), data: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), step: [Std::Vector≺unsigned Int64≻](https://en.cppreference.com/w/cpp/container/vector.html))


## Attributes
[dims](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a0c7bb2ffe61258ee8330e92ed2de841c): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[flags](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a7d884fbe10014edf2410aed9d0dc7d4c): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[size](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#ab0b733dbf9e305537fd9f45834d1fa15): [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html) (read/write)

[step](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a3448b5ff7cd136b1c36ef20ce95136af): [Std::Vector≺unsigned Int64≻](https://en.cppreference.com/w/cpp/container/vector.html) (read/write)


## Methods
[assign](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a8d6d1ef75427ba64fefc4be5f45494f5)(: [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)) -> [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)

[assign](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a8d6d1ef75427ba64fefc4be5f45494f5)(: [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)) -> [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)

[call](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#ac50c25ab533701f7e6c590f77ceca463)(ranges: [Std::Vector≺cv꞉꞉Range≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)

[call](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#ac50c25ab533701f7e6c590f77ceca463)(idx: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), row_range: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html), col_range: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[clone](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a286dc4b28a43c41814355fea8fb5eecf) -> [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)

[clone](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a286dc4b28a43c41814355fea8fb5eecf)(stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)

[continuous?](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a69cf00f52088902c4f7cfb878889d24b) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[create](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#ac611c38596f137fcb096297735a4ea13)(size: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[create_gpu_mat_header](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a9685798953a57ebbd18558a6ca0e9c63) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[create_gpu_mat_header](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a9685798953a57ebbd18558a6ca0e9c63)(idx: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), row_range: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html), col_range: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[download](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a541ecc2ed0a625fa1a553ebec49ea5da)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[download](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a541ecc2ed0a625fa1a553ebec49ea5da)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[elem_size](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a9613a1cb08b93538c6a91e4b65dc68f1) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[elem_size1](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a32608e334c69769359fb395a9c012f94) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[empty?](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#ad70f1a6adcd06229f4953b72b9d7918d) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[external?](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a1c5ccfd3a01b3c25ef2b860668781017) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[initialize_copy](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a0121ae48309b703132bdd1c62a74e8b9)(: [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[release](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#ab2fb57a56ebd24076ff2ab715cfdb55b) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[submatrix?](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a12b9ae95f63299fc6a4ca0078f393368) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[swap](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#aff068aafbcb358f85bf214f51ff3a785)(m: [Cv::Cuda::GpuMatND](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[to_gpu_mat](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#af1c7d7063a526b4662c339a965e601a7) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[total](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a1f394b0658fde4da1fd67e667e1e7d0d) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[total_mem_size](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#a9ead01c1372c6dce2ee3217b7392ffff) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[type](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#aaaa7c0aff13beeac8217773f57b47468) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[upload](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#af2216b878fd50a7aec3d1f580bd5471a)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[upload](https://docs.opencv.org/4.x/d2/d0f/classcv_1_1cuda_1_1GpuMatND.html#af2216b878fd50a7aec3d1f580bd5471a)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


