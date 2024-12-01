#include <opencv2/core/cuda/detail/vec_distance_detail.hpp>
#include "vec_distance_detail-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, int THREAD_DIM, int N>
inline void UnrollVecDiffCached_builder(Data_Type_T& klass)
{
};
void Init_VecDistanceDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceVecDistanceDetail = define_module_under(rb_mCvCudaDevice, "VecDistanceDetail");
  

}