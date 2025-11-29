#include <opencv2/flann/defines.h>
#include "defines-rb.hpp"

using namespace Rice;


void Init_Defines()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  Enum<cvflann::flann_algorithm_t> rb_cCvflannFlannAlgorithmT = define_enum_under<cvflann::flann_algorithm_t>("FlannAlgorithmT", rb_mCvflann).
    define_value("FLANN_INDEX_LINEAR", cvflann::flann_algorithm_t::FLANN_INDEX_LINEAR).
    define_value("FLANN_INDEX_KDTREE", cvflann::flann_algorithm_t::FLANN_INDEX_KDTREE).
    define_value("FLANN_INDEX_KMEANS", cvflann::flann_algorithm_t::FLANN_INDEX_KMEANS).
    define_value("FLANN_INDEX_COMPOSITE", cvflann::flann_algorithm_t::FLANN_INDEX_COMPOSITE).
    define_value("FLANN_INDEX_KDTREE_SINGLE", cvflann::flann_algorithm_t::FLANN_INDEX_KDTREE_SINGLE).
    define_value("FLANN_INDEX_HIERARCHICAL", cvflann::flann_algorithm_t::FLANN_INDEX_HIERARCHICAL).
    define_value("FLANN_INDEX_LSH", cvflann::flann_algorithm_t::FLANN_INDEX_LSH).
    define_value("FLANN_INDEX_SAVED", cvflann::flann_algorithm_t::FLANN_INDEX_SAVED).
    define_value("FLANN_INDEX_AUTOTUNED", cvflann::flann_algorithm_t::FLANN_INDEX_AUTOTUNED).
    define_value("LINEAR", cvflann::flann_algorithm_t::LINEAR).
    define_value("KDTREE", cvflann::flann_algorithm_t::KDTREE).
    define_value("KMEANS", cvflann::flann_algorithm_t::KMEANS).
    define_value("COMPOSITE", cvflann::flann_algorithm_t::COMPOSITE).
    define_value("KDTREE_SINGLE", cvflann::flann_algorithm_t::KDTREE_SINGLE).
    define_value("SAVED", cvflann::flann_algorithm_t::SAVED).
    define_value("AUTOTUNED", cvflann::flann_algorithm_t::AUTOTUNED);
  
  Enum<cvflann::flann_centers_init_t> rb_cCvflannFlannCentersInitT = define_enum_under<cvflann::flann_centers_init_t>("FlannCentersInitT", rb_mCvflann).
    define_value("FLANN_CENTERS_RANDOM", cvflann::flann_centers_init_t::FLANN_CENTERS_RANDOM).
    define_value("FLANN_CENTERS_GONZALES", cvflann::flann_centers_init_t::FLANN_CENTERS_GONZALES).
    define_value("FLANN_CENTERS_KMEANSPP", cvflann::flann_centers_init_t::FLANN_CENTERS_KMEANSPP).
    define_value("FLANN_CENTERS_GROUPWISE", cvflann::flann_centers_init_t::FLANN_CENTERS_GROUPWISE).
    define_value("CENTERS_RANDOM", cvflann::flann_centers_init_t::CENTERS_RANDOM).
    define_value("CENTERS_GONZALES", cvflann::flann_centers_init_t::CENTERS_GONZALES).
    define_value("CENTERS_KMEANSPP", cvflann::flann_centers_init_t::CENTERS_KMEANSPP);
  
  Enum<cvflann::flann_log_level_t> rb_cCvflannFlannLogLevelT = define_enum_under<cvflann::flann_log_level_t>("FlannLogLevelT", rb_mCvflann).
    define_value("FLANN_LOG_NONE", cvflann::flann_log_level_t::FLANN_LOG_NONE).
    define_value("FLANN_LOG_FATAL", cvflann::flann_log_level_t::FLANN_LOG_FATAL).
    define_value("FLANN_LOG_ERROR", cvflann::flann_log_level_t::FLANN_LOG_ERROR).
    define_value("FLANN_LOG_WARN", cvflann::flann_log_level_t::FLANN_LOG_WARN).
    define_value("FLANN_LOG_INFO", cvflann::flann_log_level_t::FLANN_LOG_INFO);
  
  Enum<cvflann::flann_distance_t> rb_cCvflannFlannDistanceT = define_enum_under<cvflann::flann_distance_t>("FlannDistanceT", rb_mCvflann).
    define_value("FLANN_DIST_EUCLIDEAN", cvflann::flann_distance_t::FLANN_DIST_EUCLIDEAN).
    define_value("FLANN_DIST_L2", cvflann::flann_distance_t::FLANN_DIST_L2).
    define_value("FLANN_DIST_MANHATTAN", cvflann::flann_distance_t::FLANN_DIST_MANHATTAN).
    define_value("FLANN_DIST_L1", cvflann::flann_distance_t::FLANN_DIST_L1).
    define_value("FLANN_DIST_MINKOWSKI", cvflann::flann_distance_t::FLANN_DIST_MINKOWSKI).
    define_value("FLANN_DIST_MAX", cvflann::flann_distance_t::FLANN_DIST_MAX).
    define_value("FLANN_DIST_HIST_INTERSECT", cvflann::flann_distance_t::FLANN_DIST_HIST_INTERSECT).
    define_value("FLANN_DIST_HELLINGER", cvflann::flann_distance_t::FLANN_DIST_HELLINGER).
    define_value("FLANN_DIST_CHI_SQUARE", cvflann::flann_distance_t::FLANN_DIST_CHI_SQUARE).
    define_value("FLANN_DIST_CS", cvflann::flann_distance_t::FLANN_DIST_CS).
    define_value("FLANN_DIST_KULLBACK_LEIBLER", cvflann::flann_distance_t::FLANN_DIST_KULLBACK_LEIBLER).
    define_value("FLANN_DIST_KL", cvflann::flann_distance_t::FLANN_DIST_KL).
    define_value("FLANN_DIST_HAMMING", cvflann::flann_distance_t::FLANN_DIST_HAMMING).
    define_value("FLANN_DIST_DNAMMING", cvflann::flann_distance_t::FLANN_DIST_DNAMMING).
    define_value("EUCLIDEAN", cvflann::flann_distance_t::EUCLIDEAN).
    define_value("MANHATTAN", cvflann::flann_distance_t::MANHATTAN).
    define_value("MINKOWSKI", cvflann::flann_distance_t::MINKOWSKI).
    define_value("MAX_DIST", cvflann::flann_distance_t::MAX_DIST).
    define_value("HIST_INTERSECT", cvflann::flann_distance_t::HIST_INTERSECT).
    define_value("HELLINGER", cvflann::flann_distance_t::HELLINGER).
    define_value("CS", cvflann::flann_distance_t::CS).
    define_value("KL", cvflann::flann_distance_t::KL).
    define_value("KULLBACK_LEIBLER", cvflann::flann_distance_t::KULLBACK_LEIBLER);
  
  Enum<cvflann::flann_datatype_t> rb_cCvflannFlannDatatypeT = define_enum_under<cvflann::flann_datatype_t>("FlannDatatypeT", rb_mCvflann).
    define_value("FLANN_INT8", cvflann::flann_datatype_t::FLANN_INT8).
    define_value("FLANN_INT16", cvflann::flann_datatype_t::FLANN_INT16).
    define_value("FLANN_INT32", cvflann::flann_datatype_t::FLANN_INT32).
    define_value("FLANN_INT64", cvflann::flann_datatype_t::FLANN_INT64).
    define_value("FLANN_UINT8", cvflann::flann_datatype_t::FLANN_UINT8).
    define_value("FLANN_UINT16", cvflann::flann_datatype_t::FLANN_UINT16).
    define_value("FLANN_UINT32", cvflann::flann_datatype_t::FLANN_UINT32).
    define_value("FLANN_UINT64", cvflann::flann_datatype_t::FLANN_UINT64).
    define_value("FLANN_FLOAT32", cvflann::flann_datatype_t::FLANN_FLOAT32).
    define_value("FLANN_FLOAT64", cvflann::flann_datatype_t::FLANN_FLOAT64);
  
  rb_mCvflann.define_constant("FLANN_CHECKS_UNLIMITED", (int)cvflann::FLANN_CHECKS_UNLIMITED);
  rb_mCvflann.define_constant("FLANN_CHECKS_AUTOTUNED", (int)cvflann::FLANN_CHECKS_AUTOTUNED);

}