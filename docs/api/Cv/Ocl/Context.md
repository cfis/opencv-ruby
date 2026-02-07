#[Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a71fd118ca17edb79d936a8055441a7db)(configuration: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)

[from_device](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#afca93fd75a481337148310b68b488477)(device: [Cv::Ocl::Device](https://docs.opencv.org/4.x/d7/d9f/classcv_1_1ocl_1_1Device.html)) -> [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)

[from_handle](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#ab6570940f8a3e4c8c125e245b646fd80)(context: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)

[get_default](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a75a786be2f0bfbcbe8cd49976db3303e)(initialize: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a1e29fc6b44d86782dd90a9fe986c9cd1)()

[initialize](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a1e29fc6b44d86782dd90a9fe986c9cd1)(dtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Attributes
[p](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#aa40f58476d9e54c1c58557f24eede23c): [Cv::Ocl::Context::Impl]() (read/write)


## Methods
[assign](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#aaa2c55ecaac5851c8e0493b4cf5aa259)(c: [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)) -> [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)

[assign](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#aaa2c55ecaac5851c8e0493b4cf5aa259)(c: [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)) -> [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)

[create](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a34a5de8c9951363ed10bc44813971d9b)(dtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[create?](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a34a5de8c9951363ed10bc44813971d9b) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[device](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#abc0d5b72f7821637fa98058ca753a452)(idx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Ocl::Device](https://docs.opencv.org/4.x/d7/d9f/classcv_1_1ocl_1_1Device.html)

[empty?](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a579d721330f1480fe04736469bb4e27b) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[get_impl](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a5ceecf52dcb42277ae852ad9295253e4) -> Cv::Ocl::Context::Impl

get_open_cl_context_property(property_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[get_prog](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a9b16748ebf8a27a343c3d702606f5a28)(prog: [Cv::Ocl::ProgramSource](https://docs.opencv.org/4.x/d5/de3/classcv_1_1ocl_1_1ProgramSource.html), buildopt: [String](https://docs.ruby-lang.org/en/master/String.html), errmsg: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Cv::Ocl::Program](https://docs.opencv.org/4.x/d2/d88/classcv_1_1ocl_1_1Program.html)

[get_user_context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a7bc3305b4f5150426396f8f487fa48ae)(type_id: [Std::TypeIndex](https://en.cppreference.com/w/cpp/types/type_index.html)) -> [Std::SharedPtr≺cv꞉꞉ocl꞉꞉Context꞉꞉UserContext≻](https://en.cppreference.com/w/cpp/memory/shared_ptr.html)

[initialize_copy](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a1e29fc6b44d86782dd90a9fe986c9cd1)(c: [Cv::Ocl::Context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[ndevices](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#adb412f36d792b6a219c54d912a9ff43b) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[ptr](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#af248ab9f544a1147b27882ba63067caf) -> [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[release](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#ac9d59d02b1305f82fd9ce6f7222cab35) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

set_use_svm(enabled: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_user_context](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#ac0439021c4a4911c391820975084d38c)(type_id: [Std::TypeIndex](https://en.cppreference.com/w/cpp/types/type_index.html), user_context: [Std::SharedPtr≺cv꞉꞉ocl꞉꞉Context꞉꞉UserContext≻](https://en.cppreference.com/w/cpp/memory/shared_ptr.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[unload_prog](https://docs.opencv.org/4.x/d1/d45/classcv_1_1ocl_1_1Context.html#a2f0c81651cac98395c68f88756d92468)(prog: [Cv::Ocl::Program](https://docs.opencv.org/4.x/d2/d88/classcv_1_1ocl_1_1Program.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

use_svm? -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)


