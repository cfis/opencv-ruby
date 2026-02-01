#include <opencv2/core/cuda/detail/color_detail.hpp>
#include "color_detail-rb.hpp"

using namespace Rice;

#include "color_detail-rb.ipp"

void Init_Core_Cuda_Detail_ColorDetail()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Module rb_mCvCudaDeviceColorDetail = define_module_under(rb_mCvCudaDevice, "ColorDetail");

  Rice::Data_Type<cv::cuda::device::color_detail::ColorChannel<float>> rb_cCvCudaDeviceColorDetailColorChannelFloat = define_class_under<cv::cuda::device::color_detail::ColorChannel<float>>(rb_mCvCudaDeviceColorDetail, "ColorChannelFloat").
    define_constructor(Constructor<cv::cuda::device::color_detail::ColorChannel<float>>()).
    define_singleton_function<float(*)()>("max", &cv::cuda::device::color_detail::ColorChannel<float>::max).
    define_singleton_function<float(*)()>("half", &cv::cuda::device::color_detail::ColorChannel<float>::half);

  rb_mCvCudaDeviceColorDetail.define_constant("B2YF", cv::cuda::device::color_detail::B2YF);

  rb_mCvCudaDeviceColorDetail.define_constant("G2YF", cv::cuda::device::color_detail::G2YF);

  rb_mCvCudaDeviceColorDetail.define_constant("R2YF", cv::cuda::device::color_detail::R2YF);

  rb_mCvCudaDeviceColorDetail.define_constant("YCBF", cv::cuda::device::color_detail::YCBF);

  rb_mCvCudaDeviceColorDetail.define_constant("YCRF", cv::cuda::device::color_detail::YCRF);

  rb_mCvCudaDeviceColorDetail.define_constant("YCBI", cv::cuda::device::color_detail::YCBI);

  rb_mCvCudaDeviceColorDetail.define_constant("YCRI", cv::cuda::device::color_detail::YCRI);

  rb_mCvCudaDeviceColorDetail.define_constant("B2UF", cv::cuda::device::color_detail::B2UF);

  rb_mCvCudaDeviceColorDetail.define_constant("R2VF", cv::cuda::device::color_detail::R2VF);

  rb_mCvCudaDeviceColorDetail.define_constant("B2UI", cv::cuda::device::color_detail::B2UI);

  rb_mCvCudaDeviceColorDetail.define_constant("R2VI", cv::cuda::device::color_detail::R2VI);

  rb_mCvCudaDeviceColorDetail.define_constant("U2BF", cv::cuda::device::color_detail::U2BF);

  rb_mCvCudaDeviceColorDetail.define_constant("U2GF", cv::cuda::device::color_detail::U2GF);

  rb_mCvCudaDeviceColorDetail.define_constant("V2GF", cv::cuda::device::color_detail::V2GF);

  rb_mCvCudaDeviceColorDetail.define_constant("V2RF", cv::cuda::device::color_detail::V2RF);

  rb_mCvCudaDeviceColorDetail.define_constant("U2BI", cv::cuda::device::color_detail::U2BI);

  rb_mCvCudaDeviceColorDetail.define_constant("U2GI", cv::cuda::device::color_detail::U2GI);

  rb_mCvCudaDeviceColorDetail.define_constant("V2GI", cv::cuda::device::color_detail::V2GI);

  rb_mCvCudaDeviceColorDetail.define_constant("V2RI", cv::cuda::device::color_detail::V2RI);

  rb_mCvCudaDeviceColorDetail.define_constant("CB2BF", cv::cuda::device::color_detail::CB2BF);

  rb_mCvCudaDeviceColorDetail.define_constant("CB2GF", cv::cuda::device::color_detail::CB2GF);

  rb_mCvCudaDeviceColorDetail.define_constant("CR2GF", cv::cuda::device::color_detail::CR2GF);

  rb_mCvCudaDeviceColorDetail.define_constant("CR2RF", cv::cuda::device::color_detail::CR2RF);

  rb_mCvCudaDeviceColorDetail.define_constant("CB2BI", cv::cuda::device::color_detail::CB2BI);

  rb_mCvCudaDeviceColorDetail.define_constant("CB2GI", cv::cuda::device::color_detail::CB2GI);

  rb_mCvCudaDeviceColorDetail.define_constant("CR2GI", cv::cuda::device::color_detail::CR2GI);

  rb_mCvCudaDeviceColorDetail.define_constant("CR2RI", cv::cuda::device::color_detail::CR2RI);

  rb_mCvCudaDeviceColorDetail.define_constant("Yuv_shift", (int)cv::cuda::device::color_detail::yuv_shift);
  rb_mCvCudaDeviceColorDetail.define_constant("Xyz_shift", (int)cv::cuda::device::color_detail::xyz_shift);
  rb_mCvCudaDeviceColorDetail.define_constant("Gray_shift", (int)cv::cuda::device::color_detail::gray_shift);
  rb_mCvCudaDeviceColorDetail.define_constant("R2Y", (int)cv::cuda::device::color_detail::R2Y);
  rb_mCvCudaDeviceColorDetail.define_constant("G2Y", (int)cv::cuda::device::color_detail::G2Y);
  rb_mCvCudaDeviceColorDetail.define_constant("B2Y", (int)cv::cuda::device::color_detail::B2Y);
  rb_mCvCudaDeviceColorDetail.define_constant("RY15", (int)cv::cuda::device::color_detail::RY15);
  rb_mCvCudaDeviceColorDetail.define_constant("GY15", (int)cv::cuda::device::color_detail::GY15);
  rb_mCvCudaDeviceColorDetail.define_constant("BY15", (int)cv::cuda::device::color_detail::BY15);
  rb_mCvCudaDeviceColorDetail.define_constant("BLOCK_SIZE", (int)cv::cuda::device::color_detail::BLOCK_SIZE);

  Rice::Data_Type<cv::cuda::device::unary_function<unsigned int, unsigned int>> rb_cUnaryFunctionUnsignedIntUnsignedInt = define_class_under<cv::cuda::device::unary_function<unsigned int, unsigned int>>(rb_mCvCudaDeviceColorDetail, "UnaryFunctionUnsignedIntUnsignedInt").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<unsigned int, unsigned int>>, unsigned int, unsigned int>);
  Rice::Data_Type<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>> rb_cCvCudaDeviceColorDetailRGB2RGBUchar442 = define_class_under<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>, cv::cuda::device::unary_function<unsigned int, unsigned int>>(rb_mCvCudaDeviceColorDetail, "RGB2RGBUchar442").
    define_method<uint(cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>::*)(uint) const>("call", &cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>, const cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::unary_function<unsigned char, unsigned int>> rb_cUnaryFunctionUnsignedCharUnsignedInt = define_class_under<cv::cuda::device::unary_function<unsigned char, unsigned int>>(rb_mCvCudaDeviceColorDetail, "UnaryFunctionUnsignedCharUnsignedInt").
    define(&unary_function_builder<Data_Type<cv::cuda::device::unary_function<unsigned char, unsigned int>>, unsigned char, unsigned int>);
  Rice::Data_Type<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>> rb_cCvCudaDeviceColorDetailGray2RGBUchar4 = define_class_under<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>, cv::cuda::device::unary_function<unsigned char, unsigned int>>(rb_mCvCudaDeviceColorDetail, "Gray2RGBUchar4").
    define_method<uint(cv::cuda::device::color_detail::Gray2RGB<uchar, 4>::*)(uint) const>("call", &cv::cuda::device::color_detail::Gray2RGB<uchar, 4>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>, const cv::cuda::device::color_detail::Gray2RGB<uchar, 4>&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>> rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter6 = define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>>(rb_mCvCudaDeviceColorDetail, "Gray2RGB5x5Converter6").
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>>()).
    define_singleton_function<ushort(*)(uint)>("cvt", &cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>::cvt,
      Arg("t"));

  Rice::Data_Type<cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>> rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter5 = define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>>(rb_mCvCudaDeviceColorDetail, "Gray2RGB5x5Converter5").
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>>()).
    define_singleton_function<ushort(*)(uint)>("cvt", &cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>::cvt,
      Arg("t"));

  Rice::Data_Type<cv::cuda::device::color_detail::RGB5x52GrayConverter<6>> rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter6 = define_class_under<cv::cuda::device::color_detail::RGB5x52GrayConverter<6>>(rb_mCvCudaDeviceColorDetail, "RGB5x52GrayConverter6").
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52GrayConverter<6>>()).
    define_singleton_function<uchar(*)(uint)>("cvt", &cv::cuda::device::color_detail::RGB5x52GrayConverter<6>::cvt,
      Arg("t"));

  Rice::Data_Type<cv::cuda::device::color_detail::RGB5x52GrayConverter<5>> rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter5 = define_class_under<cv::cuda::device::color_detail::RGB5x52GrayConverter<5>>(rb_mCvCudaDeviceColorDetail, "RGB5x52GrayConverter5").
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52GrayConverter<5>>()).
    define_singleton_function<uchar(*)(uint)>("cvt", &cv::cuda::device::color_detail::RGB5x52GrayConverter<5>::cvt,
      Arg("t"));

  rb_mCvCudaDeviceColorDetail.define_constant("C_RGB2YUVCoeffs_f", cv::cuda::device::color_detail::c_RGB2YUVCoeffs_f);

  rb_mCvCudaDeviceColorDetail.define_constant("C_RGB2YUVCoeffs_i", cv::cuda::device::color_detail::c_RGB2YUVCoeffs_i);

  rb_mCvCudaDeviceColorDetail.define_constant("C_YUV2RGBCoeffs_f", cv::cuda::device::color_detail::c_YUV2RGBCoeffs_f);

  rb_mCvCudaDeviceColorDetail.define_constant("C_YUV2RGBCoeffs_i", cv::cuda::device::color_detail::c_YUV2RGBCoeffs_i);

  rb_mCvCudaDeviceColorDetail.define_constant("C_RGB2YCrCbCoeffs_f", cv::cuda::device::color_detail::c_RGB2YCrCbCoeffs_f);

  rb_mCvCudaDeviceColorDetail.define_constant("C_RGB2YCrCbCoeffs_i", cv::cuda::device::color_detail::c_RGB2YCrCbCoeffs_i);

  rb_mCvCudaDeviceColorDetail.define_constant("C_YCrCb2RGBCoeffs_f", cv::cuda::device::color_detail::c_YCrCb2RGBCoeffs_f);

  rb_mCvCudaDeviceColorDetail.define_constant("C_YCrCb2RGBCoeffs_i", cv::cuda::device::color_detail::c_YCrCb2RGBCoeffs_i);

  rb_mCvCudaDeviceColorDetail.define_constant("C_RGB2XYZ_D65f", cv::cuda::device::color_detail::c_RGB2XYZ_D65f);

  rb_mCvCudaDeviceColorDetail.define_constant("C_RGB2XYZ_D65i", cv::cuda::device::color_detail::c_RGB2XYZ_D65i);

  rb_mCvCudaDeviceColorDetail.define_constant("C_XYZ2sRGB_D65f", cv::cuda::device::color_detail::c_XYZ2sRGB_D65f);

  rb_mCvCudaDeviceColorDetail.define_constant("C_XYZ2sRGB_D65i", cv::cuda::device::color_detail::c_XYZ2sRGB_D65i);

  rb_mCvCudaDeviceColorDetail.define_constant("C_HsvDivTable", cv::cuda::device::color_detail::c_HsvDivTable);

  rb_mCvCudaDeviceColorDetail.define_constant("C_HsvDivTable180", cv::cuda::device::color_detail::c_HsvDivTable180);

  rb_mCvCudaDeviceColorDetail.define_constant("C_HsvDivTable256", cv::cuda::device::color_detail::c_HsvDivTable256);

  rb_mCvCudaDeviceColorDetail.define_constant("C_HsvSectorData", cv::cuda::device::color_detail::c_HsvSectorData);

  rb_mCvCudaDeviceColorDetail.define_constant("C_HlsSectorData", cv::cuda::device::color_detail::c_HlsSectorData);

  rb_mCvCudaDeviceColorDetail.define_constant("LAB_CBRT_TAB_SIZE", (int)cv::cuda::device::color_detail::LAB_CBRT_TAB_SIZE);
  rb_mCvCudaDeviceColorDetail.define_constant("GAMMA_TAB_SIZE", (int)cv::cuda::device::color_detail::GAMMA_TAB_SIZE);
  rb_mCvCudaDeviceColorDetail.define_constant("Lab_shift", (int)cv::cuda::device::color_detail::lab_shift);
  rb_mCvCudaDeviceColorDetail.define_constant("Gamma_shift", (int)cv::cuda::device::color_detail::gamma_shift);
  rb_mCvCudaDeviceColorDetail.define_constant("Lab_shift2", (int)cv::cuda::device::color_detail::lab_shift2);
  rb_mCvCudaDeviceColorDetail.define_constant("LAB_CBRT_TAB_SIZE_B", (int)cv::cuda::device::color_detail::LAB_CBRT_TAB_SIZE_B);

  rb_mCvCudaDeviceColorDetail.define_constant("C_sRGBGammaTab_b", cv::cuda::device::color_detail::c_sRGBGammaTab_b);

  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("lab_cbrt_b", &cv::cuda::device::color_detail::LabCbrt_b,
    Arg("i"));

  rb_mCvCudaDeviceColorDetail.define_module_function<float(*)(float, const float*, int)>("spline_interpolate", &cv::cuda::device::color_detail::splineInterpolate,
    Arg("x"), ArgBuffer("tab"), Arg("n"));

  rb_mCvCudaDeviceColorDetail.define_constant("C_sRGBGammaTab", cv::cuda::device::color_detail::c_sRGBGammaTab);

  rb_mCvCudaDeviceColorDetail.define_constant("C_sRGBInvGammaTab", cv::cuda::device::color_detail::c_sRGBInvGammaTab);

  rb_mCvCudaDeviceColorDetail.define_constant("C_LabCbrtTab", cv::cuda::device::color_detail::c_LabCbrtTab);
}