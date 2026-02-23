template<typename Distance>
inline Rice::Data_Type<cvflann::LshIndex<Distance>> LshIndex_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::LshIndex<Distance>>(parent, name).
    define_constructor(Constructor<cvflann::LshIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::LshIndexParams()), Arg("d") = static_cast<Distance>(cvflann::LshIndex::Distance())).
    define_constructor(Constructor<cvflann::LshIndex<Distance>, const cvflann::LshIndex<Distance>&>(),
      Arg("arg_0")).
    template define_method<cvflann::LshIndex<Distance>&(cvflann::LshIndex<Distance>::*)(const cvflann::LshIndex<Distance>&)>("assign", &cvflann::LshIndex<Distance>::operator=,
      Arg("arg_0")).
    template define_method<void(cvflann::LshIndex<Distance>::*)()>("build_index", &cvflann::LshIndex<Distance>::buildIndex).
    template define_method<cvflann::flann_algorithm_t(cvflann::LshIndex<Distance>::*)() const>("get_type", &cvflann::LshIndex<Distance>::getType).
    template define_method<void(cvflann::LshIndex<Distance>::*)(FILE*)>("save_index", &cvflann::LshIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::LshIndex<Distance>::*)(FILE*)>("load_index", &cvflann::LshIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method<size_t(cvflann::LshIndex<Distance>::*)() const>("size", &cvflann::LshIndex<Distance>::size).
    template define_method<size_t(cvflann::LshIndex<Distance>::*)() const>("veclen", &cvflann::LshIndex<Distance>::veclen).
    template define_method<int(cvflann::LshIndex<Distance>::*)() const>("used_memory", &cvflann::LshIndex<Distance>::usedMemory).
    template define_method<cvflann::IndexParams(cvflann::LshIndex<Distance>::*)() const>("get_parameters", &cvflann::LshIndex<Distance>::getParameters).
    template define_method<void(cvflann::LshIndex<Distance>::*)(const cvflann::Matrix<typename cvflann::LshIndex<Distance>::ElementType>&, cvflann::Matrix<int>&, cvflann::Matrix<typename cvflann::LshIndex<Distance>::DistanceType>&, int, const cvflann::SearchParams&)>("knn_search", &cvflann::LshIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<void(cvflann::LshIndex<Distance>::*)(cvflann::ResultSet<typename cvflann::LshIndex<Distance>::DistanceType>&, const typename cvflann::LshIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::LshIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("arg_2"));
}

