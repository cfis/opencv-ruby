#include <opencv2/core.hpp>
#include <opencv2/flann/random.h>
#include "random-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannUniqueRandom;

void Init_Random()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_mCvflann.define_module_function("rand", &cvflann::rand);
  
  rb_mCvflann.define_module_function("seed_random", &cvflann::seed_random,
    Arg("seed"));
  
  rb_mCvflann.define_module_function("rand_double", &cvflann::rand_double,
    Arg("high") = static_cast<double>(1.0), Arg("low") = static_cast<double>(0));
  
  rb_mCvflann.define_module_function("rand_int", &cvflann::rand_int,
    Arg("high") = static_cast<int>(RAND_MAX), Arg("low") = static_cast<int>(0));
  
  rb_cCvflannUniqueRandom = define_class_under<cvflann::UniqueRandom>(rb_mCvflann, "UniqueRandom").
    define_constructor(Constructor<cvflann::UniqueRandom, int>(),
      Arg("n")).
    define_method("init", &cvflann::UniqueRandom::init,
      Arg("n")).
    define_method("next", &cvflann::UniqueRandom::next);

}