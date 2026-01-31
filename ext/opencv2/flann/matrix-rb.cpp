#include "matrix-rb.ipp"

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