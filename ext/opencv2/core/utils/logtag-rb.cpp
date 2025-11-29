#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logtag.hpp>
#include "logtag-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvUtilsLoggingLogTag;

void Init_Logtag()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsLogging = define_module_under(rb_mCvUtils, "Logging");
  
  rb_cCvUtilsLoggingLogTag = define_class_under<cv::utils::logging::LogTag>(rb_mCvUtilsLogging, "LogTag").
    define_attr("name", &cv::utils::logging::LogTag::name).
    define_attr("level", &cv::utils::logging::LogTag::level).
    define_constructor(Constructor<cv::utils::logging::LogTag, const char*, cv::utils::logging::LogLevel>(),
      Arg("_name"), Arg("_level"));

}