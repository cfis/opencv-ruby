#include <opencv2/flann/dynamic_bitset.h>
#include "dynamic_bitset-rb.hpp"

using namespace Rice;

void Init_Flann_DynamicBitset()
{
  Class(rb_cObject).define_constant("FLANN_USE_BOOST", FLANN_USE_BOOST);

  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::DynamicBitset> rb_cCvflannDynamicBitset = define_class_under<cvflann::DynamicBitset>(rb_mCvflann, "DynamicBitset").
    define_constructor(Constructor<cvflann::DynamicBitset>()).
    define_constructor(Constructor<cvflann::DynamicBitset, size_t>(),
      Arg("sz")).
    define_method<void(cvflann::DynamicBitset::*)()>("clear", &cvflann::DynamicBitset::clear).
    define_method<bool(cvflann::DynamicBitset::*)() const>("empty?", &cvflann::DynamicBitset::empty).
    define_method<void(cvflann::DynamicBitset::*)()>("reset", &cvflann::DynamicBitset::reset).
    define_method<void(cvflann::DynamicBitset::*)(size_t)>("reset", &cvflann::DynamicBitset::reset,
      Arg("index")).
    define_method<void(cvflann::DynamicBitset::*)(size_t)>("reset_block", &cvflann::DynamicBitset::reset_block,
      Arg("index")).
    define_method<void(cvflann::DynamicBitset::*)(size_t)>("resize", &cvflann::DynamicBitset::resize,
      Arg("sz")).
    define_method<void(cvflann::DynamicBitset::*)(size_t)>("set", &cvflann::DynamicBitset::set,
      Arg("index")).
    define_method<size_t(cvflann::DynamicBitset::*)() const>("size", &cvflann::DynamicBitset::size).
    define_method<bool(cvflann::DynamicBitset::*)(size_t) const>("test", &cvflann::DynamicBitset::test,
      Arg("index"));
}