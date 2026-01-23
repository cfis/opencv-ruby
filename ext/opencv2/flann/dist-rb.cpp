#include <opencv2/core/base.hpp>
#include <opencv2/flann/dist.h>
#include "dist-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void Accumulator_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void ZeroIterator_builder(Data_Type_T& klass)
{
  klass.define_method("dereference", &cvflann::ZeroIterator<T>::operator*).
    define_method("[]", &cvflann::ZeroIterator<T>::operator[],
      Arg("arg_0")).
    template define_method<const cvflann::ZeroIterator<T>&(cvflann::ZeroIterator<T>::*)()>("increment_pre", &cvflann::ZeroIterator<T>::operator++).
    template define_method<cvflann::ZeroIterator<T>(cvflann::ZeroIterator<T>::*)(int)>("increment", &cvflann::ZeroIterator<T>::operator++,
      Arg("arg_0")).
    define_method("assign_plus", &cvflann::ZeroIterator<T>::operator+=,
      Arg("arg_0"));
};

template<typename Data_Type_T, typename T>
inline void L2_Simple_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void L2_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void L1_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void MinkowskiDistance_builder(Data_Type_T& klass)
{
  klass.define_attr("order", &cvflann::MinkowskiDistance<T>::order).
    define_constructor(Constructor<cvflann::MinkowskiDistance<T>, int>(),
      Arg("order_"));
};

template<typename Data_Type_T, typename T>
inline void MaxDistance_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void Hamming_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void Hamming2_builder(Data_Type_T& klass)
{
  klass.define_method("popcnt32", &cvflann::Hamming2<T>::popcnt32,
      Arg("n")).
    define_method("popcnt64", &cvflann::Hamming2<T>::popcnt64,
      Arg("n"));
};

template<typename Data_Type_T, typename T>
inline void DNAmming2_builder(Data_Type_T& klass)
{
  klass.define_method("popcnt32", &cvflann::DNAmming2<T>::popcnt32,
      Arg("n")).
    define_method("popcnt64", &cvflann::DNAmming2<T>::popcnt64,
      Arg("n"));
};

template<typename Data_Type_T, typename T>
inline void HistIntersectionDistance_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void HellingerDistance_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void ChiSquareDistance_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void KL_Divergence_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename Distance, typename ElementType>
inline void squareDistance_builder(Data_Type_T& klass)
{
  klass.define_method("call", &cvflann::squareDistance<Distance, ElementType>::operator(),
      Arg("dist"));
};

template<typename Data_Type_T, typename Distance, typename ElementType>
inline void isSquareDist_builder(Data_Type_T& klass)
{
  klass.define_method("call", &cvflann::isSquareDist<Distance, ElementType>::operator());
};

template<typename Data_Type_T, typename Distance, typename ElementType>
inline void simpleDistance_builder(Data_Type_T& klass)
{
  klass.define_method("call", &cvflann::simpleDistance<Distance, ElementType>::operator(),
      Arg("dist"));
};

