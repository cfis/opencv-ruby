#include <opencv2/flann/any.h>
#include "any-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void typed_base_any_policy_builder(Data_Type_T& klass)
{
  klass.template define_method<::size_t(cvflann::anyimpl::typed_base_any_policy<T>::*)()>("get_size", &cvflann::anyimpl::typed_base_any_policy<T>::get_size).
    template define_method<const std::type_info&(cvflann::anyimpl::typed_base_any_policy<T>::*)()>("type", &cvflann::anyimpl::typed_base_any_policy<T>::type);
};

template<typename Data_Type_T, typename T>
inline void small_any_policy_builder(Data_Type_T& klass)
{
  klass.template define_method<void(cvflann::anyimpl::small_any_policy<T>::*)(void**)>("static_delete", &cvflann::anyimpl::small_any_policy<T>::static_delete,
      ArgBuffer("arg_0")).
    template define_method<void(cvflann::anyimpl::small_any_policy<T>::*)(const void*, void**)>("copy_from_value", &cvflann::anyimpl::small_any_policy<T>::copy_from_value,
      ArgBuffer("src"), ArgBuffer("dest")).
    template define_method<void(cvflann::anyimpl::small_any_policy<T>::*)(void* const*, void**)>("clone", &cvflann::anyimpl::small_any_policy<T>::clone,
      ArgBuffer("src"), ArgBuffer("dest")).
    template define_method<void(cvflann::anyimpl::small_any_policy<T>::*)(void* const*, void**)>("move", &cvflann::anyimpl::small_any_policy<T>::move,
      ArgBuffer("src"), ArgBuffer("dest")).
    template define_method<void*(cvflann::anyimpl::small_any_policy<T>::*)(void**)>("get_value", &cvflann::anyimpl::small_any_policy<T>::get_value,
      ArgBuffer("src"), ReturnBuffer()).
    template define_method<const void*(cvflann::anyimpl::small_any_policy<T>::*)(void* const*)>("get_value", &cvflann::anyimpl::small_any_policy<T>::get_value,
      ArgBuffer("src"), ReturnBuffer()).
    template define_method<void(cvflann::anyimpl::small_any_policy<T>::*)(std::ostream&, void* const*)>("print", &cvflann::anyimpl::small_any_policy<T>::print,
      Arg("out"), ArgBuffer("src"));
};

template<typename Data_Type_T, typename T>
inline void big_any_policy_builder(Data_Type_T& klass)
{
  klass.template define_method<void(cvflann::anyimpl::big_any_policy<T>::*)(void**)>("static_delete", &cvflann::anyimpl::big_any_policy<T>::static_delete,
      ArgBuffer("x")).
    template define_method<void(cvflann::anyimpl::big_any_policy<T>::*)(const void*, void**)>("copy_from_value", &cvflann::anyimpl::big_any_policy<T>::copy_from_value,
      ArgBuffer("src"), ArgBuffer("dest")).
    template define_method<void(cvflann::anyimpl::big_any_policy<T>::*)(void* const*, void**)>("clone", &cvflann::anyimpl::big_any_policy<T>::clone,
      ArgBuffer("src"), ArgBuffer("dest")).
    template define_method<void(cvflann::anyimpl::big_any_policy<T>::*)(void* const*, void**)>("move", &cvflann::anyimpl::big_any_policy<T>::move,
      ArgBuffer("src"), ArgBuffer("dest")).
    template define_method<void*(cvflann::anyimpl::big_any_policy<T>::*)(void**)>("get_value", &cvflann::anyimpl::big_any_policy<T>::get_value,
      ArgBuffer("src"), ReturnBuffer()).
    template define_method<const void*(cvflann::anyimpl::big_any_policy<T>::*)(void* const*)>("get_value", &cvflann::anyimpl::big_any_policy<T>::get_value,
      ArgBuffer("src"), ReturnBuffer()).
    template define_method<void(cvflann::anyimpl::big_any_policy<T>::*)(std::ostream&, void* const*)>("print", &cvflann::anyimpl::big_any_policy<T>::print,
      Arg("out"), ArgBuffer("src"));
};

template<typename Data_Type_T, typename T>
inline void SinglePolicy_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<cvflann::anyimpl::base_any_policy*(*)()>("get_policy", &cvflann::anyimpl::SinglePolicy<T>::get_policy);
};

