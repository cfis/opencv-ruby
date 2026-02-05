template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_rgb_traits<T>> bgr_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_bgra_traits<T>> bgr_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_rgba_traits<T>> bgr_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_bgr_traits<T>> bgra_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_rgb_traits<T>> bgra_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_rgba_traits<T>> bgra_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::gray_to_bgr_traits<T>> gray_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::gray_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::gray_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::gray_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::gray_to_bgra_traits<T>> gray_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::gray_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::gray_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::gray_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_gray_traits<T>> rgb_to_gray_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_gray_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_gray_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_gray_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_gray_traits<T>> bgr_to_gray_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_gray_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_gray_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_gray_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_gray_traits<T>> rgba_to_gray_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_gray_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_gray_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_gray_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_gray_traits<T>> bgra_to_gray_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_gray_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_gray_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_gray_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_yuv_traits<T>> rgb_to_yuv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_yuv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_yuv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_yuv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_yuv_traits<T>> rgba_to_yuv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_yuv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_yuv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_yuv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_yuv4_traits<T>> rgb_to_yuv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_yuv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_yuv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_yuv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_yuv4_traits<T>> rgba_to_yuv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_yuv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_yuv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_yuv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_yuv_traits<T>> bgr_to_yuv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_yuv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_yuv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_yuv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_yuv_traits<T>> bgra_to_yuv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_yuv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_yuv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_yuv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_yuv4_traits<T>> bgr_to_yuv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_yuv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_yuv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_yuv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_yuv4_traits<T>> bgra_to_yuv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_yuv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_yuv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_yuv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::yuv_to_rgb_traits<T>> yuv_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::yuv_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::yuv_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::yuv_to_rgba_traits<T>> yuv_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::yuv_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::yuv_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::yuv4_to_rgb_traits<T>> yuv4_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::yuv4_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::yuv4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv4_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::yuv4_to_rgba_traits<T>> yuv4_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::yuv4_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::yuv4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv4_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::yuv_to_bgr_traits<T>> yuv_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::yuv_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::yuv_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::yuv_to_bgra_traits<T>> yuv_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::yuv_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::yuv_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::yuv4_to_bgr_traits<T>> yuv4_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::yuv4_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::yuv4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv4_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::yuv4_to_bgra_traits<T>> yuv4_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::yuv4_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::yuv4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::yuv4_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_YCrCb_traits<T>> rgb_to_YCrCb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_YCrCb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_YCrCb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_YCrCb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_YCrCb_traits<T>> rgba_to_YCrCb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_YCrCb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_YCrCb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_YCrCb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_YCrCb4_traits<T>> rgb_to_YCrCb4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_YCrCb4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_YCrCb4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_YCrCb4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_YCrCb4_traits<T>> rgba_to_YCrCb4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_YCrCb4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_YCrCb4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_YCrCb4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_YCrCb_traits<T>> bgr_to_YCrCb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_YCrCb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_YCrCb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_YCrCb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_YCrCb_traits<T>> bgra_to_YCrCb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_YCrCb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_YCrCb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_YCrCb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_YCrCb4_traits<T>> bgr_to_YCrCb4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_YCrCb4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_YCrCb4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_YCrCb4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_YCrCb4_traits<T>> bgra_to_YCrCb4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_YCrCb4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_YCrCb4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_YCrCb4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::YCrCb_to_rgb_traits<T>> YCrCb_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::YCrCb_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::YCrCb_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::YCrCb_to_rgba_traits<T>> YCrCb_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::YCrCb_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::YCrCb_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::YCrCb4_to_rgb_traits<T>> YCrCb4_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::YCrCb4_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::YCrCb4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb4_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::YCrCb4_to_rgba_traits<T>> YCrCb4_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::YCrCb4_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::YCrCb4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb4_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::YCrCb_to_bgr_traits<T>> YCrCb_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::YCrCb_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::YCrCb_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::YCrCb_to_bgra_traits<T>> YCrCb_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::YCrCb_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::YCrCb_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::YCrCb4_to_bgr_traits<T>> YCrCb4_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::YCrCb4_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::YCrCb4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb4_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::YCrCb4_to_bgra_traits<T>> YCrCb4_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::YCrCb4_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::YCrCb4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::YCrCb4_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_xyz_traits<T>> rgb_to_xyz_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_xyz_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_xyz_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_xyz_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_xyz_traits<T>> rgba_to_xyz_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_xyz_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_xyz_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_xyz_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_xyz4_traits<T>> rgb_to_xyz4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_xyz4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_xyz4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_xyz4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_xyz4_traits<T>> rgba_to_xyz4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_xyz4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_xyz4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_xyz4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_xyz_traits<T>> bgr_to_xyz_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_xyz_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_xyz_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_xyz_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_xyz_traits<T>> bgra_to_xyz_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_xyz_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_xyz_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_xyz_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_xyz4_traits<T>> bgr_to_xyz4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_xyz4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_xyz4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_xyz4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_xyz4_traits<T>> bgra_to_xyz4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_xyz4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_xyz4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_xyz4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::xyz_to_rgb_traits<T>> xyz_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::xyz_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::xyz_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::xyz4_to_rgb_traits<T>> xyz4_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::xyz4_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::xyz4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz4_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::xyz_to_rgba_traits<T>> xyz_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::xyz_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::xyz_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::xyz4_to_rgba_traits<T>> xyz4_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::xyz4_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::xyz4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz4_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::xyz_to_bgr_traits<T>> xyz_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::xyz_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::xyz_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::xyz4_to_bgr_traits<T>> xyz4_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::xyz4_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::xyz4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz4_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::xyz_to_bgra_traits<T>> xyz_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::xyz_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::xyz_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::xyz4_to_bgra_traits<T>> xyz4_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::xyz4_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::xyz4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::xyz4_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_hsv_traits<T>> rgb_to_hsv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_hsv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_hsv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_hsv_full_traits<T>> rgb_to_hsv_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_hsv_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_hsv_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_hsv_traits<T>> rgba_to_hsv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_hsv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_hsv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_hsv_full_traits<T>> rgba_to_hsv_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_hsv_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_hsv_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_hsv4_traits<T>> rgb_to_hsv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_hsv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_hsv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_hsv4_full_traits<T>> rgb_to_hsv4_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_hsv4_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_hsv4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hsv4_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_hsv4_traits<T>> rgba_to_hsv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_hsv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_hsv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_hsv4_full_traits<T>> rgba_to_hsv4_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_hsv4_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_hsv4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hsv4_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_hsv_traits<T>> bgr_to_hsv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_hsv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_hsv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_hsv_full_traits<T>> bgr_to_hsv_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_hsv_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_hsv_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_hsv_traits<T>> bgra_to_hsv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_hsv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_hsv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_hsv_full_traits<T>> bgra_to_hsv_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_hsv_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_hsv_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_hsv4_traits<T>> bgr_to_hsv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_hsv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_hsv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_hsv4_full_traits<T>> bgr_to_hsv4_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_hsv4_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_hsv4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hsv4_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_hsv4_traits<T>> bgra_to_hsv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_hsv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_hsv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_hsv4_full_traits<T>> bgra_to_hsv4_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_hsv4_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_hsv4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hsv4_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv_to_rgb_traits<T>> hsv_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv_to_rgb_full_traits<T>> hsv_to_rgb_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv_to_rgb_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv_to_rgb_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgb_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv_to_rgba_traits<T>> hsv_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv_to_rgba_full_traits<T>> hsv_to_rgba_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv_to_rgba_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv_to_rgba_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_rgba_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv4_to_rgb_traits<T>> hsv4_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv4_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv4_to_rgb_full_traits<T>> hsv4_to_rgb_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv4_to_rgb_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv4_to_rgb_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgb_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv4_to_rgba_traits<T>> hsv4_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv4_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv4_to_rgba_full_traits<T>> hsv4_to_rgba_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv4_to_rgba_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv4_to_rgba_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_rgba_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv_to_bgr_traits<T>> hsv_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv_to_bgr_full_traits<T>> hsv_to_bgr_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv_to_bgr_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv_to_bgr_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgr_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv_to_bgra_traits<T>> hsv_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv_to_bgra_full_traits<T>> hsv_to_bgra_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv_to_bgra_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv_to_bgra_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv_to_bgra_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv4_to_bgr_traits<T>> hsv4_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv4_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv4_to_bgr_full_traits<T>> hsv4_to_bgr_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv4_to_bgr_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv4_to_bgr_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgr_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv4_to_bgra_traits<T>> hsv4_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv4_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hsv4_to_bgra_full_traits<T>> hsv4_to_bgra_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hsv4_to_bgra_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hsv4_to_bgra_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hsv4_to_bgra_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_hls_traits<T>> rgb_to_hls_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_hls_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_hls_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_hls_full_traits<T>> rgb_to_hls_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_hls_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_hls_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_hls_traits<T>> rgba_to_hls_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_hls_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_hls_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_hls_full_traits<T>> rgba_to_hls_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_hls_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_hls_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_hls4_traits<T>> rgb_to_hls4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_hls4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_hls4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_hls4_full_traits<T>> rgb_to_hls4_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_hls4_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_hls4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_hls4_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_hls4_traits<T>> rgba_to_hls4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_hls4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_hls4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_hls4_full_traits<T>> rgba_to_hls4_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_hls4_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_hls4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_hls4_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_hls_traits<T>> bgr_to_hls_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_hls_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_hls_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_hls_full_traits<T>> bgr_to_hls_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_hls_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_hls_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_hls_traits<T>> bgra_to_hls_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_hls_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_hls_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_hls_full_traits<T>> bgra_to_hls_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_hls_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_hls_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_hls4_traits<T>> bgr_to_hls4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_hls4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_hls4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_hls4_full_traits<T>> bgr_to_hls4_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_hls4_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_hls4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_hls4_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_hls4_traits<T>> bgra_to_hls4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_hls4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_hls4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_hls4_full_traits<T>> bgra_to_hls4_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_hls4_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_hls4_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_hls4_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls_to_rgb_traits<T>> hls_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls_to_rgb_full_traits<T>> hls_to_rgb_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls_to_rgb_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls_to_rgb_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgb_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls_to_rgba_traits<T>> hls_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls_to_rgba_full_traits<T>> hls_to_rgba_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls_to_rgba_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls_to_rgba_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_rgba_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls4_to_rgb_traits<T>> hls4_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls4_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls4_to_rgb_full_traits<T>> hls4_to_rgb_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls4_to_rgb_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls4_to_rgb_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgb_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls4_to_rgba_traits<T>> hls4_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls4_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls4_to_rgba_full_traits<T>> hls4_to_rgba_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls4_to_rgba_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls4_to_rgba_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_rgba_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls_to_bgr_traits<T>> hls_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls_to_bgr_full_traits<T>> hls_to_bgr_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls_to_bgr_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls_to_bgr_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgr_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls_to_bgra_traits<T>> hls_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls_to_bgra_full_traits<T>> hls_to_bgra_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls_to_bgra_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls_to_bgra_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls_to_bgra_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls4_to_bgr_traits<T>> hls4_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls4_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls4_to_bgr_full_traits<T>> hls4_to_bgr_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls4_to_bgr_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls4_to_bgr_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgr_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls4_to_bgra_traits<T>> hls4_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls4_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::hls4_to_bgra_full_traits<T>> hls4_to_bgra_full_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::hls4_to_bgra_full_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::hls4_to_bgra_full_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::hls4_to_bgra_full_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_lab_traits<T>> rgb_to_lab_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_lab_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_lab_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_lab_traits<T>> rgba_to_lab_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_lab_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_lab_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_lab4_traits<T>> rgb_to_lab4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_lab4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_lab4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_lab4_traits<T>> rgba_to_lab4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_lab4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_lab4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_lab_traits<T>> bgr_to_lab_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_lab_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_lab_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_lab_traits<T>> bgra_to_lab_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_lab_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_lab_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_lab4_traits<T>> bgr_to_lab4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_lab4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_lab4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_lab4_traits<T>> bgra_to_lab4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_lab4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_lab4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lrgb_to_lab_traits<T>> lrgb_to_lab_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lrgb_to_lab_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lrgb_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgb_to_lab_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lrgba_to_lab_traits<T>> lrgba_to_lab_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lrgba_to_lab_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lrgba_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgba_to_lab_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lrgb_to_lab4_traits<T>> lrgb_to_lab4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lrgb_to_lab4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lrgb_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgb_to_lab4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lrgba_to_lab4_traits<T>> lrgba_to_lab4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lrgba_to_lab4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lrgba_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgba_to_lab4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lbgr_to_lab_traits<T>> lbgr_to_lab_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lbgr_to_lab_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lbgr_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgr_to_lab_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lbgra_to_lab_traits<T>> lbgra_to_lab_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lbgra_to_lab_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lbgra_to_lab_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgra_to_lab_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lbgr_to_lab4_traits<T>> lbgr_to_lab4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lbgr_to_lab4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lbgr_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgr_to_lab4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lbgra_to_lab4_traits<T>> lbgra_to_lab4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lbgra_to_lab4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lbgra_to_lab4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgra_to_lab4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab_to_rgb_traits<T>> lab_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab4_to_rgb_traits<T>> lab4_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab4_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab_to_rgba_traits<T>> lab_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab4_to_rgba_traits<T>> lab4_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab4_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab_to_bgr_traits<T>> lab_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab4_to_bgr_traits<T>> lab4_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab4_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab_to_bgra_traits<T>> lab_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab4_to_bgra_traits<T>> lab4_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab4_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab_to_lrgb_traits<T>> lab_to_lrgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab_to_lrgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab_to_lrgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_lrgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab4_to_lrgb_traits<T>> lab4_to_lrgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab4_to_lrgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab4_to_lrgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_lrgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab_to_lrgba_traits<T>> lab_to_lrgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab_to_lrgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab_to_lrgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_lrgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab4_to_lrgba_traits<T>> lab4_to_lrgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab4_to_lrgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab4_to_lrgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_lrgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab_to_lbgr_traits<T>> lab_to_lbgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab_to_lbgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab_to_lbgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_lbgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab4_to_lbgr_traits<T>> lab4_to_lbgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab4_to_lbgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab4_to_lbgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_lbgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab_to_lbgra_traits<T>> lab_to_lbgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab_to_lbgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab_to_lbgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab_to_lbgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lab4_to_lbgra_traits<T>> lab4_to_lbgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lab4_to_lbgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lab4_to_lbgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lab4_to_lbgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_luv_traits<T>> rgb_to_luv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_luv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_luv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_luv_traits<T>> rgba_to_luv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_luv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_luv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgb_to_luv4_traits<T>> rgb_to_luv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgb_to_luv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgb_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgb_to_luv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::rgba_to_luv4_traits<T>> rgba_to_luv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::rgba_to_luv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::rgba_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::rgba_to_luv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_luv_traits<T>> bgr_to_luv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_luv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_luv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_luv_traits<T>> bgra_to_luv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_luv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_luv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgr_to_luv4_traits<T>> bgr_to_luv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgr_to_luv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgr_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgr_to_luv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::bgra_to_luv4_traits<T>> bgra_to_luv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::bgra_to_luv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::bgra_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::bgra_to_luv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lrgb_to_luv_traits<T>> lrgb_to_luv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lrgb_to_luv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lrgb_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgb_to_luv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lrgba_to_luv_traits<T>> lrgba_to_luv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lrgba_to_luv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lrgba_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgba_to_luv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lrgb_to_luv4_traits<T>> lrgb_to_luv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lrgb_to_luv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lrgb_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgb_to_luv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lrgba_to_luv4_traits<T>> lrgba_to_luv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lrgba_to_luv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lrgba_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lrgba_to_luv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lbgr_to_luv_traits<T>> lbgr_to_luv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lbgr_to_luv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lbgr_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgr_to_luv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lbgra_to_luv_traits<T>> lbgra_to_luv_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lbgra_to_luv_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lbgra_to_luv_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgra_to_luv_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lbgr_to_luv4_traits<T>> lbgr_to_luv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lbgr_to_luv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lbgr_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgr_to_luv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::lbgra_to_luv4_traits<T>> lbgra_to_luv4_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::lbgra_to_luv4_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::lbgra_to_luv4_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::lbgra_to_luv4_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv_to_rgb_traits<T>> luv_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv4_to_rgb_traits<T>> luv4_to_rgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv4_to_rgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv4_to_rgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_rgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv_to_rgba_traits<T>> luv_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv4_to_rgba_traits<T>> luv4_to_rgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv4_to_rgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv4_to_rgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_rgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv_to_bgr_traits<T>> luv_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv4_to_bgr_traits<T>> luv4_to_bgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv4_to_bgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv4_to_bgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_bgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv_to_bgra_traits<T>> luv_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv4_to_bgra_traits<T>> luv4_to_bgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv4_to_bgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv4_to_bgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_bgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv_to_lrgb_traits<T>> luv_to_lrgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv_to_lrgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv_to_lrgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_lrgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv4_to_lrgb_traits<T>> luv4_to_lrgb_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv4_to_lrgb_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv4_to_lrgb_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_lrgb_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv_to_lrgba_traits<T>> luv_to_lrgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv_to_lrgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv_to_lrgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_lrgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv4_to_lrgba_traits<T>> luv4_to_lrgba_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv4_to_lrgba_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv4_to_lrgba_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_lrgba_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv_to_lbgr_traits<T>> luv_to_lbgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv_to_lbgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv_to_lbgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_lbgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv4_to_lbgr_traits<T>> luv4_to_lbgr_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv4_to_lbgr_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv4_to_lbgr_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_lbgr_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv_to_lbgra_traits<T>> luv_to_lbgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv_to_lbgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv_to_lbgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv_to_lbgra_traits<T>::create_functor);
}

template<typename T>
inline Rice::Data_Type<cv::cuda::device::luv4_to_lbgra_traits<T>> luv4_to_lbgra_traits_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::luv4_to_lbgra_traits<T>>(parent, name).
    template define_singleton_function<typename cv::cuda::device::luv4_to_lbgra_traits<T>::functor_type(*)()>("create_functor", &cv::cuda::device::luv4_to_lbgra_traits<T>::create_functor);
}

