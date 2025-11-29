#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/autotuned_index.h>
#include "autotuned_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannAutotunedIndexParams;

template<typename Data_Type_T, typename Distance>
inline void AutotunedIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::AutotunedIndex<Distance>, const cvflann::Matrix<typename cvflann::AutotunedIndex<Distance>::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams &>(cvflann::AutotunedIndexParams()), Arg("d") = static_cast<Distance>(Distance())).
    define_constructor(Constructor<cvflann::AutotunedIndex<Distance>, const cvflann::AutotunedIndex<Distance>&>(),
      Arg("")).
    template define_method("assign", &cvflann::AutotunedIndex<Distance>::operator=,
      Arg("")).
    template define_method("build_index", &cvflann::AutotunedIndex<Distance>::buildIndex).
    template define_method("save_index", &cvflann::AutotunedIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method("load_index", &cvflann::AutotunedIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method("find_neighbors", &cvflann::AutotunedIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    template define_method("get_parameters", &cvflann::AutotunedIndex<Distance>::getParameters).
    template define_method("get_search_parameters", &cvflann::AutotunedIndex<Distance>::getSearchParameters).
    template define_method("get_speedup", &cvflann::AutotunedIndex<Distance>::getSpeedup).
    template define_method("size", &cvflann::AutotunedIndex<Distance>::size).
    template define_method("veclen", &cvflann::AutotunedIndex<Distance>::veclen).
    template define_method("used_memory", &cvflann::AutotunedIndex<Distance>::usedMemory).
    template define_method("get_type", &cvflann::AutotunedIndex<Distance>::getType);
};
void Init_AutotunedIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannAutotunedIndexParams = define_class_under<cvflann::AutotunedIndexParams, cvflann::IndexParams>(rb_mCvflann, "AutotunedIndexParams").
    define_constructor(Constructor<cvflann::AutotunedIndexParams, float, float, float, float>(),
      Arg("target_precision") = static_cast<float>(0.8), Arg("build_weight") = static_cast<float>(0.01), Arg("memory_weight") = static_cast<float>(0), Arg("sample_fraction") = static_cast<float>(0.1));

}