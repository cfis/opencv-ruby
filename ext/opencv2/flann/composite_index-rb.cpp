#include <opencv2/flann/composite_index.h>
#include "composite_index-rb.hpp"

using namespace Rice;

#include "composite_index-rb.ipp"

void Init_Flann_CompositeIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::CompositeIndexParams> rb_cCvflannCompositeIndexParams = define_class_under<cvflann::CompositeIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "CompositeIndexParams").
    define_constructor(Constructor<cvflann::CompositeIndexParams, int, int, int, cvflann::flann_centers_init_t, float>(),
      Arg("trees") = static_cast<int>(4), Arg("branching") = static_cast<int>(32), Arg("iterations") = static_cast<int>(11), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::FLANN_CENTERS_RANDOM), Arg("cb_index") = static_cast<float>(0.2));
}