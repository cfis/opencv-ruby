#include <opencv2/flann/any.h>
#include "any-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannAny;
Rice::Class rb_cCvflannAnyimplBadAnyCast;
Rice::Class rb_cCvflannAnyimplBaseAnyPolicy;
Rice::Class rb_cCvflannAnyimplChoosePolicyAny;
Rice::Class rb_cCvflannAnyimplChoosePolicyBool;
Rice::Class rb_cCvflannAnyimplChoosePolicyFloat;
Rice::Class rb_cCvflannAnyimplChoosePolicyInt;
Rice::Class rb_cCvflannAnyimplChoosePolicyLong;
Rice::Class rb_cCvflannAnyimplChoosePolicyShort;
Rice::Class rb_cCvflannAnyimplChoosePolicySignedChar;
Rice::Class rb_cCvflannAnyimplChoosePolicyUnsignedChar;
Rice::Class rb_cCvflannAnyimplChoosePolicyUnsignedInt;
Rice::Class rb_cCvflannAnyimplChoosePolicyUnsignedLong;
Rice::Class rb_cCvflannAnyimplChoosePolicyUnsignedShort;
Rice::Class rb_cCvflannAnyimplEmptyAny;

template<typename Data_Type_T, typename T>
inline void typed_base_any_policy_builder(Data_Type_T& klass)
{
  klass.define_method("get_size", &cvflann::anyimpl::typed_base_any_policy<T>::get_size).
    define_method("type", &cvflann::anyimpl::typed_base_any_policy<T>::type);
};

template<typename Data_Type_T, typename T>
inline void small_any_policy_builder(Data_Type_T& klass)
{
  klass.define_method("static_delete", &cvflann::anyimpl::small_any_policy<T>::static_delete,
      Arg("arg_0")).
    define_method("copy_from_value", &cvflann::anyimpl::small_any_policy<T>::copy_from_value,
      Arg("src"), Arg("dest")).
    define_method("clone", &cvflann::anyimpl::small_any_policy<T>::clone,
      Arg("src"), Arg("dest")).
    define_method("move", &cvflann::anyimpl::small_any_policy<T>::move,
      Arg("src"), Arg("dest")).
    template define_method<void*(cvflann::anyimpl::small_any_policy<T>::*)(void**)>("get_value", &cvflann::anyimpl::small_any_policy<T>::get_value,
      Arg("src")).
    template define_method<const void*(cvflann::anyimpl::small_any_policy<T>::*)(void* const*)>("get_value", &cvflann::anyimpl::small_any_policy<T>::get_value,
      Arg("src")).
    define_method("print", &cvflann::anyimpl::small_any_policy<T>::print,
      Arg("out"), Arg("src"));
};

template<typename Data_Type_T, typename T>
inline void big_any_policy_builder(Data_Type_T& klass)
{
  klass.define_method("static_delete", &cvflann::anyimpl::big_any_policy<T>::static_delete,
      Arg("x")).
    define_method("copy_from_value", &cvflann::anyimpl::big_any_policy<T>::copy_from_value,
      Arg("src"), Arg("dest")).
    define_method("clone", &cvflann::anyimpl::big_any_policy<T>::clone,
      Arg("src"), Arg("dest")).
    define_method("move", &cvflann::anyimpl::big_any_policy<T>::move,
      Arg("src"), Arg("dest")).
    template define_method<void*(cvflann::anyimpl::big_any_policy<T>::*)(void**)>("get_value", &cvflann::anyimpl::big_any_policy<T>::get_value,
      Arg("src")).
    template define_method<const void*(cvflann::anyimpl::big_any_policy<T>::*)(void* const*)>("get_value", &cvflann::anyimpl::big_any_policy<T>::get_value,
      Arg("src")).
    define_method("print", &cvflann::anyimpl::big_any_policy<T>::print,
      Arg("out"), Arg("src"));
};

