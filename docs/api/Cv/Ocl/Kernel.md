#[Kernel](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a46b9185ef45da15d6a6823496e206a0c)()

[initialize](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a46b9185ef45da15d6a6823496e206a0c)(kname: [String](https://docs.ruby-lang.org/en/master/String.html), prog: [Cv::Ocl::Program](https://docs.opencv.org/4.x/d2/d88/classcv_1_1ocl_1_1Program.html))

[initialize](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a46b9185ef45da15d6a6823496e206a0c)(kname: [String](https://docs.ruby-lang.org/en/master/String.html), prog: [Cv::Ocl::ProgramSource](https://docs.opencv.org/4.x/d5/de3/classcv_1_1ocl_1_1ProgramSource.html), buildopts: [String](https://docs.ruby-lang.org/en/master/String.html), errmsg: [Rice::Pointer≺string≻](https://ruby-rice.github.io/4.x/ruby_api/pointer))


## Methods
[assign](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a40a54607403c7a97648ebbdc1fd58c13)(k: [Cv::Ocl::Kernel](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html)) -> [Cv::Ocl::Kernel](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html)

[assign](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a40a54607403c7a97648ebbdc1fd58c13)(k: [Cv::Ocl::Kernel](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html)) -> [Cv::Ocl::Kernel](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html)

[compile_work_group_size](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a45d1fe80bed5fe85974a83d08c67ca53)(wsz: [Rice::Pointer≺unsigned Int64≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[create](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#af4c66ae727523e0a1155b9837848e8a6)(kname: [String](https://docs.ruby-lang.org/en/master/String.html), prog: [Cv::Ocl::Program](https://docs.opencv.org/4.x/d2/d88/classcv_1_1ocl_1_1Program.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[create](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#af4c66ae727523e0a1155b9837848e8a6)(kname: [String](https://docs.ruby-lang.org/en/master/String.html), prog: [Cv::Ocl::ProgramSource](https://docs.opencv.org/4.x/d5/de3/classcv_1_1ocl_1_1ProgramSource.html), buildopts: [String](https://docs.ruby-lang.org/en/master/String.html), errmsg: [Rice::Pointer≺string≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[empty?](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a405ff97081b9506249b7f31fd22191d6) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[initialize_copy](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a46b9185ef45da15d6a6823496e206a0c)(k: [Cv::Ocl::Kernel](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[local_mem_size](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a9a22e8dbd4fd080ac2c1946d1bae220c) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[prefered_work_group_size_multiple](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a4c7c188799b17f593647f3476de0ec4f) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[ptr](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a7faaa893844331a6c8ea3a9e9be3f2e4) -> [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[run](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a1ce6b92ee1801a96913402483f086e4a)(dims: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), globalsize: [Rice::Pointer≺unsigned Int64≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), localsize: [Rice::Pointer≺unsigned Int64≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), sync: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), q: [Cv::Ocl::Queue](https://docs.opencv.org/4.x/dd/dc0/classcv_1_1ocl_1_1Queue.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[run_profiling](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#a9e3957a938a48d16a665bfc170759461)(dims: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), globalsize: [Rice::Pointer≺unsigned Int64≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), localsize: [Rice::Pointer≺unsigned Int64≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), q: [Cv::Ocl::Queue](https://docs.opencv.org/4.x/dd/dc0/classcv_1_1ocl_1_1Queue.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[run_task](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#afdc8795606e2db6d3186d8fb339d4623)(sync: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), q: [Cv::Ocl::Queue](https://docs.opencv.org/4.x/dd/dc0/classcv_1_1ocl_1_1Queue.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[set](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#aff26198735930885f1f78e1990937475)(i: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), image_2d: [Cv::Ocl::Image2D](https://docs.opencv.org/4.x/d0/d4e/classcv_1_1ocl_1_1Image2D.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[set](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#aff26198735930885f1f78e1990937475)(i: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), arg: [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[set](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#aff26198735930885f1f78e1990937475)(i: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[set](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#aff26198735930885f1f78e1990937475)(i: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), value: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), sz: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[work_group_size](https://docs.opencv.org/4.x/dd/d4c/classcv_1_1ocl_1_1Kernel.html#ad4d8b8b503683b9ab5764e4faa54984a) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)


