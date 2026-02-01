

template<unsigned int I, typename KP, typename KR, typename VP, typename VR, typename Cmp>
inline Rice::Data_Type<cv::cuda::device::reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>> Unroll_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>>(parent, name).
    template define_singleton_function<int(*)(KR, VR, Cmp, unsigned int)>("loop_shfl", &cv::cuda::device::reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>::loopShfl,
      Arg("key"), Arg("val"), Arg("cmp"), Arg("n")).
    template define_singleton_function<int(*)(KP, KR, VP, VR, unsigned int, Cmp)>("loop", &cv::cuda::device::reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>::loop,
      Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));
}

template<unsigned int N>
inline Rice::Data_Type<cv::cuda::device::reduce_key_val_detail::GenericOptimized32<N>> GenericOptimized32_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::reduce_key_val_detail::GenericOptimized32<N>>(parent, name).
    define_constant("M", (int)cv::cuda::device::reduce_key_val_detail::GenericOptimized32<N>::M);
}

template<unsigned int N>
inline Rice::Data_Type<cv::cuda::device::reduce_key_val_detail::IsPowerOf2<N>> IsPowerOf2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::reduce_key_val_detail::IsPowerOf2<N>>(parent, name).
    define_constant("Value", (int)cv::cuda::device::reduce_key_val_detail::IsPowerOf2<N>::value);
}

