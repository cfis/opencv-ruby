template<typename Distance>
inline Rice::Data_Type<cvflann::CompositeIndex<Distance>> CompositeIndex_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cvflann::CompositeIndex<Distance>>(parent, name).
    define_constructor(Constructor<cvflann::CompositeIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::CompositeIndexParams()), Arg("d") = static_cast<Distance>(cvflann::CompositeIndex::Distance())).
    define_constructor(Constructor<cvflann::CompositeIndex<Distance>, const cvflann::CompositeIndex<Distance>&>(),
      Arg("arg_0")).
    template define_method<cvflann::CompositeIndex<Distance>&(cvflann::CompositeIndex<Distance>::*)(const cvflann::CompositeIndex<Distance>&)>("assign", &cvflann::CompositeIndex<Distance>::operator=,
      Arg("arg_0")).
    template define_method<cvflann::flann_algorithm_t(cvflann::CompositeIndex<Distance>::*)() const>("get_type", &cvflann::CompositeIndex<Distance>::getType).
    template define_method<size_t(cvflann::CompositeIndex<Distance>::*)() const>("size", &cvflann::CompositeIndex<Distance>::size).
    template define_method<size_t(cvflann::CompositeIndex<Distance>::*)() const>("veclen", &cvflann::CompositeIndex<Distance>::veclen).
    template define_method<int(cvflann::CompositeIndex<Distance>::*)() const>("used_memory", &cvflann::CompositeIndex<Distance>::usedMemory).
    template define_method<void(cvflann::CompositeIndex<Distance>::*)()>("build_index", &cvflann::CompositeIndex<Distance>::buildIndex).
    template define_method<void(cvflann::CompositeIndex<Distance>::*)(FILE*)>("save_index", &cvflann::CompositeIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::CompositeIndex<Distance>::*)(FILE*)>("load_index", &cvflann::CompositeIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method<cvflann::IndexParams(cvflann::CompositeIndex<Distance>::*)() const>("get_parameters", &cvflann::CompositeIndex<Distance>::getParameters).
    template define_method<void(cvflann::CompositeIndex<Distance>::*)(cvflann::ResultSet<cvflann::CompositeIndex<Distance>::DistanceType>&, const typename cvflann::CompositeIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::CompositeIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
}

