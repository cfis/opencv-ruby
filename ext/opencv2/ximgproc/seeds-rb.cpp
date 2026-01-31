#include <opencv2/ximgproc/seeds.hpp>
#include "seeds-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Seeds()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::SuperpixelSEEDS> rb_cCvXimgprocSuperpixelSEEDS = define_class_under<cv::ximgproc::SuperpixelSEEDS, cv::Algorithm>(rb_mCvXimgproc, "SuperpixelSEEDS").
    define_method<int(cv::ximgproc::SuperpixelSEEDS::*)()>("get_number_of_superpixels", &cv::ximgproc::SuperpixelSEEDS::getNumberOfSuperpixels).
    define_method<void(cv::ximgproc::SuperpixelSEEDS::*)(cv::InputArray, int)>("iterate", &cv::ximgproc::SuperpixelSEEDS::iterate,
      Arg("img"), Arg("num_iterations") = static_cast<int>(4)).
    define_method<void(cv::ximgproc::SuperpixelSEEDS::*)(cv::OutputArray)>("get_labels", &cv::ximgproc::SuperpixelSEEDS::getLabels,
      Arg("labels_out")).
    define_method<void(cv::ximgproc::SuperpixelSEEDS::*)(cv::OutputArray, bool)>("get_label_contour_mask", &cv::ximgproc::SuperpixelSEEDS::getLabelContourMask,
      Arg("image"), Arg("thick_line") = static_cast<bool>(false));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::SuperpixelSEEDS>(*)(int, int, int, int, int, int, int, bool)>("create_superpixel_seeds", &cv::ximgproc::createSuperpixelSEEDS,
    Arg("image_width"), Arg("image_height"), Arg("image_channels"), Arg("num_superpixels"), Arg("num_levels"), Arg("prior") = static_cast<int>(2), Arg("histogram_bins") = static_cast<int>(5), Arg("double_step") = static_cast<bool>(false));
}