#include <opencv2/cudev/functional/color_cvt.hpp>
#include "color_cvt-rb.hpp"

using namespace Rice;

void Init_Cudev_Functional_ColorCvt()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 2, 360>> rb_cRGB2HSVFloat332360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 2, 360>>(rb_mCvCudev, "RGB2HSVFloat332360").
    define(&RGB2HSV_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 2, 360>>, float, 3, 3, 2, 360>);
  Rice::Data_Type<cv::cudev::RGB_to_HSV_func<float>> rb_cCvCudevRGBToHSVFuncFloat = define_class_under<cv::cudev::RGB_to_HSV_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 2, 360>>(rb_mCvCudev, "RGBToHSVFuncFloat").
    define_constructor(Constructor<cv::cudev::RGB_to_HSV_func<float>>());

  Rice::Data_Type<cv::cudev::RGB_to_HSV_FULL_func<float>> rb_cCvCudevRGBToHSVFULLFuncFloat = define_class_under<cv::cudev::RGB_to_HSV_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 2, 360>>(rb_mCvCudev, "RGBToHSVFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::RGB_to_HSV_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 2, 360>> rb_cRGB2HSVFloat432360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 2, 360>>(rb_mCvCudev, "RGB2HSVFloat432360").
    define(&RGB2HSV_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 2, 360>>, float, 4, 3, 2, 360>);
  Rice::Data_Type<cv::cudev::RGBA_to_HSV_func<float>> rb_cCvCudevRGBAToHSVFuncFloat = define_class_under<cv::cudev::RGBA_to_HSV_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 2, 360>>(rb_mCvCudev, "RGBAToHSVFuncFloat").
    define_constructor(Constructor<cv::cudev::RGBA_to_HSV_func<float>>());

  Rice::Data_Type<cv::cudev::RGBA_to_HSV_FULL_func<float>> rb_cCvCudevRGBAToHSVFULLFuncFloat = define_class_under<cv::cudev::RGBA_to_HSV_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 2, 360>>(rb_mCvCudev, "RGBAToHSVFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::RGBA_to_HSV_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 2, 360>> rb_cRGB2HSVFloat342360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 2, 360>>(rb_mCvCudev, "RGB2HSVFloat342360").
    define(&RGB2HSV_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 2, 360>>, float, 3, 4, 2, 360>);
  Rice::Data_Type<cv::cudev::RGB_to_HSV4_func<float>> rb_cCvCudevRGBToHSV4FuncFloat = define_class_under<cv::cudev::RGB_to_HSV4_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 2, 360>>(rb_mCvCudev, "RGBToHSV4FuncFloat").
    define_constructor(Constructor<cv::cudev::RGB_to_HSV4_func<float>>());

  Rice::Data_Type<cv::cudev::RGB_to_HSV4_FULL_func<float>> rb_cCvCudevRGBToHSV4FULLFuncFloat = define_class_under<cv::cudev::RGB_to_HSV4_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 2, 360>>(rb_mCvCudev, "RGBToHSV4FULLFuncFloat").
    define_constructor(Constructor<cv::cudev::RGB_to_HSV4_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 2, 360>> rb_cRGB2HSVFloat442360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 2, 360>>(rb_mCvCudev, "RGB2HSVFloat442360").
    define(&RGB2HSV_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 2, 360>>, float, 4, 4, 2, 360>);
  Rice::Data_Type<cv::cudev::RGBA_to_HSV4_func<float>> rb_cCvCudevRGBAToHSV4FuncFloat = define_class_under<cv::cudev::RGBA_to_HSV4_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 2, 360>>(rb_mCvCudev, "RGBAToHSV4FuncFloat").
    define_constructor(Constructor<cv::cudev::RGBA_to_HSV4_func<float>>());

  Rice::Data_Type<cv::cudev::RGBA_to_HSV4_FULL_func<float>> rb_cCvCudevRGBAToHSV4FULLFuncFloat = define_class_under<cv::cudev::RGBA_to_HSV4_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 2, 360>>(rb_mCvCudev, "RGBAToHSV4FULLFuncFloat").
    define_constructor(Constructor<cv::cudev::RGBA_to_HSV4_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 0, 360>> rb_cRGB2HSVFloat330360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 0, 360>>(rb_mCvCudev, "RGB2HSVFloat330360").
    define(&RGB2HSV_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 0, 360>>, float, 3, 3, 0, 360>);
  Rice::Data_Type<cv::cudev::BGR_to_HSV_func<float>> rb_cCvCudevBGRToHSVFuncFloat = define_class_under<cv::cudev::BGR_to_HSV_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 0, 360>>(rb_mCvCudev, "BGRToHSVFuncFloat").
    define_constructor(Constructor<cv::cudev::BGR_to_HSV_func<float>>());

  Rice::Data_Type<cv::cudev::BGR_to_HSV_FULL_func<float>> rb_cCvCudevBGRToHSVFULLFuncFloat = define_class_under<cv::cudev::BGR_to_HSV_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 3, 0, 360>>(rb_mCvCudev, "BGRToHSVFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::BGR_to_HSV_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 0, 360>> rb_cRGB2HSVFloat430360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 0, 360>>(rb_mCvCudev, "RGB2HSVFloat430360").
    define(&RGB2HSV_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 0, 360>>, float, 4, 3, 0, 360>);
  Rice::Data_Type<cv::cudev::BGRA_to_HSV_func<float>> rb_cCvCudevBGRAToHSVFuncFloat = define_class_under<cv::cudev::BGRA_to_HSV_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 0, 360>>(rb_mCvCudev, "BGRAToHSVFuncFloat").
    define_constructor(Constructor<cv::cudev::BGRA_to_HSV_func<float>>());

  Rice::Data_Type<cv::cudev::BGRA_to_HSV_FULL_func<float>> rb_cCvCudevBGRAToHSVFULLFuncFloat = define_class_under<cv::cudev::BGRA_to_HSV_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 3, 0, 360>>(rb_mCvCudev, "BGRAToHSVFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::BGRA_to_HSV_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 0, 360>> rb_cRGB2HSVFloat340360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 0, 360>>(rb_mCvCudev, "RGB2HSVFloat340360").
    define(&RGB2HSV_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 0, 360>>, float, 3, 4, 0, 360>);
  Rice::Data_Type<cv::cudev::BGR_to_HSV4_func<float>> rb_cCvCudevBGRToHSV4FuncFloat = define_class_under<cv::cudev::BGR_to_HSV4_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 0, 360>>(rb_mCvCudev, "BGRToHSV4FuncFloat").
    define_constructor(Constructor<cv::cudev::BGR_to_HSV4_func<float>>());

  Rice::Data_Type<cv::cudev::BGR_to_HSV4_FULL_func<float>> rb_cCvCudevBGRToHSV4FULLFuncFloat = define_class_under<cv::cudev::BGR_to_HSV4_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 3, 4, 0, 360>>(rb_mCvCudev, "BGRToHSV4FULLFuncFloat").
    define_constructor(Constructor<cv::cudev::BGR_to_HSV4_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 0, 360>> rb_cRGB2HSVFloat440360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 0, 360>>(rb_mCvCudev, "RGB2HSVFloat440360").
    define(&RGB2HSV_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 0, 360>>, float, 4, 4, 0, 360>);
  Rice::Data_Type<cv::cudev::BGRA_to_HSV4_func<float>> rb_cCvCudevBGRAToHSV4FuncFloat = define_class_under<cv::cudev::BGRA_to_HSV4_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 0, 360>>(rb_mCvCudev, "BGRAToHSV4FuncFloat").
    define_constructor(Constructor<cv::cudev::BGRA_to_HSV4_func<float>>());

  Rice::Data_Type<cv::cudev::BGRA_to_HSV4_FULL_func<float>> rb_cCvCudevBGRAToHSV4FULLFuncFloat = define_class_under<cv::cudev::BGRA_to_HSV4_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HSV<float, 4, 4, 0, 360>>(rb_mCvCudev, "BGRAToHSV4FULLFuncFloat").
    define_constructor(Constructor<cv::cudev::BGRA_to_HSV4_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 2, 360>> rb_cHSV2RGBFloat332360 = define_class_under<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 2, 360>>(rb_mCvCudev, "HSV2RGBFloat332360").
    define(&HSV2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 2, 360>>, float, 3, 3, 2, 360>);
  Rice::Data_Type<cv::cudev::HSV_to_RGB_func<float>> rb_cCvCudevHSVToRGBFuncFloat = define_class_under<cv::cudev::HSV_to_RGB_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 2, 360>>(rb_mCvCudev, "HSVToRGBFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV_to_RGB_func<float>>());

  Rice::Data_Type<cv::cudev::HSV_to_RGB_FULL_func<float>> rb_cCvCudevHSVToRGBFULLFuncFloat = define_class_under<cv::cudev::HSV_to_RGB_FULL_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 2, 360>>(rb_mCvCudev, "HSVToRGBFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV_to_RGB_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 2, 360>> rb_cHSV2RGBFloat342360 = define_class_under<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 2, 360>>(rb_mCvCudev, "HSV2RGBFloat342360").
    define(&HSV2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 2, 360>>, float, 3, 4, 2, 360>);
  Rice::Data_Type<cv::cudev::HSV_to_RGBA_func<float>> rb_cCvCudevHSVToRGBAFuncFloat = define_class_under<cv::cudev::HSV_to_RGBA_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 2, 360>>(rb_mCvCudev, "HSVToRGBAFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV_to_RGBA_func<float>>());

  Rice::Data_Type<cv::cudev::HSV_to_RGBA_FULL_func<float>> rb_cCvCudevHSVToRGBAFULLFuncFloat = define_class_under<cv::cudev::HSV_to_RGBA_FULL_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 2, 360>>(rb_mCvCudev, "HSVToRGBAFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV_to_RGBA_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 2, 360>> rb_cHSV2RGBFloat432360 = define_class_under<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 2, 360>>(rb_mCvCudev, "HSV2RGBFloat432360").
    define(&HSV2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 2, 360>>, float, 4, 3, 2, 360>);
  Rice::Data_Type<cv::cudev::HSV4_to_RGB_func<float>> rb_cCvCudevHSV4ToRGBFuncFloat = define_class_under<cv::cudev::HSV4_to_RGB_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 2, 360>>(rb_mCvCudev, "HSV4ToRGBFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV4_to_RGB_func<float>>());

  Rice::Data_Type<cv::cudev::HSV4_to_RGB_FULL_func<float>> rb_cCvCudevHSV4ToRGBFULLFuncFloat = define_class_under<cv::cudev::HSV4_to_RGB_FULL_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 2, 360>>(rb_mCvCudev, "HSV4ToRGBFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV4_to_RGB_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 2, 360>> rb_cHSV2RGBFloat442360 = define_class_under<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 2, 360>>(rb_mCvCudev, "HSV2RGBFloat442360").
    define(&HSV2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 2, 360>>, float, 4, 4, 2, 360>);
  Rice::Data_Type<cv::cudev::HSV4_to_RGBA_func<float>> rb_cCvCudevHSV4ToRGBAFuncFloat = define_class_under<cv::cudev::HSV4_to_RGBA_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 2, 360>>(rb_mCvCudev, "HSV4ToRGBAFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV4_to_RGBA_func<float>>());

  Rice::Data_Type<cv::cudev::HSV4_to_RGBA_FULL_func<float>> rb_cCvCudevHSV4ToRGBAFULLFuncFloat = define_class_under<cv::cudev::HSV4_to_RGBA_FULL_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 2, 360>>(rb_mCvCudev, "HSV4ToRGBAFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV4_to_RGBA_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 0, 360>> rb_cHSV2RGBFloat330360 = define_class_under<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 0, 360>>(rb_mCvCudev, "HSV2RGBFloat330360").
    define(&HSV2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 0, 360>>, float, 3, 3, 0, 360>);
  Rice::Data_Type<cv::cudev::HSV_to_BGR_func<float>> rb_cCvCudevHSVToBGRFuncFloat = define_class_under<cv::cudev::HSV_to_BGR_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 0, 360>>(rb_mCvCudev, "HSVToBGRFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV_to_BGR_func<float>>());

  Rice::Data_Type<cv::cudev::HSV_to_BGR_FULL_func<float>> rb_cCvCudevHSVToBGRFULLFuncFloat = define_class_under<cv::cudev::HSV_to_BGR_FULL_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 3, 0, 360>>(rb_mCvCudev, "HSVToBGRFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV_to_BGR_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 0, 360>> rb_cHSV2RGBFloat340360 = define_class_under<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 0, 360>>(rb_mCvCudev, "HSV2RGBFloat340360").
    define(&HSV2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 0, 360>>, float, 3, 4, 0, 360>);
  Rice::Data_Type<cv::cudev::HSV_to_BGRA_func<float>> rb_cCvCudevHSVToBGRAFuncFloat = define_class_under<cv::cudev::HSV_to_BGRA_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 0, 360>>(rb_mCvCudev, "HSVToBGRAFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV_to_BGRA_func<float>>());

  Rice::Data_Type<cv::cudev::HSV_to_BGRA_FULL_func<float>> rb_cCvCudevHSVToBGRAFULLFuncFloat = define_class_under<cv::cudev::HSV_to_BGRA_FULL_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 3, 4, 0, 360>>(rb_mCvCudev, "HSVToBGRAFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV_to_BGRA_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 0, 360>> rb_cHSV2RGBFloat430360 = define_class_under<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 0, 360>>(rb_mCvCudev, "HSV2RGBFloat430360").
    define(&HSV2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 0, 360>>, float, 4, 3, 0, 360>);
  Rice::Data_Type<cv::cudev::HSV4_to_BGR_func<float>> rb_cCvCudevHSV4ToBGRFuncFloat = define_class_under<cv::cudev::HSV4_to_BGR_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 0, 360>>(rb_mCvCudev, "HSV4ToBGRFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV4_to_BGR_func<float>>());

  Rice::Data_Type<cv::cudev::HSV4_to_BGR_FULL_func<float>> rb_cCvCudevHSV4ToBGRFULLFuncFloat = define_class_under<cv::cudev::HSV4_to_BGR_FULL_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 3, 0, 360>>(rb_mCvCudev, "HSV4ToBGRFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV4_to_BGR_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 0, 360>> rb_cHSV2RGBFloat440360 = define_class_under<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 0, 360>>(rb_mCvCudev, "HSV2RGBFloat440360").
    define(&HSV2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 0, 360>>, float, 4, 4, 0, 360>);
  Rice::Data_Type<cv::cudev::HSV4_to_BGRA_func<float>> rb_cCvCudevHSV4ToBGRAFuncFloat = define_class_under<cv::cudev::HSV4_to_BGRA_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 0, 360>>(rb_mCvCudev, "HSV4ToBGRAFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV4_to_BGRA_func<float>>());

  Rice::Data_Type<cv::cudev::HSV4_to_BGRA_FULL_func<float>> rb_cCvCudevHSV4ToBGRAFULLFuncFloat = define_class_under<cv::cudev::HSV4_to_BGRA_FULL_func<float>, cv::cudev::color_cvt_detail::HSV2RGB<float, 4, 4, 0, 360>>(rb_mCvCudev, "HSV4ToBGRAFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HSV4_to_BGRA_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 2, 360>> rb_cRGB2HLSFloat332360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 2, 360>>(rb_mCvCudev, "RGB2HLSFloat332360").
    define(&RGB2HLS_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 2, 360>>, float, 3, 3, 2, 360>);
  Rice::Data_Type<cv::cudev::RGB_to_HLS_func<float>> rb_cCvCudevRGBToHLSFuncFloat = define_class_under<cv::cudev::RGB_to_HLS_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 2, 360>>(rb_mCvCudev, "RGBToHLSFuncFloat").
    define_constructor(Constructor<cv::cudev::RGB_to_HLS_func<float>>());

  Rice::Data_Type<cv::cudev::RGB_to_HLS_FULL_func<float>> rb_cCvCudevRGBToHLSFULLFuncFloat = define_class_under<cv::cudev::RGB_to_HLS_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 2, 360>>(rb_mCvCudev, "RGBToHLSFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::RGB_to_HLS_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 2, 360>> rb_cRGB2HLSFloat432360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 2, 360>>(rb_mCvCudev, "RGB2HLSFloat432360").
    define(&RGB2HLS_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 2, 360>>, float, 4, 3, 2, 360>);
  Rice::Data_Type<cv::cudev::RGBA_to_HLS_func<float>> rb_cCvCudevRGBAToHLSFuncFloat = define_class_under<cv::cudev::RGBA_to_HLS_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 2, 360>>(rb_mCvCudev, "RGBAToHLSFuncFloat").
    define_constructor(Constructor<cv::cudev::RGBA_to_HLS_func<float>>());

  Rice::Data_Type<cv::cudev::RGBA_to_HLS_FULL_func<float>> rb_cCvCudevRGBAToHLSFULLFuncFloat = define_class_under<cv::cudev::RGBA_to_HLS_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 2, 360>>(rb_mCvCudev, "RGBAToHLSFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::RGBA_to_HLS_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 2, 360>> rb_cRGB2HLSFloat342360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 2, 360>>(rb_mCvCudev, "RGB2HLSFloat342360").
    define(&RGB2HLS_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 2, 360>>, float, 3, 4, 2, 360>);
  Rice::Data_Type<cv::cudev::RGB_to_HLS4_func<float>> rb_cCvCudevRGBToHLS4FuncFloat = define_class_under<cv::cudev::RGB_to_HLS4_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 2, 360>>(rb_mCvCudev, "RGBToHLS4FuncFloat").
    define_constructor(Constructor<cv::cudev::RGB_to_HLS4_func<float>>());

  Rice::Data_Type<cv::cudev::RGB_to_HLS4_FULL_func<float>> rb_cCvCudevRGBToHLS4FULLFuncFloat = define_class_under<cv::cudev::RGB_to_HLS4_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 2, 360>>(rb_mCvCudev, "RGBToHLS4FULLFuncFloat").
    define_constructor(Constructor<cv::cudev::RGB_to_HLS4_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 2, 360>> rb_cRGB2HLSFloat442360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 2, 360>>(rb_mCvCudev, "RGB2HLSFloat442360").
    define(&RGB2HLS_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 2, 360>>, float, 4, 4, 2, 360>);
  Rice::Data_Type<cv::cudev::RGBA_to_HLS4_func<float>> rb_cCvCudevRGBAToHLS4FuncFloat = define_class_under<cv::cudev::RGBA_to_HLS4_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 2, 360>>(rb_mCvCudev, "RGBAToHLS4FuncFloat").
    define_constructor(Constructor<cv::cudev::RGBA_to_HLS4_func<float>>());

  Rice::Data_Type<cv::cudev::RGBA_to_HLS4_FULL_func<float>> rb_cCvCudevRGBAToHLS4FULLFuncFloat = define_class_under<cv::cudev::RGBA_to_HLS4_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 2, 360>>(rb_mCvCudev, "RGBAToHLS4FULLFuncFloat").
    define_constructor(Constructor<cv::cudev::RGBA_to_HLS4_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 0, 360>> rb_cRGB2HLSFloat330360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 0, 360>>(rb_mCvCudev, "RGB2HLSFloat330360").
    define(&RGB2HLS_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 0, 360>>, float, 3, 3, 0, 360>);
  Rice::Data_Type<cv::cudev::BGR_to_HLS_func<float>> rb_cCvCudevBGRToHLSFuncFloat = define_class_under<cv::cudev::BGR_to_HLS_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 0, 360>>(rb_mCvCudev, "BGRToHLSFuncFloat").
    define_constructor(Constructor<cv::cudev::BGR_to_HLS_func<float>>());

  Rice::Data_Type<cv::cudev::BGR_to_HLS_FULL_func<float>> rb_cCvCudevBGRToHLSFULLFuncFloat = define_class_under<cv::cudev::BGR_to_HLS_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 3, 0, 360>>(rb_mCvCudev, "BGRToHLSFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::BGR_to_HLS_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 0, 360>> rb_cRGB2HLSFloat430360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 0, 360>>(rb_mCvCudev, "RGB2HLSFloat430360").
    define(&RGB2HLS_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 0, 360>>, float, 4, 3, 0, 360>);
  Rice::Data_Type<cv::cudev::BGRA_to_HLS_func<float>> rb_cCvCudevBGRAToHLSFuncFloat = define_class_under<cv::cudev::BGRA_to_HLS_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 0, 360>>(rb_mCvCudev, "BGRAToHLSFuncFloat").
    define_constructor(Constructor<cv::cudev::BGRA_to_HLS_func<float>>());

  Rice::Data_Type<cv::cudev::BGRA_to_HLS_FULL_func<float>> rb_cCvCudevBGRAToHLSFULLFuncFloat = define_class_under<cv::cudev::BGRA_to_HLS_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 3, 0, 360>>(rb_mCvCudev, "BGRAToHLSFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::BGRA_to_HLS_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 0, 360>> rb_cRGB2HLSFloat340360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 0, 360>>(rb_mCvCudev, "RGB2HLSFloat340360").
    define(&RGB2HLS_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 0, 360>>, float, 3, 4, 0, 360>);
  Rice::Data_Type<cv::cudev::BGR_to_HLS4_func<float>> rb_cCvCudevBGRToHLS4FuncFloat = define_class_under<cv::cudev::BGR_to_HLS4_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 0, 360>>(rb_mCvCudev, "BGRToHLS4FuncFloat").
    define_constructor(Constructor<cv::cudev::BGR_to_HLS4_func<float>>());

  Rice::Data_Type<cv::cudev::BGR_to_HLS4_FULL_func<float>> rb_cCvCudevBGRToHLS4FULLFuncFloat = define_class_under<cv::cudev::BGR_to_HLS4_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 3, 4, 0, 360>>(rb_mCvCudev, "BGRToHLS4FULLFuncFloat").
    define_constructor(Constructor<cv::cudev::BGR_to_HLS4_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 0, 360>> rb_cRGB2HLSFloat440360 = define_class_under<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 0, 360>>(rb_mCvCudev, "RGB2HLSFloat440360").
    define(&RGB2HLS_builder<Data_Type<cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 0, 360>>, float, 4, 4, 0, 360>);
  Rice::Data_Type<cv::cudev::BGRA_to_HLS4_func<float>> rb_cCvCudevBGRAToHLS4FuncFloat = define_class_under<cv::cudev::BGRA_to_HLS4_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 0, 360>>(rb_mCvCudev, "BGRAToHLS4FuncFloat").
    define_constructor(Constructor<cv::cudev::BGRA_to_HLS4_func<float>>());

  Rice::Data_Type<cv::cudev::BGRA_to_HLS4_FULL_func<float>> rb_cCvCudevBGRAToHLS4FULLFuncFloat = define_class_under<cv::cudev::BGRA_to_HLS4_FULL_func<float>, cv::cudev::color_cvt_detail::RGB2HLS<float, 4, 4, 0, 360>>(rb_mCvCudev, "BGRAToHLS4FULLFuncFloat").
    define_constructor(Constructor<cv::cudev::BGRA_to_HLS4_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 2, 360>> rb_cHLS2RGBFloat332360 = define_class_under<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 2, 360>>(rb_mCvCudev, "HLS2RGBFloat332360").
    define(&HLS2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 2, 360>>, float, 3, 3, 2, 360>);
  Rice::Data_Type<cv::cudev::HLS_to_RGB_func<float>> rb_cCvCudevHLSToRGBFuncFloat = define_class_under<cv::cudev::HLS_to_RGB_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 2, 360>>(rb_mCvCudev, "HLSToRGBFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS_to_RGB_func<float>>());

  Rice::Data_Type<cv::cudev::HLS_to_RGB_FULL_func<float>> rb_cCvCudevHLSToRGBFULLFuncFloat = define_class_under<cv::cudev::HLS_to_RGB_FULL_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 2, 360>>(rb_mCvCudev, "HLSToRGBFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS_to_RGB_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 2, 360>> rb_cHLS2RGBFloat342360 = define_class_under<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 2, 360>>(rb_mCvCudev, "HLS2RGBFloat342360").
    define(&HLS2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 2, 360>>, float, 3, 4, 2, 360>);
  Rice::Data_Type<cv::cudev::HLS_to_RGBA_func<float>> rb_cCvCudevHLSToRGBAFuncFloat = define_class_under<cv::cudev::HLS_to_RGBA_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 2, 360>>(rb_mCvCudev, "HLSToRGBAFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS_to_RGBA_func<float>>());

  Rice::Data_Type<cv::cudev::HLS_to_RGBA_FULL_func<float>> rb_cCvCudevHLSToRGBAFULLFuncFloat = define_class_under<cv::cudev::HLS_to_RGBA_FULL_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 2, 360>>(rb_mCvCudev, "HLSToRGBAFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS_to_RGBA_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 2, 360>> rb_cHLS2RGBFloat432360 = define_class_under<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 2, 360>>(rb_mCvCudev, "HLS2RGBFloat432360").
    define(&HLS2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 2, 360>>, float, 4, 3, 2, 360>);
  Rice::Data_Type<cv::cudev::HLS4_to_RGB_func<float>> rb_cCvCudevHLS4ToRGBFuncFloat = define_class_under<cv::cudev::HLS4_to_RGB_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 2, 360>>(rb_mCvCudev, "HLS4ToRGBFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS4_to_RGB_func<float>>());

  Rice::Data_Type<cv::cudev::HLS4_to_RGB_FULL_func<float>> rb_cCvCudevHLS4ToRGBFULLFuncFloat = define_class_under<cv::cudev::HLS4_to_RGB_FULL_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 2, 360>>(rb_mCvCudev, "HLS4ToRGBFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS4_to_RGB_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 2, 360>> rb_cHLS2RGBFloat442360 = define_class_under<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 2, 360>>(rb_mCvCudev, "HLS2RGBFloat442360").
    define(&HLS2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 2, 360>>, float, 4, 4, 2, 360>);
  Rice::Data_Type<cv::cudev::HLS4_to_RGBA_func<float>> rb_cCvCudevHLS4ToRGBAFuncFloat = define_class_under<cv::cudev::HLS4_to_RGBA_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 2, 360>>(rb_mCvCudev, "HLS4ToRGBAFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS4_to_RGBA_func<float>>());

  Rice::Data_Type<cv::cudev::HLS4_to_RGBA_FULL_func<float>> rb_cCvCudevHLS4ToRGBAFULLFuncFloat = define_class_under<cv::cudev::HLS4_to_RGBA_FULL_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 2, 360>>(rb_mCvCudev, "HLS4ToRGBAFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS4_to_RGBA_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 0, 360>> rb_cHLS2RGBFloat330360 = define_class_under<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 0, 360>>(rb_mCvCudev, "HLS2RGBFloat330360").
    define(&HLS2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 0, 360>>, float, 3, 3, 0, 360>);
  Rice::Data_Type<cv::cudev::HLS_to_BGR_func<float>> rb_cCvCudevHLSToBGRFuncFloat = define_class_under<cv::cudev::HLS_to_BGR_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 0, 360>>(rb_mCvCudev, "HLSToBGRFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS_to_BGR_func<float>>());

  Rice::Data_Type<cv::cudev::HLS_to_BGR_FULL_func<float>> rb_cCvCudevHLSToBGRFULLFuncFloat = define_class_under<cv::cudev::HLS_to_BGR_FULL_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 3, 0, 360>>(rb_mCvCudev, "HLSToBGRFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS_to_BGR_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 0, 360>> rb_cHLS2RGBFloat340360 = define_class_under<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 0, 360>>(rb_mCvCudev, "HLS2RGBFloat340360").
    define(&HLS2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 0, 360>>, float, 3, 4, 0, 360>);
  Rice::Data_Type<cv::cudev::HLS_to_BGRA_func<float>> rb_cCvCudevHLSToBGRAFuncFloat = define_class_under<cv::cudev::HLS_to_BGRA_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 0, 360>>(rb_mCvCudev, "HLSToBGRAFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS_to_BGRA_func<float>>());

  Rice::Data_Type<cv::cudev::HLS_to_BGRA_FULL_func<float>> rb_cCvCudevHLSToBGRAFULLFuncFloat = define_class_under<cv::cudev::HLS_to_BGRA_FULL_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 3, 4, 0, 360>>(rb_mCvCudev, "HLSToBGRAFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS_to_BGRA_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 0, 360>> rb_cHLS2RGBFloat430360 = define_class_under<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 0, 360>>(rb_mCvCudev, "HLS2RGBFloat430360").
    define(&HLS2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 0, 360>>, float, 4, 3, 0, 360>);
  Rice::Data_Type<cv::cudev::HLS4_to_BGR_func<float>> rb_cCvCudevHLS4ToBGRFuncFloat = define_class_under<cv::cudev::HLS4_to_BGR_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 0, 360>>(rb_mCvCudev, "HLS4ToBGRFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS4_to_BGR_func<float>>());

  Rice::Data_Type<cv::cudev::HLS4_to_BGR_FULL_func<float>> rb_cCvCudevHLS4ToBGRFULLFuncFloat = define_class_under<cv::cudev::HLS4_to_BGR_FULL_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 3, 0, 360>>(rb_mCvCudev, "HLS4ToBGRFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS4_to_BGR_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 0, 360>> rb_cHLS2RGBFloat440360 = define_class_under<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 0, 360>>(rb_mCvCudev, "HLS2RGBFloat440360").
    define(&HLS2RGB_builder<Data_Type<cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 0, 360>>, float, 4, 4, 0, 360>);
  Rice::Data_Type<cv::cudev::HLS4_to_BGRA_func<float>> rb_cCvCudevHLS4ToBGRAFuncFloat = define_class_under<cv::cudev::HLS4_to_BGRA_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 0, 360>>(rb_mCvCudev, "HLS4ToBGRAFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS4_to_BGRA_func<float>>());

  Rice::Data_Type<cv::cudev::HLS4_to_BGRA_FULL_func<float>> rb_cCvCudevHLS4ToBGRAFULLFuncFloat = define_class_under<cv::cudev::HLS4_to_BGRA_FULL_func<float>, cv::cudev::color_cvt_detail::HLS2RGB<float, 4, 4, 0, 360>>(rb_mCvCudev, "HLS4ToBGRAFULLFuncFloat").
    define_constructor(Constructor<cv::cudev::HLS4_to_BGRA_FULL_func<float>>());

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB5x5<3, 0, 5>> rb_cBGRToBGR555Func = RGB2RGB5x5_instantiate<3, 0, 5>(rb_mCvCudev, "BGRToBGR555Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB5x5<3, 0, 6>> rb_cBGRToBGR565Func = RGB2RGB5x5_instantiate<3, 0, 6>(rb_mCvCudev, "BGRToBGR565Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB5x5<3, 2, 5>> rb_cRGBToBGR555Func = RGB2RGB5x5_instantiate<3, 2, 5>(rb_mCvCudev, "RGBToBGR555Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB5x5<3, 2, 6>> rb_cRGBToBGR565Func = RGB2RGB5x5_instantiate<3, 2, 6>(rb_mCvCudev, "RGBToBGR565Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB5x5<4, 0, 5>> rb_cBGRAToBGR555Func = RGB2RGB5x5_instantiate<4, 0, 5>(rb_mCvCudev, "BGRAToBGR555Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB5x5<4, 0, 6>> rb_cBGRAToBGR565Func = RGB2RGB5x5_instantiate<4, 0, 6>(rb_mCvCudev, "BGRAToBGR565Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB5x5<4, 2, 5>> rb_cRGBAToBGR555Func = RGB2RGB5x5_instantiate<4, 2, 5>(rb_mCvCudev, "RGBAToBGR555Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB2RGB5x5<4, 2, 6>> rb_cRGBAToBGR565Func = RGB2RGB5x5_instantiate<4, 2, 6>(rb_mCvCudev, "RGBAToBGR565Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52RGB<3, 2, 5>> rb_cBGR555ToRGBFunc = RGB5x52RGB_instantiate<3, 2, 5>(rb_mCvCudev, "BGR555ToRGBFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52RGB<3, 2, 6>> rb_cBGR565ToRGBFunc = RGB5x52RGB_instantiate<3, 2, 6>(rb_mCvCudev, "BGR565ToRGBFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52RGB<3, 0, 5>> rb_cBGR555ToBGRFunc = RGB5x52RGB_instantiate<3, 0, 5>(rb_mCvCudev, "BGR555ToBGRFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52RGB<3, 0, 6>> rb_cBGR565ToBGRFunc = RGB5x52RGB_instantiate<3, 0, 6>(rb_mCvCudev, "BGR565ToBGRFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52RGB<4, 2, 5>> rb_cBGR555ToRGBAFunc = RGB5x52RGB_instantiate<4, 2, 5>(rb_mCvCudev, "BGR555ToRGBAFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52RGB<4, 2, 6>> rb_cBGR565ToRGBAFunc = RGB5x52RGB_instantiate<4, 2, 6>(rb_mCvCudev, "BGR565ToRGBAFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52RGB<4, 0, 5>> rb_cBGR555ToBGRAFunc = RGB5x52RGB_instantiate<4, 0, 5>(rb_mCvCudev, "BGR555ToBGRAFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52RGB<4, 0, 6>> rb_cBGR565ToBGRAFunc = RGB5x52RGB_instantiate<4, 0, 6>(rb_mCvCudev, "BGR565ToBGRAFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::Gray2RGB5x5<5>> rb_cGRAYToBGR555Func = Gray2RGB5x5_instantiate<5>(rb_mCvCudev, "GRAYToBGR555Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::Gray2RGB5x5<6>> rb_cGRAYToBGR565Func = Gray2RGB5x5_instantiate<6>(rb_mCvCudev, "GRAYToBGR565Func");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52Gray<5>> rb_cBGR555ToGRAYFunc = RGB5x52Gray_instantiate<5>(rb_mCvCudev, "BGR555ToGRAYFunc");

  Rice::Data_Type<cv::cudev::color_cvt_detail::RGB5x52Gray<6>> rb_cBGR565ToGRAYFunc = RGB5x52Gray_instantiate<6>(rb_mCvCudev, "BGR565ToGRAYFunc");
}