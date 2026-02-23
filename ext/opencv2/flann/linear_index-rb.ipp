template<typename Distance>
inline Rice::Data_Type<cvflann::LinearIndex<Distance>> LinearIndex_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::LinearIndex<Distance>>(parent, name).
    define_constructor(Constructor<cvflann::LinearIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
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
    template define_method<void(cvflann::LinearIndex<Distance>::*)(cvflann::ResultSet<typename cvflann::LinearIndex<Distance>::DistanceType>&, const typename cvflann::LinearIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::LinearIndex<Distance>::findNeighbors,
      Arg("result_set"), Arg("vec"), Arg("arg_2")).
    template define_method<cvflann::IndexParams(cvflann::LinearIndex<Distance>::*)() const>("get_parameters", &cvflann::LinearIndex<Distance>::getParameters);
}

