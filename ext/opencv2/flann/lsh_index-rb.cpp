#include <opencv2/flann/lsh_index.h>
#include "lsh_index-rb.hpp"

using namespace Rice;

#include "lsh_index-rb.ipp"

void Init_Flann_LshIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::LshIndexParams> rb_cCvflannLshIndexParams = define_class_under<cvflann::LshIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "LshIndexParams").
    define_constructor(Constructor<cvflann::LshIndexParams, int, int, int>(),
      Arg("table_number") = static_cast<int>(12), Arg("key_size") = static_cast<int>(20), Arg("multi_probe_level") = static_cast<int>(2));
}