
template<typename Distance>
inline Rice::Data_Type<cv::flann::GenericIndex<Distance>> GenericIndex_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::flann::GenericIndex<Distance>>(parent, name).
    define_constructor(Constructor<cv::flann::GenericIndex<Distance>, const cv::Mat&, const ::cvflann::IndexParams&, Distance>(),
      Arg("features"), Arg("params"), Arg("distance") = static_cast<Distance>(cv::flann::GenericIndex::Distance())).
    template define_method<void(cv::flann::GenericIndex<Distance>::*)(const std::vector<cv::flann::GenericIndex<Distance>::ElementType>&, std::vector<int>&, std::vector<cv::flann::GenericIndex<Distance>::DistanceType>&, int, const ::cvflann::SearchParams&)>("knn_search", &cv::flann::GenericIndex<Distance>::knnSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<void(cv::flann::GenericIndex<Distance>::*)(const cv::Mat&, cv::Mat&, cv::Mat&, int, const ::cvflann::SearchParams&)>("knn_search", &cv::flann::GenericIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<int(cv::flann::GenericIndex<Distance>::*)(const std::vector<cv::flann::GenericIndex<Distance>::ElementType>&, std::vector<int>&, std::vector<cv::flann::GenericIndex<Distance>::DistanceType>&, typename cv::flann::GenericIndex<Distance>::DistanceType, const ::cvflann::SearchParams&)>("radius_search", &cv::flann::GenericIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method<int(cv::flann::GenericIndex<Distance>::*)(const cv::Mat&, cv::Mat&, cv::Mat&, typename cv::flann::GenericIndex<Distance>::DistanceType, const ::cvflann::SearchParams&)>("radius_search", &cv::flann::GenericIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method<void(cv::flann::GenericIndex<Distance>::*)(cv::String)>("save", &cv::flann::GenericIndex<Distance>::save,
      Arg("filename")).
    template define_method<int(cv::flann::GenericIndex<Distance>::*)() const>("veclen", &cv::flann::GenericIndex<Distance>::veclen).
    template define_method<int(cv::flann::GenericIndex<Distance>::*)() const>("size", &cv::flann::GenericIndex<Distance>::size).
    template define_method<::cvflann::IndexParams(cv::flann::GenericIndex<Distance>::*)()>("get_parameters", &cv::flann::GenericIndex<Distance>::getParameters);
}

