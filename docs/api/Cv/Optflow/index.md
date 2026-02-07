#Cv::Optflow
## Singleton Methods
calc_optical_flow_sf(from: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), to: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), flow: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), layers: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), averaging_block_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), max_flow: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

calc_optical_flow_sf(from: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), to: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), flow: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), layers: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), averaging_block_size: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), max_flow: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), sigma_dist: [Float](https://docs.ruby-lang.org/en/master/Float.html), sigma_color: [Float](https://docs.ruby-lang.org/en/master/Float.html), postprocess_window: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), sigma_dist_fix: [Float](https://docs.ruby-lang.org/en/master/Float.html), sigma_color_fix: [Float](https://docs.ruby-lang.org/en/master/Float.html), occ_thr: [Float](https://docs.ruby-lang.org/en/master/Float.html), upscale_averaging_radius: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), upscale_sigma_dist: [Float](https://docs.ruby-lang.org/en/master/Float.html), upscale_sigma_color: [Float](https://docs.ruby-lang.org/en/master/Float.html), speed_up_thr: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[calc_optical_flow_sparse_to_dense](https://docs.opencv.org/4.x/d2/d84/group__optflow.html#gad6aa63f2703202806fe18dc1353b5f4b)(from: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), to: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), flow: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), grid_step: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), k: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), sigma: [Float](https://docs.ruby-lang.org/en/master/Float.html), use_post_proc: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), fgs_lambda: [Float](https://docs.ruby-lang.org/en/master/Float.html), fgs_sigma: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

create_opt_flow_deep_flow -> Cv::Ptr≺cv꞉꞉DenseOpticalFlow≻

create_opt_flow_dual_tvl1 -> Cv::Ptr≺cv꞉꞉optflow꞉꞉DualTVL1OpticalFlow≻

create_opt_flow_farneback -> Cv::Ptr≺cv꞉꞉DenseOpticalFlow≻

create_opt_flow_simple_flow -> Cv::Ptr≺cv꞉꞉DenseOpticalFlow≻

create_opt_flow_sparse_to_dense -> Cv::Ptr≺cv꞉꞉DenseOpticalFlow≻


