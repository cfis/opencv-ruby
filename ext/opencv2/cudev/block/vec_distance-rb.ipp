#include <opencv2/cudev/block/vec_distance.hpp>
#include "vec_distance-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void NormL1_builder(Data_Type_T& klass)
{
  klass.define_attr("my_sum", &cv::cudev::NormL1<T>::mySum).
    define_constructor(Constructor<cv::cudev::NormL1<T>>()).
    template define_method<void(cv::cudev::NormL1<T>::*)(typename cv::cudev::NormL1<T>::value_type, typename cv::cudev::NormL1<T>::value_type)>("reduce_thread", &cv::cudev::NormL1<T>::reduceThread,
      Arg("val1"), Arg("val2")).
    template define_method<void(cv::cudev::NormL1<T>::*)(typename cv::cudev::NormL1<T>::result_type*, uint)>("reduce_warp", &cv::cudev::NormL1<T>::reduceWarp,
      ArgBuffer("smem"), Arg("tid")).
    define_method("to_result_type", [](const cv::cudev::NormL1<T>& self) -> typename cv::cudev::NormL1<T>::result_type
    {
      return self;
    });
};

