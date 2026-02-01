template<int T>
inline Rice::Data_Type<cv::optflow::GPCForest<T>> GPCForest_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::optflow::GPCForest<T>>(parent, name).
    template define_method<void(cv::optflow::GPCForest<T>::*)(cv::optflow::GPCTrainingSamples&, const cv::optflow::GPCTrainingParams)>("train", &cv::optflow::GPCForest<T>::train,
      Arg("samples"), Arg("params") = static_cast<const cv::optflow::GPCTrainingParams>(cv::optflow::GPCTrainingParams())).
    template define_method<void(cv::optflow::GPCForest<T>::*)(const std::vector<std::basic_string<char>>&, const std::vector<std::basic_string<char>>&, const std::vector<std::basic_string<char>>&, const cv::optflow::GPCTrainingParams)>("train", &cv::optflow::GPCForest<T>::train,
      Arg("images_from"), Arg("images_to"), Arg("gt"), Arg("params") = static_cast<const cv::optflow::GPCTrainingParams>(cv::optflow::GPCTrainingParams())).
    template define_method<void(cv::optflow::GPCForest<T>::*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, const cv::optflow::GPCTrainingParams)>("train", &cv::optflow::GPCForest<T>::train,
      Arg("images_from"), Arg("images_to"), Arg("gt"), Arg("params") = static_cast<const cv::optflow::GPCTrainingParams>(cv::optflow::GPCTrainingParams())).
    template define_method<void(cv::optflow::GPCForest<T>::*)(cv::FileStorage&) const>("write", &cv::optflow::GPCForest<T>::write,
      Arg("fs")).
    template define_method<void(cv::optflow::GPCForest<T>::*)(const cv::FileNode&)>("read", &cv::optflow::GPCForest<T>::read,
      Arg("fn")).
    template define_method<void(cv::optflow::GPCForest<T>::*)(cv::InputArray, cv::InputArray, std::vector<std::pair<cv::Point_<int>, cv::Point_<int>>>&, const cv::optflow::GPCMatchingParams) const>("find_correspondences", &cv::optflow::GPCForest<T>::findCorrespondences,
      Arg("img_from"), Arg("img_to"), Arg("corr"), Arg("params") = static_cast<const cv::optflow::GPCMatchingParams>(cv::optflow::GPCMatchingParams())).
    template define_singleton_function<cv::Ptr<GPCForest<T>>(*)()>("create", &cv::optflow::GPCForest<T>::create);
}

