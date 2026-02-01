template<typename BaseClass, typename UniqueIdType, typename ObjectCreator>
inline Rice::Data_Type<cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>> ObjectFactory_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>>(parent, name).
    template define_method<bool(cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::*)(UniqueIdType, ObjectCreator)>("subscribe", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::subscribe,
      Arg("id"), Arg("creator")).
    template define_method<bool(cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::*)(UniqueIdType)>("unregister", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::unregister,
      Arg("id")).
    template define_method<ObjectCreator(cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::*)(UniqueIdType)>("create", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::create,
      Arg("id")).
    template define_singleton_function<typename cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::ThisClass&(*)()>("instance", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::instance);
}

