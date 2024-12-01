#include <opencv2/flann/logger.h>
#include "logger-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannLogger;

void Init_Flann_Logger()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannLogger = define_class_under<cvflann::Logger>(rb_mCvflann, "Logger").
    define_singleton_function("set_level", &cvflann::Logger::setLevel,
      Arg("level")).
    define_singleton_function("set_destination", &cvflann::Logger::setDestination,
      Arg("name")).
    define_singleton_function("log", &cvflann::Logger::log,
      Arg("level"), Arg("fmt"));

}