#include <opencv2/flann/object_factory.h>
#include "object_factory-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename BaseClass, typename UniqueIdType, typename ObjectCreator>
inline void ObjectFactory_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::*)(UniqueIdType, ObjectCreator)>("subscribe", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::subscribe,
      Arg("id"), Arg("creator")).
    template define_method<bool(cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::*)(UniqueIdType)>("unregister", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::unregister,
      Arg("id")).
    template define_method<ObjectCreator(cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::*)(UniqueIdType)>("create", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::create,
      Arg("id")).
    template define_singleton_function<typename cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::ThisClass&(*)()>("instance", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::instance);
};

