#include <opencv2/xphoto/bm3d_image_denoising.hpp>
#include "bm3d_image_denoising-rb.hpp"

using namespace Rice;

void Init_Xphoto_Bm3dImageDenoising()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");

  Enum<cv::xphoto::TransformTypes> rb_cCvXphotoTransformTypes = define_enum_under<cv::xphoto::TransformTypes>("TransformTypes", rb_mCvXphoto).
    define_value("HAAR", cv::xphoto::TransformTypes::HAAR);

  Enum<cv::xphoto::Bm3dSteps> rb_cCvXphotoBm3dSteps = define_enum_under<cv::xphoto::Bm3dSteps>("Bm3dSteps", rb_mCvXphoto).
    define_value("BM3D_STEPALL", cv::xphoto::Bm3dSteps::BM3D_STEPALL).
    define_value("BM3D_STEP1", cv::xphoto::Bm3dSteps::BM3D_STEP1).
    define_value("BM3D_STEP2", cv::xphoto::Bm3dSteps::BM3D_STEP2);

  rb_mCvXphoto.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, float, int, int, int, int, int, int, float, int, int, int)>("bm3d_denoising", &cv::xphoto::bm3dDenoising,
    Arg("src"), Arg("dst_step1"), Arg("dst_step2"), Arg("h") = static_cast<float>(1), Arg("template_window_size") = static_cast<int>(4), Arg("search_window_size") = static_cast<int>(16), Arg("block_matching_step1") = static_cast<int>(2500), Arg("block_matching_step2") = static_cast<int>(400), Arg("group_size") = static_cast<int>(8), Arg("sliding_step") = static_cast<int>(1), Arg("beta") = static_cast<float>(2.0f), Arg("norm_type") = static_cast<int>(cv::NORM_L2), Arg("step") = static_cast<int>(cv::xphoto::BM3D_STEPALL), Arg("transform_type") = static_cast<int>(cv::xphoto::HAAR));

  rb_mCvXphoto.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, int, int, int, int, int, int, float, int, int, int)>("bm3d_denoising", &cv::xphoto::bm3dDenoising,
    Arg("src"), Arg("dst"), Arg("h") = static_cast<float>(1), Arg("template_window_size") = static_cast<int>(4), Arg("search_window_size") = static_cast<int>(16), Arg("block_matching_step1") = static_cast<int>(2500), Arg("block_matching_step2") = static_cast<int>(400), Arg("group_size") = static_cast<int>(8), Arg("sliding_step") = static_cast<int>(1), Arg("beta") = static_cast<float>(2.0f), Arg("norm_type") = static_cast<int>(cv::NORM_L2), Arg("step") = static_cast<int>(cv::xphoto::BM3D_STEPALL), Arg("transform_type") = static_cast<int>(cv::xphoto::HAAR));
}