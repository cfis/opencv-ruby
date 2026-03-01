template<typename T>
inline Rice::Data_Type<cvflann::Datatype<T>> Datatype_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cvflann::Datatype<T>>(parent, name);
}

