#include <opencv2/ximgproc/lsc.hpp>
#include "lsc-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Lsc()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::SuperpixelLSC> rb_cCvXimgprocSuperpixelLSC = define_class_under<cv::ximgproc::SuperpixelLSC, cv::Algorithm>(rb_mCvXimgproc, "SuperpixelLSC").
    define_method<int(cv::ximgproc::SuperpixelLSC::*)() const>("get_number_of_superpixels", &cv::ximgproc::SuperpixelLSC::getNumberOfSuperpixels).
    define_method<void(cv::ximgproc::SuperpixelLSC::*)(int)>("iterate", &cv::ximgproc::SuperpixelLSC::iterate,
      Arg("num_iterations") = static_cast<int>(10)).
    define_method<void(cv::ximgproc::SuperpixelLSC::*)(cv::OutputArray) const>("get_labels", &cv::ximgproc::SuperpixelLSC::getLabels,
      Arg("labels_out")).
    define_method<void(cv::ximgproc::SuperpixelLSC::*)(cv::OutputArray, bool) const>("get_label_contour_mask", &cv::ximgproc::SuperpixelLSC::getLabelContourMask,
      Arg("image"), Arg("thick_line") = static_cast<bool>(true)).
    define_method<void(cv::ximgproc::SuperpixelLSC::*)(int)>("enforce_label_connectivity", &cv::ximgproc::SuperpixelLSC::enforceLabelConnectivity,
      Arg("min_element_size") = static_cast<int>(25));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::SuperpixelLSC>(*)(cv::InputArray, int, float)>("create_superpixel_lsc", &cv::ximgproc::createSuperpixelLSC,
    Arg("image"), Arg("region_size") = static_cast<int>(10), Arg("ratio") = static_cast<float>(0.075f));
}