#include <opencv2/face.hpp>
#include "face-rb.hpp"

using namespace Rice;

void Init_Face()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::FaceRecognizer> rb_cCvFaceFaceRecognizer = define_class_under<cv::face::FaceRecognizer, cv::Algorithm>(rb_mCvFace, "FaceRecognizer").
    define_method("train", &cv::face::FaceRecognizer::train,
      Arg("src"), Arg("labels")).
    define_method("update", &cv::face::FaceRecognizer::update,
      Arg("src"), Arg("labels")).
    define_method<int(cv::face::FaceRecognizer::*)(cv::InputArray) const>("predict", &cv::face::FaceRecognizer::predict,
      Arg("src")).
    define_method<void(cv::face::FaceRecognizer::*)(cv::InputArray, int&, double&) const>("predict", &cv::face::FaceRecognizer::predict,
      Arg("src"), Arg("label"), Arg("confidence")).
    define_method<void(cv::face::FaceRecognizer::*)(cv::InputArray, cv::Ptr<cv::face::PredictCollector>) const>("predict", &cv::face::FaceRecognizer::predict,
      Arg("src"), Arg("collector")).
    define_method<void(cv::face::FaceRecognizer::*)(const cv::String&) const>("write", &cv::face::FaceRecognizer::write,
      Arg("filename")).
    define_method<void(cv::face::FaceRecognizer::*)(const cv::String&)>("read", &cv::face::FaceRecognizer::read,
      Arg("filename")).
    define_method<void(cv::face::FaceRecognizer::*)(cv::FileStorage&) const>("write", &cv::face::FaceRecognizer::write,
      Arg("fs")).
    define_method<void(cv::face::FaceRecognizer::*)(const cv::FileNode&)>("read", &cv::face::FaceRecognizer::read,
      Arg("fn")).
    define_method("empty?", &cv::face::FaceRecognizer::empty).
    define_method("set_label_info", &cv::face::FaceRecognizer::setLabelInfo,
      Arg("label"), Arg("str_info")).
    define_method("get_label_info", &cv::face::FaceRecognizer::getLabelInfo,
      Arg("label")).
    define_method("get_labels_by_string", &cv::face::FaceRecognizer::getLabelsByString,
      Arg("str")).
    define_method("get_threshold", &cv::face::FaceRecognizer::getThreshold).
    define_method("set_threshold", &cv::face::FaceRecognizer::setThreshold,
      Arg("val"));
}