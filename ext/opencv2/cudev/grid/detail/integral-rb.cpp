#include <opencv2/cudev/grid/detail/integral.hpp>
#include "integral-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Detail_Integral()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevIntegralDetail = define_module_under(rb_mCvCudev, "IntegralDetail");

  rb_mCvCudevIntegralDetail.define_module_function<uchar4(*)(unsigned int)>("int_to_uchar4", &cv::cudev::integral_detail::int_to_uchar4,
    Arg("in"));

  rb_mCvCudevIntegralDetail.define_module_function<void(*)(const cv::cudev::GlobPtr<uint4>, cv::cudev::GlobPtr<uint4>)>("horisontal_pass_8u_shfl_kernel", &cv::cudev::integral_detail::horisontal_pass_8u_shfl_kernel,
    Arg("img"), Arg("integral"));

  rb_mCvCudevIntegralDetail.define_module_function<void(*)(const cv::cudev::GlobPtr<uchar>, cv::cudev::GlobPtr<uint>, int, int, cudaStream_t)>("horisontal_pass_8u_shfl", &cv::cudev::integral_detail::horisontal_pass_8u_shfl,
    Arg("src"), Arg("integral"), Arg("rows"), Arg("cols"), Arg("stream"));

  rb_mCvCudevIntegralDetail.define_module_function<void(*)(const cv::cudev::GlobPtr<uchar>&, const cv::cudev::GlobPtr<uint>&, int, int, cudaStream_t)>("integral", &cv::cudev::integral_detail::integral,
    Arg("src"), Arg("dst"), Arg("rows"), Arg("cols"), Arg("stream"));

  rb_mCvCudevIntegralDetail.define_module_function<void(*)(const cv::cudev::GlobPtr<uchar>&, const cv::cudev::GlobPtr<int>&, int, int, cudaStream_t)>("integral", &cv::cudev::integral_detail::integral,
    Arg("src"), Arg("dst"), Arg("rows"), Arg("cols"), Arg("stream"));
}