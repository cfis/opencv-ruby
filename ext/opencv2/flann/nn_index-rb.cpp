#include <opencv2/flann/nn_index.h>
#include "nn_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void NNIndex_builder(Data_Type_T& klass)
{
  klass.define_method("build_index", &cvflann::NNIndex<Distance>::buildIndex).
    define_method("knn_search", &cvflann::NNIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    define_method("radius_search", &cvflann::NNIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    define_method("save_index", &cvflann::NNIndex<Distance>::saveIndex,
      Arg("stream")).
    define_method("load_index", &cvflann::NNIndex<Distance>::loadIndex,
      Arg("stream")).
    define_method("size", &cvflann::NNIndex<Distance>::size).
    define_method("veclen", &cvflann::NNIndex<Distance>::veclen).
    define_method("used_memory", &cvflann::NNIndex<Distance>::usedMemory).
    define_method("get_type", &cvflann::NNIndex<Distance>::getType).
    define_method("get_parameters", &cvflann::NNIndex<Distance>::getParameters).
    define_method("find_neighbors", &cvflann::NNIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
};

void Init_Flann_NnIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
}