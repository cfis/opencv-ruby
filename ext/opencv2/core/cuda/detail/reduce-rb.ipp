

template<unsigned int I, typename Pointer, typename Reference, typename Op>
inline Rice::Data_Type<cv::cuda::device::reduce_detail::Unroll<I, Pointer, Reference, Op>> Unroll_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::reduce_detail::Unroll<I, Pointer, Reference, Op>>(parent, name).
    template define_singleton_function<int(*)(Reference, Op, unsigned int)>("loop_shfl", &cv::cuda::device::reduce_detail::Unroll<I, Pointer, Reference, Op>::loopShfl,
      Arg("val"), Arg("op"), Arg("n")).
    template define_singleton_function<int(*)(Pointer, Reference, unsigned int, Op)>("loop", &cv::cuda::device::reduce_detail::Unroll<I, Pointer, Reference, Op>::loop,
      Arg("smem"), Arg("val"), Arg("tid"), Arg("op"));
}

template<unsigned int N>
inline Rice::Data_Type<cv::cuda::device::reduce_detail::GenericOptimized32<N>> GenericOptimized32_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::reduce_detail::GenericOptimized32<N>>(parent, name).
    define_constant("M", (int)cv::cuda::device::reduce_detail::GenericOptimized32<N>::M);
}

template<unsigned int N>
inline Rice::Data_Type<cv::cuda::device::reduce_detail::IsPowerOf2<N>> IsPowerOf2_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::reduce_detail::IsPowerOf2<N>>(parent, name).
    define_constant("Value", (int)cv::cuda::device::reduce_detail::IsPowerOf2<N>::value);
}

