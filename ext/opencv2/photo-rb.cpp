#include <opencv2/photo.hpp>
#include "core/cvstd_wrapper-rb.hpp"
#include "photo-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvAlignExposures;
Rice::Class rb_cCvAlignMTB;
Rice::Class rb_cCvCalibrateCRF;
Rice::Class rb_cCvCalibrateDebevec;
Rice::Class rb_cCvCalibrateRobertson;
Rice::Class rb_cCvMergeDebevec;
Rice::Class rb_cCvMergeExposures;
Rice::Class rb_cCvMergeMertens;
Rice::Class rb_cCvMergeRobertson;
Rice::Class rb_cCvTonemap;
Rice::Class rb_cCvTonemapDrago;
Rice::Class rb_cCvTonemapMantiuk;
Rice::Class rb_cCvTonemapReinhard;

void Init_Photo()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_constant("INPAINT_NS", (int)cv::INPAINT_NS);
  rb_mCv.define_constant("INPAINT_TELEA", (int)cv::INPAINT_TELEA);
  
  rb_mCv.define_module_function("inpaint", &cv::inpaint,
    Arg("src"), Arg("inpaint_mask"), Arg("dst"), Arg("inpaint_radius"), Arg("flags"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, float, int, int)>("fast_nl_means_denoising", &cv::fastNlMeansDenoising,
    Arg("src"), Arg("dst"), Arg("h") = static_cast<float>(3), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const std::vector<float>&, int, int, int)>("fast_nl_means_denoising", &cv::fastNlMeansDenoising,
    Arg("src"), Arg("dst"), Arg("h"), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21), Arg("norm_type") = static_cast<int>(cv::NormTypes::NORM_L2));
  
  rb_mCv.define_module_function("fast_nl_means_denoising_colored", &cv::fastNlMeansDenoisingColored,
    Arg("src"), Arg("dst"), Arg("h") = static_cast<float>(3), Arg("h_color") = static_cast<float>(3), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21));
  
  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, int, int, float, int, int)>("fast_nl_means_denoising_multi", &cv::fastNlMeansDenoisingMulti,
    Arg("src_imgs"), Arg("dst"), Arg("img_to_denoise_index"), Arg("temporal_window_size"), Arg("h") = static_cast<float>(3), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21));
  
  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray, int, int, const std::vector<float>&, int, int, int)>("fast_nl_means_denoising_multi", &cv::fastNlMeansDenoisingMulti,
    Arg("src_imgs"), Arg("dst"), Arg("img_to_denoise_index"), Arg("temporal_window_size"), Arg("h"), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21), Arg("norm_type") = static_cast<int>(cv::NormTypes::NORM_L2));
  
  rb_mCv.define_module_function("fast_nl_means_denoising_colored_multi", &cv::fastNlMeansDenoisingColoredMulti,
    Arg("src_imgs"), Arg("dst"), Arg("img_to_denoise_index"), Arg("temporal_window_size"), Arg("h") = static_cast<float>(3), Arg("h_color") = static_cast<float>(3), Arg("template_window_size") = static_cast<int>(7), Arg("search_window_size") = static_cast<int>(21));
  
  rb_mCv.define_module_function("denoise_tvl1", &cv::denoise_TVL1,
    Arg("observations"), Arg("result"), Arg("lambda") = static_cast<double>(1.0), Arg("niters") = static_cast<int>(30));
  
  rb_mCv.define_constant("LDR_SIZE", (int)cv::LDR_SIZE);
  
  rb_cCvTonemap = define_class_under<cv::Tonemap, cv::Algorithm>(rb_mCv, "Tonemap").
    define_method("process", &cv::Tonemap::process,
      Arg("src"), Arg("dst")).
    define_method("get_gamma", &cv::Tonemap::getGamma).
    define_method("set_gamma", &cv::Tonemap::setGamma,
      Arg("gamma"));
  
  rb_mCv.define_module_function("create_tonemap", &cv::createTonemap,
    Arg("gamma") = static_cast<float>(1.0f));
  
  rb_cCvTonemapDrago = define_class_under<cv::TonemapDrago, cv::Tonemap>(rb_mCv, "TonemapDrago").
    define_method("get_saturation", &cv::TonemapDrago::getSaturation).
    define_method("set_saturation", &cv::TonemapDrago::setSaturation,
      Arg("saturation")).
    define_method("get_bias", &cv::TonemapDrago::getBias).
    define_method("set_bias", &cv::TonemapDrago::setBias,
      Arg("bias"));
  
  rb_mCv.define_module_function("create_tonemap_drago", &cv::createTonemapDrago,
    Arg("gamma") = static_cast<float>(1.0f), Arg("saturation") = static_cast<float>(1.0f), Arg("bias") = static_cast<float>(0.85f));
  
  rb_cCvTonemapReinhard = define_class_under<cv::TonemapReinhard, cv::Tonemap>(rb_mCv, "TonemapReinhard").
    define_method("get_intensity", &cv::TonemapReinhard::getIntensity).
    define_method("set_intensity", &cv::TonemapReinhard::setIntensity,
      Arg("intensity")).
    define_method("get_light_adaptation", &cv::TonemapReinhard::getLightAdaptation).
    define_method("set_light_adaptation", &cv::TonemapReinhard::setLightAdaptation,
      Arg("light_adapt")).
    define_method("get_color_adaptation", &cv::TonemapReinhard::getColorAdaptation).
    define_method("set_color_adaptation", &cv::TonemapReinhard::setColorAdaptation,
      Arg("color_adapt"));
  
  rb_mCv.define_module_function("create_tonemap_reinhard", &cv::createTonemapReinhard,
    Arg("gamma") = static_cast<float>(1.0f), Arg("intensity") = static_cast<float>(0.0f), Arg("light_adapt") = static_cast<float>(1.0f), Arg("color_adapt") = static_cast<float>(0.0f));
  
  rb_cCvTonemapMantiuk = define_class_under<cv::TonemapMantiuk, cv::Tonemap>(rb_mCv, "TonemapMantiuk").
    define_method("get_scale", &cv::TonemapMantiuk::getScale).
    define_method("set_scale", &cv::TonemapMantiuk::setScale,
      Arg("scale")).
    define_method("get_saturation", &cv::TonemapMantiuk::getSaturation).
    define_method("set_saturation", &cv::TonemapMantiuk::setSaturation,
      Arg("saturation"));
  
  rb_mCv.define_module_function("create_tonemap_mantiuk", &cv::createTonemapMantiuk,
    Arg("gamma") = static_cast<float>(1.0f), Arg("scale") = static_cast<float>(0.7f), Arg("saturation") = static_cast<float>(1.0f));
  
  rb_cCvAlignExposures = define_class_under<cv::AlignExposures, cv::Algorithm>(rb_mCv, "AlignExposures").
    define_method("process", &cv::AlignExposures::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response"));
  
  rb_cCvAlignMTB = define_class_under<cv::AlignMTB, cv::AlignExposures>(rb_mCv, "AlignMTB").
    define_method<void(cv::AlignMTB::*)(cv::InputArrayOfArrays, std::vector<cv::Mat>&, cv::InputArray, cv::InputArray)>("process", &cv::AlignMTB::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response")).
    define_method<void(cv::AlignMTB::*)(cv::InputArrayOfArrays, std::vector<cv::Mat>&)>("process", &cv::AlignMTB::process,
      Arg("src"), Arg("dst")).
    define_method("calculate_shift", &cv::AlignMTB::calculateShift,
      Arg("img0"), Arg("img1")).
    define_method("shift_mat", &cv::AlignMTB::shiftMat,
      Arg("src"), Arg("dst"), Arg("shift")).
    define_method("compute_bitmaps", &cv::AlignMTB::computeBitmaps,
      Arg("img"), Arg("tb"), Arg("eb")).
    define_method("get_max_bits", &cv::AlignMTB::getMaxBits).
    define_method("set_max_bits", &cv::AlignMTB::setMaxBits,
      Arg("max_bits")).
    define_method("get_exclude_range", &cv::AlignMTB::getExcludeRange).
    define_method("set_exclude_range", &cv::AlignMTB::setExcludeRange,
      Arg("exclude_range")).
    define_method("get_cut?", &cv::AlignMTB::getCut).
    define_method("set_cut", &cv::AlignMTB::setCut,
      Arg("value"));
  
  rb_mCv.define_module_function("create_align_mtb", &cv::createAlignMTB,
    Arg("max_bits") = static_cast<int>(6), Arg("exclude_range") = static_cast<int>(4), Arg("cut") = static_cast<bool>(true));
  
  rb_cCvCalibrateCRF = define_class_under<cv::CalibrateCRF, cv::Algorithm>(rb_mCv, "CalibrateCRF").
    define_method("process", &cv::CalibrateCRF::process,
      Arg("src"), Arg("dst"), Arg("times"));
  
  rb_cCvCalibrateDebevec = define_class_under<cv::CalibrateDebevec, cv::CalibrateCRF>(rb_mCv, "CalibrateDebevec").
    define_method("get_lambda", &cv::CalibrateDebevec::getLambda).
    define_method("set_lambda", &cv::CalibrateDebevec::setLambda,
      Arg("lambda")).
    define_method("get_samples", &cv::CalibrateDebevec::getSamples).
    define_method("set_samples", &cv::CalibrateDebevec::setSamples,
      Arg("samples")).
    define_method("get_random?", &cv::CalibrateDebevec::getRandom).
    define_method("set_random", &cv::CalibrateDebevec::setRandom,
      Arg("random"));
  
  rb_mCv.define_module_function("create_calibrate_debevec", &cv::createCalibrateDebevec,
    Arg("samples") = static_cast<int>(70), Arg("lambda") = static_cast<float>(10.0f), Arg("random") = static_cast<bool>(false));
  
  rb_cCvCalibrateRobertson = define_class_under<cv::CalibrateRobertson, cv::CalibrateCRF>(rb_mCv, "CalibrateRobertson").
    define_method("get_max_iter", &cv::CalibrateRobertson::getMaxIter).
    define_method("set_max_iter", &cv::CalibrateRobertson::setMaxIter,
      Arg("max_iter")).
    define_method("get_threshold", &cv::CalibrateRobertson::getThreshold).
    define_method("set_threshold", &cv::CalibrateRobertson::setThreshold,
      Arg("threshold")).
    define_method("get_radiance", &cv::CalibrateRobertson::getRadiance);
  
  rb_mCv.define_module_function("create_calibrate_robertson", &cv::createCalibrateRobertson,
    Arg("max_iter") = static_cast<int>(30), Arg("threshold") = static_cast<float>(0.01f));
  
  rb_cCvMergeExposures = define_class_under<cv::MergeExposures, cv::Algorithm>(rb_mCv, "MergeExposures").
    define_method("process", &cv::MergeExposures::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response"));
  
  rb_cCvMergeDebevec = define_class_under<cv::MergeDebevec, cv::MergeExposures>(rb_mCv, "MergeDebevec").
    define_method<void(cv::MergeDebevec::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray, cv::InputArray)>("process", &cv::MergeDebevec::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response")).
    define_method<void(cv::MergeDebevec::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray)>("process", &cv::MergeDebevec::process,
      Arg("src"), Arg("dst"), Arg("times"));
  
  rb_mCv.define_module_function("create_merge_debevec", &cv::createMergeDebevec);
  
  rb_cCvMergeMertens = define_class_under<cv::MergeMertens, cv::MergeExposures>(rb_mCv, "MergeMertens").
    define_method<void(cv::MergeMertens::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray, cv::InputArray)>("process", &cv::MergeMertens::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response")).
    define_method<void(cv::MergeMertens::*)(cv::InputArrayOfArrays, cv::OutputArray)>("process", &cv::MergeMertens::process,
      Arg("src"), Arg("dst")).
    define_method("get_contrast_weight", &cv::MergeMertens::getContrastWeight).
    define_method("set_contrast_weight", &cv::MergeMertens::setContrastWeight,
      Arg("contrast_weiht")).
    define_method("get_saturation_weight", &cv::MergeMertens::getSaturationWeight).
    define_method("set_saturation_weight", &cv::MergeMertens::setSaturationWeight,
      Arg("saturation_weight")).
    define_method("get_exposure_weight", &cv::MergeMertens::getExposureWeight).
    define_method("set_exposure_weight", &cv::MergeMertens::setExposureWeight,
      Arg("exposure_weight"));
  
  rb_mCv.define_module_function("create_merge_mertens", &cv::createMergeMertens,
    Arg("contrast_weight") = static_cast<float>(1.0f), Arg("saturation_weight") = static_cast<float>(1.0f), Arg("exposure_weight") = static_cast<float>(0.0f));
  
  rb_cCvMergeRobertson = define_class_under<cv::MergeRobertson, cv::MergeExposures>(rb_mCv, "MergeRobertson").
    define_method<void(cv::MergeRobertson::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray, cv::InputArray)>("process", &cv::MergeRobertson::process,
      Arg("src"), Arg("dst"), Arg("times"), Arg("response")).
    define_method<void(cv::MergeRobertson::*)(cv::InputArrayOfArrays, cv::OutputArray, cv::InputArray)>("process", &cv::MergeRobertson::process,
      Arg("src"), Arg("dst"), Arg("times"));
  
  rb_mCv.define_module_function("create_merge_robertson", &cv::createMergeRobertson);
  
  rb_mCv.define_module_function("decolor", &cv::decolor,
    Arg("src"), Arg("grayscale"), Arg("color_boost"));
  
  rb_mCv.define_constant("NORMAL_CLONE", (int)cv::NORMAL_CLONE);
  rb_mCv.define_constant("MIXED_CLONE", (int)cv::MIXED_CLONE);
  rb_mCv.define_constant("MONOCHROME_TRANSFER", (int)cv::MONOCHROME_TRANSFER);
  
  rb_mCv.define_module_function("seamless_clone", &cv::seamlessClone,
    Arg("src"), Arg("dst"), Arg("mask"), Arg("p"), Arg("blend"), Arg("flags"));
  
  rb_mCv.define_module_function("color_change", &cv::colorChange,
    Arg("src"), Arg("mask"), Arg("dst"), Arg("red_mul") = static_cast<float>(1.0f), Arg("green_mul") = static_cast<float>(1.0f), Arg("blue_mul") = static_cast<float>(1.0f));
  
  rb_mCv.define_module_function("illumination_change", &cv::illuminationChange,
    Arg("src"), Arg("mask"), Arg("dst"), Arg("alpha") = static_cast<float>(0.2f), Arg("beta") = static_cast<float>(0.4f));
  
  rb_mCv.define_module_function("texture_flattening", &cv::textureFlattening,
    Arg("src"), Arg("mask"), Arg("dst"), Arg("low_threshold") = static_cast<float>(30), Arg("high_threshold") = static_cast<float>(45), Arg("kernel_size") = static_cast<int>(3));
  
  rb_mCv.define_constant("RECURS_FILTER", (int)cv::RECURS_FILTER);
  rb_mCv.define_constant("NORMCONV_FILTER", (int)cv::NORMCONV_FILTER);
  
  rb_mCv.define_module_function("edge_preserving_filter", &cv::edgePreservingFilter,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(1), Arg("sigma_s") = static_cast<float>(60), Arg("sigma_r") = static_cast<float>(0.4f));
  
  rb_mCv.define_module_function("detail_enhance", &cv::detailEnhance,
    Arg("src"), Arg("dst"), Arg("sigma_s") = static_cast<float>(10), Arg("sigma_r") = static_cast<float>(0.15f));
  
  rb_mCv.define_module_function("pencil_sketch", &cv::pencilSketch,
    Arg("src"), Arg("dst1"), Arg("dst2"), Arg("sigma_s") = static_cast<float>(60), Arg("sigma_r") = static_cast<float>(0.07f), Arg("shade_factor") = static_cast<float>(0.02f));
  
  rb_mCv.define_module_function("stylization", &cv::stylization,
    Arg("src"), Arg("dst"), Arg("sigma_s") = static_cast<float>(60), Arg("sigma_r") = static_cast<float>(0.45f));

}