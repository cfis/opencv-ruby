#include <opencv2/core/utils/tls.hpp>
#include "tls-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void TLSData_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::TLSData<T>>()).
    template define_method<T*(cv::TLSData<T>::*)() const>("get", &cv::TLSData<T>::get).
    template define_method<T&(cv::TLSData<T>::*)() const>("get_ref", &cv::TLSData<T>::getRef).
    template define_method<void(cv::TLSData<T>::*)()>("cleanup", &cv::TLSData<T>::cleanup);
};

template<typename Data_Type_T, typename T>
inline void TLSDataAccumulator_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::TLSDataAccumulator<T>>()).
    template define_method<void(cv::TLSDataAccumulator<T>::*)(std::vector<T *>&) const>("gather", &cv::TLSDataAccumulator<T>::gather,
      Arg("data")).
    template define_method<std::vector<T *>&(cv::TLSDataAccumulator<T>::*)()>("detach_data", &cv::TLSDataAccumulator<T>::detachData).
    template define_method<void(cv::TLSDataAccumulator<T>::*)()>("cleanup_detached_data", &cv::TLSDataAccumulator<T>::cleanupDetachedData).
    template define_method<void(cv::TLSDataAccumulator<T>::*)()>("cleanup", &cv::TLSDataAccumulator<T>::cleanup).
    template define_method<void(cv::TLSDataAccumulator<T>::*)()>("release", &cv::TLSDataAccumulator<T>::release);
};

