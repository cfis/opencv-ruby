#include <opencv2/ximgproc/peilin.hpp>
#include "peilin-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Peilin()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<cv::Matx23d(*)(cv::InputArray)>("pei_lin_normalization", &cv::ximgproc::PeiLinNormalization,
    Arg("i"));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("pei_lin_normalization", &cv::ximgproc::PeiLinNormalization,
    Arg("i"), Arg("t"));
}