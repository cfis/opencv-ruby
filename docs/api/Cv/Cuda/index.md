#Cv::Cuda
## Singleton Methods
[create_continuous](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#ga3a55474eb59c884697edf397fe0f871c)(rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), arr: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[create_gpu_mat_from_cuda_memory](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#gac3ca8e6e41d70a228d72422c844dc99c)(size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cuda_memory_address: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), step: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[create_gpu_mat_from_cuda_memory](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#gac3ca8e6e41d70a228d72422c844dc99c)(rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cuda_memory_address: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), step: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[device_supports?](https://docs.opencv.org/4.x/d8/d40/group__cudacore__init.html#ga170b10cc9af4aa8cce8c0afdb4b1d08c)(feature_set: [Cv::Cuda::FeatureSet](https://docs.opencv.org/4.x/d8/d40/group__cudacore__init.html#ga776cf8e0301b18e19be4782754274fe0)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[ensure_size_is_enough](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#ga4551c222cdf97ebdb4d7440fecfc737a)(rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), arr: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_cuda_enabled_device_count](https://docs.opencv.org/4.x/d8/d40/group__cudacore__init.html#gaaa93892f9189163e5d53790b4b1e88db) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_device](https://docs.opencv.org/4.x/d8/d40/group__cudacore__init.html#ga6ded4ed8e4fc483a9863d31f34ec9c0e) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[print_cuda_device_info](https://docs.opencv.org/4.x/d8/d40/group__cudacore__init.html#gaa37afdfb8efe85b6252ca2bb8bea8ff2)(device: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[print_short_cuda_device_info](https://docs.opencv.org/4.x/d8/d40/group__cudacore__init.html#gacece2dc1d7962bcc7233c033fe64328b)(device: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[register_page_locked](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#ga6d25da8194cc95035994ae98e9eebc02)(m: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[reset_device](https://docs.opencv.org/4.x/d8/d40/group__cudacore__init.html#ga6153b6f461101374e655a54fc77e725e) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_buffer_pool_config](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#ga93da1d4c64558590950409266b1e2a92)(device_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), stack_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), stack_count: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_buffer_pool_usage](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#ga7dbf253e43493eb870c9759cc35bbffb)(on: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_device](https://docs.opencv.org/4.x/d8/d40/group__cudacore__init.html#gaefa34186b185de47851836dba537828b)(device: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_gl_device](https://docs.opencv.org/4.x/d2/d3c/group__core__opengl.html#ga7da4b94fc78501f4239c132901387730)(device: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[unregister_page_locked](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#ga68dd974fb5e19f6306122a4b49c6a428)(m: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[wrap_stream](https://docs.opencv.org/4.x/d9/d41/group__cudacore__struct.html#gaf7bc2ae636c98eb4cb073287b897a091)(cuda_stream_memory_address: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)


