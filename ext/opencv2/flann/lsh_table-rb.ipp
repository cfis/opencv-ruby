template<typename ElementType>
inline Rice::Data_Type<cvflann::lsh::LshTable<ElementType>> LshTable_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::lsh::LshTable<ElementType>>(parent, name).
    define_constructor(Constructor<cvflann::lsh::LshTable<ElementType>>()).
    define_constructor(Constructor<cvflann::lsh::LshTable<ElementType>, unsigned int, unsigned int>(),
      Arg("feature_size"), Arg("key_size")).
    template define_method<void(cvflann::lsh::LshTable<ElementType>::*)(unsigned int, const ElementType*)>("add", &cvflann::lsh::LshTable<ElementType>::add,
      Arg("value"), std::conditional_t<std::is_fundamental_v<const ElementType>, ArgBuffer, Arg>("feature")).
    template define_method<void(cvflann::lsh::LshTable<ElementType>::*)(cvflann::Matrix<ElementType>)>("add", &cvflann::lsh::LshTable<ElementType>::add,
      Arg("dataset")).
    template define_method<const cvflann::lsh::Bucket*(cvflann::lsh::LshTable<ElementType>::*)(cvflann::lsh::BucketKey) const>("get_bucket_from_key", &cvflann::lsh::LshTable<ElementType>::getBucketFromKey,
      Arg("key")).
    template define_method<size_t(cvflann::lsh::LshTable<ElementType>::*)(const ElementType*) const>("get_key", &cvflann::lsh::LshTable<ElementType>::getKey,
      std::conditional_t<std::is_fundamental_v<const ElementType>, ArgBuffer, Arg>("arg_0")).
    template define_method<cvflann::lsh::LshStats(cvflann::lsh::LshTable<ElementType>::*)() const>("get_stats", &cvflann::lsh::LshTable<ElementType>::getStats);
}

