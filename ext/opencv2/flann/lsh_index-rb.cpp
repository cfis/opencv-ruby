#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/lsh_index.h>
#include "lsh_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannLshIndexParams;

template<typename Data_Type_T, typename Distance>
inline void LshIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::LshIndex<Distance>, const cvflann::Matrix<typename cvflann::LshIndex<Distance>::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams &>(cvflann::LshIndexParams()), Arg("d") = static_cast<Distance>(Distance())).
    define_constructor(Constructor<cvflann::LshIndex<Distance>, const cvflann::LshIndex<Distance>&>(),
      Arg("")).
    template define_method("assign", &cvflann::LshIndex<Distance>::operator=,
      Arg("")).
    template define_method("build_index", &cvflann::LshIndex<Distance>::buildIndex).
    template define_method("get_type", &cvflann::LshIndex<Distance>::getType).
    template define_method("save_index", &cvflann::LshIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method("load_index", &cvflann::LshIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method("size", &cvflann::LshIndex<Distance>::size).
    template define_method("veclen", &cvflann::LshIndex<Distance>::veclen).
    template define_method("used_memory", &cvflann::LshIndex<Distance>::usedMemory).
    template define_method("get_parameters", &cvflann::LshIndex<Distance>::getParameters).
    template define_method("knn_search", &cvflann::LshIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method("find_neighbors", &cvflann::LshIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg(""));
};
void Init_LshIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannLshIndexParams = define_class_under<cvflann::LshIndexParams, cvflann::IndexParams>(rb_mCvflann, "LshIndexParams").
    define_constructor(Constructor<cvflann::LshIndexParams, int, int, int>(),
      Arg("table_number") = static_cast<int>(12), Arg("key_size") = static_cast<int>(20), Arg("multi_probe_level") = static_cast<int>(2));

}