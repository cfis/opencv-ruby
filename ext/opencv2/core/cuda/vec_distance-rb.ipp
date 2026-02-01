template<typename T>
inline Rice::Data_Type<cv::cuda::device::L1Dist<T>> L1Dist_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::L1Dist<T>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::L1Dist<T>>()).
    template define_method<void(cv::cuda::device::L1Dist<T>::*)(int, int)>("reduce_iter", &cv::cuda::device::L1Dist<T>::reduceIter,
      Arg("val1"), Arg("val2")).
    define_method("to_i", [](const cv::cuda::device::L1Dist<T>& self) -> int
    {
      return self;
    }).
    define_attr("my_sum", &cv::cuda::device::L1Dist<T>::mySum);
}

template<int THREAD_DIM, typename T1>
inline Rice::Data_Type<cv::cuda::device::VecDiffGlobal<THREAD_DIM, T1>> VecDiffGlobal_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::VecDiffGlobal<THREAD_DIM, T1>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::VecDiffGlobal<THREAD_DIM, T1>, const T1*, int, void*, int, int>(),
      std::conditional_t<std::is_fundamental_v<const T1>, ArgBuffer, Arg>("vec1_"), Arg("arg_1") = static_cast<int>(0), ArgBuffer("arg_2") = static_cast<void*>(0), Arg("arg_3") = static_cast<int>(0), Arg("arg_4") = static_cast<int>(0)).
    define_attr("vec1", &cv::cuda::device::VecDiffGlobal<THREAD_DIM, T1>::vec1);
}

template<int THREAD_DIM, int MAX_LEN, bool LEN_EQ_MAX_LEN, typename U>
inline Rice::Data_Type<cv::cuda::device::VecDiffCachedRegister<THREAD_DIM, MAX_LEN, LEN_EQ_MAX_LEN, U>> VecDiffCachedRegister_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::VecDiffCachedRegister<THREAD_DIM, MAX_LEN, LEN_EQ_MAX_LEN, U>>(parent, name).
    define_attr("vec1_vals", &cv::cuda::device::VecDiffCachedRegister<THREAD_DIM, MAX_LEN, LEN_EQ_MAX_LEN, U>::vec1Vals, Rice::AttrAccess::Read);
}

