template<typename T>
inline Rice::Data_Type<cvflann::Accumulator<T>> Accumulator_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::Accumulator<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::ZeroIterator<T>> ZeroIterator_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::ZeroIterator<T>>(parent, name)
    .template define_method<T(cvflann::ZeroIterator<T>::*)()>("dereference", &cvflann::ZeroIterator<T>::operator*)
    .template define_method<T(cvflann::ZeroIterator<T>::*)(int)>("[]", &cvflann::ZeroIterator<T>::operator[],
      Arg("arg_0"))
    .template define_method<const cvflann::ZeroIterator<T>&(cvflann::ZeroIterator<T>::*)()>("increment", &cvflann::ZeroIterator<T>::operator++)
    .template define_method<cvflann::ZeroIterator<T>(cvflann::ZeroIterator<T>::*)(int)>("increment_post", &cvflann::ZeroIterator<T>::operator++,
      Arg("arg_0"))
    .template define_method<cvflann::ZeroIterator<T>&(cvflann::ZeroIterator<T>::*)(int)>("assign_plus", &cvflann::ZeroIterator<T>::operator+=,
      Arg("arg_0"))
    ;
}

template<typename T>
inline Rice::Data_Type<cvflann::L2_Simple<T>> L2_Simple_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::L2_Simple<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::L2<T>> L2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::L2<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::L1<T>> L1_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::L1<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::MinkowskiDistance<T>> MinkowskiDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::MinkowskiDistance<T>>(parent, name)
    .define_attr("order", &cvflann::MinkowskiDistance<T>::order)
    .define_constructor(Constructor<cvflann::MinkowskiDistance<T>, int>(),
      Arg("order_"))
    ;
}

template<typename T>
inline Rice::Data_Type<cvflann::MaxDistance<T>> MaxDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::MaxDistance<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::Hamming<T>> Hamming_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::Hamming<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::Hamming2<T>> Hamming2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::Hamming2<T>>(parent, name)
    .template define_method<unsigned int(cvflann::Hamming2<T>::*)(uint32_t) const>("popcnt32", &cvflann::Hamming2<T>::popcnt32,
      Arg("n"))
    .template define_method<unsigned int(cvflann::Hamming2<T>::*)(uint64_t) const>("popcnt64", &cvflann::Hamming2<T>::popcnt64,
      Arg("n"))
    ;
}

template<typename T>
inline Rice::Data_Type<cvflann::DNAmming2<T>> DNAmming2_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::DNAmming2<T>>(parent, name)
    .template define_method<unsigned int(cvflann::DNAmming2<T>::*)(uint32_t) const>("popcnt32", &cvflann::DNAmming2<T>::popcnt32,
      Arg("n"))
    .template define_method<unsigned int(cvflann::DNAmming2<T>::*)(uint64_t) const>("popcnt64", &cvflann::DNAmming2<T>::popcnt64,
      Arg("n"))
    ;
}

template<typename T>
inline Rice::Data_Type<cvflann::HistIntersectionDistance<T>> HistIntersectionDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::HistIntersectionDistance<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::HellingerDistance<T>> HellingerDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::HellingerDistance<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::ChiSquareDistance<T>> ChiSquareDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::ChiSquareDistance<T>>(parent, name);
}

template<typename T>
inline Rice::Data_Type<cvflann::KL_Divergence<T>> KL_Divergence_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::KL_Divergence<T>>(parent, name);
}

template<typename Distance, typename ElementType>
inline Rice::Data_Type<cvflann::squareDistance<Distance, ElementType>> squareDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::squareDistance<Distance, ElementType>>(parent, name)
    .template define_method<typename cvflann::squareDistance<Distance, ElementType>::ResultType(cvflann::squareDistance<Distance, ElementType>::*)(typename cvflann::squareDistance<Distance, ElementType>::ResultType)>("call", &cvflann::squareDistance<Distance, ElementType>::operator(),
      Arg("dist"))
    ;
}

template<typename Distance, typename ElementType>
inline Rice::Data_Type<cvflann::isSquareDist<Distance, ElementType>> isSquareDist_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::isSquareDist<Distance, ElementType>>(parent, name)
    .template define_method<bool(cvflann::isSquareDist<Distance, ElementType>::*)()>("call", &cvflann::isSquareDist<Distance, ElementType>::operator())
    ;
}

template<typename Distance, typename ElementType>
inline Rice::Data_Type<cvflann::simpleDistance<Distance, ElementType>> simpleDistance_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::simpleDistance<Distance, ElementType>>(parent, name)
    .template define_method<typename cvflann::simpleDistance<Distance, ElementType>::ResultType(cvflann::simpleDistance<Distance, ElementType>::*)(typename cvflann::simpleDistance<Distance, ElementType>::ResultType)>("call", &cvflann::simpleDistance<Distance, ElementType>::operator(),
      Arg("dist"))
    ;
}

