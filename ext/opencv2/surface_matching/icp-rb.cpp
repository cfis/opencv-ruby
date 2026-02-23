#include <opencv2/surface_matching/icp.hpp>
#include "icp-rb.hpp"

using namespace Rice;

void Init_SurfaceMatching_Icp()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");

  Rice::Data_Type<cv::ppf_match_3d::ICP> rb_cCvPpfMatch3dICP = define_class_under<cv::ppf_match_3d::ICP>(rb_mCvPpfMatch3d, "ICP").
    define_constructor(Constructor<cv::ppf_match_3d::ICP>()).
    define_constructor(Constructor<cv::ppf_match_3d::ICP, const int, const float, const float, const int, const int, const int>(),
      Arg("iterations"), Arg("tolerence") = static_cast<const float>(0.05f), Arg("rejection_scale") = static_cast<const float>(2.5f), Arg("num_levels") = static_cast<const int>(6), Arg("sample_type") = static_cast<const int>(cv::ppf_match_3d::ICP::ICP_SAMPLING_TYPE_UNIFORM), Arg("num_max_corr") = static_cast<const int>(1)).
    define_method<int(cv::ppf_match_3d::ICP::*)(const cv::Mat&, const cv::Mat&, double&, cv::Matx44d&)>("register_model_to_scene", &cv::ppf_match_3d::ICP::registerModelToScene,
      Arg("src_pc"), Arg("dst_pc"), Arg("residual"), Arg("pose")).
    define_method<int(cv::ppf_match_3d::ICP::*)(const cv::Mat&, const cv::Mat&, std::vector<cv::Ptr<cv::ppf_match_3d::Pose3D>>&)>("register_model_to_scene", &cv::ppf_match_3d::ICP::registerModelToScene,
      Arg("src_pc"), Arg("dst_pc"), Arg("poses"));

  rb_cCvPpfMatch3dICP.define_constant("ICP_SAMPLING_TYPE_UNIFORM", (int)cv::ppf_match_3d::ICP::ICP_SAMPLING_TYPE_UNIFORM);
  rb_cCvPpfMatch3dICP.define_constant("ICP_SAMPLING_TYPE_GELFAND", (int)cv::ppf_match_3d::ICP::ICP_SAMPLING_TYPE_GELFAND);
}
