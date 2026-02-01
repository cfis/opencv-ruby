#include <opencv2/flann/kdtree_index.h>
#include "kdtree_index-rb.hpp"

using namespace Rice;

#include "kdtree_index-rb.ipp"

void Init_Flann_KdtreeIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::KDTreeIndexParams> rb_cCvflannKDTreeIndexParams = define_class_under<cvflann::KDTreeIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "KDTreeIndexParams").
    define_constructor(Constructor<cvflann::KDTreeIndexParams, int>(),
      Arg("trees") = static_cast<int>(4));
}