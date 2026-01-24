#include <opencv2/ximgproc.hpp>
#include "ximgproc-rb.hpp"

using namespace Rice;

void Init_Ximgproc()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Enum<cv::ximgproc::ThinningTypes> rb_cCvXimgprocThinningTypes = define_enum_under<cv::ximgproc::ThinningTypes>("ThinningTypes", rb_mCvXimgproc).
    define_value("THINNING_ZHANGSUEN", cv::ximgproc::ThinningTypes::THINNING_ZHANGSUEN).
    define_value("THINNING_GUOHALL", cv::ximgproc::ThinningTypes::THINNING_GUOHALL);

  Enum<cv::ximgproc::LocalBinarizationMethods> rb_cCvXimgprocLocalBinarizationMethods = define_enum_under<cv::ximgproc::LocalBinarizationMethods>("LocalBinarizationMethods", rb_mCvXimgproc).
    define_value("BINARIZATION_NIBLACK", cv::ximgproc::LocalBinarizationMethods::BINARIZATION_NIBLACK).
    define_value("BINARIZATION_SAUVOLA", cv::ximgproc::LocalBinarizationMethods::BINARIZATION_SAUVOLA).
    define_value("BINARIZATION_WOLF", cv::ximgproc::LocalBinarizationMethods::BINARIZATION_WOLF).
    define_value("BINARIZATION_NICK", cv::ximgproc::LocalBinarizationMethods::BINARIZATION_NICK);

  rb_mCvXimgproc.define_module_function("ni_black_threshold", &cv::ximgproc::niBlackThreshold,
    Arg("_src"), Arg("_dst"), Arg("max_value"), Arg("type"), Arg("block_size"), Arg("k"), Arg("binarization_method") = static_cast<int>(cv::ximgproc::BINARIZATION_NIBLACK), Arg("r") = static_cast<double>(128));

  rb_mCvXimgproc.define_module_function("thinning", &cv::ximgproc::thinning,
    Arg("src"), Arg("dst"), Arg("thinning_type") = static_cast<int>(cv::ximgproc::THINNING_ZHANGSUEN));

  rb_mCvXimgproc.define_module_function("anisotropic_diffusion", &cv::ximgproc::anisotropicDiffusion,
    Arg("src"), Arg("dst"), Arg("alpha"), Arg("k"), Arg("niters"));
}