#include <opencv2/flann/autotuned_index.h>
#include "autotuned_index-rb.hpp"

using namespace Rice;

#include "autotuned_index-rb.ipp"

void Init_Flann_AutotunedIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::AutotunedIndexParams> rb_cCvflannAutotunedIndexParams = define_class_under<cvflann::AutotunedIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "AutotunedIndexParams").
    define_constructor(Constructor<cvflann::AutotunedIndexParams, float, float, float, float>(),
      Arg("target_precision") = static_cast<float>(0.8), Arg("build_weight") = static_cast<float>(0.01), Arg("memory_weight") = static_cast<float>(0), Arg("sample_fraction") = static_cast<float>(0.1));
}
