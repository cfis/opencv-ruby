#Index
## Constructors
initialize()

initialize(features: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), params: Cv::Flann::IndexParams, dist_type: Cvflann::FlannDistanceT)


## Methods
build(features: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), params: Cv::Flann::IndexParams, dist_type: Cvflann::FlannDistanceT) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_algorithm -> Cvflann::FlannAlgorithmT

get_distance -> Cvflann::FlannDistanceT

knn_search(query: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), indices: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), dists: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), knn: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: Cv::Flann::SearchParams) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

load(features: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), filename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

radius_search(query: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), indices: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), dists: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), radius: [Float](https://docs.ruby-lang.org/en/master/Float.html), max_results: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), params: Cv::Flann::SearchParams) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

release -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

save(filename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


