#include <opencv2/core/base.hpp>
#include <opencv2/flann/heap.h>
#include "heap-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void greater_builder(Data_Type_T& klass)
{
  klass.define_method("call", &cvflann::greater<T>::operator(),
      Arg("x"), Arg("y"));
};

template<typename Data_Type_T, typename T>
inline void Heap_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::Heap<T>, const int>(),
      Arg("capacity")).
    define_constructor(Constructor<cvflann::Heap<T>, std::vector<T>&&>(),
      Arg("vec")).
    define_method("size", &cvflann::Heap<T>::size).
    define_method("capacity", &cvflann::Heap<T>::capacity).
    define_method("empty?", &cvflann::Heap<T>::empty).
    define_method("clear", &cvflann::Heap<T>::clear).
    define_method("reserve", &cvflann::Heap<T>::reserve,
      Arg("capacity")).
    define_method("insert", &cvflann::Heap<T>::insert,
      Arg("value")).
    define_method("pop_min", &cvflann::Heap<T>::popMin,
      Arg("value"));
};

void Init_Flann_Heap()
{
  Module rb_mCvflann = define_module("Cvflann");
}