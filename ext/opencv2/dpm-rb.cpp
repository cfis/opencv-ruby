#include <opencv2/dpm.hpp>
#include "dpm-rb.hpp"

using namespace Rice;

void Init_Dpm()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDpm = define_module_under(rb_mCv, "Dpm");

  Rice::Data_Type<cv::dpm::DPMDetector> rb_cCvDpmDPMDetector = define_class_under<cv::dpm::DPMDetector>(rb_mCvDpm, "DPMDetector").
    define_method<bool(cv::dpm::DPMDetector::*)() const>("empty?", &cv::dpm::DPMDetector::isEmpty).
    define_method<void(cv::dpm::DPMDetector::*)(cv::Mat&, std::vector<cv::dpm::DPMDetector::ObjectDetection>&)>("detect", &cv::dpm::DPMDetector::detect,
      Arg("image"), Arg("objects")).
    define_method<const std::vector<std::string>&(cv::dpm::DPMDetector::*)() const>("get_class_names", &cv::dpm::DPMDetector::getClassNames).
    define_method<size_t(cv::dpm::DPMDetector::*)() const>("get_class_count", &cv::dpm::DPMDetector::getClassCount).
    define_singleton_function<cv::Ptr<cv::dpm::DPMDetector>(*)(const std::vector<std::string>&, const std::vector<std::string>&)>("create", &cv::dpm::DPMDetector::create,
      Arg("filenames"), Arg("class_names") = static_cast<const std::vector<std::string>&>(std::vector<std::string>()));

  Rice::Data_Type<cv::dpm::DPMDetector::ObjectDetection> rb_cCvDpmDPMDetectorObjectDetection = define_class_under<cv::dpm::DPMDetector::ObjectDetection>(rb_cCvDpmDPMDetector, "ObjectDetection").
    define_constructor(Constructor<cv::dpm::DPMDetector::ObjectDetection>()).
    define_constructor(Constructor<cv::dpm::DPMDetector::ObjectDetection, const cv::Rect&, float, int>(),
      Arg("rect"), Arg("score"), Arg("class_id") = static_cast<int>(-1)).
    define_attr("rect", &cv::dpm::DPMDetector::ObjectDetection::rect).
    define_attr("score", &cv::dpm::DPMDetector::ObjectDetection::score).
    define_attr("class_id", &cv::dpm::DPMDetector::ObjectDetection::classID);
}
