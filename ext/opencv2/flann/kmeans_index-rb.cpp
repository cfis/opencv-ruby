#include "kmeans_index-rb.ipp"

void Init_Flann_KmeansIndex()
{
  Class(rb_cObject).define_constant("BITS_PER_CHAR", BITS_PER_CHAR);

  Class(rb_cObject).define_constant("BITS_PER_BASE", BITS_PER_BASE);

  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::KMeansIndexParams> rb_cCvflannKMeansIndexParams = define_class_under<cvflann::KMeansIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "KMeansIndexParams").
    define_constructor(Constructor<cvflann::KMeansIndexParams, int, int, cvflann::flann_centers_init_t, float, int>(),
      Arg("branching") = static_cast<int>(32), Arg("iterations") = static_cast<int>(11), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::FLANN_CENTERS_RANDOM), Arg("cb_index") = static_cast<float>(0.2), Arg("trees") = static_cast<int>(1));
}