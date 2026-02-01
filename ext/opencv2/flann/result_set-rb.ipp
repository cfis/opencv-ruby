template<typename T, typename DistanceType>
inline Rice::Data_Type<cvflann::BranchStruct<T, DistanceType>> BranchStruct_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::BranchStruct<T, DistanceType>>(parent, name).
    define_attr("node", &cvflann::BranchStruct<T, DistanceType>::node).
    define_attr("mindist", &cvflann::BranchStruct<T, DistanceType>::mindist).
    define_constructor(Constructor<cvflann::BranchStruct<T, DistanceType>>()).
    define_constructor(Constructor<cvflann::BranchStruct<T, DistanceType>, const T&, DistanceType>(),
      Arg("a_node"), Arg("dist")).
    template define_method<bool(cvflann::BranchStruct<T, DistanceType>::*)(const cvflann::BranchStruct<T, DistanceType>&) const>("<", &cvflann::BranchStruct<T, DistanceType>::operator<,
      Arg("rhs"));
}

template<typename DistanceType>
inline Rice::Data_Type<cvflann::ResultSet<DistanceType>> ResultSet_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::ResultSet<DistanceType>>(parent, name).
    template define_method<bool(cvflann::ResultSet<DistanceType>::*)() const>("full?", &cvflann::ResultSet<DistanceType>::full).
    template define_method<void(cvflann::ResultSet<DistanceType>::*)(DistanceType, int)>("add_point", &cvflann::ResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method<DistanceType(cvflann::ResultSet<DistanceType>::*)() const>("worst_dist", &cvflann::ResultSet<DistanceType>::worstDist);
}

template<typename DistanceType>
inline Rice::Data_Type<cvflann::KNNSimpleResultSet<DistanceType>> KNNSimpleResultSet_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::KNNSimpleResultSet<DistanceType>>(parent, name).
    define_constructor(Constructor<cvflann::KNNSimpleResultSet<DistanceType>, int>(),
      Arg("capacity_")).
    template define_method<void(cvflann::KNNSimpleResultSet<DistanceType>::*)(int*, DistanceType*)>("init", &cvflann::KNNSimpleResultSet<DistanceType>::init,
      ArgBuffer("indices_"), std::conditional_t<std::is_fundamental_v<DistanceType>, ArgBuffer, Arg>("dists_")).
    template define_method<size_t(cvflann::KNNSimpleResultSet<DistanceType>::*)() const>("size", &cvflann::KNNSimpleResultSet<DistanceType>::size).
    template define_method<bool(cvflann::KNNSimpleResultSet<DistanceType>::*)() const>("full?", &cvflann::KNNSimpleResultSet<DistanceType>::full).
    template define_method<void(cvflann::KNNSimpleResultSet<DistanceType>::*)(DistanceType, int)>("add_point", &cvflann::KNNSimpleResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method<DistanceType(cvflann::KNNSimpleResultSet<DistanceType>::*)() const>("worst_dist", &cvflann::KNNSimpleResultSet<DistanceType>::worstDist);
}

template<typename DistanceType>
inline Rice::Data_Type<cvflann::KNNResultSet<DistanceType>> KNNResultSet_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::KNNResultSet<DistanceType>>(parent, name).
    define_constructor(Constructor<cvflann::KNNResultSet<DistanceType>, int>(),
      Arg("capacity_")).
    template define_method<void(cvflann::KNNResultSet<DistanceType>::*)(int*, DistanceType*)>("init", &cvflann::KNNResultSet<DistanceType>::init,
      ArgBuffer("indices_"), std::conditional_t<std::is_fundamental_v<DistanceType>, ArgBuffer, Arg>("dists_")).
    template define_method<size_t(cvflann::KNNResultSet<DistanceType>::*)() const>("size", &cvflann::KNNResultSet<DistanceType>::size).
    template define_method<bool(cvflann::KNNResultSet<DistanceType>::*)() const>("full?", &cvflann::KNNResultSet<DistanceType>::full).
    template define_method<void(cvflann::KNNResultSet<DistanceType>::*)(DistanceType, int)>("add_point", &cvflann::KNNResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method<DistanceType(cvflann::KNNResultSet<DistanceType>::*)() const>("worst_dist", &cvflann::KNNResultSet<DistanceType>::worstDist);
}

