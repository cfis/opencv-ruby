#include <opencv2/ximgproc/fast_line_detector.hpp>
#include "fast_line_detector-rb.hpp"

using namespace Rice;

void Init_Ximgproc_FastLineDetector()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::FastLineDetector> rb_cCvXimgprocFastLineDetector = define_class_under<cv::ximgproc::FastLineDetector, cv::Algorithm>(rb_mCvXimgproc, "FastLineDetector").
    define_method<void(cv::ximgproc::FastLineDetector::*)(cv::InputArray, cv::OutputArray)>("detect", &cv::ximgproc::FastLineDetector::detect,
      Arg("image"), Arg("lines")).
    define_method<void(cv::ximgproc::FastLineDetector::*)(cv::InputOutputArray, cv::InputArray, bool, cv::Scalar, int)>("draw_segments", &cv::ximgproc::FastLineDetector::drawSegments,
      Arg("image"), Arg("lines"), Arg("draw_arrow") = static_cast<bool>(false), Arg("linecolor") = static_cast<cv::Scalar>(cv::Scalar(0, 0, 255)), Arg("linethickness") = static_cast<int>(1));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::FastLineDetector>(*)(int, float, double, double, int, bool)>("create_fast_line_detector", &cv::ximgproc::createFastLineDetector,
    Arg("length_threshold") = static_cast<int>(10), Arg("distance_threshold") = static_cast<float>(1.414213562f), Arg("canny_th1") = static_cast<double>(50.0), Arg("canny_th2") = static_cast<double>(50.0), Arg("canny_aperture_size") = static_cast<int>(3), Arg("do_merge") = static_cast<bool>(false));
}