#include <opencv2/flann/logger.h>
#include "logger-rb.hpp"

using namespace Rice;

void Init_Flann_Logger()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::Logger> rb_cCvflannLogger = define_class_under<cvflann::Logger>(rb_mCvflann, "Logger").
    define_singleton_function<void(*)(int)>("set_level", &cvflann::Logger::setLevel,
      Arg("level")).
    define_singleton_function<void(*)(const char*)>("set_destination", &cvflann::Logger::setDestination,
      Arg("name"));
}
