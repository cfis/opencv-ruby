

template<int I, typename KP, typename KR, typename VP, typename VR, typename Cmp>
inline Rice::Data_Type<cv::cudev::block_reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>> Unroll_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::block_reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>>(parent, name).
    template define_singleton_function<void(*)(KP, KR, VP, VR, uint, Cmp)>("loop", &cv::cudev::block_reduce_key_val_detail::Unroll<I, KP, KR, VP, VR, Cmp>::loop,
      Arg("skeys"), Arg("key"), Arg("svals"), Arg("val"), Arg("tid"), Arg("cmp"));
}

template<uint N>
inline Rice::Data_Type<cv::cudev::block_reduce_key_val_detail::GenericOptimized32<N>> GenericOptimized32_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::block_reduce_key_val_detail::GenericOptimized32<N>>(parent, name).
    define_constant("M", (int)cv::cudev::block_reduce_key_val_detail::GenericOptimized32<N>::M);
}

