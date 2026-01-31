#include <opencv2/fuzzy/fuzzy_image.hpp>
#include "fuzzy_image-rb.hpp"

using namespace Rice;

void Init_Fuzzy_FuzzyImage()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFt = define_module_under(rb_mCv, "Ft");

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, const int)>("create_kernel", &cv::ft::createKernel,
    Arg("a"), Arg("b"), Arg("kernel"), Arg("chn"));

  rb_mCvFt.define_module_function<void(*)(int, int, cv::OutputArray, const int)>("create_kernel", &cv::ft::createKernel,
    Arg("function"), Arg("radius"), Arg("kernel"), Arg("chn"));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, int, int)>("inpaint", &cv::ft::inpaint,
    Arg("image"), Arg("mask"), Arg("output"), Arg("radius"), Arg("function"), Arg("algorithm"));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("filter", &cv::ft::filter,
    Arg("image"), Arg("kernel"), Arg("output"));
}