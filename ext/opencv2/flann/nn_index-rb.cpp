#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/nn_index.h>
#include "nn_index-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, typename Distance>
inline void NNIndex_builder(Data_Type_T& klass)
{
  klass.template define_method("build_index", &cvflann::NNIndex<Distance>::buildIndex).
    template define_method("knn_search", &cvflann::NNIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method("radius_search", &cvflann::NNIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method("save_index", &cvflann::NNIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method("load_index", &cvflann::NNIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method("size", &cvflann::NNIndex<Distance>::size).
    template define_method("veclen", &cvflann::NNIndex<Distance>::veclen).
    template define_method("used_memory", &cvflann::NNIndex<Distance>::usedMemory).
    template define_method("get_type", &cvflann::NNIndex<Distance>::getType).
    template define_method("get_parameters", &cvflann::NNIndex<Distance>::getParameters).
    template define_method("find_neighbors", &cvflann::NNIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
};
void Init_NnIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  

}