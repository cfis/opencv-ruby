#include <opencv2/surface_matching/ppf_helpers.hpp>
#include "ppf_helpers-rb.hpp"

using namespace Rice;

void Init_SurfaceMatching_PpfHelpers()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");

  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(const char*, int)>("load_ply_simple", &cv::ppf_match_3d::loadPLYSimple,
    Arg("file_name"), Arg("with_normals") = static_cast<int>(0));

  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::Mat, const char*)>("write_ply", &cv::ppf_match_3d::writePLY,
    Arg("pc"), Arg("file_name"));

  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::Mat, const char*)>("write_ply_visible_normals", &cv::ppf_match_3d::writePLYVisibleNormals,
    Arg("pc"), Arg("file_name"));

  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, int)>("sample_pc_uniform", &cv::ppf_match_3d::samplePCUniform,
    Arg("pc"), Arg("sample_step"));

  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, int, std::vector<int>&)>("sample_pc_uniform_ind", &cv::ppf_match_3d::samplePCUniformInd,
    Arg("pc"), Arg("sample_step"), Arg("indices"));

  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, cv::Vec2f&, cv::Vec2f&, cv::Vec2f&, float, int)>("sample_pc_by_quantization", &cv::ppf_match_3d::samplePCByQuantization,
    Arg("pc"), Arg("xrange"), Arg("yrange"), Arg("zrange"), Arg("sample_step_relative"), Arg("weight_by_center") = static_cast<int>(0));

  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::Mat, cv::Vec2f&, cv::Vec2f&, cv::Vec2f&)>("compute_bbox_std", &cv::ppf_match_3d::computeBboxStd,
    Arg("pc"), Arg("x_range"), Arg("y_range"), Arg("z_range"));

  rb_mCvPpfMatch3d.define_module_function<void*(*)(cv::Mat)>("index_pc_flann", &cv::ppf_match_3d::indexPCFlann,
    Arg("pc"), ReturnBuffer());

  rb_mCvPpfMatch3d.define_module_function<void(*)(void*)>("destroy_flann", &cv::ppf_match_3d::destroyFlann,
    ArgBuffer("flann_index"));

  rb_mCvPpfMatch3d.define_module_function<void(*)(void*, cv::Mat&, cv::Mat&, cv::Mat&)>("query_pc_flann", &cv::ppf_match_3d::queryPCFlann,
    ArgBuffer("flann_index"), Arg("pc"), Arg("indices"), Arg("distances"));

  rb_mCvPpfMatch3d.define_module_function<void(*)(void*, cv::Mat&, cv::Mat&, cv::Mat&, const int)>("query_pc_flann", &cv::ppf_match_3d::queryPCFlann,
    ArgBuffer("flann_index"), Arg("pc"), Arg("indices"), Arg("distances"), Arg("num_neighbors"));

  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, float, float*, float*, float*, float*, float*)>("normalize_pc_coeff", &cv::ppf_match_3d::normalizePCCoeff,
    Arg("pc"), Arg("scale"), ArgBuffer("cx"), ArgBuffer("cy"), ArgBuffer("cz"), ArgBuffer("min_val"), ArgBuffer("max_val"));

  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, float, float, float, float, float, float)>("trans_pc_coeff", &cv::ppf_match_3d::transPCCoeff,
    Arg("pc"), Arg("scale"), Arg("cx"), Arg("cy"), Arg("cz"), Arg("min_val"), Arg("max_val"));

  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, const cv::Matx44d&)>("transform_pc_pose", &cv::ppf_match_3d::transformPCPose,
    Arg("pc"), Arg("pose"));

  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::Matx44d&)>("get_random_pose", &cv::ppf_match_3d::getRandomPose,
    Arg("pose"));

  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, double)>("add_noise_pc", &cv::ppf_match_3d::addNoisePC,
    Arg("pc"), Arg("scale"));

  rb_mCvPpfMatch3d.define_module_function<int(*)(const cv::Mat&, cv::Mat&, const int, const bool, const cv::Vec3f&)>("compute_normals_pc3d", &cv::ppf_match_3d::computeNormalsPC3d,
    Arg("pc"), Arg("pc_normals"), Arg("num_neighbors"), Arg("flip_viewpoint"), Arg("viewpoint"));
}