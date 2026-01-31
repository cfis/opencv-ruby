#include <opencv2/videostab/log.hpp>
#include "log-rb.hpp"

using namespace Rice;

void Init_Videostab_Log()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  Rice::Data_Type<cv::videostab::ILog> rb_cCvVideostabILog = define_class_under<cv::videostab::ILog>(rb_mCvVideostab, "ILog");

  Rice::Data_Type<cv::videostab::NullLog> rb_cCvVideostabNullLog = define_class_under<cv::videostab::NullLog, cv::videostab::ILog>(rb_mCvVideostab, "NullLog").
    define_constructor(Constructor<cv::videostab::NullLog>());

  Rice::Data_Type<cv::videostab::LogToStdout> rb_cCvVideostabLogToStdout = define_class_under<cv::videostab::LogToStdout, cv::videostab::ILog>(rb_mCvVideostab, "LogToStdout").
    define_constructor(Constructor<cv::videostab::LogToStdout>());
}