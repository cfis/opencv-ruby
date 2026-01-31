#include <opencv2/core/cuda/detail/color_detail.hpp>
#include "color_detail-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void ColorChannel_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<T(*)()>("max", &cv::cuda::device::color_detail::ColorChannel<T>::max).
    template define_singleton_function<T(*)()>("half", &cv::cuda::device::color_detail::ColorChannel<T>::half);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int dcn>
inline void Gray2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::Gray2RGB<T, dcn>::*)(T) const>("call", &cv::cuda::device::color_detail::Gray2RGB<T, dcn>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB<T, dcn>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB<T, dcn>, const cv::cuda::device::color_detail::Gray2RGB<T, dcn>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, int green_bits>
inline void Gray2RGB5x5_builder(Data_Type_T& klass)
{
  klass.template define_method<ushort(cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>::*)(uint) const>("call", &cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>, const cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, int green_bits>
inline void RGB5x52Gray_builder(Data_Type_T& klass)
{
  klass.template define_method<uchar(cv::cuda::device::color_detail::RGB5x52Gray<green_bits>::*)(uint) const>("call", &cv::cuda::device::color_detail::RGB5x52Gray<green_bits>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52Gray<green_bits>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52Gray<green_bits>, const cv::cuda::device::color_detail::RGB5x52Gray<green_bits>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int bidx>
inline void RGB2Gray_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>, const cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2YUV_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void YUV2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2YCrCb_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void YCrCb2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2XYZ_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void XYZ2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>, const cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void RGB2HSV_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>, const cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void HSV2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>, const cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void RGB2HLS_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>, const cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>&>(),
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void HLS2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename TypeVec<T, dcn>::vec_type(cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>::*)(const typename TypeVec<T, scn>::vec_type&) const>("call", &cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>::operator(),
      Arg("src")).
    define_constructor(Constructor<cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>, const cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>&>(),
      Arg("arg_0"));
};

