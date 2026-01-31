#include <opencv2/flann/kdtree_index.h>
#include "kdtree_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void KDTreeIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KDTreeIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::KDTreeIndexParams()), Arg("d") = static_cast<Distance>(cvflann::KDTreeIndex::Distance())).
    define_constructor(Constructor<cvflann::KDTreeIndex<Distance>, const cvflann::KDTreeIndex<Distance>&>(),
      Arg("arg_0")).
    template define_method<cvflann::KDTreeIndex<Distance>&(cvflann::KDTreeIndex<Distance>::*)(const cvflann::KDTreeIndex<Distance>&)>("assign", &cvflann::KDTreeIndex<Distance>::operator=,
      Arg("arg_0")).
    template define_method<void(cvflann::KDTreeIndex<Distance>::*)()>("build_index", &cvflann::KDTreeIndex<Distance>::buildIndex).
    template define_method<cvflann::flann_algorithm_t(cvflann::KDTreeIndex<Distance>::*)() const>("get_type", &cvflann::KDTreeIndex<Distance>::getType).
    template define_method<void(cvflann::KDTreeIndex<Distance>::*)(FILE*)>("save_index", &cvflann::KDTreeIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::KDTreeIndex<Distance>::*)(FILE*)>("load_index", &cvflann::KDTreeIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method<size_t(cvflann::KDTreeIndex<Distance>::*)() const>("size", &cvflann::KDTreeIndex<Distance>::size).
    template define_method<size_t(cvflann::KDTreeIndex<Distance>::*)() const>("veclen", &cvflann::KDTreeIndex<Distance>::veclen).
    template define_method<int(cvflann::KDTreeIndex<Distance>::*)() const>("used_memory", &cvflann::KDTreeIndex<Distance>::usedMemory).
    template define_method<void(cvflann::KDTreeIndex<Distance>::*)(cvflann::ResultSet<cvflann::KDTreeIndex<Distance>::DistanceType>&, const typename cvflann::KDTreeIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::KDTreeIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    template define_method<cvflann::IndexParams(cvflann::KDTreeIndex<Distance>::*)() const>("get_parameters", &cvflann::KDTreeIndex<Distance>::getParameters);
};

