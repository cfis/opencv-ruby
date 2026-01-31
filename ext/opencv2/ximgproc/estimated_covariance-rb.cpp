#include <opencv2/ximgproc/estimated_covariance.hpp>
#include "estimated_covariance-rb.hpp"

using namespace Rice;

void Init_Ximgproc_EstimatedCovariance()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int)>("covariance_estimation", &cv::ximgproc::covarianceEstimation,
    Arg("src"), Arg("dst"), Arg("window_rows"), Arg("window_cols"));
}