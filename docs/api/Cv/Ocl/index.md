#Cv::Ocl
## Singleton Methods
[attach_context](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gaf83af36be2097fd43e3eba5c8f3025b1)(platform_name: [String](https://docs.ruby-lang.org/en/master/String.html), platform_id: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), context: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), device_id: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[build_options_add_matrix_description](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#ga95fc5d853c45a6b1db1d425d831f7d2f)(build_options: [String](https://docs.ruby-lang.org/en/master/String.html), name: [String](https://docs.ruby-lang.org/en/master/String.html), _m: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[check_optimal_vector_width](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#ga293c0b13a39f10465e3ea67a018d6779)(vector_widths: [Rice::Pointer≺int≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), src1: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src2: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src3: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src4: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src5: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src6: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src7: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src8: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src9: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), strat: [Cv::Ocl::OclVectorStrategy](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gae601ac868b72015b583ccbbdd0dec587)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[convert_from_buffer](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gaf7698360b08aa452c2692296ce55bccd)(cl_mem_buffer: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), step: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), dst: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[convert_from_image](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gada97cc08c31e416b957e23b480334b6c)(cl_mem_image: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), dst: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[finish](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gabfca32247f267c662b3bff6587d14b40) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_open_cl_allocator -> [Cv::MatAllocator](https://docs.opencv.org/4.x/df/d4c/classcv_1_1MatAllocator.html)

get_open_cl_error_string(error_code: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[get_platfoms_info](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gae98550085d4a41df7a1daff093fe775c)(platform_info: [Std::Vector≺cv꞉꞉ocl꞉꞉PlatformInfo≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[have_amd_blas?](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gad2e486ab8104a3b197001e27d54e2a95) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[have_amd_fft?](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#ga593387b5285a57ea03350b363c74c6cf) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

have_open_cl? -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

have_svm? -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[kernel_to_str](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gafb2b78806f036b57609e26b8237fa3d9)(_kernel: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), ddepth: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[memop_type_to_str](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gaaa35ea353690d0bba9edd9a1a3e69484)(t: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[predict_optimal_vector_width](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#ga1b16507915166d63529ad8126e465c1a)(src1: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src2: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src3: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src4: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src5: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src6: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src7: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src8: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src9: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), strat: [Cv::Ocl::OclVectorStrategy](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gae601ac868b72015b583ccbbdd0dec587)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[predict_optimal_vector_width_max](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#ga8b96cd547eac1e787cf50e22820bc4b9)(src1: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src2: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src3: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src4: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src5: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src6: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src7: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src8: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src9: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

set_use_open_cl(flag: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[type_to_str](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#ga7f2f248d37cfa3e1e4122249f7dc8c49)(t: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [String](https://docs.ruby-lang.org/en/master/String.html)

use_open_cl? -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[vecop_type_to_str](https://docs.opencv.org/4.x/dc/d83/group__core__opencl.html#gaa3c1017cd44dcd6c739943f31bb8f248)(t: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [String](https://docs.ruby-lang.org/en/master/String.html)


