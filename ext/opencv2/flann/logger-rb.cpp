#include <opencv2/flann/logger.h>
#include "logger-rb.hpp"

using namespace Rice;

void Init_Flann_Logger()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::Logger> rb_cCvflannLogger = define_class_under<cvflann::Logger>(rb_mCvflann, "Logger").
    define_singleton_function("set_level", &cvflann::Logger::setLevel,
      Arg("level")).
    define_singleton_function("set_destination", &cvflann::Logger::setDestination,
      Arg("name")).
    define_singleton_function("log", &cvflann::Logger::log,
      Arg("level"), Arg("fmt")).
    define_singleton_function("fatal", &cvflann::Logger::fatal,
      Arg("fmt")).
    define_singleton_function("error", &cvflann::Logger::error,
      Arg("fmt")).
    define_singleton_function("warn", &cvflann::Logger::warn,
      Arg("fmt")).
    define_singleton_function("info", &cvflann::Logger::info,
      Arg("fmt"));
}