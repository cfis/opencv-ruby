#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/all_indices.h>
#include "all_indices-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, typename KDTreeCapability, typename VectorSpace, typename Distance>
inline void index_creator_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function("create", &cvflann::index_creator<KDTreeCapability, VectorSpace, Distance>::create,
      Arg("dataset"), Arg("params"), Arg("distance"));
};
void Init_AllIndices()
{
  Module rb_mCvflann = define_module("Cvflann");
  

}