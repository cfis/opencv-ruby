#include <opencv2/xobjdetect.hpp>
#include "xobjdetect-rb.hpp"

using namespace Rice;

void Init_Xobjdetect()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXobjdetect = define_module_under(rb_mCv, "Xobjdetect");

  Rice::Data_Type<cv::xobjdetect::WBDetector> rb_cCvXobjdetectWBDetector = define_class_under<cv::xobjdetect::WBDetector>(rb_mCvXobjdetect, "WBDetector").
    define_method("read", &cv::xobjdetect::WBDetector::read,
      Arg("node")).
    define_method("write", &cv::xobjdetect::WBDetector::write,
      Arg("fs")).
    define_method("train", &cv::xobjdetect::WBDetector::train,
      Arg("pos_samples"), Arg("neg_imgs")).
    define_method("detect", &cv::xobjdetect::WBDetector::detect,
      Arg("img"), Arg("bboxes"), Arg("confidences")).
    define_singleton_function("create", &cv::xobjdetect::WBDetector::create);
}