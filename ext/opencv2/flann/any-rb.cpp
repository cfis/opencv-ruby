#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/any.h>
#include "any-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannAny;

void Init_Any()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannAny = define_class_under<cvflann::any>(rb_mCvflann, "Any").
    define_constructor(Constructor<cvflann::any>()).
    define_constructor(Constructor<cvflann::any, const char*>(),
      Arg("x")).
    define_constructor(Constructor<cvflann::any, const cvflann::any&>(),
      Arg("x")).
    define_method<cvflann::any&(cvflann::any::*)(const cvflann::any&)>("assign", &cvflann::any::assign,
      Arg("x")).
    //define_method<cvflann::any&(cvflann::any::*)(const cvflann::any&)>("assign", &cvflann::any::operator=,
    //  Arg("x")).
    //define_method<cvflann::any&(cvflann::any::*)(const char*)>("assign", &cvflann::any::operator=,
    //  Arg("x")).
    define_method("swap", &cvflann::any::swap,
      Arg("x")).
    define_method("empty?", &cvflann::any::empty).
    define_method("reset", &cvflann::any::reset).
    define_method("compatible?", &cvflann::any::compatible,
      Arg("x")).
    define_method("type", &cvflann::any::type);
    
  rb_cCvflannAny.define_method("inspect", [](const cvflann::any& self) -> std::string
  {
    std::ostringstream stream;
    stream << self;
    return stream.str();
  });
}