#[MSER](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#ac14ab32f45fd5b160265df15f3aad575)(delta: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), min_area: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), max_area: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), max_variation: [Float](https://docs.ruby-lang.org/en/master/Float.html), min_diversity: [Float](https://docs.ruby-lang.org/en/master/Float.html), max_evolution: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), area_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html), min_margin: [Float](https://docs.ruby-lang.org/en/master/Float.html), edge_blur_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> Cv::Ptr≺cv꞉꞉MSER≻


## Methods
[detect_regions](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a49d72a1346413106516a7fc6d95c09bb)(image: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), msers: [Std::Vector≺vector≺cv꞉꞉Point_≺int≻≻≻](https://en.cppreference.com/w/cpp/container/vector.html), bboxes: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[get_area_threshold](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a25f67d3ba4cb6bcfefa690ca49a3039c) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_default_name](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a412b100d43b81c56b9c7e060886453c4) -> [String](https://docs.ruby-lang.org/en/master/String.html)

[get_delta](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a85c31900cc98b08bb416428993093aa1) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_edge_blur_size](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a25bd7588e92c0305e1eab53a408776a1) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_max_area](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a6afe75169c69225a8081cc8f3732c9b5) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_max_evolution](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#ad22f2f404fd0f9266d2ab9bf3efce9ba) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_max_variation](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a0f20f2314d67fed7e509eb2d682681b6) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_min_area](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#aac842d86a5de819490dd8c0105b17c10) -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

[get_min_diversity](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a1ee388fd00bb83c81e2f9aca6f83837e) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_min_margin](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a2d13405ec30124e51288ce7baff082d2) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_pass2_only?](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a181a9a49a969620a76cbebbf1de0bfa2) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[set_area_threshold](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#ab05fe070724a12c8f12ac06eac60dbfd)(area_threshold: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_delta](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a9828f6a0cc9b0aebf87db9ee34c8b2f7)(delta: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_edge_blur_size](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a4a60f41d7728128749733d1477c272f9)(edge_blur_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_max_area](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#ad768e2445e6cdacd6ed28b5fb533a464)(max_area: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_max_evolution](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a7e4c0d4d22b0abb700fce4001701fe77)(max_evolution: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_max_variation](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#ad43553abfbd04bee710053738e52d0c0)(max_variation: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_min_area](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a90de7b99fcbcf2b184420dedcb5912b3)(min_area: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_min_diversity](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#a048f0e052f9c6a8f13b1039741218930)(min_diversity: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_min_margin](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#ad7f668b6f9d473c2041b03defd6a44d0)(min_margin: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_pass2_only](https://docs.opencv.org/4.x/d3/d28/classcv_1_1MSER.html#aba564613ffdcd6a89ef0e381c4b02c48)(f: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


