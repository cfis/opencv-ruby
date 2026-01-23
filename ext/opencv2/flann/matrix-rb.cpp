#include <opencv2/flann/matrix.h>
#include "matrix-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void Matrix_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cvflann::Matrix<T>::rows).
    define_attr("cols", &cvflann::Matrix<T>::cols).
    define_attr("stride", &cvflann::Matrix<T>::stride).
    define_attr("data", &cvflann::Matrix<T>::data).
    define_constructor(Constructor<cvflann::Matrix<T>>()).
    define_constructor(Constructor<cvflann::Matrix<T>, T*, size_t, size_t, size_t>(),
      Arg("data_"), Arg("rows_"), Arg("cols_"), Arg("stride_") = static_cast<size_t>(0)).
    define_method("[]", &cvflann::Matrix<T>::operator[],
      Arg("index"));
};

void Init_Flann_Matrix()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::UntypedMatrix> rb_cCvflannUntypedMatrix = define_class_under<cvflann::UntypedMatrix>(rb_mCvflann, "UntypedMatrix").
    define_attr("rows", &cvflann::UntypedMatrix::rows).
    define_attr("cols", &cvflann::UntypedMatrix::cols).
    define_attr("data", &cvflann::UntypedMatrix::data).
    define_attr("type", &cvflann::UntypedMatrix::type).
    define_constructor(Constructor<cvflann::UntypedMatrix, void*, long, long>(),
      ArgBuffer("data_"), Arg("rows_"), Arg("cols_"));
}