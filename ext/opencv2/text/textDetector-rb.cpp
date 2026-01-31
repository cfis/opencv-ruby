#include <opencv2/text/textDetector.hpp>
#include "textDetector-rb.hpp"

using namespace Rice;

void Init_Text_TextDetector()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvText = define_module_under(rb_mCv, "Text");

  Rice::Data_Type<cv::text::TextDetector> rb_cCvTextTextDetector = define_class_under<cv::text::TextDetector>(rb_mCvText, "TextDetector").
    define_method<void(cv::text::TextDetector::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<float>&)>("detect", &cv::text::TextDetector::detect,
      Arg("input_image"), Arg("bbox"), Arg("confidence"));

  Rice::Data_Type<cv::text::TextDetectorCNN> rb_cCvTextTextDetectorCNN = define_class_under<cv::text::TextDetectorCNN, cv::text::TextDetector>(rb_mCvText, "TextDetectorCNN").
    define_method<void(cv::text::TextDetectorCNN::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<float>&)>("detect", &cv::text::TextDetectorCNN::detect,
      Arg("input_image"), Arg("bbox"), Arg("confidence")).
    define_singleton_function<cv::Ptr<cv::text::TextDetectorCNN>(*)(const cv::String&, const cv::String&, std::vector<cv::Size_<int>>)>("create", &cv::text::TextDetectorCNN::create,
      Arg("model_arch_filename"), Arg("model_weights_filename"), Arg("detection_sizes")).
    define_singleton_function<cv::Ptr<cv::text::TextDetectorCNN>(*)(const cv::String&, const cv::String&)>("create", &cv::text::TextDetectorCNN::create,
      Arg("model_arch_filename"), Arg("model_weights_filename"));
}