#include <opencv2/stitching/detail/blenders.hpp>
#include "../../core/cvstd_wrapper-rb.hpp"
#include "blenders-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailBlender;
Rice::Class rb_cCvDetailFeatherBlender;
Rice::Class rb_cCvDetailMultiBandBlender;

void Init_Blenders()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_cCvDetailBlender = define_class_under<cv::detail::Blender>(rb_mCvDetail, "Blender").
    define_constructor(Constructor<cv::detail::Blender>()).
    define_singleton_function("create_default", &cv::detail::Blender::createDefault,
      Arg("type"), Arg("try_gpu") = static_cast<bool>(false)).
    define_method<void(cv::detail::Blender::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("prepare", &cv::detail::Blender::prepare,
      Arg("corners"), Arg("sizes")).
    define_method<void(cv::detail::Blender::*)(cv::Rect)>("prepare", &cv::detail::Blender::prepare,
      Arg("dst_roi")).
    define_method("feed", &cv::detail::Blender::feed,
      Arg("img"), Arg("mask"), Arg("tl")).
    define_method("blend", &cv::detail::Blender::blend,
      Arg("dst"), Arg("dst_mask"));
  
  rb_cCvDetailBlender.define_constant("NO", (int)cv::detail::Blender::NO);
  rb_cCvDetailBlender.define_constant("FEATHER", (int)cv::detail::Blender::FEATHER);
  rb_cCvDetailBlender.define_constant("MULTI_BAND", (int)cv::detail::Blender::MULTI_BAND);
  
  rb_cCvDetailFeatherBlender = define_class_under<cv::detail::FeatherBlender, cv::detail::Blender>(rb_mCvDetail, "FeatherBlender").
    define_constructor(Constructor<cv::detail::FeatherBlender, float>(),
      Arg("sharpness") = static_cast<float>(0.02f)).
    define_method("sharpness", &cv::detail::FeatherBlender::sharpness).
    define_method("set_sharpness", &cv::detail::FeatherBlender::setSharpness,
      Arg("val")).
    define_method("prepare", &cv::detail::FeatherBlender::prepare,
      Arg("dst_roi")).
    define_method("feed", &cv::detail::FeatherBlender::feed,
      Arg("img"), Arg("mask"), Arg("tl")).
    define_method("blend", &cv::detail::FeatherBlender::blend,
      Arg("dst"), Arg("dst_mask")).
    define_method("create_weight_maps", &cv::detail::FeatherBlender::createWeightMaps,
      Arg("masks"), Arg("corners"), Arg("weight_maps"));
  
  rb_cCvDetailMultiBandBlender = define_class_under<cv::detail::MultiBandBlender, cv::detail::Blender>(rb_mCvDetail, "MultiBandBlender").
    define_constructor(Constructor<cv::detail::MultiBandBlender, int, int, int>(),
      Arg("try_gpu") = static_cast<int>(false), Arg("num_bands") = static_cast<int>(5), Arg("weight_type") = static_cast<int>(CV_32F)).
    define_method("num_bands", &cv::detail::MultiBandBlender::numBands).
    define_method("set_num_bands", &cv::detail::MultiBandBlender::setNumBands,
      Arg("val")).
    define_method("prepare", &cv::detail::MultiBandBlender::prepare,
      Arg("dst_roi")).
    define_method("feed", &cv::detail::MultiBandBlender::feed,
      Arg("img"), Arg("mask"), Arg("tl")).
    define_method("blend", &cv::detail::MultiBandBlender::blend,
      Arg("dst"), Arg("dst_mask"));
  
  rb_mCvDetail.define_module_function("normalize_using_weight_map", &cv::detail::normalizeUsingWeightMap,
    Arg("weight"), Arg("src"));
  
  rb_mCvDetail.define_module_function("create_weight_map", &cv::detail::createWeightMap,
    Arg("mask"), Arg("sharpness"), Arg("weight"));
  
  rb_mCvDetail.define_module_function("create_laplace_pyr", &cv::detail::createLaplacePyr,
    Arg("img"), Arg("num_levels"), Arg("pyr"));
  
  rb_mCvDetail.define_module_function("create_laplace_pyr_gpu", &cv::detail::createLaplacePyrGpu,
    Arg("img"), Arg("num_levels"), Arg("pyr"));
  
  rb_mCvDetail.define_module_function("restore_image_from_laplace_pyr", &cv::detail::restoreImageFromLaplacePyr,
    Arg("pyr"));
  
  rb_mCvDetail.define_module_function("restore_image_from_laplace_pyr_gpu", &cv::detail::restoreImageFromLaplacePyrGpu,
    Arg("pyr"));

}