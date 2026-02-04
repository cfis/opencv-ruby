#include <opencv2/ximgproc/ridgefilter.hpp>
#include "ridgefilter-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Ridgefilter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::RidgeDetectionFilter> rb_cCvXimgprocRidgeDetectionFilter = define_class_under<cv::ximgproc::RidgeDetectionFilter, cv::Algorithm>(rb_mCvXimgproc, "RidgeDetectionFilter").
    define_singleton_function<cv::Ptr<cv::ximgproc::RidgeDetectionFilter>(*)(int, int, int, int, int, double, double, int)>("create", &cv::ximgproc::RidgeDetectionFilter::create,
      Arg("ddepth") = static_cast<int>(CV_32FC1), Arg("dx") = static_cast<int>(1), Arg("dy") = static_cast<int>(1), Arg("ksize") = static_cast<int>(3), Arg("out_dtype") = static_cast<int>(CV_8UC1), Arg("scale") = static_cast<double>(1), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT)).
    define_method<void(cv::ximgproc::RidgeDetectionFilter::*)(cv::InputArray, cv::OutputArray)>("get_ridge_filtered_image", &cv::ximgproc::RidgeDetectionFilter::getRidgeFilteredImage,
      Arg("_img"), Arg("out"));
}