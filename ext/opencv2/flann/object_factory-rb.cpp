#include "object_factory-rb.ipp"

void Init_Flann_ObjectFactory()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::CreatorNotFound> rb_cCvflannCreatorNotFound = define_class_under<cvflann::CreatorNotFound>(rb_mCvflann, "CreatorNotFound").
    define_constructor(Constructor<cvflann::CreatorNotFound>());
}