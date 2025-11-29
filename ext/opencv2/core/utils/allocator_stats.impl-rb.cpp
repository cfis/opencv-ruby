#include <opencv2/core/utils/allocator_stats.impl.hpp>
#include "allocator_stats.impl-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvUtilsAllocatorStatistics;

void Init_AllocatorStatsImpl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  rb_cCvUtilsAllocatorStatistics = define_class_under<cv::utils::AllocatorStatistics, cv::utils::AllocatorStatisticsInterface>(rb_mCvUtils, "AllocatorStatistics").
    define_constructor(Constructor<cv::utils::AllocatorStatistics>()).
    define_method("get_current_usage", &cv::utils::AllocatorStatistics::getCurrentUsage).
    define_method("get_total_usage", &cv::utils::AllocatorStatistics::getTotalUsage).
    define_method("get_number_of_allocations", &cv::utils::AllocatorStatistics::getNumberOfAllocations).
    define_method("get_peak_usage", &cv::utils::AllocatorStatistics::getPeakUsage).
    define_method("reset_peak_usage", &cv::utils::AllocatorStatistics::resetPeakUsage).
    define_method("on_allocate", &cv::utils::AllocatorStatistics::onAllocate,
      Arg("sz")).
    define_method("on_free", &cv::utils::AllocatorStatistics::onFree,
      Arg("sz"));

}