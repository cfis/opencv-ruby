#include <opencv2/flann/object_factory.h>
#include "object_factory-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannCreatorNotFound;

template<typename Data_Type_T, typename BaseClass, typename UniqueIdType, typename ObjectCreator>
inline void ObjectFactory_builder(Data_Type_T& klass)
{
  klass.template define_method("subscribe?", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::subscribe,
      Arg("id"), Arg("creator")).
    template define_method("unregister?", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::unregister,
      Arg("id")).
    template define_method("create", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::create,
      Arg("id")).
    template define_singleton_function("instance", &cvflann::ObjectFactory<BaseClass, UniqueIdType, ObjectCreator>::instance);
};
void Init_ObjectFactory()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannCreatorNotFound = define_class_under<cvflann::CreatorNotFound>(rb_mCvflann, "CreatorNotFound").
    define_constructor(Constructor<cvflann::CreatorNotFound>());

}