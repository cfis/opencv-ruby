#include <opencv2/core.hpp>
#include <opencv2/core/utils/tls.hpp>
#include "tls-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvTLSDataContainer;

template<typename Data_Type_T, typename T>
inline void TLSData_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::TLSData::TLSData<T>>()).
    template define_method("get", &cv::TLSData<T>::get).
    template define_method("get_ref", &cv::TLSData<T>::getRef).
    template define_method("cleanup", &cv::TLSData<T>::cleanup);
};

template<typename Data_Type_T, typename T>
inline void TLSDataAccumulator_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::TLSDataAccumulator::TLSDataAccumulator<T>>()).
    template define_method("gather", &cv::TLSDataAccumulator<T>::gather,
      Arg("data")).
    template define_method("detach_data", &cv::TLSDataAccumulator<T>::detachData).
    template define_method("cleanup_detached_data", &cv::TLSDataAccumulator<T>::cleanupDetachedData).
    template define_method("cleanup", &cv::TLSDataAccumulator<T>::cleanup).
    template define_method("release", &cv::TLSDataAccumulator<T>::release);
};

void Init_Tls()
{
  Module rb_mCv = define_module("Cv");
  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");
    
  rb_cCvTLSDataContainer = define_class_under<cv::TLSDataContainer>(rb_mCv, "TLSDataContainer").
    define_method("cleanup", &cv::TLSDataContainer::cleanup);
}