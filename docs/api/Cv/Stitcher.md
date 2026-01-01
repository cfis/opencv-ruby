#[Stitcher](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html)
## Singleton Methods
[create](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a94ea28f7f5005571aeb3f75a6de59484)(mode: [Cv::Stitcher::Mode](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a114713924ec05a0309f4df7e918c0324)) -> Cv::Ptr≺cv꞉꞉Stitcher≻


## Constructors
[initialize](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html)()


## Methods
[blender](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#af99a29ab6bf57c5855cdacc91f406e42) -> Cv::Ptr≺cv꞉꞉detail꞉꞉Blender≻

[blender](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#af99a29ab6bf57c5855cdacc91f406e42) -> Cv::Ptr≺cv꞉꞉detail꞉꞉Blender≻

[bundle_adjuster](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#af4dfbb09600eb48bf4cacbd13c5e6b0d) -> Cv::Ptr≺cv꞉꞉detail꞉꞉BundleAdjusterBase≻

[bundle_adjuster](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#af4dfbb09600eb48bf4cacbd13c5e6b0d) -> Cv::Ptr≺cv꞉꞉detail꞉꞉BundleAdjusterBase≻

[cameras](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a52929072fecde6e7e8e08e13c0b90d03) -> [Std::Vector≺cv꞉꞉detail꞉꞉CameraParams≻](https://en.cppreference.com/w/cpp/container/vector.html)

[component](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a7c61a21114463b8a4ee848fd4d73314d) -> [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)

[compose_panorama](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#acc8409a6b2e548de1653f0dc5c2ccb02)(pano: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Stitcher::Status](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a507409ce9435dd89857469d12ec06b45)

[compose_panorama](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#acc8409a6b2e548de1653f0dc5c2ccb02)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), pano: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Stitcher::Status](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a507409ce9435dd89857469d12ec06b45)

[compositing_resol](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ad13d2d50b253e471fbaf041b9a044571) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[estimate_transform](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a4c25557af4d40a79a4d1f23d9548131d)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), masks: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Stitcher::Status](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a507409ce9435dd89857469d12ec06b45)

[estimator](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a19ab856bc8617dabf338cc8977213343) -> Cv::Ptr≺cv꞉꞉detail꞉꞉Estimator≻

[estimator](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a19ab856bc8617dabf338cc8977213343) -> Cv::Ptr≺cv꞉꞉detail꞉꞉Estimator≻

[exposure_compensator](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ae1793ea1b1fd5a45d2a04fd6a5c2f4dd) -> Cv::Ptr≺cv꞉꞉detail꞉꞉ExposureCompensator≻

[exposure_compensator](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ae1793ea1b1fd5a45d2a04fd6a5c2f4dd) -> Cv::Ptr≺cv꞉꞉detail꞉꞉ExposureCompensator≻

[features_finder](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a81b3c104e13f9d23a7f5803e8dfa613b) -> Cv::Ptr≺cv꞉꞉Feature2D≻

[features_finder](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a81b3c104e13f9d23a7f5803e8dfa613b) -> Cv::Ptr≺cv꞉꞉Feature2D≻

[features_matcher](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ac5cf82d173728b92cc7674f1325cc606) -> Cv::Ptr≺cv꞉꞉detail꞉꞉FeaturesMatcher≻

[features_matcher](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ac5cf82d173728b92cc7674f1325cc606) -> Cv::Ptr≺cv꞉꞉detail꞉꞉FeaturesMatcher≻

[interpolation_flags](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#abc0c8f54a1d223a1098206654813d973) -> [Cv::InterpolationFlags](https://docs.opencv.org/4.x/da/d54/group__imgproc__transform.html#ga5bb5a1fea74ea38e1a5445ca803ff121)

[matching_mask](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a2f9f735f0a72ec71fbc5d15bfe343b62) -> [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)

[pano_confidence_thresh](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a3755bbeca7f4c80dc42af034f7621568) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[registration_resol](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a9b90774eabdf68c9ee864918d620538d) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[result_mask](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ac56296a206e88fe886470fe09738c2c8) -> [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)

[seam_estimation_resol](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ac559c3eb228614f9402ff3eba23a08f5) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[seam_finder](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a2989234215594f8fb519afcebd8d6ae5) -> Cv::Ptr≺cv꞉꞉detail꞉꞉SeamFinder≻

[seam_finder](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a2989234215594f8fb519afcebd8d6ae5) -> Cv::Ptr≺cv꞉꞉detail꞉꞉SeamFinder≻

[set_blender](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a79651cf9e4b87cb6af26caa0535b9baa)(b: Cv::Ptr≺cv꞉꞉detail꞉꞉Blender≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_bundle_adjuster](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#aa3060cbd7d492a53052754439e830d40)(bundle_adjuster: Cv::Ptr≺cv꞉꞉detail꞉꞉BundleAdjusterBase≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_compositing_resol](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#afe927e80fcb2ca2061630ddd98eebba8)(resol_mpx: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_estimator](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a29fecbbacdfd0adc964f8ce451c0046b)(estimator: Cv::Ptr≺cv꞉꞉detail꞉꞉Estimator≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_exposure_compensator](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a487373f15a54192e6a85ce6b04151d91)(exposure_comp: Cv::Ptr≺cv꞉꞉detail꞉꞉ExposureCompensator≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_features_finder](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a943d01c149aa987e289f6be9b63d4e4b)(features_finder: Cv::Ptr≺cv꞉꞉Feature2D≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_features_matcher](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ada7fb8b0e696bfe3104f73d07ab0b5c4)(features_matcher: Cv::Ptr≺cv꞉꞉detail꞉꞉FeaturesMatcher≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_interpolation_flags](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a253d04b8dcd3c674321b29139c769873)(interp_flags: [Cv::InterpolationFlags](https://docs.opencv.org/4.x/da/d54/group__imgproc__transform.html#ga5bb5a1fea74ea38e1a5445ca803ff121)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_matching_mask](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ad1591614305b0385f8a6152458f93955)(mask: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_pano_confidence_thresh](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a6f5e62bc1dd5d7bdb5f9313a2c21c558)(conf_thresh: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_registration_resol](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a9912fe8c095b8385267908e5ef707439)(resol_mpx: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_seam_estimation_resol](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ad0fcef52b2fedda1dbb90ea780cd7979)(resol_mpx: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_seam_finder](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ad813cf8a3493fa6fe53343f3f5a1da81)(seam_finder: Cv::Ptr≺cv꞉꞉detail꞉꞉SeamFinder≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_transform](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a1bbb3bb8cc7763a0177a05b21c97f794)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), cameras: [Std::Vector≺cv꞉꞉detail꞉꞉CameraParams≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Cv::Stitcher::Status](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a507409ce9435dd89857469d12ec06b45)

[set_transform](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a1bbb3bb8cc7763a0177a05b21c97f794)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), cameras: [Std::Vector≺cv꞉꞉detail꞉꞉CameraParams≻](https://en.cppreference.com/w/cpp/container/vector.html), component: [Std::Vector≺int≻](https://en.cppreference.com/w/cpp/container/vector.html)) -> [Cv::Stitcher::Status](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a507409ce9435dd89857469d12ec06b45)

[set_warper](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#adb1219c1caae710736a5a5e6b13ad21b)(creator: Cv::Ptr≺cv꞉꞉WarperCreator≻) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_wave_correct_kind](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a17413f5c06e4e569bfd45e01d4e8ff4a)(kind: [Cv::Detail::WaveCorrectKind](https://docs.opencv.org/4.x/d7/d74/group__stitching__rotation.html#ga83b24d4c3e93584986a56d9e43b9cf7f)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[set_wave_correction](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a968a2f4a1faddfdacbcfce54b44bab70)(flag: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[stitch](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a3156a44286a7065ba9e8802023ad2074)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), pano: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Stitcher::Status](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a507409ce9435dd89857469d12ec06b45)

[stitch](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a3156a44286a7065ba9e8802023ad2074)(images: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), masks: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), pano: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [Cv::Stitcher::Status](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a507409ce9435dd89857469d12ec06b45)

[warper](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a96084e9ad81687625c8cc92954f18160) -> Cv::Ptr≺cv꞉꞉WarperCreator≻

[warper](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a96084e9ad81687625c8cc92954f18160) -> Cv::Ptr≺cv꞉꞉WarperCreator≻

[wave_correct_kind](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#ad9c9c9b8a97b686ad3b93f7918c4c6de) -> [Cv::Detail::WaveCorrectKind](https://docs.opencv.org/4.x/d7/d74/group__stitching__rotation.html#ga83b24d4c3e93584986a56d9e43b9cf7f)

[wave_correction?](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#af6a51e0b23dac119a3612d57345f9a7f) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[work_scale](https://docs.opencv.org/4.x/d2/d8d/classcv_1_1Stitcher.html#a69f0feb213330d7e4806892867ac4249) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)


