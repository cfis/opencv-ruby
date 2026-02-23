#include <opencv2/saliency/saliencyBaseClasses.hpp>
#include "saliencyBaseClasses-rb.hpp"

using namespace Rice;

void Init_Saliency_SaliencyBaseClasses()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvSaliency = define_module_under(rb_mCv, "Saliency");

  Rice::Data_Type<cv::saliency::Saliency> rb_cCvSaliencySaliency = define_class_under<cv::saliency::Saliency, cv::Algorithm>(rb_mCvSaliency, "Saliency").
    define_method<bool(cv::saliency::Saliency::*)(cv::InputArray, cv::OutputArray)>("compute_saliency", &cv::saliency::Saliency::computeSaliency,
      Arg("image"), Arg("saliency_map"));

  Rice::Data_Type<cv::saliency::StaticSaliency> rb_cCvSaliencyStaticSaliency = define_class_under<cv::saliency::StaticSaliency, cv::saliency::Saliency>(rb_mCvSaliency, "StaticSaliency").
    define_method<bool(cv::saliency::StaticSaliency::*)(cv::InputArray, cv::OutputArray)>("compute_binary_map", &cv::saliency::StaticSaliency::computeBinaryMap,
      Arg("_saliency_map"), Arg("_binary_map"));

  Rice::Data_Type<cv::saliency::MotionSaliency> rb_cCvSaliencyMotionSaliency = define_class_under<cv::saliency::MotionSaliency, cv::saliency::Saliency>(rb_mCvSaliency, "MotionSaliency");

  Rice::Data_Type<cv::saliency::Objectness> rb_cCvSaliencyObjectness = define_class_under<cv::saliency::Objectness, cv::saliency::Saliency>(rb_mCvSaliency, "Objectness");
}
