#include <opencv2/flann/linear_index.h>
#include "linear_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void LinearIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::LinearIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::LinearIndexParams()), Arg("d") = static_cast<Distance>(cvflann::LinearIndex::Distance())).
    define_constructor(Constructor<cvflann::LinearIndex<Distance>, const cvflann::LinearIndex<Distance>&>(),
      Arg("arg_0")).
    template define_method<cvflann::LinearIndex<Distance>&(cvflann::LinearIndex<Distance>::*)(const cvflann::LinearIndex<Distance>&)>("assign", &cvflann::LinearIndex<Distance>::operator=,
      Arg("arg_0")).
    template define_method<cvflann::flann_algorithm_t(cvflann::LinearIndex<Distance>::*)() const>("get_type", &cvflann::LinearIndex<Distance>::getType).
    template define_method<size_t(cvflann::LinearIndex<Distance>::*)() const>("size", &cvflann::LinearIndex<Distance>::size).
    template define_method<size_t(cvflann::LinearIndex<Distance>::*)() const>("veclen", &cvflann::LinearIndex<Distance>::veclen).
    template define_method<int(cvflann::LinearIndex<Distance>::*)() const>("used_memory", &cvflann::LinearIndex<Distance>::usedMemory).
    template define_method<void(cvflann::LinearIndex<Distance>::*)()>("build_index", &cvflann::LinearIndex<Distance>::buildIndex).
    template define_method<void(cvflann::LinearIndex<Distance>::*)(FILE*)>("save_index", &cvflann::LinearIndex<Distance>::saveIndex,
      Arg("arg_0")).
    template define_method<void(cvflann::LinearIndex<Distance>::*)(FILE*)>("load_index", &cvflann::LinearIndex<Distance>::loadIndex,
      Arg("arg_0")).
    template define_method<void(cvflann::LinearIndex<Distance>::*)(cvflann::ResultSet<cvflann::LinearIndex<Distance>::DistanceType>&, const typename cvflann::LinearIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::LinearIndex<Distance>::findNeighbors,
      Arg("result_set"), Arg("vec"), Arg("arg_2")).
    template define_method<cvflann::IndexParams(cvflann::LinearIndex<Distance>::*)() const>("get_parameters", &cvflann::LinearIndex<Distance>::getParameters);
};

void Init_Flann_LinearIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::LinearIndexParams> rb_cCvflannLinearIndexParams = define_class_under<cvflann::LinearIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "LinearIndexParams").
    define_constructor(Constructor<cvflann::LinearIndexParams>());
}