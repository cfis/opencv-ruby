#include <opencv2/xphoto/inpainting.hpp>
#include "inpainting-rb.hpp"

using namespace Rice;

void Init_Xphoto_Inpainting()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");

  Enum<cv::xphoto::InpaintTypes> rb_cCvXphotoInpaintTypes = define_enum_under<cv::xphoto::InpaintTypes>("InpaintTypes", rb_mCvXphoto).
    define_value("INPAINT_SHIFTMAP", cv::xphoto::InpaintTypes::INPAINT_SHIFTMAP).
    define_value("INPAINT_FSR_BEST", cv::xphoto::InpaintTypes::INPAINT_FSR_BEST).
    define_value("INPAINT_FSR_FAST", cv::xphoto::InpaintTypes::INPAINT_FSR_FAST);

  rb_mCvXphoto.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, cv::Mat&, const int)>("inpaint", &cv::xphoto::inpaint,
    Arg("src"), Arg("mask"), Arg("dst"), Arg("algorithm_type"));
}
