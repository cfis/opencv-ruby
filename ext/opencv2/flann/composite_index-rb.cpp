#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/composite_index.h>
#include "composite_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannCompositeIndexParams;

template<typename Data_Type_T, typename Distance>
inline void CompositeIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::CompositeIndex<Distance>, const typename cvflann::Matrix<typename cvflann::CompositeIndex<Distance>::ElementType>&, const typename cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::CompositeIndexParams()), Arg("d") = static_cast<Distance>(Distance())).
    define_constructor(Constructor<cvflann::CompositeIndex<Distance>, const cvflann::CompositeIndex<Distance>&>(),
      Arg("")).
    template define_method("assign", &cvflann::CompositeIndex<Distance>::operator=,
      Arg("")).
    template define_method("get_type", &cvflann::CompositeIndex<Distance>::getType).
    template define_method("size", &cvflann::CompositeIndex<Distance>::size).
    template define_method("veclen", &cvflann::CompositeIndex<Distance>::veclen).
    template define_method("used_memory", &cvflann::CompositeIndex<Distance>::usedMemory).
    template define_method("build_index", &cvflann::CompositeIndex<Distance>::buildIndex).
    template define_method("save_index", &cvflann::CompositeIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method("load_index", &cvflann::CompositeIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method("get_parameters", &cvflann::CompositeIndex<Distance>::getParameters).
    template define_method("find_neighbors", &cvflann::CompositeIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
};
void Init_CompositeIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannCompositeIndexParams = define_class_under<cvflann::CompositeIndexParams, cvflann::IndexParams>(rb_mCvflann, "CompositeIndexParams").
    define_constructor(Constructor<cvflann::CompositeIndexParams, int, int, int, cvflann::flann_centers_init_t, float>(),
      Arg("trees") = static_cast<int>(4), Arg("branching") = static_cast<int>(32), Arg("iterations") = static_cast<int>(11), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::flann_centers_init_t::FLANN_CENTERS_RANDOM), Arg("cb_index") = static_cast<float>(0.2));

}