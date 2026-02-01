template<typename T>
inline Rice::Data_Type<cvflann::greater<T>> greater_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cvflann::greater<T>>(parent, name).
    template define_method<bool(cvflann::greater<T>::*)(const T&, const T&) const>("call", &cvflann::greater<T>::operator(),
      Arg("x"), Arg("y"));
}

template<typename T>
inline Rice::Data_Type<cvflann::Heap<T>> Heap_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cvflann::Heap<T>>(parent, name).
    define_constructor(Constructor<cvflann::Heap<T>, const int>(),
      Arg("capacity")).
    define_constructor(Constructor<cvflann::Heap<T>, std::vector<T>&&>(),
      Arg("vec")).
    template define_method<int(cvflann::Heap<T>::*)() const>("size", &cvflann::Heap<T>::size).
    template define_method<int(cvflann::Heap<T>::*)() const>("capacity", &cvflann::Heap<T>::capacity).
    template define_method<bool(cvflann::Heap<T>::*)()>("empty?", &cvflann::Heap<T>::empty).
    template define_method<void(cvflann::Heap<T>::*)()>("clear", &cvflann::Heap<T>::clear).
    template define_method<void(cvflann::Heap<T>::*)(const int)>("reserve", &cvflann::Heap<T>::reserve,
      Arg("capacity")).
    template define_method<void(cvflann::Heap<T>::*)(T)>("insert", &cvflann::Heap<T>::insert,
      Arg("value")).
    template define_method<bool(cvflann::Heap<T>::*)(T&)>("pop_min", &cvflann::Heap<T>::popMin,
      Arg("value"));
}

