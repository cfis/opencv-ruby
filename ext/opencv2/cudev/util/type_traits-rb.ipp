#include <opencv2/cudev/util/type_traits.hpp>
#include "type_traits-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, int A>
inline void Int2Type_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cudev::Int2Type<A>::value);
};

template<typename Data_Type_T, typename T, int COUNT>
inline void ArrayWrapper_builder(Data_Type_T& klass)
{
  klass.define_attr("array", &cv::cudev::ArrayWrapper<T, COUNT>::array, Rice::AttrAccess::Read);
};

template<typename Data_Type_T, int N, int CURRENT_VAL, int COUNT>
inline void Log2_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cudev::Log2<N, CURRENT_VAL, COUNT>::value);
};

template<typename Data_Type_T, int N>
inline void IsPowerOf2_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cudev::IsPowerOf2<N>::value);
};

template<typename Data_Type_T, typename A, typename B>
inline void TypesEquals_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::cudev::TypesEquals<A, B>::value);
};

template<typename Data_Type_T, typename T>
inline void TypeTraits_builder(Data_Type_T& klass)
{
  klass.define_constant("Is_const", (int)cv::cudev::TypeTraits<T>::is_const).
    define_constant("Is_volatile", (int)cv::cudev::TypeTraits<T>::is_volatile).
    define_constant("Is_reference", (int)cv::cudev::TypeTraits<T>::is_reference).
    define_constant("Is_pointer", (int)cv::cudev::TypeTraits<T>::is_pointer).
    define_constant("Is_unsigned_int", (int)cv::cudev::TypeTraits<T>::is_unsigned_int).
    define_constant("Is_signed_int", (int)cv::cudev::TypeTraits<T>::is_signed_int).
    define_constant("Is_integral", (int)cv::cudev::TypeTraits<T>::is_integral).
    define_constant("Is_float", (int)cv::cudev::TypeTraits<T>::is_float).
    define_constant("Is_scalar", (int)cv::cudev::TypeTraits<T>::is_scalar).
    define_constant("Is_vec", (int)cv::cudev::TypeTraits<T>::is_vec);
};

