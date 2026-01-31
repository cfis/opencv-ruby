#include <opencv2/photo.hpp>
#include "photo-rb.hpp"

using namespace Rice;

void Init_Photo()
{
  Module rb_mCv = define_module("Cv");

  rb_mCv.define_constant("INPAINT_NS", (int)cv::INPAINT_NS);
  rb_mCv.define_constant("INPAINT_TELEA", (int)cv::INPAINT_TELEA);

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double, int)>("inpaint", &cv::inpaint,
    Arg("src"), Arg("inpaint_mask"), Arg("dst"), Arg("inpaint_radius"), Arg("flags"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, int, int)>("fast_nl_means_denoising", &cv::fastNlMeansDenoising,
    Arg("src"), Arg("dst"), Arg("h") = static_cast<float>(3), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const std::vector<float>&, int, int, int)>("fast_nl_means_denoising", &cv::fastNlMeansDenoising,
    Arg("src"), Arg("dst"), Arg("h"), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21), Arg("norm_type") = static_cast<int>(cv::NORM_L2));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, float, int, int)>("fast_nl_means_denoising_colored", &cv::fastNlMeansDenoisingColored,
    Arg("src"), Arg("dst"), Arg("h") = static_cast<float>(3), Arg("h_color") = static_cast<float>(3), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, int, int, float, int, int)>("fast_nl_means_denoising_multi", &cv::fastNlMeansDenoisingMulti,
    Arg("src_imgs"), Arg("dst"), Arg("img_to_denoise_index"), Arg("temporal_window_size"), Arg("h") = static_cast<float>(3), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, int, int, const std::vector<float>&, int, int, int)>("fast_nl_means_denoising_multi", &cv::fastNlMeansDenoisingMulti,
    Arg("src_imgs"), Arg("dst"), Arg("img_to_denoise_index"), Arg("temporal_window_size"), Arg("h"), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21), Arg("norm_type") = static_cast<int>(cv::NORM_L2));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, int, int, float, float, int, int)>("fast_nl_means_denoising_colored_multi", &cv::fastNlMeansDenoisingColoredMulti,
    Arg("src_imgs"), Arg("dst"), Arg("img_to_denoise_index"), Arg("temporal_window_size"), Arg("h") = static_cast<float>(3), Arg("h_color") = static_cast<float>(3), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21));

  rb_mCv.define_module_function<void(*)(const std::vector<cv::Mat>&, cv::Mat&, double, int)>("denoise_tvl1", &cv::denoise_TVL1,
    Arg("observations"), Arg("result"), Arg("lambda") = static_cast<double>(1.0), Arg("niters") = static_cast<int>(30));

  rb_mCv.define_constant("LDR_SIZE", (int)cv::LDR_SIZE);

  Rice::Data_Type<cv::Tonemap> rb_cCvTonemap = define_class_under<cv::Tonemap, cv::Algorithm>(rb_mCv, "Tonemap").
    define_method<void(cv::Tonemap::*)(cv::InputArray, cv::OutputArray)>("process", &cv::Tonemap::process,
      Arg("src"), Arg("dst")).
    define_method<float(cv::Tonemap::*)() const>("get_gamma", &cv::Tonemap::getGamma).
    define_method<void(cv::Tonemap::*)(float)>("set_gamma", &cv::Tonemap::setGamma,
      Arg("gamma"));

  rb_mCv.define_module_function<cv::Ptr<cv::Tonemap>(*)(float)>("create_tonemap", &cv::createTonemap,
    Arg("gamma") = static_cast<float>(1.0f));

  Rice::Data_Type<cv::TonemapDrago> rb_cCvTonemapDrago = define_class_under<cv::TonemapDrago, cv::Tonemap>(rb_mCv, "TonemapDrago").
    define_method<float(cv::TonemapDrago::*)() const>("get_saturation", &cv::TonemapDrago::getSaturation).
    define_method<void(cv::TonemapDrago::*)(float)>("set_saturation", &cv::TonemapDrago::setSaturation,
      Arg("saturation")).
    define_method<float(cv::TonemapDrago::*)() const>("get_bias", &cv::TonemapDrago::getBias).
    define_method<void(cv::TonemapDrago::*)(float)>("set_bias", &cv::TonemapDrago::setBias,
      Arg("bias"));

  rb_mCv.define_module_function<cv::Ptr<cv::TonemapDrago>(*)(float, float, float)>("create_tonemap_drago", &cv::createTonemapDrago,
    Arg("gamma") = static_cast<float>(1.0f), Arg("saturation") = static_cast<float>(1.0f), Arg("bias") = static_cast<float>(0.85f));

  Rice::Data_Type<cv::TonemapReinhard> rb_cCvTonemapReinhard = define_class_under<cv::TonemapReinhard, cv::Tonemap>(rb_mCv, "TonemapReinhard").
    define_method<float(cv::TonemapReinhard::*)() const>("get_intensity", &cv::TonemapReinhard::getIntensity).
    define_method<void(cv::TonemapReinhard::*)(float)>("set_intensity", &cv::TonemapReinhard::setIntensity,
      Arg("intensity")).
    define_method<float(cv::TonemapReinhard::*)() const>("get_light_adaptation", &cv::TonemapReinhard::getLightAdaptation).
    define_method<void(cv::TonemapReinhard::*)(float)>("set_light_adaptation", &cv::TonemapReinhard::setLightAdaptation,
      Arg("light_adapt")).
    define_method<float(cv::TonemapReinhard::*)() const>("get_color_adaptation", &cv::TonemapReinhard::getColorAdaptation).
    define_method<void(cv::TonemapReinhard::*)(float)>("set_color_adaptation", &cv::TonemapReinhard::setColorAdaptation,
      Arg("color_adapt"));

  rb_mCv.define_module_function<cv::Ptr<cv::TonemapReinhard>(*)(float, float, float, float)>("create_tonemap_reinhard", &cv::createTonemapReinhard,
    Arg("gamma") = static_cast<float>(1.0f), Arg("intensity") = static_cast<float>(0.0f), Arg("light_adapt") = static_cast<float>(1.0f), Arg("color_adapt") = static_cast<float>(0.0f));

  Rice::Data_Type<cv::TonemapMantiuk> rb_cCvTonemapMantiuk = define_class_under<cv::TonemapMantiuk, cv::Tonemap>(rb_mCv, "TonemapMantiuk").
    define_method<float(cv::TonemapMantiuk::*)() const>("get_scale", &cv::TonemapMantiuk::getScale).
    define_method<void(cv::TonemapMantiuk::*)(float)>("set_scale", &cv::TonemapMantiuk::setScale,
      Arg("scale")).
    define_method<float(cv::TonemapMantiuk::*)() const>("get_saturation", &cv::TonemapMantiuk::getSaturation).
    define_method<void(cv::TonemapMantiuk::*)(float)>("set_saturation", &cv::TonemapMantiuk::setSaturation,
      Arg("saturation"));

  rb_mCv.define_module_function<cv::Ptr<cv::TonemapMantiuk>(*)(float, float, float)>("create_tonemap_mantiuk", &cv::createTonemapMantiuk,
    Arg("gamma") = static_cast<float>(1.0f), Arg("scale") = static_cast<float>(0.7f), Arg("saturation") = static_cast<float>(1.0f));

  Rice::Data_Type<cv::AlignExposures> rb_cCvAlignExposures = define_class_under<cv::AlignExposures, cv::Algorithm>(rb_mCv, "AlignExposures").
    define_method<void(cv::AlignExposures::*)(cv::InputArrayOfArrays, std::vector<cv::Mat>&, cv::InputArray, cv::InputArray)>("process", &cv::AlignExposures::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response"));

  Rice::Data_Type<cv::AlignMTB> rb_cCvAlignMTB = define_class_under<cv::AlignMTB, cv::AlignExposures>(rb_mCv, "AlignMTB").
    define_method<void(cv::AlignMTB::*)(cv::InputArrayOfArrays, std::vector<cv::Mat>&, cv::InputArray, cv::InputArray)>("process", &cv::AlignMTB::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response")).
    define_method<void(cv::AlignMTB::*)(cv::InputArrayOfArrays, std::vector<cv::Mat>&)>("process", &cv::AlignMTB::process,
      Arg("src"), Arg("dst")).
    define_method<cv::Point(cv::AlignMTB::*)(cv::InputArray, cv::InputArray)>("calculate_shift", &cv::AlignMTB::calculateShift,
      Arg("img0"), Arg("img1")).
    define_method<void(cv::AlignMTB::*)(cv::InputArray, cv::OutputArray, const cv::Point)>("shift_mat", &cv::AlignMTB::shiftMat,
      Arg("src"), Arg("dst"), Arg("shift")).
    define_method<void(cv::AlignMTB::*)(cv::InputArray, cv::OutputArray, cv::OutputArray)>("compute_bitmaps", &cv::AlignMTB::computeBitmaps,
      Arg("img"), Arg("tb"), Arg("eb")).
    define_method<int(cv::AlignMTB::*)() const>("get_max_bits", &cv::AlignMTB::getMaxBits).
    define_method<void(cv::AlignMTB::*)(int)>("set_max_bits", &cv::AlignMTB::setMaxBits,
      Arg("max_bits")).
    define_method<int(cv::AlignMTB::*)() const>("get_exclude_range", &cv::AlignMTB::getExcludeRange).
    define_method<void(cv::AlignMTB::*)(int)>("set_exclude_range", &cv::AlignMTB::setExcludeRange,
      Arg("exclude_range")).
    define_method<bool(cv::AlignMTB::*)() const>("get_cut?", &cv::AlignMTB::getCut).
    define_method<void(cv::AlignMTB::*)(bool)>("set_cut", &cv::AlignMTB::setCut,
      Arg("value"));

  rb_mCv.define_module_function<cv::Ptr<cv::AlignMTB>(*)(int, int, bool)>("create_align_mtb", &cv::createAlignMTB,
    Arg("max_bits") = static_cast<int>(6), Arg("exclude_range") = static_cast<int>(4), Arg("cut") = static_cast<bool>(true));

  Rice::Data_Type<cv::CalibrateCRF> rb_cCvCalibrateCRF = define_class_under<cv::CalibrateCRF, cv::Algorithm>(rb_mCv, "CalibrateCRF").
    define_method<void(cv::CalibrateCRF::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray)>("process", &cv::CalibrateCRF::process,
      Arg("src"), Arg("dst"), Arg("times"));

  Rice::Data_Type<cv::CalibrateDebevec> rb_cCvCalibrateDebevec = define_class_under<cv::CalibrateDebevec, cv::CalibrateCRF>(rb_mCv, "CalibrateDebevec").
    define_method<float(cv::CalibrateDebevec::*)() const>("get_lambda", &cv::CalibrateDebevec::getLambda).
    define_method<void(cv::CalibrateDebevec::*)(float)>("set_lambda", &cv::CalibrateDebevec::setLambda,
      Arg("lambda")).
    define_method<int(cv::CalibrateDebevec::*)() const>("get_samples", &cv::CalibrateDebevec::getSamples).
    define_method<void(cv::CalibrateDebevec::*)(int)>("set_samples", &cv::CalibrateDebevec::setSamples,
      Arg("samples")).
    define_method<bool(cv::CalibrateDebevec::*)() const>("get_random?", &cv::CalibrateDebevec::getRandom).
    define_method<void(cv::CalibrateDebevec::*)(bool)>("set_random", &cv::CalibrateDebevec::setRandom,
      Arg("random"));

  rb_mCv.define_module_function<cv::Ptr<cv::CalibrateDebevec>(*)(int, float, bool)>("create_calibrate_debevec", &cv::createCalibrateDebevec,
    Arg("samples") = static_cast<int>(70), Arg("lambda") = static_cast<float>(10.0f), Arg("random") = static_cast<bool>(false));

  Rice::Data_Type<cv::CalibrateRobertson> rb_cCvCalibrateRobertson = define_class_under<cv::CalibrateRobertson, cv::CalibrateCRF>(rb_mCv, "CalibrateRobertson").
    define_method<int(cv::CalibrateRobertson::*)() const>("get_max_iter", &cv::CalibrateRobertson::getMaxIter).
    define_method<void(cv::CalibrateRobertson::*)(int)>("set_max_iter", &cv::CalibrateRobertson::setMaxIter,
      Arg("max_iter")).
    define_method<float(cv::CalibrateRobertson::*)() const>("get_threshold", &cv::CalibrateRobertson::getThreshold).
    define_method<void(cv::CalibrateRobertson::*)(float)>("set_threshold", &cv::CalibrateRobertson::setThreshold,
      Arg("threshold")).
    define_method<cv::Mat(cv::CalibrateRobertson::*)() const>("get_radiance", &cv::CalibrateRobertson::getRadiance);

  rb_mCv.define_module_function<cv::Ptr<cv::CalibrateRobertson>(*)(int, float)>("create_calibrate_robertson", &cv::createCalibrateRobertson,
    Arg("max_iter") = static_cast<int>(30), Arg("threshold") = static_cast<float>(0.01f));

  Rice::Data_Type<cv::MergeExposures> rb_cCvMergeExposures = define_class_under<cv::MergeExposures, cv::Algorithm>(rb_mCv, "MergeExposures").
    define_method<void(cv::MergeExposures::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray, cv::InputArray)>("process", &cv::MergeExposures::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response"));

  Rice::Data_Type<cv::MergeDebevec> rb_cCvMergeDebevec = define_class_under<cv::MergeDebevec, cv::MergeExposures>(rb_mCv, "MergeDebevec").
    define_method<void(cv::MergeDebevec::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray, cv::InputArray)>("process", &cv::MergeDebevec::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response")).
    define_method<void(cv::MergeDebevec::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray)>("process", &cv::MergeDebevec::process,
      Arg("src"), Arg("dst"), Arg("times"));

  rb_mCv.define_module_function<cv::Ptr<cv::MergeDebevec>(*)()>("create_merge_debevec", &cv::createMergeDebevec);

  Rice::Data_Type<cv::MergeMertens> rb_cCvMergeMertens = define_class_under<cv::MergeMertens, cv::MergeExposures>(rb_mCv, "MergeMertens").
    define_method<void(cv::MergeMertens::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray, cv::InputArray)>("process", &cv::MergeMertens::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response")).
    define_method<void(cv::MergeMertens::*)(cv::InputArrayOfArrays, cv::OutputArray)>("process", &cv::MergeMertens::process,
      Arg("src"), Arg("dst")).
    define_method<float(cv::MergeMertens::*)() const>("get_contrast_weight", &cv::MergeMertens::getContrastWeight).
    define_method<void(cv::MergeMertens::*)(float)>("set_contrast_weight", &cv::MergeMertens::setContrastWeight,
      Arg("contrast_weiht")).
    define_method<float(cv::MergeMertens::*)() const>("get_saturation_weight", &cv::MergeMertens::getSaturationWeight).
    define_method<void(cv::MergeMertens::*)(float)>("set_saturation_weight", &cv::MergeMertens::setSaturationWeight,
      Arg("saturation_weight")).
    define_method<float(cv::MergeMertens::*)() const>("get_exposure_weight", &cv::MergeMertens::getExposureWeight).
    define_method<void(cv::MergeMertens::*)(float)>("set_exposure_weight", &cv::MergeMertens::setExposureWeight,
      Arg("exposure_weight"));

  rb_mCv.define_module_function<cv::Ptr<cv::MergeMertens>(*)(float, float, float)>("create_merge_mertens", &cv::createMergeMertens,
    Arg("contrast_weight") = static_cast<float>(1.0f), Arg("saturation_weight") = static_cast<float>(1.0f), Arg("exposure_weight") = static_cast<float>(0.0f));

  Rice::Data_Type<cv::MergeRobertson> rb_cCvMergeRobertson = define_class_under<cv::MergeRobertson, cv::MergeExposures>(rb_mCv, "MergeRobertson").
    define_method<void(cv::MergeRobertson::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray, cv::InputArray)>("process", &cv::MergeRobertson::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response")).
    define_method<void(cv::MergeRobertson::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray)>("process", &cv::MergeRobertson::process,
      Arg("src"), Arg("dst"), Arg("times"));

  rb_mCv.define_module_function<cv::Ptr<cv::MergeRobertson>(*)()>("create_merge_robertson", &cv::createMergeRobertson);

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray)>("decolor", &cv::decolor,
    Arg("src"), Arg("grayscale"), Arg("color_boost"));

  Enum<cv::SeamlessCloneFlags> rb_cCvSeamlessCloneFlags = define_enum_under<cv::SeamlessCloneFlags>("SeamlessCloneFlags", rb_mCv).
    define_value("NORMAL_CLONE", cv::SeamlessCloneFlags::NORMAL_CLONE).
    define_value("MIXED_CLONE", cv::SeamlessCloneFlags::MIXED_CLONE).
    define_value("MONOCHROME_TRANSFER", cv::SeamlessCloneFlags::MONOCHROME_TRANSFER).
    define_value("NORMAL_CLONE_WIDE", cv::SeamlessCloneFlags::NORMAL_CLONE_WIDE).
    define_value("MIXED_CLONE_WIDE", cv::SeamlessCloneFlags::MIXED_CLONE_WIDE).
    define_value("MONOCHROME_TRANSFER_WIDE", cv::SeamlessCloneFlags::MONOCHROME_TRANSFER_WIDE);

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::Point, cv::OutputArray, int)>("seamless_clone", &cv::seamlessClone,
    Arg("src"), Arg("dst"), Arg("mask"), Arg("p"), Arg("blend"), Arg("flags"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, float, float, float)>("color_change", &cv::colorChange,
    Arg("src"), Arg("mask"), Arg("dst"), Arg("red_mul") = static_cast<float>(1.0f), Arg("green_mul") = static_cast<float>(1.0f), Arg("blue_mul") = static_cast<float>(1.0f));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, float, float)>("illumination_change", &cv::illuminationChange,
    Arg("src"), Arg("mask"), Arg("dst"), Arg("alpha") = static_cast<float>(0.2f), Arg("beta") = static_cast<float>(0.4f));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, float, float, int)>("texture_flattening", &cv::textureFlattening,
    Arg("src"), Arg("mask"), Arg("dst"), Arg("low_threshold") = static_cast<float>(30), Arg("high_threshold") = static_cast<float>(45), Arg("kernel_size") = static_cast<int>(3));

  rb_mCv.define_constant("RECURS_FILTER", (int)cv::RECURS_FILTER);
  rb_mCv.define_constant("NORMCONV_FILTER", (int)cv::NORMCONV_FILTER);

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, float, float)>("edge_preserving_filter", &cv::edgePreservingFilter,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(1), Arg("sigma_s") = static_cast<float>(60), Arg("sigma_r") = static_cast<float>(0.4f));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, float)>("detail_enhance", &cv::detailEnhance,
    Arg("src"), Arg("dst"), Arg("sigma_s") = static_cast<float>(10), Arg("sigma_r") = static_cast<float>(0.15f));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, float, float, float)>("pencil_sketch", &cv::pencilSketch,
    Arg("src"), Arg("dst1"), Arg("dst2"), Arg("sigma_s") = static_cast<float>(60), Arg("sigma_r") = static_cast<float>(0.07f), Arg("shade_factor") = static_cast<float>(0.02f));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, float)>("stylization", &cv::stylization,
    Arg("src"), Arg("dst"), Arg("sigma_s") = static_cast<float>(60), Arg("sigma_r") = static_cast<float>(0.45f));
}