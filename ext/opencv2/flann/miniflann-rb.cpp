#include <opencv2/flann/miniflann.hpp>
#include "miniflann-rb.hpp"

using namespace Rice;

void Init_Flann_Miniflann()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFlann = define_module_under(rb_mCv, "Flann");

  Enum<cv::flann::FlannIndexType> rb_cCvFlannFlannIndexType = define_enum_under<cv::flann::FlannIndexType>("FlannIndexType", rb_mCvFlann).
    define_value("FLANN_INDEX_TYPE_8U", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_8U).
    define_value("FLANN_INDEX_TYPE_8S", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_8S).
    define_value("FLANN_INDEX_TYPE_16U", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_16U).
    define_value("FLANN_INDEX_TYPE_16S", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_16S).
    define_value("FLANN_INDEX_TYPE_32S", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_32S).
    define_value("FLANN_INDEX_TYPE_32F", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_32F).
    define_value("FLANN_INDEX_TYPE_64F", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_64F).
    define_value("FLANN_INDEX_TYPE_STRING", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_STRING).
    define_value("FLANN_INDEX_TYPE_BOOL", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_BOOL).
    define_value("FLANN_INDEX_TYPE_ALGORITHM", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_ALGORITHM).
    define_value("LAST_VALUE_FLANN_INDEX_TYPE", cv::flann::FlannIndexType::LAST_VALUE_FLANN_INDEX_TYPE);

  Rice::Data_Type<cv::flann::IndexParams> rb_cCvFlannIndexParams = define_class_under<cv::flann::IndexParams>(rb_mCvFlann, "IndexParams").
    define_constructor(Constructor<cv::flann::IndexParams>()).
    define_method<cv::String(cv::flann::IndexParams::*)(const cv::String&, const cv::String&) const>("get_string", &cv::flann::IndexParams::getString,
      Arg("key"), Arg("default_val") = static_cast<const cv::String&>(cv::String())).
    define_method<int(cv::flann::IndexParams::*)(const cv::String&, int) const>("get_int", &cv::flann::IndexParams::getInt,
      Arg("key"), Arg("default_val") = static_cast<int>(-1)).
    define_method<double(cv::flann::IndexParams::*)(const cv::String&, double) const>("get_double", &cv::flann::IndexParams::getDouble,
      Arg("key"), Arg("default_val") = static_cast<double>(-1)).
    define_method<void(cv::flann::IndexParams::*)(const cv::String&, const cv::String&)>("set_string", &cv::flann::IndexParams::setString,
      Arg("key"), Arg("value")).
    define_method<void(cv::flann::IndexParams::*)(const cv::String&, int)>("set_int", &cv::flann::IndexParams::setInt,
      Arg("key"), Arg("value")).
    define_method<void(cv::flann::IndexParams::*)(const cv::String&, double)>("set_double", &cv::flann::IndexParams::setDouble,
      Arg("key"), Arg("value")).
    define_method<void(cv::flann::IndexParams::*)(const cv::String&, float)>("set_float", &cv::flann::IndexParams::setFloat,
      Arg("key"), Arg("value")).
    define_method<void(cv::flann::IndexParams::*)(const cv::String&, bool)>("set_bool", &cv::flann::IndexParams::setBool,
      Arg("key"), Arg("value")).
    define_method<void(cv::flann::IndexParams::*)(int)>("set_algorithm", &cv::flann::IndexParams::setAlgorithm,
      Arg("value")).
    define_method<void(cv::flann::IndexParams::*)(std::vector<std::basic_string<char>>&, std::vector<cv::flann::FlannIndexType>&, std::vector<std::basic_string<char>>&, std::vector<double>&) const>("get_all", &cv::flann::IndexParams::getAll,
      Arg("names"), Arg("types"), Arg("str_values"), Arg("num_values")).
    define_attr("params", &cv::flann::IndexParams::params);

  Rice::Data_Type<cv::flann::KDTreeIndexParams> rb_cCvFlannKDTreeIndexParams = define_class_under<cv::flann::KDTreeIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "KDTreeIndexParams").
    define_constructor(Constructor<cv::flann::KDTreeIndexParams, int>(),
      Arg("trees") = static_cast<int>(4));

  Rice::Data_Type<cv::flann::LinearIndexParams> rb_cCvFlannLinearIndexParams = define_class_under<cv::flann::LinearIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "LinearIndexParams").
    define_constructor(Constructor<cv::flann::LinearIndexParams>());

  Rice::Data_Type<cv::flann::CompositeIndexParams> rb_cCvFlannCompositeIndexParams = define_class_under<cv::flann::CompositeIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "CompositeIndexParams").
    define_constructor(Constructor<cv::flann::CompositeIndexParams, int, int, int, cvflann::flann_centers_init_t, float>(),
      Arg("trees") = static_cast<int>(4), Arg("branching") = static_cast<int>(32), Arg("iterations") = static_cast<int>(11), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::FLANN_CENTERS_RANDOM), Arg("cb_index") = static_cast<float>(0.2f));

  Rice::Data_Type<cv::flann::AutotunedIndexParams> rb_cCvFlannAutotunedIndexParams = define_class_under<cv::flann::AutotunedIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "AutotunedIndexParams").
    define_constructor(Constructor<cv::flann::AutotunedIndexParams, float, float, float, float>(),
      Arg("target_precision") = static_cast<float>(0.8f), Arg("build_weight") = static_cast<float>(0.01f), Arg("memory_weight") = static_cast<float>(0), Arg("sample_fraction") = static_cast<float>(0.1f));

  Rice::Data_Type<cv::flann::HierarchicalClusteringIndexParams> rb_cCvFlannHierarchicalClusteringIndexParams = define_class_under<cv::flann::HierarchicalClusteringIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "HierarchicalClusteringIndexParams").
    define_constructor(Constructor<cv::flann::HierarchicalClusteringIndexParams, int, cvflann::flann_centers_init_t, int, int>(),
      Arg("branching") = static_cast<int>(32), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::FLANN_CENTERS_RANDOM), Arg("trees") = static_cast<int>(4), Arg("leaf_size") = static_cast<int>(100));

  Rice::Data_Type<cv::flann::KMeansIndexParams> rb_cCvFlannKMeansIndexParams = define_class_under<cv::flann::KMeansIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "KMeansIndexParams").
    define_constructor(Constructor<cv::flann::KMeansIndexParams, int, int, cvflann::flann_centers_init_t, float>(),
      Arg("branching") = static_cast<int>(32), Arg("iterations") = static_cast<int>(11), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::FLANN_CENTERS_RANDOM), Arg("cb_index") = static_cast<float>(0.2f));

  Rice::Data_Type<cv::flann::LshIndexParams> rb_cCvFlannLshIndexParams = define_class_under<cv::flann::LshIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "LshIndexParams").
    define_constructor(Constructor<cv::flann::LshIndexParams, int, int, int>(),
      Arg("table_number"), Arg("key_size"), Arg("multi_probe_level"));

  Rice::Data_Type<cv::flann::SavedIndexParams> rb_cCvFlannSavedIndexParams = define_class_under<cv::flann::SavedIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "SavedIndexParams").
    define_constructor(Constructor<cv::flann::SavedIndexParams, const cv::String&>(),
      Arg("filename"));

  Rice::Data_Type<cv::flann::SearchParams> rb_cCvFlannSearchParams = define_class_under<cv::flann::SearchParams, cv::flann::IndexParams>(rb_mCvFlann, "SearchParams").
    define_constructor(Constructor<cv::flann::SearchParams, int, float, bool, bool>(),
      Arg("checks"), Arg("eps"), Arg("sorted"), Arg("explore_all_trees")).
    define_constructor(Constructor<cv::flann::SearchParams, int, float, bool>(),
      Arg("checks") = static_cast<int>(32), Arg("eps") = static_cast<float>(0), Arg("sorted") = static_cast<bool>(true));

  Rice::Data_Type<cv::flann::Index> rb_cCvFlannIndex = define_class_under<cv::flann::Index>(rb_mCvFlann, "Index").
    define_constructor(Constructor<cv::flann::Index>()).
    define_constructor(Constructor<cv::flann::Index, cv::InputArray, const cv::flann::IndexParams&, cvflann::flann_distance_t>(),
      Arg("features"), Arg("params"), Arg("dist_type") = static_cast<cvflann::flann_distance_t>(cvflann::FLANN_DIST_L2)).
    define_method<void(cv::flann::Index::*)(cv::InputArray, const cv::flann::IndexParams&, cvflann::flann_distance_t)>("build", &cv::flann::Index::build,
      Arg("features"), Arg("params"), Arg("dist_type") = static_cast<cvflann::flann_distance_t>(cvflann::FLANN_DIST_L2)).
    define_method<void(cv::flann::Index::*)(cv::InputArray, cv::OutputArray, cv::OutputArray, int, const cv::flann::SearchParams&)>("knn_search", &cv::flann::Index::knnSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    define_method<int(cv::flann::Index::*)(cv::InputArray, cv::OutputArray, cv::OutputArray, double, int, const cv::flann::SearchParams&)>("radius_search", &cv::flann::Index::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("max_results"), Arg("params")).
    define_method<void(cv::flann::Index::*)(const cv::String&) const>("save", &cv::flann::Index::save,
      Arg("filename")).
    define_method<bool(cv::flann::Index::*)(cv::InputArray, const cv::String&)>("load", &cv::flann::Index::load,
      Arg("features"), Arg("filename")).
    define_method<void(cv::flann::Index::*)()>("release", &cv::flann::Index::release).
    define_method<cvflann::flann_distance_t(cv::flann::Index::*)() const>("get_distance", &cv::flann::Index::getDistance).
    define_method<cvflann::flann_algorithm_t(cv::flann::Index::*)() const>("get_algorithm", &cv::flann::Index::getAlgorithm);
}