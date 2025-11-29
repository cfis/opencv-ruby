#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/kdtree_single_index.h>
#include "kdtree_single_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannKDTreeSingleIndexParams;

template<typename Data_Type_T, typename Distance>
inline void KDTreeSingleIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KDTreeSingleIndex<Distance>, const cvflann::Matrix<typename cvflann::KDTreeSingleIndex<Distance>::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams &>(cvflann::KDTreeSingleIndexParams()), Arg("d") = static_cast<Distance>(Distance())).
    define_constructor(Constructor<cvflann::KDTreeSingleIndex<Distance>, const cvflann::KDTreeSingleIndex<Distance>&>(),
      Arg("")).
    template define_method("assign", &cvflann::KDTreeSingleIndex<Distance>::operator=,
      Arg("")).
    template define_method("build_index", &cvflann::KDTreeSingleIndex<Distance>::buildIndex).
    template define_method("get_type", &cvflann::KDTreeSingleIndex<Distance>::getType).
    template define_method("save_index", &cvflann::KDTreeSingleIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method("load_index", &cvflann::KDTreeSingleIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method("size", &cvflann::KDTreeSingleIndex<Distance>::size).
    template define_method("veclen", &cvflann::KDTreeSingleIndex<Distance>::veclen).
    template define_method("used_memory", &cvflann::KDTreeSingleIndex<Distance>::usedMemory).
    template define_method("knn_search", &cvflann::KDTreeSingleIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method("get_parameters", &cvflann::KDTreeSingleIndex<Distance>::getParameters).
    template define_method("find_neighbors", &cvflann::KDTreeSingleIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
};
void Init_KdtreeSingleIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannKDTreeSingleIndexParams = define_class_under<cvflann::KDTreeSingleIndexParams, cvflann::IndexParams>(rb_mCvflann, "KDTreeSingleIndexParams").
    define_constructor(Constructor<cvflann::KDTreeSingleIndexParams, int, bool, int>(),
      Arg("leaf_max_size") = static_cast<int>(10), Arg("reorder") = static_cast<bool>(true), Arg("dim") = static_cast<int>(-1));

}