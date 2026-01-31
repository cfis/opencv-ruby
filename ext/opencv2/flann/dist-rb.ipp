#include <opencv2/flann/dist.h>
#include "dist-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void ZeroIterator_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cvflann::ZeroIterator<T>::*)()>("dereference", &cvflann::ZeroIterator<T>::operator*).
    template define_method<T(cvflann::ZeroIterator<T>::*)(int)>("[]", &cvflann::ZeroIterator<T>::operator[],
      Arg("arg_0")).
    template define_method<const cvflann::ZeroIterator<T>&(cvflann::ZeroIterator<T>::*)()>("increment", &cvflann::ZeroIterator<T>::operator++).
    template define_method<cvflann::ZeroIterator<T>(cvflann::ZeroIterator<T>::*)(int)>("increment_post", &cvflann::ZeroIterator<T>::operator++,
      Arg("arg_0")).
    template define_method<cvflann::ZeroIterator<T>&(cvflann::ZeroIterator<T>::*)(int)>("assign_plus", &cvflann::ZeroIterator<T>::operator+=,
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void MinkowskiDistance_builder(Data_Type_T& klass)
{
  klass.define_attr("order", &cvflann::MinkowskiDistance<T>::order).
    define_constructor(Constructor<cvflann::MinkowskiDistance<T>, int>(),
      Arg("order_"));
};

template<typename Data_Type_T, typename T>
inline void Hamming2_builder(Data_Type_T& klass)
{
  klass.template define_method<unsigned int(cvflann::Hamming2<T>::*)(uint32_t) const>("popcnt32", &cvflann::Hamming2<T>::popcnt32,
      Arg("n")).
    template define_method<unsigned int(cvflann::Hamming2<T>::*)(uint64_t) const>("popcnt64", &cvflann::Hamming2<T>::popcnt64,
      Arg("n"));
};

template<typename Data_Type_T, typename T>
inline void DNAmming2_builder(Data_Type_T& klass)
{
  klass.template define_method<unsigned int(cvflann::DNAmming2<T>::*)(uint32_t) const>("popcnt32", &cvflann::DNAmming2<T>::popcnt32,
      Arg("n")).
    template define_method<unsigned int(cvflann::DNAmming2<T>::*)(uint64_t) const>("popcnt64", &cvflann::DNAmming2<T>::popcnt64,
      Arg("n"));
};

template<typename Data_Type_T, typename Distance, typename ElementType>
inline void squareDistance_builder(Data_Type_T& klass)
{
  klass.template define_method<typename cvflann::squareDistance<Distance, ElementType>::ResultType(cvflann::squareDistance<Distance, ElementType>::*)(typename cvflann::squareDistance<Distance, ElementType>::ResultType)>("call", &cvflann::squareDistance<Distance, ElementType>::operator(),
      Arg("dist"));
};

template<typename Data_Type_T, typename Distance, typename ElementType>
inline void isSquareDist_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cvflann::isSquareDist<Distance, ElementType>::*)()>("call", &cvflann::isSquareDist<Distance, ElementType>::operator());
};

template<typename Data_Type_T, typename Distance, typename ElementType>
inline void simpleDistance_builder(Data_Type_T& klass)
{
  klass.template define_method<typename cvflann::simpleDistance<Distance, ElementType>::ResultType(cvflann::simpleDistance<Distance, ElementType>::*)(typename cvflann::simpleDistance<Distance, ElementType>::ResultType)>("call", &cvflann::simpleDistance<Distance, ElementType>::operator(),
      Arg("dist"));
};