void Init_Flann_Dist()
{
  Module rb_mCvflann = define_module("Cvflann");

  rb_mCvflann.define_module_function<int(*)(int)>("abs", &cvflann::abs,
    Arg("x"));

  rb_mCvflann.define_module_function<float(*)(float)>("abs", &cvflann::abs,
    Arg("x"));

  rb_mCvflann.define_module_function<double(*)(double)>("abs", &cvflann::abs,
    Arg("x"));

  rb_mCvflann.define_module_function<unsigned int(*)(float)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<unsigned short(*)(float)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<unsigned char(*)(float)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<long long(*)(float)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<long(*)(float)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<int(*)(float)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<short(*)(float)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<char(*)(float)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<unsigned int(*)(double)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<unsigned short(*)(double)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<unsigned char(*)(double)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<long long(*)(double)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<long(*)(double)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<int(*)(double)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<short(*)(double)>("round", &cvflann::round,
    Arg("x"));

  rb_mCvflann.define_module_function<char(*)(double)>("round", &cvflann::round,
    Arg("x"));

  Rice::Data_Type<cvflann::Accumulator<unsigned char>> rb_cCvflannAccumulatorUnsignedChar = define_class_under<cvflann::Accumulator<unsigned char>>(rb_mCvflann, "AccumulatorUnsignedChar").
    define_constructor(Constructor<cvflann::Accumulator<unsigned char>>());

  Rice::Data_Type<cvflann::Accumulator<unsigned short>> rb_cCvflannAccumulatorUnsignedShort = define_class_under<cvflann::Accumulator<unsigned short>>(rb_mCvflann, "AccumulatorUnsignedShort").
    define_constructor(Constructor<cvflann::Accumulator<unsigned short>>());

  Rice::Data_Type<cvflann::Accumulator<unsigned int>> rb_cCvflannAccumulatorUnsignedInt = define_class_under<cvflann::Accumulator<unsigned int>>(rb_mCvflann, "AccumulatorUnsignedInt").
    define_constructor(Constructor<cvflann::Accumulator<unsigned int>>());

  Rice::Data_Type<cvflann::Accumulator<char>> rb_cCvflannAccumulatorChar = define_class_under<cvflann::Accumulator<char>>(rb_mCvflann, "AccumulatorChar").
    define_constructor(Constructor<cvflann::Accumulator<char>>());

  Rice::Data_Type<cvflann::Accumulator<short>> rb_cCvflannAccumulatorShort = define_class_under<cvflann::Accumulator<short>>(rb_mCvflann, "AccumulatorShort").
    define_constructor(Constructor<cvflann::Accumulator<short>>());

  Rice::Data_Type<cvflann::Accumulator<int>> rb_cCvflannAccumulatorInt = define_class_under<cvflann::Accumulator<int>>(rb_mCvflann, "AccumulatorInt").
    define_constructor(Constructor<cvflann::Accumulator<int>>());

  Rice::Data_Type<cvflann::True> rb_cCvflannTrue = define_class_under<cvflann::True>(rb_mCvflann, "True").
    define_constructor(Constructor<cvflann::True>()).
    define_constant("Val", cvflann::True::val);

  Rice::Data_Type<cvflann::False> rb_cCvflannFalse = define_class_under<cvflann::False>(rb_mCvflann, "False").
    define_constructor(Constructor<cvflann::False>()).
    define_constant("Val", cvflann::False::val);

  Rice::Data_Type<cvflann::ZeroIterator<unsigned char>> rb_cCvflannZeroiteratorUnsignedChar = define_class_under<cvflann::ZeroIterator<unsigned char>>(rb_mCvflann, "ZeroIteratorUnsignedChar").
    define(&ZeroIterator_builder<Data_Type<cvflann::ZeroIterator<unsigned char>>, unsigned char>);

  Rice::Data_Type<cvflann::HammingLUT> rb_cCvflannHammingLUT = define_class_under<cvflann::HammingLUT>(rb_mCvflann, "HammingLUT").
    define_constructor(Constructor<cvflann::HammingLUT>()).
    define_method<cvflann::HammingLUT::ResultType(cvflann::HammingLUT::*)(const unsigned char*, const cvflann::ZeroIterator<unsigned char>, size_t) const>("call", &cvflann::HammingLUT::operator(),
      ArgBuffer("a"), Arg("b"), Arg("size"));

  Rice::Data_Type<cvflann::DNAmmingLUT> rb_cCvflannDNAmmingLUT = define_class_under<cvflann::DNAmmingLUT>(rb_mCvflann, "DNAmmingLUT").
    define_constructor(Constructor<cvflann::DNAmmingLUT>()).
    define_method<cvflann::DNAmmingLUT::ResultType(cvflann::DNAmmingLUT::*)(const unsigned char*, const cvflann::ZeroIterator<unsigned char>, size_t) const>("call", &cvflann::DNAmmingLUT::operator(),
      ArgBuffer("a"), Arg("b"), Arg("size"));
}