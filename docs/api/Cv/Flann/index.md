#Index
## Constructors
initialize()

initialize(features: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), params: Cv::Flann::IndexParams, dist_type: Cvflann::FlannDistanceT)


## Methods
build(features: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), params: Cv::Flann::IndexParams, dist_type: Cvflann::FlannDistanceT) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

get_algorithm -> Cvflann::FlannAlgorithmT

get_distance -> Cvflann::FlannDistanceT

load?(features: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), filename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

release -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

save(filename: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


