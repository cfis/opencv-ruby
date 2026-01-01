#Image2BlobParams
## Constructors
initialize()

initialize(scalefactor: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html), size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), mean: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html), swap_rb: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), ddepth: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), datalayout: Cv::Dnn::DataLayout, mode: Cv::Dnn::ImagePaddingMode, border_value: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html))


## Attributes
border_value: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html) (read/write)

datalayout: [Cv::Dnn::DataLayout]() (read/write)

ddepth: [Integer](https://docs.ruby-lang.org/en/master/Integer.html) (read/write)

mean: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html) (read/write)

paddingmode: [Cv::Dnn::ImagePaddingMode]() (read/write)

scalefactor: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html) (read/write)

size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html) (read/write)

swap_rb: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html) (read/write)


## Methods
blob_rect_to_image_rect(r_blob: [Cv::Rect](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html), size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)) -> [Cv::Rect](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)

blob_rects_to_image_rects(r_blob: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), r_img: [Std::Vector≺cv꞉꞉Rect_≺int≻≻](https://en.cppreference.com/w/cpp/container/vector.html), size: [Cv::Size](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


