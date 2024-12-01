#include <opencv2/core/cuda/border_interpolate.hpp>
#include "border_interpolate-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, typename D>
inline void BrdRowConstant_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdRowConstant<D>::__device__).
    define_attr("val", &cv::cuda::device::BrdRowConstant<D>::val);
};

template<typename Data_Type_T, typename D>
inline void BrdColConstant_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdColConstant<D>::__device__).
    define_attr("val", &cv::cuda::device::BrdColConstant<D>::val);
};

template<typename Data_Type_T, typename D>
inline void BrdConstant_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdConstant<D>::__device__).
    define_attr("width", &cv::cuda::device::BrdConstant<D>::width).
    define_attr("val", &cv::cuda::device::BrdConstant<D>::val);
};

template<typename Data_Type_T, typename D>
inline void BrdRowReplicate_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdRowReplicate<D>::__device__);
};

template<typename Data_Type_T, typename D>
inline void BrdColReplicate_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdColReplicate<D>::__device__);
};

template<typename Data_Type_T, typename D>
inline void BrdReplicate_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdReplicate<D>::__device__).
    define_attr("last_col", &cv::cuda::device::BrdReplicate<D>::last_col);
};

template<typename Data_Type_T, typename D>
inline void BrdRowReflect101_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdRowReflect101<D>::__device__);
};

template<typename Data_Type_T, typename D>
inline void BrdColReflect101_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdColReflect101<D>::__device__);
};

template<typename Data_Type_T, typename D>
inline void BrdReflect101_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdReflect101<D>::__device__).
    define_attr("last_col", &cv::cuda::device::BrdReflect101<D>::last_col);
};

template<typename Data_Type_T, typename D>
inline void BrdRowReflect_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdRowReflect<D>::__device__);
};

template<typename Data_Type_T, typename D>
inline void BrdColReflect_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdColReflect<D>::__device__);
};

template<typename Data_Type_T, typename D>
inline void BrdReflect_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdReflect<D>::__device__).
    define_attr("last_col", &cv::cuda::device::BrdReflect<D>::last_col);
};

template<typename Data_Type_T, typename D>
inline void BrdRowWrap_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdRowWrap<D>::__device__);
};

template<typename Data_Type_T, typename D>
inline void BrdColWrap_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdColWrap<D>::__device__);
};

template<typename Data_Type_T, typename D>
inline void BrdWrap_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BrdWrap<D>::__device__).
    define_attr("width", &cv::cuda::device::BrdWrap<D>::width);
};

template<typename Data_Type_T, typename Ptr2D, typename B>
inline void BorderReader_builder(Data_Type_T& klass)
{
  klass.define_attr("__device__", &cv::cuda::device::BorderReader<Ptr2D, B>::__device__).
    define_attr("b", &cv::cuda::device::BorderReader<Ptr2D, B>::b);
};
void Init_BorderInterpolate()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  

}