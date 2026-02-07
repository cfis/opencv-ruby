#[GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)
## Singleton Methods
[default_allocator](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5c97009a327d58934cf00cd879a24755) -> [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html)

[get_std_allocator](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a31e089f29c260a3eec9b94a197bbb418) -> [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html)

[set_default_allocator](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc463cf6516957a2d78bd03c6d81de5)(allocator: [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(allocator: [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(m: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), roi: [Cv::Rect2i](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(arr: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), allocator: [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(m: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), row_range: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html), col_range: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), allocator: [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), data: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), step: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), allocator: [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), s: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html), allocator: [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), s: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html), allocator: [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html))

[initialize](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), data: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), step: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Attributes
[allocator](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a1dc1f7a23c89d2a36f0efc7db1b0d5a4): [Cv::Cuda::GpuMat::Allocator](https://docs.opencv.org/4.x/df/d98/classcv_1_1cuda_1_1GpuMat_1_1Allocator.html) (read/write)

[cols](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a9265a32d8d29fe29804a0cb8f57213e9): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[data](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5139f9492f9079c7b9e414d50da332a3): [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[dataend](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ad76c4f58490134f1acf3e580e669c58b): [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[datastart](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ade4a4dfc61facd5f18143b4c9d56dbae): [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[flags](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#adfd242b365e79ebc382a0829d8e9f44f): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[refcount](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af528e8b675a72fd79ff1f399b7dd42df): [Rice::Pointer≺int≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[rows](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a7385022ca9114e5f5058dbb2f12467cb): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[step](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af46427ea4c9b3fe7687e3afa84baede3): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)


## Methods
[adjust_roi](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a6cdd55bdc067e64e693929f9c290017b)(dtop: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), dbottom: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), dleft: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), dright: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[assign](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a842187dd1b01ca6d4b984ec79386a2c0)(m: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[assign_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a03e76eb8993215020cff624ace66d7e6)(m: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[call](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a2b3c25e36b0f82ca8f9f74b6ae68c41d)(row_range: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html), col_range: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[call](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a2b3c25e36b0f82ca8f9f74b6ae68c41d)(roi: [Cv::Rect2i](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[channels](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a538fc6d75281b4ecb7ad50e4555f3fc6) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[clone](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ae1d42819f7f3251478cd6edab8069758) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[col](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#aac2b18c2ef3fbefc6f776cc313b966c0)(x: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[col_range](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a7256892911593daf1bdefb183d6fd29e)(r: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[col_range](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a7256892911593daf1bdefb183d6fd29e)(startcol: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), endcol: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[continuous?](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a400fc4c7880bf132f2ffea03892486b0) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[convert_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ac15573aeafb223f9341658118a54e254)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), rtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[convert_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ac15573aeafb223f9341658118a54e254)(dst: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), rtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[convert_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ac15573aeafb223f9341658118a54e254)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), rtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[convert_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ac15573aeafb223f9341658118a54e254)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), rtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), alpha: [Float](https://docs.ruby-lang.org/en/master/Float.html), beta: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[convert_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ac15573aeafb223f9341658118a54e254)(dst: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), rtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), alpha: [Float](https://docs.ruby-lang.org/en/master/Float.html), beta: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[convert_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ac15573aeafb223f9341658118a54e254)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), rtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), alpha: [Float](https://docs.ruby-lang.org/en/master/Float.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[convert_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ac15573aeafb223f9341658118a54e254)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), rtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), alpha: [Float](https://docs.ruby-lang.org/en/master/Float.html), beta: [Float](https://docs.ruby-lang.org/en/master/Float.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[convert_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ac15573aeafb223f9341658118a54e254)(dst: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), rtype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), alpha: [Float](https://docs.ruby-lang.org/en/master/Float.html), beta: [Float](https://docs.ruby-lang.org/en/master/Float.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc77b91600fe774e398c1978b52cc0f)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc77b91600fe774e398c1978b52cc0f)(dst: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc77b91600fe774e398c1978b52cc0f)(dst: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc77b91600fe774e398c1978b52cc0f)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc77b91600fe774e398c1978b52cc0f)(dst: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), mask: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc77b91600fe774e398c1978b52cc0f)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc77b91600fe774e398c1978b52cc0f)(dst: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), mask: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[copy_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5cc77b91600fe774e398c1978b52cc0f)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[create](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af21454929f3efba4c783edbc27042200)(size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[create](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af21454929f3efba4c783edbc27042200)(rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), cols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[cuda_ptr](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a3fa3b3234ef66ef85bcd8f4ad5d1dcd9) -> [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[depth](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#aaa229d9b2b2f60ecae3b5fbf0603c1b9) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[download](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a027e74e4364ddfd9687b58aa5db8d4e8)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[download](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a027e74e4364ddfd9687b58aa5db8d4e8)(dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[elem_size](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a7e73b4fa94d32e0585564217ebe3fc6c) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[elem_size1](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a988831407704239eadc036df1b615de5) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[empty?](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a509710f61e3a7e13b5ebb2b40984900a) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[initialize_copy](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#af1fd1025a62d333c9c970ca3761a23db)(m: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[locate_roi](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a934d25560bfb1f03c0077e437d41e0cb)(whole_size: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), ofs: [Cv::Point2i](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[ptr](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ab0f7199a9b564bc020e7251588b657f4)(y: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[ptr](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ab0f7199a9b564bc020e7251588b657f4)(y: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[release](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a460951a00945774e9da0b1062ea0a319) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[reshape](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a408e22ed824d1ddf59f58bda895017a8)(cn: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), rows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[row](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a8d6954870e3c3eacc0ea85cd38bd86b4)(y: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[row_range](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a0bf9a88fc518cc9986808aaf916f2182)(r: [Cv::Range](https://docs.opencv.org/4.x/da/d35/classcv_1_1Range.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[row_range](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a0bf9a88fc518cc9986808aaf916f2182)(startrow: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), endrow: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[set_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#aa4c50630ceb28bb28cb861a9a96945a1)(s: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[set_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#aa4c50630ceb28bb28cb861a9a96945a1)(s: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[set_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#aa4c50630ceb28bb28cb861a9a96945a1)(s: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[set_to](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#aa4c50630ceb28bb28cb861a9a96945a1)(s: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

[size](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ab02f97698d8272f0d253f3029329ed10) -> [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)

[step1](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a5ead91d096cca20e59ba9af8574187cc) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[swap](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a7135c058aef51c37884a2b2ae8151631)(mat: [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[type](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#ab0c835e86e2af3c8fc14fee8a2937281) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[update_continuity_flag](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a700ad759547d8c4255833e1fa0e6f751) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[upload](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a00ef5bfe18d14623dcf578a35e40a46b)(arr: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[upload](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html#a00ef5bfe18d14623dcf578a35e40a46b)(arr: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


