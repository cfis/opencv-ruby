#include <opencv2/flann/autotuned_index.h>
#include "autotuned_index-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void AutotunedIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::AutotunedIndex<Distance>, const Matrix<type-parameter-0-0::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::AutotunedIndexParams()), Arg("d") = static_cast<Distance>(cvflann::AutotunedIndex::Distance())).
    define_constructor(Constructor<cvflann::AutotunedIndex<Distance>, const cvflann::AutotunedIndex<Distance>&>(),
      Arg("arg_0")).
    define_method("assign", &cvflann::AutotunedIndex<Distance>::operator=,
      Arg("arg_0")).
    define_method("build_index", &cvflann::AutotunedIndex<Distance>::buildIndex).
    define_method("save_index", &cvflann::AutotunedIndex<Distance>::saveIndex,
      Arg("stream")).
    define_method("load_index", &cvflann::AutotunedIndex<Distance>::loadIndex,
      Arg("stream")).
    define_method("find_neighbors", &cvflann::AutotunedIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    define_method("get_parameters", &cvflann::AutotunedIndex<Distance>::getParameters).
    define_method("get_search_parameters", &cvflann::AutotunedIndex<Distance>::getSearchParameters).
    define_method("get_speedup", &cvflann::AutotunedIndex<Distance>::getSpeedup).
    define_method("size", &cvflann::AutotunedIndex<Distance>::size).
    define_method("veclen", &cvflann::AutotunedIndex<Distance>::veclen).
    define_method("used_memory", &cvflann::AutotunedIndex<Distance>::usedMemory).
    define_method("get_type", &cvflann::AutotunedIndex<Distance>::getType);
};

void Init_Flann_AutotunedIndex()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::AutotunedIndexParams> rb_cCvflannAutotunedIndexParams = define_class_under<cvflann::AutotunedIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "AutotunedIndexParams").
    define_constructor(Constructor<cvflann::AutotunedIndexParams, float, float, float, float>(),
      Arg("target_precision") = static_cast<float>(0.8), Arg("build_weight") = static_cast<float>(0.01), Arg("memory_weight") = static_cast<float>(0), Arg("sample_fraction") = static_cast<float>(0.1));
}