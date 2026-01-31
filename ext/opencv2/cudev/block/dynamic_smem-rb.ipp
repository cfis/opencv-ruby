#include <opencv2/cudev/block/dynamic_smem.hpp>
#include "dynamic_smem-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void DynamicSharedMem_builder(Data_Type_T& klass)
{
  klass.define_method("to_ptr", [](cv::cudev::DynamicSharedMem<T>& self) -> T*
    {
      return self;
    }).
    define_method("to_const_ptr", [](const cv::cudev::DynamicSharedMem<T>& self) -> const T*
    {
      return self;
    });
};

