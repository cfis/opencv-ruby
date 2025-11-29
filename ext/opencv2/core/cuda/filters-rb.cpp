#include <opencv2/core/cuda/filters.hpp>
#include "filters-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, typename Ptr2D>
inline void PointFilter_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::PointFilter<Ptr2D>::__device__);
};

template<typename Data_Type_T, typename Ptr2D>
inline void LinearFilter_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::LinearFilter<Ptr2D>::__device__);
};

template<typename Data_Type_T, typename Ptr2D>
inline void CubicFilter_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::CubicFilter<Ptr2D>::__device__);
};

template<typename Data_Type_T, typename Ptr2D>
inline void IntegerAreaFilter_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::__device__).
    define_attr("scale_x", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale_x).
    define_attr("scale_y", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale_y).
    define_attr("scale", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale);
};

template<typename Data_Type_T, typename Ptr2D>
inline void AreaFilter_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::AreaFilter<Ptr2D>::__device__).
    define_attr("scale_x", &cv::cuda::device::AreaFilter<Ptr2D>::scale_x).
    define_attr("scale_y", &cv::cuda::device::AreaFilter<Ptr2D>::scale_y).
    define_attr("width", &cv::cuda::device::AreaFilter<Ptr2D>::width).
    define_attr("haight", &cv::cuda::device::AreaFilter<Ptr2D>::haight);
};
void Init_Filters()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  

}