#include <opencv2/ximgproc/scansegment.hpp>
#include "scansegment-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Scansegment()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::ScanSegment> rb_cCvXimgprocScanSegment = define_class_under<cv::ximgproc::ScanSegment, cv::Algorithm>(rb_mCvXimgproc, "ScanSegment").
    define_method<int(cv::ximgproc::ScanSegment::*)()>("get_number_of_superpixels", &cv::ximgproc::ScanSegment::getNumberOfSuperpixels).
    define_method<void(cv::ximgproc::ScanSegment::*)(cv::InputArray)>("iterate", &cv::ximgproc::ScanSegment::iterate,
      Arg("img")).
    define_method<void(cv::ximgproc::ScanSegment::*)(cv::OutputArray)>("get_labels", &cv::ximgproc::ScanSegment::getLabels,
      Arg("labels_out")).
    define_method<void(cv::ximgproc::ScanSegment::*)(cv::OutputArray, bool)>("get_label_contour_mask", &cv::ximgproc::ScanSegment::getLabelContourMask,
      Arg("image"), Arg("thick_line") = static_cast<bool>(false));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::ScanSegment>(*)(int, int, int, int, bool)>("create_scan_segment", &cv::ximgproc::createScanSegment,
    Arg("image_width"), Arg("image_height"), Arg("num_superpixels"), Arg("slices") = static_cast<int>(8), Arg("merge_small") = static_cast<bool>(true));
}
