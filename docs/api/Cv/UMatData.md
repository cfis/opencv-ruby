#[UMatData](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#acf6afbd0fafee36cafe5c10ff82cc45d)(allocator: [Cv::MatAllocator](https://docs.opencv.org/4.x/df/d4c/classcv_1_1MatAllocator.html))


## Attributes
[allocator_context](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a02c6b0ae16a63d3b9db6c0d2bdea8b9e): [Std::SharedPtr≺void≻](https://en.cppreference.com/w/cpp/memory/shared_ptr.html) (read/write)

[allocator_flags_](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a398a4153df8d1af5fd5a26996d1b4684): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[curr_allocator](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a7e737c9fe94d01dc12729e2dcea38485): [Cv::MatAllocator](https://docs.opencv.org/4.x/df/d4c/classcv_1_1MatAllocator.html) (read/write)

[data](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a20e87bb7088a637bdd9e1bc6ed649419): [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[flags](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#abd20502f4de49d5bf2fe2147d3f49d83): [Cv::UMatData::MemoryFlag]() (read/write)

[handle](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#aba264d5c9040ab073de11c64c766d653): [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[mapcount](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a962745e56207df9044692e6fa0617f57): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[origdata](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#aee30a2d2615e8e4d7fcfb2c893ac9839): [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[original_u_mat_data](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a4bdd72ed97e5afd923d661cd6e6f6471): [Cv::UMatData](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html) (read/write)

[prev_allocator](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#aaefdaa34b364c74fa54c72da4a218384): [Cv::MatAllocator](https://docs.opencv.org/4.x/df/d4c/classcv_1_1MatAllocator.html) (read/write)

[refcount](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a21d534e3d518241614744ecf92119a84): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[size](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#ab3bf7b4c0a3f1206def1008d9f9150ba): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[urefcount](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#afb9eb71d0e7cb31fa6b636bb2e62e5dc): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[userdata](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a0ac6f5f68de43c177a9b040ecc7611f2): [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)


## Methods
[copy_on_map?](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#ae5183bcbc64aa706848ef32401e4b202) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[device_copy_obsolete?](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a637d69a885ec00d4d69559efb748fa6b) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[device_mem_mapped?](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#acf725c681271182c34317ac7686b415e) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[host_copy_obsolete?](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a52b9f7ef6e7b51fd9429d50bf115ad62) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[lock](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#afd0d8141835b66eb92cd65c4d2f25b51) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[mark_device_copy_obsolete](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#aa7ed39306d6008f2f83654e67856a414)(flag: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[mark_device_mem_mapped](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a2d5b899a98a2ead70375caa03cc37a29)(flag: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[mark_host_copy_obsolete](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a613d3a32b2b6543662d2a9809ce05217)(flag: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[temp_copied_u_mat?](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#a858c76492f954666835719215e04129c) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[temp_u_mat?](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#ae0fe4f5c2d26556d535bc86b02a424d1) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[unlock](https://docs.opencv.org/4.x/db/d58/structcv_1_1UMatData.html#ad3c8c1e9b0692239610e8d830e581230) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


