#include <opencv2/core/utils/allocator_stats.hpp>
#include "allocator_stats-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvUtilsAllocatorStatisticsInterface;

void Init_AllocatorStats()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  rb_cCvUtilsAllocatorStatisticsInterface = define_class_under<cv::utils::AllocatorStatisticsInterface>(rb_mCvUtils, "AllocatorStatisticsInterface").
    define_method("get_current_usage", &cv::utils::AllocatorStatisticsInterface::getCurrentUsage).
    define_method("get_total_usage", &cv::utils::AllocatorStatisticsInterface::getTotalUsage).
    define_method("get_number_of_allocations", &cv::utils::AllocatorStatisticsInterface::getNumberOfAllocations).
    define_method("get_peak_usage", &cv::utils::AllocatorStatisticsInterface::getPeakUsage).
    define_method("reset_peak_usage", &cv::utils::AllocatorStatisticsInterface::resetPeakUsage);

}