#include <opencv2/features2d.hpp>
#include "features2d-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void SL2_builder(Data_Type_T& klass)
{
  klass.define_constant("NormType", cv::SL2<T>::normType).
    template define_method<typename cv::SL2<T>::ResultType(cv::SL2<T>::*)(const T*, const T*, int) const>("call", &cv::SL2<T>::operator(),
      std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("a"), std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("b"), Arg("size"));
};

template<typename Data_Type_T, typename T>
inline void L2_builder(Data_Type_T& klass)
{
  klass.define_constant("NormType", cv::L2<T>::normType).
    template define_method<typename cv::L2<T>::ResultType(cv::L2<T>::*)(const T*, const T*, int) const>("call", &cv::L2<T>::operator(),
      std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("a"), std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("b"), Arg("size"));
};

template<typename Data_Type_T, typename T>
inline void L1_builder(Data_Type_T& klass)
{
  klass.define_constant("NormType", cv::L1<T>::normType).
    template define_method<typename cv::L1<T>::ResultType(cv::L1<T>::*)(const T*, const T*, int) const>("call", &cv::L1<T>::operator(),
      std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("a"), std::conditional_t<std::is_fundamental_v<const T>, ArgBuffer, Arg>("b"), Arg("size"));
};

