#[PCA](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a50ad1a87273a258055a331d5a4c63ce4)()

[initialize](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a50ad1a87273a258055a331d5a4c63ce4)(data: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mean: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), retained_variance: [Float](https://docs.ruby-lang.org/en/master/Float.html))

[initialize](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a50ad1a87273a258055a331d5a4c63ce4)(data: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mean: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), max_components: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Attributes
[eigenvalues](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a1c9d34c02df49120474a4a366b971303): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[eigenvectors](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a8fed85cf5f9d8bb9b17f031398cb74a0): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[mean](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a1bca9d1cc7808b7d08b2a046ee92cd11): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)


## Methods
[back_project](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a5f84cfbdb25b9833cc1bfb5bd484ea79)(vec: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[back_project](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a5f84cfbdb25b9833cc1bfb5bd484ea79)(vec: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), result: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[call](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a63b4df4e66a94799762349a7aff557bb)(data: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mean: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), max_components: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::PCA](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html)

[call](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a63b4df4e66a94799762349a7aff557bb)(data: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mean: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), retained_variance: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::PCA](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html)

[project](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a67c9a3f8fe804f40be58c88a3ae73f41)(vec: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[project](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a67c9a3f8fe804f40be58c88a3ae73f41)(vec: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), result: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[read](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#aa41a4bdd788b67e7e83de8c096f30816)(fn: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/d3/d8d/classcv_1_1PCA.html#a8be99fa476731ff5429c241e9a92a57b)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


