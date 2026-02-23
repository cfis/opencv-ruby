#include <opencv2/xphoto/dct_image_denoising.hpp>
#include "dct_image_denoising-rb.hpp"

using namespace Rice;

void Init_Xphoto_DctImageDenoising()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");

  rb_mCvXphoto.define_module_function<void(*)(const cv::Mat&, cv::Mat&, const double, const int)>("dct_denoising", &cv::xphoto::dctDenoising,
    Arg("src"), Arg("dst"), Arg("sigma"), Arg("psize") = static_cast<const int>(16));
}
