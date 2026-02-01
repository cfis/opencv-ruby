

template<int I, typename Pointer, typename Reference, typename Op>
inline Rice::Data_Type<cv::cudev::block_reduce_detail::Unroll<I, Pointer, Reference, Op>> Unroll_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::block_reduce_detail::Unroll<I, Pointer, Reference, Op>>(parent, name).
    template define_singleton_function<void(*)(Pointer, Reference, uint, Op)>("loop", &cv::cudev::block_reduce_detail::Unroll<I, Pointer, Reference, Op>::loop,
      Arg("smem"), Arg("val"), Arg("tid"), Arg("op"));
}

template<int N>
inline Rice::Data_Type<cv::cudev::block_reduce_detail::GenericOptimized32<N>> GenericOptimized32_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::block_reduce_detail::GenericOptimized32<N>>(parent, name).
    define_constant("M", (int)cv::cudev::block_reduce_detail::GenericOptimized32<N>::M);
}

