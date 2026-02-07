#[Dictionary](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html)
## Singleton Methods
[get_bits_from_byte_list](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#aa3bc5c683875f80db77a58b1b300e598)(byte_list: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), marker_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[get_byte_list_from_bits](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#af64929dff16f07347e6a449f48c78ec9)(bits: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#a17acff2600946000f9d65ecadfb3590e)()

[initialize](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#a17acff2600946000f9d65ecadfb3590e)(bytes_list: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), _marker_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), maxcorr: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Attributes
[bytes_list](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#acd75143ec1fe49467dccc67503a66f07): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[marker_size](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#a996eb5d27e061fedf0550092a6149ed7): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

[max_correction_bits](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#a729196b33a1a678a82f01f8e15d7864b): [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)


## Methods
[generate_image_marker](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#af51c65595d7f0a15f99dfa829788cda5)(id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), side_pixels: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), _img: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), border_bits: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_distance_to_id](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#af49505e713e72ead5314216d0c2842d7)(bits: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), all_rotations: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[identify](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#a82348e625eafe407794a4a757168b70d)(only_bits: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), idx: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), rotation: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), max_correction_rate: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[read_dictionary](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#a69ec5ae547b01be07b7ce8c437ad1db4)(fn: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[write_dictionary](https://docs.opencv.org/4.x/d5/d0b/classcv_1_1aruco_1_1Dictionary.html#a2d0bfe5fab9f66d822cfdaadd1a477f2)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html), name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


