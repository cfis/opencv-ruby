#include <opencv2/core/cuda/detail/type_traits_detail.hpp>
#include "type_traits_detail-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void IsSignedIntergral_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<T>::value);
};

template<typename Data_Type_T, typename T>
inline void IsUnsignedIntegral_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<T>::value);
};

template<typename Data_Type_T, typename T>
inline void IsIntegral_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsIntegral<T>::value);
};

template<typename Data_Type_T, typename T>
inline void IsFloat_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsFloat<T>::value);
};

template<typename Data_Type_T, typename T>
inline void IsVec_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<T>::value);
};

template<typename Data_Type_T, typename U>
inline void ReferenceTraits_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::ReferenceTraits<U>::value);
};

template<typename Data_Type_T, typename U>
inline void PointerTraits_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::PointerTraits<U>::value);
};

template<typename Data_Type_T, typename U>
inline void UnConst_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::UnConst<U>::value);
};

template<typename Data_Type_T, typename U>
inline void UnVolatile_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cuda::device::type_traits_detail::UnVolatile<U>::value);
};

