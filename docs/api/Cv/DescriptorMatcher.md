#[DescriptorMatcher](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a08d359b8acc9a5a1828ed6c3c7712ceb)(matcher_type: [Cv::DescriptorMatcher::MatcherType](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#af8b6f4acb8f1a9ea6b73bfcb86b80c3b)) -> Cv::Ptr≺cv꞉꞉DescriptorMatcher≻

[create](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a08d359b8acc9a5a1828ed6c3c7712ceb)(descriptor_matcher_type: [String](https://docs.ruby-lang.org/en/master/String.html)) -> Cv::Ptr≺cv꞉꞉DescriptorMatcher≻


## Methods
[add](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a623a2b07755cf7fb1c79554af73cdbb0)(descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[clear](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a01f97324f1393aae68d9c84874060454) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[clone](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a35261cc2dfb3b5922d10daa8fcfd10ab)(empty_train_data: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Ptr≺cv꞉꞉DescriptorMatcher≻

[empty?](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#ac0951eebe04d00aa66117eab337909e4) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[get_train_descriptors](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a93d741fbc352ae5dfa3df27b52f9cdf2) -> [Std::Vector≺cv꞉꞉Mat≻](https://en.cppreference.com/w/cpp/container/vector.html)

[knn_match](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a378f35c9b1a5dfa4022839a45cdf0e89)(query_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), matches: [Std::Vector≺vector≺cv꞉꞉DMatch≻≻](https://en.cppreference.com/w/cpp/container/vector.html), k: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), masks: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), compact_result: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[knn_match](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a378f35c9b1a5dfa4022839a45cdf0e89)(query_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), train_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), matches: [Std::Vector≺vector≺cv꞉꞉DMatch≻≻](https://en.cppreference.com/w/cpp/container/vector.html), k: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), compact_result: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[mask_supported?](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a3cc074710ccb466a662815969e14cf5e) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[match](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a0f046f47b68ec7074391e1e85c750cba)(query_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), matches: [Std::Vector≺cv꞉꞉DMatch≻](https://en.cppreference.com/w/cpp/container/vector.html), masks: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[match](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a0f046f47b68ec7074391e1e85c750cba)(query_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), train_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), matches: [Std::Vector≺cv꞉꞉DMatch≻](https://en.cppreference.com/w/cpp/container/vector.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[radius_match](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a56b8dcd6fc600f8f2a23212f6e4c5082)(query_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), matches: [Std::Vector≺vector≺cv꞉꞉DMatch≻≻](https://en.cppreference.com/w/cpp/container/vector.html), max_distance: [Float](https://docs.ruby-lang.org/en/master/Float.html), masks: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), compact_result: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[radius_match](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a56b8dcd6fc600f8f2a23212f6e4c5082)(query_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), train_descriptors: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), matches: [Std::Vector≺vector≺cv꞉꞉DMatch≻≻](https://en.cppreference.com/w/cpp/container/vector.html), max_distance: [Float](https://docs.ruby-lang.org/en/master/Float.html), mask: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), compact_result: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[read](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#abb46ea487ffa0c0f9dd72d3de9fd42ab)(file_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[read](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#abb46ea487ffa0c0f9dd72d3de9fd42ab)(arg_0: [Cv::FileNode](https://docs.opencv.org/4.x/de/dd9/classcv_1_1FileNode.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[train](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#a80e9fd98de5908f5348c17696eeb1a32) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#ac921506f2862b292b41de95546319174)(file_name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#ac921506f2862b292b41de95546319174)(arg_0: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#ac921506f2862b292b41de95546319174)(fs: [Cv::FileStorage](https://docs.opencv.org/4.x/da/d56/classcv_1_1FileStorage.html), name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[write](https://docs.opencv.org/4.x/db/d39/classcv_1_1DescriptorMatcher.html#ac921506f2862b292b41de95546319174)(fs: Cv::Ptr≺cv꞉꞉FileStorage≻, name: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


