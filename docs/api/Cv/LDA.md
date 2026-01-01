#[LDA](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html)
## Singleton Methods
[subspace_project](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a69c7019a344edc5c55799c16a9fc9ada)(w: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mean: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[subspace_reconstruct](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#acbf9949e7567e23af5f71c29fcef76d4)(w: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mean: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a5e8ec64b33aea2317631be0f9b85d833)(num_components: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))

[initialize](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a5e8ec64b33aea2317631be0f9b85d833)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), labels: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), num_components: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Methods
[compute](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a68c714a24483a1afd1864fbac7fe2048)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), labels: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[eigenvalues](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a09eeb511758f419c8d079489e2c5c939) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[eigenvectors](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a70ef2afa53f4eb93b4b98a8e359cc628) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[load](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#ace12ed0301bbd01b8fc16934c9a4c580)(filename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[load](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#ace12ed0301bbd01b8fc16934c9a4c580)(node: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[project](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#ac8b4067465dda3972a74d4f15ef1087c)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[reconstruct](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a64eb8bb493d5c491e6d28ea04501c068)(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[save](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a6576e46845c6c06257d8093cb9fcf591)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[save](https://docs.opencv.org/4.x/db/d59/classcv_1_1LDA.html#a6576e46845c6c06257d8093cb9fcf591)(filename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


