#include <opencv2/core.hpp> // Manual
#include <opencv2/flann/random.h>
#include "random-rb.hpp"

using namespace Rice;

void Init_Flann_Random()
{
  Module rb_mCvflann = define_module("Cvflann");

  rb_mCvflann.define_module_function<int(*)()>("rand", &cvflann::rand);

  rb_mCvflann.define_module_function<void(*)(unsigned int)>("seed_random", &cvflann::seed_random,
    Arg("seed"));

  rb_mCvflann.define_module_function<double(*)(double, double)>("rand_double", &cvflann::rand_double,
    Arg("high") = static_cast<double>(1.0), Arg("low") = static_cast<double>(0));

  rb_mCvflann.define_module_function<int(*)(int, int)>("rand_int", &cvflann::rand_int,
    Arg("high") = static_cast<int>(RAND_MAX), Arg("low") = static_cast<int>(0));

  Rice::Data_Type<cvflann::UniqueRandom> rb_cCvflannUniqueRandom = define_class_under<cvflann::UniqueRandom>(rb_mCvflann, "UniqueRandom").
    define_constructor(Constructor<cvflann::UniqueRandom, int>(),
      Arg("n")).
    define_method<void(cvflann::UniqueRandom::*)(int)>("init", &cvflann::UniqueRandom::init,
      Arg("n")).
    define_method<int(cvflann::UniqueRandom::*)()>("next", &cvflann::UniqueRandom::next);
}
