#include <opencv2/xphoto/oilpainting.hpp>
#include "oilpainting-rb.hpp"

using namespace Rice;

void Init_Xphoto_Oilpainting()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");

  rb_mCvXphoto.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int)>("oil_painting", &cv::xphoto::oilPainting,
    Arg("src"), Arg("dst"), Arg("size"), Arg("dyn_ratio"), Arg("code"));

  rb_mCvXphoto.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int)>("oil_painting", &cv::xphoto::oilPainting,
    Arg("src"), Arg("dst"), Arg("size"), Arg("dyn_ratio"));
}
