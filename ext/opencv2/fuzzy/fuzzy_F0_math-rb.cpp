#include <opencv2/fuzzy/fuzzy_F0_math.hpp>
#include "fuzzy_F0_math-rb.hpp"

using namespace Rice;

void Init_Fuzzy_FuzzyF0Math()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFt = define_module_under(rb_mCv, "Ft");

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray)>("ft02d_components", &cv::ft::FT02D_components,
    Arg("matrix"), Arg("kernel"), Arg("components"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, int)>("ft02d_inverse_ft", &cv::ft::FT02D_inverseFT,
    Arg("components"), Arg("kernel"), Arg("output"), Arg("width"), Arg("height"));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray)>("ft02d_process", &cv::ft::FT02D_process,
    Arg("matrix"), Arg("kernel"), Arg("output"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvFt.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray, cv::OutputArray, bool)>("ft02d_iteration", &cv::ft::FT02D_iteration,
    Arg("matrix"), Arg("kernel"), Arg("output"), Arg("mask"), Arg("mask_output"), Arg("first_stop"));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, const int, cv::OutputArray)>("ft02d_fl_process", &cv::ft::FT02D_FL_process,
    Arg("matrix"), Arg("radius"), Arg("output"));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, const int, cv::OutputArray)>("ft02d_fl_process_float", &cv::ft::FT02D_FL_process_float,
    Arg("matrix"), Arg("radius"), Arg("output"));
}