template<typename Data_Type_T, typename T>
inline void choose_policy_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void SinglePolicy_builder(Data_Type_T& klass)
{
  klass.define_singleton_function("get_policy", &cvflann::anyimpl::SinglePolicy<T>::get_policy);
};
void Init_Any()
{
  Module rb_mCvflann = define_module("Cvflann");

  Module rb_mCvflannAnyimpl = define_module_under(rb_mCvflann, "Anyimpl");

  rb_cCvflannAnyimplBadAnyCast = define_class_under<cvflann::anyimpl::bad_any_cast, std::exception>(rb_mCvflannAnyimpl, "BadAnyCast").
    define_constructor(Constructor<cvflann::anyimpl::bad_any_cast>()).
    define_constructor(Constructor<cvflann::anyimpl::bad_any_cast, const char*, const char*>(),
      Arg("src"), Arg("dst")).
    define_method("what", &cvflann::anyimpl::bad_any_cast::what);

  rb_cCvflannAnyimplEmptyAny = define_class_under<cvflann::anyimpl::empty_any>(rb_mCvflannAnyimpl, "EmptyAny").
    define_constructor(Constructor<cvflann::anyimpl::empty_any>());

  rb_cCvflannAnyimplBaseAnyPolicy = define_class_under<cvflann::anyimpl::base_any_policy>(rb_mCvflannAnyimpl, "BaseAnyPolicy").
    define_method("static_delete", &cvflann::anyimpl::base_any_policy::static_delete,
      Arg("x")).
    define_method("copy_from_value", &cvflann::anyimpl::base_any_policy::copy_from_value,
      Arg("src"), Arg("dest")).
    define_method("clone", &cvflann::anyimpl::base_any_policy::clone,
      Arg("src"), Arg("dest")).
    define_method("move", &cvflann::anyimpl::base_any_policy::move,
      Arg("src"), Arg("dest")).
    define_method<void*(cvflann::anyimpl::base_any_policy::*)(void**)>("get_value", &cvflann::anyimpl::base_any_policy::get_value,
      Arg("src")).
    define_method<const void*(cvflann::anyimpl::base_any_policy::*)(void* const*)>("get_value", &cvflann::anyimpl::base_any_policy::get_value,
      Arg("src")).
    define_method("get_size", &cvflann::anyimpl::base_any_policy::get_size).
    define_method("type", &cvflann::anyimpl::base_any_policy::type).
    define_method("print", &cvflann::anyimpl::base_any_policy::print,
      Arg("out"), Arg("src"));

  rb_cCvflannAnyimplChoosePolicyAny = define_class_under<cvflann::anyimpl::choose_policy<cvflann::anyimpl::any>>(rb_mCvflannAnyimpl, "ChoosePolicyAny").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<cvflann::anyimpl::any>>());

  rb_cCvflannAnyimplChoosePolicySignedChar = define_class_under<cvflann::anyimpl::choose_policy<signed char>>(rb_mCvflannAnyimpl, "ChoosePolicySignedChar").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<signed char>>());

  rb_cCvflannAnyimplChoosePolicyUnsignedChar = define_class_under<cvflann::anyimpl::choose_policy<unsigned char>>(rb_mCvflannAnyimpl, "ChoosePolicyUnsignedChar").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<unsigned char>>());

  rb_cCvflannAnyimplChoosePolicyShort = define_class_under<cvflann::anyimpl::choose_policy<short>>(rb_mCvflannAnyimpl, "ChoosePolicyShort").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<short>>());

  rb_cCvflannAnyimplChoosePolicyUnsignedShort = define_class_under<cvflann::anyimpl::choose_policy<unsigned short>>(rb_mCvflannAnyimpl, "ChoosePolicyUnsignedShort").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<unsigned short>>());

  rb_cCvflannAnyimplChoosePolicyInt = define_class_under<cvflann::anyimpl::choose_policy<int>>(rb_mCvflannAnyimpl, "ChoosePolicyInt").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<int>>());

  rb_cCvflannAnyimplChoosePolicyUnsignedInt = define_class_under<cvflann::anyimpl::choose_policy<unsigned int>>(rb_mCvflannAnyimpl, "ChoosePolicyUnsignedInt").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<unsigned int>>());

  rb_cCvflannAnyimplChoosePolicyLong = define_class_under<cvflann::anyimpl::choose_policy<long>>(rb_mCvflannAnyimpl, "ChoosePolicyLong").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<long>>());

  rb_cCvflannAnyimplChoosePolicyUnsignedLong = define_class_under<cvflann::anyimpl::choose_policy<unsigned long>>(rb_mCvflannAnyimpl, "ChoosePolicyUnsignedLong").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<unsigned long>>());

  rb_cCvflannAnyimplChoosePolicyFloat = define_class_under<cvflann::anyimpl::choose_policy<float>>(rb_mCvflannAnyimpl, "ChoosePolicyFloat").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<float>>());

  rb_cCvflannAnyimplChoosePolicyBool = define_class_under<cvflann::anyimpl::choose_policy<bool>>(rb_mCvflannAnyimpl, "ChoosePolicyBool").
    define_constructor(Constructor<cvflann::anyimpl::choose_policy<bool>>());

  rb_cCvflannAny = define_class_under<cvflann::any>(rb_mCvflann, "Any").
    define_constructor(Constructor<cvflann::any>()).
    define_constructor(Constructor<cvflann::any, const char*>(),
      Arg("x")).
    define_constructor(Constructor<cvflann::any, const cvflann::any&>(),
      Arg("x")).
    define_method<cvflann::any&(cvflann::any::*)(const cvflann::any&)>("assign", &cvflann::any::assign,
      Arg("x")).
    define_method<cvflann::any&(cvflann::any::*)(const cvflann::any&)>("assign", &cvflann::any::operator=,
      Arg("x")).
    define_method<cvflann::any&(cvflann::any::*)(const char*)>("assign", &cvflann::any::operator=,
      Arg("x")).
    define_method("swap", &cvflann::any::swap,
      Arg("x")).
    define_method("empty?", &cvflann::any::empty).
    define_method("reset", &cvflann::any::reset).
    define_method("compatible?", &cvflann::any::compatible,
      Arg("x")).
    define_method("type", &cvflann::any::type);

  rb_cCvflannAnyimplEmptyAny.
    define_method("inspect", [](const cvflann::anyimpl::empty_any& self) -> std::string
  {
    std::ostringstream stream;
    stream << self;
    return stream.str();
  });

  rb_cCvflannAny.
    define_method("inspect", [](const cvflann::any& self) -> std::string
  {
    std::ostringstream stream;
    stream << self;
    return stream.str();
  });
}