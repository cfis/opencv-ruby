#include <opencv2/flann/hierarchical_clustering_index.h>
#include "hierarchical_clustering_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void HierarchicalClusteringIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::HierarchicalClusteringIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("index_params") = static_cast<const cvflann::IndexParams&>(cvflann::HierarchicalClusteringIndexParams()), Arg("d") = static_cast<Distance>(cvflann::HierarchicalClusteringIndex::Distance())).
    define_constructor(Constructor<cvflann::HierarchicalClusteringIndex<Distance>, const cvflann::HierarchicalClusteringIndex<Distance>&>(),
      Arg("arg_0")).
    template define_method<cvflann::HierarchicalClusteringIndex<Distance>&(cvflann::HierarchicalClusteringIndex<Distance>::*)(const cvflann::HierarchicalClusteringIndex<Distance>&)>("assign", &cvflann::HierarchicalClusteringIndex<Distance>::operator=,
      Arg("arg_0")).
    template define_method<size_t(cvflann::HierarchicalClusteringIndex<Distance>::*)() const>("size", &cvflann::HierarchicalClusteringIndex<Distance>::size).
    template define_method<size_t(cvflann::HierarchicalClusteringIndex<Distance>::*)() const>("veclen", &cvflann::HierarchicalClusteringIndex<Distance>::veclen).
    template define_method<int(cvflann::HierarchicalClusteringIndex<Distance>::*)() const>("used_memory", &cvflann::HierarchicalClusteringIndex<Distance>::usedMemory).
    template define_method<void(cvflann::HierarchicalClusteringIndex<Distance>::*)()>("build_index", &cvflann::HierarchicalClusteringIndex<Distance>::buildIndex).
    template define_method<cvflann::flann_algorithm_t(cvflann::HierarchicalClusteringIndex<Distance>::*)() const>("get_type", &cvflann::HierarchicalClusteringIndex<Distance>::getType).
    template define_method<void(cvflann::HierarchicalClusteringIndex<Distance>::*)(FILE*)>("save_index", &cvflann::HierarchicalClusteringIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::HierarchicalClusteringIndex<Distance>::*)(FILE*)>("load_index", &cvflann::HierarchicalClusteringIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method<void(cvflann::HierarchicalClusteringIndex<Distance>::*)(cvflann::ResultSet<cvflann::HierarchicalClusteringIndex<Distance>::DistanceType>&, const typename cvflann::HierarchicalClusteringIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::HierarchicalClusteringIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    template define_method<cvflann::IndexParams(cvflann::HierarchicalClusteringIndex<Distance>::*)() const>("get_parameters", &cvflann::HierarchicalClusteringIndex<Distance>::getParameters);
};

void Init_Flann_HierarchicalClusteringIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::HierarchicalClusteringIndexParams> rb_cCvflannHierarchicalClusteringIndexParams = define_class_under<cvflann::HierarchicalClusteringIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "HierarchicalClusteringIndexParams").
    define_constructor(Constructor<cvflann::HierarchicalClusteringIndexParams, int, cvflann::flann_centers_init_t, int, int>(),
      Arg("branching") = static_cast<int>(32), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::FLANN_CENTERS_RANDOM), Arg("trees") = static_cast<int>(4), Arg("leaf_size") = static_cast<int>(100));
}