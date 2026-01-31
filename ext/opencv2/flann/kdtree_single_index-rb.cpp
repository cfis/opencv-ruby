#include <opencv2/flann/kdtree_single_index.h>
#include "kdtree_single_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void KDTreeSingleIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KDTreeSingleIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::KDTreeSingleIndexParams()), Arg("d") = static_cast<Distance>(cvflann::KDTreeSingleIndex::Distance())).
    define_constructor(Constructor<cvflann::KDTreeSingleIndex<Distance>, const cvflann::KDTreeSingleIndex<Distance>&>(),
      Arg("arg_0")).
    template define_method<cvflann::KDTreeSingleIndex<Distance>&(cvflann::KDTreeSingleIndex<Distance>::*)(const cvflann::KDTreeSingleIndex<Distance>&)>("assign", &cvflann::KDTreeSingleIndex<Distance>::operator=,
      Arg("arg_0")).
    template define_method<void(cvflann::KDTreeSingleIndex<Distance>::*)()>("build_index", &cvflann::KDTreeSingleIndex<Distance>::buildIndex).
    template define_method<cvflann::flann_algorithm_t(cvflann::KDTreeSingleIndex<Distance>::*)() const>("get_type", &cvflann::KDTreeSingleIndex<Distance>::getType).
    template define_method<void(cvflann::KDTreeSingleIndex<Distance>::*)(FILE*)>("save_index", &cvflann::KDTreeSingleIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::KDTreeSingleIndex<Distance>::*)(FILE*)>("load_index", &cvflann::KDTreeSingleIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method<size_t(cvflann::KDTreeSingleIndex<Distance>::*)() const>("size", &cvflann::KDTreeSingleIndex<Distance>::size).
    template define_method<size_t(cvflann::KDTreeSingleIndex<Distance>::*)() const>("veclen", &cvflann::KDTreeSingleIndex<Distance>::veclen).
    template define_method<int(cvflann::KDTreeSingleIndex<Distance>::*)() const>("used_memory", &cvflann::KDTreeSingleIndex<Distance>::usedMemory).
    template define_method<void(cvflann::KDTreeSingleIndex<Distance>::*)(const cvflann::Matrix<cvflann::KDTreeSingleIndex<Distance>::ElementType>&, cvflann::Matrix<int>&, cvflann::Matrix<cvflann::KDTreeSingleIndex<Distance>::DistanceType>&, int, const cvflann::SearchParams&)>("knn_search", &cvflann::KDTreeSingleIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<cvflann::IndexParams(cvflann::KDTreeSingleIndex<Distance>::*)() const>("get_parameters", &cvflann::KDTreeSingleIndex<Distance>::getParameters).
    template define_method<void(cvflann::KDTreeSingleIndex<Distance>::*)(cvflann::ResultSet<cvflann::KDTreeSingleIndex<Distance>::DistanceType>&, const typename cvflann::KDTreeSingleIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::KDTreeSingleIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
};

void Init_Flann_KdtreeSingleIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::KDTreeSingleIndexParams> rb_cCvflannKDTreeSingleIndexParams = define_class_under<cvflann::KDTreeSingleIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "KDTreeSingleIndexParams").
    define_constructor(Constructor<cvflann::KDTreeSingleIndexParams, int, bool, int>(),
      Arg("leaf_max_size") = static_cast<int>(10), Arg("reorder") = static_cast<bool>(true), Arg("dim") = static_cast<int>(-1));
}