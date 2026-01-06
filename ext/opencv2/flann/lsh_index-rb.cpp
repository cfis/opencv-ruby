#include <opencv2/flann/lsh_index.h>
#include "lsh_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannLshIndexParams;

template<typename Data_Type_T, typename Distance>
inline void LshIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::LshIndex<Distance>, const Matrix<type-parameter-0-0::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::LshIndexParams()), Arg("d") = static_cast<Distance>(cvflann::LshIndex::Distance())).
    define_constructor(Constructor<cvflann::LshIndex<Distance>, const cvflann::LshIndex<Distance>&>(),
      Arg("arg_0")).
    define_method("assign", &cvflann::LshIndex<Distance>::operator=,
      Arg("arg_0")).
    define_method("build_index", &cvflann::LshIndex<Distance>::buildIndex).
    define_method("get_type", &cvflann::LshIndex<Distance>::getType).
    define_method("save_index", &cvflann::LshIndex<Distance>::saveIndex,
      Arg("stream")).
    define_method("load_index", &cvflann::LshIndex<Distance>::loadIndex,
      Arg("stream")).
    define_method("size", &cvflann::LshIndex<Distance>::size).
    define_method("veclen", &cvflann::LshIndex<Distance>::veclen).
    define_method("used_memory", &cvflann::LshIndex<Distance>::usedMemory).
    define_method("get_parameters", &cvflann::LshIndex<Distance>::getParameters).
    define_method("knn_search", &cvflann::LshIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    define_method("find_neighbors", &cvflann::LshIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("arg_2"));
};
void Init_LshIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannLshIndexParams = define_class_under<cvflann::LshIndexParams, cvflann::IndexParams>(rb_mCvflann, "LshIndexParams").
    define_constructor(Constructor<cvflann::LshIndexParams, int, int, int>(),
      Arg("table_number") = static_cast<int>(12), Arg("key_size") = static_cast<int>(20), Arg("multi_probe_level") = static_cast<int>(2));

}