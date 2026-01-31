#include <opencv2/flann/autotuned_index.h>
#include "autotuned_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void AutotunedIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::AutotunedIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::AutotunedIndexParams()), Arg("d") = static_cast<Distance>(cvflann::AutotunedIndex::Distance())).
    define_constructor(Constructor<cvflann::AutotunedIndex<Distance>, const cvflann::AutotunedIndex<Distance>&>(),
      Arg("arg_0")).
    template define_method<cvflann::AutotunedIndex<Distance>&(cvflann::AutotunedIndex<Distance>::*)(const cvflann::AutotunedIndex<Distance>&)>("assign", &cvflann::AutotunedIndex<Distance>::operator=,
      Arg("arg_0")).
    template define_method<void(cvflann::AutotunedIndex<Distance>::*)()>("build_index", &cvflann::AutotunedIndex<Distance>::buildIndex).
    template define_method<void(cvflann::AutotunedIndex<Distance>::*)(FILE*)>("save_index", &cvflann::AutotunedIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::AutotunedIndex<Distance>::*)(FILE*)>("load_index", &cvflann::AutotunedIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method<void(cvflann::AutotunedIndex<Distance>::*)(cvflann::ResultSet<cvflann::AutotunedIndex<Distance>::DistanceType>&, const typename cvflann::AutotunedIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::AutotunedIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    template define_method<cvflann::IndexParams(cvflann::AutotunedIndex<Distance>::*)() const>("get_parameters", &cvflann::AutotunedIndex<Distance>::getParameters).
    template define_method<cvflann::SearchParams(cvflann::AutotunedIndex<Distance>::*)() const>("get_search_parameters", &cvflann::AutotunedIndex<Distance>::getSearchParameters).
    template define_method<float(cvflann::AutotunedIndex<Distance>::*)() const>("get_speedup", &cvflann::AutotunedIndex<Distance>::getSpeedup).
    template define_method<size_t(cvflann::AutotunedIndex<Distance>::*)() const>("size", &cvflann::AutotunedIndex<Distance>::size).
    template define_method<size_t(cvflann::AutotunedIndex<Distance>::*)() const>("veclen", &cvflann::AutotunedIndex<Distance>::veclen).
    template define_method<int(cvflann::AutotunedIndex<Distance>::*)() const>("used_memory", &cvflann::AutotunedIndex<Distance>::usedMemory).
    template define_method<cvflann::flann_algorithm_t(cvflann::AutotunedIndex<Distance>::*)() const>("get_type", &cvflann::AutotunedIndex<Distance>::getType);
};

