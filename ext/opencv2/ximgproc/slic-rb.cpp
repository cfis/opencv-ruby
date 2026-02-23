#include <opencv2/ximgproc/slic.hpp>
#include "slic-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Slic()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Enum<cv::ximgproc::SLICType> rb_cCvXimgprocSLICType = define_enum_under<cv::ximgproc::SLICType>("SLICType", rb_mCvXimgproc).
    define_value("SLIC", cv::ximgproc::SLICType::SLIC).
    define_value("SLICO", cv::ximgproc::SLICType::SLICO).
    define_value("MSLIC", cv::ximgproc::SLICType::MSLIC);

  Rice::Data_Type<cv::ximgproc::SuperpixelSLIC> rb_cCvXimgprocSuperpixelSLIC = define_class_under<cv::ximgproc::SuperpixelSLIC, cv::Algorithm>(rb_mCvXimgproc, "SuperpixelSLIC").
    define_method<int(cv::ximgproc::SuperpixelSLIC::*)() const>("get_number_of_superpixels", &cv::ximgproc::SuperpixelSLIC::getNumberOfSuperpixels).
    define_method<void(cv::ximgproc::SuperpixelSLIC::*)(int)>("iterate", &cv::ximgproc::SuperpixelSLIC::iterate,
      Arg("num_iterations") = static_cast<int>(10)).
    define_method<void(cv::ximgproc::SuperpixelSLIC::*)(cv::OutputArray) const>("get_labels", &cv::ximgproc::SuperpixelSLIC::getLabels,
      Arg("labels_out")).
    define_method<void(cv::ximgproc::SuperpixelSLIC::*)(cv::OutputArray, bool) const>("get_label_contour_mask", &cv::ximgproc::SuperpixelSLIC::getLabelContourMask,
      Arg("image"), Arg("thick_line") = static_cast<bool>(true)).
    define_method<void(cv::ximgproc::SuperpixelSLIC::*)(int)>("enforce_label_connectivity", &cv::ximgproc::SuperpixelSLIC::enforceLabelConnectivity,
      Arg("min_element_size") = static_cast<int>(25));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::SuperpixelSLIC>(*)(cv::InputArray, int, int, float)>("create_superpixel_slic", &cv::ximgproc::createSuperpixelSLIC,
    Arg("image"), Arg("algorithm") = static_cast<int>(cv::ximgproc::SLICO), Arg("region_size") = static_cast<int>(10), Arg("ruler") = static_cast<float>(10.0f));
}
