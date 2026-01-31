#include <opencv2/xobjdetect.hpp>
#include "xobjdetect-rb.hpp"

using namespace Rice;

void Init_Xobjdetect()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXobjdetect = define_module_under(rb_mCv, "Xobjdetect");

  Rice::Data_Type<cv::xobjdetect::WBDetector> rb_cCvXobjdetectWBDetector = define_class_under<cv::xobjdetect::WBDetector>(rb_mCvXobjdetect, "WBDetector").
    define_method<void(cv::xobjdetect::WBDetector::*)(const cv::FileNode&)>("read", &cv::xobjdetect::WBDetector::read,
      Arg("node")).
    define_method<void(cv::xobjdetect::WBDetector::*)(cv::FileStorage&) const>("write", &cv::xobjdetect::WBDetector::write,
      Arg("fs")).
    define_method<void(cv::xobjdetect::WBDetector::*)(const std::string&, const std::string&)>("train", &cv::xobjdetect::WBDetector::train,
      Arg("pos_samples"), Arg("neg_imgs")).
    define_method<void(cv::xobjdetect::WBDetector::*)(const cv::Mat&, std::vector<cv::Rect_<int>>&, std::vector<double>&)>("detect", &cv::xobjdetect::WBDetector::detect,
      Arg("img"), Arg("bboxes"), Arg("confidences")).
    define_singleton_function<cv::Ptr<cv::xobjdetect::WBDetector>(*)()>("create", &cv::xobjdetect::WBDetector::create);
}