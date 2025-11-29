#include <vector>
#include <opencv2/core/base.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/flann/dynamic_bitset.h>
#include "dynamic_bitset-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannDynamicBitset;

void Init_DynamicBitset()
{
  Class(rb_cObject).define_constant("FLANN_USE_BOOST", FLANN_USE_BOOST);
  
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannDynamicBitset = define_class_under<cvflann::DynamicBitset>(rb_mCvflann, "DynamicBitset").
    define_constructor(Constructor<cvflann::DynamicBitset>()).
    define_constructor(Constructor<cvflann::DynamicBitset, ::size_t>(),
      Arg("sz")).
    define_method("clear", &cvflann::DynamicBitset::clear).
    define_method("empty?", &cvflann::DynamicBitset::empty).
    define_method<void(cvflann::DynamicBitset::*)()>("reset", &cvflann::DynamicBitset::reset).
    define_method<void(cvflann::DynamicBitset::*)(::size_t)>("reset", &cvflann::DynamicBitset::reset,
      Arg("index")).
    define_method("reset_block", &cvflann::DynamicBitset::reset_block,
      Arg("index")).
    define_method("resize", &cvflann::DynamicBitset::resize,
      Arg("sz")).
    define_method("set", &cvflann::DynamicBitset::set,
      Arg("index")).
    define_method("size", &cvflann::DynamicBitset::size).
    define_method("test?", &cvflann::DynamicBitset::test,
      Arg("index"));

}