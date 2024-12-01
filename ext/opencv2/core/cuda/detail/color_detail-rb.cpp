#include <opencv2/core/cuda/detail/color_detail.hpp>
#include "color_detail-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaDeviceColorDetailColorChannelFloat;
Rice::Class rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter5;
Rice::Class rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter6;
Rice::Class rb_cCvCudaDeviceColorDetailGray2RGBUchar4;
Rice::Class rb_cCvCudaDeviceColorDetailRGB2RGBUchar442;
Rice::Class rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter5;
Rice::Class rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter6;

template<typename Data_Type_T, typename T>
inline void ColorChannel_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method("call", &cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_attr("__device__", &cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::__device__);
};

template<typename Data_Type_T, typename T, int dcn>
inline void Gray2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::Gray2RGB<T, dcn>::__forceinline__);
};

template<typename Data_Type_T, int green_bits>
inline void Gray2RGB5x5_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>::__forceinline__);
};

template<typename Data_Type_T, int green_bits>
inline void RGB5x52Gray_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB5x52Gray<green_bits>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int bidx>
inline void RGB2Gray_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2YUV_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void YUV2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2YCrCb_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void YCrCb2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2XYZ_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void XYZ2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void RGB2HSV_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void HSV2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void RGB2HLS_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void HLS2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>::__forceinline__);
};
void Init_ColorDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceColorDetail = define_module_under(rb_mCvCudaDevice, "ColorDetail");
  
  rb_cCvCudaDeviceColorDetailColorChannelFloat = define_class_under<cv::cuda::device::color_detail::ColorChannel<float>>(rb_mCvCudaDeviceColorDetail, "ColorChannelFloat").
    define_constructor(Constructor<cv::cuda::device::color_detail::ColorChannel<float>>());
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(int&, int)>("set_alpha", &cv::cuda::device::color_detail::setAlpha,
    Arg("vec"), Arg("val"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(int&, int)>("set_alpha", &cv::cuda::device::color_detail::setAlpha,
    Arg("vec"), Arg("val"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(const int&)>("get_alpha", &cv::cuda::device::color_detail::getAlpha,
    Arg("vec"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(const int&)>("get_alpha", &cv::cuda::device::color_detail::getAlpha,
    Arg("vec"));
  
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
  
  rb_cCvCudaDeviceColorDetailRGB2RGBUchar442 = define_class_under<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>>(rb_mCvCudaDeviceColorDetail, "RGB2RGBUchar442").
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>>()).
    define_attr("uint", &cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>::uint);
  
  
  
  rb_cCvCudaDeviceColorDetailGray2RGBUchar4 = define_class_under<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>>(rb_mCvCudaDeviceColorDetail, "Gray2RGBUchar4").
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>>()).
    define_attr("__forceinline__", &cv::cuda::device::color_detail::Gray2RGB<uchar, 4>::__forceinline__);
  
  rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter6 = define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>>(rb_mCvCudaDeviceColorDetail, "Gray2RGB5x5Converter6").
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>>());
  
  rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter5 = define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>>(rb_mCvCudaDeviceColorDetail, "Gray2RGB5x5Converter5").
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>>());
  
  rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter6 = define_class_under<cv::cuda::device::color_detail::RGB5x52GrayConverter<6>>(rb_mCvCudaDeviceColorDetail, "RGB5x52GrayConverter6").
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52GrayConverter<6>>());
  
  rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter5 = define_class_under<cv::cuda::device::color_detail::RGB5x52GrayConverter<5>>(rb_mCvCudaDeviceColorDetail, "RGB5x52GrayConverter5").
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52GrayConverter<5>>());
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(const int*)>("rgb2_gray_convert", &cv::cuda::device::color_detail::RGB2GrayConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<uchar(*)(uint)>("rgb2_gray_convert", &cv::cuda::device::color_detail::RGB2GrayConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<float(*)(const float*)>("rgb2_gray_convert", &cv::cuda::device::color_detail::RGB2GrayConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CRGB2YUVCoeffsF", &cv::cuda::device::color_detail::c_RGB2YUVCoeffs_f);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CRGB2YUVCoeffsI", &cv::cuda::device::color_detail::c_RGB2YUVCoeffs_i);
  
  rb_mCvCudaDeviceColorDetail.define_module_function("rgb2_yuv_convert", &cv::cuda::device::color_detail::RGB2YUVConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CYUV2RGBCoeffsF", &cv::cuda::device::color_detail::c_YUV2RGBCoeffs_f);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CYUV2RGBCoeffsI", &cv::cuda::device::color_detail::c_YUV2RGBCoeffs_i);
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("yuv2_rgb_convert", &cv::cuda::device::color_detail::YUV2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, float*)>("yuv2_rgb_convert", &cv::cuda::device::color_detail::YUV2RGBConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CRGB2YCrCbCoeffsF", &cv::cuda::device::color_detail::c_RGB2YCrCbCoeffs_f);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CRGB2YCrCbCoeffsI", &cv::cuda::device::color_detail::c_RGB2YCrCbCoeffs_i);
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("rgb2_y_cr_cb_convert", &cv::cuda::device::color_detail::RGB2YCrCbConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const float*, int&)>("rgb2_y_cr_cb_convert", &cv::cuda::device::color_detail::RGB2YCrCbConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CYCrCb2RGBCoeffsF", &cv::cuda::device::color_detail::c_YCrCb2RGBCoeffs_f);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CYCrCb2RGBCoeffsI", &cv::cuda::device::color_detail::c_YCrCb2RGBCoeffs_i);
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("y_cr_cb2_rgb_convert", &cv::cuda::device::color_detail::YCrCb2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, float*)>("y_cr_cb2_rgb_convert", &cv::cuda::device::color_detail::YCrCb2RGBConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CRGB2XYZD65f", &cv::cuda::device::color_detail::c_RGB2XYZ_D65f);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CRGB2XYZD65i", &cv::cuda::device::color_detail::c_RGB2XYZ_D65i);
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int*, int&)>("rgb2_xyz_convert", &cv::cuda::device::color_detail::RGB2XYZConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("rgb2_xyz_convert", &cv::cuda::device::color_detail::RGB2XYZConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const float*, int&)>("rgb2_xyz_convert", &cv::cuda::device::color_detail::RGB2XYZConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CXYZ2sRGBD65f", &cv::cuda::device::color_detail::c_XYZ2sRGB_D65f);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CXYZ2sRGBD65i", &cv::cuda::device::color_detail::c_XYZ2sRGB_D65i);
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int*)>("xyz2_rgb_convert", &cv::cuda::device::color_detail::XYZ2RGBConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("xyz2_rgb_convert", &cv::cuda::device::color_detail::XYZ2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, float*)>("xyz2_rgb_convert", &cv::cuda::device::color_detail::XYZ2RGBConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CHsvDivTable", &cv::cuda::device::color_detail::c_HsvDivTable);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CHsvDivTable180", &cv::cuda::device::color_detail::c_HsvDivTable180);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CHsvDivTable256", &cv::cuda::device::color_detail::c_HsvDivTable256);
  
  rb_mCvCudaDeviceColorDetail.define_module_function("rgb2_hsv_convert", &cv::cuda::device::color_detail::RGB2HSVConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CHsvSectorData", &cv::cuda::device::color_detail::c_HsvSectorData);
  
  rb_mCvCudaDeviceColorDetail.define_module_function("hsv2_rgb_convert", &cv::cuda::device::color_detail::HSV2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function("rgb2_hls_convert", &cv::cuda::device::color_detail::RGB2HLSConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CHlsSectorData", &cv::cuda::device::color_detail::c_HlsSectorData);
  
  rb_mCvCudaDeviceColorDetail.define_module_function("hls2_rgb_convert", &cv::cuda::device::color_detail::HLS2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_constant("LAB_CBRT_TAB_SIZE", (int)cv::cuda::device::color_detail::LAB_CBRT_TAB_SIZE);
  rb_mCvCudaDeviceColorDetail.define_constant("GAMMA_TAB_SIZE", (int)cv::cuda::device::color_detail::GAMMA_TAB_SIZE);
  rb_mCvCudaDeviceColorDetail.define_constant("Lab_shift", (int)cv::cuda::device::color_detail::lab_shift);
  rb_mCvCudaDeviceColorDetail.define_constant("Gamma_shift", (int)cv::cuda::device::color_detail::gamma_shift);
  rb_mCvCudaDeviceColorDetail.define_constant("Lab_shift2", (int)cv::cuda::device::color_detail::lab_shift2);
  rb_mCvCudaDeviceColorDetail.define_constant("LAB_CBRT_TAB_SIZE_B", (int)cv::cuda::device::color_detail::LAB_CBRT_TAB_SIZE_B);
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("Ushort", &cv::cuda::device::color_detail::ushort);
  
  rb_mCvCudaDeviceColorDetail.define_module_function("lab_cbrt_b", &cv::cuda::device::color_detail::LabCbrt_b,
    Arg("i"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function("rgb2_lab_convert_b", &cv::cuda::device::color_detail::RGB2LabConvert_b,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function("spline_interpolate", &cv::cuda::device::color_detail::splineInterpolate,
    Arg("x"), Arg("tab"), Arg("n"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CSRGBGammaTab", &cv::cuda::device::color_detail::c_sRGBGammaTab);
  
  rb_mCvCudaDeviceColorDetail.define_module_function("rgb2_lab_convert_f", &cv::cuda::device::color_detail::RGB2LabConvert_f,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CSRGBInvGammaTab", &cv::cuda::device::color_detail::c_sRGBInvGammaTab);
  
  rb_mCvCudaDeviceColorDetail.define_module_function("lab2_rgb_convert_f", &cv::cuda::device::color_detail::Lab2RGBConvert_f,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function("lab2_rgb_convert_b", &cv::cuda::device::color_detail::Lab2RGBConvert_b,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_singleton_attr("CLabCbrtTab", &cv::cuda::device::color_detail::c_LabCbrtTab);
  
  rb_mCvCudaDeviceColorDetail.define_module_function("rgb2_luv_convert_f", &cv::cuda::device::color_detail::RGB2LuvConvert_f,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function("rgb2_luv_convert_b", &cv::cuda::device::color_detail::RGB2LuvConvert_b,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function("luv2_rgb_convert_f", &cv::cuda::device::color_detail::Luv2RGBConvert_f,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function("luv2_rgb_convert_b", &cv::cuda::device::color_detail::Luv2RGBConvert_b,
    Arg("src"), Arg("dst"));

}