#[MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a11c8b512e764c96c1e4ec6519df84503)()

[initialize](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a11c8b512e764c96c1e4ec6519df84503)(_m: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html))

[initialize](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a11c8b512e764c96c1e4ec6519df84503)(_m: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), _pt: [Cv::Point2i](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html))

[initialize](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a11c8b512e764c96c1e4ec6519df84503)(_m: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), _row: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), _col: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Attributes
[elem_size](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#abb8c32985f6cb017b926e584c48361dc): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[m](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a20e36deeac061339e0a0fed3fdd2457b): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[ptr](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a5904a30e2069349bca792b54dcf02de7): [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[slice_end](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a135e544f96bb39f2fe713dfd1ab02d02): [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)

[slice_start](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a0b9062870872eadbb5bdda0580e3ea3f): [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer) (read/write)


## Methods
[\[\]](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#aaed03ca7ced6461dd5a951312bdf622e)(i: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[assign_minus](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a8e9e9eab1a0581da604714dabc4311a0)(ofs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)

[assign_plus](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#ab395d2d892e04907cfc1ee879cdcc5a6)(ofs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)

[decrement](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a53a79d18796e6bcbcb12381447ccdcba) -> [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)

[assign](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#ab9137a94a12c00c9360f69c34d5fa7fd)(it: [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)) -> [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)

decrement_post(arg_0: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)

[dereference](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a1b43c8e412185b9d874125cbcaf7438f) -> [Rice::Pointer≺unsigned char≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[increment](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a468f5d085cbb145ee6164a6ad1bdeec6) -> [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)

increment_post(arg_0: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)

[initialize_copy](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a11c8b512e764c96c1e4ec6519df84503)(it: [Cv::MatConstIterator](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[lpos](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a56e2e4fcf08374696d6d99f6173f2081) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[pos](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a85189ac66049666ba8cb89540fef5a63) -> [Cv::Point2i](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)

[pos](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#a85189ac66049666ba8cb89540fef5a63)(_idx: [Rice::Pointer≺int≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[seek](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#acf82c2ab7fe9e81961db497909cee953)(ofs: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), relative: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[seek](https://docs.opencv.org/4.x/d7/dcf/classcv_1_1MatConstIterator.html#acf82c2ab7fe9e81961db497909cee953)(_idx: [Rice::Pointer≺int≻](https://ruby-rice.github.io/4.x/ruby_api/pointer), relative: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


