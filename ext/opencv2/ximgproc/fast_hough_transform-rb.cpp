#include <opencv2/ximgproc/fast_hough_transform.hpp>
#include "fast_hough_transform-rb.hpp"

using namespace Rice;

void Init_Ximgproc_FastHoughTransform()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Enum<cv::ximgproc::AngleRangeOption> rb_cCvXimgprocAngleRangeOption = define_enum_under<cv::ximgproc::AngleRangeOption>("AngleRangeOption", rb_mCvXimgproc).
    define_value("ARO_0_45", cv::ximgproc::AngleRangeOption::ARO_0_45).
    define_value("ARO_45_90", cv::ximgproc::AngleRangeOption::ARO_45_90).
    define_value("ARO_90_135", cv::ximgproc::AngleRangeOption::ARO_90_135).
    define_value("ARO_315_0", cv::ximgproc::AngleRangeOption::ARO_315_0).
    define_value("ARO_315_45", cv::ximgproc::AngleRangeOption::ARO_315_45).
    define_value("ARO_45_135", cv::ximgproc::AngleRangeOption::ARO_45_135).
    define_value("ARO_315_135", cv::ximgproc::AngleRangeOption::ARO_315_135).
    define_value("ARO_CTR_HOR", cv::ximgproc::AngleRangeOption::ARO_CTR_HOR).
    define_value("ARO_CTR_VER", cv::ximgproc::AngleRangeOption::ARO_CTR_VER);

  Enum<cv::ximgproc::HoughOp> rb_cCvXimgprocHoughOp = define_enum_under<cv::ximgproc::HoughOp>("HoughOp", rb_mCvXimgproc).
    define_value("FHT_MIN", cv::ximgproc::HoughOp::FHT_MIN).
    define_value("FHT_MAX", cv::ximgproc::HoughOp::FHT_MAX).
    define_value("FHT_ADD", cv::ximgproc::HoughOp::FHT_ADD).
    define_value("FHT_AVE", cv::ximgproc::HoughOp::FHT_AVE);

  Enum<cv::ximgproc::HoughDeskewOption> rb_cCvXimgprocHoughDeskewOption = define_enum_under<cv::ximgproc::HoughDeskewOption>("HoughDeskewOption", rb_mCvXimgproc).
    define_value("HDO_RAW", cv::ximgproc::HoughDeskewOption::HDO_RAW).
    define_value("HDO_DESKEW", cv::ximgproc::HoughDeskewOption::HDO_DESKEW);

  Enum<cv::ximgproc::RulesOption> rb_cCvXimgprocRulesOption = define_enum_under<cv::ximgproc::RulesOption>("RulesOption", rb_mCvXimgproc).
    define_value("RO_STRICT", cv::ximgproc::RulesOption::RO_STRICT).
    define_value("RO_IGNORE_BORDERS", cv::ximgproc::RulesOption::RO_IGNORE_BORDERS);

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int, int)>("fast_hough_transform", &cv::ximgproc::FastHoughTransform,
    Arg("src"), Arg("dst"), Arg("dst_mat_depth"), Arg("angle_range") = static_cast<int>(cv::ximgproc::ARO_315_135), Arg("op") = static_cast<int>(cv::ximgproc::FHT_ADD), Arg("make_skew") = static_cast<int>(cv::ximgproc::HDO_DESKEW));

  rb_mCvXimgproc.define_module_function<cv::Vec4i(*)(const cv::Point&, cv::InputArray, int, int, int)>("hough_point2_line", &cv::ximgproc::HoughPoint2Line,
    Arg("hough_point"), Arg("src_img_info"), Arg("angle_range") = static_cast<int>(cv::ximgproc::ARO_315_135), Arg("make_skew") = static_cast<int>(cv::ximgproc::HDO_DESKEW), Arg("rules") = static_cast<int>(cv::ximgproc::RO_IGNORE_BORDERS));
}