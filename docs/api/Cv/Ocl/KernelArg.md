#[KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)
## Singleton Methods
[constant](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#a357cca635048b2a6e2606f07d30efd31)(m: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

[local](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#ae99e4f30c874011acee657294d077b36)(local_mem_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

ptr_read_only(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

ptr_read_write(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

ptr_write_only(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

read_only(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html), wscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), iwscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

read_only_no_size(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html), wscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), iwscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

read_write(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html), wscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), iwscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

read_write_no_size(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html), wscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), iwscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

write_only(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html), wscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), iwscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)

write_only_no_size(m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html), wscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), iwscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Ocl::KernelArg](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#af81d15769012672366ef12dbd35970ff)()

[initialize](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#af81d15769012672366ef12dbd35970ff)(_flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), _m: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html), wscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), iwscale: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), _obj: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), _sz: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Attributes
[flags](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#a6c2adb1ffd71913a3c37ea4f0e0583f5): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[iwscale](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#a097562f84bb9d6a6bf28f53369fc26c2): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[m](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#ac893d5710cca7d85c85b194a4e38afaf): [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html) (read/write)

[obj](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#a415569785153582f595b68d65576d2c5): [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[sz](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#a7c4ecb345f1bd57c86f9395c7b82de91): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[wscale](https://docs.opencv.org/4.x/d3/d17/classcv_1_1ocl_1_1KernelArg.html#aafa6d7b275138dd568afb41a388c2fc4): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)


