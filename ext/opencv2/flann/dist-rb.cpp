#include <opencv2/core/base.hpp> // Manual
#include <opencv2/flann/dist.h>
#include "dist-rb.hpp"

using namespace Rice;

#include "dist-rb.ipp"

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

  Rice::Data_Type<cvflann::ZeroIterator<unsigned char>> rb_cCvflannZeroiteratorUnsignedChar = ZeroIterator_instantiate<unsigned char>(rb_mCvflann, "ZeroIteratorUnsignedChar");

  Rice::Data_Type<cvflann::HammingLUT> rb_cCvflannHammingLUT = define_class_under<cvflann::HammingLUT>(rb_mCvflann, "HammingLUT").
    define_constructor(Constructor<cvflann::HammingLUT>()).
    define_method<cvflann::HammingLUT::ResultType(cvflann::HammingLUT::*)(const unsigned char*, const cvflann::ZeroIterator<unsigned char>, size_t) const>("call", &cvflann::HammingLUT::operator(),
      ArgBuffer("a"), Arg("b"), Arg("size"));

  Rice::Data_Type<cvflann::DNAmmingLUT> rb_cCvflannDNAmmingLUT = define_class_under<cvflann::DNAmmingLUT>(rb_mCvflann, "DNAmmingLUT").
    define_constructor(Constructor<cvflann::DNAmmingLUT>()).
    define_method<cvflann::DNAmmingLUT::ResultType(cvflann::DNAmmingLUT::*)(const unsigned char*, const cvflann::ZeroIterator<unsigned char>, size_t) const>("call", &cvflann::DNAmmingLUT::operator(),
      ArgBuffer("a"), Arg("b"), Arg("size"));
}