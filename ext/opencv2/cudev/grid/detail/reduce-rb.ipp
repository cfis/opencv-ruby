#include <opencv2/cudev/grid/detail/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename src_type, typename work_type>
inline void SumReductor_builder(Data_Type_T& klass)
{
  klass.define_constant("Cn", (int)cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>::cn).
    define_attr("sum", &cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>::sum).
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>>()).
    template define_method<void(cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>::*)(typename TypeTraits<src_type>::parameter_type)>("reduce_val", &cv::cudev::grid_reduce_detail::SumReductor<src_type, work_type>::reduceVal,
      Arg("src_val"));
};

template<typename Data_Type_T, typename T>
inline void minop_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<T(*)()>("initial", &cv::cudev::grid_reduce_detail::minop<T>::initial).
    template define_singleton_function<void(*)(T*, T)>("atomic", &cv::cudev::grid_reduce_detail::minop<T>::atomic,
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("result"), Arg("myval"));
};

template<typename Data_Type_T, typename T>
inline void maxop_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<T(*)()>("initial", &cv::cudev::grid_reduce_detail::maxop<T>::initial).
    template define_singleton_function<void(*)(T*, T)>("atomic", &cv::cudev::grid_reduce_detail::maxop<T>::atomic,
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("result"), Arg("myval"));
};

template<typename Data_Type_T, typename Op, typename src_type, typename work_type>
inline void MinMaxReductor_builder(Data_Type_T& klass)
{
  klass.define_attr("myval", &cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>::myval).
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>>()).
    template define_method<void(cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>::*)(typename TypeTraits<src_type>::parameter_type)>("reduce_val", &cv::cudev::grid_reduce_detail::MinMaxReductor<Op, src_type, work_type>::reduceVal,
      Arg("src_val"));
};

