#include <opencv2/fuzzy/fuzzy_F1_math.hpp>
#include "fuzzy_F1_math-rb.hpp"

using namespace Rice;

void Init_Fuzzy_FuzzyF1Math()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFt = define_module_under(rb_mCv, "Ft");

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("ft12d_components", &cv::ft::FT12D_components,
    Arg("matrix"), Arg("kernel"), Arg("components"));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::InputArray)>("ft12d_polynomial", &cv::ft::FT12D_polynomial,
    Arg("matrix"), Arg("kernel"), Arg("c00"), Arg("c10"), Arg("c01"), Arg("components"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvFt.define_module_function<void(*)(int, cv::OutputArray, const int)>("ft12d_create_polynom_matrix_vertical", &cv::ft::FT12D_createPolynomMatrixVertical,
    Arg("radius"), Arg("matrix"), Arg("chn"));

  rb_mCvFt.define_module_function<void(*)(int, cv::OutputArray, const int)>("ft12d_create_polynom_matrix_horizontal", &cv::ft::FT12D_createPolynomMatrixHorizontal,
    Arg("radius"), Arg("matrix"), Arg("chn"));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray)>("ft12d_process", &cv::ft::FT12D_process,
    Arg("matrix"), Arg("kernel"), Arg("output"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvFt.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, int)>("ft12d_inverse_ft", &cv::ft::FT12D_inverseFT,
    Arg("components"), Arg("kernel"), Arg("output"), Arg("width"), Arg("height"));
}
