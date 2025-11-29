#include <opencv2/core.hpp>
#include <opencv2/core/utils/logger.hpp>
#include "logger-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvUtilsLoggingLogTagAuto;

void Init_Utils_Logger()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsLogging = define_module_under(rb_mCvUtils, "Logging");
  
  rb_mCvUtilsLogging.define_module_function("set_log_level", &cv::utils::logging::setLogLevel,
    Arg("log_level"));
  
  rb_mCvUtilsLogging.define_module_function("get_log_level", &cv::utils::logging::getLogLevel);
  
  rb_mCvUtilsLogging.define_module_function("register_log_tag", &cv::utils::logging::registerLogTag,
    Arg("plogtag"));
  
  rb_mCvUtilsLogging.define_module_function("set_log_tag_level", &cv::utils::logging::setLogTagLevel,
    Arg("tag"), Arg("level"));
  
  rb_mCvUtilsLogging.define_module_function("get_log_tag_level", &cv::utils::logging::getLogTagLevel,
    Arg("tag"));
  
  Module rb_mCvUtilsLoggingInternal = define_module_under(rb_mCvUtilsLogging, "Internal");
  
  rb_mCvUtilsLoggingInternal.define_module_function("get_global_log_tag", &cv::utils::logging::internal::getGlobalLogTag);
  
  rb_mCvUtilsLoggingInternal.define_module_function("write_log_message", &cv::utils::logging::internal::writeLogMessage,
    Arg("log_level"), Arg("message"));
  
  rb_mCvUtilsLoggingInternal.define_module_function("write_log_message_ex", &cv::utils::logging::internal::writeLogMessageEx,
    Arg("log_level"), Arg("tag"), Arg("file"), Arg("line"), Arg("func"), Arg("message"));
  
  rb_cCvUtilsLoggingLogTagAuto = define_class_under<cv::utils::logging::LogTagAuto, cv::utils::logging::LogTag>(rb_mCvUtilsLogging, "LogTagAuto").
    define_constructor(Constructor<cv::utils::logging::LogTagAuto, const char*, cv::utils::logging::LogLevel>(),
      Arg("_name"), Arg("_level"));

}