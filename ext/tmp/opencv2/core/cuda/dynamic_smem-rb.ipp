template<typename T>
inline Rice::Data_Type<cv::cuda::device::DynamicSharedMem<T>> DynamicSharedMem_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::DynamicSharedMem<T>>(parent, name).
    define_attr("__forceinline__", &cv::cuda::device::DynamicSharedMem<T>::__forceinline__);
}

