template<typename Distance>
inline Rice::Data_Type<cvflann::Index<Distance>> Index_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cvflann::Index<Distance>>(parent, name).
    define_constructor(Constructor<cvflann::Index<Distance>, const cvflann::Matrix<ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("features"), Arg("params"), Arg("distance") = static_cast<Distance>(cvflann::Index::Distance())).
    template define_method<void(cvflann::Index<Distance>::*)()>("build_index", &cvflann::Index<Distance>::buildIndex).
    template define_method<void(cvflann::Index<Distance>::*)(cv::String)>("save", &cvflann::Index<Distance>::save,
      Arg("filename")).
    template define_method<void(cvflann::Index<Distance>::*)(FILE*)>("save_index", &cvflann::Index<Distance>::saveIndex,
      Arg("stream")).
    template define_method<void(cvflann::Index<Distance>::*)(FILE*)>("load_index", &cvflann::Index<Distance>::loadIndex,
      Arg("stream")).
    template define_method<size_t(cvflann::Index<Distance>::*)() const>("veclen", &cvflann::Index<Distance>::veclen).
    template define_method<size_t(cvflann::Index<Distance>::*)() const>("size", &cvflann::Index<Distance>::size).
    template define_method<cvflann::flann_algorithm_t(cvflann::Index<Distance>::*)() const>("get_type", &cvflann::Index<Distance>::getType).
    template define_method<int(cvflann::Index<Distance>::*)() const>("used_memory", &cvflann::Index<Distance>::usedMemory).
    template define_method<cvflann::IndexParams(cvflann::Index<Distance>::*)() const>("get_parameters", &cvflann::Index<Distance>::getParameters).
    template define_method<void(cvflann::Index<Distance>::*)(const cvflann::Matrix<cvflann::Index<Distance>::ElementType>&, cvflann::Matrix<int>&, cvflann::Matrix<cvflann::Index<Distance>::DistanceType>&, int, const cvflann::SearchParams&)>("knn_search", &cvflann::Index<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<int(cvflann::Index<Distance>::*)(const cvflann::Matrix<cvflann::Index<Distance>::ElementType>&, cvflann::Matrix<int>&, cvflann::Matrix<cvflann::Index<Distance>::DistanceType>&, float, const cvflann::SearchParams&)>("radius_search", &cvflann::Index<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method<void(cvflann::Index<Distance>::*)(cvflann::ResultSet<cvflann::Index<Distance>::DistanceType>&, const typename cvflann::Index<Distance>::ElementType*, const cvflann::SearchParams&)>("find_neighbors", &cvflann::Index<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
}