template<typename DistanceType>
inline Rice::Data_Type<cvflann::RadiusResultSet<DistanceType>> RadiusResultSet_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::RadiusResultSet<DistanceType>>(parent, name).
    define_constructor(Constructor<cvflann::RadiusResultSet<DistanceType>, DistanceType, int*, DistanceType*, int>(),
      Arg("radius_"), ArgBuffer("indices_"), std::conditional_t<std::is_fundamental_v<DistanceType>, ArgBuffer, Arg>("dists_"), Arg("capacity_")).
    template define_method<void(cvflann::RadiusResultSet<DistanceType>::*)()>("init", &cvflann::RadiusResultSet<DistanceType>::init).
    template define_method<size_t(cvflann::RadiusResultSet<DistanceType>::*)() const>("size", &cvflann::RadiusResultSet<DistanceType>::size).
    template define_method<bool(cvflann::RadiusResultSet<DistanceType>::*)() const>("full?", &cvflann::RadiusResultSet<DistanceType>::full).
    template define_method<void(cvflann::RadiusResultSet<DistanceType>::*)(DistanceType, int)>("add_point", &cvflann::RadiusResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method<DistanceType(cvflann::RadiusResultSet<DistanceType>::*)() const>("worst_dist", &cvflann::RadiusResultSet<DistanceType>::worstDist);
}

template<typename DistanceType>
inline Rice::Data_Type<cvflann::UniqueResultSet<DistanceType>> UniqueResultSet_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::UniqueResultSet<DistanceType>>(parent, name).
    define_constructor(Constructor<cvflann::UniqueResultSet<DistanceType>>()).
    template define_method<bool(cvflann::UniqueResultSet<DistanceType>::*)() const>("full?", &cvflann::UniqueResultSet<DistanceType>::full).
    template define_method<void(cvflann::UniqueResultSet<DistanceType>::*)()>("clear", &cvflann::UniqueResultSet<DistanceType>::clear).
    template define_method<void(cvflann::UniqueResultSet<DistanceType>::*)(int*, DistanceType*, int) const>("copy", &cvflann::UniqueResultSet<DistanceType>::copy,
      ArgBuffer("indices"), std::conditional_t<std::is_fundamental_v<DistanceType>, ArgBuffer, Arg>("dist"), Arg("n_neighbors") = static_cast<int>(-1)).
    template define_method<void(cvflann::UniqueResultSet<DistanceType>::*)(int*, DistanceType*, int) const>("sort_and_copy", &cvflann::UniqueResultSet<DistanceType>::sortAndCopy,
      ArgBuffer("indices"), std::conditional_t<std::is_fundamental_v<DistanceType>, ArgBuffer, Arg>("dist"), Arg("n_neighbors") = static_cast<int>(-1)).
    template define_method<size_t(cvflann::UniqueResultSet<DistanceType>::*)() const>("size", &cvflann::UniqueResultSet<DistanceType>::size).
    template define_method<DistanceType(cvflann::UniqueResultSet<DistanceType>::*)() const>("worst_dist", &cvflann::UniqueResultSet<DistanceType>::worstDist);
}

template<typename DistanceType>
inline Rice::Data_Type<cvflann::KNNUniqueResultSet<DistanceType>> KNNUniqueResultSet_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::KNNUniqueResultSet<DistanceType>>(parent, name).
    define_constructor(Constructor<cvflann::KNNUniqueResultSet<DistanceType>, unsigned int>(),
      Arg("capacity")).
    template define_method<void(cvflann::KNNUniqueResultSet<DistanceType>::*)(DistanceType, int)>("add_point", &cvflann::KNNUniqueResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method<void(cvflann::KNNUniqueResultSet<DistanceType>::*)()>("clear", &cvflann::KNNUniqueResultSet<DistanceType>::clear);
}

template<typename DistanceType>
inline Rice::Data_Type<cvflann::RadiusUniqueResultSet<DistanceType>> RadiusUniqueResultSet_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::RadiusUniqueResultSet<DistanceType>>(parent, name).
    define_constructor(Constructor<cvflann::RadiusUniqueResultSet<DistanceType>, DistanceType>(),
      Arg("radius")).
    template define_method<void(cvflann::RadiusUniqueResultSet<DistanceType>::*)(DistanceType, int)>("add_point", &cvflann::RadiusUniqueResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method<void(cvflann::RadiusUniqueResultSet<DistanceType>::*)()>("clear", &cvflann::RadiusUniqueResultSet<DistanceType>::clear).
    template define_method<bool(cvflann::RadiusUniqueResultSet<DistanceType>::*)() const>("full?", &cvflann::RadiusUniqueResultSet<DistanceType>::full).
    template define_method<DistanceType(cvflann::RadiusUniqueResultSet<DistanceType>::*)() const>("worst_dist", &cvflann::RadiusUniqueResultSet<DistanceType>::worstDist);
}

template<typename DistanceType>
inline Rice::Data_Type<cvflann::KNNRadiusUniqueResultSet<DistanceType>> KNNRadiusUniqueResultSet_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::KNNRadiusUniqueResultSet<DistanceType>>(parent, name).
    define_constructor(Constructor<cvflann::KNNRadiusUniqueResultSet<DistanceType>, unsigned int, DistanceType>(),
      Arg("capacity"), Arg("radius")).
    template define_method<void(cvflann::KNNRadiusUniqueResultSet<DistanceType>::*)()>("clear", &cvflann::KNNRadiusUniqueResultSet<DistanceType>::clear);
}

