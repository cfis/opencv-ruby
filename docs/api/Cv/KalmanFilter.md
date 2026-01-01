#[KalmanFilter](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html)
## Constructors
[initialize](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#ac0799f0611baee9e7e558f016e4a7b40)()

[initialize](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#ac0799f0611baee9e7e558f016e4a7b40)(dynam_params: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), measure_params: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), control_params: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))


## Attributes
[control_matrix](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a6486e7287114810636fb33953280ed52): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[error_cov_post](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a446d8e9a0105b0aa35cd66119c529803): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[error_cov_pre](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#ae1bd3a86f10753d723e7174d570d9ac1): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[gain](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a077d73eb075b00779dc009a9057c27c3): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[measurement_matrix](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a0f60b78726d8eccf74a1f2479c2d1f97): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[measurement_noise_cov](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a828d051035ba807966ad65edf288a08e): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[process_noise_cov](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#af19be9c0630d0f658bdbaea409a35cda): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[state_post](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#add8fb5ac9c04b4600b679698dcb0447d): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[state_pre](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a926dece64b4e0e28c3f58af8b7793669): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[temp1](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#aa3d064a9194c2815dbe19c056b6dc763): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[temp2](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a14866bd506668eb0ed57b3974b3a1ee7): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[temp3](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#afdbe36066a7d7f560aa02abe6be114d8): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[temp4](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a84342f2d9dec1e6389025ad229401809): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[temp5](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a846c2a6222c6e5d8b1385dfbccc83ae0): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)

[transition_matrix](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a0657173e411acbf40d2d3c6b46e03b19): [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html) (read/write)


## Methods
[correct](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#ad2b05172fe48be090c0d82a32d0bb40f)(measurement: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

[init](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#a4f136c39c016d3530c7c5801dd1ddb3b)(dynam_params: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), measure_params: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), control_params: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), type: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[predict](https://docs.opencv.org/4.x/dd/d6a/classcv_1_1KalmanFilter.html#ae682426262f3001e324d6a8d757679ba)(control: [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)


