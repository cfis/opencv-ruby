#include <opencv2/flann/hierarchical_clustering_index.h>
#include "hierarchical_clustering_index-rb.hpp"

using namespace Rice;

#include "hierarchical_clustering_index-rb.ipp"

void Init_Flann_HierarchicalClusteringIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::HierarchicalClusteringIndexParams> rb_cCvflannHierarchicalClusteringIndexParams = define_class_under<cvflann::HierarchicalClusteringIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "HierarchicalClusteringIndexParams").
    define_constructor(Constructor<cvflann::HierarchicalClusteringIndexParams, int, cvflann::flann_centers_init_t, int, int>(),
      Arg("branching") = static_cast<int>(32), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::FLANN_CENTERS_RANDOM), Arg("trees") = static_cast<int>(4), Arg("leaf_size") = static_cast<int>(100));
}
