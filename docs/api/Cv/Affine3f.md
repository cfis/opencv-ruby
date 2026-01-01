#[Affine3f](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)
## Singleton Methods
[identity](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#acf5d919fc383da6777f2f66746ae9466) -> [Cv::Affine3f](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a116afdeed21ac6a341033ff38a01b4a2)()

[initialize](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a116afdeed21ac6a341033ff38a01b4a2)(affine: [Cv::Matx44f](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html))

[initialize](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a116afdeed21ac6a341033ff38a01b4a2)(vals: [Rice::Pointer≺float≻](https://ruby-rice.github.io/4.x/ruby_api/pointer))

[initialize](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a116afdeed21ac6a341033ff38a01b4a2)(rvec: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html), t: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html))

[initialize](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a116afdeed21ac6a341033ff38a01b4a2)(data: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html), t: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html))

[initialize](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a116afdeed21ac6a341033ff38a01b4a2)(r: [Cv::Matx33f](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html), t: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html))


## Attributes
[matrix](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#ad122a1f67e7b1d20fd2cb511f2fe7d5d): [Cv::Matx44f](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html) (read/write)


## Methods
\*(arg_0: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)) -> [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

\*(arg_0: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)) -> [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

[concatenate](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a82684a32c8dee80e0a82d992eb5a83fa)(affine: [Cv::Affine3f](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)) -> [Cv::Affine3f](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)

[inv](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#ac4a16f4a77037c883dbbc2a4f617ee4f)(method: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Cv::Affine3f](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)

[linear](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a914f41895b8a246232db4a186b70d480) -> [Cv::Matx33f](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html)

[linear](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a914f41895b8a246232db4a186b70d480)(l: [Cv::Matx33f](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[rotate](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a990d571a479b9b336f30c259fb74d18c)(r: [Cv::Matx33f](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html)) -> [Cv::Affine3f](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)

[rotate](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a990d571a479b9b336f30c259fb74d18c)(rvec: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)) -> [Cv::Affine3f](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)

[rotation](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a6a6b70508a7d7fd7725696852da7a20c) -> [Cv::Matx33f](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html)

[rotation](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a6a6b70508a7d7fd7725696852da7a20c)(rvec: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[rotation](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a6a6b70508a7d7fd7725696852da7a20c)(r: [Cv::Matx33f](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[rotation](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a6a6b70508a7d7fd7725696852da7a20c)(data: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[rvec](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a2b55e155790f606db5eb913bd350645b) -> [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

[translate](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a11d9cdc588a9c08c0c1c205a872663fd)(t: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)) -> [Cv::Affine3f](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)

[translation](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a19e2decf4df4a6e72118f9ef6482d502) -> [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

[translation](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html#a19e2decf4df4a6e72118f9ef6482d502)(t: [Cv::Vec3f](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


