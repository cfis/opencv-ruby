#include <opencv2/objdetect/barcode.hpp>
#include "barcode-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvBarcodeBarcodeDetector;

void Init_Barcode()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvBarcode = define_module_under(rb_mCv, "Barcode");
  
  rb_cCvBarcodeBarcodeDetector = define_class_under<cv::barcode::BarcodeDetector, cv::GraphicalCodeDetector>(rb_mCvBarcode, "BarcodeDetector").
    define_constructor(Constructor<cv::barcode::BarcodeDetector>()).
    define_constructor(Constructor<cv::barcode::BarcodeDetector, const std::string&, const std::string&>(),
      Arg("prototxt_path"), Arg("model_path")).
    define_method("decode_with_type?", &cv::barcode::BarcodeDetector::decodeWithType,
      Arg("img"), Arg("points"), Arg("decoded_info"), Arg("decoded_type")).
    define_method("detect_and_decode_with_type?", &cv::barcode::BarcodeDetector::detectAndDecodeWithType,
      Arg("img"), Arg("decoded_info"), Arg("decoded_type"), Arg("points") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method("get_downsampling_threshold", &cv::barcode::BarcodeDetector::getDownsamplingThreshold).
    define_method("set_downsampling_threshold", &cv::barcode::BarcodeDetector::setDownsamplingThreshold,
      Arg("thresh")).
    define_method("get_detector_scales", &cv::barcode::BarcodeDetector::getDetectorScales,
      Arg("sizes")).
    define_method("set_detector_scales", &cv::barcode::BarcodeDetector::setDetectorScales,
      Arg("sizes")).
    define_method("get_gradient_threshold", &cv::barcode::BarcodeDetector::getGradientThreshold).
    define_method("set_gradient_threshold", &cv::barcode::BarcodeDetector::setGradientThreshold,
      Arg("thresh"));

}