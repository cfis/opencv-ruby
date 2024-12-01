#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/kdtree_index.h>
#include "kdtree_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannKDTreeIndexParams;

template<typename Data_Type_T, typename Distance>
inline void KDTreeIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KDTreeIndex<Distance>, const cvflann::Matrix<typename cvflann::KDTreeIndex<Distance>::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams &>(cvflann::KDTreeIndexParams()), Arg("d") = static_cast<Distance>(Distance())).
    define_constructor(Constructor<cvflann::KDTreeIndex<Distance>, const cvflann::KDTreeIndex<Distance>&>(),
      Arg("")).
    template define_method("assign", &cvflann::KDTreeIndex<Distance>::operator=,
      Arg("")).
    template define_method("build_index", &cvflann::KDTreeIndex<Distance>::buildIndex).
    template define_method("get_type", &cvflann::KDTreeIndex<Distance>::getType).
    template define_method("save_index", &cvflann::KDTreeIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method("load_index", &cvflann::KDTreeIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method("size", &cvflann::KDTreeIndex<Distance>::size).
    template define_method("veclen", &cvflann::KDTreeIndex<Distance>::veclen).
    template define_method("used_memory", &cvflann::KDTreeIndex<Distance>::usedMemory).
    template define_method("find_neighbors", &cvflann::KDTreeIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    template define_method("get_parameters", &cvflann::KDTreeIndex<Distance>::getParameters);
};
void Init_KdtreeIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannKDTreeIndexParams = define_class_under<cvflann::KDTreeIndexParams, cvflann::IndexParams>(rb_mCvflann, "KDTreeIndexParams").
    define_constructor(Constructor<cvflann::KDTreeIndexParams, int>(),
      Arg("trees") = static_cast<int>(4));

}