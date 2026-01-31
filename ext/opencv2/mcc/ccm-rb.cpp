#include <opencv2/mcc/ccm.hpp>
#include "ccm-rb.hpp"

using namespace Rice;

void Init_Mcc_Ccm()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCcm = define_module_under(rb_mCv, "Ccm");

  Enum<cv::ccm::CCM_TYPE> rb_cCvCcmCCMTYPE = define_enum_under<cv::ccm::CCM_TYPE>("CCM_TYPE", rb_mCvCcm).
    define_value("CCM_3x3", cv::ccm::CCM_TYPE::CCM_3x3).
    define_value("CCM_4x3", cv::ccm::CCM_TYPE::CCM_4x3);

  Enum<cv::ccm::INITIAL_METHOD_TYPE> rb_cCvCcmINITIALMETHODTYPE = define_enum_under<cv::ccm::INITIAL_METHOD_TYPE>("INITIAL_METHOD_TYPE", rb_mCvCcm).
    define_value("INITIAL_METHOD_WHITE_BALANCE", cv::ccm::INITIAL_METHOD_TYPE::INITIAL_METHOD_WHITE_BALANCE).
    define_value("INITIAL_METHOD_LEAST_SQUARE", cv::ccm::INITIAL_METHOD_TYPE::INITIAL_METHOD_LEAST_SQUARE);

  Enum<cv::ccm::CONST_COLOR> rb_cCvCcmCONSTCOLOR = define_enum_under<cv::ccm::CONST_COLOR>("CONST_COLOR", rb_mCvCcm).
    define_value("COLORCHECKER_Macbeth", cv::ccm::CONST_COLOR::COLORCHECKER_Macbeth).
    define_value("COLORCHECKER_Vinyl", cv::ccm::CONST_COLOR::COLORCHECKER_Vinyl).
    define_value("COLORCHECKER_DigitalSG", cv::ccm::CONST_COLOR::COLORCHECKER_DigitalSG);

  Enum<cv::ccm::COLOR_SPACE> rb_cCvCcmCOLORSPACE = define_enum_under<cv::ccm::COLOR_SPACE>("COLOR_SPACE", rb_mCvCcm).
    define_value("COLOR_SPACE_sRGB", cv::ccm::COLOR_SPACE::COLOR_SPACE_sRGB).
    define_value("COLOR_SPACE_sRGBL", cv::ccm::COLOR_SPACE::COLOR_SPACE_sRGBL).
    define_value("COLOR_SPACE_AdobeRGB", cv::ccm::COLOR_SPACE::COLOR_SPACE_AdobeRGB).
    define_value("COLOR_SPACE_AdobeRGBL", cv::ccm::COLOR_SPACE::COLOR_SPACE_AdobeRGBL).
    define_value("COLOR_SPACE_WideGamutRGB", cv::ccm::COLOR_SPACE::COLOR_SPACE_WideGamutRGB).
    define_value("COLOR_SPACE_WideGamutRGBL", cv::ccm::COLOR_SPACE::COLOR_SPACE_WideGamutRGBL).
    define_value("COLOR_SPACE_ProPhotoRGB", cv::ccm::COLOR_SPACE::COLOR_SPACE_ProPhotoRGB).
    define_value("COLOR_SPACE_ProPhotoRGBL", cv::ccm::COLOR_SPACE::COLOR_SPACE_ProPhotoRGBL).
    define_value("COLOR_SPACE_DCI_P3_RGB", cv::ccm::COLOR_SPACE::COLOR_SPACE_DCI_P3_RGB).
    define_value("COLOR_SPACE_DCI_P3_RGBL", cv::ccm::COLOR_SPACE::COLOR_SPACE_DCI_P3_RGBL).
    define_value("COLOR_SPACE_AppleRGB", cv::ccm::COLOR_SPACE::COLOR_SPACE_AppleRGB).
    define_value("COLOR_SPACE_AppleRGBL", cv::ccm::COLOR_SPACE::COLOR_SPACE_AppleRGBL).
    define_value("COLOR_SPACE_REC_709_RGB", cv::ccm::COLOR_SPACE::COLOR_SPACE_REC_709_RGB).
    define_value("COLOR_SPACE_REC_709_RGBL", cv::ccm::COLOR_SPACE::COLOR_SPACE_REC_709_RGBL).
    define_value("COLOR_SPACE_REC_2020_RGB", cv::ccm::COLOR_SPACE::COLOR_SPACE_REC_2020_RGB).
    define_value("COLOR_SPACE_REC_2020_RGBL", cv::ccm::COLOR_SPACE::COLOR_SPACE_REC_2020_RGBL).
    define_value("COLOR_SPACE_XYZ_D65_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_D65_2).
    define_value("COLOR_SPACE_XYZ_D65_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_D65_10).
    define_value("COLOR_SPACE_XYZ_D50_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_D50_2).
    define_value("COLOR_SPACE_XYZ_D50_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_D50_10).
    define_value("COLOR_SPACE_XYZ_A_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_A_2).
    define_value("COLOR_SPACE_XYZ_A_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_A_10).
    define_value("COLOR_SPACE_XYZ_D55_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_D55_2).
    define_value("COLOR_SPACE_XYZ_D55_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_D55_10).
    define_value("COLOR_SPACE_XYZ_D75_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_D75_2).
    define_value("COLOR_SPACE_XYZ_D75_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_D75_10).
    define_value("COLOR_SPACE_XYZ_E_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_E_2).
    define_value("COLOR_SPACE_XYZ_E_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_XYZ_E_10).
    define_value("COLOR_SPACE_Lab_D65_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_D65_2).
    define_value("COLOR_SPACE_Lab_D65_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_D65_10).
    define_value("COLOR_SPACE_Lab_D50_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_D50_2).
    define_value("COLOR_SPACE_Lab_D50_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_D50_10).
    define_value("COLOR_SPACE_Lab_A_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_A_2).
    define_value("COLOR_SPACE_Lab_A_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_A_10).
    define_value("COLOR_SPACE_Lab_D55_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_D55_2).
    define_value("COLOR_SPACE_Lab_D55_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_D55_10).
    define_value("COLOR_SPACE_Lab_D75_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_D75_2).
    define_value("COLOR_SPACE_Lab_D75_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_D75_10).
    define_value("COLOR_SPACE_Lab_E_2", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_E_2).
    define_value("COLOR_SPACE_Lab_E_10", cv::ccm::COLOR_SPACE::COLOR_SPACE_Lab_E_10);

  Enum<cv::ccm::LINEAR_TYPE> rb_cCvCcmLINEARTYPE = define_enum_under<cv::ccm::LINEAR_TYPE>("LINEAR_TYPE", rb_mCvCcm).
    define_value("LINEARIZATION_IDENTITY", cv::ccm::LINEAR_TYPE::LINEARIZATION_IDENTITY).
    define_value("LINEARIZATION_GAMMA", cv::ccm::LINEAR_TYPE::LINEARIZATION_GAMMA).
    define_value("LINEARIZATION_COLORPOLYFIT", cv::ccm::LINEAR_TYPE::LINEARIZATION_COLORPOLYFIT).
    define_value("LINEARIZATION_COLORLOGPOLYFIT", cv::ccm::LINEAR_TYPE::LINEARIZATION_COLORLOGPOLYFIT).
    define_value("LINEARIZATION_GRAYPOLYFIT", cv::ccm::LINEAR_TYPE::LINEARIZATION_GRAYPOLYFIT).
    define_value("LINEARIZATION_GRAYLOGPOLYFIT", cv::ccm::LINEAR_TYPE::LINEARIZATION_GRAYLOGPOLYFIT);

  Enum<cv::ccm::DISTANCE_TYPE> rb_cCvCcmDISTANCETYPE = define_enum_under<cv::ccm::DISTANCE_TYPE>("DISTANCE_TYPE", rb_mCvCcm).
    define_value("DISTANCE_CIE76", cv::ccm::DISTANCE_TYPE::DISTANCE_CIE76).
    define_value("DISTANCE_CIE94_GRAPHIC_ARTS", cv::ccm::DISTANCE_TYPE::DISTANCE_CIE94_GRAPHIC_ARTS).
    define_value("DISTANCE_CIE94_TEXTILES", cv::ccm::DISTANCE_TYPE::DISTANCE_CIE94_TEXTILES).
    define_value("DISTANCE_CIE2000", cv::ccm::DISTANCE_TYPE::DISTANCE_CIE2000).
    define_value("DISTANCE_CMC_1TO1", cv::ccm::DISTANCE_TYPE::DISTANCE_CMC_1TO1).
    define_value("DISTANCE_CMC_2TO1", cv::ccm::DISTANCE_TYPE::DISTANCE_CMC_2TO1).
    define_value("DISTANCE_RGB", cv::ccm::DISTANCE_TYPE::DISTANCE_RGB).
    define_value("DISTANCE_RGBL", cv::ccm::DISTANCE_TYPE::DISTANCE_RGBL);

  Rice::Data_Type<cv::ccm::ColorCorrectionModel> rb_cCvCcmColorCorrectionModel = define_class_under<cv::ccm::ColorCorrectionModel>(rb_mCvCcm, "ColorCorrectionModel");

  Rice::Data_Type<cv::ccm::ColorCorrectionModel::Impl> rb_cCvCcmColorCorrectionModelImpl = define_class_under<cv::ccm::ColorCorrectionModel::Impl>(rb_cCvCcmColorCorrectionModel, "Impl");

  rb_cCvCcmColorCorrectionModel.
    define_constructor(Constructor<cv::ccm::ColorCorrectionModel, const cv::Mat&, cv::ccm::CONST_COLOR>(),
      Arg("src"), Arg("constcolor")).
    define_constructor(Constructor<cv::ccm::ColorCorrectionModel, const cv::Mat&, cv::Mat, cv::ccm::COLOR_SPACE>(),
      Arg("src"), Arg("colors"), Arg("ref_cs")).
    define_constructor(Constructor<cv::ccm::ColorCorrectionModel, const cv::Mat&, cv::Mat, cv::ccm::COLOR_SPACE, cv::Mat>(),
      Arg("src"), Arg("colors"), Arg("ref_cs"), Arg("colored")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(cv::ccm::COLOR_SPACE)>("set_color_space", &cv::ccm::ColorCorrectionModel::setColorSpace,
      Arg("cs")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(cv::ccm::CCM_TYPE)>("set_ccm_type", &cv::ccm::ColorCorrectionModel::setCCM_TYPE,
      Arg("ccm_type")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(cv::ccm::DISTANCE_TYPE)>("set_distance", &cv::ccm::ColorCorrectionModel::setDistance,
      Arg("distance")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(cv::ccm::LINEAR_TYPE)>("set_linear", &cv::ccm::ColorCorrectionModel::setLinear,
      Arg("linear_type")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(const double&)>("set_linear_gamma", &cv::ccm::ColorCorrectionModel::setLinearGamma,
      Arg("gamma")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(const int&)>("set_linear_degree", &cv::ccm::ColorCorrectionModel::setLinearDegree,
      Arg("deg")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(const double&, const double&)>("set_saturated_threshold", &cv::ccm::ColorCorrectionModel::setSaturatedThreshold,
      Arg("lower"), Arg("upper")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(const cv::Mat&)>("set_weights_list", &cv::ccm::ColorCorrectionModel::setWeightsList,
      Arg("weights_list")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(const double&)>("set_weight_coeff", &cv::ccm::ColorCorrectionModel::setWeightCoeff,
      Arg("weights_coeff")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(cv::ccm::INITIAL_METHOD_TYPE)>("set_initial_method", &cv::ccm::ColorCorrectionModel::setInitialMethod,
      Arg("initial_method_type")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(const int&)>("set_max_count", &cv::ccm::ColorCorrectionModel::setMaxCount,
      Arg("max_count")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)(const double&)>("set_epsilon", &cv::ccm::ColorCorrectionModel::setEpsilon,
      Arg("epsilon")).
    define_method<void(cv::ccm::ColorCorrectionModel::*)()>("run", &cv::ccm::ColorCorrectionModel::run).
    define_method<cv::Mat(cv::ccm::ColorCorrectionModel::*)() const>("get_ccm", &cv::ccm::ColorCorrectionModel::getCCM).
    define_method<double(cv::ccm::ColorCorrectionModel::*)() const>("get_loss", &cv::ccm::ColorCorrectionModel::getLoss).
    define_method<cv::Mat(cv::ccm::ColorCorrectionModel::*)() const>("get_src_rgbl", &cv::ccm::ColorCorrectionModel::get_src_rgbl).
    define_method<cv::Mat(cv::ccm::ColorCorrectionModel::*)() const>("get_dst_rgbl", &cv::ccm::ColorCorrectionModel::get_dst_rgbl).
    define_method<cv::Mat(cv::ccm::ColorCorrectionModel::*)() const>("get_mask", &cv::ccm::ColorCorrectionModel::getMask).
    define_method<cv::Mat(cv::ccm::ColorCorrectionModel::*)() const>("get_weights", &cv::ccm::ColorCorrectionModel::getWeights).
    define_method<cv::Mat(cv::ccm::ColorCorrectionModel::*)(const cv::Mat&, bool)>("infer", &cv::ccm::ColorCorrectionModel::infer,
      Arg("img"), Arg("islinear") = static_cast<bool>(false));
}