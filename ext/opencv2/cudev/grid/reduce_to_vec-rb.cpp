#include <opencv2/cudev/grid/reduce_to_vec.hpp>
#include "reduce_to_vec-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void Sum_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<T(*)()>("initial_value", &cv::cudev::Sum<T>::initialValue).
    template define_singleton_function<T(*)(T, int)>("result", &cv::cudev::Sum<T>::result,
      Arg("r"), Arg("arg_1"));
};

template<typename Data_Type_T, typename T>
inline void Avg_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<T(*)()>("initial_value", &cv::cudev::Avg<T>::initialValue).
    template define_singleton_function<T(*)(T, float)>("result", &cv::cudev::Avg<T>::result,
      Arg("r"), Arg("sz"));
};

template<typename Data_Type_T, typename T>
inline void Min_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<T(*)()>("initial_value", &cv::cudev::Min<T>::initialValue).
    template define_singleton_function<T(*)(T, int)>("result", &cv::cudev::Min<T>::result,
      Arg("r"), Arg("arg_1"));
};

template<typename Data_Type_T, typename T>
inline void Max_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<T(*)()>("initial_value", &cv::cudev::Max<T>::initialValue).
    template define_singleton_function<T(*)(T, int)>("result", &cv::cudev::Max<T>::result,
      Arg("r"), Arg("arg_1"));
};

void Init_Cudev_Grid_ReduceToVec()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DefaultReduceToVecPolicy> rb_cCvCudevDefaultReduceToVecPolicy = define_class_under<cv::cudev::DefaultReduceToVecPolicy>(rb_mCvCudev, "DefaultReduceToVecPolicy").
    define_constructor(Constructor<cv::cudev::DefaultReduceToVecPolicy>());

  rb_cCvCudevDefaultReduceToVecPolicy.define_constant("Block_size_x", (int)cv::cudev::DefaultReduceToVecPolicy::block_size_x);
  rb_cCvCudevDefaultReduceToVecPolicy.define_constant("Block_size_y", (int)cv::cudev::DefaultReduceToVecPolicy::block_size_y);
}