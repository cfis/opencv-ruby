#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.defines.hpp>
#include "logger.defines-rb.hpp"

using namespace Rice;


void Init_LoggerDefines()
{
  Class(rb_cObject).define_constant("CV_LOG_LEVEL_SILENT", CV_LOG_LEVEL_SILENT);
  
  Class(rb_cObject).define_constant("CV_LOG_LEVEL_FATAL", CV_LOG_LEVEL_FATAL);
  
  Class(rb_cObject).define_constant("CV_LOG_LEVEL_ERROR", CV_LOG_LEVEL_ERROR);
  
  Class(rb_cObject).define_constant("CV_LOG_LEVEL_WARN", CV_LOG_LEVEL_WARN);
  
  Class(rb_cObject).define_constant("CV_LOG_LEVEL_INFO", CV_LOG_LEVEL_INFO);
  
  Class(rb_cObject).define_constant("CV_LOG_LEVEL_DEBUG", CV_LOG_LEVEL_DEBUG);
  
  Class(rb_cObject).define_constant("CV_LOG_LEVEL_VERBOSE", CV_LOG_LEVEL_VERBOSE);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsLogging = define_module_under(rb_mCvUtils, "Logging");
  
  Enum<cv::utils::logging::LogLevel> rb_cCvUtilsLoggingLogLevel = define_enum_under<cv::utils::logging::LogLevel>("LogLevel", rb_mCvUtilsLogging).
    define_value("LOG_LEVEL_SILENT", cv::utils::logging::LogLevel::LOG_LEVEL_SILENT).
    define_value("LOG_LEVEL_FATAL", cv::utils::logging::LogLevel::LOG_LEVEL_FATAL).
    define_value("LOG_LEVEL_ERROR", cv::utils::logging::LogLevel::LOG_LEVEL_ERROR).
    define_value("LOG_LEVEL_WARNING", cv::utils::logging::LogLevel::LOG_LEVEL_WARNING).
    define_value("LOG_LEVEL_INFO", cv::utils::logging::LogLevel::LOG_LEVEL_INFO).
    define_value("LOG_LEVEL_DEBUG", cv::utils::logging::LogLevel::LOG_LEVEL_DEBUG).
    define_value("LOG_LEVEL_VERBOSE", cv::utils::logging::LogLevel::LOG_LEVEL_VERBOSE).
    define_value("ENUM_LOG_LEVEL_FORCE_INT", cv::utils::logging::LogLevel::ENUM_LOG_LEVEL_FORCE_INT);

}