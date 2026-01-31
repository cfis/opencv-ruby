#include <opencv2/flann/nn_index.h>
#include "nn_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void NNIndex_builder(Data_Type_T& klass)
{
  klass.template define_method<void(cvflann::NNIndex<Distance>::*)()>("build_index", &cvflann::NNIndex<Distance>::buildIndex).
    template define_method<void(cvflann::NNIndex<Distance>::*)(const cvflann::Matrix<cvflann::NNIndex<Distance>::ElementType>&, cvflann::Matrix<int>&, cvflann::Matrix<cvflann::NNIndex<Distance>::DistanceType>&, int, const cvflann::SearchParams&)>("knn_search", &cvflann::NNIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<int(cvflann::NNIndex<Distance>::*)(const cvflann::Matrix<cvflann::NNIndex<Distance>::ElementType>&, cvflann::Matrix<int>&, cvflann::Matrix<cvflann::NNIndex<Distance>::DistanceType>&, float, const cvflann::SearchParams&)>("radius_search", &cvflann::NNIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method<void(cvflann::NNIndex<Distance>::*)(FILE*)>("save_index", &cvflann::NNIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::NNIndex<Distance>::*)(FILE*)>("load_index", &cvflann::NNIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method<size_t(cvflann::NNIndex<Distance>::*)() const>("size", &cvflann::NNIndex<Distance>::size).
    template define_method<size_t(cvflann::NNIndex<Distance>::*)() const>("veclen", &cvflann::NNIndex<Distance>::veclen).
    template define_method<int(cvflann::NNIndex<Distance>::*)() const>("used_memory", &cvflann::NNIndex<Distance>::usedMemory).
    template define_method<cvflann::flann_algorithm_t(cvflann::NNIndex<Distance>::*)() const>("get_type", &cvflann::NNIndex<Distance>::getType).
    template define_method<cvflann::IndexParams(cvflann::NNIndex<Distance>::*)() const>("get_parameters", &cvflann::NNIndex<Distance>::getParameters).
    template define_method<void(cvflann::NNIndex<Distance>::*)(cvflann::ResultSet<cvflann::NNIndex<Distance>::DistanceType>&, const typename cvflann::NNIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::NNIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
};

