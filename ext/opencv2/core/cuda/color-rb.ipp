#include <opencv2/core/cuda/color.hpp>
#include "color-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void bgr_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void gray_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::gray_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::gray_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void gray_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::gray_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::gray_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_gray_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_gray_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_gray_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_gray_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_gray_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_gray_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_gray_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_gray_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_gray_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_gray_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_gray_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_gray_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_yuv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_yuv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_yuv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_yuv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_yuv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_yuv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_yuv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_yuv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_yuv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_yuv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_yuv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_yuv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_yuv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_yuv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_yuv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_yuv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_yuv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_yuv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_yuv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_yuv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_yuv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_yuv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_yuv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_yuv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void yuv_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::yuv_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void yuv_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::yuv_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void yuv4_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::yuv4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv4_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void yuv4_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::yuv4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv4_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void yuv_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::yuv_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void yuv_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::yuv_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void yuv4_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::yuv4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv4_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void yuv4_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::yuv4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv4_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_YCrCb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_YCrCb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_YCrCb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_YCrCb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_YCrCb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_YCrCb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_YCrCb4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_YCrCb4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_YCrCb4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_YCrCb4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_YCrCb4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_YCrCb4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_YCrCb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_YCrCb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_YCrCb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_YCrCb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_YCrCb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_YCrCb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_YCrCb4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_YCrCb4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_YCrCb4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_YCrCb4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_YCrCb4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_YCrCb4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void YCrCb_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::YCrCb_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void YCrCb_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::YCrCb_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void YCrCb4_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::YCrCb4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb4_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void YCrCb4_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::YCrCb4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb4_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void YCrCb_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::YCrCb_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void YCrCb_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::YCrCb_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void YCrCb4_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::YCrCb4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb4_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void YCrCb4_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::YCrCb4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb4_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_xyz_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_xyz_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_xyz_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_xyz_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_xyz_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_xyz_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_xyz4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_xyz4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_xyz4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_xyz4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_xyz4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_xyz4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_xyz_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_xyz_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_xyz_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_xyz_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_xyz_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_xyz_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_xyz4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_xyz4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_xyz4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_xyz4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_xyz4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_xyz4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void xyz_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::xyz_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void xyz4_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::xyz4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz4_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void xyz_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::xyz_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void xyz4_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::xyz4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz4_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void xyz_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::xyz_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void xyz4_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::xyz4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz4_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void xyz_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::xyz_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void xyz4_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::xyz4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz4_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_hsv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_hsv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_hsv_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_hsv_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_hsv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_hsv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_hsv_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_hsv_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_hsv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_hsv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_hsv4_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_hsv4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv4_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_hsv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_hsv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_hsv4_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_hsv4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv4_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_hsv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_hsv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_hsv_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_hsv_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_hsv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_hsv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_hsv_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_hsv_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_hsv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_hsv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_hsv4_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_hsv4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv4_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_hsv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_hsv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_hsv4_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_hsv4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv4_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv_to_rgb_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv_to_rgb_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgb_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv_to_rgba_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv_to_rgba_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgba_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv4_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv4_to_rgb_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv4_to_rgb_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgb_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv4_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv4_to_rgba_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv4_to_rgba_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgba_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv_to_bgr_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv_to_bgr_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgr_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv_to_bgra_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv_to_bgra_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgra_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv4_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv4_to_bgr_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv4_to_bgr_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgr_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv4_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hsv4_to_bgra_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hsv4_to_bgra_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgra_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_hls_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_hls_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_hls_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_hls_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_hls_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_hls_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_hls_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_hls_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_hls4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_hls4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_hls4_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_hls4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls4_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_hls4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_hls4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_hls4_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_hls4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls4_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_hls_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_hls_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_hls_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_hls_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_hls_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_hls_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_hls_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_hls_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_hls4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_hls4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_hls4_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_hls4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls4_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_hls4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_hls4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_hls4_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_hls4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls4_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls_to_rgb_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls_to_rgb_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgb_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls_to_rgba_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls_to_rgba_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgba_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls4_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls4_to_rgb_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls4_to_rgb_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgb_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls4_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls4_to_rgba_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls4_to_rgba_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgba_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls_to_bgr_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls_to_bgr_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgr_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls_to_bgra_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls_to_bgra_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgra_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls4_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls4_to_bgr_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls4_to_bgr_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgr_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls4_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void hls4_to_bgra_full_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::hls4_to_bgra_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgra_full_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_lab_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_lab_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_lab_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_lab_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_lab4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_lab4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_lab4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_lab4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_lab_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_lab_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_lab_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_lab_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_lab4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_lab4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_lab4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_lab4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lrgb_to_lab_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lrgb_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgb_to_lab_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lrgba_to_lab_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lrgba_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgba_to_lab_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lrgb_to_lab4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lrgb_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgb_to_lab4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lrgba_to_lab4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lrgba_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgba_to_lab4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lbgr_to_lab_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lbgr_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgr_to_lab_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lbgra_to_lab_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lbgra_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgra_to_lab_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lbgr_to_lab4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lbgr_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgr_to_lab4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lbgra_to_lab4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lbgra_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgra_to_lab4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab4_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab4_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab4_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab4_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab_to_lrgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab_to_lrgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_lrgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab4_to_lrgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab4_to_lrgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_lrgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab_to_lrgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab_to_lrgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_lrgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab4_to_lrgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab4_to_lrgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_lrgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab_to_lbgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab_to_lbgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_lbgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab4_to_lbgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab4_to_lbgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_lbgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab_to_lbgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab_to_lbgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_lbgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lab4_to_lbgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lab4_to_lbgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_lbgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_luv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_luv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_luv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_luv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgb_to_luv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgb_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_luv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void rgba_to_luv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::rgba_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_luv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_luv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_luv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_luv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_luv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgr_to_luv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgr_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_luv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void bgra_to_luv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::bgra_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_luv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lrgb_to_luv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lrgb_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgb_to_luv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lrgba_to_luv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lrgba_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgba_to_luv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lrgb_to_luv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lrgb_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgb_to_luv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lrgba_to_luv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lrgba_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgba_to_luv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lbgr_to_luv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lbgr_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgr_to_luv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lbgra_to_luv_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lbgra_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgra_to_luv_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lbgr_to_luv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lbgr_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgr_to_luv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void lbgra_to_luv4_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::lbgra_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgra_to_luv4_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv4_to_rgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_rgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv4_to_rgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_rgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv4_to_bgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_bgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv4_to_bgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_bgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv_to_lrgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv_to_lrgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_lrgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv4_to_lrgb_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv4_to_lrgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_lrgb_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv_to_lrgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv_to_lrgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_lrgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv4_to_lrgba_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv4_to_lrgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_lrgba_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv_to_lbgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv_to_lbgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_lbgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv4_to_lbgr_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv4_to_lbgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_lbgr_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv_to_lbgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv_to_lbgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_lbgra_traits<T>::create_functor);
};

template<typename Data_Type_T, typename T>
inline void luv4_to_lbgra_traits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<typename cv::cuda::device::luv4_to_lbgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_lbgra_traits<T>::create_functor);
};

