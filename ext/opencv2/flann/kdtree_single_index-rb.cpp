#include <opencv2/flann/kdtree_single_index.h>
#include "kdtree_single_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void KDTreeSingleIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KDTreeSingleIndex<Distance>, const Matrix<type-parameter-0-0::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::KDTreeSingleIndexParams()), Arg("d") = static_cast<Distance>(cvflann::KDTreeSingleIndex::Distance())).
    define_constructor(Constructor<cvflann::KDTreeSingleIndex<Distance>, const cvflann::KDTreeSingleIndex<Distance>&>(),
      Arg("arg_0")).
    define_method("assign", &cvflann::KDTreeSingleIndex<Distance>::operator=,
      Arg("arg_0")).
    define_method("build_index", &cvflann::KDTreeSingleIndex<Distance>::buildIndex).
    define_method("get_type", &cvflann::KDTreeSingleIndex<Distance>::getType).
    define_method("save_index", &cvflann::KDTreeSingleIndex<Distance>::saveIndex,
      Arg("stream")).
    define_method("load_index", &cvflann::KDTreeSingleIndex<Distance>::loadIndex,
      Arg("stream")).
    define_method("size", &cvflann::KDTreeSingleIndex<Distance>::size).
    define_method("veclen", &cvflann::KDTreeSingleIndex<Distance>::veclen).
    define_method("used_memory", &cvflann::KDTreeSingleIndex<Distance>::usedMemory).
    define_method("knn_search", &cvflann::KDTreeSingleIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    define_method("get_parameters", &cvflann::KDTreeSingleIndex<Distance>::getParameters).
    define_method("find_neighbors", &cvflann::KDTreeSingleIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
};

void Init_Flann_KdtreeSingleIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::KDTreeSingleIndexParams> rb_cCvflannKDTreeSingleIndexParams = define_class_under<cvflann::KDTreeSingleIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "KDTreeSingleIndexParams").
    define_constructor(Constructor<cvflann::KDTreeSingleIndexParams, int, bool, int>(),
      Arg("leaf_max_size") = static_cast<int>(10), Arg("reorder") = static_cast<bool>(true), Arg("dim") = static_cast<int>(-1));
}