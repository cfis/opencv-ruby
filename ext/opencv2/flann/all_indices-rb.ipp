template<typename KDTreeCapability, typename VectorSpace, typename Distance>
inline Rice::Data_Type<cvflann::index_creator<KDTreeCapability, VectorSpace, Distance>> index_creator_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::index_creator<KDTreeCapability, VectorSpace, Distance>>(parent, name).
    template define_singleton_function<cvflann::NNIndex<Distance>*(*)(const Matrix<typename Distance::ElementType>&, const cvflann::IndexParams&, const Distance&)>("create", &cvflann::index_creator<KDTreeCapability, VectorSpace, Distance>::create,
      Arg("dataset"), Arg("params"), Arg("distance"));
}

