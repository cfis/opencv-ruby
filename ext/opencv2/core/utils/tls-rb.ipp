template<typename T>
inline Rice::Data_Type<cv::TLSData<T>> TLSData_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::TLSData<T>>(parent, name).
    define_constructor(Constructor<cv::TLSData<T>>()).
    template define_method<T*(cv::TLSData<T>::*)() const>("get", &cv::TLSData<T>::get).
    template define_method<T&(cv::TLSData<T>::*)() const>("get_ref", &cv::TLSData<T>::getRef).
    template define_method<void(cv::TLSData<T>::*)()>("cleanup", &cv::TLSData<T>::cleanup);
}

template<typename T>
inline Rice::Data_Type<cv::TLSDataAccumulator<T>> TLSDataAccumulator_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::TLSDataAccumulator<T>>(parent, name).
    define_constructor(Constructor<cv::TLSDataAccumulator<T>>()).
    template define_method<void(cv::TLSDataAccumulator<T>::*)(std::vector<T *>&) const>("gather", &cv::TLSDataAccumulator<T>::gather,
      Arg("data")).
    template define_method<std::vector<T *>&(cv::TLSDataAccumulator<T>::*)()>("detach_data", &cv::TLSDataAccumulator<T>::detachData).
    template define_method<void(cv::TLSDataAccumulator<T>::*)()>("cleanup_detached_data", &cv::TLSDataAccumulator<T>::cleanupDetachedData).
    template define_method<void(cv::TLSDataAccumulator<T>::*)()>("cleanup", &cv::TLSDataAccumulator<T>::cleanup).
    template define_method<void(cv::TLSDataAccumulator<T>::*)()>("release", &cv::TLSDataAccumulator<T>::release);
}

