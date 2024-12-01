#include <cstddef>
#include <opencv2/core/cuda_types.hpp>
#include "cuda_types-rb.hpp"

using namespace Rice;

Rice::Class rb_cPtrStepSzb;
Rice::Class rb_cPtrStepSzf;
Rice::Class rb_cPtrStepSzi;
Rice::Class rb_cPtrStepSzus;
Rice::Class rb_cPtrStepb;
Rice::Class rb_cPtrStepf;
Rice::Class rb_cPtrStepi;
Rice::Class rb_cPtrStepus;

template<typename Data_Type_T, typename T>
inline void DevPtr_builder(Data_Type_T& klass)
{
  klass.define_constant("Elem_size", (int)cv::cuda::DevPtr<T>::elem_size).
    define_attr("data", &cv::cuda::DevPtr<T>::data).
    define_constructor(Constructor<cv::cuda::DevPtr<T>>()).
    define_constructor(Constructor<cv::cuda::DevPtr<T>, T*>(),
      Arg("data_")).
    template define_method("elem_size", &cv::cuda::DevPtr<T>::elemSize).
    define_method("to_type_parameter_0_0 *", [](const cv::cuda::DevPtr<T>& self) -> T*
    {
      return self;
    }).
    define_method("to_const type_parameter_0_0 *", [](const cv::cuda::DevPtr<T>& self) -> const T*
    {
      return self;
    });
};

template<typename Data_Type_T, typename T>
inline void PtrSz_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::PtrSz<T>>()).
    define_constructor(Constructor<cv::cuda::PtrSz<T>, T*, size_t>(),
      Arg("data_"), Arg("size_")).
    define_attr("size", &cv::cuda::PtrSz<T>::size);
};

template<typename Data_Type_T, typename T>
inline void PtrStep_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::PtrStep<T>>()).
    define_constructor(Constructor<cv::cuda::PtrStep<T>, T*, size_t>(),
      Arg("data_"), Arg("step_")).
    define_attr("step", &cv::cuda::PtrStep<T>::step).
   //template define_method<T*(cv::cuda::PtrStep<T>::*)(int)>("ptr", &cv::cuda::PtrStep<T>::ptr,
   //   Arg("y") = static_cast<int>(0)).
  //  template define_method<const T*(cv::cuda::PtrStep<T>::*)(int) const>("ptr", &cv::cuda::PtrStep<T>::ptr,
  //    Arg("y") = static_cast<int>(0)).
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
      Arg("rows_"), Arg("cols_"), Arg("data_"), Arg("step_")).
    define_attr("cols", &cv::cuda::PtrStepSz<T>::cols).
    define_attr("rows", &cv::cuda::PtrStepSz<T>::rows);
};
void Init_CudaTypes()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  rb_cPtrStepSzb = define_class_under<cv::cuda::PtrStepSz<unsigned char>, cv::cuda::PtrStep<unsigned char>>(rb_mCvCuda, "PtrStepSzb").
    define(&PtrStepSz_builder<Data_Type<cv::cuda::PtrStepSz<unsigned char>>, unsigned char>);
  
  rb_cPtrStepSzus = define_class_under<cv::cuda::PtrStepSz<unsigned short>, cv::cuda::PtrStep<unsigned short>>(rb_mCvCuda, "PtrStepSzus").
    define(&PtrStepSz_builder<Data_Type<cv::cuda::PtrStepSz<unsigned short>>, unsigned short>);
  
  rb_cPtrStepSzf = define_class_under<cv::cuda::PtrStepSz<float>, cv::cuda::PtrStep<float>>(rb_mCvCuda, "PtrStepSzf").
    define(&PtrStepSz_builder<Data_Type<cv::cuda::PtrStepSz<float>>, float>);
  
  rb_cPtrStepSzi = define_class_under<cv::cuda::PtrStepSz<int>, cv::cuda::PtrStep<int>>(rb_mCvCuda, "PtrStepSzi").
    define(&PtrStepSz_builder<Data_Type<cv::cuda::PtrStepSz<int>>, int>);
  
  rb_cPtrStepb = define_class_under<cv::cuda::PtrStep<unsigned char>, cv::cuda::DevPtr<unsigned char>>(rb_mCvCuda, "PtrStepb").
    define(&PtrStep_builder<Data_Type<cv::cuda::PtrStep<unsigned char>>, unsigned char>);
  
  rb_cPtrStepus = define_class_under<cv::cuda::PtrStep<unsigned short>, cv::cuda::DevPtr<unsigned short>>(rb_mCvCuda, "PtrStepus").
    define(&PtrStep_builder<Data_Type<cv::cuda::PtrStep<unsigned short>>, unsigned short>);
  
  rb_cPtrStepf = define_class_under<cv::cuda::PtrStep<float>, cv::cuda::DevPtr<float>>(rb_mCvCuda, "PtrStepf").
    define(&PtrStep_builder<Data_Type<cv::cuda::PtrStep<float>>, float>);
  
  rb_cPtrStepi = define_class_under<cv::cuda::PtrStep<int>, cv::cuda::DevPtr<int>>(rb_mCvCuda, "PtrStepi").
    define(&PtrStep_builder<Data_Type<cv::cuda::PtrStep<int>>, int>);
}