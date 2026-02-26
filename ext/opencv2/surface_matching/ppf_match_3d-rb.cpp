#include <opencv2/surface_matching/ppf_match_3d.hpp>
#include "ppf_match_3d-rb.hpp"

using namespace Rice;

void Init_SurfaceMatching_PpfMatch3d()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");

  Rice::Data_Type<cv::ppf_match_3d::THash> rb_cCvPpfMatch3dTHash = define_class_under<cv::ppf_match_3d::THash>(rb_mCvPpfMatch3d, "THash").
    define_constructor(Constructor<cv::ppf_match_3d::THash>()).
    define_attr("id", &cv::ppf_match_3d::THash::id).
    define_attr("i", &cv::ppf_match_3d::THash::i).
    define_attr("ppf_ind", &cv::ppf_match_3d::THash::ppfInd);

  Rice::Data_Type<cv::ppf_match_3d::PPF3DDetector> rb_cCvPpfMatch3dPPF3DDetector = define_class_under<cv::ppf_match_3d::PPF3DDetector>(rb_mCvPpfMatch3d, "PPF3DDetector").
    define_constructor(Constructor<cv::ppf_match_3d::PPF3DDetector>()).
    define_constructor(Constructor<cv::ppf_match_3d::PPF3DDetector, const double, const double, const double>(),
      Arg("relative_sampling_step"), Arg("relative_distance_step") = static_cast<const double>(0.05), Arg("num_angles") = static_cast<const double>(30)).
    define_method<void(cv::ppf_match_3d::PPF3DDetector::*)(const double, const double, const bool)>("set_search_params", &cv::ppf_match_3d::PPF3DDetector::setSearchParams,
      Arg("position_threshold") = static_cast<const double>(-1), Arg("rotation_threshold") = static_cast<const double>(-1), Arg("use_weighted_clustering") = static_cast<const bool>(false)).
    define_method<void(cv::ppf_match_3d::PPF3DDetector::*)(const cv::Mat&)>("train_model", &cv::ppf_match_3d::PPF3DDetector::trainModel,
      Arg("model")).
    define_method<void(cv::ppf_match_3d::PPF3DDetector::*)(const cv::Mat&, std::vector<cv::ppf_match_3d::Pose3DPtr>&, const double, const double)>("match", &cv::ppf_match_3d::PPF3DDetector::match,
      Arg("scene"), Arg("results"), Arg("relative_scene_sample_step"), Arg("relative_scene_distance") = static_cast<const double>(0.03));
}
