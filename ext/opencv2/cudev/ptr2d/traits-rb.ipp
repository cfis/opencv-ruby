template<typename Ptr2DSz, typename Ptr2D>
inline Rice::Data_Type<cv::cudev::PtrTraitsBase<Ptr2DSz, Ptr2D>> PtrTraitsBase_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::PtrTraitsBase<Ptr2DSz, Ptr2D>>(parent, name).
    template define_singleton_function<Ptr2D(*)(const Ptr2DSz&)>("shrink_ptr", &cv::cudev::PtrTraitsBase<Ptr2DSz, Ptr2D>::shrinkPtr,
      Arg("ptr")).
    template define_singleton_function<int(*)(const Ptr2DSz&)>("get_rows", &cv::cudev::PtrTraitsBase<Ptr2DSz, Ptr2D>::getRows,
      Arg("ptr")).
    template define_singleton_function<int(*)(const Ptr2DSz&)>("get_cols", &cv::cudev::PtrTraitsBase<Ptr2DSz, Ptr2D>::getCols,
      Arg("ptr"));
}

