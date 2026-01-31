#include <opencv2/core/cuda/dynamic_smem.hpp>
#include "dynamic_smem-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void DynamicSharedMem_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::DynamicSharedMem<T>::__forceinline__);
};

