template<typename T>
inline Rice::Data_Type<cv::cudev::DynamicSharedMem<T>> DynamicSharedMem_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::DynamicSharedMem<T>>(parent, name).
    define_method("to_ptr", [](cv::cudev::DynamicSharedMem<T>& self) -> T*
    {
      return self;
    }).
    define_method("to_const_ptr", [](const cv::cudev::DynamicSharedMem<T>& self) -> const T*
    {
      return self;
    });
}

