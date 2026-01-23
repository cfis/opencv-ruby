#include <opencv2/flann/kdtree_index.h>
#include "kdtree_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void KDTreeIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KDTreeIndex<Distance>, const Matrix<type-parameter-0-0::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::KDTreeIndexParams()), Arg("d") = static_cast<Distance>(cvflann::KDTreeIndex::Distance())).
    define_constructor(Constructor<cvflann::KDTreeIndex<Distance>, const cvflann::KDTreeIndex<Distance>&>(),
      Arg("arg_0")).
    define_method("assign", &cvflann::KDTreeIndex<Distance>::operator=,
      Arg("arg_0")).
    define_method("build_index", &cvflann::KDTreeIndex<Distance>::buildIndex).
    define_method("get_type", &cvflann::KDTreeIndex<Distance>::getType).
    define_method("save_index", &cvflann::KDTreeIndex<Distance>::saveIndex,
      Arg("stream")).
    define_method("load_index", &cvflann::KDTreeIndex<Distance>::loadIndex,
      Arg("stream")).
    define_method("size", &cvflann::KDTreeIndex<Distance>::size).
    define_method("veclen", &cvflann::KDTreeIndex<Distance>::veclen).
    define_method("used_memory", &cvflann::KDTreeIndex<Distance>::usedMemory).
    define_method("find_neighbors", &cvflann::KDTreeIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    define_method("get_parameters", &cvflann::KDTreeIndex<Distance>::getParameters);
};

void Init_Flann_KdtreeIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::KDTreeIndexParams> rb_cCvflannKDTreeIndexParams = define_class_under<cvflann::KDTreeIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "KDTreeIndexParams").
    define_constructor(Constructor<cvflann::KDTreeIndexParams, int>(),
      Arg("trees") = static_cast<int>(4));
}