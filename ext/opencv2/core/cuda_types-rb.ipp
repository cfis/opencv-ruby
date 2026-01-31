#include <opencv2/core/cuda_types.hpp>
#include "cuda_types-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void DevPtr_builder(Data_Type_T& klass)
{
  klass.define_constant("Elem_size", (int)cv::cuda::DevPtr<T>::elem_size).
    define_attr("data", &cv::cuda::DevPtr<T>::data).
    define_constructor(Constructor<cv::cuda::DevPtr<T>>()).
    define_constructor(Constructor<cv::cuda::DevPtr<T>, T*>(),
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_")).
    template define_method<size_t(cv::cuda::DevPtr<T>::*)() const>("elem_size", &cv::cuda::DevPtr<T>::elemSize).
    define_method("to_ptr", [](cv::cuda::DevPtr<T>& self) -> T*
    {
      return self;
    }).
    define_method("to_const_ptr", [](const cv::cuda::DevPtr<T>& self) -> const T*
    {
      return self;
    });
};

template<typename Data_Type_T, typename T>
inline void PtrSz_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::PtrSz<T>>()).
    define_constructor(Constructor<cv::cuda::PtrSz<T>, T*, size_t>(),
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_"), Arg("size_")).
    define_attr("size", &cv::cuda::PtrSz<T>::size);
};

template<typename Data_Type_T, typename T>
inline void PtrStep_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::PtrStep<T>>()).
    define_constructor(Constructor<cv::cuda::PtrStep<T>, T*, size_t>(),
      std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_"), Arg("step_")).
    define_attr("step", &cv::cuda::PtrStep<T>::step).
    template define_method<T*(cv::cuda::PtrStep<T>::*)(int)>("ptr", &cv::cuda::PtrStep<T>::ptr,
      Arg("y") = static_cast<int>(0)).
    template define_method<const T*(cv::cuda::PtrStep<T>::*)(int) const>("ptr", &cv::cuda::PtrStep<T>::ptr,
      Arg("y") = static_cast<int>(0)).
    template define_method<T&(cv::cuda::PtrStep<T>::*)(int, int)>("call", &cv::cuda::PtrStep<T>::operator(),
      Arg("y"), Arg("x")).
    template define_method<const T&(cv::cuda::PtrStep<T>::*)(int, int) const>("call", &cv::cuda::PtrStep<T>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename T>
inline void PtrStepSz_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::PtrStepSz<T>>()).
    define_constructor(Constructor<cv::cuda::PtrStepSz<T>, int, int, T*, size_t>(),
      Arg("rows_"), Arg("cols_"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data_"), Arg("step_")).
    define_attr("cols", &cv::cuda::PtrStepSz<T>::cols).
    define_attr("rows", &cv::cuda::PtrStepSz<T>::rows).
    template define_method<cv::Size(cv::cuda::PtrStepSz<T>::*)() const>("size", &cv::cuda::PtrStepSz<T>::size).
    template define_method<T&(cv::cuda::PtrStepSz<T>::*)(const cv::Point&)>("call", &cv::cuda::PtrStepSz<T>::operator(),
      Arg("pos")).
    template define_method<const T&(cv::cuda::PtrStepSz<T>::*)(const cv::Point&) const>("call", &cv::cuda::PtrStepSz<T>::operator(),
      Arg("pos"));
};

