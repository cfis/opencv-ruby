#include <opencv2/imgproc/hal/hal.hpp>
#include "hal-rb.hpp"

using namespace Rice;

void Init_Imgproc_Hal_Hal()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvHal = define_module_under(rb_mCv, "Hal");

  Rice::Data_Type<cv::hal::Filter2D> rb_cCvHalFilter2D = define_class_under<cv::hal::Filter2D>(rb_mCvHal, "Filter2D").
    define_method<void(cv::hal::Filter2D::*)(uchar*, size_t, uchar*, size_t, int, int, int, int, int, int)>("apply", &cv::hal::Filter2D::apply,
      ArgBuffer("arg_0"), Arg("arg_1"), ArgBuffer("arg_2"), Arg("arg_3"), Arg("arg_4"), Arg("arg_5"), Arg("arg_6"), Arg("arg_7"), Arg("arg_8"), Arg("arg_9"));

  Rice::Data_Type<cv::hal::SepFilter2D> rb_cCvHalSepFilter2D = define_class_under<cv::hal::SepFilter2D>(rb_mCvHal, "SepFilter2D").
    define_method<void(cv::hal::SepFilter2D::*)(uchar*, size_t, uchar*, size_t, int, int, int, int, int, int)>("apply", &cv::hal::SepFilter2D::apply,
      ArgBuffer("arg_0"), Arg("arg_1"), ArgBuffer("arg_2"), Arg("arg_3"), Arg("arg_4"), Arg("arg_5"), Arg("arg_6"), Arg("arg_7"), Arg("arg_8"), Arg("arg_9"));

  Rice::Data_Type<cv::hal::Morph> rb_cCvHalMorph = define_class_under<cv::hal::Morph>(rb_mCvHal, "Morph").
    define_method<void(cv::hal::Morph::*)(uchar*, size_t, uchar*, size_t, int, int, int, int, int, int, int, int, int, int)>("apply", &cv::hal::Morph::apply,
      ArgBuffer("arg_0"), Arg("arg_1"), ArgBuffer("arg_2"), Arg("arg_3"), Arg("arg_4"), Arg("arg_5"), Arg("arg_6"), Arg("arg_7"), Arg("arg_8"), Arg("arg_9"), Arg("arg_10"), Arg("arg_11"), Arg("arg_12"), Arg("arg_13"));

  rb_mCvHal.define_module_function<void(*)(int, int, int, uchar*, size_t, uchar*, size_t, int, int, int, int, int, int, uchar*, size_t, int, int, int, int, double, int, bool)>("filter_2d", &cv::hal::filter2D,
    Arg("stype"), Arg("dtype"), Arg("kernel_type"), ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("full_width"), Arg("full_height"), Arg("offset_x"), Arg("offset_y"), ArgBuffer("kernel_data"), Arg("kernel_step"), Arg("kernel_width"), Arg("kernel_height"), Arg("anchor_x"), Arg("anchor_y"), Arg("delta"), Arg("border_type"), Arg("is_submatrix"));

  rb_mCvHal.define_module_function<void(*)(int, int, int, uchar*, size_t, uchar*, size_t, int, int, int, int, int, int, uchar*, int, uchar*, int, int, int, double, int)>("sep_filter_2d", &cv::hal::sepFilter2D,
    Arg("stype"), Arg("dtype"), Arg("ktype"), ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("full_width"), Arg("full_height"), Arg("offset_x"), Arg("offset_y"), ArgBuffer("kernelx_data"), Arg("kernelx_len"), ArgBuffer("kernely_data"), Arg("kernely_len"), Arg("anchor_x"), Arg("anchor_y"), Arg("delta"), Arg("border_type"));

  rb_mCvHal.define_module_function<void(*)(int, int, int, uchar*, size_t, uchar*, size_t, int, int, int, int, int, int, int, int, int, int, int, uchar*, size_t, int, int, int, int, int, const double[4], int, bool)>("morph", &cv::hal::morph,
    Arg("op"), Arg("src_type"), Arg("dst_type"), ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("roi_width"), Arg("roi_height"), Arg("roi_x"), Arg("roi_y"), Arg("roi_width2"), Arg("roi_height2"), Arg("roi_x2"), Arg("roi_y2"), Arg("kernel_type"), ArgBuffer("kernel_data"), Arg("kernel_step"), Arg("kernel_width"), Arg("kernel_height"), Arg("anchor_x"), Arg("anchor_y"), Arg("border_type"), Arg("border_value"), Arg("iterations"), Arg("is_submatrix"));

  rb_mCvHal.define_module_function<void(*)(int, const uchar*, size_t, int, int, uchar*, size_t, int, int, double, double, int)>("resize", &cv::hal::resize,
    Arg("src_type"), ArgBuffer("src_data"), Arg("src_step"), Arg("src_width"), Arg("src_height"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("inv_scale_x"), Arg("inv_scale_y"), Arg("interpolation"));

  rb_mCvHal.define_module_function<void(*)(int, const uchar*, size_t, int, int, uchar*, size_t, int, int, const double[6], int, int, const double[4])>("warp_affine", &cv::hal::warpAffine,
    Arg("src_type"), ArgBuffer("src_data"), Arg("src_step"), Arg("src_width"), Arg("src_height"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("m"), Arg("interpolation"), Arg("border_type"), Arg("border_value"));

  rb_mCvHal.define_module_function<void(*)(int*, int*, short*, int, int, int)>("warp_affine_blockline_nn", &cv::hal::warpAffineBlocklineNN,
    ArgBuffer("adelta"), ArgBuffer("bdelta"), ArgBuffer("xy"), Arg("x0"), Arg("y0"), Arg("bw"));

  rb_mCvHal.define_module_function<void(*)(int*, int*, short*, short*, int, int, int)>("warp_affine_blockline", &cv::hal::warpAffineBlockline,
    ArgBuffer("adelta"), ArgBuffer("bdelta"), ArgBuffer("xy"), ArgBuffer("alpha"), Arg("x0"), Arg("y0"), Arg("bw"));

  rb_mCvHal.define_module_function<void(*)(int, const uchar*, size_t, int, int, uchar*, size_t, int, int, const double[9], int, int, const double[4])>("warp_perspective", &cv::hal::warpPerspective,
    Arg("src_type"), ArgBuffer("src_data"), Arg("src_step"), Arg("src_width"), Arg("src_height"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("m"), Arg("interpolation"), Arg("border_type"), Arg("border_value"));

  rb_mCvHal.define_module_function<void(*)(const double*, short*, double, double, double, int)>("warp_perspective_blockline_nn", &cv::hal::warpPerspectiveBlocklineNN,
    ArgBuffer("m"), ArgBuffer("xy"), Arg("x0"), Arg("y0"), Arg("w0"), Arg("bw"));

  rb_mCvHal.define_module_function<void(*)(const double*, short*, short*, double, double, double, int)>("warp_perspective_blockline", &cv::hal::warpPerspectiveBlockline,
    ArgBuffer("m"), ArgBuffer("xy"), ArgBuffer("alpha"), Arg("x0"), Arg("y0"), Arg("w0"), Arg("bw"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, int, bool)>("cvt_bg_rto_bgr", &cv::hal::cvtBGRtoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("dcn"), Arg("swap_blue"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, bool, int)>("cvt_bg_rto_bgr5x5", &cv::hal::cvtBGRtoBGR5x5,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("scn"), Arg("swap_blue"), Arg("green_bits"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, bool, int)>("cvt_bgr5x5to_bgr", &cv::hal::cvtBGR5x5toBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("dcn"), Arg("swap_blue"), Arg("green_bits"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool)>("cvt_bg_rto_gray", &cv::hal::cvtBGRtoGray,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int)>("cvt_grayto_bgr", &cv::hal::cvtGraytoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int)>("cvt_bgr5x5to_gray", &cv::hal::cvtBGR5x5toGray,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("green_bits"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int)>("cvt_grayto_bgr5x5", &cv::hal::cvtGraytoBGR5x5,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("green_bits"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool, bool, cv::AlgorithmHint)>("cvt_bg_rto_yuv", &cv::hal::cvtBGRtoYUV,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"), Arg("is_cb_cr"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool, bool, cv::AlgorithmHint)>("cvt_yu_vto_bgr", &cv::hal::cvtYUVtoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"), Arg("swap_blue"), Arg("is_cb_cr"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool)>("cvt_bg_rto_xyz", &cv::hal::cvtBGRtoXYZ,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool)>("cvt_xy_zto_bgr", &cv::hal::cvtXYZtoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"), Arg("swap_blue"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool, bool, bool)>("cvt_bg_rto_hsv", &cv::hal::cvtBGRtoHSV,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"), Arg("is_full_range"), Arg("is_hsv"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool, bool, bool)>("cvt_hs_vto_bgr", &cv::hal::cvtHSVtoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"), Arg("swap_blue"), Arg("is_full_range"), Arg("is_hsv"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool, bool, bool)>("cvt_bg_rto_lab", &cv::hal::cvtBGRtoLab,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"), Arg("is_lab"), Arg("srgb"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, int, bool, bool, bool)>("cvt_labto_bgr", &cv::hal::cvtLabtoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"), Arg("swap_blue"), Arg("is_lab"), Arg("srgb"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, bool, int, cv::AlgorithmHint)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, const uchar*, size_t, uchar*, size_t, int, int, int, bool, int, cv::AlgorithmHint)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR,
    ArgBuffer("y_data"), ArgBuffer("uv_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, const uchar*, size_t, uchar*, size_t, int, int, int, bool, int, cv::AlgorithmHint)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR,
    ArgBuffer("y_data"), Arg("y_step"), ArgBuffer("uv_data"), Arg("uv_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, bool, int, cv::AlgorithmHint)>("cvt_three_plane_yu_vto_bgr", &cv::hal::cvtThreePlaneYUVtoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, bool, int, cv::AlgorithmHint)>("cvt_bg_rto_three_plane_yuv", &cv::hal::cvtBGRtoThreePlaneYUV,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("scn"), Arg("swap_blue"), Arg("u_idx"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, uchar*, size_t, int, int, int, bool, int)>("cvt_bg_rto_two_plane_yuv", &cv::hal::cvtBGRtoTwoPlaneYUV,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("y_data"), ArgBuffer("uv_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("scn"), Arg("swap_blue"), Arg("u_idx"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, bool, int, int, cv::AlgorithmHint)>("cvt_one_plane_yu_vto_bgr", &cv::hal::cvtOnePlaneYUVtoBGR,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"), Arg("ycn"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int, int, bool, int, int, cv::AlgorithmHint)>("cvt_one_plane_bg_rto_yuv", &cv::hal::cvtOnePlaneBGRtoYUV,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("scn"), Arg("swap_blue"), Arg("u_idx"), Arg("ycn"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int)>("cvt_rgb_ato_multiplied_rgba", &cv::hal::cvtRGBAtoMultipliedRGBA,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"));

  rb_mCvHal.define_module_function<void(*)(const uchar*, size_t, uchar*, size_t, int, int)>("cvt_multiplied_rgb_ato_rgba", &cv::hal::cvtMultipliedRGBAtoRGBA,
    ArgBuffer("src_data"), Arg("src_step"), ArgBuffer("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"));

  rb_mCvHal.define_module_function<void(*)(int, int, int, const uchar*, size_t, uchar*, size_t, uchar*, size_t, uchar*, size_t, int, int, int)>("integral", &cv::hal::integral,
    Arg("depth"), Arg("sdepth"), Arg("sqdepth"), ArgBuffer("src"), Arg("srcstep"), ArgBuffer("sum"), Arg("sumstep"), ArgBuffer("sqsum"), Arg("sqsumstep"), ArgBuffer("tilted"), Arg("tstep"), Arg("width"), Arg("height"), Arg("cn"));
}
