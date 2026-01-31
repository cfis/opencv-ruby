#include <opencv2/core_detect.hpp>
#include "core_detect-rb.hpp"

using namespace Rice;

void Init_CoreDetect()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnnObjdetect = define_module_under(rb_mCv, "DnnObjdetect");

  Rice::Data_Type<cv::dnn_objdetect::object> rb_cCvDnnObjdetectObject = define_class_under<cv::dnn_objdetect::object>(rb_mCvDnnObjdetect, "Object").
    define_constructor(Constructor<cv::dnn_objdetect::object>()).
    define_attr("xmin", &cv::dnn_objdetect::object::xmin).
    define_attr("xmax", &cv::dnn_objdetect::object::xmax).
    define_attr("ymin", &cv::dnn_objdetect::object::ymin).
    define_attr("ymax", &cv::dnn_objdetect::object::ymax).
    define_attr("class_idx", &cv::dnn_objdetect::object::class_idx).
    define_attr("label_name", &cv::dnn_objdetect::object::label_name).
    define_attr("class_prob", &cv::dnn_objdetect::object::class_prob);

  Rice::Data_Type<cv::dnn_objdetect::InferBbox> rb_cCvDnnObjdetectInferBbox = define_class_under<cv::dnn_objdetect::InferBbox>(rb_mCvDnnObjdetect, "InferBbox").
    define_constructor(Constructor<cv::dnn_objdetect::InferBbox, cv::Mat, cv::Mat, cv::Mat>(),
      Arg("_delta_bbox"), Arg("_class_scores"), Arg("_conf_scores")).
    define_method<void(cv::dnn_objdetect::InferBbox::*)(double)>("filter", &cv::dnn_objdetect::InferBbox::filter,
      Arg("thresh") = static_cast<double>(0.8)).
    define_attr("detections", &cv::dnn_objdetect::InferBbox::detections);
}