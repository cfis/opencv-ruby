#include <opencv2/flann/hierarchical_clustering_index.h>
#include "hierarchical_clustering_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannHierarchicalClusteringIndexParams;

template<typename Data_Type_T, typename Distance>
inline void HierarchicalClusteringIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::HierarchicalClusteringIndex<Distance>, const Matrix<type-parameter-0-0::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("index_params") = static_cast<const cvflann::IndexParams&>(cvflann::HierarchicalClusteringIndexParams()), Arg("d") = static_cast<Distance>(cvflann::HierarchicalClusteringIndex::Distance())).
    define_constructor(Constructor<cvflann::HierarchicalClusteringIndex<Distance>, const cvflann::HierarchicalClusteringIndex<Distance>&>(),
      Arg("arg_0")).
    define_method("assign", &cvflann::HierarchicalClusteringIndex<Distance>::operator=,
      Arg("arg_0")).
    define_method("size", &cvflann::HierarchicalClusteringIndex<Distance>::size).
    define_method("veclen", &cvflann::HierarchicalClusteringIndex<Distance>::veclen).
    define_method("used_memory", &cvflann::HierarchicalClusteringIndex<Distance>::usedMemory).
    define_method("build_index", &cvflann::HierarchicalClusteringIndex<Distance>::buildIndex).
    define_method("get_type", &cvflann::HierarchicalClusteringIndex<Distance>::getType).
    define_method("save_index", &cvflann::HierarchicalClusteringIndex<Distance>::saveIndex,
      Arg("stream")).
    define_method("load_index", &cvflann::HierarchicalClusteringIndex<Distance>::loadIndex,
      Arg("stream")).
    define_method("find_neighbors", &cvflann::HierarchicalClusteringIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    define_method("get_parameters", &cvflann::HierarchicalClusteringIndex<Distance>::getParameters);
};
void Init_HierarchicalClusteringIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannHierarchicalClusteringIndexParams = define_class_under<cvflann::HierarchicalClusteringIndexParams, cvflann::IndexParams>(rb_mCvflann, "HierarchicalClusteringIndexParams").
    define_constructor(Constructor<cvflann::HierarchicalClusteringIndexParams, int, cvflann::flann_centers_init_t, int, int>(),
      Arg("branching") = static_cast<int>(32), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::FLANN_CENTERS_RANDOM), Arg("trees") = static_cast<int>(4), Arg("leaf_size") = static_cast<int>(100));

}