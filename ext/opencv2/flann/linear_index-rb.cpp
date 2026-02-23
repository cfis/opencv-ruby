#include <opencv2/flann/linear_index.h>
#include "linear_index-rb.hpp"

using namespace Rice;

#include "linear_index-rb.ipp"

void Init_Flann_LinearIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::LinearIndexParams> rb_cCvflannLinearIndexParams = define_class_under<cvflann::LinearIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "LinearIndexParams").
    define_constructor(Constructor<cvflann::LinearIndexParams>());
}
