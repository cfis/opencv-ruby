
template<typename T>
inline Rice::Data_Type<cvflann::ZeroIterator<T>> ZeroIterator_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::ZeroIterator<T>>(parent, name).
    template define_method<T(cvflann::ZeroIterator<T>::*)()>("dereference", &cvflann::ZeroIterator<T>::operator*).
    template define_method<T(cvflann::ZeroIterator<T>::*)(int)>("[]", &cvflann::ZeroIterator<T>::operator[],
      Arg("arg_0")).
    template define_method<const cvflann::ZeroIterator<T>&(cvflann::ZeroIterator<T>::*)()>("increment", &cvflann::ZeroIterator<T>::operator++).
    template define_method<cvflann::ZeroIterator<T>(cvflann::ZeroIterator<T>::*)(int)>("increment_post", &cvflann::ZeroIterator<T>::operator++,
      Arg("arg_0")).
    template define_method<cvflann::ZeroIterator<T>&(cvflann::ZeroIterator<T>::*)(int)>("assign_plus", &cvflann::ZeroIterator<T>::operator+=,
      Arg("arg_0"));
}

template<typename T>
inline Rice::Data_Type<cvflann::MinkowskiDistance<T>> MinkowskiDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::MinkowskiDistance<T>>(parent, name).
    define_attr("order", &cvflann::MinkowskiDistance<T>::order).
    define_constructor(Constructor<cvflann::MinkowskiDistance<T>, int>(),
      Arg("order_"));
}

template<typename T>
inline Rice::Data_Type<cvflann::Hamming2<T>> Hamming2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::Hamming2<T>>(parent, name).
    template define_method<unsigned int(cvflann::Hamming2<T>::*)(uint32_t) const>("popcnt32", &cvflann::Hamming2<T>::popcnt32,
      Arg("n")).
    template define_method<unsigned int(cvflann::Hamming2<T>::*)(uint64_t) const>("popcnt64", &cvflann::Hamming2<T>::popcnt64,
      Arg("n"));
}

template<typename T>
inline Rice::Data_Type<cvflann::DNAmming2<T>> DNAmming2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::DNAmming2<T>>(parent, name).
    template define_method<unsigned int(cvflann::DNAmming2<T>::*)(uint32_t) const>("popcnt32", &cvflann::DNAmming2<T>::popcnt32,
      Arg("n")).
    template define_method<unsigned int(cvflann::DNAmming2<T>::*)(uint64_t) const>("popcnt64", &cvflann::DNAmming2<T>::popcnt64,
      Arg("n"));
}

template<typename Distance, typename ElementType>
inline Rice::Data_Type<cvflann::squareDistance<Distance, ElementType>> squareDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::squareDistance<Distance, ElementType>>(parent, name).
    template define_method<typename cvflann::squareDistance<Distance, ElementType>::ResultType(cvflann::squareDistance<Distance, ElementType>::*)(typename cvflann::squareDistance<Distance, ElementType>::ResultType)>("call", &cvflann::squareDistance<Distance, ElementType>::operator(),
      Arg("dist"));
}

template<typename Distance, typename ElementType>
inline Rice::Data_Type<cvflann::isSquareDist<Distance, ElementType>> isSquareDist_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::isSquareDist<Distance, ElementType>>(parent, name).
    template define_method<bool(cvflann::isSquareDist<Distance, ElementType>::*)()>("call", &cvflann::isSquareDist<Distance, ElementType>::operator());
}

template<typename Distance, typename ElementType>
inline Rice::Data_Type<cvflann::simpleDistance<Distance, ElementType>> simpleDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::simpleDistance<Distance, ElementType>>(parent, name).
    template define_method<typename cvflann::simpleDistance<Distance, ElementType>::ResultType(cvflann::simpleDistance<Distance, ElementType>::*)(typename cvflann::simpleDistance<Distance, ElementType>::ResultType)>("call", &cvflann::simpleDistance<Distance, ElementType>::operator(),
      Arg("dist"));
}

