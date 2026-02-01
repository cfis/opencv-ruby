#include <opencv2/flann/kdtree_single_index.h>
#include "kdtree_single_index-rb.hpp"

using namespace Rice;

#include "kdtree_single_index-rb.ipp"

void Init_Flann_KdtreeSingleIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::KDTreeSingleIndexParams> rb_cCvflannKDTreeSingleIndexParams = define_class_under<cvflann::KDTreeSingleIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "KDTreeSingleIndexParams").
    define_constructor(Constructor<cvflann::KDTreeSingleIndexParams, int, bool, int>(),
      Arg("leaf_max_size") = static_cast<int>(10), Arg("reorder") = static_cast<bool>(true), Arg("dim") = static_cast<int>(-1));
}