#[Subdiv2D](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#aed58be264a17cdbe712b6a35036d13cb)()

[initialize](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#aed58be264a17cdbe712b6a35036d13cb)(rect: [Cv::Rect2i](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html))


## Methods
[edge_dst](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#aee192f95bf19c74619641496c457586d)(edge: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), dstpt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[edge_org](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a5563e3cae0a9b95df63e72f0c12f9389)(edge: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), orgpt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[find_nearest](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a3ec256af000e129e08eb5f269ccdeb0f)(pt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), nearest_pt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_edge](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#af73f08576709bad7a36f8f8e5fc43c84)(edge: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), next_edge_type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_edge_list](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#ab527c11e9938eed53cf9c790afa9416d)(edge_list: [Std::Vector≺cv꞉꞉Vec≺float‚ 4≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_leading_edge_list](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a2d02a1d66ef7f8f267beb549cb2823f1)(leading_edge_list: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_triangle_list](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a26bfe32209bc8ae9ecc53e93da01e466)(triangle_list: [Std::Vector≺cv꞉꞉Vec≺float‚ 6≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_vertex](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a5297daca30f90d1e6d0cc5a75ba76351)(vertex: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), first_edge: [Rice::Pointer≺int≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)

[get_voronoi_facet_list](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a3a9e080423475be056a79da4c04741ea)(idx: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html), facet_list: [Std::Vector≺vector≺cv꞉꞉Point_≺float≻≻≻](https://en.cppreference.com/w/cpp/container/vector.html), facet_centers: [Std::Vector≺cv꞉꞉Point_≺float≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[init_delaunay](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#ae4a3d65e798c46fd6ce64370f24b0287)(rect: [Cv::Rect2i](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[insert](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a37223a499032ef57364f1372ad0c9c2e)(ptvec: [Std::Vector≺cv꞉꞉Point_≺float≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[insert](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a37223a499032ef57364f1372ad0c9c2e)(pt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[locate](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#aec8f1fd5a802f62faa97520b465897d7)(pt: [Cv::Point2f](https://docs.opencv.org/4.x/db/d4e/classcv_1_1Point__.html), edge: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), vertex: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[next_edge](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#a36ebf478e2546615c2db457106393acb)(edge: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[rotate_edge](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#aa1179507f651b67c22e06517fbc6a145)(edge: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), rotate: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[sym_edge](https://docs.opencv.org/4.x/df/dbf/classcv_1_1Subdiv2D.html#aabbb10b8d5b0311b7e22040fc0db56b4)(edge: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)


