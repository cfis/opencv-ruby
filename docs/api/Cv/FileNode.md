#[FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)
## Singleton Methods
collection?(flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

empty_collection?(flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

flow?(flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

map?(flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

seq?(flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a062a89a78d3cab1e7949b3d0fd3d60ee)()

[initialize](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a062a89a78d3cab1e7949b3d0fd3d60ee)(fs: Cv::FileStorage::Impl, block_idx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), ofs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))

[initialize](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a062a89a78d3cab1e7949b3d0fd3d60ee)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html), block_idx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), ofs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Attributes
[block_idx](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a79b8df175f56f5a36509ce0d310b4039): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[fs](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#acb6381c79910c136ae68b7c83a63f005): [Cv::FileStorage::Impl]() (read/write)

[ofs](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a824f3fd3cd0f3a3be9cecc66ceb32065): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)


## Methods
>>(arg_0: [Std::Vector≺cv꞉꞉KeyPoint≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

>>(arg_0: [Std::Vector≺cv꞉꞉DMatch≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

>>(arg_0: [Cv::DMatch](https://docs.opencv.org/4.x/d4/de0/classcv_1_1DMatch.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

>>(arg_0: [Cv::KeyPoint](https://docs.opencv.org/4.x/d2/d29/classcv_1_1KeyPoint.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[\[\]](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a611004b953e5a13140f2d344ed4f6398)(i: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)

[\[\]](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a611004b953e5a13140f2d344ed4f6398)(nodename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)

[\[\]](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a611004b953e5a13140f2d344ed4f6398)(nodename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)

[assign](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#ae34495dd683467189f84125f685deac1)(node: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)

[empty?](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a82d59aab4765da6140c238c54aadfa92) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[initialize_copy](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a062a89a78d3cab1e7949b3d0fd3d60ee)(node: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[int?](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#aeac30395ae3473911171a2091c6ab74c) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[keys](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a0b54218dfbdd81d2a92f8095ac05cea8) -> [Std::Vector≺string≻](https://en.cppreference.com/w/cpp/container/vector.html)

[map?](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#afe948d153d1962ff4c9ad02b1295d832) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[mat](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a42a7627680e1866327c479e0e38cc889) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[name](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a95a49dbbedd455d780cf8dd220f6addc) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[named?](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#aa129964f34bc9c288bdd6195c71f0836) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[none?](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a6039b64bf7c1719056f3ef2626d882e1) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[ptr](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a4b5e47a4fff3909e3e1ac14bf563d5c3) -> [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[ptr](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a4b5e47a4fff3909e3e1ac14bf563d5c3) -> [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[raw_size](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a7ddda6e2aa1c1c6c08e89db3d9afe9d0) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[read_raw](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a8c491ab24daea27a82a3b64b8b3b85a2)(fmt: [String](https://docs.ruby-lang.org/en/master/String.html), vec: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), len: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[real](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#ae46beda960c10cd574302b3bec63849c) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[real?](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a2b4bb5e70a940bc5543207387923f5aa) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[seq?](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#aa2671f0a2a477a9f82d73e1bad1f5158) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[set_value](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a279bef7b343cbe935402be1d1ee8bdcf)(type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), value: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), len: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[size](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#a05c11e00d20223cde61677de91c71197) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[string](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#ae7fa61092f596efa610a7f672885f3d6) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[string?](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#abbc622e50535692d0ca5f2e70589a175) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

to_f -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

to_f32 -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

to_i -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

to_i64 -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

to_s -> [String](https://docs.ruby-lang.org/en/master/String.html)

[type](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html#ad0fd448e25719a94320ebe574b87f997) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)


