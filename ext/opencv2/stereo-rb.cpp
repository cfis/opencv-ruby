#include <opencv2/stereo.hpp>
#include "stereo-rb.hpp"

using namespace Rice;

void Init_Stereo()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvStereo = define_module_under(rb_mCv, "Stereo");

  Rice::Data_Type<cv::stereo::StereoMatcher> rb_cCvStereoStereoMatcher = define_class_under<cv::stereo::StereoMatcher, cv::Algorithm>(rb_mCvStereo, "StereoMatcher").
    define_method("compute", &cv::stereo::StereoMatcher::compute,
      Arg("left"), Arg("right"), Arg("disparity")).
    define_method("get_min_disparity", &cv::stereo::StereoMatcher::getMinDisparity).
    define_method("set_min_disparity", &cv::stereo::StereoMatcher::setMinDisparity,
      Arg("min_disparity")).
    define_method("get_num_disparities", &cv::stereo::StereoMatcher::getNumDisparities).
    define_method("set_num_disparities", &cv::stereo::StereoMatcher::setNumDisparities,
      Arg("num_disparities")).
    define_method("get_block_size", &cv::stereo::StereoMatcher::getBlockSize).
    define_method("set_block_size", &cv::stereo::StereoMatcher::setBlockSize,
      Arg("block_size")).
    define_method("get_speckle_window_size", &cv::stereo::StereoMatcher::getSpeckleWindowSize).
    define_method("set_speckle_window_size", &cv::stereo::StereoMatcher::setSpeckleWindowSize,
      Arg("speckle_window_size")).
    define_method("get_speckle_range", &cv::stereo::StereoMatcher::getSpeckleRange).
    define_method("set_speckle_range", &cv::stereo::StereoMatcher::setSpeckleRange,
      Arg("speckle_range")).
    define_method("get_disp12_max_diff", &cv::stereo::StereoMatcher::getDisp12MaxDiff).
    define_method("set_disp12_max_diff", &cv::stereo::StereoMatcher::setDisp12MaxDiff,
      Arg("disp12_max_diff"));

  rb_cCvStereoStereoMatcher.define_constant("DISP_SHIFT", (int)cv::stereo::StereoMatcher::DISP_SHIFT);
  rb_cCvStereoStereoMatcher.define_constant("DISP_SCALE", (int)cv::stereo::StereoMatcher::DISP_SCALE);

  rb_mCvStereo.define_constant("CV_SPECKLE_REMOVAL_ALGORITHM", (int)cv::stereo::CV_SPECKLE_REMOVAL_ALGORITHM);
  rb_mCvStereo.define_constant("CV_SPECKLE_REMOVAL_AVG_ALGORITHM", (int)cv::stereo::CV_SPECKLE_REMOVAL_AVG_ALGORITHM);

  rb_mCvStereo.define_constant("CV_QUADRATIC_INTERPOLATION", (int)cv::stereo::CV_QUADRATIC_INTERPOLATION);
  rb_mCvStereo.define_constant("CV_SIMETRICV_INTERPOLATION", (int)cv::stereo::CV_SIMETRICV_INTERPOLATION);

  Rice::Data_Type<cv::stereo::StereoBinaryBM> rb_cCvStereoStereoBinaryBM = define_class_under<cv::stereo::StereoBinaryBM, cv::stereo::StereoMatcher>(rb_mCvStereo, "StereoBinaryBM").
    define_method("get_pre_filter_type", &cv::stereo::StereoBinaryBM::getPreFilterType).
    define_method("set_pre_filter_type", &cv::stereo::StereoBinaryBM::setPreFilterType,
      Arg("pre_filter_type")).
    define_method("get_pre_filter_size", &cv::stereo::StereoBinaryBM::getPreFilterSize).
    define_method("set_pre_filter_size", &cv::stereo::StereoBinaryBM::setPreFilterSize,
      Arg("pre_filter_size")).
    define_method("get_pre_filter_cap", &cv::stereo::StereoBinaryBM::getPreFilterCap).
    define_method("set_pre_filter_cap", &cv::stereo::StereoBinaryBM::setPreFilterCap,
      Arg("pre_filter_cap")).
    define_method("get_texture_threshold", &cv::stereo::StereoBinaryBM::getTextureThreshold).
    define_method("set_texture_threshold", &cv::stereo::StereoBinaryBM::setTextureThreshold,
      Arg("texture_threshold")).
    define_method("get_uniqueness_ratio", &cv::stereo::StereoBinaryBM::getUniquenessRatio).
    define_method("set_uniqueness_ratio", &cv::stereo::StereoBinaryBM::setUniquenessRatio,
      Arg("uniqueness_ratio")).
    define_method("get_smaller_block_size", &cv::stereo::StereoBinaryBM::getSmallerBlockSize).
    define_method("set_smaller_block_size", &cv::stereo::StereoBinaryBM::setSmallerBlockSize,
      Arg("block_size")).
    define_method("get_scalle_factor", &cv::stereo::StereoBinaryBM::getScalleFactor).
    define_method("set_scalle_factor", &cv::stereo::StereoBinaryBM::setScalleFactor,
      Arg("factor")).
    define_method("get_spekle_removal_technique", &cv::stereo::StereoBinaryBM::getSpekleRemovalTechnique).
    define_method("set_spekle_removal_technique", &cv::stereo::StereoBinaryBM::setSpekleRemovalTechnique,
      Arg("factor")).
    define_method("get_use_prefilter?", &cv::stereo::StereoBinaryBM::getUsePrefilter).
    define_method("set_use_prefilter", &cv::stereo::StereoBinaryBM::setUsePrefilter,
      Arg("factor")).
    define_method("get_binary_kernel_type", &cv::stereo::StereoBinaryBM::getBinaryKernelType).
    define_method("set_binary_kernel_type", &cv::stereo::StereoBinaryBM::setBinaryKernelType,
      Arg("value")).
    define_method("get_agregation_window_size", &cv::stereo::StereoBinaryBM::getAgregationWindowSize).
    define_method("set_agregation_window_size", &cv::stereo::StereoBinaryBM::setAgregationWindowSize,
      Arg("value")).
    define_singleton_function("create", &cv::stereo::StereoBinaryBM::create,
      Arg("num_disparities") = static_cast<int>(0), Arg("block_size") = static_cast<int>(9));

  rb_cCvStereoStereoBinaryBM.define_constant("PREFILTER_NORMALIZED_RESPONSE", (int)cv::stereo::StereoBinaryBM::PREFILTER_NORMALIZED_RESPONSE);
  rb_cCvStereoStereoBinaryBM.define_constant("PREFILTER_XSOBEL", (int)cv::stereo::StereoBinaryBM::PREFILTER_XSOBEL);

  Rice::Data_Type<cv::stereo::StereoBinarySGBM> rb_cCvStereoStereoBinarySGBM = define_class_under<cv::stereo::StereoBinarySGBM, cv::stereo::StereoMatcher>(rb_mCvStereo, "StereoBinarySGBM").
    define_method("get_pre_filter_cap", &cv::stereo::StereoBinarySGBM::getPreFilterCap).
    define_method("set_pre_filter_cap", &cv::stereo::StereoBinarySGBM::setPreFilterCap,
      Arg("pre_filter_cap")).
    define_method("get_uniqueness_ratio", &cv::stereo::StereoBinarySGBM::getUniquenessRatio).
    define_method("set_uniqueness_ratio", &cv::stereo::StereoBinarySGBM::setUniquenessRatio,
      Arg("uniqueness_ratio")).
    define_method("get_p1", &cv::stereo::StereoBinarySGBM::getP1).
    define_method("set_p1", &cv::stereo::StereoBinarySGBM::setP1,
      Arg("p1")).
    define_method("get_p2", &cv::stereo::StereoBinarySGBM::getP2).
    define_method("set_p2", &cv::stereo::StereoBinarySGBM::setP2,
      Arg("p2")).
    define_method("get_mode", &cv::stereo::StereoBinarySGBM::getMode).
    define_method("set_mode", &cv::stereo::StereoBinarySGBM::setMode,
      Arg("mode")).
    define_method("get_spekle_removal_technique", &cv::stereo::StereoBinarySGBM::getSpekleRemovalTechnique).
    define_method("set_spekle_removal_technique", &cv::stereo::StereoBinarySGBM::setSpekleRemovalTechnique,
      Arg("factor")).
    define_method("get_binary_kernel_type", &cv::stereo::StereoBinarySGBM::getBinaryKernelType).
    define_method("set_binary_kernel_type", &cv::stereo::StereoBinarySGBM::setBinaryKernelType,
      Arg("value")).
    define_method("get_sub_pixel_interpolation_method", &cv::stereo::StereoBinarySGBM::getSubPixelInterpolationMethod).
    define_method("set_sub_pixel_interpolation_method", &cv::stereo::StereoBinarySGBM::setSubPixelInterpolationMethod,
      Arg("value")).
    define_singleton_function("create", &cv::stereo::StereoBinarySGBM::create,
      Arg("min_disparity"), Arg("num_disparities"), Arg("block_size"), Arg("p1") = static_cast<int>(100), Arg("p2") = static_cast<int>(1000), Arg("disp12_max_diff") = static_cast<int>(1), Arg("pre_filter_cap") = static_cast<int>(0), Arg("uniqueness_ratio") = static_cast<int>(5), Arg("speckle_window_size") = static_cast<int>(400), Arg("speckle_range") = static_cast<int>(200), Arg("mode") = static_cast<int>(cv::stereo::StereoBinarySGBM::MODE_SGBM));

  rb_cCvStereoStereoBinarySGBM.define_constant("MODE_SGBM", (int)cv::stereo::StereoBinarySGBM::MODE_SGBM);
  rb_cCvStereoStereoBinarySGBM.define_constant("MODE_HH", (int)cv::stereo::StereoBinarySGBM::MODE_HH);
}