#include <opencv2/core/cuda/vec_distance.hpp>
#include "vec_distance-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void L1Dist_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::L1Dist<T>>()).
    template define_method<void(cv::cuda::device::L1Dist<T>::*)(int, int)>("reduce_iter", &cv::cuda::device::L1Dist<T>::reduceIter,
      Arg("val1"), Arg("val2")).
    define_method("to_i", [](const cv::cuda::device::L1Dist<T>& self) -> int
    {
      return self;
    }).
    define_attr("my_sum", &cv::cuda::device::L1Dist<T>::mySum);
};

template<typename Data_Type_T, int THREAD_DIM, typename T1>
inline void VecDiffGlobal_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::VecDiffGlobal<THREAD_DIM, T1>, const T1*, int, void*, int, int>(),
      std::conditional_t<std::is_fundamental_v<const T1>, ArgBuffer, Arg>("vec1_"), Arg("arg_1") = static_cast<int>(0), ArgBuffer("arg_2") = static_cast<void*>(0), Arg("arg_3") = static_cast<int>(0), Arg("arg_4") = static_cast<int>(0)).
    define_attr("vec1", &cv::cuda::device::VecDiffGlobal<THREAD_DIM, T1>::vec1);
};

template<typename Data_Type_T, int THREAD_DIM, int MAX_LEN, bool LEN_EQ_MAX_LEN, typename U>
inline void VecDiffCachedRegister_builder(Data_Type_T& klass)
{
  klass.define_attr("vec1_vals", &cv::cuda::device::VecDiffCachedRegister<THREAD_DIM, MAX_LEN, LEN_EQ_MAX_LEN, U>::vec1Vals, Rice::AttrAccess::Read);
};

