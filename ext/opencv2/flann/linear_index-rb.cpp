#include <opencv2/flann/linear_index.h>
#include "linear_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannLinearIndexParams;

template<typename Data_Type_T, typename Distance>
inline void LinearIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::LinearIndex<Distance>, const Matrix<type-parameter-0-0::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams&>(cvflann::LinearIndexParams()), Arg("d") = static_cast<Distance>(cvflann::LinearIndex::Distance())).
    define_constructor(Constructor<cvflann::LinearIndex<Distance>, const cvflann::LinearIndex<Distance>&>(),
      Arg("arg_0")).
    define_method("assign", &cvflann::LinearIndex<Distance>::operator=,
      Arg("arg_0")).
    define_method("get_type", &cvflann::LinearIndex<Distance>::getType).
    define_method("size", &cvflann::LinearIndex<Distance>::size).
    define_method("veclen", &cvflann::LinearIndex<Distance>::veclen).
    define_method("used_memory", &cvflann::LinearIndex<Distance>::usedMemory).
    define_method("build_index", &cvflann::LinearIndex<Distance>::buildIndex).
    define_method("save_index", &cvflann::LinearIndex<Distance>::saveIndex,
      Arg("arg_0")).
    define_method("load_index", &cvflann::LinearIndex<Distance>::loadIndex,
      Arg("arg_0")).
    define_method("find_neighbors", &cvflann::LinearIndex<Distance>::findNeighbors,
      Arg("result_set"), Arg("vec"), Arg("arg_2")).
    define_method("get_parameters", &cvflann::LinearIndex<Distance>::getParameters);
};
void Init_LinearIndex()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannLinearIndexParams = define_class_under<cvflann::LinearIndexParams, cvflann::IndexParams>(rb_mCvflann, "LinearIndexParams").
    define_constructor(Constructor<cvflann::LinearIndexParams>());

}