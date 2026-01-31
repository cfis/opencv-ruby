#include <opencv2/objdetect/barcode.hpp>
#include "barcode-rb.hpp"

using namespace Rice;

void Init_Objdetect_Barcode()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvBarcode = define_module_under(rb_mCv, "Barcode");

  Rice::Data_Type<cv::barcode::BarcodeDetector> rb_cCvBarcodeBarcodeDetector = define_class_under<cv::barcode::BarcodeDetector, cv::GraphicalCodeDetector>(rb_mCvBarcode, "BarcodeDetector").
    define_constructor(Constructor<cv::barcode::BarcodeDetector>()).
    define_constructor(Constructor<cv::barcode::BarcodeDetector, const std::string&, const std::string&>(),
      Arg("prototxt_path"), Arg("model_path")).
    define_method<bool(cv::barcode::BarcodeDetector::*)(cv::InputArray, cv::InputArray, std::vector<std::string>&, std::vector<std::string>&) const>("decode_with_type", &cv::barcode::BarcodeDetector::decodeWithType,
      Arg("img"), Arg("points"), Arg("decoded_info"), Arg("decoded_type")).
    define_method<bool(cv::barcode::BarcodeDetector::*)(cv::InputArray, std::vector<std::string>&, std::vector<std::string>&, cv::OutputArray) const>("detect_and_decode_with_type", &cv::barcode::BarcodeDetector::detectAndDecodeWithType,
      Arg("img"), Arg("decoded_info"), Arg("decoded_type"), Arg("points") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<double(cv::barcode::BarcodeDetector::*)() const>("get_downsampling_threshold", &cv::barcode::BarcodeDetector::getDownsamplingThreshold).
    define_method<cv::barcode::BarcodeDetector&(cv::barcode::BarcodeDetector::*)(double)>("set_downsampling_threshold", &cv::barcode::BarcodeDetector::setDownsamplingThreshold,
      Arg("thresh")).
    define_method<void(cv::barcode::BarcodeDetector::*)(std::vector<float>&) const>("get_detector_scales", &cv::barcode::BarcodeDetector::getDetectorScales,
      Arg("sizes")).
    define_method<cv::barcode::BarcodeDetector&(cv::barcode::BarcodeDetector::*)(const std::vector<float>&)>("set_detector_scales", &cv::barcode::BarcodeDetector::setDetectorScales,
      Arg("sizes")).
    define_method<double(cv::barcode::BarcodeDetector::*)() const>("get_gradient_threshold", &cv::barcode::BarcodeDetector::getGradientThreshold).
    define_method<cv::barcode::BarcodeDetector&(cv::barcode::BarcodeDetector::*)(double)>("set_gradient_threshold", &cv::barcode::BarcodeDetector::setGradientThreshold,
      Arg("thresh"));
}