template<typename Distance>
inline Rice::Data_Type<cvflann::KMeansIndex<Distance>> KMeansIndex_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::KMeansIndex<Distance>>(parent, name).
    define_attr("choose_centers", &cvflann::KMeansIndex<Distance>::chooseCenters).
    template define_method<void(cvflann::KMeansIndex<Distance>::*)(int, int*, int, int*, int&)>("choose_centers_random", &cvflann::KMeansIndex<Distance>::chooseCentersRandom,
      Arg("k"), ArgBuffer("indices"), Arg("indices_length"), ArgBuffer("centers"), Arg("centers_length")).
    template define_method<void(cvflann::KMeansIndex<Distance>::*)(int, int*, int, int*, int&)>("choose_centers_gonzales", &cvflann::KMeansIndex<Distance>::chooseCentersGonzales,
      Arg("k"), ArgBuffer("indices"), Arg("indices_length"), ArgBuffer("centers"), Arg("centers_length")).
    template define_method<void(cvflann::KMeansIndex<Distance>::*)(int, int*, int, int*, int&)>("choose_centers_k_meanspp", &cvflann::KMeansIndex<Distance>::chooseCentersKMeanspp,
      Arg("k"), ArgBuffer("indices"), Arg("indices_length"), ArgBuffer("centers"), Arg("centers_length")).
    template define_method<cvflann::flann_algorithm_t(cvflann::KMeansIndex<Distance>::*)() const>("get_type", &cvflann::KMeansIndex<Distance>::getType).
    define_constructor(Constructor<cvflann::KMeansIndex<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::KMeansIndexParams()), Arg("d") = static_cast<Distance>(cvflann::KMeansIndex::Distance())).
    define_constructor(Constructor<cvflann::KMeansIndex<Distance>, const cvflann::KMeansIndex<Distance>&>(),
      Arg("arg_0")).
    template define_method<cvflann::KMeansIndex<Distance>&(cvflann::KMeansIndex<Distance>::*)(const cvflann::KMeansIndex<Distance>&)>("assign", &cvflann::KMeansIndex<Distance>::operator=,
      Arg("arg_0")).
    template define_method<size_t(cvflann::KMeansIndex<Distance>::*)() const>("size", &cvflann::KMeansIndex<Distance>::size).
    template define_method<size_t(cvflann::KMeansIndex<Distance>::*)() const>("veclen", &cvflann::KMeansIndex<Distance>::veclen).
    template define_method<void(cvflann::KMeansIndex<Distance>::*)(float)>("set_cb_index", &cvflann::KMeansIndex<Distance>::set_cb_index,
      Arg("index")).
    template define_method<int(cvflann::KMeansIndex<Distance>::*)() const>("used_memory", &cvflann::KMeansIndex<Distance>::usedMemory).
    template define_method<void(cvflann::KMeansIndex<Distance>::*)()>("build_index", &cvflann::KMeansIndex<Distance>::buildIndex).
    template define_method<void(cvflann::KMeansIndex<Distance>::*)(FILE*)>("save_index", &cvflann::KMeansIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::KMeansIndex<Distance>::*)(FILE*)>("load_index", &cvflann::KMeansIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method<void(cvflann::KMeansIndex<Distance>::*)(cvflann::ResultSet<cvflann::KMeansIndex<Distance>::DistanceType>&, const typename cvflann::KMeansIndex<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::KMeansIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    template define_method<int(cvflann::KMeansIndex<Distance>::*)(cvflann::Matrix<cvflann::KMeansIndex<Distance>::CentersType>&)>("get_cluster_centers", &cvflann::KMeansIndex<Distance>::getClusterCenters,
      Arg("centers")).
    template define_method<cvflann::IndexParams(cvflann::KMeansIndex<Distance>::*)() const>("get_parameters", &cvflann::KMeansIndex<Distance>::getParameters);
}

template<typename CentersContainerType>
inline Rice::Data_Type<cvflann::KMeansIndex::KMeansDistanceComputer<CentersContainerType>> KMeansDistanceComputer_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::KMeansIndex::KMeansDistanceComputer<CentersContainerType>>(parent, name).
    define_constructor(Constructor<cvflann::KMeansIndex<Distance>::KMeansDistanceComputer<CentersContainerType>, Distance, const cvflann::Matrix<ElementType>&, const int, const int*, const CentersContainerType&, const size_t, std::vector<int>&, std::vector<DistanceType>&>(),
      Arg("_distance"), Arg("_dataset"), Arg("_branching"), ArgBuffer("_indices"), Arg("_dcenters"), Arg("_veclen"), Arg("_new_centroids"), Arg("_sq_dists")).
    template define_method<void(cvflann::KMeansIndex<Distance>::KMeansDistanceComputer<CentersContainerType>::*)(const cv::Range&) const>("call", &cvflann::KMeansIndex<Distance>::KMeansDistanceComputer<CentersContainerType>::operator(),
      Arg("range"));
}

