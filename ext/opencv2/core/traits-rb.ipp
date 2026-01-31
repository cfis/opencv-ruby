#include <opencv2/core/traits.hpp>
#include "traits-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp>
inline void DataDepth_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::DataDepth<_Tp>::value).
    define_constant("Fmt", (int)cv::DataDepth<_Tp>::fmt);
};

template<typename Data_Type_T, typename T>
inline void CheckMember_fmt_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::traits::internal::CheckMember_fmt<T>::value);
};

template<typename Data_Type_T, typename T>
inline void CheckMember_type_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::traits::internal::CheckMember_type<T>::value);
};

template<typename Data_Type_T, typename T>
inline void Depth_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::traits::Depth<T>::value);
};

template<typename Data_Type_T, typename T>
inline void Type_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::traits::Type<T>::value);
};

