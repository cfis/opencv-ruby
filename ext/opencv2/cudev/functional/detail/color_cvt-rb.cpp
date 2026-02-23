#include <opencv2/cudev/functional/detail/color_cvt.hpp>
#include "color_cvt-rb.hpp"

using namespace Rice;

#include "color_cvt-rb.ipp"

void Init_Cudev_Functional_Detail_ColorCvt()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevColorCvtDetail = define_module_under(rb_mCvCudev, "ColorCvtDetail");

  Rice::Data_Type<cv::cudev::color_cvt_detail::ColorChannel<float>> rb_cCvCudevColorCvtDetailColorChannelFloat = define_class_under<cv::cudev::color_cvt_detail::ColorChannel<float>>(rb_mCvCudevColorCvtDetail, "ColorChannelFloat").
    define_constructor(Constructor<cv::cudev::color_cvt_detail::ColorChannel<float>>()).
    define_singleton_function<float(*)()>("max", &cv::cudev::color_cvt_detail::ColorChannel<float>::max).
    define_singleton_function<float(*)()>("half", &cv::cudev::color_cvt_detail::ColorChannel<float>::half);

  rb_mCvCudevColorCvtDetail.define_constant("Rgb_shift", (int)cv::cudev::color_cvt_detail::rgb_shift);
  rb_mCvCudevColorCvtDetail.define_constant("Yuv_shift", (int)cv::cudev::color_cvt_detail::yuv_shift);
  rb_mCvCudevColorCvtDetail.define_constant("Xyz_shift", (int)cv::cudev::color_cvt_detail::xyz_shift);
  rb_mCvCudevColorCvtDetail.define_constant("R2Y", (int)cv::cudev::color_cvt_detail::R2Y);
  rb_mCvCudevColorCvtDetail.define_constant("G2Y", (int)cv::cudev::color_cvt_detail::G2Y);
  rb_mCvCudevColorCvtDetail.define_constant("B2Y", (int)cv::cudev::color_cvt_detail::B2Y);
  rb_mCvCudevColorCvtDetail.define_constant("RY15", (int)cv::cudev::color_cvt_detail::RY15);
  rb_mCvCudevColorCvtDetail.define_constant("GY15", (int)cv::cudev::color_cvt_detail::GY15);
  rb_mCvCudevColorCvtDetail.define_constant("BY15", (int)cv::cudev::color_cvt_detail::BY15);
  rb_mCvCudevColorCvtDetail.define_constant("BLOCK_SIZE", (int)cv::cudev::color_cvt_detail::BLOCK_SIZE);

  Rice::Data_Type<cv::cudev::unary_function<unsigned char, unsigned short>> rb_cUnaryFunctionUnsignedCharUnsignedShort = unary_function_instantiate<unsigned char, unsigned short>(rb_mCvCudevColorCvtDetail, "UnaryFunctionUnsignedCharUnsignedShort");
  Rice::Data_Type<cv::cudev::color_cvt_detail::Gray2RGB5x5<5>> rb_cCvCudevColorCvtDetailGray2RGB5x55 = define_class_under<cv::cudev::color_cvt_detail::Gray2RGB5x5<5>, cv::cudev::unary_function<unsigned char, unsigned short>>(rb_mCvCudevColorCvtDetail, "Gray2RGB5x55").
    define_constructor(Constructor<cv::cudev::color_cvt_detail::Gray2RGB5x5<5>>()).
    define_method<ushort(cv::cudev::color_cvt_detail::Gray2RGB5x5<5>::*)(uchar) const>("call", &cv::cudev::color_cvt_detail::Gray2RGB5x5<5>::operator(),
      Arg("src"));

  Rice::Data_Type<cv::cudev::color_cvt_detail::Gray2RGB5x5<6>> rb_cCvCudevColorCvtDetailGray2RGB5x56 = define_class_under<cv::cudev::color_cvt_detail::Gray2RGB5x5<6>, cv::cudev::unary_function<unsigned char, unsigned short>>(rb_mCvCudevColorCvtDetail, "Gray2RGB5x56").
    define_constructor(Constructor<cv::cudev::color_cvt_detail::Gray2RGB5x5<6>>()).
    define_method<ushort(cv::cudev::color_cvt_detail::Gray2RGB5x5<6>::*)(uchar) const>("call", &cv::cudev::color_cvt_detail::Gray2RGB5x5<6>::operator(),
      Arg("src"));

  Rice::Data_Type<cv::cudev::unary_function<unsigned short, unsigned char>> rb_cUnaryFunctionUnsignedShortUnsignedChar = unary_function_instantiate<unsigned short, unsigned char>(rb_mCvCudevColorCvtDetail, "UnaryFunctionUnsignedShortUnsignedChar");
  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52Gray<5>> rb_cCvCudevColorCvtDetailRGB5x52Gray5 = define_class_under<cv::cudev::color_cvt_detail::RGB5x52Gray<5>, cv::cudev::unary_function<unsigned short, unsigned char>>(rb_mCvCudevColorCvtDetail, "RGB5x52Gray5").
    define_constructor(Constructor<cv::cudev::color_cvt_detail::RGB5x52Gray<5>>()).
    define_method<uchar(cv::cudev::color_cvt_detail::RGB5x52Gray<5>::*)(ushort) const>("call", &cv::cudev::color_cvt_detail::RGB5x52Gray<5>::operator(),
      Arg("src"));

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52Gray<6>> rb_cCvCudevColorCvtDetailRGB5x52Gray6 = define_class_under<cv::cudev::color_cvt_detail::RGB5x52Gray<6>, cv::cudev::unary_function<unsigned short, unsigned char>>(rb_mCvCudevColorCvtDetail, "RGB5x52Gray6").
    define_constructor(Constructor<cv::cudev::color_cvt_detail::RGB5x52Gray<6>>()).
    define_method<uchar(cv::cudev::color_cvt_detail::RGB5x52Gray<6>::*)(ushort) const>("call", &cv::cudev::color_cvt_detail::RGB5x52Gray<6>::operator(),
      Arg("src"));

  rb_mCvCudevColorCvtDetail.define_constant("C_RGB2YUVCoeffs_f", cv::cudev::color_cvt_detail::c_RGB2YUVCoeffs_f);

  rb_mCvCudevColorCvtDetail.define_constant("C_RGB2YUVCoeffs_i", cv::cudev::color_cvt_detail::c_RGB2YUVCoeffs_i);

  rb_mCvCudevColorCvtDetail.define_constant("C_YUV2RGBCoeffs_f", cv::cudev::color_cvt_detail::c_YUV2RGBCoeffs_f);

  rb_mCvCudevColorCvtDetail.define_constant("C_YUV2RGBCoeffs_i", cv::cudev::color_cvt_detail::c_YUV2RGBCoeffs_i);

  rb_mCvCudevColorCvtDetail.define_constant("C_RGB2YCrCbCoeffs_f", cv::cudev::color_cvt_detail::c_RGB2YCrCbCoeffs_f);

  rb_mCvCudevColorCvtDetail.define_constant("C_RGB2YCrCbCoeffs_i", cv::cudev::color_cvt_detail::c_RGB2YCrCbCoeffs_i);

  rb_mCvCudevColorCvtDetail.define_constant("C_YCrCb2RGBCoeffs_f", cv::cudev::color_cvt_detail::c_YCrCb2RGBCoeffs_f);

  rb_mCvCudevColorCvtDetail.define_constant("C_YCrCb2RGBCoeffs_i", cv::cudev::color_cvt_detail::c_YCrCb2RGBCoeffs_i);

  rb_mCvCudevColorCvtDetail.define_constant("C_RGB2XYZ_D65f", cv::cudev::color_cvt_detail::c_RGB2XYZ_D65f);

  rb_mCvCudevColorCvtDetail.define_constant("C_RGB2XYZ_D65i", cv::cudev::color_cvt_detail::c_RGB2XYZ_D65i);

  rb_mCvCudevColorCvtDetail.define_constant("C_XYZ2sRGB_D65f", cv::cudev::color_cvt_detail::c_XYZ2sRGB_D65f);

  rb_mCvCudevColorCvtDetail.define_constant("C_XYZ2sRGB_D65i", cv::cudev::color_cvt_detail::c_XYZ2sRGB_D65i);

  rb_mCvCudevColorCvtDetail.define_constant("C_HsvDivTable", cv::cudev::color_cvt_detail::c_HsvDivTable);

  rb_mCvCudevColorCvtDetail.define_constant("C_HsvDivTable180", cv::cudev::color_cvt_detail::c_HsvDivTable180);

  rb_mCvCudevColorCvtDetail.define_constant("C_HsvDivTable256", cv::cudev::color_cvt_detail::c_HsvDivTable256);

  rb_mCvCudevColorCvtDetail.define_constant("C_HsvSectorData", cv::cudev::color_cvt_detail::c_HsvSectorData);

  rb_mCvCudevColorCvtDetail.define_constant("C_HlsSectorData", cv::cudev::color_cvt_detail::c_HlsSectorData);

  rb_mCvCudevColorCvtDetail.define_constant("LAB_CBRT_TAB_SIZE", (int)cv::cudev::color_cvt_detail::LAB_CBRT_TAB_SIZE);
  rb_mCvCudevColorCvtDetail.define_constant("GAMMA_TAB_SIZE", (int)cv::cudev::color_cvt_detail::GAMMA_TAB_SIZE);
  rb_mCvCudevColorCvtDetail.define_constant("Lab_shift", (int)cv::cudev::color_cvt_detail::lab_shift);
  rb_mCvCudevColorCvtDetail.define_constant("Gamma_shift", (int)cv::cudev::color_cvt_detail::gamma_shift);
  rb_mCvCudevColorCvtDetail.define_constant("Lab_shift2", (int)cv::cudev::color_cvt_detail::lab_shift2);
  rb_mCvCudevColorCvtDetail.define_constant("LAB_CBRT_TAB_SIZE_B", (int)cv::cudev::color_cvt_detail::LAB_CBRT_TAB_SIZE_B);

  rb_mCvCudevColorCvtDetail.define_constant("C_sRGBGammaTab_b", cv::cudev::color_cvt_detail::c_sRGBGammaTab_b);

  rb_mCvCudevColorCvtDetail.define_constant("C_sRGBGammaTab", cv::cudev::color_cvt_detail::c_sRGBGammaTab);

  rb_mCvCudevColorCvtDetail.define_module_function<int(*)(int)>("lab_cbrt_b", &cv::cudev::color_cvt_detail::LabCbrt_b,
    Arg("i"));

  rb_mCvCudevColorCvtDetail.define_module_function<float(*)(float, const float*, int)>("spline_interpolate", &cv::cudev::color_cvt_detail::splineInterpolate,
    Arg("x"), ArgBuffer("tab"), Arg("n"));

  rb_mCvCudevColorCvtDetail.define_constant("C_sRGBInvGammaTab", cv::cudev::color_cvt_detail::c_sRGBInvGammaTab);

  rb_mCvCudevColorCvtDetail.define_constant("C_LabCbrtTab", cv::cudev::color_cvt_detail::c_LabCbrtTab);
}
